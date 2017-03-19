#pragma once

#include <string>

class CMDUtil
{
public:
	CMDUtil() = delete;

	static void ExcuteCommand(const std::string& command);
};