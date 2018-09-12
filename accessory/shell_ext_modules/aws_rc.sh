#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Shell RC script providing aliases for various AWS commands
# @file aws_rc.sh
# @version 2018.09.11
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


if [ -x "$(command -v aws)" ]; then


alias awstime='sudo ntpdate 0.amazon.pool.ntp.org; sudo ntpdate 0.amazon.pool.ntp.org; sudo hwclock -w'


# AWS BATCH #


alias bat_desc_compenv='aws batch describe-compute-environments'
alias bat_desc_jq='aws batch describe-job-queues'
alias bat_disable_compenv='aws batch update-compute-environment --state DISABLED --compute-environment'
alias bat_disable_jq='aws batch update-job-queue --state DISABLE --job-queue'
alias bat_enable_compenv='aws batch update-compute-environment --state ENABLED --compute-environment'
alias bat_enable_jq='aws batch update-job-queue --state ENABLE --job-queue'
alias bat_lscompenv='aws batch describe-compute-environments | grep computeEnvironmentName'
alias bat_lsjobs='aws batch list-jobs'  # Lists running jobs
alias bat_lsjq='aws batch describe-job-queues | grep jobQueueName'
alias bat_mkcompenv='aws batch create-compute-environment --cli-input-json'
alias bat_mkjob='aws batch submit-job --cli-input-json'
alias bat_mkjobdef='aws batch register-job-definition --cli-input-json'
alias bat_mkjq='aws batch create-job-queue --cli-input-json'
alias bat_rmcompenv='aws batch delete-compute-environment --compute-environment'
alias bat_rmjq='aws batch delete-job-queue --job-queue'


# AWS DATAPIPELINE #


alias dpl_act_pipe='aws datapipeline activate-pipeline --pipeline-id'
alias dpl_deact_pipe='aws datapipeline deactivate-pipeline --no-cancel-active --pipeline-id'
alias dpl_deact_pipe_now='aws datapipeline deactivate-pipeline --pipeline-id'
alias dpl_desc='aws datapipeline describe-pipelines --pipeline-ids'
alias dpl_ls='aws datapipeline list-pipelines'
alias dpl_lsruns='aws datapipeline list-runs --pipeline-id'
alias dpl_prog='aws datapipeline report-task-progress --task-id'


# AWS EC2 #


alias ec2_desc='aws ec2 describe-instances'
alias ec2_desc_addr='aws ec2 describe-addresses'
alias ec2_desc_gpu='aws ec2 describe-elastic-gpus'
alias ec2_desc_hosts='aws ec2 describe-hosts'
alias ec2_desc_nics='aws ec2 describe-network-interfaces'
alias ec2_desc_regions='aws ec2 describe-regions'
alias ec2_desc_rtab='aws ec2 describe-route-tables'


# AWS ECR #


alias ecr_desc_repo='aws ecr describe-repositories --no-paginate'
alias ecr_getlogin='$(aws ecr get-login --no-include-email)'  # Get and execute Docker login code
alias ecr_mkrepo='aws ecr create-repository --repository-name'
alias ecr_rmrepo='aws ecr delete-repository --repository-name'


# AWS ECS #


alias ecs_desc_clust='aws ecs describe-clusters'
alias ecs_ls_clust='aws ecs list-clusters --no-paginate'
alias ecs_ls_con='aws ecs list-container-instances --no-paginate'
alias ecs_ls_srv='aws ecs list-services --no-paginate'
alias ecs_ls_tasks='aws ecs list-tasks --no-paginate'
alias ecs_ls_taskdef='aws ecs list-task-definitions --no-paginate'
alias ecs_ls_taskdeffam='aws ecs list-task-definition-families --no-paginate'


# AWS IAM #


alias iam_act_auth='aws iam get-account-authorization-details'
alias iam_act_pswd_policy='aws iam get-account-password-policy'
alias iam_actsmry='aws iam get-account-summary'
alias iam_lsgrps='aws iam list-groups'
alias iam_lsroles='aws iam list-roles'
alias iam_lskeys='aws iam list-access-keys'


# AWS S3 #


alias s3cp='aws s3 cp'  # Copy file
alias s3ls='aws s3 ls'  # List files
alias s3rm='aws s3 rm'  # Remove file
alias s3mv='aws s3 mv'  # Move file
alias s3mb='aws s3 mb'  # Make S3 bucket
alias s3rb='aws s3 rb'  # Remove S3 bucket


fi
