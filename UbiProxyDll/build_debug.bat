del /Q /S release64\*
rmdir /S /Q release64
mkdir release64
call build_env_x64.bat
cl /std:c++17 /LD /DNDEBUG dllmain.cpp framework.h pch.cpp pch.h upc_r2.cpp upc_r2.h utils.cpp utils.h User32.lib Shell32.lib /EHsc /MP12 /Ox /link /OUT:release64\upc_r264.dll
echo asss
echo aa
pause
echo ss