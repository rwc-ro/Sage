@ECHO OFF
Title Automatic update the latest Git from the rAyam by.null#6385
ECHO Getting the latest Git.
ECHO please wait...
git pull https://github.com/rathena/rathena.git

timeout /t 3
cls

Echo ---------------------------------------------------
Set /p Wait="Finished."