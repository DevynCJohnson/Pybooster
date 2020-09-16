#!/usr/bin/make -f
# -*- coding: utf-8-unix; Mode: Makefile; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=makefile syntax=makefile.doxygen fileformat=unix tabstop=4 :
# kate: encoding utf-8; bom off; syntax makefile; indent-mode normal; eol unix; indent-width 4; tab-width 4; remove-trailing-space on;
#' @brief Makefile containing phony targets that perform project-level tasks
#' @file project.mk
#' @version 2020.09.16
#' @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
#' @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


# CHECKSUM COMMANDS #


.PHONY : genchecksums valchecksums


genchecksums :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating Checksums ==='
	$(RM) ./.checksums.b2b512 ./.checksums.rmd160 ./.checksums.sha1 ./.checksums.sha512 ./.checksums.whirlpool || true
	find . -mount -type f -not \( -name '.checksums.sha512' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -sha512 > "${FOLDER}.checksums.sha512"
	find . -mount -type f -not \( -name '.checksums.whirlpool' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -whirlpool > "${FOLDER}.checksums.whirlpool"
	find . -mount -type f -not \( -name '.checksums.rmd160' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -ripemd160 > "${FOLDER}.checksums.rmd160"
	find . -mount -type f -not \( -name '.checksums.b2b512' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl blake2b512 > "${FOLDER}.checksums.b2b512"
	find . -mount -type f -not \( -name '.checksums.sha1' -o -path "./bin/*" -o -path "./debugging/*" -o -path "./testing/*" -o -path "./.git/*" \) -print0 | xargs -0 openssl dgst -sha1 > "${FOLDER}.checksums.sha1"

valchecksums :
	-@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Validating Checksums ==='
	sha512sum --check --quiet --strict ./.checksums.sha512
	sha1sum --check --quiet --strict ./.checksums.sha1


# GIT COMMANDS #


.PHONY : cleangit commit commithash commithashes gitattr gitchanges gitignore gitlastchanges gitlinechanges gitlscommits gitlsconfigs gitlsfiles gitlsuncommitted gitstats gitundoadd lscontrib lstags newchanges news numcommits previewcleangit pushtags setkey signoff status tag treehashes uncommit xcommit xtag


commit :
	@printf 'Create a commit message: ' && read -r GITMSG && git commit --cleanup=strip --message="$$GITMSG" --signoff

commithash :
	@git log -1 --pretty=format:"%H"
	git log -1 --pretty=format:"%h"

commithashes :
	@git log --pretty=format:"%H"

cleangit : cleanall fixperm
	-@git reflog expire --all --expire=now --stale-fix
	git rm --cached -r --ignore-unmatch *
	git gc --prune=now --aggressive
	git add --all --refresh
	git fsck --dangling --full --name-objects --progress --strict --unreachable
	git gc --prune=now --aggressive

gitattr :
	@git check-attr --all ./*
	git check-attr --all ./*/*
	git check-attr --all ./*/*/*

gitchanges :
	@git show

gitignore :
	@git check-ignore ./*
	git check-ignore ./*/*
	git check-ignore ./*/*/*

gitlastchanges :
	@git show --summary

gitlinechanges :
	@git show --stat

gitlscommits :
	@git log --pretty=format:'%C(auto) %H | %s | %an | %ar%d'

gitlsconfigs :
	@git config --list

gitlsfiles :
	@git ls-files

gitlsuncommitted :
	@git diff

gitstats :
	-@gitstats ./ $(TESTINGDIR)/git/

gitundoadd :
	-@git reset

lscontrib :
	@git log --format='%aN <%aE>' | sort -n -r | uniq

lstags :
	@git tag

newchanges :
	@git diff HEAD~1

numcommits :
	@git log | grep ^commit | wc -l

previewcleangit : cleanall fixperm
	-@git reflog expire --dry-run --all --expire=now --stale-fix
	git rm --dry-run --cached -r --ignore-unmatch *
	git prune --dry-run --verbose
	git add --dry-run --all --refresh

pushtags :
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Pushing Tags ==='
	git push origin --tags

setkey :
	@git config --global user.signingkey $(key); git config --global commit.gpgsign true; git config --global gpg.program "$(shell which gpg)"

signoff :
	@git commit --amend --signoff

status :
	@git status --ahead-behind --branch --short --verbose

tag :
	@git tag -a 'v$(__VERSION__)' -m 'Stable Release (v$(__VERSION__))'

treehashes :
	@git log --pretty=format:"%T"

uncommit :
	@git reset --soft HEAD~

xcommit :
	@printf 'Create a commit message: ' && read -r GITMSG && git commit --cleanup=strip --message="$$GITMSG" --signoff

xtag :
	@git tag -s -a 'v$(__VERSION__)' -m 'Stable Release (v$(__VERSION__))'


# MISCELLANEOUS PROJECT COMMANDS #


.PHONY : changelogmd gnuchangelog news

changelogmd : ./tools/mkchangelogmd.sh
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating Markdown ChangeLog ==='
	$(RM) ./ChangeLog.md
	./tools/mkchangelogmd.sh

gnuchangelog : ./.git/
	@printf '\x1b[1;4;33m%s\x1b[0m\n\n' '=== Creating GNU ChangeLog from Git ==='
	git log --pretty --numstat --summary | git2cl > GNU-ChangeLog

news :
	@([ -f ./ChangeLog ] && $(COPY) ./ChangeLog ./NEWS) || true
