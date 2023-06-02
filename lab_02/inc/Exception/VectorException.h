#pragma once

#include "BaseException.h"

class VectorException: public BaseException
{
public:
	VectorException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *info)
        : BaseException(filename, funcname, line, time, info)
    {};
};

class VectorZeroDivisionException: public VectorException
{
public:
    VectorZeroDivisionException(
        const char *filename,
        const char *funcname,
        const int line,
        const char *time,
        const char *info = "Division by zero!")
        : VectorException(filename, funcname, line, time, info)
    {};
};

class VectorSourceParamsException: public VectorException
{
public:
	VectorSourceParamsException(
		const char* filename,
		const char* funcname,
		const int line,
		const char* time,
		const char* info = "Incorrect source parameters!")
		: VectorException(filename, funcname, line, time, info)
	{};
};

class VectorAllocException: public VectorException
{
public:
	VectorAllocException(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* info = "Vector memory allocation error!")
        : VectorException(filename, funcname, line, time, info)
    {};
}; 

class VectorNotEqualDimException: public VectorException
{
public:
	VectorNotEqualDimException(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* info = "Numbers of dimensions of the vectors are not equal!")
        : VectorException(filename, funcname, line, time, info)
    {};
};

class VectorZeroDimException: public VectorException
{
public:
	VectorZeroDimException(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* info = "Number of dimensions must be greater than zero!")
        : VectorException(filename, funcname, line, time, info)
    {};
};

class VectorEmptyException: public VectorException
{
public:
	VectorEmptyException(
		const char* filename,
		const char* funcname,
		const int line,
		const char* time,
		const char* info = "Current vector is empty!")
		: VectorException(filename, funcname, line, time, info)
	{};
};

class VectorNullptrSourceException: public VectorException
{
public:
	VectorNullptrSourceException(
        const char* filename,
        const char* funcname,
        const int line,
        const char* time,
        const char* info = "Source pointer is null!")
        : VectorException(filename, funcname, line, time, info)
    {};
};
