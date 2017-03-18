#pragma once

#include <string>
#include <vector>

class CSVUtil
{
public:
	typedef std::vector< std::vector<std::string> > DataFrame;

	static bool ReadFile(const std::string& filepath, DataFrame& dataList);
	static bool WriteFile(const std::string& filepath, const DataFrame& dataList);

private:
	static bool ValidateFileFormat(const std::string& filepath);

public:
	static const char g_token = ","[0];
};


class TextUtil
{
};