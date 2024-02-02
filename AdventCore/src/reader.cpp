#include "reader.h"
#include <string>

#ifdef  _DEBUG
#include <direct.h>
#endif

namespace core
{
    std::ifstream _file;

    reader::reader(const char* file_path)
    {
        _file.open(file_path);

#ifdef _DEBUG
        char tuh[_MAX_PATH];
        char* abc;
        abc = _getcwd(tuh, sizeof(tuh));
        std::string str = abc;
        std::string path = file_path;
        OutputDebugString(L"Opening File in path: ");
        OutputDebugString(std::wstring(str.begin(), str.end()).c_str());
        OutputDebugString(L"\\");
        OutputDebugString(std::wstring(path.begin(), path.end()).c_str());
        OutputDebugString(L"\n");
#endif
    }

    reader::~reader()
    {
        if (_file.is_open())
        {
            _file.close();
        }
    }

    bool reader::getNextLine(std::string& result)
    {
        if (std::getline(_file, result))
        {
            return true;
        }

        return false;
    }

    void reader::reset()
    {
        _file.clear();
        _file.seekg(0);
    }
}
