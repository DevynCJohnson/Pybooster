#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Functions and data for manipulating and processing markup languages and CSS.

@file markup.py
@package pybooster.markup
@version 2020.11.06
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This library contains
 - Data tables of tags and attributes
 - Functions for manipulationing and processing markup data and CSS
 - Parsers

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from io import StringIO
from os import environ
from sys import stderr
from typing import List, Optional, Union
import xml.etree.ElementTree as ET  # nosec

from pybooster.libregex import CHARACTER_ENTITY, LEADING_TRAILING_WHITESPACE, LEADING_WHITESPACE, TRAILING_WHITESPACE, WHITESPACE
from pybooster.strtools import rmspecialwhitespace, unescape

try:  # Regular Expression module
    from regex import compile as rgxcompile, DOTALL, IGNORECASE, match as rgxmatch, sub as resub, VERBOSE
except ImportError:
    from re import compile as rgxcompile, DOTALL, IGNORECASE, match as rgxmatch, sub as resub, VERBOSE

if r'DISABLE_DEFUSEDXML' not in environ:
    try:  # XML module
        from defusedxml import defuse_stdlib
        defuse_stdlib()
    except ImportError:
        pass


__all__: list = [
    # CONSTANTS #
    r'INKSCAPE_NAMESPACES',
    r'SVG_SIZE',
    r'SVG_VIEWBOX_SEP',
    r'LEADING_SURROGATE',
    r'TRAILING_SURROGATE',
    r'LOCATESTARTTAGEND_TOLERANT',
    r'ATTRFIND_TOLERANT',
    r'CC_NS',
    r'COMMENTCLOSE',
    r'DECLNAME_MATCH',
    r'DECLSTRINGLIT_MATCH',
    r'DC_NS',
    r'ENDENDTAG',
    r'ENDTAGFIND',
    r'ENTITYREF',
    r'HEX_COLOR',
    r'INCOMPLETE',
    r'INKSCAPE_NS',
    r'INTERESTING_NORMAL',
    r'MARKEDSECTIONCLOSE',
    r'MSMARKEDSECTIONCLOSE',
    r'NUMBER',
    r'PICLOSE',
    r'RDF_NS',
    r'SELF_CLOSING_TAG',
    r'SODIPODI_NS',
    r'STARTTAGOPEN',
    r'TAGFIND_TOLERANT',
    r'WHITESPACE_IN_CHARREF',
    r'XML_DECLARATION',
    r'CDATA_CONTENT_ELEMENTS',
    r'PRE_TAGS',
    r'ROOT_TAGS',
    r'XML_ROOT_TAGS',
    r'JUNK_ATTR',
    r'JUNK_NS',
    r'CC_NO_CLOSE_TAGS',
    r'DC_NO_CLOSE_TAGS',
    r'HTML_NO_CLOSE_TAGS',
    r'MIMETYPE_NO_CLOSE_TAGS',
    r'SVG_NO_CLOSE_TAGS',
    r'BOOLEAN_ATTRIBUTES',
    r'TAG_SETS',
    r'XML_DOCTYPES',
    r'SVG_COLORS',
    r'SVG_UNIT',
    r'SVG_UNIT_CONVERSIONS',
    r'SVG_STYLES',
    r'SVG_TINY_STYLES',
    r'SVG_POSITION_ATTR',
    r'SVG_SCALING_ATTR',
    r'MIMETYPE_CORRECTIONS',
    # ASSERTION FUNCTIONS #
    r'assert_is_xml',
    # BOOLEAN TESTS #
    r'is_in_tagstack',
    r'is_removable_metadata_attr',
    r'is_removable_metadata_tag',
    r'is_self_closing_tag',
    r'is_xml_dtd',
    r'is_xml_xsd',
    # ESCAPE MANIPULATIONS #
    r'escape',
    r'escape_ambiguous_ampersand',
    r'escape_attr_value',
    r'htmlunescape',
    r'int2refnum',
    # SVG FUNCTIONS #
    r'parse_svg_size',
    r'svgviewbox2pixels',
    r'resize_svg',
    r'remove_duplicated_svg_ns',
    r'repair_svg_tag',
    r'repair_svg_attr',
    # MINIFY FUNCTIONS #
    r'condense_hex_colors',
    r'attribute_cleaner',
    # PRETTIFY FUNCTIONS #
    r'attr_sort',
    r'prettify_xml_schema',
    # XML REPAIR FUNCTIONS #
    r'fix_xml_declaration',
    r'insert_missing_xml_namespaces',
    # CLASSES #
    r'ParserBase',
    r'HTMLParser',
    r'Minifier',
    r'XMLMinParser'
]


# CONSTANTS #


INKSCAPE_NAMESPACES: dict = {r'inkscape': r'http://www.inkscape.org/namespaces/inkscape', r'sodipodi': r'http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd'}  # type: ignore
SVG_SIZE = rgxcompile(r'^\s*(-?\d+(?:\.\d+)?)\s*(px|in|cm|mm|pt|pc|%)?')
SVG_VIEWBOX_SEP = rgxcompile(r'[ ,\t]+')
NO_QUOTES: int = 0
SINGLE_QUOTE: int = 1
DOUBLE_QUOTE: int = 2
FILETYPE_HTML: int = 0
FILETYPE_XML: int = 1
FILETYPE_MATHML: int = 2
FILETYPE_SVG: int = 3
FILETYPE_DTD: int = 4
FILETYPE_XSD: int = 5
LEADING_SURROGATE = rgxcompile(r'[\ud800-\udbff]')
TRAILING_SURROGATE = rgxcompile(r'[\udc00-\udfff]')
LOCATESTARTTAGEND_TOLERANT = rgxcompile(r'<[A-Za-z\-][^\s/>\x00]*(?:[\s/]*(?:(?<=[\'\"\s/])[^\s/>][^\s/=>]*(?:\s*=+\s*(?:\'[^\']*\'|\"[^\"]*\"|(?![\'\"])[^>\s]*)(?:\s*,)*)?(?:\s|/(?!>))*)*)?\s*', flags=VERBOSE)
ATTR_TOLERANT: str = r'((?<=[\'"\s/])[^\s/>][^\s/=>]*)(\s*=+\s*(\'[^\']*\'|"[^"]*"|(?![\'"])[^>\s]*))?(?:\s|/(?!>))*'
ATTRFIND_TOLERANT = rgxcompile(ATTR_TOLERANT)
CC_NS = rgxcompile(r'\s*xmlns:cc\s*=\s*(\'|")(http://creativecommons.org/ns#|http://web.resource.org/cc/)(\'|")\s*')
COMMENTCLOSE = rgxcompile(r'--\s*>')
DECLNAME_MATCH = rgxcompile(r'[A-Za-z][-.\w]*\s*').match
DECLSTRINGLIT_MATCH = rgxcompile(r'(\'[^\']*\'|"[^"]*")\s*').match
DC_NS = rgxcompile(r'\s*xmlns:dc\s*=\s*(\'|")http://purl.org/dc/elements/1.1/(\'|")\s*')
ENDENDTAG = rgxcompile(r'>')
ENDTAGFIND = rgxcompile(r'</\s*([A-Za-z][-.:\w]*)\s*>')
ENTITYREF = rgxcompile(r'&([A-Za-z][-.0-9A-Za-z]*)[^0-9A-Za-z]')
HEX_COLOR = rgxcompile(r'(\s*)#([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])', flags=DOTALL)
INCOMPLETE = rgxcompile(r'&[A-Za-z#]')
INKSCAPE_NS = rgxcompile(r'\s*xmlns:inkscape\s*=\s*(\'|")http://www.inkscape.org/namespaces/inkscape(\'|")\s*')
INTERESTING_NORMAL = rgxcompile(r'[&<]')
MARKEDSECTIONCLOSE = rgxcompile(r']\s*]\s*>')
MSMARKEDSECTIONCLOSE = rgxcompile(r']\s*>')
NUMBER = rgxcompile(r'^[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?$')
PICLOSE = ENDENDTAG
RDF_NS = rgxcompile(r'\s*xmlns:rdf\s*=\s*(\'|")http://www.w3.org/1999/02/22-rdf-syntax-ns#(\'|")\s*')
SELF_CLOSING_TAG = rgxcompile(r'<([A-Za-z\-:][\s/]*)(' + ATTR_TOLERANT + r')([\s/]*)/>')
SODIPODI_NS = rgxcompile(r'\s*xmlns:sodipodi\s*=\s*(\'|")(http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd|http://inkscape.sourceforge.net/DTD/sodipodi-0.dtd)(\'|")\s*')
STARTTAGOPEN = rgxcompile(r'<[A-Za-z]')
TAGFIND_TOLERANT = rgxcompile(r'([A-Za-z][^\t\n\r\f />\x00]*)(?:\s|/(?!>))*')
TAGS_WITH_MIMETYPES = (r'embed', r'object', r'script', r'source', r'style')
WHITESPACE_IN_CHARREF = rgxcompile(r'[\s;]')
XML_DECLARATION = rgxcompile(r'<\?xml\s*[\w"\'=\-\. \t]*\s*\?>')
CDATA_CONTENT_ELEMENTS: set = {r'script', r'style'}
PRE_TAGS: tuple = (r'pre', r'textarea')
ROOT_TAGS: set = {r'html', r'math', r'svg', r'x3d'}
XML_ROOT_TAGS: set = {r'interface', r'math', r'mime-info', r'svg', r'x3d'}
JUNK_ATTR: set = {r'xmlns:a', r'xmlns:cc', r'xmlns:cib', r'xmlns:dc', r'xmlns:inkscape', r'xmlns:osb', r'xmlns:ns1', r'xmlns:rdf', r'xmlns:sodipodi'}
JUNK_NS: set = {r'cc:', r'cib:', r'dc:', r'inkscape:', r'osb:', r'rdf:', r'sodipodi:'}
CC_NO_CLOSE_TAGS: set = {r'cc:license', r'cc:permits', r'cc:requires'}
DC_NO_CLOSE_TAGS: set = {r'dc:type'}
HTML_NO_CLOSE_TAGS: set = {r'area', r'base', r'br', r'col', r'command', r'embed', r'hr', r'img', r'input', r'keygen', r'link', r'meta', r'param', r'source', r'track', r'wbr'}  # Tags that self-opening/closing
MIMETYPE_NO_CLOSE_TAGS: set = {r'alias', r'generic-icon', r'glob', r'match', r'sub-class-of'}  # Tags that self-opening/closing
SVG_NO_CLOSE_TAGS: set = {r'animate', r'audio', r'animateColor', r'animateMotion', r'animateTransform', r'br', r'circle', r'ellipse', r'embed', r'feBlend', r'feColorMatrix', r'feComposite', r'feDistantLight', r'feFuncA', r'feFuncB', r'feFuncG', r'feFuncR', r'feGaussianBlur', r'feImage', r'feMergeNode', r'feMorphology', r'feOffset', r'fePointLight', r'flowPara', r'image', r'line', r'meta', r'path', r'polygon', r'polyline', r'rect', r'set', r'stop', r'use', r'video'}  # Tags that self-opening/closing
SVG_MAY_CLOSE_TAGS: set = {r'g', r'linearGradient', r'radialGradient'}  # Tags that are sometimes self-opening/closing
USELESS_SVG_TAGS: set = {r'comment', r'desc', r'flowRoot', r'title'}


BOOLEAN_ATTRIBUTES: dict = {  # type: ignore
    r'audio': {r'autoplay', r'controls', r'loop', r'muted'},
    r'button': {r'autofocus', r'disabled', r'formnovalidate'},
    r'command': {r'checked', r'disabled'},
    r'dialog': {r'open'},
    r'fieldset': {r'disabled'},
    r'form': {r'novalidate'},
    r'iframe': {r'seamless'},
    r'img': {r'ismap'},
    r'input': {r'autofocus', r'checked', r'disabled', r'formnovalidate', r'multiple', r'readonly', r'required'},
    r'keygen': {r'autofocus', r'disabled'},
    r'object': {r'typesmustmatch'},
    r'ol': {r'reversed'},
    r'optgroup': {r'disabled'},
    r'option': {r'disabled', r'selected'},
    r'script': {r'async', r'defer'},
    r'select': {r'autofocus', r'disabled', r'multiple', r'required'},
    r'style': {r'scoped'},
    r'textarea': {r'autofocus', r'disabled', r'readonly', r'required'},
    r'track': {r'default'},
    r'video': {r'autoplay', r'controls', r'loop', r'muted'},
    r'*': {r'hidden'}
}


