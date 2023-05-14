#pragma once

#include "BaseError.h"

class VectorError : public BaseError
{
public:
	VectorError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errinfo)
        : BaseError(filename, funcname, line, time, errinfo)
    {}
};

class VectorZeroDivisionError : public VectorError
{
public:
    VectorZeroDivisionError(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *errinfo = "Division by zero!")
        : VectorError(filename, funcname, line, time, errinfo)
    {}
};

class VectorMemoryError : public VectorError
{
public:
    VectorMemoryError(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* errinfo = "Vector memory allocation error!")
        : VectorError(filename, funcname, line, time, errinfo)
    {}
}; 

class VectorNotEqualSizeError : public VectorError
{
public:
    VectorNotEqualSizeError(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* errinfo = "Vectors have not equal sizes!")
        : VectorError(filename, funcname, line, time, errinfo)
    {}
};

class VectorEmptyError : public VectorError
{
public:
    VectorEmptyError(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* errinfo = "The size of the vector must be greater than zero!")
        : VectorError(filename, funcname, line, time, errinfo)
    {}
};

class VectorCopyError : public VectorError
{
public:
    VectorCopyError(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* errinfo = "Copy source vector is invalid!")
        : VectorError(filename, funcname, line, time, errinfo)
    {}
};
