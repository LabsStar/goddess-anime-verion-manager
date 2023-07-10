#include "Converter.h"

std::string Converter::charToString(const char* cString)
{
    if (cString == nullptr)
        return "";

    return std::string(cString);
}
