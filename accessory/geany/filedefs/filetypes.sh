[keywords]
primary=break case continue do done elif else esac eval exec exit export fi for function goto if in integer printf readonly return set shift then until while

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
FT_00_LB=ShellCheck
FT_00_CM=sh -n "%d/%f"
FT_00_WD=
FT_02_LB=
FT_02_CM=$file"
FT_02_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%f"
EX_00_WD=
FT_01_LB=ShAnalysis
FT_01_CM=shanalysis "%d/%f"
FT_01_WD=
EX_01_LB=Run Debugging
EX_01_CM=sh -vx "%d/%f"
EX_01_WD=
FT_03_LB=
FT_03_CM=
FT_03_WD=
