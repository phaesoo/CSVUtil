#include <Windows.h>

#include "CMDUtil.h"

using std::string;

void CMDUtil::ExcuteCommand(const string& command)
{
	string cmd = "/k " + command; // /k : ��� ������ cmd����
	auto x = ShellExecuteA(NULL, "open", "cmd.exe", cmd.c_str(), NULL, SW_HIDE);
}
