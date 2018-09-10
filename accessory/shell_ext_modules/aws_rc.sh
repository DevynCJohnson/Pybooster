#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Shell RC script providing aliases for various AWS commands
# @file aws_rc.sh
# @version 2018.09.06
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


if [ -x "$(command -v aws)" ]; then


alias awstime='sudo ntpdate 0.amazon.pool.ntp.org; sudo ntpdate 0.amazon.pool.ntp.org; sudo hwclock -w'


# AWS EC2 #


alias ec2desc='aws ec2 describe-instances'


# AWS ECR #


alias ecrgetlogin='aws ecr get-login --no-include-email'


# AWS S3 #


alias s3cp='aws s3 cp'
alias s3ls='aws s3 ls'
alias s3rm='aws s3 rm'
alias s3mv='aws s3 mv'
alias s3mb='aws s3 mb'  # Make S3 Bucket
alias s3rb='aws s3 rb'  # Remove S3 Bucket


# AWS IAM #


alias iamactsmry='aws iam get-account-summary'
alias iamlsgrps='aws iam list-groups'
alias iamlsroles='aws iam list-roles'
alias iamlskeys='aws iam list-access-keys'


fi


# TODO: Implement the below comments
#export AWS_ACCESS_KEY_ID=
#export AWS_SECRET_ACCESS_KEY=
#export AWS_SESSION_TOKEN=
#export AWS_REGION='us-east-1'
#export AWS_PROFILE=


# AWS ENVIRONMENT VARIABLES #


#AWS_BATCH_CE_NAME
#AWS_BATCH_JOB_ARRAY_INDEX
#AWS_BATCH_JOB_ATTEMPT
#AWS_BATCH_JOB_ID
#AWS_BATCH_JQ_NAME
#AWS_EXECUTION_ENV
#LAMBDA_RUNTIME_DIR
