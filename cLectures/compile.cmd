@echo off
:PRE
cls
@echo Parallel latex compilation.
@echo.
SET /p MODE=Enter 1 for Lectures, 2 for Handouts: 
IF %MODE%==1 GOTO LECTURE
IF %MODE%==2 GOTO HANDOUT
GOTO PRE

:LECTURE
SET TOPLINE=\\documentclass[smaller,table]{beamer}
GOTO START
:HANDOUT
SET TOPLINE=\\documentclass[smaller,handout,table]{beamer}

:START
FOR %%T IN (*.tex) DO (CALL :handleTex "%%T")
GOTO :eof

:handleTex
copy /Y %1 %1.old >nul
sed -i "1 s/^.*$/%TOPLINE%/g" %1
START "PdfLatex" /B pdflatex -synctex=1 -interaction=nonstopmode %1 >nul 2>&1
GOTO :eof