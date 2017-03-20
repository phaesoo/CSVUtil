#pragma once

#include <string>
#include <vector>

namespace util
{
    class CSVUtil
    {
    public:
        typedef std::vector< std::vector<std::string> > DataFrame;

    public:
        CSVUtil() = delete;

        static bool ReadFile(const std::string& filepath, DataFrame& dataList);
        static bool WriteFile(const std::string& filepath, const DataFrame& dataList);

    public:
        static const char g_token = ","[0];
    };
}
