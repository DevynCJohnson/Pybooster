#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing aliases for various AWS commands
#' @file aws_rc.sh
#' @version 2018.12.28
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -x "$(command -v aws)" ]; then


#' Synchronize the system's time with Amazon's NTP server
alias awstime='sudo ntpdate 0.amazon.pool.ntp.org; sudo ntpdate 0.amazon.pool.ntp.org; sudo hwclock -w'


# AWS BATCH #


alias bat_desc_compenv='aws batch describe-compute-environments'
alias bat_desc_job='aws batch describe-jobs --jobs'
alias bat_desc_jobdef='aws batch describe-job-definitions'
alias bat_desc_jobdef_active='aws batch describe-job-definitions --status ACTIVE'
alias bat_desc_jobdef_inactive='aws batch describe-job-definitions --status INACTIVE'
alias bat_desc_jobq='aws batch describe-job-queues'
alias bat_disable_compenv='aws batch update-compute-environment --state DISABLED --compute-environment'
alias bat_disable_jq='aws batch update-job-queue --state DISABLE --job-queue'
alias bat_enable_compenv='aws batch update-compute-environment --state ENABLED --compute-environment'
alias bat_enable_jq='aws batch update-job-queue --state ENABLE --job-queue'
alias bat_jobdef='aws batch describe-job-definitions --job-definitions'
alias bat_mkcompenv='aws batch create-compute-environment --cli-input-json'
alias bat_mkjob='aws batch submit-job --cli-input-json'
alias bat_mkjobdef='aws batch register-job-definition --cli-input-json'
alias bat_mkjobq='aws batch create-job-queue --cli-input-json'
alias bat_rmcompenv='aws batch delete-compute-environment --compute-environment'
alias bat_rmjobq='aws batch delete-job-queue --job-queue'
alias bat_watch_job='watch -n 10 aws batch describe-jobs --jobs'  #' Continually watch the status of the specified BATCH job (by Job ID)


#' List the compute environments in BATCH
bat_lscompenv() {
    aws batch describe-compute-environments --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"ComputeEnvironment /, "", $0); gsub(/"computeEnvironmentName":/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | sort -d -f
}


#' List the ECS Cluster ARNs used in the compute environments in BATCH
bat_lsecsarn() {
    aws batch describe-compute-environments --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"ecsClusterArn"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | grep -F 'arn:' | sort -d -f
}


#' List the names of the BATCH JobDefinitions
bat_lsjobdef() {
    aws batch describe-job-definitions --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"jobDefinitionName"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | sort -d -f | uniq
}


#' List the names of the BATCH Job Queues
bat_lsjobq() {
    aws batch describe-job-queues --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"statusReason": "JobQueue /, "", $0); gsub(/"jobQueueName"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | sort -d -f
}


#' List the jobs in the specified queue by job status
#' @param[in] $1 Job-Queue name
bat_lsjobs() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        printf '%s\n' '----- SUBMITTED -----'
        bat_lsjobs_submitted "${1}"
        printf '\n%s\n' '----- PENDING -----'
        bat_lsjobs_pending "${1}"
        printf '\n%s\n' '----- RUNNABLE -----'
        bat_lsjobs_runnable "${1}"
        printf '\n%s\n' '----- STARTING -----'
        bat_lsjobs_starting "${1}"
        printf '\n%s\n' '----- RUNNING -----'
        bat_lsjobs_running "${1}"
        printf '\n%s\n' '----- SUCCEEDED -----'
        bat_lsjobs_succeeded "${1}"
        printf '\n%s\n' '----- FAILED -----'
        bat_lsjobs_failed "${1}"
    fi
}


#' List all the jobs in all the job-queues
bat_lsalljobs() {
    jobq_list="$(bat_lsjobq)"
    for jobq in ${jobq_list}; do
        if [ -z "${jobq:-}" ]; then
            printf 'ERROR: Missing or faulty repository name!\n' >&2
            break
        fi
        printf '\n======= %s =======\n\n\n' "${jobq}"
        bat_lsjobs "${jobq}"
        printf '\n'
    done
}


