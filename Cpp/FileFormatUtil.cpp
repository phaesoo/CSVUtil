#include "FileFormatUtil.h"

#include <assert.h>

using namespace util;
using std::string;

bool FileFormatUtil::ValidateFileFormat(const std::string& filepath, Format format)
{
	string ext = "";
	if (!GetExtension(format, ext))
	{
		assert(0);
		return false;
	}

	// csv파일인지 검사
	if (filepath.substr(filepath.find_last_of(".") + 1) == ext)
	{
		return true;
	}

	assert(0);
	return false;
}

bool FileFormatUtil::GetExtension(Format format, string& ext)
{
	ext.clear();

	switch (format)
	{
	case csv: ext = "csv"; break;
	default:
        assert(0);
		return false;
	}

	return true;
}