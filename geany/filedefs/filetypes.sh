[keywords]
primary=alias break case continue do done elif else esac eval exec exit export fi for function goto if in integer printf readonly return set shift then until while

[lexer_properties]
fold.compact=0

[settings]
extension=sh
mime_type=application/x-shellscript
comment_single=#
comment_use_indent=true
context_action_cmd=

[indentation]
type=0
width=4

[build-menu]
FT_00_LB=_ShellCheck
FT_00_CM=sh -n "%d/%f"
FT_00_WD=
FT_02_LB=
FT_02_CM=
FT_02_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%f"
EX_00_WD=
FT_01_LB=Sh_Analysis
FT_01_CM=shanalysis "%d/%f"
FT_01_WD=
EX_01_LB=Run _Debugging
EX_01_CM=sh -v -x "%d/%f"
EX_01_WD=
FT_03_LB=
FT_03_CM=
FT_03_WD=
error_regex=
