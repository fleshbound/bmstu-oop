#pragma once

#include <cstdio>
#include <exception>
#include <source_location>

#include <ctime>
#include <utility>

constexpr auto ERROR_MSG_BUFFER_SIZE = 512;

class BaseException: public std::exception 
{
public:
    BaseException(
        const char *filename, 
        const char *funcname, 
        const int line,
        const char *time, 
        const char *info = "Exception!")
    {
        snprintf(msg, sizeof(msg) + 1, "\nIn file: %s, in function: %s, at line: %d, at: %s\nOccured: %s",
                 filename, funcname, line, time, info);
    }

    virtual const char *what() const noexcept override 
    {
        return msg;
    }

private:
    static constexpr size_t sizeBuf = ERROR_MSG_BUFFER_SIZE;
    char msg[sizeBuf]{};
};