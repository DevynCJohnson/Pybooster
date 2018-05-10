@echo off
REM -*- coding: utf-8-dos; Mode: Batch; indent-tabs-mode: nil; tab-width: 4 -*-
REM vim: set fileencoding=utf-8 filetype=batch syn=batch.doxygen fileformat=dos tabstop=4 expandtab :
REM kate: encoding utf-8; bom off; syntax batch; indent-mode normal; eol dos; replace-tabs on; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
REM @brief flake8, pycodestyle (pep8), pyflakes, pylint, and doctest for Geany
REM @file pygeany-check.bat
REM @version 2018.04.27
REM @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
REM @copyright Public Domain (CC0) - https://creativecommons.org/publicdomain/zero/1.0/


echo.
echo ======  *FLAKE8*  ======
echo.
where /q flake8
if errorlevel 1 (
    set FOUND=0
) else (
    set FOUND=1
)
if %FOUND% == 1 (
    flake8 --jobs=1 --ignore="E501,T001" --max-complexity=10 --exclude=".svn,CVS,.bzr,.hg,.git,__pycache__,__init__.py,__init__" --doctests --benchmark --statistics --show-source --exit-zero %1
) else (
    echo Flake8 is not installed!
    echo.
)
echo.


echo.
echo ======  *PEP8*  ======
echo.
where /q pycodestyle
if errorlevel 1 (
    set FOUND=0
) else (
    set FOUND=1
)
if %FOUND% == 1 (
    pycodestyle -v --ignore="E501" --statistics --show-pep8 --show-source %1
) else (
    echo pycodestyle/pep8 is not installed!
    echo.
)
echo.


echo.
echo ======  *PYLINT3*  ======
echo.
where /q pylint
if errorlevel 1 (
    set FOUND=0
) else (
    set FOUND=1
)
if %FOUND% == 1 (
    pylint --disable="I0011,C0111,C0301,E501,T001" --good-names="i,j,k,v,key,val,ex,Run,_" --notes="FIXME,XXX,TODO,FINISH,DEBUG,FIX,HERE" --msg-template="{path}:{line}: [{msg_id}({symbol}), {obj}] {msg}" --max-returns=16 --max-module-lines=4096 --reports=y --persistent=n %1
) else (
    echo Pylint is not installed!
    echo.
)
echo.


echo.
echo ======  *NOQA CHECKER*  ======
echo.
where /q noqa_checker
if errorlevel 1 (
    set FOUND=0
) else (
    set FOUND=1
)
if %FOUND% == 1 (
    noqa_checker %1
) else (
    echo noqa_checker is not installed!
    echo.
)
echo.


goto :EOF
