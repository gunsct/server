#pragma once

#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <iostream>

class Error
{
public:
	Error(void){};
	~Error(void){};

	static Error* GetInstance();

	void err_display( char* msg );
	void err_quit( char* msg );
};


#define ERROR ( Error::GetInstance() )
