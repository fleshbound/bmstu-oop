#pragma once

#include <cstdio>
#include <exception>
#include <source_location>

#include <ctime>
#include <utility>

#define ERROR_MSG_BUFFER_SIZE 512

class BaseError : public std::exception 
{
public:
    BaseError(
        const char *filename, 
        const char *funcname, 
        const int line,
        const char *time, 
        const char *errinfo = "Error!")
    {
        snprintf(msg, sizeof(msg) + 1, "\nIn file: %s, in function: %s, at line: %d, at: %s\nOccured: %s",
                 filename, funcname, line, time, errinfo);
    }

    virtual const char *what() const noexcept override 
    {
        return msg;
    }

private:
    static constexpr size_t sizeBuf = ERROR_MSG_BUFFER_SIZE;
    char msg[sizeBuf]{};
};