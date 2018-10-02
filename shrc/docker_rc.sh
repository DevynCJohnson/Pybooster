#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing aliases for various Docker commands
#' @file docker_rc.sh
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/
#' @section INSTALL DOCKER
#' To install Docker on Ubuntu, use the below commands
#' curl -f -s -S -L https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
#' sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"


if [ -x "$(command -v docker)" ]; then


alias dock_cl='docker container ls -a --format "table {{.ID}}\t{{.Image}}\t{{.Status}}\t{{.Ports}}"'  #' List containers (compressed list)
alias dock_clean_all='docker system prune --all'  #' Remove all unused images not just dangling ones
alias dock_clean_con='docker container prune'  #' Remove all stopped containers
alias dock_clean_img='docker image prune --all'  #' Remove all unused images, not just dangling ones
alias dock_conls='docker ps -a'  #' List containers
alias dock_conrm='docker container rm'  #' Remove container
alias dock_constop='docker container stop'  #' Stop container
alias dock_exe='docker run -i -t'  #' Run Docker image like an executable
alias dock_imgls='docker images'  #' List images
alias dock_plugls='docker plugin ls'  #' List plugins
alias dock_rm_sock='sudo rm -r -f /var/run/docker.sock'  #' Remove Docker's socket
alias dock_srvmk='docker service create'  #' Create service
alias dock_srvps='docker service ps'  #' View services
alias dock_srvrm='docker service rm'  #' Remove service
alias dock_volinspect='docker volume inspect'  #' Inspect volume
alias dock_volls='docker volume ls'  #' List volumes
alias dock_volmk='docker volume create'  #' Create volumes
alias dock_volprune='docker volume prune'  #' Prune unused volumes
alias dock_volrm='docker volume rm'  #' Remove volumes
alias getdockimg='docker image pull'  #' Retrieve the specified Docker image

dock_lsvolfiles() { docker export "${1}" | tar -t; }  #' List the files in a Docker volume
dock_terminal() { docker run -i -t "${1}" /bin/bash; }  #' Run the specified Docker image and access the contained system's terminal
dock_running_terminal() { docker exec -i -t "${1}" /bin/bash; }  #' Access the BASH shell of an already running Docker image

if [ -x "$(command -v docker-compose)" ]; then
    alias dockdown='docker-compose down'
    alias dockup='docker-compose up -d'
fi


if [ -x "$(command -v service)" ]; then
    alias dock_stat='service docker status'  #' View the status of the Docker service
    alias dock_restart='sudo service docker restart'  #' Restart the Docker service
elif [ -x "$(command -v systemctl)" ]; then
    alias dock_stat='systemctl status docker.service'  #' View the status of the Docker service
fi


#' Build, Tag, & Push Docker Image to S3 repository
#' @section USAGE
#' export MAIN_REPO='S3_REPO'  # 123456789.dkr.ecr.REGION.amazonaws.com/
#' docker_buildpush BUCKET_NAME [TAG_1] [TAG_2] [TAG_3]
#' @param[in] $1 Bucket name
#' @param[in] $2 Tag name (Optional; defaults to "latest")
#' @param[in] $3 Tag name (Optional)
#' @param[in] $4 Tag name (Optional)
dock_buildpush() {
    if [ -z "${MAIN_REPO:-}" ]; then
        printf 'The environment variable "MAIN_REPO" must be defined to specify the S3 repository!\n' >&2
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ] && [ ! -z "${3:-}" ] && [ ! -z "${4:-}" ]; then
        docker build --tag "${1}:${2}" --tag "${1}:${3}" --tag "${1}:${4}" .
        docker tag "${1}:${2}" "${MAIN_REPO}${1}:${2}"
        docker push "${MAIN_REPO}${1}:${2}"
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ] && [ ! -z "${3:-}" ] && [ -z "${4:-}" ]; then
        docker build --tag "${1}:${2}" --tag "${1}:${3}" .
        docker tag "${1}:${2}" "${MAIN_REPO}${1}:${2}"
        docker push "${MAIN_REPO}${1}:${2}"
    elif [ ! -z "${1:-}" ] && [ ! -z "${2:-}" ] && [ -z "${3:-}" ] && [ -z "${4:-}" ]; then
        docker build --tag "${1}:${2}" .
        docker tag "${1}:${2}" "${MAIN_REPO}${1}:${2}"
        docker push "${MAIN_REPO}${1}:${2}"
    elif [ ! -z "${1:-}" ] && [ -z "${2:-}" ] && [ -z "${3:-}" ] && [ -z "${4:-}" ]; then
        docker build --tag "${1}" .
        docker tag "${1}:latest" "${MAIN_REPO}${1}:latest"
        docker push "${MAIN_REPO}${1}:latest"
    else
        printf 'You must specify at least one repository and bucket name!\n' >&2
    fi
}


fi
