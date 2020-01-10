[styling]
character=character
comment=comment
commentdoc=commentdoc
commentline=commentline
coroutines=coroutines
function_basic=function_basic
function_other=function_other
identifier=identifier
keywords=keywords
label=label
literalstring=literalstring
number=number
operator=operator
preprocessor=preprocessor
string=string
stringeol=stringeol
user1=user1
user2=user2
user3=user3
user4=user4
word5=word5
word6=word6
word7=word7
word8=word8
word=word

[keywords]
coroutines=appendto clock closefile coroutine.create coroutine.resume coroutine.running coroutine.status coroutine.wrap coroutine.yield date difftime execute exit flush getenv io.close io.flush io.input io.lines io.open io.output io.popen io.read io.stderr io.stdin io.stdout io.tmpfile io.type io.write openfile os.clock os.date os.difftime os.execute os.exit os.getenv os.remove os.rename os.setlocale os.time os.tmpname package.cpath package.loaded package.loadlib package.path package.preload package.seeall read readfrom remove rename seek setlocale time tmpfile tmpname write writeto
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
function_basic=_ALERT _ERRORMESSAGE _G _INPUT _OUTPUT _PROMPT _STDERR _STDIN _STDOUT _VERSION assert call collectgarbage coroutine debug dofile dostring error foreach foreachi gcinfo getfenv getmetatable getn globals io ipairs load loadfile loadlib loadstring math module newtype next os pairs pcall print rawequal rawget rawset require select setfenv setmetatable sort string table tinsert tonumber tostring tremove type unpack xpcall
function_other=abs acos asin atan atan2 ceil cos deg exp floor format frexp gsub ldexp log log10 math.abs math.acos math.asin math.atan math.atan2 math.ceil math.cos math.cosh math.deg math.exp math.floor math.fmod math.frexp math.huge math.ldexp math.log math.log10 math.max math.min math.mod math.modf math.pi math.pow math.rad math.random math.randomseed math.sin math.sinh math.sqrt math.tan math.tanh max min mod rad random randomseed sin sqrt strbyte strchar strfind string.byte string.char string.dump string.find string.format string.gfind string.gmatch string.gsub string.len string.lower string.match string.rep string.reverse string.sub string.upper strlen strlower strrep strsub strupper table.concat table.foreach table.foreachi table.getn table.insert table.maxn table.remove table.setn table.sort tan
keywords=and break do else elseif end false for function if in local nil not or repeat return then true until while
user1=
user2=
user3=
user4=

[lexer_properties]
fold.compact=0
fold.cpp.comment.explicit=1
fold.cpp.comment.multiline=1
fold.cpp.explicit.anywhere=1
fold.cpp.explicit.end=-- }
fold.cpp.explicit.start=-- (FB){

[settings]
extension=lua
mime_type=text/x-lua
comment_single=--
comment_open=--[[
comment_close=]]--
comment_use_indent=true
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=
FT_00_CM=
FT_00_WD=
FT_01_LB=
FT_01_CM=
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=lua "%d/%f"
EX_00_WD=
error_regex=^([^:]+):([0-9]+):([0-9:]+)?.*$
