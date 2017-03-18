#include <iostream>
#include <string>

#include <fstream>

#include "CSVUtil.h"

using namespace std;

void FileFunc()
{
	string infilepath = "C:/Users/phaes/Documents/Haafor/Python/Haafor/file.csv";
	std::ifstream open(infilepath);

	CSVUtil::DataFrame dataframe;
	CSVUtil::ReadFile(infilepath, dataframe);

	// loop를 돌며 파일에 쓰기
	for (auto itr = dataframe.begin(); itr != dataframe.end(); ++itr)
	{
		auto& row = *itr;
		for (auto itr2 = row.begin(); itr2 != row.end(); ++itr2)
		{
			cout << *itr2 << CSVUtil::g_token;
		}
		cout << std::endl;
	}

	string outfilepath = "C:/Users/phaes/Documents/Haafor/Python/Haafor/file_cpp.csv";

	CSVUtil::WriteFile(outfilepath, dataframe);

	int x = 0;
}


int main()
{
	FileFunc();

	return 0;
}
