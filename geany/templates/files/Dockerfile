# Dockerfile
# -*- coding: utf-8-unix; indent-tabs-mode: t; tab-width: 4 -*-
# vim: set fileencoding=utf-8 fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;


FROM IMAGENAME:IMAGETAG

LABEL maintainer="{developer}"
LABEL developer="{developer}"
LABEL email="{mail}"
LABEL version="{date}"
LABEL description="XXX"


# SETUP ENVIRONMENT #


SHELL ash|bash|csh|dash|sh|tcsh|zsh

ENV XXX XXX
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8
ENV LC_ADDRESS en_US.UTF-8
ENV LC_ALL en_US.UTF-8
ENV LC_COLLATE en_US.UTF-8
ENV LC_CTYPE en_US.UTF-8
ENV LC_IDENTIFICATION en_US.UTF-8
ENV LC_MEASUREMENT en_US.UTF-8
ENV LC_MESSAGES en_US.UTF-8
ENV LC_MONETARY en_US.UTF-8
ENV LC_NAME en_US.UTF-8
ENV LC_NUMERIC en_US.UTF-8
ENV LC_PAPER en_US.UTF-8
ENV LC_TELEPHONE en_US.UTF-8
ENV LC_TIME en_US.UTF-8

ENV G_DBUS_DEBUG ''
ENV G_DEBUG ''
ENV G_ENABLE_DIAGNOSTIC 0
ENV G_MESSAGES_DEBUG ''
ENV GST_DEBUG 0
ENV GTK_DEBUG ''
ENV MESA_NO_ERROR 1
ENV ORC_DEBUG 0

ENV GTK_OVERLAY_SCROLLING 0
ENV NO_AT_BRIDGE 1


# SETUP SYSTEM #


USER USERNAME|UID

WORKDIR /PATH/TO/WORKDIR/

RUN apt-get update && apt-get install -y XXX && apt-get clean && rm -f -r /var/lib/apt/lists/*

ADD SRC [SRC ...] DEST
COPY "SRC" ["SRC" "..."] "DEST"


# INITIATE THE SERVER #


EXPOSE PORTNUM

CMD ["/PATH/XXX", "-X", "XXX"]