TAG_SETS: tuple = (  # Tuple of tags and their respective closing tags
    ((r'li'), (r'li')),
    ((r'dd', r'dt'), (r'dd', r'dt')),
    ((r'rp', r'rt'), (r'rp', r'rt')),
    ((r'p'), (r'address', r'article', r'aside', r'blockquote', r'dir', r'div', r'dl', r'fieldset', r'footer', r'form', r'h1', r'h2', r'h3', r'h4', r'h5', r'h6', r'header', r'hgroup', r'hr', r'menu', r'nav', r'ol', r'p', r'pre', r'section', r'table', r'ul')),
    ((r'optgroup'), (r'optgroup')),
    ((r'option'), (r'option', r'optgroup')),
    ((r'colgroup'), (r'*')),
    ((r'tbody', r'thead'), (r'tbody', r'tfoot')),
    ((r'tfoot'), (r'tbody')),
    ((r'tr'), (r'tr')),
    ((r'td', r'th'), (r'td', r'th'))
)


XML_DOCTYPES: dict = {  # type: ignore
    r'FREEDESKTOP_DBUS_INTROSPECTION': r'<!DOCTYPE node PUBLIC "-//freedesktop//DTD D-BUS Object Introspection 1.0//EN" "http://www.freedesktop.org/standards/dbus/1.0/introspect.dtd">',
    r'GENTOO_PKGMETADATA': r'<!DOCTYPE pkgmetadata SYSTEM "http://www.gentoo.org/dtd/metadata.dtd">',
    r'HTML5': r'<!DOCTYPE HTML>',
    r'HTML4_STRICT': r'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">',
    r'': r'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">',
    r'HTML4_TRANSITIONAL': r'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">',
    r'HTML4_FRAMESET': r'<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN" "http://www.w3.org/TR/html4/frameset.dtd">',
    r'XHTML_STRICT': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">',
    r'XHTML_TRANSITIONAL': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">',
    r'XHTML_FRAESET': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">',
    r'XHTML_1_1': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN"  "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">',
    r'XHTML_BASIC': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML Basic 1.1//EN" "http://www.w3.org/TR/xhtml-basic/xhtml-basic11.dtd">',
    r'MATHML_2': r'<!DOCTYPE math PUBLIC "-//W3C//DTD MathML 2.0//EN" "http://www.w3.org/Math/DTD/mathml2/mathml2.dtd">',
    r'MATHML_1': r'<!DOCTYPE math SYSTEM "http://www.w3.org/Math/DTD/mathml1/mathml.dtd">',
    r'XHTML_MATHML_SVG': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN" "http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd">',
    r'XHTML_MATHML_SVG_HOST': r'<!DOCTYPE svg:svg PUBLIC "-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN" "http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd">',
    r'SVG': r'<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.0//EN" "http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd">',
    r'SVG_FULL': r'<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">',
    r'SVG_BASIC': r'<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1 Basic//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11-basic.dtd">',
    r'SVG_TINY': r'<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1 Tiny//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11-tiny.dtd">',
    r'HTML2': r'<!DOCTYPE html PUBLIC "-//IETF//DTD HTML 2.0//EN">',
    r'HTML3': r'<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 3.2 Final//EN">',
    r'X3D_3_1': r'<!DOCTYPE X3D PUBLIC "ISO//Web3D//DTD X3D 3.1//EN" "http://www.web3d.org/specifications/x3d-3.1.dtd">',
    r'X3D_3_2': r'<!DOCTYPE X3D PUBLIC "ISO//Web3D//DTD X3D 3.2//EN" "http://www.web3d.org/specifications/x3d-3.2.dtd">',
    r'XHTML_BASIC_1_0': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML Basic 1.0//EN" "http://www.w3.org/TR/xhtml-basic/xhtml-basic10.dtd">',
    r'XHTML_ARIA': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+ARIA 1.0//EN" "http://www.w3.org/WAI/ARIA/schemata/xhtml-aria-1.dtd">',
    r'XHTML_RDF_1_1': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.1//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-2.dtd">',
    r'XHTML_RDF_1': r'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">',
    r'XHTML_MOBILE': r'<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.2//EN" "http://www.openmobilealliance.org/tech/DTD/xhtml-mobile12.dtd">'
}


XML_NAMESPACES: dict = {
    r'ADOBE_CUSTOM': r'http://ns.adobe.com/GenericCustomNamespace/1.0/',
    r'ADOBE_EXTENSIBILITY': r'http://ns.adobe.com/Extensibility/1.0/',
    r'ADOBE_FLOWS': r'http://ns.adobe.com/Flows/1.0/',
    r'ADOBE_GRAPHS': r'http://ns.adobe.com/Graphs/1.0/',
    r'ADOBE_ILLUSTRATOR': r'http://ns.adobe.com/AdobeIllustrator/10.0/',
    r'ADOBE_IMAGE_REPLACEMENT': r'http://ns.adobe.com/ImageReplacement/1.0/',
    r'ADOBE_SFW': r'http://ns.adobe.com/SaveForWeb/1.0/',
    r'ADOBE_SVG_VIEWER': r'http://ns.adobe.com/AdobeSVGViewerExtensions/3.0/',
    r'ADOBE_VARIABLES': r'http://ns.adobe.com/Variables/1.0/',
    r'ADOBE_XPATH': r'http://ns.adobe.com/XPath/1.0/',
    r'ATOM': r'http://www.w3.org/2005/Atom',
    r'CC': r'http://creativecommons.org/ns#',
    r'DC': r'http://purl.org/dc/elements/1.1/',
    r'FOAF': r'http://xmlns.com/foaf/0.1/',
    r'GRDDL': r'http://www.w3.org/2003/g/data-view',
    r'HCALENDAR': r'http://microformats.org/wiki/hcalendar',
    r'HCARD': r'http://www.w3.org/2006/03/hcard',  # hcard http://microformats.org/profile/hcard
    r'HREVIEW': r'http://microformats.org/wiki/hreview',
    r'INKSCAPE': r'http://www.inkscape.org/namespaces/inkscape',
    r'MATHML': r'http://www.w3.org/1998/Math/MathML',
    r'OPENSEARCH': r'http://a9.com/-/spec/opensearch/1.1/',
    r'OSB': r'http://www.openswatchbook.org/uri/2009/osb',
    r'RDF': r'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
    r'RDFS': r'http://www.w3.org/2000/01/rdf-schema#',
    r'SKETCH': r'http://www.bohemiancoding.com/sketch/ns',
    r'SODIPODI': r'http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd',
    r'SVG': r'http://www.w3.org/2000/svg',
    r'VCARD': r'http://www.w3.org/2006/vcard/ns#',
    r'VCARD_V3': r'http://www.w3.org/2001/vcard-rdf/3.0#',
    r'X3D': r'http://www.web3d.org/specifications/x3d-3.2.xsd',
    r'XFN': r'http://www.gmpg.org/xfn/11',
    r'XHTML': r'http://www.w3.org/1999/xhtml',
    r'XSI': r'http://www.w3.org/2001/XMLSchema-instance',
    r'XLINK': r'http://www.w3.org/1999/xlink',
    r'XPATH': r'http://ns.adobe.com/XPath/1.0/',
    r'XSD': r'http://www.w3.org/2001/XMLSchema-instance'
}


SVG_COLORS: dict = {  # type: ignore
    r'aliceblue': r'rgb(240, 248, 255)',
    r'antiquewhite': r'rgb(250, 235, 215)',
    r'aqua': r'rgb(0, 255, 255)',
    r'aquamarine': r'rgb(127, 255, 212)',
    r'azure': r'rgb(240, 255, 255)',
    r'beige': r'rgb(245, 245, 220)',
    r'bisque': r'rgb(255, 228, 196)',
    r'black': r'rgb(0, 0, 0)',
    r'blanchedalmond': r'rgb(255, 235, 205)',
    r'blue': r'rgb(0, 0, 255)',
    r'blueviolet': r'rgb(138, 43, 226)',
    r'brown': r'rgb(165, 42, 42)',
    r'burlywood': r'rgb(222, 184, 135)',
    r'cadetblue': r'rgb(95, 158, 160)',
    r'chartreuse': r'rgb(127, 255, 0)',
    r'chocolate': r'rgb(210, 105, 30)',
    r'coral': r'rgb(255, 127, 80)',
    r'cornflowerblue': r'rgb(100, 149, 237)',
    r'cornsilk': r'rgb(255, 248, 220)',
    r'crimson': r'rgb(220, 20, 60)',
    r'cyan': r'rgb(0, 255, 255)',
    r'darkblue': r'rgb(0, 0, 139)',
    r'darkcyan': r'rgb(0, 139, 139)',
    r'darkgoldenrod': r'rgb(184, 134, 11)',
    r'darkgray': r'rgb(169, 169, 169)',
    r'darkgreen': r'rgb(0, 100, 0)',
    r'darkgrey': r'rgb(169, 169, 169)',
    r'darkkhaki': r'rgb(189, 183, 107)',
    r'darkmagenta': r'rgb(139, 0, 139)',
    r'darkolivegreen': r'rgb(85, 107, 47)',
    r'darkorange': r'rgb(255, 140, 0)',
    r'darkorchid': r'rgb(153, 50, 204)',
    r'darkred': r'rgb(139, 0, 0)',
    r'darksalmon': r'rgb(233, 150, 122)',
    r'darkseagreen': r'rgb(143, 188, 143)',
    r'darkslateblue': r'rgb(72, 61, 139)',
    r'darkslategray': r'rgb(47, 79, 79)',
    r'darkslategrey': r'rgb(47, 79, 79)',
    r'darkturquoise': r'rgb(0, 206, 209)',
    r'darkviolet': r'rgb(148, 0, 211)',
    r'deeppink': r'rgb(255, 20, 147)',
    r'deepskyblue': r'rgb(0, 191, 255)',
    r'dimgray': r'rgb(105, 105, 105)',
    r'dimgrey': r'rgb(105, 105, 105)',
    r'dodgerblue': r'rgb(30, 144, 255)',
    r'firebrick': r'rgb(178, 34, 34)',
    r'floralwhite': r'rgb(255, 250, 240)',
    r'forestgreen': r'rgb(34, 139, 34)',
    r'fuchsia': r'rgb(255, 0, 255)',
    r'gainsboro': r'rgb(220, 220, 220)',
    r'ghostwhite': r'rgb(248, 248, 255)',
    r'gold': r'rgb(255, 215, 0)',
    r'goldenrod': r'rgb(218, 165, 32)',
    r'gray': r'rgb(128, 128, 128)',
    r'grey': r'rgb(128, 128, 128)',
    r'green': r'rgb(0, 128, 0)',
    r'greenyellow': r'rgb(173, 255, 47)',
    r'honeydew': r'rgb(240, 255, 240)',
    r'hotpink': r'rgb(255, 105, 180)',
    r'indianred': r'rgb(205, 92, 92)',
    r'indigo': r'rgb(75, 0, 130)',
    r'ivory': r'rgb(255, 255, 240)',
    r'khaki': r'rgb(240, 230, 140)',
    r'lavender': r'rgb(230, 230, 250)',
    r'lavenderblush': r'rgb(255, 240, 245)',
    r'lawngreen': r'rgb(124, 252, 0)',
    r'lemonchiffon': r'rgb(255, 250, 205)',
    r'lightblue': r'rgb(173, 216, 230)',
    r'lightcoral': r'rgb(240, 128, 128)',
    r'lightcyan': r'rgb(224, 255, 255)',
    r'lightgoldenrodyellow': r'rgb(250, 250, 210)',
    r'lightgray': r'rgb(211, 211, 211)',
    r'lightgreen': r'rgb(144, 238, 144)',
    r'lightgrey': r'rgb(211, 211, 211)',
    r'lightpink': r'rgb(255, 182, 193)',
    r'lightsalmon': r'rgb(255, 160, 122)',
    r'lightseagreen': r'rgb(32, 178, 170)',
    r'lightskyblue': r'rgb(135, 206, 250)',
    r'lightslategray': r'rgb(119, 136, 153)',
    r'lightslategrey': r'rgb(119, 136, 153)',
    r'lightsteelblue': r'rgb(176, 196, 222)',
    r'lightyellow': r'rgb(255, 255, 224)',
    r'lime': r'rgb(0, 255, 0)',
    r'limegreen': r'rgb(50, 205, 50)',
    r'linen': r'rgb(250, 240, 230)',
    r'magenta': r'rgb(255, 0, 255)',
    r'maroon': r'rgb(128, 0, 0)',
    r'mediumaquamarine': r'rgb(102, 205, 170)',
    r'mediumblue': r'rgb(0, 0, 205)',
    r'mediumorchid': r'rgb(186, 85, 211)',
    r'mediumpurple': r'rgb(147, 112, 219)',
    r'mediumseagreen': r'rgb(60, 179, 113)',
    r'mediumslateblue': r'rgb(123, 104, 238)',
    r'mediumspringgreen': r'rgb(0, 250, 154)',
    r'mediumturquoise': r'rgb(72, 209, 204)',
    r'mediumvioletred': r'rgb(199, 21, 133)',
    r'midnightblue': r'rgb(25, 25, 112)',
    r'mintcream': r'rgb(245, 255, 250)',
    r'mistyrose': r'rgb(255, 228, 225)',
    r'moccasin': r'rgb(255, 228, 181)',
    r'navajowhite': r'rgb(255, 222, 173)',
    r'navy': r'rgb(0, 0, 128)',
    r'oldlace': r'rgb(253, 245, 230)',
    r'olive': r'rgb(128, 128, 0)',
    r'olivedrab': r'rgb(107, 142, 35)',
    r'orange': r'rgb(255, 165, 0)',
    r'orangered': r'rgb(255, 69, 0)',
    r'orchid': r'rgb(218, 112, 214)',
    r'palegoldenrod': r'rgb(238, 232, 170)',
    r'palegreen': r'rgb(152, 251, 152)',
    r'paleturquoise': r'rgb(175, 238, 238)',
    r'palevioletred': r'rgb(219, 112, 147)',
    r'papayawhip': r'rgb(255, 239, 213)',
    r'peachpuff': r'rgb(255, 218, 185)',
    r'peru': r'rgb(205, 133, 63)',
    r'pink': r'rgb(255, 192, 203)',
    r'plum': r'rgb(221, 160, 221)',
    r'powderblue': r'rgb(176, 224, 230)',
    r'purple': r'rgb(128, 0, 128)',
    r'red': r'rgb(255, 0, 0)',
    r'rosybrown': r'rgb(188, 143, 143)',
    r'royalblue': r'rgb(65, 105, 225)',
    r'saddlebrown': r'rgb(139, 69, 19)',
    r'salmon': r'rgb(250, 128, 114)',
    r'sandybrown': r'rgb(244, 164, 96)',
    r'seagreen': r'rgb(46, 139, 87)',
    r'seashell': r'rgb(255, 245, 238)',
    r'sienna': r'rgb(160, 82, 45)',
    r'silver': r'rgb(192, 192, 192)',
    r'skyblue': r'rgb(135, 206, 235)',
    r'slateblue': r'rgb(106, 90, 205)',
    r'slategray': r'rgb(112, 128, 144)',
    r'slategrey': r'rgb(112, 128, 144)',
    r'snow': r'rgb(255, 250, 250)',
    r'springgreen': r'rgb(0, 255, 127)',
    r'steelblue': r'rgb(70, 130, 180)',
    r'tan': r'rgb(210, 180, 140)',
    r'teal': r'rgb(0, 128, 128)',
    r'thistle': r'rgb(216, 191, 216)',
    r'tomato': r'rgb(255, 99, 71)',
    r'turquoise': r'rgb(64, 224, 208)',
    r'violet': r'rgb(238, 130, 238)',
    r'wheat': r'rgb(245, 222, 179)',
    r'white': r'rgb(255, 255, 255)',
    r'whitesmoke': r'rgb(245, 245, 245)',
    r'yellow': r'rgb(255, 255, 0)',
    r'yellowgreen': r'rgb(154, 205, 50)'
}


