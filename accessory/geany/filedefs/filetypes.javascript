[keywords]
primary=abs abstract acos anchor asin async atan atan2 await big bold boolean break byte case catch ceil char charAt charCodeAt class concat const continue cos Date debugger default delete do double each else enum escape exp export extends false final finally fixed float floor fontcolor fontsize for fromCharCode function get goto if implements import in indexOf Infinity instanceof int interface italics join lastIndexOf length let link log long max MAX_VALUE min MIN_VALUE NaN native NEGATIVE_INFINITY new null package pop POSITIVE_INFINITY pow private protected prototype public push random return return reverse round set shift short sin slice small sort splice split sqrt static static strike string String sub substr substring sup super switch synchronized tan this throw throws toLowerCase toString toUpperCase transient true try typeof undefined unescape unshift valueOf var void volatile while with yield
secondary=Array Boolean constructor Date decodeURI decodeURIComponent encodeURI encodeURIComponent Error eval EvalError Function isFinite isNaN Math Number Object parseFloat parseInt prototype RangeError ReferenceError RegExp String SyntaxError TypeError URIError

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
FT_02_LB=_Lint
FT_02_CM=jshint "%f"
FT_02_WD=
error_regex=([^:]+): line ([0-9]+), col ([0-9]+)
