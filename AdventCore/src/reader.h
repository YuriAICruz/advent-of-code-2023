#pragma once
#include <iostream>
#include <fstream>
#include "config.h"

namespace core
{
    class CORE_API reader
    {
    public:
        explicit reader(const char* file_path);
        ~reader();
        bool getNextLine(std::string& result);
        void reset();
    };
}
