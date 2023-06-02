#pragma once

#include <cstddef>
#include "../Exception/VectorException.h"

class BaseVector
{
public:
	explicit BaseVector(size_t dim): _dim(dim) {};
	virtual ~BaseVector() = default;
	virtual bool empty() = 0;
    virtual size_t get_dim() const = 0;
    
protected:
	void _check_empty() const
	{
		if (this->_dim == 0)
		{
			time_t curTime = time(nullptr);
			auto curLoc = std::source_location::current();

			throw VectorEmptyException(
				curLoc.file_name(),
				curLoc.function_name(),
				__LINE__,
				ctime(&curTime)
			);
		}
	};

	void _check_source_params(size_t dim)
	{
		if (this->_dim != dim)
		{
			time_t curTime = time(nullptr);
			auto curLoc = std::source_location::current();

			throw VectorSourceParamsException(
				curLoc.file_name(),
				curLoc.function_name(),
				__LINE__,
				ctime(&curTime)
			);
		}
	};

    size_t _dim = 0;
};