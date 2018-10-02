#!/usr/bin/env Rscript
# -*- coding: utf-8-unix; Mode: R; indent-tabs-mode: nil; tab-width: 2 -*-
# vim: set fileencoding=utf-8 filetype=r syn=r.doxygen fileformat=unix tabstop=2 expandtab :
# kate: encoding utf-8; bom off; syntax r; indent-mode normal; eol unix; replace-tabs on; indent-width 2; tab-width 2; remove-trailing-space on; line-numbers on;
#' @brief Tidy R Source Code
#' @file RTidy.R
#' @version 2018.10.02
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


library('formatR')


args <- commandArgs(trailingOnly = TRUE)
orig_file <- args[1]


if (file.exists(orig_file)) {
  tmpfile <- tempfile()
  tidy_source(orig_file, arrow = TRUE, blank = TRUE, comment = TRUE, file = tmpfile, indent = 2)
  file.copy(tmpfile, orig_file, overwrite = TRUE, recursive = FALSE, copy.mode = FALSE, copy.date = FALSE)
  file.remove(tmpfile)
}
