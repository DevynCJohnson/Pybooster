[keywords]
primary=__DATA__ __END__ __FILE__ __LINE__ __PACKAGE__ __SUB__ abs accept alarm and atan2 AUTOLOAD BEGIN bind binmode bless caller chdir CHECK chmod chomp chop chown chr chroot close closedir cmp connect continue CORE cos crypt dbmclose dbmopen default defined delete DESTROY die do dump each else elsif END endgrent endhostent endnetent endprotoent endpwent endservent eof eq EQ eval exec exists exit exp fcntl fileno flock for foreach fork format formline ge GE getc getgrent getgrgid getgrnam gethostbyaddr gethostbyname gethostent getlogin getnetbyaddr getnetbyname getnetent getpeername getpgrp getppid getpriority getprotobyname getprotobynumber getprotoent getpwent getpwnam getpwuid getservbyname getservbyport getservent getsockname getsockopt given glob gmtime goto grep gt GT hex if index INIT int ioctl join keys kill last lc lcfirst LE le length link listen local localtime lock log lstat lt LT m map mkdir msgctl msgget msgrcv msgsnd my ne NE next no not NULL oct open opendir or ord our pack package pipe pop pos print printf prototype push q qq qr qu quotemeta qw qx rand read readdir readline readlink readpipe recv redo ref rename require reset return reverse rewinddir rindex rmdir s say scalar seek seekdir select semctl semget semop send setgrent sethostent setnetent setpgrp setpriority setprotoent setpwent setservent setsockopt shift shmctl shmget shmread shmwrite shutdown sin sleep socket socketpair sort splice split sprintf sqrt srand stat state study sub substr symlink syscall sysopen sysread sysseek system syswrite tell telldir tie tied time times tr truncate uc ucfirst umask undef unless unlink unpack unshift untie until use utime values vec wait waitpid wantarray warn when while write x xor y

[lexer_properties]
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
EX_00_CM=perl "%d/%e"
EX_00_WD=
