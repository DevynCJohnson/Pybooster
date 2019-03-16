#!/bin/sh
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
#' @brief Shell RC script providing aliases for various Docker commands
#' @file docker_rc.sh
#' @version 2019.03.16
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/
#' @section INSTALL_DOCKER
#' To install Docker on Ubuntu, use the below commands
#' curl -f -L -s -S https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
#' sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -c -s) stable"


if [ -x "$(command -v docker)" ]; then


alias docker_clean_all='docker system prune --all'  #' Remove all unused images not just dangling ones
alias docker_clean_con='docker container prune'  #' Remove all stopped containers
alias docker_clean_dimg='docker rmi "$(docker images -a --filter=dangling=true -q)"'  #' Remove dangling images
alias docker_clean_img='docker image prune --all'  #' Remove all unused images, not just dangling ones
alias docker_clean_ps='docker rm "$(docker ps --filter=status=exited --filter=status=created -q)"'  #' Remove stopped containers
alias docker_conls='docker container ls -a --format "table {{.ID}}\t{{.Image}}\t{{.Status}}\t{{.Ports}}"'  #' List containers (compressed list)
alias docker_conls='docker ps -a'  #' List containers
alias docker_conrm='docker container rm'  #' Remove container
alias docker_constop='docker container stop'  #' Stop container
alias docker_exe='docker run -i -t'  #' Run Docker image like an executable
alias docker_imgls='docker images'  #' List images
alias docker_imgrm='docker rmi'  #' Remove Docker image
alias docker_kill_all='docker kill "$(docker ps -q)"'  #' Stop all running Dockers
alias docker_plugls='docker plugin ls'  #' List plugins
alias docker_rm_sock='sudo rm -r -f /var/run/docker.sock'  #' Remove Docker's socket
alias docker_srvmk='docker service create'  #' Create service
alias docker_srvps='docker service ps'  #' View services
alias docker_srvrm='docker service rm'  #' Remove service
alias docker_volinspect='docker volume inspect'  #' Inspect volume
alias docker_volls='docker volume ls'  #' List volumes
alias docker_volmk='docker volume create'  #' Create volumes
alias docker_volprune='docker volume prune'  #' Prune unused volumes
alias docker_volrm='docker volume rm'  #' Remove volumes
alias getdockerimg='docker image pull'  #' Retrieve the specified Docker image

docker_lsvolfiles() { docker export "${1}" | tar -t; }  #' List the files in a Docker volume
docker_terminal() { docker run -i -t "${1}" /bin/bash; }  #' Run the specified Docker image and access the contained system's terminal
docker_running_terminal() { docker exec -i -t "${1}" /bin/bash; }  #' Access the BASH shell of an already running Docker image

if [ -x "$(command -v docker-compose)" ]; then
    alias dockerdown='docker-compose down'
    alias dockerup='docker-compose up -d'
fi


if [ -x "$(command -v service)" ]; then
    alias docker_stat='service docker status'  #' View the status of the Docker service
    alias docker_restart='sudo service docker restart'  #' Restart the Docker service
elif [ -x "$(command -v systemctl)" ]; then
    alias docker_stat='systemctl status docker.service'  #' View the status of the Docker service
fi


#' Build, Tag, & Push Docker Image to an ECR repository
#' @section USAGE
#' export MAIN_REPO='ECR_REPO'  # 123456789.dkr.ecr.REGION.amazonaws.com/
#' docker_buildpush BUCKET_NAME [TAG_1] [TAG_2] [TAG_3]
#' @param[in] $1 Bucket name (Optional only if `$ECR_BUCKET` is defined)
#' @param[in] $2 Tag name (Optional; defaults to "latest")
#' @param[in] $3 Tag name (Optional)
#' @param[in] $4 Tag name (Optional)
dock_buildpush() {
    [ -z "${ECR_BUCKET:-}" ] && [ -n "${1:-}" ] && ECR_BUCKET="${1}"
    if [ -n "${2:-}" ]; then
        tag="${2}"
    else
        tag='latest'
    fi
    if [ -z "${MAIN_REPO:-}" ]; then
        printf 'The environment variable "MAIN_REPO" must be defined to specify the ECR repository!\n' >&2
    elif [ -n "${ECR_BUCKET:-}" ] && [ -n "${3:-}" ] && [ -n "${4:-}" ]; then
        docker build --tag "${ECR_BUCKET}:${tag}" --tag "${ECR_BUCKET}:${3}" --tag "${ECR_BUCKET}:${4}" .
    elif [ -n "${ECR_BUCKET:-}" ] && [ -n "${3:-}" ] && [ -z "${4:-}" ]; then
        docker build --tag "${ECR_BUCKET}:${tag}" --tag "${ECR_BUCKET}:${3}" .
    elif [ -n "${ECR_BUCKET:-}" ] && [ -z "${3:-}" ] && [ -z "${4:-}" ]; then
        docker build --tag "${ECR_BUCKET}:${tag}" .
    else
        printf 'You must specify at least one ECR repository!\n' >&2
    fi
    if [ -n "${ECR_BUCKET:-}" ]; then
        docker tag "${ECR_BUCKET}:${tag}" "${MAIN_REPO}${ECR_BUCKET}:${tag}"
        docker push "${MAIN_REPO}${ECR_BUCKET}:${tag}"
    fi
}


fi
