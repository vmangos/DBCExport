#ifndef MANGOS_UTILITY_H
#define MANGOS_UTILITY_H

#include <cstring>
#include <iostream>
#include "Database\Database.h"

inline uint32 GetUInt32()
{
    uint32 value = 0;
    scanf_s("%u", &value);
    return value;
}

inline char GetChar()
{
    fseek(stdin, 0, SEEK_END);
    char const chr = getchar();
    fseek(stdin, 0, SEEK_END);
    return chr;
}

inline std::string GetString(std::string defaultText)
{
    std::string text;
    fseek(stdin, 0, SEEK_END);
    getline(std::cin, text);
    fseek(stdin, 0, SEEK_END);
    if (text.empty())
        return defaultText;
    return text;
}

inline std::string EscapeString(char* unescapedString)
{
    char* escapedString = new char[strlen(unescapedString) * 2 + 1];
    mysql_escape_string(escapedString, unescapedString, strlen(unescapedString));
    std::string returnString = escapedString;
    delete[] escapedString;
    return returnString;
}

inline std::string EscapeString(std::string unescapedString)
{
    char* escapedString = new char[unescapedString.length() * 2 + 1];
    mysql_escape_string(escapedString, unescapedString.c_str(), unescapedString.length());
    std::string returnString = escapedString;
    delete[] escapedString;
    return returnString;
}

inline std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace)
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

inline void CopyStringArrays(char const* const src[], char* dst[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dst[i] = strdup(src[i]);
    }
}

inline bool CompareStringArrays(char const* const strings1[], char const* const strings2[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(strings1[i], strings2[i]) != 0)
            return false;
    }
    return true;
}

#endif