#' List the SUBMITTED jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_submitted() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status SUBMITTED --job-queue "${1}" --no-paginate
    fi
}


#' List the PENDING jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_pending() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status PENDING --job-queue "${1}" --no-paginate
    fi
}


#' List the RUNNABLE jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_runnable() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status RUNNABLE --job-queue "${1}" --no-paginate
    fi
}


#' List the STARTING jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_starting() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status STARTING --job-queue "${1}" --no-paginate
    fi
}


#' List the RUNNING jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_running() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status RUNNING --job-queue "${1}" --no-paginate
    fi
}


#' List the SUCCEEDED jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_succeeded() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status SUCCEEDED --job-queue "${1}" --no-paginate
    fi
}


#' List the FAILED jobs in the specified queue
#' @param[in] $1 Job-Queue name
bat_lsjobs_failed() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (job-queue name)!\n' >&2
    else
        aws batch list-jobs --job-status FAILED --job-queue "${1}" --no-paginate
    fi
}


#' List the names of the BATCH Job Queues with the compute environment ARN
bat_lsjobqcomparn() {
    aws batch describe-job-queues --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"statusReason": "JobQueue /, "", $0); gsub(/"jobQueueName"/, "_ _", $0); gsub(/"computeEnvironment"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | paste -d ' ' - - | sort -d -f
}


# AWS DATAPIPELINE #


alias dpl_act_pipe='aws datapipeline activate-pipeline --pipeline-id'
alias dpl_deact_pipe='aws datapipeline deactivate-pipeline --no-cancel-active --pipeline-id'
alias dpl_deact_pipe_now='aws datapipeline deactivate-pipeline --pipeline-id'
alias dpl_desc='aws datapipeline describe-pipelines --pipeline-ids'
alias dpl_ls='aws datapipeline list-pipelines'
alias dpl_lsruns='aws datapipeline list-runs --pipeline-id'
alias dpl_prog='aws datapipeline report-task-progress --task-id'


# AWS EC2 #


alias ec2_con='aws ec2 get-console-output --instance-id'  #' Get the consoole output of the specified EC2 instance
alias ec2_desc='aws ec2 describe-instances'
alias ec2_desc_addr='aws ec2 describe-addresses'
alias ec2_desc_gpu='aws ec2 describe-elastic-gpus'
alias ec2_desc_hosts='aws ec2 describe-hosts'
alias ec2_desc_nics='aws ec2 describe-network-interfaces'
alias ec2_desc_regions='aws ec2 describe-regions'
alias ec2_desc_rtab='aws ec2 describe-route-tables'
alias ec2_lsimg_available='aws ec2 describe-images --no-paginate --filters=Name=state,Values=available'
alias ec2_lsimg_failed='aws ec2 describe-images --no-paginate --filters=Name=state,Values=failed'
alias ec2_lsimg_hvm='aws ec2 describe-images --no-paginate --filters=Name=virtualization-type,Values=hvm'
alias ec2_lsimg_kernel='aws ec2 describe-images --no-paginate --filters=Name=image-type,Values=kernel'
alias ec2_lsimg_machine='aws ec2 describe-images --no-paginate --filters=Name=image-type,Values=machine'
alias ec2_lsimg_oem='aws ec2 describe-images --no-paginate --filters=Name=hypervisor,Values=oem'
alias ec2_lsimg_paravirtual='aws ec2 describe-images --no-paginate --filters=Name=virtualization-type,Values=paravirtual'
alias ec2_lsimg_pending='aws ec2 describe-images --no-paginate --filters=Name=state,Values=pending'
alias ec2_lsimg_ramdisk='aws ec2 describe-images --no-paginate --filters=Name=image-type,Values=ramdisk'
alias ec2_lsimg_xen='aws ec2 describe-images --no-paginate --filters=Name=hypervisor,Values=xen'


#' Return information (in JSON format) about the specified instance (by ID)
ec2_inst_info() {
    aws ec2 describe-instances --filters=Name=instance-id,Values="${1:-}" --no-paginate
}


#' Return the instance type of the specified instance (by ID)
ec2_inst_type() {
    aws ec2 describe-instances --filters=Name=instance-id,Values="${1:-}" --no-paginate | grep 'InstanceType'
}


