[keywords]
docComment=Authors Bugs Copyright Date Deprecated Examples History License Macros Params Returns See_Also Standards Throws Version a addindex addtogroup anchor arg attention author authors b brief bug c callergraph callgraph category cite class code cond copybrief copydetails copydoc copyright date def defgroup deprecated details dir dontinclude dot dotfile e else elseif em endcode endcond enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endrtfonly endverbatim endxmlonly enum example exception extends file fn headerfile hideinitializer htmlinclude htmlonly if ifnot image implements include includelineno ingroup interface internal invariant latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] post pre private privatesection property protected protectedsection protocol public publicsection ref related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa section see short showinitializer since skip skipline snippet struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version warning weakgroup xmlonly xrefitem
primary=__DATE__ __EOF__ __FILE__ __FUNCTION__ __gshared __LINE__ __MODULE__ __parameters __PRETTY_FUNCTION__ __TIME__ __TIMESTAMP__ __traits __vector __VENDOR__ __VERSION__ abstract alias align asm assert auto body bool break byte case cast catch cdouble cent cfloat char class const continue creal dchar debug default delegate delete deprecated do double else enum export extern false final finally float for foreach foreach_reverse function goto idouble if ifloat immutable import in inout int interface invariant ireal is lazy long macro mixin module new nothrow null out override package pragma private protected public pure real ref return scope shared short static struct super switch synchronized template this throw true try typedef typeid typeof ubyte ucent uint ulong union unittest ushort version void volatile wchar while with
secondary=
types=

[lexer_properties]
fold.d.comment.explicit=0

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
FT_00_LB=GDMD Build
FT_00_CM=gdmd -w -c "%d/%f"
FT_00_WD=
FT_01_LB=GDMD Link
FT_01_CM=gdmd -w -of"%e" "%d/%f"
FT_01_WD=

[build_settings]
compiler=dmd -w -c "%d/%f"
linker=dmd -w -of"%e" "%d/%f"
run_cmd="%d/%e"
