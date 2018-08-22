[keywords]
coroutines=appendto clock closefile coroutine.create coroutine.resume coroutine.running coroutine.status coroutine.wrap coroutine.yield date difftime execute exit flush getenv io.close io.flush io.input io.lines io.open io.output io.popen io.read io.stderr io.stdin io.stdout io.tmpfile io.type io.write openfile os.clock os.date os.difftime os.execute os.exit os.getenv os.remove os.rename os.setlocale os.time os.tmpname package.cpath package.loaded package.loadlib package.path package.preload package.seeall read readfrom remove rename seek setlocale time tmpfile tmpname write writeto
function_basic=_ALERT _ERRORMESSAGE _G _INPUT _OUTPUT _PROMPT _STDERR _STDIN _STDOUT _VERSION assert call collectgarbage coroutine debug dofile dostring error foreach foreachi gcinfo getfenv getmetatable getn globals io ipairs load loadfile loadlib loadstring math module newtype next os pairs pcall print rawequal rawget rawset require select setfenv setmetatable sort string table tinsert tonumber tostring tremove type unpack xpcall
function_other=abs acos asin atan atan2 ceil cos deg exp floor format frexp gsub ldexp log log10 math.abs math.acos math.asin math.atan math.atan2 math.ceil math.cos math.cosh math.deg math.exp math.floor math.fmod math.frexp math.huge math.ldexp math.log math.log10 math.max math.min math.mod math.modf math.pi math.pow math.rad math.random math.randomseed math.sin math.sinh math.sqrt math.tan math.tanh max min mod rad random randomseed sin sqrt strbyte strchar strfind string.byte string.char string.dump string.find string.format string.gfind string.gmatch string.gsub string.len string.lower string.match string.rep string.reverse string.sub string.upper strlen strlower strrep strsub strupper table.concat table.foreach table.foreachi table.getn table.insert table.maxn table.remove table.setn table.sort tan
keywords=and break do else elseif end false for function if in local nil not or repeat return then true until while
user1=
user2=
user3=
user4=

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

[build_settings]
compiler=
run_cmd=lua "%f"