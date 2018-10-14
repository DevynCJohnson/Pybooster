[keywords]
docComment=a addindex addtogroup anchor annotatedclasslist arg attention author authors b brief bug c callergraph callgraph category cite class classhierarchy code cond copybrief copydetails copydoc copyright date def defgroup define deprecated details diafile dir docbookonly dontinclude dot dotfile e else elseif em endcode endcond enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly endsecreflist enduml endverbatim endxmlonly enum example exception extends ff[ f] file fn functionindex f{ f} header headerfile headerfilelist hidecallergraph hidecallgraph hideinitializer htmlinclude htmlonly idlexcept if ifnot image implements include includedoc includelineno ingroup inherit interface internal invariant l latexinclude latexonly li license line link mainpage manonly memberof msc mscfile n name namespace nosubgrouping note overload p package page par paragraph param param[in] parblock post postheader pre private privatesection property protected protectedsection protocol public publicsection pure ref refitem related relatedalso relates relatesalso remark remarks result return returns retval rtfonly sa secreflist section see short showinitializer since skip skipline snippet snippetdoc snippetlineno startuml static struct subpage subsection subsubsection tableofcontents test throw throws todo tparam typedef union until var verbatim verbinclude version vhdlflow warning weakgroup xmlonly xrefitem
package=F FALSE Inf letters LETTERS month.abb month.name NA NA_character_ NA_complex_ NA_integer_ NA_real_ NaN NULL pi T TRUE
package_other=clusterApply clusterApplyLB clusterCall clusterEvalQ clusterExport clusterMap clusterSetRNGStream clusterSplit detectCores makeCluster makeForkCluster makePSOCKcluster mc.reset.stream mcaffinity mccollect mclapply mcMap mcmapply mcparallel nextRNGStream nextRNGSubStream parApply parCapply parLapply parLapplyLB parRapply parSapply parSapplyLB pvec setDefaultCluster splitIndices stopCluster
primary=abs all all.equal all.names all.vars any anyDuplicated anyMissing anyNA anyNA.numeric_version anyNA.POSIXlt as.call as.character as.complex as.double as.formula as.integer as.logical as.name as.null as.raw as.symbol as.vector asS3 asS4 assertCondition attach break c call cbind ceiling colnames complete.cases cos cut dbinom deparse detach diff dim dimnames dir.create dir.exists dnorm do.call dpois dunif else eval evalq exp file.exists floor for formula function getRversion glm grep gsub if in is.array is.call is.language is.matrix is.na is.nan is.null is.numeric is.object is.symbol isS4 lapply length levels library list lm local log log10 matrix max mean median message min mode na.action na.fail na.omit names ncol new next nrow numeric_version package_version parse paste paste0 pbinom pnorm ppois punif qbinom qpois quantile quit qunif R_system_version range rbind rbinom Recall rep repeat require return rnorm round rpois runif sapply scale sd seq seq.int setClass setGeneric setGroupGeneric setMethod setRefClass signf sin source sqrt stop stopifnot storage.mode strsplit sub substitute substr sum switch tan tolower toupper trunc try tryCatch typeof unlist warning which while write.csv xtfrm

[lexer_properties]
fold.at.else=1
fold.compact=0

[settings]
extension=R
comment_single=#
comment_use_indent=false
context_action_cmd=
whitespace_chars=\s\t!\"#$%&'()*+,-/:;<=>?@[\\]^`{|}~
wordchars=._abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789

[indentation]
type=1
width=2

[build-menu]
FT_00_LB=_Compile
FT_00_CM=RCompiler.R "%d/%f"
FT_00_WD=
FT_01_LB=
FT_01_CM=
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=Rscript "%d/%f"
EX_00_WD=
EX_01_LB=Execute (_Verbose)
EX_01_CM=R --quiet --no-restore --no-save < "%d/%f"
EX_01_WD=
EX_02_LB=E_xecute
EX_02_CM=Rexe "%d/%e.Rc"
EX_02_WD=
error_regex=
