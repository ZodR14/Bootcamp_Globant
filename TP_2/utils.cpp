#include "utils.h"

/*
std::string getTime() {
	std::string buffer;
	// current date/time based on current system
	time_t now = time(0);

	tm *ltm = localtime(&now);

	buffer = std::to_string(1900 + ltm->tm_year) + "-" + std::to_string(ltm->tm_mon + 1)+ "-" + std::to_string(ltm->tm_mday);
	buffer += " " + std::to_string(1 + ltm->tm_hour) + ":" + std::to_string(1 + ltm->tm_sec); 

	return buffer;
}
*/