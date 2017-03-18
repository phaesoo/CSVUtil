#include "CSVUtil.h"

#include <fstream>
#include <assert.h>

using std::vector;
using std::string;

bool CSVUtil::ReadFile(const string& filepath, DataFrame& dataList)
{
	dataList.clear();

	// Check file format 
	if (!ValidateFileFormat(filepath))
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
		vector<string> row;
		string cell;
		int size = textline.size();
		for (int i = 0; i < size; ++i)
		{
			if (textline[i] == g_token) // Token일 경우(,)
			{
				row.push_back(cell);
				cell.clear();
			}
			else
			{
				cell.push_back(textline[i]);

				if (i == size - 1) // Last loop
				{
					row.push_back(cell);
				}
			}
		}

		dataList.push_back(row);
	}

	return true;
}

bool CSVUtil::WriteFile(const std::string& filepath, const DataFrame& dataList)
{
	// Check file format 
	if (!ValidateFileFormat(filepath))
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
	int listsize = dataList.size();
	for (int i = 0; i < listsize; ++i)
	{
		int datasize = dataList[i].size();
		for (int j = 0; j < datasize; ++j)
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

bool CSVUtil::ValidateFileFormat(const std::string& filepath)
{
	// csv파일인지 검사
	if (filepath.substr(filepath.find_last_of(".") + 1) == "csv")
	{
		return true;
	}

	assert(0);
	return false;
}