#pragma once

#include <string>

namespace util
{
    class FileFormatUtil
    {
    public:
        enum Format : int
        {
            None = -1,
            csv,
        };

    public:
        FileFormatUtil() = delete;

        static bool ValidateFileFormat(const std::string& filepath, Format format);

    private:
        static bool GetExtension(Format format, std::string& ext);
    };
}
