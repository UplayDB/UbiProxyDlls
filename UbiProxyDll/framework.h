#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ShlObj.h>
#include <io.h>
#include <fcntl.h>
#include <queue>
#include <list>
#include <filesystem>
#include <string>
#include <minwindef.h>

using FunctionAddress = uint64_t;

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
