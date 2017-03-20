#include <iostream>
#include <string>

#include <fstream>
#include <Windows.h>

#include "CSVUtil.h"
#include "CMDUtil.h"
#include "Statistic.h"

using namespace std;
using namespace util;

void FileFunc()
{
	string infilepath = "C:/Users/phs0710/Documents/test/test.csv";
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

	string outfilepath = "C:/Users/phs0710/Documents/test/test_out.csv";

	CSVUtil::WriteFile(outfilepath, dataframe);

	int x = 0;
}

void Calc_Statistic()
{
	vector<double> vec;
	vec.push_back(2.3);
	vec.push_back(1.7);
	vec.push_back(1.4);
	vec.push_back(0.7);
	vec.push_back(1.9);

	double dval = math::Statistic<double>::Mean(vec);
	double dvar = math::Statistic<double>::Variance(vec);
	double dstv = math::Statistic<double>::StandartDeviation(vec);

	int x = 0;
}

int main()
{
	FileFunc();
	string filepath = "python C:/Users/phaes/Documents/Haafor/Python/Haafor/ex_graph.py";
	CMDUtil::ExcuteCommand(filepath);
	Calc_Statistic();
    
	return 0;
}