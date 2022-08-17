#pragma once
#include "framework.h"
#include "pch.h"

using std::string;
using std::wstring;
using std::vector;


#define EXPORT extern "C" _declspec(dllexport)

#define PRINT_DEBUG(a, ...) do {FILE *t = fopen("upc_proxy_LOG.txt", "a"); fprintf(t, "%u " a, GetCurrentThreadId(), __VA_ARGS__); fclose(t);} while (0)