SVG_UNIT: set = {r'em', r'ex', r'px', r'in', r'cm', r'mm', r'pt', r'pc', r'%'}


SVG_UNIT_CONVERSIONS: dict = {  # type: ignore
    None: 1.0,  # Default unit (same as pixel)
    r'px': 1.0,  # Pixel; Default SVG unit
    r'em': 1.328352013,  # Pixels per width of the letter `m`
    r'ex': 5.0,  # Pixels per element x-height
    r'in': 96.0,  # Pixels per inch
    r'cm': 37.79527559,  # Pixels per centimeter
    r'mm': 3.779527559,  # Pixels per millimeter
    r'pt': 1.3333333,  # Pixels per point
    r'pc': 16.0,  # Pixels per pica
    r'%': 0.01  # Pixels per percent
}


SVG_STYLES: frozenset = frozenset({
    r'alignment-baseline',
    r'baseline-shift',
    r'clip-path',
    r'clip-rule',
    r'color-interpolation',
    r'color-interpolation-filters',
    r'color-profile',
    r'color-rendering',
    r'direction',
    r'dominant-baseline',
    r'fill',
    r'fill-opacity',
    r'fill-rule',
    r'font',
    r'font-family',
    r'font-size',
    r'font-size-adjust',
    r'font-stretch',
    r'font-style',
    r'font-variant',
    r'font-weight',
    r'glyph-orientation-horizontal',
    r'glyph-orientation-vertical',
    r'image-rendering',
    r'kerning',
    r'letter-spacing',
    r'marker',
    r'marker-end',
    r'marker-mid',
    r'marker-start',
    r'mask',
    r'opacity',
    r'pointer-events',
    r'shape-rendering',
    r'stop-color',
    r'stop-opacity',
    r'stroke',
    r'stroke-dasharray',
    r'stroke-dashoffset',
    r'stroke-linecap',
    r'stroke-linejoin',
    r'stroke-miterlimit',
    r'stroke-opacity',
    r'stroke-width',
    r'text-anchor',
    r'text-decoration',
    r'text-rendering',
    r'unicode-bidi',
    r'word-spacing',
    r'writing-mode'
})


SVG_TINY_STYLES: frozenset = frozenset({
    r'audio-level',
    r'buffered-rendering',
    r'display-align',
    r'line-increment',
    r'solid-color',
    r'solid-opacity',
    r'text-align',
    r'vector-effect',
    r'viewport-fill',
    r'viewport-fill-opacity'
})


SVG_POSITION_ATTR: dict = {  # type: ignore
    r'circle': (r'cx', r'cy'),
    r'ellipse': (r'cx', r'cy'),
    r'line': (r'x1', r'y1', r'x2', r'y2'),
    r'rect': (r'x', r'y'),
    r'tspan': (r'x', r'y')
}


SVG_SCALING_ATTR: dict = {r'rect': {r'x', r'y', r'width', r'height'}}  # type: ignore


MIMETYPE_CORRECTIONS: tuple = (
    # (Incorrect, Correct)
    (r'application/xml+xhtml', r'application/xhtml+xml'),
    (r'image/svg-xml', r'image/svg+xml'),
    (r'text/xml', r'application/xml'),
    (r'text/xml+html', r'application/xhtml+xml')
)


_ALPHASET: set = {
    r'a', r'b', r'c', r'd', r'e', r'f', r'g', r'h', r'i', r'j', r'k', r'l', r'm', r'n', r'o', r'p', r'q', r'r', r's', r't', r'u', r'v', r'w', r'x', r'y', r'z', r'=', r'/', r'A', r'B', r'C', r'D', r'E', r'F', r'G', r'H', r'I', r'J', r'K', r'L', r'M', r'N', r'O', r'P', r'Q', r'R', r'S', r'T', r'U', r'V', r'W', r'X', r'Y', r'Z'
}


# ASSERTION FUNCTIONS #


def assert_is_xml(_doc_type: int, data: str, _filename: str) -> None:
    """Ensure input data is valid XML data; otherwise, raise an exception."""
    if r'<' not in data or r'>' not in data:
        stderr.write(r'Unsupported filetype (' + _filename + ')!\n')
        raise SystemExit(1)
    if _doc_type == FILETYPE_DTD and r'<!ELEMENT ' not in data and r'<!ATTLIST ' not in data:
        stderr.write(r'Invalid DTD file (' + _filename + ')!\n')
        raise SystemExit(1)
    if _doc_type == FILETYPE_XSD and r'</xs:schema>' not in data and r'<xs:element ' not in data:
        stderr.write(r'Invalid XSD file (' + _filename + ')!\n')
        raise SystemExit(1)


# BOOLEAN TESTS #


def is_in_tagstack(tag: str, _tag_stack: list) -> bool:
    """Test if the given tag is in the tag-stack."""
    return any((_tag[0] == tag for _tag in _tag_stack))


def is_removable_metadata_attr(remove_metadata: int, attr: str) -> bool:
    """Determine if the given data is a removable metadata attribute."""
    if remove_metadata < 2:
        return False
    if r'xmlns:' in attr and attr in JUNK_ATTR:  # XMLNS attribute
        return True
    if r':' in attr and r'xmlns:' not in attr and attr.split(r':')[0] + r':' in JUNK_NS:  # Namespace attribute
        return True
    return False


def is_removable_metadata_tag(doc_type: int, tag: str, _in_metadata: bool = False, remove_metadata: int = 2) -> bool:
    """Determine if the given data is a removable metadata tag."""
    if tag == r'namedview':
        return True
    if remove_metadata < 1:
        return False
    if _in_metadata or (remove_metadata > 0 and doc_type == FILETYPE_SVG and tag in {r'desc', r'title'}):
        return True
    if remove_metadata == 2 and r':' in tag and tag.split(r':')[0] + r':' in JUNK_NS:  # Namespace tags
        return True
    return False


def is_self_closing_tag(_tag: str, _doc_type: int, _tag_stack: list) -> bool:  # noqa: R701
    """Test if the given tag is a self-closing tag for the given XML document type."""
    if _tag in CC_NO_CLOSE_TAGS or _tag in DC_NO_CLOSE_TAGS:
        return True
    if _doc_type == FILETYPE_SVG or is_in_tagstack(r'svg', _tag_stack):  # SVG
        if _tag in SVG_NO_CLOSE_TAGS:
            return True
    elif _doc_type == FILETYPE_HTML or is_in_tagstack(r'html', _tag_stack):  # HTML
        if _tag in HTML_NO_CLOSE_TAGS:
            return True
    elif _doc_type == FILETYPE_XML and is_in_tagstack(r'mime-info', _tag_stack):  # XDG Freedesktop Mime-type XML
        if _tag in MIMETYPE_NO_CLOSE_TAGS and is_in_tagstack(r'mime-type', _tag_stack):
            return True
    elif _doc_type == FILETYPE_XML and is_in_tagstack(r'interface', _tag_stack):  # Glade XML
        if _tag in {r'accelerator', r'requires', r'signal'}:
            return True
    return False


def is_xml_dtd(xmldata: str) -> bool:
    """Return true if the given data is DTD."""
    return bool(r'<!ELEMENT ' in xmldata and r'<!ATTLIST ' in xmldata)


def is_xml_xsd(xmldata: str) -> bool:
    """Return true if the given data is XSD."""
    return bool(r'</xs:schema>' in xmldata and r'<xs:element ' in xmldata)


# ESCAPE MANIPULATIONS #


def escape(_str: str, quote: bool = True) -> str:
    """Replace special characters `&`, `<`, and `>` to HTML-safe sequences.

    If the optional flag quote is true (default), quotation mark
    characters, double-quotes, and single-quotes are also translated.

    >>> escape('String with "special" characters')
    'String with &quot;special&quot; characters'
    >>> escape('String without "special" characters', False)
    'String without "special" characters'
    >>> escape('This <b>is</b> a "test" (&).')
    'This &lt;b&gt;is&lt;/b&gt; a &quot;test&quot; (&amp;).'
    >>> escape('This <b>is</b> a "test" (&).', False)
    'This &lt;b&gt;is&lt;/b&gt; a "test" (&amp;).'
    """
    _str = _str.replace(r'&', r'&amp;')
    _str = _str.replace(r'<', r'&lt;').replace(r'>', r'&gt;')
    if quote:
        return _str.replace(r'"', r'&quot;').replace('\'', r'&#39;')
    return _str