#' Return all EC2 instances that have a tag equal to the given value
ec2_tagsbyvalue() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: Specify a tag!\n' >&2
    else
        aws ec2 describe-tags --filters=Name=key,Values="${1}"
    fi
}


# AWS ECR #


alias ecr_desc_repos='aws ecr describe-repositories --no-paginate'  #' Provide information on all of the ECR repositories (in JSON format)
alias ecr_getlogin='$(aws ecr get-login --no-include-email)'  #' Get and execute Docker login code
alias ecr_mkrepo='aws ecr create-repository --repository-name'  #' Create a new ECS repository


#' List the ECR repositories
ecr_lsrepos() {
    aws ecr describe-repositories --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/"repositoryName"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | sort -d -f
}


#' List the digests and tags of all the Docker images in the specified ECR repository
#' @param[in] $1 Repository
ecr_lsimg() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (repository name)!\n' >&2
    else
        aws ecr list-images --repository-name "${1}" --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/[",]*/, "", $2); print $2; } }'
    fi
}


#' For the specified ECR repository, retrieve and return the image manifest of a Docker image (specified by the tag)
#' @section USAGE
#' ecr_imgmanifest REPOSITORY_NAME EXISTING_TAG NEW_TAG
#' @param[in] $1 Repository
#' @param[in] $2 Existing tag
ecr_imgmanifest() { aws ecr batch-get-image --repository-name "${1:-}" --image-ids imageTag="${2:-}" --query 'images[].imageManifest' --output text; }


#' List the digests and tags of all the Docker images in all of the ECR repositories
ecr_lsimgs() {
    repo_list="$(ecr_lsrepos)"
    for repo in ${repo_list}; do
        if [ -z "${repo:-}" ]; then
            printf 'ERROR: Missing or faulty repository name!\n' >&2
            break
        fi
        printf '%s\n' "${repo}"
        ecr_lsimg "${repo}"
    done
}


#' List the digests of all the untagged Docker images in the specified ECR repository
#' @param[in] $1 Repository
ecr_lsuntaggedimg() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (repository name)!\n' >&2
    else
        aws ecr list-images --filter='tagStatus=UNTAGGED' --repository-name "${1}" --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/[",]*/, "", $2); print $2; } }' | sort -d -f
    fi
}


#' List the digests of all the untagged Docker images in all the ECR repositories
ecr_lsuntaggedimgs() {
    repo_list="$(ecr_lsrepos)"
    for repo in ${repo_list}; do
        if [ -z "${repo:-}" ]; then
            printf 'ERROR: Missing or faulty repository name!\n' >&2
            break
        fi
        printf '%s\n' "${repo}"
        ecr_lsuntaggedimg "${repo}"
    done
}


#' List the digests and tags of all the tagged Docker images in the specified ECR repository
#' @param[in] $1 Repository
ecr_lstaggedimg() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (repository name)!\n' >&2
    else
        aws ecr list-images --filter='tagStatus=TAGGED' --repository-name "${1}" --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/[",]*/, "", $2); print $2; } }'
    fi
}


#' List the digests and tags of all the tagged Docker images in all the ECR repositories
ecr_lstaggedimgs() {
    repo_list="$(ecr_lsrepos)"
    for repo in ${repo_list}; do
        if [ -z "${repo:-}" ]; then
            printf 'ERROR: Missing or faulty repository name!\n' >&2
            break
        fi
        printf '%s\n' "${repo}"
        ecr_lstaggedimg "${repo}"
    done
}


#' Remove a Docker image from the given repository name and existing tag
#' @section USAGE
#' ecr_rmimg REPOSITORY_NAME EXISTING_TAG
#' @param[in] $1 Repository
#' @param[in] $2 Existing tag or image digest of the image to remove
ecr_rmimg() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Two parameters are required (repository name, existing tag)!\n' >&2
    elif [ "$(expr "${2}" : '.*')" != 71 ] && [ "$(expr "${2}" : '.*')" -ge 64 ]; then
        case "${2}" in
            # Correct digest prefix is present
            'sha256:'*) imgdigest="${2}";;
            # Missing digest prefix; it will be added
            *) imgdigest="sha256:${2}";;
        esac
        aws ecr batch-delete-image --repository-name "${1}" --image-ids imageDigest="${imgdigest}"
    else
        aws ecr batch-delete-image --repository-name "${1}" --image-ids imageTag="${2}"
    fi
}


