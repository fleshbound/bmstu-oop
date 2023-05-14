#pragma once

#include "BaseError.h"

class IteratorError : public BaseError
{
public:
	IteratorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errinfo)
        : BaseError(filename, funcname, line, time, errinfo)
    {}
};

class OutOfRangeIteratorError : public IteratorError
{
public:
    OutOfRangeIteratorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errinfo = "Pointer access is out of range!")
        : IteratorError(filename, funcname, line, time, errinfo)
    {}
};

class ExpiredIteratorError : public IteratorError
{
    ExpiredIteratorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errinfo = "Pointer is expired!")
        : IteratorError(filename, funcname, line, time, errinfo)
    {}
};
