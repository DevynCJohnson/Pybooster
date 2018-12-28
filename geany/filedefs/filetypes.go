[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=break case chan const continue default defer else fallthrough false for func go goto if import interface iota map nil package range return select struct switch true type var
secondary=bool byte complex128 complex64 error float32 float64 int int16 int32 int64 int8 rune string uint uint16 uint32 uint64 uint8 uintptr

[lexer_properties]
fold.preprocessor=0
fold.cpp.comment.explicit=1
fold.cpp.comment.multiline=1
fold.cpp.explicit.anywhere=1
fold.cpp.explicit.end=// }
fold.cpp.explicit.start=// (FB){
lexer.cpp.allow.dollars=0
lexer.cpp.backquoted.strings=1
styling.within.preprocessor=1

[settings]
extension=go
mime_type=text/x-go
comment_single=//
comment_open=/*
comment_close=*/
comment_use_indent=true
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_Build
FT_00_CM=go build "%d/%f"
FT_00_WD=
FT_01_LB=Fmt
FT_01_CM=go fmt .
FT_01_WD=
FT_02_LB=_Test
FT_02_CM=go test
FT_02_WD=
EX_00_LB=_Run
EX_00_CM=go run "%d/%e"
EX_00_WD=
error_regex=