#' Remove the specified ECR repository
#' @param[in] $1 Repository
ecr_rmrepo() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (repository name)!\n' >&2
    else
        aws ecr delete-repository --repository-name "${1}"
    fi
}


#' Apply an additional tag to the Docker image given the repository name, existing tag, and the new tag
#' @section USAGE
#' ecr_addtag REPOSITORY_NAME EXISTING_TAG NEW_TAG
#' @param[in] $1 Repository
#' @param[in] $2 Existing tag
#' @param[in] $3 New tag to append
ecr_addtag() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ]; then
        printf 'ERROR: Three parameters are required (repository name, existing tag, new tag)!\n' >&2
    else
        MANIFEST="$(aws ecr batch-get-image --repository-name "${1}" --image-ids imageTag="${2}" --query 'images[].imageManifest' --output text --no-paginate)"
        if [ -z "${MANIFEST:-}" ]; then
            printf 'ERROR: Failed to retrieve the manifest data of the image from the specified repository!\n' >&2
        else
            aws ecr put-image --repository-name "${1}" --image-tag "${3}" --image-manifest "${MANIFEST}" --no-paginate > /dev/null
        fi
    fi
}


#' Apply a tag to a tagless Docker image given the repository name, image digest, and the new tag (AWS & Docker login must be applied first)
#' @section USAGE
#' ecr_addtag2tagless REPOSITORY_NAME IMAGE_DIGEST NEW_TAG
#' @param[in] $1 Repository
#' @param[in] $2 Image digest (with or without prefix)
#' @param[in] $3 New tag to append
ecr_addtag2tagless() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ]; then
        printf 'ERROR: Three parameters are required (repository name, image digest, new tag)!\n' >&2
    else
        case "${2:-}" in
            # Correct digest prefix is present
            'sha256:'*) imgdigest="${2}";;
            # Missing digest prefix; it will be added
            *) imgdigest="sha256:${2}";;
        esac
        if [ "$(expr "${imgdigest}" : '.*')" != 71 ]; then
            printf 'ERROR: The given image digest has an invalid length!\n' >&2
        fi
        MANIFEST="$(aws ecr batch-get-image --repository-name "${1}" --image-ids imageDigest="${imgdigest}" --query 'images[].imageManifest' --output text)"
        if [ -z "${MANIFEST:-}" ]; then
            printf 'ERROR: Failed to retrieve the manifest data of the image from the specified repository!\n' >&2
        else
            aws ecr put-image --repository-name "${1}" --image-tag "${3}" --image-manifest "${MANIFEST}" > /dev/null
        fi
    fi
}


# AWS ECS #


alias ecs_desc_clust='aws ecs describe-clusters --clusters'
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


# AWS LAMBDA #


alias lamda_desc='aws lambda list-functions --no-paginate'
alias lamda_rm='aws lambda delete-function --function-name'


#' List the lamdas
lambda_ls() {
    aws lambda list-functions --no-paginate | awk '{ if (NF == 2 && NR > 2) { gsub(/"FunctionName"/, "_ _", $0); gsub(/[",]*/, "", $3); if ($3) { print $3; } } }' | sort -d -f
}


#' List the Lambda function's aliases
lambda_lsalias() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (Lambda function name)!\n' >&2
    else
        aws lambda list-aliases --function-name "${1}" --no-paginate | awk '{ if (NF >= 2 && NR > 2) { gsub(/[",]*/, "", $0); print $0; } }'
    fi
}


# AWS LOGS #


alias log_desc_grp='aws logs describe-log-groups --no-paginate'  #' Describe log group
alias log_desc_strm='aws logs describe-log-streams --no-paginate --log-group-name'  #' Describe log stream


# AWS S3 #


