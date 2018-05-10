#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions and data for manipulating and processing markup languages

@file markup.py
@package pybooster.markup
@version 2018.04.27
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This library contains
 - Data tables of tags and attributes
 - Functions for manipulationing and processing markup data
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from io import StringIO
from sys import stderr
import xml.etree.ElementTree as ET

from pybooster.basic import isintuplelist
from pybooster.libchar import ALPHASET, INVALID_CHARREFS, INVALID_CODEPOINTS, HTML5

try:  # Regular Expression module
    import regex as re  # noqa: E402  # pylint: disable=C0411
except ImportError:
    import re  # noqa: E402  # pylint: disable=C0411


__all__ = [
    # CONSTANTS #
    r'INKSCAPE_NAMESPACES',
    r'SVG_SIZE',
    r'SVG_VIEWBOX_SEP',
    r'INCOMPLETE_REF',
    r'ENTITY_REF',
    r'CHAR_REF',
    r'CHAR_REF2',
    r'LEADING_SURROGATE',
    r'TRAILING_SURROGATE',
    r'LOCATESTARTTAGEND_TOLERANT',
    r'ATTRFIND_TOLERANT',
    r'CC_NS',
    r'CHARREF',
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
    r'LEADING_TRAILING_WHITESPACE',
    r'LEADING_WHITESPACE',
    r'MARKEDSECTIONCLOSE',
    r'MSMARKEDSECTIONCLOSE',
    r'NUMBER',
    r'PICLOSE',
    r'RDF_NS',
    r'SELF_CLOSING_TAG',
    r'SODIPODI_NS',
    r'STARTTAGOPEN',
    r'TAGFIND_TOLERANT',
    r'TRAILING_WHITESPACE',
    r'WHITESPACE',
    r'WHITESPACE_NEWLINE',
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
    r'unescape',
    r'htmlunescape',
    r'int2refnum',
    # SVG FUNCTIONS #
    r'parse_svg_size',
    r'svgviewbox2pixels',
    r'resize_svg',
    r'remove_duplicated_svg_ns',
    r'repair_svg_tag',
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


INKSCAPE_NAMESPACES = {r'inkscape': r'http://www.inkscape.org/namespaces/inkscape', r'sodipodi': r'http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd'}
SVG_SIZE = re.compile(r'^\s*(-?\d+(?:\.\d+)?)\s*(px|in|cm|mm|pt|pc|%)?')
SVG_VIEWBOX_SEP = re.compile(r'[ ,\t]+')
NO_QUOTES = 0
SINGLE_QUOTE = 1
DOUBLE_QUOTE = 2
FILETYPE_HTML = 0
FILETYPE_XML = 1
FILETYPE_MATHML = 2
FILETYPE_SVG = 3
FILETYPE_DTD = 4
FILETYPE_XSD = 5
INCOMPLETE_REF = re.compile('&[#]?[0-9A-Za-z]+')
ENTITY_REF = re.compile('&[0-9A-Za-z]+;')
CHAR_REF = re.compile('&#(?:[0-9]+|[Xx][0-9A-Fa-f]+);')
CHAR_REF2 = re.compile(
    r'&(#[0-9]+;?'
    r'|#[xX][0-9a-fA-F]+;?'
    r'|[^\t\n\f <&#;]{1,32};?)'
)
LEADING_SURROGATE = re.compile(r'[\ud800-\udbff]')
TRAILING_SURROGATE = re.compile(r'[\udc00-\udfff]')
LOCATESTARTTAGEND_TOLERANT = re.compile(r'<[A-Za-z\-][^\s/>\x00]*(?:[\s/]*(?:(?<=[\'\"\s/])[^\s/>][^\s/=>]*(?:\s*=+\s*(?:\'[^\']*\'|\"[^\"]*\"|(?![\'\"])[^>\s]*)(?:\s*,)*)?(?:\s|/(?!>))*)*)?\s*', re.VERBOSE)
ATTR_TOLERANT = r'((?<=[\'"\s/])[^\s/>][^\s/=>]*)(\s*=+\s*(\'[^\']*\'|"[^"]*"|(?![\'"])[^>\s]*))?(?:\s|/(?!>))*'
ATTRFIND_TOLERANT = re.compile(ATTR_TOLERANT)
CC_NS = re.compile(r'\s*xmlns:cc\s*=\s*(\'|")(http://creativecommons.org/ns#|http://web.resource.org/cc/)(\'|")\s*')
CHARREF = re.compile(r'&(#[0-9]+;|#[xX]+[0-9A-Fa-f]+;|[A-Za-z0-9]+;)')
COMMENTCLOSE = re.compile(r'--\s*>')
DECLNAME_MATCH = re.compile(r'[A-Za-z][-.\w]*\s*').match
DECLSTRINGLIT_MATCH = re.compile(r'(\'[^\']*\'|"[^"]*")\s*').match
DC_NS = re.compile(r'\s*xmlns:dc\s*=\s*(\'|")http://purl.org/dc/elements/1.1/(\'|")\s*')
ENDENDTAG = re.compile(r'>')
ENDTAGFIND = re.compile(r'</\s*([A-Za-z][-.:\w]*)\s*>')
ENTITYREF = re.compile(r'&([A-Za-z][-.0-9A-Za-z]*)[^0-9A-Za-z]')
HEX_COLOR = re.compile(r'(\s*)#([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])([0-9A-Fa-f])', re.S)
INCOMPLETE = re.compile(r'&[A-Za-z#]')
INKSCAPE_NS = re.compile(r'\s*xmlns:inkscape\s*=\s*(\'|")http://www.inkscape.org/namespaces/inkscape(\'|")\s*')
INTERESTING_NORMAL = re.compile(r'[&<]')
LEADING_TRAILING_WHITESPACE = re.compile(r'(^\s+)|(\s+$)')
LEADING_WHITESPACE = re.compile(r'^\s+')
MARKEDSECTIONCLOSE = re.compile(r']\s*]\s*>')
MSMARKEDSECTIONCLOSE = re.compile(r']\s*>')
NUMBER = re.compile(r'^[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?$')
PICLOSE = ENDENDTAG
RDF_NS = re.compile(r'\s*xmlns:rdf\s*=\s*(\'|")http://www.w3.org/1999/02/22-rdf-syntax-ns#(\'|")\s*')
SELF_CLOSING_TAG = re.compile(r'<([A-Za-z\-:][\s/]*)(' + ATTR_TOLERANT + r')([\s/]*)/>')
SODIPODI_NS = re.compile(r'\s*xmlns:sodipodi\s*=\s*(\'|")(http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd|http://inkscape.sourceforge.net/DTD/sodipodi-0.dtd)(\'|")\s*')
STARTTAGOPEN = re.compile(r'<[A-Za-z]')
TAGFIND_TOLERANT = re.compile(r'([A-Za-z][^\t\n\r\f />\x00]*)(?:\s|/(?!>))*')
TAGS_WITH_MIMETYPES = (r'embed', r'object', r'script', r'source', r'style')
TRAILING_ZEROS = re.compile(r'\d*\.(\d*?)(0+)$')
TRAILING_WHITESPACE = re.compile(r'\s+$')
WHITESPACE = re.compile(r'\s+')
WHITESPACE_NEWLINE = re.compile(r'\s*(\f|\r|\n)+\s*')
WHITESPACE_IN_CHARREF = re.compile(r'[\s;]')
XML_DECLARATION = re.compile(r'<\?xml\s*[\w"\'=\-\. \t]*\s*\?>')
CDATA_CONTENT_ELEMENTS = {r'script', r'style'}
PRE_TAGS = (r'pre', r'textarea')
ROOT_TAGS = {r'html', r'math', r'svg', r'x3d'}
XML_ROOT_TAGS = {r'interface', r'math', r'mime-info', r'svg', r'x3d'}
JUNK_ATTR = {r'xmlns:a', r'xmlns:cc', r'xmlns:cib', r'xmlns:dc', r'xmlns:inkscape', r'xmlns:osb' r'xmlns:ns1', r'xmlns:rdf', r'xmlns:sodipodi'}
JUNK_NS = {r'cc:', r'cib:', r'dc:', r'inkscape:', r'osb:', r'rdf:', r'sodipodi:'}
CC_NO_CLOSE_TAGS = {r'cc:license', r'cc:permits', r'cc:requires'}
DC_NO_CLOSE_TAGS = {r'dc:type'}
HTML_NO_CLOSE_TAGS = {r'area', r'base', r'br', r'col', r'command', r'embed', r'hr', r'img', r'input', r'keygen', r'link', r'meta', r'param', r'source', r'track', r'wbr'}  # Tags that self-opening/closing
MIMETYPE_NO_CLOSE_TAGS = {r'alias', r'generic-icon', r'glob', r'match', r'sub-class-of'}  # Tags that self-opening/closing
SVG_NO_CLOSE_TAGS = {r'animate', r'audio', r'animateColor', r'animateMotion', r'animateTransform', r'br', r'circle', r'ellipse', r'embed', r'feBlend', r'feColorMatrix', r'feComposite', r'feDistantLight', r'feFuncA', r'feFuncB', r'feFuncG', r'feFuncR', r'feGaussianBlur', r'feImage', r'feMergeNode', r'feMorphology', r'feOffset', r'fePointLight', r'flowPara', r'image', r'line', r'meta', r'path', r'polygon', r'polyline', r'rect', r'set', r'stop', r'use', r'video'}  # Tags that self-opening/closing
SVG_MAY_CLOSE_TAGS = {r'g', r'linearGradient', r'radialGradient'}  # Tags that are sometimes self-opening/closing
USELESS_SVG_TAGS = {r'desc', r'flowRoot', r'title'}


BOOLEAN_ATTRIBUTES = {
    r'audio': (r'autoplay', r'controls', r'loop', r'muted'),
    r'button': (r'autofocus', r'disabled', r'formnovalidate'),
    r'command': (r'checked', r'disabled'),
    r'dialog': (r'open'),
    r'fieldset': (r'disabled'),
    r'form': (r'novalidate'),
    r'iframe': (r'seamless'),
    r'img': (r'ismap'),
    r'input': (r'autofocus', r'checked', r'disabled', r'formnovalidate', r'multiple', r'readonly', r'required'),
    r'keygen': (r'autofocus', r'disabled'),
    r'object': (r'typesmustmatch'),
    r'ol': (r'reversed'),
    r'optgroup': (r'disabled'),
    r'option': (r'disabled', r'selected'),
    r'script': (r'async', r'defer'),
    r'select': (r'autofocus', r'disabled', r'multiple', r'required'),
    r'style': (r'scoped'),
    r'textarea': (r'autofocus', r'disabled', r'readonly', r'required'),
    r'track': (r'default'),
    r'video': (r'autoplay', r'controls', r'loop', r'muted'),
    r'*': (r'hidden')
}


TAG_SETS = (  # Tuple of tags and their respective closing tags
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


XML_DOCTYPES = {
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


XML_NAMESPACES = {
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
    r'CC': r'http://creativecommons.org/ns#',
    r'DC': r'http://purl.org/dc/elements/1.1/',
    r'INKSCAPE': r'http://www.inkscape.org/namespaces/inkscape',
    r'OSB': r'http://www.openswatchbook.org/uri/2009/osb',
    r'RDF': r'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
    r'RDFS': r'http://www.w3.org/2000/01/rdf-schema#',
    r'SKETCH': r'http://www.bohemiancoding.com/sketch/ns',
    r'SODIPODI': r'http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd',
    r'SVG': r'http://www.w3.org/2000/svg',
    r'X3D': r'http://www.web3d.org/specifications/x3d-3.2.xsd',
    r'XHTML': r'http://www.w3.org/1999/xhtml',
    r'XSI': r'http://www.w3.org/2001/XMLSchema-instance',
    r'XLINK': r'http://www.w3.org/1999/xlink',
    r'XPATH': r'http://ns.adobe.com/XPath/1.0/',
    r'XSD': r'http://www.w3.org/2001/XMLSchema-instance'
}


SVG_COLORS = {
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


SVG_UNIT = (r'em', r'ex', r'px', r'in', r'cm', r'mm', r'pt', r'pc', r'%')


SVG_UNIT_CONVERSIONS = {
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


SVG_STYLES = (
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
)


SVG_TINY_STYLES = (
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
)


SVG_POSITION_ATTR = {
    r'circle': (r'cx', r'cy'),
    r'ellipse': (r'cx', r'cy'),
    r'line': (r'x1', r'y1', r'x2', r'y2'),
    r'rect': (r'x', r'y'),
    r'tspan': (r'x', r'y')
}


SVG_SCALING_ATTR = {r'rect': (r'x', r'y', r'width', r'height')}


MIMETYPE_CORRECTIONS = (
    # (Incorrect, Correct)
    (r'application/xml+xhtml', r'application/xhtml+xml'),
    (r'image/svg-xml', r'image/svg+xml'),
    (r'text/xml', r'application/xml'),
    (r'text/xml+html', r'application/xhtml+xml')
)


# ASSERTION FUNCTIONS #


def assert_is_xml(_doc_type: int, data: str, _filename: str) -> None:
    """Ensure input data is valid XML data; otherwise, raise an exception"""
    if r'<' not in data or r'>' not in data:
        stderr.write(r'Unsupported filetype (' + _filename + ')!\n')
        raise SystemExit(1)
    elif _doc_type == FILETYPE_DTD and r'<!ELEMENT ' not in data and r'<!ATTLIST ' not in data:
        stderr.write(r'Invalid DTD file (' + _filename + ')!\n')
        raise SystemExit(1)
    elif _doc_type == FILETYPE_XSD and r'</xs:schema>' not in data and r'<xs:element ' not in data:
        stderr.write(r'Invalid XSD file (' + _filename + ')!\n')
        raise SystemExit(1)


# BOOLEAN TESTS #


def is_in_tagstack(tag: str, _tag_stack: list) -> bool:
    """Test if the given tag is in the tag-stack"""
    for _tag in _tag_stack:
        if _tag[0] == tag:
            return True
    return False


def is_removable_metadata_attr(remove_metadata: bool, attr: str) -> bool:
    """Determine if the given data is a removable metadata attribute"""
    if remove_metadata < 2:
        return False
    elif r'xmlns:' in attr:  # XMLNS attribute
        if attr in JUNK_ATTR:
            return True
    elif r':' in attr:  # Namespace attribute
        if attr.split(r':')[0] + r':' in JUNK_NS:
            return True
    return False


def is_removable_metadata_tag(doc_type: int, tag: str, _in_metadata: bool = False, remove_metadata: int = 2) -> bool:
    """Determine if the given data is a removable metadata tag"""
    if remove_metadata < 1:
        return False
    elif _in_metadata:
        return True
    elif remove_metadata > 0 and doc_type == FILETYPE_SVG and tag in {r'desc', r'title'}:
        return True
    elif remove_metadata == 2 and r':' in tag:  # Namespace tags
        if tag.split(r':')[0] + r':' in JUNK_NS:
            return True
    return False


def is_self_closing_tag(_tag: str, _doc_type: int, _tag_stack: list) -> bool:
    """Test if the given tag is a self-closing tag for the given XML document type"""
    if _tag in CC_NO_CLOSE_TAGS or _tag in DC_NO_CLOSE_TAGS:
        return True
    elif _doc_type == FILETYPE_SVG or is_in_tagstack(r'svg', _tag_stack):  # SVG
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
    """Return true if the given data is DTD"""
    return True if r'<!ELEMENT ' in xmldata and r'<!ATTLIST ' in xmldata else False


def is_xml_xsd(xmldata: str) -> bool:
    """Return true if the given data is XSD"""
    return True if r'</xs:schema>' in xmldata and r'<xs:element ' in xmldata else False


# ESCAPE MANIPULATIONS #


def escape(_str: str, quote: bool = True) -> str:
    """Replace special characters '&', '<', and '>' to HTML-safe sequences

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


def escape_ambiguous_ampersand(val: str) -> str:  # noqa: C901  # pylint: disable=R0912,R0915
    """Escape the ampersand character

    >>> escape_ambiguous_ampersand('This is a test &amp; example.')
    'This is a test &amp;amp; example.'
    """
    if r'&' not in val:
        return val
    state = 0
    result = []
    amp_buff = []
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
            elif char == r'#':
                state = 2
                continue
            elif char == r';':
                if amp_buff:
                    result.append(r'&amp;')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&;')
                state = 0
                amp_buff = []
                continue
            elif char == r'&':
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
            if char == r'x' or char == r'X':
                state = 3
                continue
            elif 48 <= ord_c <= 57:
                amp_buff.append(char)
                continue
            elif char == r';':
                if amp_buff:
                    result.append(r'&amp;#')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&#;')
                state = 0
                amp_buff = []
                continue
            elif char == r'&':
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
            elif char == r';':
                if amp_buff:
                    result.append(r'&amp;#x')
                    result.extend(amp_buff)
                    result.append(r';')
                else:
                    result.append(r'&#x;')
                state = 0
                amp_buff = []
                continue
            elif char == r'&':
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
    """Escape attribute values"""
    val = escape_ambiguous_ampersand(val)
    if double_quote:
        return (val.replace(r'"', r'&#34;'), DOUBLE_QUOTE)
    elif r'"' in val:
        if '\'' in val:
            return (val.replace(r'"', r'&#34;'), DOUBLE_QUOTE)
        return (val, SINGLE_QUOTE)
    elif '\'' in val:
        return (val, DOUBLE_QUOTE)
    elif not val or any((c.isspace() for c in val)):
        return (val, DOUBLE_QUOTE)
    return (val, NO_QUOTES)


def unescape(_str: str) -> str:
    """Replace character references (e.g. &gt;, &#62;, &x3e;) with the literal characters

    >>> unescape(r'&#x22;')
    '"'
    >>> unescape(r'&x22;')
    '"'
    >>> unescape(r'&#34;')
    '"'
    >>> unescape(r'&quot;')
    '"'
    >>> unescape(r'&Utilde;')
    'Ũ'
    >>> unescape(r'String with &#34;special&#34; characters')
    'String with "special" characters'
    """
    if r'&' not in _str:
        return _str
    match = CHARREF.search(_str)
    while match:
        origrefer = r'&' + match.group(1)
        referstr = origrefer.lstrip(r'&').rstrip(r';')
        ltrlch = r''
        if referstr[0] == r'#' or referstr[0] in r'Xx':  # Decimal & Hexadecimal character reference
            num = int(referstr.replace(r'#', r'')[1:], 16) if r'x' in referstr.lower() else int(referstr[1:])
            if num in INVALID_CHARREFS:
                ltrlch = INVALID_CHARREFS[num]
            elif 0xD800 <= num <= 0xDFFF or num > 0x10FFFF:
                ltrlch = '\uFFFD'
            elif num in INVALID_CODEPOINTS:
                ltrlch = r''
            else:
                ltrlch = chr(num)
        elif referstr + r';' in HTML5:  # Named character reference
            ltrlch = HTML5[referstr + r';']
            _str = _str.replace(origrefer, ltrlch)
            match = CHARREF.search(_str)
            continue
        else:  # Unknown character reference
            ltrlch = r''
        _str = _str.replace(origrefer, ltrlch)
        if len(_str) < 4:
            return _str
        match = CHARREF.search(_str)
    return _str


def htmlunescape(_str: str) -> str:
    """Unescape &, ', ", <, and >

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
    """Convert an integer to Decimal-NCR/HTML-Entity (&#38;)"""
    if 0 <= _int <= 1114111:
        return r'&#{0};'.format(_int)
    raise ValueError(r'Integer value out of valid Unicode range (0 - {0})!'.format(1114111))


# SVG FUNCTIONS #


def parse_svg_size(value: float or int, def_units: str = r'px') -> float:
    """Parse value as SVG length and returns the value in pixels (or a negative scale: -1 = 100%)"""
    if not value:
        return 0.0
    parts = SVG_SIZE.match(value)
    if not parts:
        raise Exception(r'Unknown length format: "{}"'.format(value))
    num = float(parts.group(1))
    units = parts.group(2) or def_units
    if units == r'px':
        return num
    elif units == r'pt':
        return num * 1.25
    elif units == r'pc':
        return num * 15.0
    elif units == r'in':
        return num * 90.0
    elif units == r'mm':
        return num * 3.543307
    elif units == r'cm':
        return num * 35.43307
    elif units == r'%':
        return -num / 100.0
    raise Exception(r'Unknown length units: "{}"'.format(units))


def svgviewbox2pixels(viewbox: list) -> list or None:
    """Convert the measurements of an SVG viewbox to pixels"""
    if len(viewbox) == 4:
        viewbox[0] = parse_svg_size(viewbox[0])
        viewbox[1] = parse_svg_size(viewbox[1])
        viewbox[2] = parse_svg_size(viewbox[2])
        viewbox[3] = parse_svg_size(viewbox[3])
        if viewbox[2] * viewbox[3] <= 0.0:
            return None
        return viewbox
    return None


def resize_svg(xmltree: ET.ElementTree, options: dict) -> None:  # noqa: C901  # pylint: disable=R0912,R0914,R0915
    """Resize an SVG tree based on the specified options"""
    svg = xmltree.getroot()
    viewbox = svgviewbox2pixels(SVG_VIEWBOX_SEP.split(svg.get(r'viewBox', r'').strip()))
    if r'width' not in svg.keys() or r'height' not in svg.keys():
        if viewbox and len(viewbox) == 4:
            width = viewbox[2]
            height = viewbox[3]
        else:
            raise Exception(r'The SVG header must contain width and height attributes!')
    else:
        width = parse_svg_size(svg.get(r'width'))
        height = parse_svg_size(svg.get(r'height'))
    if width <= 0 or height <= 0:
        if viewbox:
            width = viewbox[2]
            height = viewbox[3]
        else:
            raise Exception(r'SVG width and height must be in absolute units and non-zero!')
    elif not viewbox:
        viewbox = [0, 0, width, height]
    # Read and convert size and margin values
    margin = parse_svg_size(options[r'margin'], r'px')
    twidth = None
    theight = None
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
    if twidth < 0:
        twidth = -width * twidth
    elif twidth > 0:
        twidth = max(0, twidth - margin * 2)
    if theight < 0:
        theight = -height * theight
    elif theight > 0:
        theight = max(0, theight - margin * 2)
    if not twidth:
        if not theight:
            twidth = width
            theight = height
        else:
            twidth = theight / height * width
    if not theight:
        theight = twidth / width * height
    # Set svg width and height, update viewport for margin
    svg.set(r'width', r'{}px'.format(twidth + margin * 2))
    svg.set(r'height', r'{}px'.format(theight + margin * 2))
    offsetx = 0
    offsety = 0
    if (twidth / theight) > (viewbox[2] / viewbox[3]):  # Target page is wider than source image
        page_width = (viewbox[3] / theight) * twidth
        offsetx = (page_width - viewbox[2]) / 2
        page_height = viewbox[3]
    else:
        page_width = viewbox[2]
        page_height = viewbox[2] / twidth * theight
        offsety = (page_height - viewbox[3]) / 2
    vb_margin = page_width / twidth * margin
    svg.set(r'viewBox', r'{} {} {} {}'.format(viewbox[0] - vb_margin - offsetx, viewbox[1] - vb_margin - offsety, page_width + vb_margin * 2, page_height + vb_margin * 2))
    # Add frame
    if options[r'frame']:
        layer = ET.SubElement(svg, r'g', nsmap=INKSCAPE_NAMESPACES)
        layer.set(r'{{{}}}groupmode'.format(INKSCAPE_NAMESPACES[r'inkscape']), r'layer')
        layer.set(r'{{{}}}label'.format(INKSCAPE_NAMESPACES[r'inkscape']), r'Frame')
        layer.set(r'{{{}}}insensitive'.format(INKSCAPE_NAMESPACES[r'sodipodi']), r'true')
        frame = ET.SubElement(layer, r'path')
        frame.set(r'style', r'fill:#fff;stroke:none')
        bleed = min(page_width, page_height) / 100
        frame.set(r'd', r'M {0} {1} v {3} h {2} v -{3} z M {4} {5} h {6} v {7} h -{6} z'.format(-viewbox[0] - vb_margin - offsetx - bleed, -viewbox[1] - vb_margin - offsety - bleed, page_width + (vb_margin + bleed) * 2, page_height + (vb_margin + bleed) * 2, viewbox[0], viewbox[1], viewbox[2], viewbox[3]))


def remove_duplicated_svg_ns(xmldata: str) -> str:
    """Remove duplicated SVG XML-namespace declarations"""
    if r'xmlns:svg="http://www.w3.org/2000/svg"' in xmldata and r'xmlns="http://www.w3.org/2000/svg"' in xmldata and r'<svg:' not in xmldata:
        xmldata = xmldata.replace(r'xmlns:svg="http://www.w3.org/2000/svg"', r'')
    return xmldata


def repair_svg_tag(_tag: str) -> str:
    """Auto-correct commonly mistyped/illformed SVG tag names"""
    if _tag.startswith(r'fe'):
        _tag = _tag.replace(r'feblend', r'feBlend').replace(r'fecolormatrix', r'feColorMatrix').replace(r'fecomponenttransfer', r'feComponentTransfer').replace(r'fecomposite', r'feComposite').replace(r'feconvolvematrix', r'feConvolveMatrix').replace(r'feDiffuseLighting', r'fediffuselighting').replace(r'fedisplacementmap', r'feDisplacementMap')
        _tag = _tag.replace(r'fedistantlight', r'feDistantLight').replace(r'feflood', r'feFlood').replace(r'fefunca', r'feFuncA').replace(r'fefuncb', r'feFuncB').replace(r'fefuncg', r'feFuncG').replace(r'fefuncr', r'feFuncR').replace(r'fegaussianblur', r'feGaussianBlur').replace(r'feimage', r'feImage').replace(r'femerge', r'feMerge')
        _tag = _tag.replace(r'femergenode', r'feMergeNode').replace(r'femorphology', r'feMorphology').replace(r'feoffset', r'feOffset').replace(r'fepointlight', r'fePointLight').replace(r'fespecularlighting', r'feSpecularLighting').replace(r'fespotlight', r'feSpotLight').replace(r'fetile', r'feTile').replace(r'feturbulence', r'feTurbulence')
    else:
        _tag = _tag.replace(r'foreignobject', r'foreignObject').replace(r'glyphref', r'glyphRef').replace(r'lineargradient', r'linearGradient').replace(r'radialgradient', r'radialGradient').replace(r'textpath', r'textPath')
        _tag = _tag.replace(r'solidColor', r'solidcolor').replace(r'polyLine', r'polyline').replace(r'colorprofile', r'color-profile').replace(r'colorProfile', r'color-profile').replace(r'fontface', r'font-face').replace(r'fontFace', r'font-face')
    return _tag


# MINIFY FUNCTIONS #


def condense_hex_colors(_css: str) -> str:
    """Shorten colors from #AABBCC to #ABC (where possible)

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
        if first.lower() == second.lower():
            _css = _css.replace(match.group(), r'#' + first.upper())
            match = HEX_COLOR.search(_css, match.end() - 3)
        else:
            match = HEX_COLOR.search(_css, match.end())
    return _css


def attribute_cleaner(_tag: str, _attr: str, _val: str, _doc_type: int) -> tuple:  # noqa: C901  # pylint: disable=R0912
    """Clean-up cetain XML/HTML attributes and values"""
    _attr = _attr.strip()
    _val = _val.strip()
    if _attr == r'encoding':  # Normalize encoding attribute
        return (_attr, _val.upper())
    elif _attr == r'xmlns:xlink':  # Fix any invalid XLink Namespaces
        return (_attr, r'http://www.w3.org/1999/xlink')
    elif _attr == r'type' and _tag in TAGS_WITH_MIMETYPES:  # Correct mimetypes
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
    """Sort attributes alphanumerically (but with `xmlns` first)"""
    return str((not _attr[0].startswith(r'xmlns:') and _attr[0].startswith(r'xmlns')) or _attr[0].startswith(r'xmlns:') or _attr[0])


def prettify_xml_schema(schema_data: str) -> str:
    """Prettify DTD and XSD XML schemas"""
    if not XML_DECLARATION.search(schema_data):
        schema_data = r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>' + schema_data
    schema_data = schema_data.replace('\n', r' ').replace('\r', r' ').replace('\t\t', r' ').replace('\t', r' ').replace(r'   ', r' ').replace('\f', r'').replace('\v', r'')
    schema_data = schema_data.replace(r'   ', r' ').replace(r'   ', r' ').replace(r'  ', r' ')
    return schema_data.replace(r' />', r'/>').replace(r'  ', r' ').replace(r'>  <', r'><').replace(r'> <', r'><').strip().replace(r'><', '>\n<')


# XML REPAIR FUNCTIONS #


def fix_xml_declaration(xmldata: str) -> str:
    """Fix and tweak the XML declaration specifically for the XML type"""
    if XML_DECLARATION.search(xmldata):
        if r'<!DOCTYPE html>' in xmldata:
            xmldata = re.sub(XML_DECLARATION, r'', xmldata)
        elif r'<mime-info xmlns="http://www.freedesktop.org/standards/shared-mime-info">' in xmldata:
            xmldata = re.sub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>', xmldata)
        elif r' standalone="yes"' in xmldata:
            xmldata = re.sub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>', xmldata)
        else:
            xmldata = re.sub(XML_DECLARATION, r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>', xmldata)
    return xmldata


def insert_missing_xml_namespaces(xmldata: str) -> str:
    """Insert missing XML namespaces based on present namespaced XML tags"""
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


class ParserBase:
    """Parser class that provides common support methods used by the SGML/HTML & XHTML parsers"""

    def __init__(self) -> None:
        """Initialize basic parser"""
        self._decl_otherchars = r''
        self.lineno = 1
        self.offset = 0
        self.rawdata = r''
        if self.__class__ is ParserBase:
            raise RuntimeError(r'ParserBase must be subclassed')

    def error(self, message: str) -> None:
        """Raise error in parser (To be overridden)"""
        raise NotImplementedError(message)

    def reset(self) -> None:
        """Reset location counters"""
        self.lineno = 1
        self.offset = 0

    def getpos(self) -> tuple:
        """Return current line number and offset"""
        return self.lineno, self.offset

    def updatepos(self, i: int, j: int) -> int:
        """Update line number and offset; Should be called for each piece of data once and in order"""
        if i >= j:
            return j
        rawdata = self.rawdata
        nlines = rawdata.count('\n', i, j)
        if nlines:
            self.lineno = self.lineno + nlines
            pos = rawdata.rindex('\n', i, j)
            self.offset = j - (pos + 1)
        else:
            self.offset = self.offset + j - i
        return j

    def handle_comment(self, data: str) -> None:
        """Handle comment (Overridable)"""
        pass

    def handle_decl(self, decl: str) -> None:
        """Handle declaration (Overridable)"""
        pass

    def parse_declaration(self, i: int) -> int:  # noqa: C901  # pylint: disable=R0912
        """Parse declaration tags"""
        rawdata = self.rawdata
        j = i + 2
        assert rawdata[i:j] == r'<!', r'Unexpected call to parse_declaration'
        if rawdata[j:j + 1] == r'>':  # Empty comment <!>
            return j + 1
        elif rawdata[j:j + 1] in {r'-', r''}:  # Start of buffer boundary (with or without a comment)
            return -1
        # A simple, practical version could look like: ((name|stringlit) S*) + '>'
        if rawdata[j:j + 2] == r'--':  # Comment
            return self.parse_comment(i)  # Locate --.*-- as the body of the comment
        elif rawdata[j] == r'[':  # Marked section
            return self.parse_marked_section(i)
        else:  # All other declaration elements
            decltype, j = self._scan_name(j, i)
        if j < 0:
            return j
        elif decltype == r'doctype':
            self._decl_otherchars = r''
        length = len(rawdata)
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
            elif char in ALPHASET:
                name, j = self._scan_name(j, i)
                del name
            elif char in self._decl_otherchars:
                j = j + 1
            elif char == r'[':
                if decltype == r'doctype':
                    j = self._parse_doctype_subset(j + 1, i)
                elif decltype in {r'attlist', r'element', r'link', r'linktype'}:
                    self.error(r'Unsupported `[` char in {} declaration'.format(decltype))
                else:
                    self.error(r'Unexpected `[` char in declaration')
            else:
                self.error(r'Unexpected {} char in declaration'.format(rawdata[j]))
            if j < 0:
                return j
        return -1  # Incomplete

    def parse_marked_section(self, i: int, report: int = 1) -> int:
        """Parse a marked section"""
        rawdata = self.rawdata
        assert rawdata[i:i + 3] == r'<![', r'Unexpected call to parse_marked_section()'
        sectname, j = self._scan_name(i + 3, i)
        if j < 0:
            return j
        elif sectname in {r'cdata', r'ignore', r'include', r'rcdata', r'temp'}:
            _match = MARKEDSECTIONCLOSE.search(rawdata, i + 3)  # Look for standard ]]> ending
        elif sectname in {r'if', r'else', r'endif'}:
            _match = MSMARKEDSECTIONCLOSE.search(rawdata, i + 3)  # Look for MS Office ]> ending
        else:
            self.error(r'Unknown status keyword {} in marked section'.format(rawdata[i + 3:j]))
        if not _match:
            return -1
        elif report:
            j = _match.start(0)
            self.unknown_decl(rawdata[i + 3: j])
        return _match.end(0)

    def parse_comment(self, i: int, report: int = 1) -> int:
        """Parse comment, return length or -1 (if not terminated)"""
        rawdata = self.rawdata
        if rawdata[i:i + 4] != r'<!--':
            self.error(r'Unexpected call to parse_comment()')
        match = COMMENTCLOSE.search(rawdata, i + 4)
        if not match:
            return -1
        elif report:
            j = match.start(0)
            self.handle_comment(rawdata[i + 4: j])
        return match.end(0)

    def _parse_doctype_subset(self, i: int, declstartpos: int) -> int:  # noqa: C901  # pylint: disable=R0912
        """Scan past the internal subset in a <!DOCTYPE declaration, returning the index just past any whitespace following the trailing ']'"""
        rawdata = self.rawdata
        length = len(rawdata)
        j = i
        while j < length:
            char = rawdata[j]
            if char == r'<':
                _str = rawdata[j:j + 2]
                if _str == r'<':  # End of buffer; incomplete
                    return -1
                elif _str != r'<!':
                    self.updatepos(declstartpos, j + 1)
                    self.error(r'Unexpected char in internal subset (in {})'.format(_str))
                if (j + 2) == length or (j + 4) > length:  # End of buffer; incomplete
                    return -1
                elif rawdata[j:j + 4] == r'<!--':
                    j = self.parse_comment(j, report=0)
                    if j < 0:
                        return j
                    continue
                name, j = self._scan_name(j + 2, declstartpos)
                if j == -1:
                    return -1
                elif name not in {r'attlist', r'element', r'entity', r'notation'}:
                    self.updatepos(declstartpos, j + 2)
                    self.error(r'Unknown declaration {} in internal subset'.format(name))
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
                elif rawdata[j] == r';':
                    j = j + 1
            elif char == r']':
                j = j + 1
                while j < length and rawdata[j].isspace():
                    j = j + 1
                if j < length:
                    if rawdata[j] == r'>':
                        return j
                    self.updatepos(declstartpos, j)
                    self.error(r'Unexpected char after internal subset')
                else:
                    return -1
            elif char.isspace():
                j = j + 1
            else:
                self.updatepos(declstartpos, j)
                self.error(r'Unexpected char {} in internal subset'.format(char))
        return -1  # End of buffer reached

    def _parse_doctype_element(self, i: int, declstartpos: int) -> int:
        """Scan past <!ELEMENT declarations"""
        name, j = self._scan_name(i, declstartpos)
        if j == -1 or name is None:
            return -1
        # Style content model; skip until '>'
        rawdata = self.rawdata
        if r'>' in rawdata[j:]:
            return rawdata.find(r'>', j) + 1
        return -1

    def _parse_doctype_attlist(self, i: int, declstartpos: int) -> int:  # noqa: C901  # pylint: disable=R0912
        """Scan past <!ATTLIST declarations"""
        rawdata = self.rawdata
        name, j = self._scan_name(i, declstartpos)
        char = rawdata[j:j + 1]
        if char == r'' or name is None:
            return -1
        elif char == r'>':
            return j + 1
        while 1:  # Scan a series of attribute descriptions
            name, j = self._scan_name(j, declstartpos)
            if j < 0 or name is None:
                return j
            char = rawdata[j:j + 1]
            if char == r'':
                return -1
            elif char == r'(':  # An enumerated type; look for ')'
                if r')' in rawdata[j:]:
                    j = rawdata.find(r')', j) + 1
                else:
                    return -1
                while rawdata[j:j + 1].isspace():
                    j = j + 1
                if not rawdata[j:]:  # End of buffer, incomplete
                    return -1
            else:
                name, j = self._scan_name(j, declstartpos)
            char = rawdata[j:j + 1]
            if not char or name is None:
                return -1
            elif char in '\'"':
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
        """Scan past <!NOTATION declarations"""
        name, j = self._scan_name(i, declstartpos)
        if j < 0 or name is None:
            return j
        rawdata = self.rawdata
        while 1:
            char = rawdata[j:j + 1]
            if not char:  # End of buffer; incomplete
                return -1
            elif char == r'>':
                return j + 1
            elif char in '\'"':
                _match = DECLSTRINGLIT_MATCH(rawdata, j)
                if not _match:
                    return -1
                j = _match.end()
            else:
                name, j = self._scan_name(j, declstartpos)
                if j < 0:
                    return j

    def _parse_doctype_entity(self, i: int, declstartpos: int) -> int:  # noqa: C901  # pylint: disable=R0912
        """Scan past <!ENTITY declarations"""
        rawdata = self.rawdata
        if rawdata[i:i + 1] == r'%':
            j = i + 1
            while 1:
                char = rawdata[j:j + 1]
                if not char:
                    return -1
                elif char.isspace():
                    j = j + 1
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
        """Scan a name token, the new position, and the token, or return -1 if the end of the buffer is reached"""
        rawdata = self.rawdata
        length = len(rawdata)
        if i == length:
            return (None, -1)
        _match = DECLNAME_MATCH(rawdata, i)
        if _match:
            _str = _match.group()
            name = _str.strip()
            if (i + len(_str)) == length:
                return (None, -1)  # End of buffer
            return (name.lower(), _match.end())
        else:
            self.updatepos(declstartpos, i)
            self.error(r'Expected name token at {}'.format(rawdata[declstartpos:declstartpos + 20]))
            return (None, -2)

    def unknown_decl(self, data: str) -> None:
        """Provide an overridable handler for unknown objects"""
        self.error(r'<![' + data + r']>')


class HTMLParser(ParserBase):  # pylint: disable=R0904
    """Find markup objects and call handler functions

    Usage:
        p = HTMLParser()
        p.feed(data)
        # Perform some task
        p.close()
    """

    def __init__(self, *, convert_charrefs: bool = False) -> None:
        """Initialize and reset this instance; If convert_charrefs is True, all character references are automatically converted to the corresponding Unicode characters"""
        self.__starttag_text = None
        self.cdata_elem = None
        self.convert_charrefs = convert_charrefs
        self.in_xml = False
        self.interesting = INTERESTING_NORMAL
        self.lasttag = r'???'
        self.rawdata = r''
        super(HTMLParser, self).__init__()

    def error(self, message: str) -> None:
        """Raise error in parser"""
        raise Exception(message)

    def reset(self) -> None:
        """Reset this instance"""
        self.cdata_elem = None
        self.interesting = INTERESTING_NORMAL
        self.lasttag = r'???'
        self.rawdata = r''
        ParserBase.reset(self)

    def feed(self, data: str) -> None:
        """Feed data to the parser"""
        self.rawdata = self.rawdata + data
        self.goahead(False)

    def close(self) -> None:
        """Handle any buffered data"""
        self.goahead(True)

    def get_starttag_text(self) -> None or str:
        """Return full source of start tag"""
        return self.__starttag_text

    def set_cdata_mode(self, elem: str) -> None:
        """Lowercase HTML element names"""
        self.cdata_elem = elem.lower()
        self.interesting = re.compile(r'</\s*{}\s*>'.format(self.cdata_elem), re.I)

    def clear_cdata_mode(self) -> None:
        """Clear self.cdata_elem and self.interesting"""
        self.interesting = INTERESTING_NORMAL
        self.cdata_elem = None

    def goahead(self, end: bool) -> None:  # noqa: C901  # pylint: disable=R0912,R0915
        """Handle data as far as reasonable. May leave state and data to be processed by a subsequent call. If `end` is true, force handling all data as if followed by EOF marker"""
        rawdata = self.rawdata
        i = 0
        length = len(rawdata)
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
                _match = CHARREF.match(rawdata, i)
                if _match:
                    name = _match.group()[2:-1]
                    self.handle_charref(name)
                    k = _match.end()
                    if not startswith(r';', k - 1):
                        k = k - 1
                    i = self.updatepos(i, k)
                    continue
                else:
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
                        k = k - 1
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
                elif (i + 1) < length:  # Not the end of the buffer
                    self.handle_data(r'&')
                    i = self.updatepos(i, i + 1)
                else:
                    break
            else:
                assert 0, r'There appears to be an issue with `interesting.search()`'
        if end and i < length and not self.cdata_elem:
            if self.convert_charrefs and not self.cdata_elem:
                self.handle_data(unescape(rawdata[i:length]))
            else:
                self.handle_data(rawdata[i:length])
            i = self.updatepos(i, length)
        self.rawdata = rawdata[i:]

    def parse_html_declaration(self, i: int) -> int:
        """Parse HTML declarations; return length or -1 (if not terminated)"""
        rawdata = self.rawdata
        assert rawdata[i:i + 2] == r'<!', r'Unexpected call to parse_html_declaration()'
        if rawdata[i:i + 4] == r'<!--':  # This case is handled in goahead()
            return self.parse_comment(i)
        elif rawdata[i:i + 3] == r'<![':
            return self.parse_marked_section(i)
        elif rawdata[i:i + 9].lower() == r'<!doctype':  # Find the closing >
            gtpos = rawdata.find(r'>', i + 9)
            if gtpos == -1:
                return -1
            self.handle_decl(rawdata[i + 2:gtpos])
            return gtpos + 1
        return self.parse_bogus_comment(i)

    def parse_bogus_comment(self, i: int, report: int = 1) -> int:
        """Parse bogus comment; return length or -1 (if not terminated)"""
        rawdata = self.rawdata
        assert rawdata[i:i + 2] in {r'<!', r'</'}, r'Unexpected call to parse_comment()'
        pos = rawdata.find(r'>', i + 2)
        if pos == -1:
            return -1
        elif report:
            self.handle_comment(rawdata[i + 2:pos])
        return pos + 1

    def parse_pi(self, i: int) -> int:
        """Parse processing instruction; return end or -1 (if not terminated)"""
        rawdata = self.rawdata
        assert rawdata[i:i + 2] == r'<?', r'Unexpected call to parse_pi()'
        match = PICLOSE.search(rawdata, i + 2)
        if not match:
            return -1
        j = match.start()
        self.handle_pi(rawdata[i + 2: j])
        j = match.end()
        return j

    def parse_starttag(self, i: int) -> int:  # noqa: C901  # pylint: disable=R0912,R0915
        """Handle starttag; return end or -1 (if not terminated)"""
        self.__starttag_text = None
        endpos = self.check_for_whole_start_tag(i)
        if endpos < 0:
            return endpos
        rawdata = self.rawdata
        self.__starttag_text = rawdata[i:endpos]
        # Parse the data between i+1 and j into a tag and attrs
        attrs = []
        _match = TAGFIND_TOLERANT.match(rawdata, i + 1)
        assert _match, r'Unexpected call to parse_starttag()'
        k = _match.end()
        tag = _match.group(1)
        if tag in XML_ROOT_TAGS:
            self.in_xml = True
        if self.in_xml:
            self.lasttag = tag
        else:
            self.lasttag = tag = tag.lower()
        while k < endpos:  # Parse Attributes
            _match = ATTRFIND_TOLERANT.match(rawdata, k)
            if not _match:
                break
            attrname, rest, attrvalue = _match.group(1, 2, 3)
            if not rest:
                attrvalue = None
            elif attrvalue[:1] == '\'' == attrvalue[-1:] or attrvalue[:1] == r'"' == attrvalue[-1:]:
                attrvalue = attrvalue[1:-1]
            if attrvalue:
                attrvalue = unescape(attrvalue)
            if self.in_xml:
                attrs.append((attrname, attrvalue))
            else:
                attrs.append((attrname.lower(), attrvalue))
            attrs.sort(key=attr_sort)
            k = _match.end()
        end = rawdata[k:endpos].strip()
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
        """Check to see if starttag is complete; return end or -1 (if incomplete)"""
        rawdata = self.rawdata
        _match = LOCATESTARTTAGEND_TOLERANT.match(rawdata, i)
        if _match:
            j = _match.end()
            _next = rawdata[j:j + 1]
            if _next == r'>':
                return j + 1
            elif _next == r'/':
                if rawdata.startswith(r'/>', j):
                    return j + 2
                elif rawdata.startswith(r'/', j):  # Buffer boundary
                    return -1
                elif j > i:
                    return j
                return i + 1
            elif _next == r'':  # End of input
                return -1
            elif _next in ALPHASET:  # End of input in or before attribute value or the '/' from a '/>' ending
                return -1
            elif j > i:
                return j
            return i + 1
        raise AssertionError(r'Fell through if constructs in check_for_whole_start_tag()')

    def parse_endtag(self, i: int) -> int:  # noqa: C901  # pylint: disable=R0912
        """Parse endtag; return end or -1 (if incomplete)"""
        rawdata = self.rawdata
        assert rawdata[i:i + 2] == r'</', r'Unexpected call to parse_endtag'
        match = ENDENDTAG.search(rawdata, i + 1)  # >
        if not match:
            return -1
        gtpos = match.end()
        match = ENDTAGFIND.match(rawdata, i)  # </ + tag + >
        if not match:
            if self.cdata_elem is not None:
                self.handle_data(rawdata[i:gtpos])
                return gtpos
            namematch = TAGFIND_TOLERANT.match(rawdata, i + 2)
            if not namematch:
                if rawdata[i:i + 3] == r'</>':
                    return i + 3
                return self.parse_bogus_comment(i)
            tagname = namematch.group(1)
            if not self.in_xml:
                tagname = tagname.lower()
            elif self.in_xml and tagname in XML_ROOT_TAGS:
                self.in_xml = False
            # Consume and ignore other stuff between the name and the >
            gtpos = rawdata.find(r'>', namematch.end())
            self.handle_endtag(tagname)
            return gtpos + 1
        # script or style
        elem = match.group(1)
        if not self.in_xml:
            elem = elem.lower()
        elif self.in_xml and elem in XML_ROOT_TAGS:
            self.in_xml = False
        if self.cdata_elem is not None:
            if elem != self.cdata_elem:
                self.handle_data(rawdata[i:gtpos])
                return gtpos
        self.handle_endtag(elem)
        self.clear_cdata_mode()
        return gtpos

    def handle_startendtag(self, tag: str, attrs: list, closing_type: int = -1) -> None:
        """Finish processing of start+end tag - <tag.../> (Overridable)"""
        if closing_type == 1:
            self.handle_starttag(tag, attrs)
            self.handle_endtag(tag)
        else:
            self.handle_starttag(tag, attrs)
            self.handle_endtag(tag)

    def handle_starttag(self, tag: str, attrs: list) -> None:
        """Handle start tag (Overridable)"""
        pass

    def handle_endtag(self, tag: str) -> None:
        """Handle end tag (Overridable)"""
        pass

    def handle_charref(self, name: str) -> None:
        """Handle character reference (Overridable)"""
        pass

    def handle_entityref(self, name: str) -> None:
        """Handle entity reference (Overridable)"""
        pass

    def handle_data(self, data: str) -> None:
        """Handle data (Overridable)"""
        pass

    def handle_comment(self, data: str) -> None:
        """Handle comment (Overridable)"""
        pass

    def handle_decl(self, decl: str) -> None:
        """Handle declaration (Overridable)"""
        pass

    def handle_pi(self, data: str) -> None:
        """Handle processing instruction (Overridable)"""
        pass

    def unknown_decl(self, data: str) -> None:
        """Handle unknown declarations (Overridable)"""
        self.error(r'Unknown declaration: <![' + data + r']>')


class Minifier(object):
    """An object that supports XML/HTML Minification; Options are passed into this class at initialization time and are persisted across each use of the instance"""

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
        """Initialize the needed minifier"""
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
        """Run XML/HTML code through the minifier in one pass"""
        self._parser.reset()
        self.input(*_input)
        return self.finalize()

    def finalize(self) -> str:
        """Flushes any remaining XML/HTML, returns the minified result, and resets the process's internal parser so that new code can be minified"""
        self._parser.close()
        result = self._parser.result
        self._parser.reset()
        return result

    def input(self, *_input: str) -> None:
        """Feed more XML/HTML into the input stream"""
        for i in _input:
            self._parser.feed(i)

    @property
    def output(self) -> str:
        """Retrieve the minified output generated thus far"""
        return self._parser.result


class XMLMinParser(HTMLParser):  # pylint: disable=R0902
    """XML/HTML Parser"""

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
        """Initialize XML/HTML parser"""
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
        self._data_buffer = []
        self._in_pre_tag = 0
        self._in_head = False
        self._in_metadata = False
        self._in_title = False
        self._after_doctype = False
        self._tag_stack = []
        self._title_newly_opened = False
        self.__title_trailing_whitespace = False
        self._doctype_inserted = False
        self._upgrade_svg10 = False

    def reset(self) -> None:
        """Flushes any remaining XML/HTML and resets the process's internal parser so that new XML/HTML can be processed"""
        self._data_buffer = []
        HTMLParser.reset(self)

    @property
    def result(self) -> str:
        """Retrieve the processed output generated thus far"""
        return r''.join(self._data_buffer)

    def insert_doctype_tag(self, decl: str = r'') -> None:
        """Insert the DOCTYPE tag"""
        if self._after_doctype:
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
        """Test if the tag uses the `pre` attribute"""
        for k in attrs:
            if k[0] == self.pre_attr:
                return True
        return False

    def in_tag(self, *tags: str) -> bool or str:
        """Test if the given tags are within the tag stack"""
        for tag in self._tag_stack:
            if tag[0] in tags:
                return tag
        return False

    def should_preserve_ws(self, tag: str, attrs: list) -> bool:
        """Test if whitespace should be preserved in the tag"""
        if tag in self.pre_tags or self._has_pre(attrs) or self._in_pre_tag > 0:  # Pre
            return True
        elif tag in CDATA_CONTENT_ELEMENTS:  # Cdata
            return True
        elif self.doc_type == FILETYPE_MATHML and tag == r'annotation':  # MathML <annotation>
            return True
        elif self.doc_type == FILETYPE_XML:
            if self.in_tag(r'mime-info') and tag in {r'acronym', r'comment', r'expanded-acronym'}:  # XDG Mime
                return True
            elif self.in_tag(r'interface', r'object') and tag == r'property':  # Glade XML
                return True
        return False

    def build_tag(self, tag: str, attrs: list, close_tag: bool) -> str:  # noqa: C901  # pylint: disable=R0912,R0915
        """Create an XML/HTML tag"""
        if is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return r''
        elif self.doc_type == FILETYPE_SVG and close_tag and tag in {r'defs', r'g'}:
            return r''
        elif not self._doctype_inserted and self.doc_type == FILETYPE_SVG and tag == r'svg':
            self.insert_doctype_tag()
        elif self.doc_type == FILETYPE_SVG and tag == r'stop' and not isintuplelist(attrs, r'offset'):
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
            if self.doc_type == FILETYPE_SVG and tag == r'svg' and k == r'viewbox':
                k = r'viewBox'
            elif self._upgrade_svg10 and self.doc_type == FILETYPE_SVG and tag == r'svg' and k == r'version':
                v = r'1.1'
            if not k:
                continue
            result_write(r' ' + escape(k))
            if v:  # Attribute value
                if self.doc_type == FILETYPE_HTML and self.reduce_bool_attrs and (k in BOOLEAN_ATTRIBUTES.get(tag, []) or k in BOOLEAN_ATTRIBUTES[r'*']):
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
        """Close previously opened tags up to the specified tag"""
        num_pres = 0
        i = 0
        for i, _tag in enumerate(self._tag_stack):
            if _tag[1]:
                num_pres += 1
            if _tag[0] == tag:
                break
            # Raise exception if an unknown tag is found
            elif _tag[0] in {r'body', r'head'}:
                raise Exception(r'Unknown tag found!')
        self._tag_stack = self._tag_stack[i + 1:]
        return num_pres

    def handle_charref(self, name: str) -> None:
        """Process decimal and hexadecimal numeric character references of the form `&#NNN;` and `&#xNNN;`"""
        if self._in_title:
            if not self._title_newly_opened and self.__title_trailing_whitespace:
                self._data_buffer.append(r' ')
                self.__title_trailing_whitespace = False
            self._title_newly_opened = False
        self._data_buffer.append(r'&#{};'.format(name))

    def handle_comment(self, data: str) -> None:
        """Process comments"""
        if not self.remove_comments or (data and (data[0] == r'!' or re.match(r'^\[if\s', data))):
            self._data_buffer.append(r'<!--{}-->'.format(data[1:] if data[0] == r'!' else data))

    def handle_data(self, data: str) -> None:  # noqa: C901  # pylint: disable=R0912
        """Process arbitrary data (such as <script> and <style>)"""
        if self._in_metadata and self.remove_metadata > 0:
            return
        elif self._in_pre_tag > 0:
            self._data_buffer.append(data)
            return
        elif not data.strip():
            return
        elif self.remove_empty_space or self.remove_all_empty_space or self._in_head or self._after_doctype:
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
        elif self._in_pre_tag == 0 and self._data_buffer:
            # It is possible that two spaces can get appended when a comment is removed from between two blocks (this code avoids this)
            if data[0] == r' ' and self._data_buffer[-1][-1] == r' ':
                data = data[1:]
                if not data:
                    return
        self._data_buffer.append(data)

    def handle_decl(self, decl: str) -> None:
        """Process the XML/HTML doctype declaration"""
        if len(self._data_buffer) == 1 and WHITESPACE.match(self._data_buffer[0]):
            self._data_buffer = []
        if not self._doctype_inserted and decl.strip().startswith(r'DOCTYPE'):
            self.insert_doctype_tag(decl)
        else:
            self._data_buffer.append(r'<!' + decl + r'>')
        self._after_doctype = True

    def handle_endtag(self, tag: str) -> None:  # noqa: C901  # pylint: disable=R0912
        """Process end tags"""
        if tag == r'a':  # </a> and <p>
            contains_p = False
            i = 0
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
            try:
                self._in_pre_tag -= self._close_tags_up_to(tag)
            except BaseException:  # Leave closing tags alone since they affect output
                # Some tags do not require a start tag; For instance, in Chrome, `</p>` results in `<p></p>`
                pass
        self._data_buffer.extend([r'</', escape(tag), r'>'])

    def handle_entityref(self, name: str) -> None:
        """Process a named character reference of the form `&name;`"""
        if self._in_title:
            if not self._title_newly_opened and self.__title_trailing_whitespace:
                self._data_buffer.append(r' ')
                self.__title_trailing_whitespace = False
            self._title_newly_opened = False
        self._data_buffer.append(r'&{};'.format(name))

    def handle_pi(self, data: str) -> None:
        """Process the processing instruction tag"""
        if data.strip().startswith(r'xml'):
            if r'standalone="yes"' in data.lower() or 'standalone=\'yes\'' in data.lower():
                self._data_buffer.append(r'<?xml version="1.0" encoding="UTF-8" standalone="yes"?>')
            else:
                self._data_buffer.append(r'<?xml version="1.0" encoding="UTF-8" standalone="no"?>')
        else:
            self._data_buffer.append(r'<?' + data + r'>')

    def handle_startendtag(self, tag: str, attrs: list, closing_type: int = -1) -> None:
        """Process XHTML-style empty tags (such as `<br/>`)"""
        self._after_doctype = False
        if is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return
        elif not self.keep_pre:
            attrs = [(k, v) for k, v in attrs if k != r'pre']
        if closing_type == 1:  # Self-closing tag
            self._data_buffer.append(self.build_tag(tag, attrs, True))
        else:  # Miscellaneous XML self-closing tag
            self._data_buffer.append(self.build_tag(tag, attrs, is_self_closing_tag(tag, self.doc_type, self._tag_stack)))

    def handle_starttag(self, tag: str, attrs: list) -> None:  # noqa: C901
        """Process start tags"""
        self._after_doctype = False
        if not self._doctype_inserted:
            self.insert_doctype_tag()  # Insert DOCTYPE tag if it is missing
        if self.remove_metadata > 0 and tag == r'metadata':
            self._in_metadata = True
            return
        elif self.doc_type == FILETYPE_SVG and self.remove_metadata > 0 and tag in USELESS_SVG_TAGS:
            self._in_metadata = True
            return
        elif is_removable_metadata_tag(self.doc_type, tag, self._in_metadata, self.remove_metadata):
            return
        elif self.doc_type == FILETYPE_HTML:  # HTML <head> and <title>
            if tag == r'head':
                self._in_head = True
            elif self._in_head and tag == r'title':
                self._in_title = True
                self._title_newly_opened = True
        for open_tags, closed_by_tags in TAG_SETS:
            in_tag = self.in_tag(*open_tags)
            if in_tag and (tag in closed_by_tags or r'*' in closed_by_tags):
                self._in_pre_tag -= self._close_tags_up_to(in_tag[0])
        start_pre = False
        if self.should_preserve_ws(tag, attrs):
            self._in_pre_tag += 1
            start_pre = True
        self._tag_stack.insert(0, (tag, start_pre))
        if not self.keep_pre:
            attrs = [(k, v) for k, v in attrs if k != self.pre_attr]
        self._data_buffer.append(self.build_tag(tag, attrs, False))

    def unknown_decl(self, data: str) -> None:
        """Process the unrecognized declaration tag"""
        self._data_buffer.append(r'<![' + data + r']>')
