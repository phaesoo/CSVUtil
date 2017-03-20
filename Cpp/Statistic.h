#pragma once

#include <vector>
#include <numeric>
#include <cmath>

namespace math
{
	template<typename T>
	class Statistic
	{
	public:
		Statistic() = delete;

		static double Mean(const std::vector<T>& vals);
		static double Variance(const std::vector<T>& vals, bool isPopulation=false);
		static double StandartDeviation(const std::vector<T>& vals, bool isPopulation=false);
	};

	template<typename T>
	double Statistic<T>::Mean(const std::vector<T>& vals)
	{
		size_t size = vals.size();
		if (size < 1) { return 0.0; }

		double sum = 0.0;
		for (size_t i = 0; i < size; ++i)
		{
			sum += vals[i];
		}

		return sum / size;
	}

	template<typename T>
	double Statistic<T>::Variance(const std::vector<T>& vals, bool isPopulation=false)
	{
        size_t size = vals.size();
		if (size < 2) { return 0.0; } // 데이터 1개이하의 분산 의미 없음

		double mean = Mean(vals);

		double sum = 0.0;
		for (size_t i = 0; i < size; ++i)
		{
			sum += std::pow(vals[i] - mean, 2.0);
		}

		// 모분산이 아닐경우(표본)
		if (!isPopulation)
		{
			size = size - 1;
		}

		return sum / size;
	}

	template<typename T>
	double Statistic<T>::StandartDeviation(const std::vector<T>& vals, bool isPopulation=false)
	{
		return sqrt(Variance(vals, isPopulation));
	}
};