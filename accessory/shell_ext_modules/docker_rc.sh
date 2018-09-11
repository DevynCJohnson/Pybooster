#!/bin/bash
# -*- coding: utf-8-unix; Mode: Shell; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=shell syn=sh.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax shell; indent-mode normal; eol unix; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
# @brief Shell RC script providing aliases for various Docker commands
# @file docker_rc.sh
# @version 2018.09.06
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @section INSTALL DOCKER
# To install Docker on Ubuntu, use the below commands
# curl -f -s -S -L https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
# sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"


if [ -x "$(command -v docker)" ]; then


alias dock_cl='docker container ls -a --format "table {{.ID}}\t{{.Image}}\t{{.Status}}\t{{.Ports}}"'  # List containers (compressed list)
alias docker_clean_all='docker system prune --all'  # Remove all unused images not just dangling ones
alias docker_clean_con='docker container prune'  # Remove all stopped containers
alias docker_clean_img='docker image prune --all'  # Remove all unused images, not just dangling ones
alias docker_conls='docker ps -a'  # List containers
alias docker_conrm='docker container rm'  # Remove container
alias docker_constop='docker container stop'  # Stop container
alias docker_exe='docker run -i -t'  # Run Docker image like an executable
alias docker_imgls='docker images'  # List images
alias dock_plugls='docker plugin ls'  # List plugins
alias dock_rm_sock='sudo rm -r -f /var/run/docker.sock'  # Remove Docker's socket
alias dock_srvmk='docker service create'  # Create service
alias dock_srvps='docker service ps'  # View services
alias dock_srvrm='docker service rm'  # Remove service
alias dock_volinspect='docker volume inspect'  # Inspect volume
alias dock_volls='docker volume ls'  # List volumes
alias dock_volmk='docker volume create'  # Create volumes
alias dock_volprune='docker volume prune'  # Prune unused volumes
alias dock_volrm='docker volume rm'  # Remove volumes


if [ -x "$(command -v docker-compose)" ]; then
    alias dockdown='docker-compose down'
    alias dockup='docker-compose up -d'
fi


if [ -x "$(command -v service)" ]; then
    alias dock_stat='service docker status'
    alias dock_restart='sudo service docker restart'
elif [ -x "$(command -v systemctl)" ]; then
    alias dock_stat='systemctl status docker.service'
fi


fi
