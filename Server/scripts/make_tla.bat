@echo off
@set PATH=C:\Program Files\Microsoft Visual Studio 8\Common7\IDE;C:\Program Files\Microsoft Visual Studio 8\VC\BIN;C:\Program Files\Microsoft Visual Studio 8\Common7\Tools;C:\Program Files\Microsoft Visual Studio 8\Common7\Tools\bin;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\bin;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\bin;C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;C:\Program Files\Microsoft Visual Studio 8\VC\VCPackages;%PATH%
@set INCLUDE=C:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\INCLUDE;C:\Program Files\Microsoft Visual Studio 8\VC\INCLUDE;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\include;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\include;%INCLUDE%
@set LIB=C:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\LIB;C:\Program Files\Microsoft Visual Studio 8\VC\LIB;C:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\lib;C:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\lib;%LIB%
@set LIBPATH=C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;C:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\LIB

del ".\\fonline_tla.dll"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__SERVER" /Fo".\\" /Fd".\\fonline_tla.obj" /FD /c ".\\fonline_tla.cpp"
link.exe /nologo /dll /incremental:no /machine:I386 ".\\fonline_tla.obj" /out:".\\fonline_tla.dll"
del ".\\fonline_tla.obj"
del ".\\fonline_tla.exp"
del ".\\fonline_tla.lib"
del ".\\fonline_tla.idb"

del ".\\fonline_tla_client.dll"
cl.exe /nologo /MT /W3 /O2 /Gd /D "__CLIENT" /Fo".\\fonline_tla_client.obj" /Fd".\\" /FD /c ".\\fonline_tla.cpp"
link.exe /nologo /dll /incremental:no /machine:I386 ".\\fonline_tla_client.obj" /out:".\\fonline_tla_client.dll"
del ".\\fonline_tla_client.obj"
del ".\\fonline_tla_client.exp"
del ".\\fonline_tla_client.lib"
del ".\\vc80.idb"
copy ".\\fonline_tla_client.dll" "..\\..\\client\\data\\scripts\\fonline_tla_client.dll"

@pause