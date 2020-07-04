@echo off

REM compile resource
rc.exe resource.rc

REM compile
cl.exe /c /EHsc /I C:\freeglut\include main.cpp

REM link
link.exe main.obj resource.res /LIBPATH:C:\freeglut\lib /SUBSYSTEM:CONSOLE

REM execute
main.exe
