#pragma once

#include <iostream>
using namespace std;

#include <tchar.h>

#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <stdlib.h>

#include <stdio.h>
#include <windows.h>
#include <time.h>

#include <vector>
#include <queue>
#include <list>
#include <map>
#include <string>

#include <memory>

// Instance 
#include "Error.h"
#include "Thread.h"

// Define
#define MAX_BUFFER_LENGTH	4096
#define SERVERPORT 9000
#define BUFSIZE    512

//#ifdef _DEBUG
//#pragma comment( linker, "/entry:mainCRTStartup /subsystem:console" )
//#endif // DEBUG