def escape_ambiguous_ampersand(val: str) -> str:  # noqa: C901,R701  # pylint: disable=R0912,R0915
    """Escape the ampersand character.

    >>> escape_ambiguous_ampersand('This is a test &amp; example.')
    'This is a test &amp;amp; example.'
    """
    if r'&' not in val:
        return val
    state = 0
    result: List[str] = []
    amp_buff: List[str] = []
    for char in val:
        if state == 0:  # Beginning
            if char == r'&':
                state = 1
                continue
            result.append(char)
        elif state == 1:  # Ampersand
            ord_c = ord(char)
            if 65 <= ord_c <= 90 or 97 <= ord_c <= 122 or 48 <= ord_c <= 57:
                amp_buff.append(char)
                continue
            if char == r'#':
                state = 2
                continue
            if char == r';':
                if amp_buff:
                    result.append(r'&amp;')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&;')
                state = 0
                amp_buff = []
                continue
            if char == r'&':
                if amp_buff:
                    result.append(r'&amp;')
                    result.extend(amp_buff)
                else:
                    result.append(r'&')
                amp_buff = []
                continue
            result.append(r'&')
            result.extend(amp_buff)
            result.append(char)
            state = 0
            amp_buff = []
        elif state == 2:  # Numeric character reference
            ord_c = ord(char)
            if char in {r'x', r'X'}:
                state = 3
                continue
            if 48 <= ord_c <= 57:
                amp_buff.append(char)
                continue
            if char == r';':
                if amp_buff:
                    result.append(r'&amp;#')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&#;')
                state = 0
                amp_buff = []
                continue
            if char == r'&':
                if amp_buff:
                    result.append(r'&amp;#')
                    result.extend(amp_buff)
                else:
                    result.append(r'&#')
                state = 1
                amp_buff = []
                continue
            if amp_buff:
                result.append(r'&amp;#')
                result.extend(amp_buff)
                result.append(char)
            else:
                result.append(r'&#')
                result.append(char)
            state = 0
            amp_buff = []
        elif state == 3:  # Hex character reference
            ord_c = ord(char)
            if 65 <= ord_c <= 70 or 97 <= ord_c <= 102 or 48 <= ord_c <= 57:
                amp_buff.append(char)
                continue
            if char == r';':
                if amp_buff:
                    result.append(r'&amp;#x')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&#x;')
                state = 0
                amp_buff = []
                continue
            if char == r'&':
                if amp_buff:
                    result.append(r'&amp;#x')
                    result.extend(amp_buff)
                else:
                    result.append(r'&#x')
                state = 1
                amp_buff = []
                continue
            if amp_buff:
                result.append(r'&amp;#x')
                result.extend(amp_buff)
                result.append(char)
            else:
                result.append(r'&#x')
                result.append(char)
            state = 0
            amp_buff = []
    if state == 1:
        result.append(r'&amp;')
        result.extend(amp_buff)
    elif state == 2:
        result.append(r'&amp;#')
        result.extend(amp_buff)
    elif state == 3:
        result.append(r'&amp;#x')
        result.extend(amp_buff)
    return r''.join(result)


def escape_attr_value(val: str, double_quote: bool = False) -> tuple:
    """Escape attribute values."""
    val = escape_ambiguous_ampersand(val)
    if double_quote:  # pylint: disable=R1705
        return (val.replace(r'"', r'&#34;'), DOUBLE_QUOTE)
    if r'"' in val:
        if '\'' in val:
            return (val.replace(r'"', r'&#34;'), DOUBLE_QUOTE)
        return (val, SINGLE_QUOTE)
    if '\'' in val:
        return (val, DOUBLE_QUOTE)
    if not val or any((c.isspace() for c in val)):
        return (val, DOUBLE_QUOTE)
    return (val, NO_QUOTES)


def htmlunescape(_str: str) -> str:
    """Unescape `&`, `'`, `"`, `<`, and `>`.

    >>> htmlunescape('This &#x3c;b&#62;is&lt;/b&gt; a &#34;test&quot; (&amp;).')
    'This <b>is</b> a "test" (&).'
    >>> htmlunescape('This &lt;b&gt;is&lt;/b&gt; a &quot;test&quot; (&amp;).')
    'This <b>is</b> a "test" (&).'
    """
    if r'&' not in _str:
        return _str
    _str = _str.replace(r'&#x27;', r'\'').replace(r'&x27;', r'\'').replace(r'&#39;', r'\'').replace(r'&apos;', r'\'')
    _str = _str.replace(r'&#x22;', r'"').replace(r'&x22;', r'"').replace(r'&#34;', r'"').replace(r'&quot;', r'"')
    _str = _str.replace(r'&#x3c;', r'<').replace(r'&x3c;', r'<').replace(r'&#60;', r'<').replace(r'&lt;', r'<')
    _str = _str.replace(r'&#x3e;', r'>').replace(r'&x3e;', r'>').replace(r'&#62;', r'>').replace(r'&gt;', r'>')
    return _str.replace(r'&#x26;', r'&').replace(r'&x26;', r'&').replace(r'&#38;', r'&').replace(r'&amp;', r'&')


def int2refnum(_int: int) -> str:
    """Convert an integer to Decimal-NCR/HTML-Entity (&#38;)."""
    if 0 <= _int <= 1114111:
        return fr'&#{_int};'
    raise ValueError(fr'Integer value out of valid Unicode range (0 - {1114111})!')


# SVG FUNCTIONS #


def parse_svg_size(value: str, def_units: str = r'px') -> float:  # noqa: C901,R701
    """Parse value as SVG length and returns the value in pixels (or a negative scale: -1 = 100%)."""
    if not value:
        return 0.0
    if not isinstance(value, str):
        raise Exception(r'Invalid datatype for `value` in `parse_svg_size()`!')
    parts = SVG_SIZE.match(str(value))
    if not parts:
        raise Exception(fr'Unknown length format: "{value}"')
    num = float(parts.group(1))
    units = parts.group(2) or def_units
    if units == r'px':
        return float(num)
    if units == r'pt':
        return num * 1.25
    if units == r'pc':
        return num * 15.0
    if units == r'in':
        return num * 90.0
    if units == r'mm':
        return num * 3.543307
    if units == r'cm':
        return num * 35.43307
    if units == r'%':
        return -num / 100.0
    raise Exception(fr'Unknown length units: "{units}"')


def svgviewbox2pixels(viewbox: List[Union[float, int, str]]) -> Optional[List[float]]:
    """Convert the measurements of an SVG viewbox to pixels."""
    _viewbox: List[float] = [0.0, 0.0, 0.0, 0.0]
    if len(viewbox) == 4 and isinstance(viewbox[0], str) and isinstance(viewbox[1], str) and isinstance(viewbox[2], str) and isinstance(viewbox[3], str):
        _viewbox[0] = parse_svg_size(viewbox[0])
        _viewbox[1] = parse_svg_size(viewbox[1])
        _viewbox[2] = parse_svg_size(viewbox[2])
        _viewbox[3] = parse_svg_size(viewbox[3])
    elif len(viewbox) == 4 and isinstance(viewbox[0], (float, int)):
        _viewbox[0] = float(viewbox[0])
        _viewbox[1] = float(viewbox[1])
        _viewbox[2] = float(viewbox[2])
        _viewbox[3] = float(viewbox[3])
    else:
        return None
    if _viewbox[2] * _viewbox[3] <= 0.0:
        return None
    return _viewbox


def resize_svg(xmltree: ET.ElementTree, options: dict) -> None:  # noqa: C901,R701  # pylint: disable=R0912,R0914,R0915
    """Resize an SVG tree based on the specified options."""
    svg = xmltree.getroot()
    viewbox: Optional[List[float]] = svgviewbox2pixels(SVG_VIEWBOX_SEP.split(svg.get(r'viewBox', r'').strip()))  # type: ignore
    if r'width' not in svg.keys() or r'height' not in svg.keys():
        if viewbox and len(viewbox) == 4 and isinstance(viewbox[2], float) and isinstance(viewbox[3], float):
            width: float = viewbox[2]
            height: float = viewbox[3]
        else:
            raise Exception(r'The SVG header must contain width and height attributes!')
    else:
        width = parse_svg_size(svg.get(r'width'))  # type: ignore
        height = parse_svg_size(svg.get(r'height'))  # type: ignore
    if width <= 0.0 or height <= 0.0:
        if viewbox and len(viewbox) == 4 and isinstance(viewbox[2], float) and isinstance(viewbox[3], float):
            width = viewbox[2]
            height = viewbox[3]
        else:
            raise Exception(r'SVG width and height must be in absolute units and non-zero!')
    elif not viewbox:
        viewbox = [0.0, 0.0, width, height]
    # Read and convert size and margin values
    margin: float = parse_svg_size(options[r'margin'], r'px')
    twidth: float = 0.0
    theight: float = 0.0
    if options[r'width']:
        twidth = parse_svg_size(options[r'width'], r'px')
    if options[r'height']:
        theight = parse_svg_size(options[r'height'], r'px')
    if options[r'longest']:
        value = parse_svg_size(options[r'longest'], r'px')
        if width > height:
            twidth = value
        else:
            theight = value
    if options[r'shortest']:
        value = parse_svg_size(options[r'shortest'], r'px')
        if width < height:
            twidth = value
        else:
            theight = value
    # twidth and theight are image dimensions without margins
    if twidth < 0.0:
        twidth = -width * twidth
    elif twidth > 0.0:
        twidth = max(0.0, twidth - margin * 2.0)
    if theight < 0.0:
        theight = -height * theight
    elif theight > 0:
        theight = max(0.0, theight - margin * 2.0)
    if twidth == 0.0:
        if theight == 0.0:
            twidth = width
            theight = height
        else:
            twidth = (theight / height) * width
    if not theight:
        theight = (twidth / width) * height
    # Set svg width and height, update viewport for margin
    svg.set(r'width', fr'{twidth + margin * 2.0}px')
    svg.set(r'height', fr'{theight + margin * 2.0}px')
    offsetx: float = 0.0
    offsety: float = 0.0
    if (twidth / theight) > (viewbox[2] / viewbox[3]):  # Target page is wider than source image
        page_width = (viewbox[3] / theight) * twidth
        offsetx = (page_width - viewbox[2]) / 2.0
        page_height = viewbox[3]
    else:
        page_width = viewbox[2]
        page_height = viewbox[2] / twidth * theight
        offsety = (page_height - viewbox[3]) / 2.0
    vb_margin: float = page_width / twidth * margin
    svg.set(r'viewBox', fr'{viewbox[0] - vb_margin - offsetx} {viewbox[1] - vb_margin - offsety} {page_width + vb_margin * 2.0} {page_height + vb_margin * 2.0}')
    # Add frame
    if options[r'frame']:
        layer = ET.SubElement(svg, r'g', nsmap=INKSCAPE_NAMESPACES)  # type: ignore
        layer.set(r'{{' + INKSCAPE_NAMESPACES[r'inkscape'] + r'}}groupmode', r'layer')
        layer.set(r'{{' + INKSCAPE_NAMESPACES[r'inkscape'] + r'}}label', r'Frame')
        layer.set(r'{{' + INKSCAPE_NAMESPACES[r'sodipodi'] + r'}}insensitive', r'true')
        frame = ET.SubElement(layer, r'path')
        frame.set(r'style', r'fill:#fff;stroke:none')
        bleed: float = min(page_width, page_height) / 100.0
        _vtmp: float = page_height + (vb_margin + bleed) * 2.0
        frame.set(r'd', fr'M {-viewbox[0] - vb_margin - offsetx - bleed} {-viewbox[1] - vb_margin - offsety - bleed} v {_vtmp} h {page_width + (vb_margin + bleed) * 2.0} v -{_vtmp} z M {viewbox[0]} {viewbox[1]} h {viewbox[2]} v {viewbox[3]} h -{viewbox[2]} z')


def remove_duplicated_svg_ns(xmldata: str) -> str:
    """Remove duplicated SVG XML-namespace declarations."""
    if r'xmlns:svg="http://www.w3.org/2000/svg"' in xmldata and r'xmlns="http://www.w3.org/2000/svg"' in xmldata and r'<svg:' not in xmldata:
        xmldata = xmldata.replace(r'xmlns:svg="http://www.w3.org/2000/svg"', r'')
    return xmldata


def repair_svg_tag(_tag: str) -> str:
    """Auto-correct commonly mistyped/illformed SVG tag names."""
    if _tag.startswith(r'fe'):
        _tag = _tag.replace(r'feblend', r'feBlend').replace(r'fecolormatrix', r'feColorMatrix').replace(r'fecomponenttransfer', r'feComponentTransfer').replace(r'fecomposite', r'feComposite').replace(r'feconvolvematrix', r'feConvolveMatrix').replace(r'feDiffuseLighting', r'fediffuselighting').replace(r'fedisplacementmap', r'feDisplacementMap')
        _tag = _tag.replace(r'fedistantlight', r'feDistantLight').replace(r'feflood', r'feFlood').replace(r'fefunca', r'feFuncA').replace(r'fefuncb', r'feFuncB').replace(r'fefuncg', r'feFuncG').replace(r'fefuncr', r'feFuncR').replace(r'fegaussianblur', r'feGaussianBlur').replace(r'feimage', r'feImage').replace(r'femerge', r'feMerge')
        _tag = _tag.replace(r'femergenode', r'feMergeNode').replace(r'femorphology', r'feMorphology').replace(r'feoffset', r'feOffset').replace(r'fepointlight', r'fePointLight').replace(r'fespecularlighting', r'feSpecularLighting').replace(r'fespotlight', r'feSpotLight').replace(r'fetile', r'feTile').replace(r'feturbulence', r'feTurbulence')
    else:
        _tag = _tag.replace(r'foreignobject', r'foreignObject').replace(r'glyphref', r'glyphRef').replace(r'lineargradient', r'linearGradient').replace(r'radialgradient', r'radialGradient').replace(r'textpath', r'textPath')
        _tag = _tag.replace(r'solidColor', r'solidcolor').replace(r'polyLine', r'polyline').replace(r'colorprofile', r'color-profile').replace(r'colorProfile', r'color-profile').replace(r'fontface', r'font-face').replace(r'fontFace', r'font-face')
    return _tag


