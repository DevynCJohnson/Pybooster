#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing aliases for various AWS commands
#' @file aws_rc.sh
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


if [ -x "$(command -v aws)" ]; then


#' Synchronize the system's time with Amazon's NTP server
alias awstime='sudo ntpdate 0.amazon.pool.ntp.org; sudo ntpdate 0.amazon.pool.ntp.org; sudo hwclock -w'


# AWS BATCH #


alias bat_desc_compenv='aws batch describe-compute-environments'
alias bat_desc_jq='aws batch describe-job-queues'
alias bat_disable_compenv='aws batch update-compute-environment --state DISABLED --compute-environment'
alias bat_disable_jq='aws batch update-job-queue --state DISABLE --job-queue'
alias bat_enable_compenv='aws batch update-compute-environment --state ENABLED --compute-environment'
alias bat_enable_jq='aws batch update-job-queue --state ENABLE --job-queue'
alias bat_lscompenv='aws batch describe-compute-environments | grep computeEnvironmentName'
alias bat_lsjobs='aws batch list-jobs'  #' Lists running jobs
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

#' Return information (in JSON format) about the specified instance (by ID)
ec2_inst_info() {
    aws ec2 describe-instances --filters=Name=instance-id,Values="${1:-}"
}

#' Return the instance type of the specified instance (by ID)
ec2_inst_type() {
    aws ec2 describe-instances --filters=Name=instance-id,Values="${1:-}" | grep 'InstanceType'
}


# AWS ECR #


alias ecr_desc_repo='aws ecr describe-repositories --no-paginate'
alias ecr_getlogin='$(aws ecr get-login --no-include-email)'  #' Get and execute Docker login code
alias ecr_mkrepo='aws ecr create-repository --repository-name'
alias ecr_rmrepo='aws ecr delete-repository --repository-name'

#' List the digests and tags of all of the Docker images in the specified ECR repository
ecr_lsdockerimg() {
    if [ -z "${1:-}" ]; then
        printf 'ERROR: A parameter is required (repository name)!\n' >&2
    fi
    aws ecr list-images --repository-name "${1}" | awk '{ if (NF >= 2 && NR > 2) { gsub("\"", "", $2); print $2; } }'
}

#' Remove a Docker image from the given repository name and existing tag
ecr_rmimg() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Two parameters are required (repository name, existing tag)!\n' >&2
    fi
    aws ecr batch-delete-image --repository-name "${1:-}" --image-ids imageTag="${2:-}"
}

#' Apply an additional tag to the Docker image given the repository name, existing tag, and the new tag
ecr_addtag() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ]; then
        printf 'ERROR: Three parameters are required (repository name, existing tag, new tag)!\n' >&2
    fi
    MANIFEST="$(aws ecr batch-get-image --repository-name "${1:-}" --image-ids imageTag="${2:-}" --query 'images[].imageManifest' --output text)"
    if [ -z "${MANIFEST:-}" ]; then
        printf 'ERROR: Failed to retrieve the manifest data of the image from the specified repository!\n' >&2
    fi
    aws ecr put-image --repository-name "${1:-}" --image-tag "${3:-}" --image-manifest "${MANIFEST:-}" > /dev/null
}

#' Apply a tag to a tagless Docker image given the repository name, image digest, and the new tag
ecr_addtag2tagless() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ] || [ -z "${3:-}" ]; then
        printf 'ERROR: Three parameters are required (repository name, image digest, new tag)!\n' >&2
    fi
    case "${2:-}" in
        # Correct digest prefix is present
        sha256:*) imgdigest="${2:-}";;
        # Missing digest prefix; it will be added
        *) imgdigest="sha256:${2:-}";;
    esac
    if [ "$(expr "${imgdigest}" : '.*')" != 71 ]; then
        printf 'ERROR: The given image digest has an invalid length!\n' >&2
    fi
    MANIFEST="$(aws ecr batch-get-image --repository-name "${1:-}" --image-ids imageDigest="${imgdigest}" --query 'images[].imageManifest' --output text)"
    if [ -z "${MANIFEST:-}" ]; then
        printf 'ERROR: Failed to retrieve the manifest data of the image from the specified repository!\n' >&2
    fi
    aws ecr put-image --repository-name "${1:-}" --image-tag "${3:-}" --image-manifest "${MANIFEST:-}" > /dev/null
}

#' For the specified ECR repository, retrieve and return the image manifest of a Docker image (specified by the tag)
ecr_imgmanifest() { aws ecr batch-get-image --repository-name "${1:-}" --image-ids imageTag="${2:-}" --query 'images[].imageManifest' --output text; }


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


# AWS S3 #


alias s3cp='aws s3 cp'  #' Copy file
alias s3rm='aws s3 rm'  #' Remove file
alias s3rmdir='aws s3 rm --recursive'  #' Remove directory and contents recursively
alias s3mv='aws s3 mv'  #' Move file
alias s3mvdir='aws s3 mv --recursive'  #' Move directory and contents recursively
alias s3mb='aws s3 mb'  #' Make S3 bucket
alias s3rb='aws s3 rb'  #' Remove S3 bucket


#' Copy directory and contents recursively
#' @section USAGE
#' s3cpdir PATH_TO_COPY DESTINATION
#' @param[in] $1 Path to copy
#' @param[in] $2 Destination path
s3cpdir() {
    if [ -z "${1:-}" ] || [ -z "${2:-}" ]; then
        printf 'ERROR: Two parameters are required (s3rename PATHNAME NEW_NAME)!\n' >&2
    else
        PATHNAME="${1:-}"
        DESTNAME="${2:-}"
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
        PATHNAME="${1:-}"
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
        PATHNAME="${1:-}"
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
        PATHNAME="${1:-}"
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
        PATHNAME="$(dirname "${1:-}")"
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
        filename="$(basename "${2}")"
        bucket_path="${1}"
        [[ ! "${1}" =~ ^.+/$ ]] && bucket_path+='/'
        aws s3 cp "${2}" "${bucket_path}${filename}"
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ] && [ ! -z "${3:-}" ]; then
        bucket_path="${1}"
        [[ ! "${1}" =~ ^.+/$ ]] && bucket_path+='/'
        aws s3 cp "${2}" "${bucket_path}${3}"
    fi
}


fi
