[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=__DATE__ __EOF__ __FILE__ __FUNCTION__ __gshared __LINE__ __MODULE__ __parameters __PRETTY_FUNCTION__ __TIME__ __TIMESTAMP__ __traits __vector __VENDOR__ __VERSION__ abstract alias align asm assert auto body bool break byte case cast catch cdouble cent cfloat char class const continue creal dchar debug default delegate delete deprecated do double else enum export extern false final finally float for foreach foreach_reverse function goto idouble if ifloat immutable import in inout int interface invariant ireal is lazy long macro mixin module new nothrow null out override package pragma private protected public pure real ref return scope shared short static struct super switch synchronized template this throw true try typedef typeid typeof ubyte ucent uint ulong union unittest ushort version void volatile wchar while with
secondary=
types=

[lexer_properties]
fold.compact=0
fold.d.comment.explicit=1
fold.d.comment.multiline=1
fold.d.explicit.anywhere=1
fold.d.explicit.end=// }
fold.d.explicit.start=// (FB){
fold.d.syntax.based=1
lexer.d.fold.at.else=1

[settings]
extension=d
mime_type=text/x-dsrc
comment_single=//
comment_open=/+
comment_close=+/
comment_use_indent=true
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_Build
FT_00_CM=gdmd -w -c "%d/%f"
FT_00_WD=
FT_01_LB=_Link
FT_01_CM=gdmd -w -of"%e" "%d/%f"
FT_01_WD=
FT_02_LB=Build
FT_02_CM=dmd -w -c "%d/%f"
FT_02_WD=
FT_03_LB=Link
FT_03_CM=dmd -w -of"%e" "%d/%f"
FT_03_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%e"
EX_00_WD=
error_regex=^([^:]+):([0-9]+):([0-9:]+)?.*$
