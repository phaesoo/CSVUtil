#include <Windows.h>

#include "CMDUtil.h"

using std::string;

void CMDUtil::ExcuteCommand(const string& command)
{
	string cmd = "/k " + command; // /k : 명령 종료후 cmd닫음
	auto x = ShellExecuteA(NULL, "open", "cmd.exe", cmd.c_str(), NULL, SW_HIDE);
}
