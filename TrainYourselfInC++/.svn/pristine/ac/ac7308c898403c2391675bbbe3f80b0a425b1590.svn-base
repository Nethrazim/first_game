#pragma once
#include <string>
#include <iostream>

class Logger
{
private: 
Logger(void);

public:
static Logger* instance;
static Logger* getInstance();

~Logger(void);
//void info(string);

void error(std::string);
void debug(std::string);

template<typename T>
static void info(T x, int value = -666)
{
	if(value == -666)
	{
		std::cout << x << std::endl;
	}else
	{
		std::cout << x << " : " << value << std::endl;
	}	
}

template<typename T>
static void error(T x, int value = -666)
{
	if(value == -666)
	{
		std::cout << x << std::endl;
	}else
	{
		std::cout << x << " : " << value << std::endl;
	}
}

};