def repair_svg_attr(_tag: str, _attr: str) -> str:  # noqa: R701
    """Auto-correct commonly mistyped/illformed SVG attribute names."""
    if _tag == r'svg' and _attr.casefold() == r'viewbox':
        _attr = r'viewBox'
    elif _tag == r'feGaussianBlur':
        if _attr == r'stddeviation':
            _attr = r'stdDeviation'
    elif _tag == r'linearGradient':
        if _attr == r'gradienttransform':
            _attr = r'gradientTransform'
        elif _attr == r'gradientunits':
            _attr = r'gradientUnits'
    elif _tag == r'radialGradient':
        if _attr == r'gradienttransform':
            _attr = r'gradientTransform'
        elif _attr == r'gradientunits':
            _attr = r'gradientUnits'
    return _attr


# MINIFY FUNCTIONS #


def condense_hex_colors(_css: str) -> str:
    """Shorten colors from `#AABBCC` to `#ABC` (where possible).

    >>> condense_hex_colors('#112233')
    '#123'
    >>> condense_hex_colors('#AaBBcc')
    '#ABC'
    >>> condense_hex_colors('#1deEC5')
    '#1deEC5'
    >>> condense_hex_colors('#11eECc')
    '#1EC'
    """
    match = HEX_COLOR.search(_css)
    while match:
        first = match.group(2) + match.group(4) + match.group(6)
        second = match.group(3) + match.group(5) + match.group(7)
        if first.casefold() == second.casefold():
            _css = _css.replace(match.group(), r'#' + first.upper())
            match = HEX_COLOR.search(_css, match.end() - 3)
        else:
            match = HEX_COLOR.search(_css, match.end())
    return _css


def attribute_cleaner(_tag: str, _attr: str, _val: str, _doc_type: int) -> tuple:  # noqa: C901,R701  # pylint: disable=R0912
    """Clean-up cetain XML/HTML attributes and values."""
    _attr = _attr.strip()
    _val = rmspecialwhitespace(_val.strip())
    if _attr == r'id':  # Remove spaces from id attribute
        _val = _val.replace(r' ', r'')
    if _attr == r'encoding':  # Normalize encoding attribute
        return (_attr, _val.upper())
    if _attr == r'xmlns:xlink':  # Correct any invalid XLink Namespaces
        return (_attr, r'http://www.w3.org/1999/xlink')
    if _attr == r'type' and _tag in TAGS_WITH_MIMETYPES:  # Correct mimetypes
        for mime_correct in MIMETYPE_CORRECTIONS:
            _val = _val.replace(mime_correct[0], mime_correct[1])
    elif _doc_type == FILETYPE_SVG:  # SVG-specific modifications
        if NUMBER.match(_val):  # Trim trailing zeros in floats and round certain floats
            if r'.9999' in _val or r'.0000' in _val:
                _val = str(round(float(_val)))
            elif r'.' in _val:
                _val = str(float(_val))
        elif _attr in {r'color', r'stop-color', r'style'} and r'#' in _val:  # Condense CSS Hex Colors
            return (_attr, condense_hex_colors(_val))
        elif _tag == r'svg' and _attr in {r'height', r'width', r'viewBox'}:  # Remove id from <stop>
            _val = _val.replace(r'.0px', r'').replace(r'.0pt', r'pt').replace(r'.0%', r'%').replace(r'.0 ', r' ')
        elif _tag == r'stop' and _attr == r'id':  # Remove id from <stop>
            return (r'', r'')
        elif _tag == r'feGaussianBlur' and _attr == r'collect':  # collect is useless in feGaussianBlur
            return (r'', r'')
        elif _tag == r'path' and _attr == r'xlink:href':  # xlink:href is useless in path
            return (r'', r'')
        elif _tag in {r'g', r'circle', r'rect'} and _attr == r'id' and NUMBER.match(_val.replace(r'x', r'').replace(r'p', r'')):  # Remove invalid id from various tags
            return (r'', r'')
    return (_attr, _val.replace(r'  ', r' '))


# PRETTIFY FUNCTIONS #


def attr_sort(_attr: tuple) -> str:
    """Sort attributes alphanumerically (but with `xmlns` first)."""
    return str((not _attr[0].startswith(r'xmlns:') and _attr[0].startswith(r'xmlns')) or _attr[0].startswith(r'xmlns:') or _attr[0])


def prettify_xml_schema(schema_data: str) -> str:
    """Prettify DTD and XSD XML schemas."""
    if not XML_DECLARATION.search(schema_data):
        schema_data = r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>' + schema_data
    schema_data = schema_data.replace('\n', r' ').replace('\r', r' ').replace('\t\t', r' ').replace('\t', r' ').replace(r'   ', r' ').replace('\f', r'').replace('\v', r'')
    schema_data = schema_data.replace(r'   ', r' ').replace(r'   ', r' ').replace(r'  ', r' ')
    return schema_data.replace(r' />', r'/>').replace(r'  ', r' ').replace(r'>  <', r'><').replace(r'> <', r'><').strip().replace(r'><', '>\n<')


# XML REPAIR FUNCTIONS #


def fix_xml_declaration(xmldata: str) -> str:
    """Fix and tweak the XML declaration specifically for the XML type."""
    if XML_DECLARATION.search(xmldata):
        if r'<!DOCTYPE html>' in xmldata:
            xmldata = resub(XML_DECLARATION, r'', xmldata)
        elif r'<mime-info xmlns="http://www.freedesktop.org/standards/shared-mime-info">' in xmldata:
            xmldata = resub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>', xmldata)
        elif r' standalone="yes"' in xmldata:
            xmldata = resub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>', xmldata)
        else:
            xmldata = resub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>', xmldata)
    return xmldata


def insert_missing_xml_namespaces(xmldata: str) -> str:  # noqa: R701
    """Insert missing XML namespaces based on present namespaced XML tags."""
    if not CC_NS.search(xmldata) and r'cc:' in xmldata:
        xmldata = xmldata.replace(r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'"', r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'" xmlns:cc="' + XML_NAMESPACES[r'CC'] + r'"')
    if not DC_NS.search(xmldata) and r'dc:' in xmldata:
        xmldata = xmldata.replace(r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'"', r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'" xmlns:dc="' + XML_NAMESPACES[r'DC'] + r'"')
    if not INKSCAPE_NS.search(xmldata) and r'inkscape:' in xmldata:
        xmldata = xmldata.replace(r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'"', r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'" xmlns:inkscape="' + XML_NAMESPACES[r'INKSCAPE'] + r'"')
    if not RDF_NS.search(xmldata) and r'rdf:' in xmldata:
        xmldata = xmldata.replace(r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'"', r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'" xmlns:rdf="' + XML_NAMESPACES[r'RDF'] + r'"')
    if not SODIPODI_NS.search(xmldata) and r'sodipodi:' in xmldata:
        xmldata = xmldata.replace(r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'"', r' xmlns="' + XML_NAMESPACES[r'SVG'] + r'" xmlns:sodipodi="' + XML_NAMESPACES[r'SODIPODI'] + r'"')
    return xmldata


# CLASSES #


