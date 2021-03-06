[styling=C]

[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=abstract as base bool break by byte case catch char checked class const continue decimal default delegate do double else enum equals event explicit extern false finally fixed float for foreach goto if implicit in int interface internal is lock long namespace new null object on operator out override params private protected public readonly ref return sbyte sealed short sizeof stackalloc static string struct switch this throw true try typeof uint ulong unchecked unsafe ushort using virtual void volatile while
secondary=add alias ascending async await descending dynamic from get global group into join let orderby partial remove select set value var where yield

[lexer_properties=C]
preprocessor.end.$(file.patterns.cs)=endif endregion
preprocessor.middle.$(file.patterns.cs)=else elif
preprocessor.start.$(file.patterns.cs)=if region
preprocessor.symbol.$(file.patterns.cs)=#

[settings]
lexer_filetype=C
tag_parser=C
extension=cs
mime_type=text/x-csharp
comment_single=//
comment_open=/*
comment_close=*/
comment_use_indent=true
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_Compile
FT_00_CM=mcs /t:winexe "%d/%f" /r:System,System.Drawing
FT_00_WD=
FT_01_LB=
FT_01_CM=
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=mono "%d/%e.exe"
EX_00_WD=
error_regex=
