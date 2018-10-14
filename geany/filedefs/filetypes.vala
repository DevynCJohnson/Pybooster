[styling=C]

[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=abstract as async base bool break callback case catch char class const constpointer construct continue default delegate delete do double dynamic else ensures enum errordomain extern false finally float for foreach generic get global if in inline int int16 int32 int64 int8 interface internal is lock long namespace new null out override owned private protected public ref requires return sealed set short signal size_t sizeof ssize_t static string struct switch this throw throws time_t true try typeof uchar uint uint16 uint32 uint64 uint8 ulong unichar unowned ushort using value var virtual void weak while yield
secondary=

[lexer_properties=C]
lexer.cpp.triplequoted.strings=1

[settings]
lexer_filetype=C
extension=vala
mime_type=text/x-vala
comment_single=//
comment_open=/*
comment_close=*/
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_Compile
FT_00_CM=valac -c "%d/%f"
FT_00_WD=
FT_01_LB=_Linker
FT_01_CM=valac "%d/%f"
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%e"
EX_00_WD=
error_regex=
