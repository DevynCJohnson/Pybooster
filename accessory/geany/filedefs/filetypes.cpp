[keywords]
docComment=a addindex addtogroup anchor arg attention author authors b brief bug c callergraph callgraph category cite class code cond copybrief copydetails copydoc copyright date def defgroup deprecated details dir dontinclude dot dotfile e else elseif em endcode endcond enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endrtfonly endverbatim endxmlonly enum example exception extends file fn headerfile hideinitializer htmlinclude htmlonly if ifnot image implements include includelineno ingroup interface internal invariant latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] post pre private privatesection property protected protectedsection protocol public publicsection ref related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa section see short showinitializer since skip skipline snippet struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version warning weakgroup xmlonly xrefitem
primary=alignas alignof and and_eq asm auto bitand bitor bool break case catch char char16_t char32_t class compl const const_cast constexpr continue decltype default delete do double dynamic_cast else enum explicit export extern false final float for friend goto if inline int long mutable namespace new noexcept not not_eq nullptr operator or or_eq override private protected public register reinterpret_cast return short signed sizeof static static_assert static_cast struct switch template this thread_local throw true try typedef typeid typename union unsigned using virtual void volatile wchar_t while xor xor_eq
secondary=asm bool break case catch char char16_t char32_t compl const_cast constexpr continue default delete do double dynamic_cast else final float for goto if int int16_t int32_t int64_t int8_t long new noexcept operator override private protected ptrdiff_t public reinterpret_cast return short signed size_t sizeof static_cast switch this thread_local throw try typeid unsigned void wchar_t while

[lexer_properties]
styling.within.preprocessor=1
lexer.cpp.track.preprocessor=1
lexer.cpp.update.preprocessor=1
preprocessor.symbol.$(file.patterns.cpp)=#
preprocessor.start.$(file.patterns.cpp)=if ifdef ifndef
preprocessor.middle.$(file.patterns.cpp)=else elif
preprocessor.end.$(file.patterns.cpp)=endif

[settings]
lexer_filetype=C
extension=cpp
mime_type=text/x-c++src
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
FT_00_CM=g++ -O2 -Wall -c "%d/%f"
FT_00_WD=
FT_01_LB=_Build
FT_01_CM=g++ -Wall -o "%d/%e" "%d/%f"
FT_01_WD=
FT_02_LB=_Lint
FT_02_CM=cppcheck --language=c++ --enable=warning,style --template=gcc "%d/%f"
FT_02_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%e"
EX_00_WD=
FT_03_LB=cppcheck
FT_03_CM=cppcheck -I. -v --language=c++ --std=c11 --std=posix --enable=all --template=gcc --inconclusive "%d/%f"
FT_03_WD=
FT_04_LB=Splint
FT_04_CM=splint -I. -hints -checks "%d/%f"
FT_04_WD=
