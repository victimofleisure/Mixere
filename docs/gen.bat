echo y | rd /s C:\Chris\MyProjects\Mixere\web\Help
ren helpframe.html helpframe.txt
navgen template.html .
if errorlevel 1 goto err
dfil *.html "C:\Chris\MyProjects\FixSelfUrl\Release\FixSelfUrl %%s" >x.bat
if errorlevel 1 goto err
call x
del x.bat
ren helpframe.txt helpframe.html
md Help
C:\Chris\MyProjects\doc2web\release\doc2web /nospaces C:\Chris\MyProjects\Mixere\Help\help.txt Help Contents.htm C:\Chris\MyProjects\Mixere\doc\MixereHelp.htm "Mixere Help"
if errorlevel 1 goto err
cd Help
copy ..\helptopic.css content.css
navgen C:\Chris\MyProjects\Mixere\Help\template.txt .
copy ..\helpheader.txt x
copy x + Contents.htm
echo ^<body^>^<html^> >>x
del Contents.htm
ren x Contents.htm
cd ..
copy C:\Chris\MyProjects\Mixere\doc\mixerehelp.htm docs\1.0.82
goto exit
:err
pause Error!
:exit
