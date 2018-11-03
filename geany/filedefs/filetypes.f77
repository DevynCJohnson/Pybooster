[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=access action advance allocatable allocate apostrophe assign assignment associate asynchronous backspace bind blank blockdata call case character class close common complex contains continue cycle data deallocate decimal default delim dimension direct do double doubleprecision dowhile else elseif elsewhere encoding end endassociate endblockdata enddo endfile endforall endfunction endif endinterface endmodule endprogram endselect endsubroutine endtype endwhere entry eor equivalence err errmsg exist exit external file flush fmt form format formatted function go goto id if implicit in include inout inquire integer intent interface intrinsic iolength iomsg iostat kind len logical module name named namelist nextrec nml none nullify number only open opened operator optional out pad parameter pass pause pending pointer pos position precision print private program protected public quote read readwrite real rec recl recursive result return rewind save select selectcase selecttype sequential sign size stat status stop stream subroutine target then to type unformatted unit use value volatile wait where while write
intrinsic_functions=abs achar acos acosd action adjustl adjustr aimag aimax0 aimin0 aint ajmax0 ajmin0 akmax0 akmin0 all allocated alog alog10 amax0 amax1 amin0 amin1 amod anint any append asin asind asis associated atan atan2 atan2d atand bit_size bitest bitl bitlr bitrl bjtest bktest break btest cabs call ccos ceiling cexp char clog cmplx conjg cos cosd cosh count cpu_time cshift csin csqrt dabs dacos dacosd dasin dasind datan datan2 datan2d datand date date_and_time dble dcos dcosd dcosh ddim dexp dfloat dfloti dflotj dflotk digits dim dint dlog dlog10 dmax1 dmin1 dmod dnint dot_product dprod dsign dsin dsind dsinh dsqrt dtan dtand dtanh elemental eor eoshift epsilon errsns exp exponent float floati floatj floatk floor fmt form fraction free huge iabs iachar iand ibclr ibits ibset ichar idate idim idint idnint ieor ifix iiabs iiand iibclr iibits iibset iidim iidint iidnnt iieor iifix iint iior iiqint iiqnnt iishft iishftc iisign ilen imax0 imax1 imin0 imin1 imod include index inint inot int ior iqint iqnint ishft ishftc isign isnan izext jiand jibclr jibits jibset jidim jidint jidnnt jieor jifix jint jior jiqint jiqnnt jishft jishftc jisign jmax0 jmax1 jmin0 jmin1 jmod jnint jnot jzext kiabs kiand kibclr kibits kibset kidim kidint kidnnt kieor kifix kint kior kishft kishftc kisign kmax0 kmax1 kmin0 kmin1 kmod knint knot kzext lbound leadz len_trim lge lgt lle llt log log10 lshift malloc matmul max max0 max1 maxexponent maxloc maxval merge min min0 min1 minexponent minloc minval mod modulo mvbits nearest nint not null number_of_processors nworkers pack popcnt poppar present product pure radix random random_number random_seed range repeat replace reshape rrspacing rshift scale scan secnds selected_int_kind selected_real_kind sequence set_exponent shape sin sind sinh sizeof sngl snglq spacing spread sqrt sum system_clock tan tand tanh tiny transfer transpose trim ubound unpack verify write yes
user_functions=cdabs cdcos cdexp cdlog cdsin cdsqrt cotan cotand dcmplx dconjg dcotan dcotand decode dimag dll_export dll_import doublecomplex dreal dvchk encode find flen getarg getcharqq getcl getdat getenv gettim hfix ibchng identifier imag int1 int2 int4 int8 intc intrup invalop iostat_msg isha ishc ishl jfix lacfar locking locnear map nargs nbreak ndperr ndpexc offset ovefl peekcharqq precfill prompt qabs qacos qacosd qasin qasind qatan qatan2 qatand qcmplx qconjg qcos qcosd qcosh qdim qexp qext qextd qfloat qimag qlog qlog10 qmax1 qmin1 qmod qreal qsign qsin qsind qsinh qsqrt qtan qtand qtanh ran rand randu rewrite segment setdat settim system timer undfl unlock val virtual zabs zcos zexp zlog zsin zsqrt

[lexer_properties]
fold.compact=0

[settings]
extension=f
mime_type=text/x-fortran
comment_single=c
comment_use_indent=false
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_Compile
FT_00_CM=gfortran -Wall -c "%d/%f"
FT_00_WD=
FT_01_LB=_Linker
FT_01_CM=gfortran -Wall -o "%d/%e" "%d/%f"
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM="%d/%e"
EX_00_WD=
error_regex=
