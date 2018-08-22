[keywords]
docComment=a addindex addtogroup anchor arg attention author authors b brief bug c callergraph callgraph category cite class code cond copybrief copydetails copydoc copyright date def defgroup deprecated details dir dontinclude dot dotfile e else elseif em endcode endcond enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endrtfonly endverbatim endxmlonly enum example exception extends file fn headerfile hideinitializer htmlinclude htmlonly if ifnot image implements include includelineno ingroup interface internal invariant latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] post pre private privatesection property protected protectedsection protocol public publicsection ref related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa section see short showinitializer since skip skipline snippet struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version warning weakgroup xmlonly xrefitem
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

[build_settings]
compiler=valac -c "%f"
linker=valac "%f"
run_cmd=./"%e"
