[keywords]
package=F FALSE Inf letters LETTERS month.abb month.name NA NA_character_ NA_complex_ NA_integer_ NA_real_ NaN NULL pi T TRUE
package_other=clusterApply clusterApplyLB clusterCall clusterEvalQ clusterExport clusterMap clusterSetRNGStream clusterSplit detectCores makeCluster makeForkCluster makePSOCKcluster mc.reset.stream mcaffinity mccollect mclapply mcMap mcmapply mcparallel nextRNGStream nextRNGSubStream parApply parCapply parLapply parLapplyLB parRapply parSapply parSapplyLB pvec setDefaultCluster splitIndices stopCluster
primary=abs attach break ceiling cos cut dbinom detach diff dnorm dpois dunif else exp floor for function grep if in library log log10 max mean median min new next paste pbinom pnorm ppois punif qbinom qpois quantile qunif range rbinom rep repeat require return rnorm round rpois runif scale sd seq setClass setGeneric setGroupGeneric setMethod setRefClass signf sin source sqrt stop strsplit sub substr sum switch tan tolower toupper trunc try tryCatch warning while

[settings]
extension=R
comment_single=#
comment_use_indent=false
context_action_cmd=

[indentation]
type=1
width=2

[build-menu]
FT_00_LB=
FT_00_CM=
FT_00_WD=
FT_01_LB=
FT_01_CM=
FT_01_WD=
EX_00_LB=_Execute
EX_00_CM=Rscript "%d/%e"
EX_00_WD=
EX_01_LB=Execute (_Verbose)
EX_01_CM=R --quiet --no-restore --no-save < "%d/%e"
EX_01_WD=

#package_dump <- function(name, file = NA) {
#    if(is.na(file)) { file <- paste(name, "dump", sep = ".") }
#    cat(ls(paste("package", name, sep = ":")), file = file)
#}
