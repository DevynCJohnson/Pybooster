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


alias docker_conrm='docker container rm'
alias docker_constop='docker container stop'
alias docker_imgls='docker images'
alias docker_rm_sock='sudo rm -r -f /var/run/docker.sock'
alias docker_srvmk='docker service create'
alias docker_srvps='docker service ps'
alias docker_srvrm='docker service rm'
alias docker_volinspect='docker volume inspect'
alias docker_volls='docker volume ls'
alias docker_volmk='docker volume create'
alias docker_volprune='docker volume prune'
alias docker_volrm='docker volume rm'


if [ -x "$(command -v service)" ]; then
    alias docker_stat='service docker status'
    alias docker_restart='sudo service docker restart'
elif [ -x "$(command -v systemctl)" ]; then
    alias docker_stat='systemctl status docker.service'
fi


fi