alias s3cp='aws s3 cp'  #' Copy file
alias s3rm='aws s3 rm'  #' Remove file
alias s3rmdir='aws s3 rm --recursive'  #' Remove directory and contents recursively
alias s3mv='aws s3 mv'  #' Move file
alias s3mvdir='aws s3 mv --recursive'  #' Move directory and contents recursively
alias s3mb='aws s3 mb'  #' Make S3 bucket
alias s3rb='aws s3 rb'  #' Remove S3 bucket
alias s3lsb='aws s3api list-buckets'  #' List AWS S3 buckets


#' Copy directory and contents recursively
#' @section USAGE
#' s3cpdir PATH_TO_COPY DESTINATION
#' @param[in] $1 Path to copy
#' @param[in] $2 Destination path
s3cpdir() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Two parameters are required (s3rename PATHNAME NEW_NAME)!\n' >&2
    else
        PATHNAME="${1}"
        DESTNAME="${2}"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${PATHNAME}/"
        [[ ! "$DESTNAME" =~ ^.+/$ ]] && DESTNAME="${DESTNAME}/"
        if [[ ! "$PATHNAME" =~ ^s3://.+$ ]] && [[ ! "$DESTNAME" =~ ^s3://.+$ ]]; then
            printf 'ERROR: An S3 URI is required (no "s3://" found)!\n' >&2
        else
            aws s3 cp --recursive "${PATHNAME}" "${DESTNAME}" > /dev/null
        fi
    fi
}


#' List files within the specified S3 directory path (emulates Unix's `ls` command)
#' @section USAGE
#' s3ls [PATHNAME]
#' @param[in] $1 S3 path without "s3:/"
s3ls() {
    if [ -n "${1:-}" ]; then
        PATHNAME="${1:-}"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${1}/"
        aws s3 ls "s3:/${PATHNAME}" | sed 's|^[ tab]*||; s|   | |g; s|  | |g; s|  | |g' | cut -d ' ' -f 4
    else
        aws s3 ls "s3://" | sed 's|^[ tab]*||; s|   | |g; s|  | |g; s|  | |g' | cut -d ' ' -f 4
    fi
}


#' List files within the specified S3 directory path (emulates Unix's `ls -l` command)
#' @section USAGE
#' s3ll [PATHNAME]
#' @param[in] $1 S3 path without "s3:/"
s3ll() {
    if [ -n "${1:-}" ]; then
        PATHNAME="${1}"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${1}/"
        aws s3 ls --human-readable --summarize "s3:/${PATHNAME}" | sed 's|^[ tab]*||'
    else
        aws s3 ls --human-readable --summarize "s3://" | sed 's|^[ tab]*||'
    fi
}


#' List files recursively within the specified S3 directory path (emulates Unix's `ls -R` command)
#' @section USAGE
#' s3lr [PATHNAME]
#' @param[in] $1 S3 path without "s3:/"
s3lr() {
    if [ -n "${1:-}" ]; then
        PATHNAME="${1}"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${1}/"
        aws s3 ls --recursive "s3:/${PATHNAME}" | sed 's|^[ tab]*||; s|   | |g; s|  | |g; s|  | |g' | cut -d ' ' -f 4
    else
        aws s3 ls --recursive "s3://" | sed 's|^[ tab]*||; s|   | |g; s|  | |g; s|  | |g' | cut -d ' ' -f 4
    fi
}


#' List files recursively within the specified S3 directory path (emulates Unix's `ls -l -R` command)
#' @section USAGE
#' s3llr [PATHNAME]
#' @param[in] $1 S3 path without "s3:/"
s3llr() {
    if [ -n "${1:-}" ]; then
        PATHNAME="${1}"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${1}/"
        aws s3 ls --recursive "s3:/${PATHNAME}" | sed 's|^[ tab]*||'
    else
        aws s3 ls --recursive "s3://" | sed 's|^[ tab]*||'
    fi
}


#' Rename a file at the listed S3 directory path to the specified name within the same directory
#' @section USAGE
#' s3rename PATHNAME NEW_NAME
#' @param[in] $1 S3 path without "s3:/"
#' @param[in] $2 new filename without path
s3rename() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Two parameters are required (s3rename PATHNAME NEW_NAME)!\n' >&2
    else
        PATHNAME="$(dirname "${1}")"
        [[ ! "$PATHNAME" =~ ^.+/$ ]] && PATHNAME="${1}/"
        aws s3 mv "s3:/${PATHNAME}" "${2}"
    fi
}


