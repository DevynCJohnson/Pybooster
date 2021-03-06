[styling]
character=character
comment=comment
commentdoc=commentdoc
commentdockeyword=commentdockeyword
commentdockeyworderror=commentdockeyworderror
commentline=commentline
commentlinedoc=commentlinedoc
escapesequence=escapesequence
globalclass=globalclass
hashquotedstring=hashquotedstring
identifier=default
number=number
operator=operator
preprocessor=preprocessor
preprocessorcomment=preprocessorcomment
preprocessorcommentdoc=preprocessorcommentdoc
regex=regex
string=string
stringeol=stringeol
stringraw=stringraw
taskmarker=taskmarker
userliteral=userliteral
uuid=uuid
verbatim=verbatim
word2=word2
word=word

[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=abs abstract acos anchor asin async atan atan2 await big bold boolean break byte case catch ceil char charAt charCodeAt class concat const continue cos Date debugger default delete do double each else enum escape exp export extends false final finally fixed float floor fontcolor fontsize for fromCharCode function get goto if implements import in indexOf Infinity instanceof int interface italics join lastIndexOf length let link log long Math.acos Math.asin Math.async Math.atan Math.atan2 Math.log Math.pow Math.round Math.sin Math.sqrt Math.tan max MAX_VALUE min MIN_VALUE NaN native NEGATIVE_INFINITY new null package pop POSITIVE_INFINITY pow private protected prototype public push random return reverse round set shift short sin slice small sort splice split sqrt static strike string String sub substr substring sup super switch synchronized tan this throw throws toLowerCase toString toUpperCase transient true try typeof undefined unescape unshift valueOf var void volatile while with yield
secondary=Array BigInt BigInt64Array BigUint64Array Boolean constructor Date decodeURI decodeURIComponent document.getElementById encodeURI encodeURIComponent Error eval EvalError Float32Array Float64Array Function Int16Array Int32Array Int8Array isFinite isNaN Map Math Number Object parseFloat parseInt prototype RangeError ReferenceError RegExp Set String Symbol SyntaxError TypeError Uint16Array Uint32Array Uint8Array Uint8ClampedArray URIError WeakMap WeakSet

[lexer_properties=C]
lexer.cpp.backquoted.strings=1

[settings]
extension=js
mime_type=application/javascript
comment_single=//
comment_open=/*
comment_close=*/
comment_use_indent=true
context_action_cmd=

[indentation]
type=0
width=2

[build-menu]
FT_00_LB=_Code Formatter
FT_00_CM=code-formatter --js --file "%d/%f"
FT_00_WD=
FT_01_LB=_JS Analysis
FT_01_CM=jsanalysis "%d/%f"
FT_01_WD=
error_regex=^([^:]+):( line |)([0-9]+)[,:]( col |)([0-9]+)?.*$
