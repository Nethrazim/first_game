#include "Logger.h"

Logger* Logger::instance = NULL;


Logger::Logger(void)
{
	Logger::instance = this;
}

Logger::~Logger(void)
{
}

void Logger::error(std::string s)
{
	std::cout << s << std::endl;
}

void Logger::debug(std::string s)
{
	std::cout << s << std::endl;
}

Logger* Logger::getInstance()
{
	if(Logger::instance == NULL)
		new Logger();
	
	return Logger::instance;
}