class ParserBase:  # pylint: disable=R0902
    """Parser class that provides common support methods used by the SGML/HTML & XHTML parsers."""

    def __init__(self) -> None:
        """Initialize basic parser."""
        self._data_buffer: list = []
        self._decl_otherchars: str = r''
        self.convrefs: bool = False
        self.doc_type: int = FILETYPE_XML
        self.keep_pre: bool = False
        self.lineno: int = 1
        self.offset: int = 0
        self.pre_attr: str = r'pre'
        self.pre_tags: tuple = PRE_TAGS
        self.rawdata: str = r''
        self.reduce_bool_attrs: bool = False
        self.reduce_empty_attributes: bool = False
        self.remove_all_empty_space: bool = True
        self.remove_comments: bool = True
        self.remove_empty_space: bool = True
        self.remove_metadata: int = 0
        self.remove_opt_attr_quotes: bool = False
        if self.__class__ is ParserBase:
            raise RuntimeError(r'ParserBase must be subclassed')

    def error(self, message: str) -> None:
        """Raise error in parser (To be overridden)."""
        raise NotImplementedError(message)

    def reset(self) -> None:
        """Reset location counters."""
        self.lineno = 1
        self.offset = 0

    def getpos(self) -> tuple:
        """Return current line number and offset."""
        return self.lineno, self.offset

    def updatepos(self, i: int, j: int) -> int:
        """Update line number and offset; Should be called for each piece of data once and in order."""
        if i >= j:
            return j
        rawdata: str = self.rawdata
        nlines: int = rawdata.count('\n', i, j)
        if nlines:
            self.lineno = self.lineno + nlines
            pos = rawdata.rindex('\n', i, j)
            self.offset = j - (pos + 1)
        else:
            self.offset = self.offset + j - i
        return j

    def handle_comment(self, data: str) -> None:
        """Process comments."""
        if not self.remove_comments or (data and (data[0] == r'!' or rgxmatch(r'^\[if\s', data))):
            _tmp = data[1:] if data[0] == r'!' else data
            self._data_buffer.append(fr'<!--{_tmp}-->')

    def handle_decl(self, decl: str) -> None:  # pylint: disable=R0201,W0613
        """Handle declaration (Overridable)."""
        return

    def parse_declaration(self, i: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912
        """Parse declaration tags."""
        rawdata: str = self.rawdata
        j = i + 2
        if rawdata[i:j] != r'<!':
            raise Exception(r'Unexpected call to parse_declaration')
        if rawdata[j:j + 1] == r'>':  # Empty comment <!>
            return j + 1
        if rawdata[j:j + 1] in {r'-', r''}:  # Start of buffer boundary (with or without a comment)
            return -1
        # A simple, practical version could look like: ((name|stringlit) S*) + '>'
        if rawdata[j:j + 2] == r'--':  # Comment
            return self.parse_comment(i)  # Locate --.*-- as the body of the comment
        if rawdata[j] == r'[':  # Marked section
            return self.parse_marked_section(i)
        decltype, j = self._scan_name(j, i)  # All other declaration elements
        if j < 0:
            return j
        if decltype == r'doctype':
            self._decl_otherchars = r''
        length: int = len(rawdata)
        while j < length:
            char = rawdata[j]
            if char == r'>':  # End of declaration syntax
                data = rawdata[i + 2:j]
                if decltype == r'doctype':
                    self.handle_decl(data)
                else:
                    self.unknown_decl(data)
                return j + 1
            if char in '"\'':
                _match = DECLSTRINGLIT_MATCH(rawdata, j)
                if not _match:  # Incomplete
                    return -1
                j = _match.end()
            elif char in _ALPHASET:
                name, j = self._scan_name(j, i)
                del name
            elif char in self._decl_otherchars:
                j = j + 1
            elif char == r'[':
                if decltype == r'doctype':
                    j = self._parse_doctype_subset(j + 1, i)
                elif decltype in {r'attlist', r'element', r'link', r'linktype'}:
                    self.error(fr'Unsupported `[` char in {decltype} declaration')
                else:
                    self.error(r'Unexpected `[` char in declaration')
            else:
                self.error(fr'Unexpected {rawdata[j]} char in declaration')
            if j < 0:
                return j
        return -1  # Incomplete

    def parse_marked_section(self, i: int, report: int = 1) -> int:
        """Parse a marked section."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 3] != r'<![':
            raise Exception(r'Unexpected call to parse_marked_section()')
        sectname, j = self._scan_name(i + 3, i)
        if j < 0:  # pylint: disable=R1705
            return j
        if sectname in {r'cdata', r'ignore', r'include', r'rcdata', r'temp'}:
            _match = MARKEDSECTIONCLOSE.search(rawdata, i + 3)  # Look for standard ]]> ending
        elif sectname in {r'if', r'else', r'endif'}:
            _match = MSMARKEDSECTIONCLOSE.search(rawdata, i + 3)  # Look for MS Office ]> ending
        else:
            self.error(fr'Unknown status keyword {rawdata[i + 3:j]} in marked section')
        if not _match:
            return -1
        if report:
            j = _match.start(0)
            self.unknown_decl(rawdata[i + 3: j])
        return _match.end(0)

    def parse_comment(self, i: int, report: int = 1) -> int:
        """Parse comment, return length or -1 (if not terminated)."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 4] != r'<!--':
            self.error(r'Unexpected call to parse_comment()')
        match = COMMENTCLOSE.search(rawdata, i + 4)
        if not match:  # pylint: disable=R1705
            return -1
        elif report:
            j = match.start(0)
            self.handle_comment(rawdata[i + 4: j])
        return match.end(0)

    def _parse_doctype_subset(self, i: int, declstartpos: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912
        """Scan past the internal subset in a <!DOCTYPE declaration, returning the index just past any whitespace following the trailing ']'."""
        rawdata: str = self.rawdata
        length: int = len(rawdata)
        j: int = i
        while j < length:
            char = rawdata[j]
            if char == r'<':  # pylint: disable=R1705
                _str = rawdata[j:j + 2]
                if _str == r'<':  # End of buffer; incomplete
                    return -1
                if _str != r'<!':
                    self.updatepos(declstartpos, j + 1)
                    self.error(fr'Unexpected char in internal subset (in {_str})')
                if (j + 2) == length or (j + 4) > length:  # End of buffer; incomplete
                    return -1
                if rawdata[j:j + 4] == r'<!--':
                    j = self.parse_comment(j, report=0)
                    if j < 0:
                        return j
                    continue
                name, j = self._scan_name(j + 2, declstartpos)
                if j == -1:
                    return -1
                if name not in {r'attlist', r'element', r'entity', r'notation'}:
                    self.updatepos(declstartpos, j + 2)
                    self.error(fr'Unknown declaration {name} in internal subset')
                # Handle the individual names
                meth = getattr(self, r'_parse_doctype_' + name)
                j = meth(j, declstartpos)
                if j < 0:
                    return j
            elif char == r'%':  # Parameter entity reference
                if (j + 1) == length:  # End of buffer; incomplete
                    return -1
                _str, j = self._scan_name(j + 1, declstartpos)
                if j < 0:
                    return j
                if rawdata[j] == r';':
                    j += 1
            elif char == r']':
                j += 1
                while j < length and rawdata[j].isspace():
                    j += 1
                if j < length:
                    if rawdata[j] == r'>':
                        return j
                    self.updatepos(declstartpos, j)
                    self.error(r'Unexpected char after internal subset')
                else:
                    return -1
            elif char.isspace():
                j += 1
            else:
                self.updatepos(declstartpos, j)
                self.error(fr'Unexpected char {char} in internal subset')
        return -1  # End of buffer reached

    def _parse_doctype_element(self, i: int, declstartpos: int) -> int:
        """Scan past <!ELEMENT declarations."""
        name, j = self._scan_name(i, declstartpos)
        if j == -1 or name is None:
            return -1
        # Style content model; skip until '>'
        rawdata: str = self.rawdata
        if r'>' in rawdata[j:]:
            return rawdata.find(r'>', j) + 1
        return -1

    def _parse_doctype_attlist(self, i: int, declstartpos: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912
        """Scan past <!ATTLIST declarations."""
        rawdata: str = self.rawdata
        name, j = self._scan_name(i, declstartpos)
        char: str = rawdata[j:j + 1]
        if char == r'' or name is None:
            return -1
        if char == r'>':
            return j + 1
        while 1:  # Scan a series of attribute descriptions
            name, j = self._scan_name(j, declstartpos)
            if j < 0 or name is None:
                return j
            char = rawdata[j:j + 1]
            if char == r'':
                return -1
            if char == r'(':  # An enumerated type; look for ')'
                if r')' in rawdata[j:]:
                    j = rawdata.find(r')', j) + 1
                else:
                    return -1
                while rawdata[j:j + 1].isspace():
                    j += 1
                if not rawdata[j:]:  # End of buffer, incomplete
                    return -1
            else:
                name, j = self._scan_name(j, declstartpos)
            char = rawdata[j:j + 1]
            if not char or name is None:
                return -1
            if char in '\'"':
                _match = DECLSTRINGLIT_MATCH(rawdata, j)
                if _match:
                    j = _match.end()
                else:
                    return -1
                char = rawdata[j:j + 1]
                if not char:
                    return -1
            if char == r'#':
                if rawdata[j:] == r'#':  # End of buffer
                    return -1
                name, j = self._scan_name(j + 1, declstartpos)
                if j < 0 or name is None:
                    return j
                char = rawdata[j:j + 1]
                if not char:
                    return -1
            if char == r'>':
                return j + 1

    def _parse_doctype_notation(self, i: int, declstartpos: int) -> int:
        """Scan past <!NOTATION declarations."""
        name, j = self._scan_name(i, declstartpos)
        if j < 0 or name is None:
            return j
        rawdata: str = self.rawdata
        while 1:
            char = rawdata[j:j + 1]
            if not char:  # End of buffer; incomplete
                return -1
            if char == r'>':
                return j + 1
            if char in '\'"':
                _match = DECLSTRINGLIT_MATCH(rawdata, j)
                if not _match:
                    return -1
                j = _match.end()
            else:
                name, j = self._scan_name(j, declstartpos)
                if j < 0:
                    return j

    def _parse_doctype_entity(self, i: int, declstartpos: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912
        """Scan past <!ENTITY declarations."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 1] == r'%':
            j = i + 1
            while 1:
                char = rawdata[j:j + 1]
                if not char:
                    return -1
                if char.isspace():
                    j += 1
                else:
                    break
        else:
            j = i
        name, j = self._scan_name(j, declstartpos)
        if j < 0 or name is None:
            return j
        while 1:
            char = self.rawdata[j:j + 1]
            if not char:
                return -1
            if char in '\'"':
                _match = DECLSTRINGLIT_MATCH(rawdata, j)
                if _match:
                    j = _match.end()
                else:  # Incomplete
                    return -1
            elif char == r'>':
                return j + 1
            else:
                name, j = self._scan_name(j, declstartpos)
                if j < 0:
                    return j

    def _scan_name(self, i: int, declstartpos: int) -> tuple:
        """Scan a name token, the new position, and the token, or return -1 if the end of the buffer is reached."""
        rawdata: str = self.rawdata
        length: int = len(rawdata)
        if i == length:
            return (None, -1)
        _match = DECLNAME_MATCH(rawdata, i)
        if _match:
            _str = _match.group()
            name = _str.strip()
            if (i + len(_str)) == length:
                return (None, -1)  # End of buffer
            return (name.casefold(), _match.end())
        self.updatepos(declstartpos, i)
        self.error(fr'Expected name token at {rawdata[declstartpos:declstartpos + 20]}')
        return (None, -2)

    def unknown_decl(self, data: str) -> None:
        """Provide an overridable handler for unknown objects."""
        self.error(r'<![' + data + r']>')


class HTMLParser(ParserBase):  # pylint: disable=R0904
    """Find markup objects and call handler functions.

    Usage:
        p = HTMLParser()
        p.feed(data)
        # Perform some task
        p.close()
    """

    def __init__(self, *, convert_charrefs: bool = False) -> None:
        """Initialize and reset this instance; If convert_charrefs is True, all character references are automatically converted to the corresponding Unicode characters."""
        self.__starttag_text: str = r''
        self.cdata_elem: str = r''
        self.convert_charrefs: bool = convert_charrefs
        self.in_xml: bool = False
        self.interesting = INTERESTING_NORMAL
        self.lasttag: str = r'???'
        self.rawdata: str = r''
        super(HTMLParser, self).__init__()

    def error(self, message: str) -> None:
        """Raise error in parser."""
        raise Exception(message)

    def reset(self) -> None:
        """Reset this instance."""
        self.cdata_elem = r''
        self.interesting = INTERESTING_NORMAL
        self.lasttag = r'???'
        self.rawdata = r''
        ParserBase.reset(self)

    def feed(self, data: str) -> None:
        """Feed data to the parser."""
        self.rawdata = self.rawdata + data
        self.goahead(False)

    def close(self) -> None:
        """Handle any buffered data."""
        self.goahead(True)

    def get_starttag_text(self) -> str:
        """Return full source of start tag."""
        return self.__starttag_text

    def set_cdata_mode(self, elem: str) -> None:
        """Lowercase HTML element names."""
        self.cdata_elem = elem.casefold()
        self.interesting = rgxcompile(fr'</\s*{self.cdata_elem}\s*>', flags=IGNORECASE)

    def clear_cdata_mode(self) -> None:
        """Clear self.cdata_elem and self.interesting."""
        self.interesting = INTERESTING_NORMAL
        self.cdata_elem = r''

    def goahead(self, end: bool) -> None:  # noqa: C901,R701  # pylint: disable=R0912,R0915
        """Handle data as far as reasonable. May leave state and data to be processed by a subsequent call. If `end` is true, force handling all data as if followed by EOF marker."""
        rawdata: str = self.rawdata
        i: int = 0
        length: int = len(rawdata)
        while i < length:
            if self.convert_charrefs and not self.cdata_elem:
                j = rawdata.find(r'<', i)
                if j < 0:
                    amppos = rawdata.rfind(r'&', max(i, length - 34))
                    if amppos >= 0 and not WHITESPACE_IN_CHARREF.search(rawdata, amppos):
                        break  # Wait until all the text is received
                    j = length
            else:
                _match = self.interesting.search(rawdata, i)  # < or &
                if _match:
                    j = _match.start()
                elif self.cdata_elem:
                    break
                else:
                    j = length
            if i < j:
                if self.convert_charrefs and not self.cdata_elem:
                    self.handle_data(unescape(rawdata[i:j]))
                else:
                    self.handle_data(rawdata[i:j])
            i = self.updatepos(i, j)
            if i == length:
                break
            startswith = rawdata.startswith
            if startswith(r'<', i):
                if STARTTAGOPEN.match(rawdata, i):  # < + letter
                    k = self.parse_starttag(i)
                elif startswith(r'</', i):
                    k = self.parse_endtag(i)
                elif startswith(r'<!--', i):
                    k = self.parse_comment(i)
                elif startswith(r'<?', i):
                    k = self.parse_pi(i)
                elif startswith(r'<!', i):
                    k = self.parse_html_declaration(i)
                elif (i + 1) < length:
                    self.handle_data(r'<')
                    k = i + 1
                else:
                    break
                if k < 0:
                    if not end:
                        break
                    k = rawdata.find(r'>', i + 1)
                    if k < 0:
                        k = rawdata.find(r'<', i + 1)
                        if k < 0:
                            k = i + 1
                    else:
                        k += 1
                    if self.convert_charrefs and not self.cdata_elem:
                        self.handle_data(unescape(rawdata[i:k]))
                    else:
                        self.handle_data(rawdata[i:k])
                i = self.updatepos(i, k)
            elif startswith(r'&#', i):
                _match = CHARACTER_ENTITY.match(rawdata, i)
                if _match:
                    name = _match.group()[2:-1]
                    self.handle_charref(name)
                    k = _match.end()
                    if not startswith(r';', k - 1):
                        k -= 1
                    i = self.updatepos(i, k)
                    continue
                if r';' in rawdata[i:]:  # Bail by consuming &#
                    self.handle_data(rawdata[i:i + 2])
                    i = self.updatepos(i, i + 2)
                break
            elif startswith(r'&', i):
                _match = ENTITYREF.match(rawdata, i)
                if _match:
                    name = _match.group(1)
                    self.handle_entityref(name)
                    k = _match.end()
                    if not startswith(r';', k - 1):
                        k -= 1
                    i = self.updatepos(i, k)
                    continue
                _match = INCOMPLETE.match(rawdata, i)
                if _match:  # _match.group() will contain at least 2 chars
                    if end and _match.group() == rawdata[i:]:
                        k = _match.end()
                        if k <= i:
                            k = length
                        i = self.updatepos(i, i + 1)
                    break  # Incomplete
                if (i + 1) < length:  # Not the end of the buffer
                    self.handle_data(r'&')
                    i = self.updatepos(i, i + 1)
                else:
                    break
            else:
                raise Exception(r'There appears to be an issue with `interesting.search()`')
        if end and i < length and not self.cdata_elem:
            if self.convert_charrefs and not self.cdata_elem:
                self.handle_data(unescape(rawdata[i:length]))
            else:
                self.handle_data(rawdata[i:length])
            i = self.updatepos(i, length)
        self.rawdata = rawdata[i:]

    def parse_html_declaration(self, i: int) -> int:
        """Parse HTML declarations; return length or -1 (if not terminated)."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 2] != r'<!':
            raise Exception(r'Unexpected call to parse_html_declaration()')
        if rawdata[i:i + 4] == r'<!--':  # This case is handled in goahead()
            return self.parse_comment(i)
        if rawdata[i:i + 3] == r'<![':
            return self.parse_marked_section(i)
        if rawdata[i:i + 9].casefold() == r'<!doctype':  # Find the closing >
            gtpos = rawdata.find(r'>', i + 9)
            if gtpos == -1:
                return -1
            self.handle_decl(rawdata[i + 2:gtpos])
            return gtpos + 1
        return self.parse_bogus_comment(i)

    def parse_bogus_comment(self, i: int, report: int = 1) -> int:
        """Parse bogus comment; return length or -1 (if not terminated)."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 2] not in {r'<!', r'</'}:
            raise Exception(r'Unexpected call to parse_comment()')
        pos: int = rawdata.find(r'>', i + 2)
        if pos == -1:
            return -1
        if report:
            self.handle_comment(rawdata[i + 2:pos])
        return pos + 1

    def parse_pi(self, i: int) -> int:
        """Parse processing instruction; return end or -1 (if not terminated)."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 2] != r'<?':
            raise Exception(r'Unexpected call to parse_pi()')
        match = PICLOSE.search(rawdata, i + 2)
        if not match:
            return -1
        j: int = match.start()
        self.handle_pi(rawdata[i + 2: j])
        j = match.end()
        return j

    def parse_starttag(self, i: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912,R0915
        """Handle starttag; return end or -1 (if not terminated)."""
        self.__starttag_text = r''
        endpos = self.check_for_whole_start_tag(i)
        if endpos < 0:
            return endpos
        rawdata: str = self.rawdata
        self.__starttag_text = rawdata[i:endpos]
        # Parse the data between i+1 and j into a tag and attrs
        attrs: list = []
        _match = TAGFIND_TOLERANT.match(rawdata, i + 1)
        if not _match:
            raise Exception(r'Unexpected call to parse_starttag()')
        k = _match.end()
        tag = _match.group(1)
        if tag in XML_ROOT_TAGS:
            self.in_xml = True
        if self.in_xml:
            self.lasttag = tag
        else:
            self.lasttag = tag = tag.casefold()
        while k < endpos:  # Parse Attributes
            _match = ATTRFIND_TOLERANT.match(rawdata, k)
            if not _match:
                break
            attrname, rest, attrvalue = _match.group(1, 2, 3)
            if not rest:
                attrvalue = r''
            elif attrvalue[:1] == '\'' == attrvalue[-1:] or attrvalue[:1] == r'"' == attrvalue[-1:]:
                attrvalue = attrvalue[1:-1]
            if attrvalue:
                attrvalue = unescape(attrvalue)
            if self.in_xml:
                attrs.append((attrname, attrvalue))
            else:
                attrs.append((attrname.casefold(), attrvalue))
            attrs.sort(key=attr_sort)
            k = _match.end()
        end: str = rawdata[k:endpos].strip()
        if self.in_xml and tag in SVG_MAY_CLOSE_TAGS and end == r'/>':
            self.handle_startendtag(tag, attrs, 1)
        elif tag == r'dc:title' and end == r'/>':
            return endpos
        elif tag == r'style' and end == r'/>' and r'src' not in iter(attrs[0]):
            return endpos
        elif end not in {r'>', r'/>'}:
            lineno, offset = self.getpos()
            if '\n' in self.__starttag_text:
                lineno = lineno + self.__starttag_text.count('\n')
                offset = len(self.__starttag_text) - self.__starttag_text.rfind('\n')
            else:
                offset = offset + len(self.__starttag_text)
            self.handle_data(rawdata[i:endpos])
            return endpos
        elif end.endswith(r'/>'):  # XHTML-style empty tag: <span attr="value" />
            self.handle_startendtag(tag, attrs, 1)
        else:
            self.handle_starttag(tag, attrs)
            if tag in CDATA_CONTENT_ELEMENTS:
                self.set_cdata_mode(tag)
        return endpos

    def check_for_whole_start_tag(self, i: int) -> int:
        """Check to see if starttag is complete; return end or -1 (if incomplete)."""
        rawdata: str = self.rawdata
        _match = LOCATESTARTTAGEND_TOLERANT.match(rawdata, i)
        if _match:
            j = _match.end()
            _next = rawdata[j:j + 1]
            if _next == r'>':  # pylint: disable=R1705
                return j + 1
            elif _next == r'/':
                if rawdata.startswith(r'/>', j):  # pylint: disable=R1705
                    return j + 2
                elif rawdata.startswith(r'/', j):  # Buffer boundary
                    return -1
                elif j > i:
                    return j
                return i + 1
            elif _next == r'':  # End of input
                return -1
            elif _next in _ALPHASET:  # End of input in or before attribute value or the '/' from a '/>' ending
                return -1
            elif j > i:
                return j
            return i + 1
        raise AssertionError(r'Fell through if constructs in check_for_whole_start_tag()')

    def parse_endtag(self, i: int) -> int:  # noqa: C901,R701  # pylint: disable=R0912
        """Parse endtag; return end or -1 (if incomplete)."""
        rawdata: str = self.rawdata
        if rawdata[i:i + 2] != r'</':
            raise Exception(r'Unexpected call to parse_endtag')
        match = ENDENDTAG.search(rawdata, i + 1)  # >
        if not match:
            return -1
        gtpos = match.end()
        match = ENDTAGFIND.match(rawdata, i)  # </ + tag + >
        if not match:
            if self.cdata_elem:
                self.handle_data(rawdata[i:gtpos])
                return gtpos
            namematch = TAGFIND_TOLERANT.match(rawdata, i + 2)
            if not namematch:
                if rawdata[i:i + 3] == r'</>':
                    return i + 3
                return self.parse_bogus_comment(i)
            tagname = namematch.group(1)
            if not self.in_xml:
                tagname = tagname.casefold()
            elif self.in_xml and tagname in XML_ROOT_TAGS:
                self.in_xml = False
            # Consume and ignore other stuff between the name and the >
            gtpos = rawdata.find(r'>', namematch.end())
            self.handle_endtag(tagname)
            return gtpos + 1
        # script or style
        elem = match.group(1)
        if not self.in_xml:
            elem = elem.casefold()
        elif self.in_xml and elem in XML_ROOT_TAGS:
            self.in_xml = False
        if self.cdata_elem:
            if elem != self.cdata_elem:
                self.handle_data(rawdata[i:gtpos])
                return gtpos
        self.handle_endtag(elem)
        self.clear_cdata_mode()
        return gtpos

    def handle_startendtag(self, tag: str, attrs: list, closing_type: int = -1) -> None:
        """Finish processing of start+end tag - <tag.../> (Overridable)."""
        if closing_type == 1:
            self.handle_starttag(tag, attrs)
            self.handle_endtag(tag)
        else:
            self.handle_starttag(tag, attrs)
            self.handle_endtag(tag)

    def handle_starttag(self, tag: str, attrs: list) -> None:  # pylint: disable=R0201,W0613
        """Handle start tag (Overridable)."""
        return

    def handle_endtag(self, tag: str) -> None:  # pylint: disable=R0201,W0613
        """Handle end tag (Overridable)."""
        return

    def handle_charref(self, name: str) -> None:  # pylint: disable=R0201,W0613
        """Handle character reference (Overridable)."""
        return

    def handle_entityref(self, name: str) -> None:  # pylint: disable=R0201,W0613
        """Handle entity reference (Overridable)."""
        return

    def handle_data(self, data: str) -> None:  # pylint: disable=R0201,W0613
        """Handle data (Overridable)."""
        return

    def handle_decl(self, decl: str) -> None:  # pylint: disable=R0201,W0613
        """Handle declaration (Overridable)."""
        return

    def handle_pi(self, data: str) -> None:  # pylint: disable=R0201,W0613
        """Handle processing instruction (Overridable)."""
        return

    def unknown_decl(self, data: str) -> None:
        """Handle unknown declarations (Overridable)."""
        self.error(r'Unknown declaration: <![' + data + r']>')


class Minifier():
    """An object that supports XML/HTML Minification; Options are passed into this class at initialization time and are persisted across each use of the instance."""

    def __init__(  # pylint: disable=R0913
            self,
            remove_metadata: int = 0,
            remove_comments: bool = True,
            remove_empty_space: bool = True,
            remove_all_empty_space: bool = True,
            reduce_empty_attributes: bool = False,
            reduce_bool_attrs: bool = False,
            remove_opt_attr_quotes: bool = False,
            keep_pre: bool = False,
            pre_tags: tuple = PRE_TAGS,
            pre_attr: str = r'pre',
            convrefs: bool = False,
            doc_type: int = FILETYPE_XML
    ) -> None:
        """Initialize the needed minifier."""
        if doc_type is FILETYPE_HTML:  # HTML
            self._parser = XMLMinParser(
                remove_metadata=remove_metadata,
                remove_comments=remove_comments,
                remove_empty_space=remove_empty_space,
                remove_all_empty_space=remove_all_empty_space,
                reduce_empty_attributes=reduce_empty_attributes,
                reduce_bool_attrs=reduce_bool_attrs,
                remove_opt_attr_quotes=remove_opt_attr_quotes,
                keep_pre=keep_pre,
                pre_tags=pre_tags,
                pre_attr=pre_attr,
                convrefs=convrefs,
                doc_type=FILETYPE_HTML
            )
        elif doc_type is FILETYPE_MATHML:  # MathML
            self._parser = XMLMinParser(
                remove_metadata=remove_metadata,
                remove_comments=remove_comments,
                remove_empty_space=remove_empty_space,
                remove_all_empty_space=remove_all_empty_space,
                reduce_empty_attributes=reduce_empty_attributes,
                reduce_bool_attrs=reduce_bool_attrs,
                remove_opt_attr_quotes=remove_opt_attr_quotes,
                keep_pre=keep_pre,
                pre_tags=pre_tags,
                pre_attr=pre_attr,
                convrefs=convrefs,
                doc_type=FILETYPE_MATHML
            )
        elif doc_type is FILETYPE_SVG:  # SVG
            self._parser = XMLMinParser(
                remove_metadata=remove_metadata,
                remove_comments=remove_comments,
                remove_empty_space=remove_empty_space,
                remove_all_empty_space=remove_all_empty_space,
                reduce_empty_attributes=False,
                reduce_bool_attrs=reduce_bool_attrs,
                remove_opt_attr_quotes=remove_opt_attr_quotes,
                keep_pre=keep_pre,
                pre_tags=pre_tags,
                pre_attr=pre_attr,
                convrefs=convrefs,
                doc_type=FILETYPE_SVG
            )
        else:  # XML
            self._parser = XMLMinParser(
                remove_metadata=remove_metadata,
                remove_comments=remove_comments,
                remove_empty_space=remove_empty_space,
                remove_all_empty_space=remove_all_empty_space,
                reduce_empty_attributes=reduce_empty_attributes,
                reduce_bool_attrs=reduce_bool_attrs,
                remove_opt_attr_quotes=remove_opt_attr_quotes,
                keep_pre=keep_pre,
                pre_tags=pre_tags,
                pre_attr=pre_attr,
                convrefs=convrefs,
                doc_type=FILETYPE_XML
            )

    def minify(self, *_input: str) -> str:
        """Run XML/HTML code through the minifier in one pass."""
        self._parser.reset()
        self.input(*_input)
        return self.finalize()

    def finalize(self) -> str:
        """Flushes any remaining XML/HTML, returns the minified result, and resets the process's internal parser so that new code can be minified."""
        self._parser.close()
        result = self._parser.result
        self._parser.reset()
        return result

    def input(self, *_input: str) -> None:  # noqa: A003
        """Feed more XML/HTML into the input stream."""
        for i in _input:
            self._parser.feed(i)

    @property
    def output(self) -> str:
        """Retrieve the minified output generated thus far."""
        return self._parser.result


class XMLMinParser(HTMLParser):  # pylint: disable=R0902
    """XML/HTML Parser."""

    def __init__(  # pylint: disable=R0913
            self,
            remove_metadata: int = 0,
            remove_comments: bool = True,
            remove_empty_space: bool = True,
            remove_all_empty_space: bool = True,
            reduce_empty_attributes: bool = False,
            reduce_bool_attrs: bool = False,
            remove_opt_attr_quotes: bool = False,
            keep_pre: bool = False,
            pre_tags: tuple = PRE_TAGS,
            pre_attr: str = r'pre',
            convrefs: bool = False,
            doc_type: int = FILETYPE_XML
    ) -> None:
        """Initialize XML/HTML parser."""
        HTMLParser.__init__(self, convert_charrefs=convrefs)
        self.remove_metadata = remove_metadata
        self.remove_comments = remove_comments
        self.remove_empty_space = remove_empty_space
        self.remove_all_empty_space = remove_all_empty_space
        self.reduce_empty_attributes = reduce_empty_attributes
        self.reduce_bool_attrs = reduce_bool_attrs
        self.remove_opt_attr_quotes = remove_opt_attr_quotes
        self.keep_pre = keep_pre
        self.pre_tags = pre_tags
        self.pre_attr = pre_attr
        self.doc_type = doc_type
        self._data_buffer: list = []
        self._in_pre_tag = 0
        self._in_head = False
        self._in_metadata = False
        self._in_title = False
        self._after_doctype = False
        self._tag_stack: list = []
        self._title_newly_opened = False
        self.__title_trailing_whitespace = False
        self._doctype_inserted = False
        self._upgrade_svg10 = False

    def reset(self) -> None:
        """Flushes any remaining XML/HTML and resets the process's internal parser so that new XML/HTML can be processed."""
        self._data_buffer = []
        HTMLParser.reset(self)

    @property
    def result(self) -> str:
        """Retrieve the processed output generated thus far."""
        return r''.join(self._data_buffer)

    def insert_doctype_tag(self, decl: str = r'') -> None:
        """Insert the DOCTYPE tag."""
        if self._after_doctype:  # pylint: disable=R1705
            return
        elif self.doc_type == FILETYPE_HTML:
            self._data_buffer.append(XML_DOCTYPES.get(r'HTML5'))
        elif self.doc_type == FILETYPE_MATHML:
            self._data_buffer.append(XML_DOCTYPES.get(r'MATHML_2'))
        elif self.doc_type == FILETYPE_SVG and self.remove_metadata > 1:
            self._data_buffer.append(XML_DOCTYPES.get(r'SVG_FULL'))
            self._upgrade_svg10 = True
        elif decl:
            self._data_buffer.append(r'<!' + decl + r'>')
        self._doctype_inserted = True
        self._after_doctype = True

    def _has_pre(self, attrs: list) -> bool:
        """Test if the tag uses the `pre` attribute."""
        return any((k[0] == self.pre_attr for k in attrs))

    def in_tag(self, *tags: str) -> str:
        """Test if the given tags are within the tag stack."""
        for tag in self._tag_stack:
            if tag[0] in tags:
                return tag
        return r''

    def should_preserve_ws(self, tag: str, attrs: list) -> bool:  # noqa: R701
        """Test if whitespace should be preserved in the tag."""
        if tag in self.pre_tags or self._has_pre(attrs) or self._in_pre_tag > 0:  # Pre
            return True
        if tag in CDATA_CONTENT_ELEMENTS:  # Cdata
            return True
        if self.doc_type == FILETYPE_MATHML and tag == r'annotation':  # MathML <annotation>
            return True
        if self.doc_type == FILETYPE_XML:
            if self.in_tag(r'mime-info') and tag in {r'acronym', r'comment', r'expanded-acronym'}:  # XDG Mime
                return True
            if self.in_tag(r'interface', r'object') and tag == r'property':  # Glade XML
                return True
        return False

    def build_tag(self, tag: str, attrs: list, close_tag: bool) -> str:  # noqa: C901,R701  # pylint: disable=R0912,R0915
        """Create an XML/HTML tag."""
        if is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):  # pylint: disable=R1705
            return r''
        if self.doc_type == FILETYPE_SVG and close_tag and tag in {r'comment', r'defs', r'g'}:
            return r''
        if not self._doctype_inserted and self.doc_type == FILETYPE_SVG and tag == r'svg':
            self.insert_doctype_tag()
        elif self.doc_type == FILETYPE_SVG and tag == r'stop' and not any((_test[0] == r'offset' for _test in attrs)):
            attrs.append((r'offset', r'0'))
        elif self.doc_type == FILETYPE_SVG:
            tag = repair_svg_tag(tag)
        result = StringIO(initial_value=r'', newline=None)
        result_write = result.write
        result_write(r'<')
        result_write(escape(tag))
        needs_closing_space = False
        # Attributes
        attrs.sort(key=attr_sort)
        for k, v in attrs:
            if is_removable_metadata_attr(self.remove_metadata, k):
                continue
            k, v = attribute_cleaner(tag, k, v, self.doc_type)
            if self.doc_type == FILETYPE_SVG:
                k = repair_svg_attr(tag, k)
                if self._upgrade_svg10 and tag == r'svg' and k == r'version':
                    v = r'1.1'
            if not k:
                continue
            result_write(r' ' + escape(k))
            if v:  # Attribute value
                if self.doc_type == FILETYPE_HTML and self.reduce_bool_attrs and (k in BOOLEAN_ATTRIBUTES.get(tag, []) or k in BOOLEAN_ATTRIBUTES[r'*']):  # type: ignore
                    pass
                else:
                    result_write(r'=')
                    (v, quote_type) = escape_attr_value(v, double_quote=not self.remove_opt_attr_quotes)
                    if quote_type == NO_QUOTES:
                        result_write(v)
                    elif quote_type == DOUBLE_QUOTE:
                        result_write(r'"')
                        result_write(v)
                        result_write(r'"')
                    else:  # SINGLE_QUOTE
                        result_write('\'')
                        result_write(v)
                        result_write('\'')
                    needs_closing_space = quote_type == NO_QUOTES and v.endswith(r'/')
            elif not self.reduce_empty_attributes or self.doc_type == FILETYPE_SVG:
                result_write(r'=""')
        # End tag
        if needs_closing_space:  # End tag space
            result_write(r' ')
        if close_tag and tag == r'svg':
            result_write(r'></svg>')
        elif close_tag:
            result_write(r'/>')
        else:
            result_write(r'>')
        return result.getvalue()

    def _close_tags_up_to(self, tag: str) -> int:
        """Close previously opened tags up to the specified tag."""
        num_pres: int = 0
        i: int = 0
        for i, _tag in enumerate(self._tag_stack):
            if _tag[1]:
                num_pres += 1
            if _tag[0] == tag:
                break
            # Raise exception if an unknown tag is found
            if _tag[0] in {r'body', r'head'}:
                raise Exception(r'Unknown tag found!')
        self._tag_stack = self._tag_stack[i + 1:]
        return num_pres

    def handle_charref(self, name: str) -> None:
        """Process decimal and hexadecimal numeric character references of the form `&#NNN;` and `&#xNNN;`."""
        if self._in_title:
            if not self._title_newly_opened and self.__title_trailing_whitespace:
                self._data_buffer.append(r' ')
                self.__title_trailing_whitespace = False
            self._title_newly_opened = False
        self._data_buffer.append(fr'&#{name};')

    def handle_data(self, data: str) -> None:  # noqa: C901,R701  # pylint: disable=R0912
        """Process arbitrary data (such as <script> and <style>)."""
        if self._in_metadata and self.remove_metadata > 0:
            return
        if self._in_pre_tag > 0:
            self._data_buffer.append(data)
            return
        if not data.strip():
            return
        if self.remove_empty_space or self.remove_all_empty_space or self._in_head or self._after_doctype:
            match = WHITESPACE.match(data)
            if match and match.end(0) == len(data):
                return
        # Remove leading and trailing whitespace in the title block
        if self._in_title:
            if self.__title_trailing_whitespace:
                self._data_buffer.append(r' ')
            self.__title_trailing_whitespace = data[-1].isspace()
            if self._title_newly_opened:
                self._title_newly_opened = False
                data = LEADING_TRAILING_WHITESPACE.sub(r'', data)
            else:
                data = TRAILING_WHITESPACE.sub(r'', LEADING_WHITESPACE.sub(r' ', data))
        data = WHITESPACE.sub(r' ', data)
        if not data:
            return
        if self._in_pre_tag == 0 and self._data_buffer:
            # It is possible that two spaces can get appended when a comment is removed from between two blocks (this code avoids this)
            if data[0] == r' ' and self._data_buffer[-1][-1] == r' ':
                data = data[1:]
                if not data:
                    return
        self._data_buffer.append(data)

    def handle_decl(self, decl: str) -> None:
        """Process the XML/HTML doctype declaration."""
        if len(self._data_buffer) == 1 and WHITESPACE.match(self._data_buffer[0]):
            self._data_buffer = []
        if not self._doctype_inserted and decl.strip().startswith(r'DOCTYPE'):
            self.insert_doctype_tag(decl)
        else:
            self._data_buffer.append(r'<!' + decl + r'>')
        self._after_doctype = True

    def handle_endtag(self, tag: str) -> None:  # noqa: C901,R701  # pylint: disable=R0912
        """Process end tags."""
        if tag == r'a':  # </a> and <p>
            contains_p: bool = False
            i: int = 0
            for i, _tag in enumerate(self._tag_stack):
                if _tag[0] == r'p':
                    contains_p = True
                elif _tag[0] == r'a':
                    break
            if contains_p:  # `<p>` and all its children should be left open
                a_tag = self._tag_stack.pop(i)
                if a_tag[1]:
                    self._in_pre_tag -= 1
        elif self._in_metadata and self.remove_metadata > 0 and tag == r'metadata':
            self._in_metadata = False
            return
        elif self.doc_type == FILETYPE_SVG and self.remove_metadata > 0 and tag in USELESS_SVG_TAGS:
            self._in_metadata = False
            return
        elif is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return
        else:
            if self.doc_type == FILETYPE_HTML:
                if tag == r'head':
                    self._in_head = False
                elif tag == r'title':
                    self._in_title = False
                    self._title_newly_opened = False
            elif self.doc_type == FILETYPE_SVG:
                tag = repair_svg_tag(tag)
            try:
                self._in_pre_tag -= self._close_tags_up_to(tag)
            except BaseException:  # Leave closing tags alone since they affect output
                # Some tags do not require a start tag; For instance, in Chrome, `</p>` results in `<p></p>`
                pass
        self._data_buffer.extend([r'</', escape(tag), r'>'])

    def handle_entityref(self, name: str) -> None:
        """Process a named character reference of the form `&name;`."""
        if self._in_title:
            if not self._title_newly_opened and self.__title_trailing_whitespace:
                self._data_buffer.append(r' ')
                self.__title_trailing_whitespace = False
            self._title_newly_opened = False
        self._data_buffer.append(fr'&{name};')

    def handle_pi(self, data: str) -> None:
        """Process the processing instruction tag."""
        if data.strip().startswith(r'xml'):
            if r'standalone="yes"' in data.casefold() or 'standalone=\'yes\'' in data.casefold():
                self._data_buffer.append(r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>')
            else:
                self._data_buffer.append(r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>')
        else:
            self._data_buffer.append(r'<?' + data + r'>')

    def handle_startendtag(self, tag: str, attrs: list, closing_type: int = -1) -> None:
        """Process XHTML-style empty tags (such as `<br/>`)."""
        self._after_doctype = False
        if is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return
        if not self.keep_pre:
            attrs = [(k, v) for k, v in attrs if k != r'pre']
        if closing_type == 1:  # Self-closing tag
            self._data_buffer.append(self.build_tag(tag, attrs, True))
        else:  # Miscellaneous XML self-closing tag
            self._data_buffer.append(self.build_tag(tag, attrs, is_self_closing_tag(tag, self.doc_type, self._tag_stack)))

    def handle_starttag(self, tag: str, attrs: list) -> None:  # noqa: C901,R701
        """Process start tags."""
        self._after_doctype = False
        if not self._doctype_inserted:
            self.insert_doctype_tag()  # Insert DOCTYPE tag if it is missing
        if self.remove_metadata > 0 and tag == r'metadata':
            self._in_metadata = True
            return
        if self.doc_type == FILETYPE_SVG and self.remove_metadata > 0 and tag in USELESS_SVG_TAGS:
            self._in_metadata = True
            return
        if is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return
        if self.doc_type == FILETYPE_HTML:  # HTML <head> and <title>
            if tag == r'head':
                self._in_head = True
            elif self._in_head and tag == r'title':
                self._in_title = True
                self._title_newly_opened = True
        for open_tags, closed_by_tags in TAG_SETS:
            in_tag: str = self.in_tag(*open_tags)  # type: ignore
            if in_tag and (tag in closed_by_tags or r'*' in closed_by_tags):  # type: ignore
                self._in_pre_tag -= self._close_tags_up_to(in_tag[0])
        start_pre: bool = False
        if self.should_preserve_ws(tag, attrs):
            self._in_pre_tag += 1
            start_pre = True
        self._tag_stack.insert(0, (tag, start_pre))
        if not self.keep_pre:
            attrs = [(k, v) for k, v in attrs if k != self.pre_attr]
        self._data_buffer.append(self.build_tag(tag, attrs, False))

    def unknown_decl(self, data: str) -> None:
        """Process the unrecognized declaration tag."""
        self._data_buffer.append(r'<![' + data + r']>')