#' Upload to a S3 Bucket (after login in to AWS via command-line)
#' @section USAGE
#' upload2bucket BUCKET_PATH PATHNAME_TO_UPLOAD [NEW_FILENAME_IN_BUCKET]
#' @param[in] $1 Bucket name
#' @param[in] $2 Pathname to the file that will be uploaded
#' @param[in] $3 New name for the file that will be uploaded (Optional)
upload2bucket() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'At least two parameters are required!\n' >&2
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ]; then
        bucket_path="${1}"
        [[ ! "${1}" =~ ^.+/$ ]] && bucket_path+='/'
        aws s3 cp "${2}" "${bucket_path}${2##*/}"
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ] && [ ! -z "${3:-}" ]; then
        bucket_path="${1}"
        [[ ! "${1}" =~ ^.+/$ ]] && bucket_path+='/'
        aws s3 cp "${2}" "${bucket_path}${3}"
    fi
}


# AUTOCOMPLETE #


#' Refresh the auto-complete lists
aws_refresh() {
    AWS_JOB_QUEUES="$(bat_lsjobq)"
    AWS_ECR_REPOS="$(ecr_lsrepos)"
    AWS_LAMBDAS="$(lambda_ls)"
    export AWS_JOB_QUEUES
    export AWS_ECR_REPOS
    export AWS_LAMBDAS
}


if [ "$PROFILE_SHELL" = 'bash' ] && [ -n "${SHELL_IS_INTERACTIVE:-}" ] && [ -n "$(command -v mapfile)" ] && [ -n "$(command -v complete)" ]; then
    # Autocomplete AWS Job Queues
    if [ -n "$(command -v bat_lsjobq)" ]; then
        _jobq_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; echo "${AWS_JOB_QUEUES}" | awk "/^${2}/" > "$tmpfile"; mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _jobq_autocomplete)" ]; then
            complete -F _jobq_autocomplete -o nospace bat_lsjobs
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_failed
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_pending
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_runnable
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_running
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_starting
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_submitted
            complete -F _jobq_autocomplete -o nospace bat_lsjobs_succeeded
            readonly -f _jobq_autocomplete
        fi
    fi
    # Autocomplete AWS ECR Repositories
    if [ -n "$(command -v ecr_lsrepos)" ]; then
        _ecr_repo_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; echo "${AWS_ECR_REPOS}" | awk "/^${2}/" > "$tmpfile" && mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _ecr_repo_autocomplete)" ]; then
            [ -x "$(command -v docker)" ] && complete -F _ecr_repo_autocomplete -o nospace dock_buildpush
            complete -F _ecr_repo_autocomplete -o nospace ecr_addtag
            complete -F _ecr_repo_autocomplete -o nospace ecr_addtag2tagless
            complete -F _ecr_repo_autocomplete -o nospace ecr_imgmanifest
            complete -F _ecr_repo_autocomplete -o nospace ecr_lsimg
            complete -F _ecr_repo_autocomplete -o nospace ecr_lstaggedimg
            complete -F _ecr_repo_autocomplete -o nospace ecr_lsuntaggedimg
            complete -F _ecr_repo_autocomplete -o nospace ecr_rmimg
        fi
    fi
    # Autocomplete AWS Lambda Functions
    if [ -n "$(command -v ecr_lsrepos)" ]; then
        _lambda_autocomplete() { tmpfile="/tmp/$(rndfname).tmp"; echo "${AWS_LAMBDAS}" | awk "/^${2}/" > "$tmpfile" && mapfile -t COMPREPLY < "$tmpfile"; rm "$tmpfile"; }
        if [ -n "$(command -v _lambda_autocomplete)" ]; then
            complete -F _lambda_autocomplete -o nospace lamda_rm
        fi
    fi
fi


fi
