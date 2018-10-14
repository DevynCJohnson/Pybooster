[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
primary=__DATA__ __END__ __FILE__ __LINE__ __PACKAGE__ __SUB__ abs accept alarm and atan2 AUTOLOAD BEGIN bind binmode bless caller chdir CHECK chmod chomp chop chown chr chroot close closedir cmp connect continue CORE cos crypt dbmclose dbmopen default defined delete DESTROY die do dump each else elsif END endgrent endhostent endnetent endprotoent endpwent endservent eof eq EQ eval exec exists exit exp fcntl fileno flock for foreach fork format formline ge GE getc getgrent getgrgid getgrnam gethostbyaddr gethostbyname gethostent getlogin getnetbyaddr getnetbyname getnetent getpeername getpgrp getppid getpriority getprotobyname getprotobynumber getprotoent getpwent getpwnam getpwuid getservbyname getservbyport getservent getsockname getsockopt given glob gmtime goto grep gt GT hex if index INIT int ioctl join keys kill last lc lcfirst LE le length link listen local localtime lock log lstat lt LT m map mkdir msgctl msgget msgrcv msgsnd my ne NE next no not NULL oct open opendir or ord our pack package pipe pop pos print printf prototype push q qq qr qu quotemeta qw qx rand read readdir readline readlink readpipe recv redo ref rename require reset return reverse rewinddir rindex rmdir s say scalar seek seekdir select semctl semget semop send setgrent sethostent setnetent setpgrp setpriority setprotoent setpwent setservent setsockopt shift shmctl shmget shmread shmwrite shutdown sin sleep socket socketpair sort splice split sprintf sqrt srand stat state study sub substr symlink syscall sysopen sysread sysseek system syswrite tell telldir tie tied time times tr truncate uc ucfirst umask undef unless unlink unpack unshift untie until use utime values vec wait waitpid wantarray warn when while write x xor y

[lexer_properties]
fold.perl.at.else=1
fold.perl.comment.explicit=1
fold.perl.package=1
fold.perl.pod=1
styling.within.preprocessor=1

[settings]
extension=pl
mime_type=application/x-perl
comment_single=#
comment_use_indent=true
context_action_cmd=

[indentation]
type=1
width=4

[build-menu]
FT_00_LB=_PerlCC
FT_00_CM=perlcc -o "%d/%e" "%d/%f"
FT_00_WD=
FT_01_LB=
FT_01_CM=
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=perl "%d/%f"
EX_00_WD=
error_regex=.+ at (.+) line ([0-9]+).*
