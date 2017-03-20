#include <fstream>
#include <assert.h>

#include "FileFormatUtil.h"
#include "TextUtil.h"
#include "CSVUtil.h"

using namespace util;
using std::vector;
using std::string;

bool CSVUtil::ReadFile(const string& filepath, DataFrame& dataList)
{
	dataList.clear();

	// Check file format
	if (!FileFormatUtil::ValidateFileFormat(filepath, FileFormatUtil::Format::csv))
	{
		return false;
	}

	std::ifstream file(filepath);
	if (file.fail())
	{
		assert(0);
		return false;
	}

	// loop를 돌며 파일에서 읽어오기
	string textline;
	while (std::getline(file, textline))
	{
        dataList.push_back(TextUtil::SeperateString(textline, g_token));
	}

	return true;
}

bool CSVUtil::WriteFile(const std::string& filepath, const DataFrame& dataList)
{
	// Check file format
	if (!FileFormatUtil::ValidateFileFormat(filepath, FileFormatUtil::Format::csv))
	{
		return false;
	}

	std::ofstream file(filepath);
	if (file.fail())
	{
		assert(0);
		return false;
	}

	// loop를 돌며 파일에 쓰기
    size_t listsize = dataList.size();
	for (size_t i = 0; i < listsize; ++i)
	{
        size_t datasize = dataList[i].size();
		for (size_t j = 0; j < datasize; ++j)
		{
			file << dataList[i][j];

			if (j != datasize - 1) // Add token
			{
				file << g_token;
			}
		}

		file << std::endl;
	}

	return true;
}