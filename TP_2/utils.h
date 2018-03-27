#pragma once
#include <iostream>
#include <string>
#include <ctime>
#define LOG_INFO(msg) std::cout /*<< getTime()*/ << " | INFO   " << " | "<< __FILE__  << " | "<< __FUNCTION__  << ":"<< __LINE__<< " | "<< msg << std::endl
#define LOG_TRACE(msg) std::cout /*<< getTime()*/ << " | TRACE   " << " | "<< __FILE__  << " | "<< __FUNCTION__  << ":"<< __LINE__<< " | "<< msg << std::endl
#define LOG_WARNING(msg) std::cout /*<< getTime() */<< " | WARNING   " << " | "<< __FILE__  << " | "<< __FUNCTION__  << ":"<< __LINE__<< " | "<< msg << std::endl
#define LOG_ERROR(msg) std::cout /*<< getTime() */<< " | ERROR   " << " | "<< __FILE__  << " | "<< __FUNCTION__  << ":"<< __LINE__<< " | "<< msg << std::endl
#define ASSERT(expr) \
    if (!(expr)) \
        LOG_ERROR("Assertion failed"); \
		abort();

//std::string getTime();
