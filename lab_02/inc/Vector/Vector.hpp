#pragma once

#include <algorithm>
#include <concepts>
#include <numeric>
#include <ranges>

#include "Vector.h"
#include "../Exception/VectorException.h"

template<VectorType T>
inline Vector<T>& Vector<T>::_check_source_pointer(T* pointer)
{
	// TODO: insert return statement here
}

template<VectorType T>
Vector<T>::Vector(const size_t dim): BaseVector(dim)
{
	if (dim == 0)
	{
		time_t curTime = time(nullptr);
		auto curLoc = std::source_location::current();

		throw VectorZeroDimException(
			curLoc.file_name(),
			curLoc.function_name(),
			__LINE__,
			ctime(&curTime)
		);
	}

	this->_realloc_coordinates();
}


template<VectorType T>
Vector<T>::Vector(const Vector<T> &other): BaseVector(other._dim)
{
	this->_realloc_coordinates();
	std::ranges::copy(other.begin(), other.end(), (*this).begin());
}

template<VectorType T>
Vector<T>::Vector(Vector<T> &&other) noexcept: BaseVector(other._dim)
{
	this->_coordinates = other._coordinates;
}

template<VectorType T>
template<VectorType U>
Vector<T>::Vector(const Vector<U> &other) requires FriendlyVectorType<T, U>: BaseVector(other._dim)
{
	this->_realloc_coordinates();
	std::ranges::copy(other.begin(), other.end(), (*this).begin());
}

template<VectorType T>
template<typename Container>
requires FriendlyContainer<T, Container>
Vector<T>::Vector(const Container &other): BaseVector(other.get_dim())
{
	this->_realloc_coordinates();
	std::ranges::copy(std::begin(other), std::end(other), this->begin());
}

template<VectorType T>
Vector<T>::Vector(T *array, const size_t dim): BaseVector(dim)
{
	this->_check_source_pointer(array);
	this->_realloc_coordinates();
	
	size_t i = 0;

	for (auto &el: *this)
		el = array[i];
}

template<VectorType T>
template <std::input_iterator Iter, std::sentinel_for<Iter> Iter_e>
requires std::constructible_from<T, typename std::iterator_traits<Iter>::reference>
Vector<T>::Vector(const Iter begin, const Iter_e end): BaseVector()
{
	size_t dim = 0;

	for (auto iter = begin; iter != end; iter++, dim++);

	if (dim == 0)
	{
		time_t curTime = time(nullptr);
		auto curLoc = std::source_location::current();

		throw VectorZeroDimException(
			curLoc.file_name(),
			curLoc.function_name(),
			__LINE__,
			ctime(&curTime)
		);
	}

	this->_dim = dim;
	this->_realloc_coordinates();
	std::ranges::copy(begin, end, this->begin());
}

template<VectorType T>
Vector<T>::Vector(FriendlyRange auto range): BaseVector()
{
	size_t dim = 0;

	for (auto iter = std::begin(range); iter != std::end(range); iter++, dim++);

	if (dim == 0)
	{
		time_t curTime = time(nullptr);
		auto curLoc = std::source_location::current();

		throw VectorZeroDimException(
			curLoc.file_name(),
			curLoc.function_name(),
			__LINE__,
			ctime(&curTime)
		);
	}

	this->_dim = dim;
	this->_realloc_coordinates();
	std::ranges(std::begin(range), std::end(range), this->begin());
}

template<VectorType T>
Vector<T>::Vector(std::initializer_list<T> list): BaseVector(list.size())
{
	this->_realloc_coordinates();

	size_t i = 0;

	this->_copy_coordinates_from_range(list);
}



template<VectorType T>
Vector<T> &Vector<T>::_realloc_coordinates()
{
	try
	{
		this->_coordinates.reset(new T[this->_dim]);
	}
	catch (std::bad_alloc)
	{
		time_t curTime = time(nullptr);
		auto curLoc = std::source_location::current();

		throw VectorAllocException(
			curLoc.file_name(),
			curLoc.function_name(),
			__LINE__,
			ctime(&curTime)
		);
	}

	return *this;
}

template<VectorType T>
Vector<T> &_check_source_pointer(T *pointer)
{
	if (pointer == nullptr)
	{
		time_t curTime = time(nullptr);
		auto curLoc = std::source_location::current();

		throw VectorNullptrSourceException(
			curLoc.file_name(),
			curLoc.function_name(),
			__LINE__,
			ctime(&curTime)
		);
	}
}

template<VectorType T>
Vector<T> &_copy_coordinates_from_range(auto &range)
{
	auto this_iter = this->begin();

	for (auto &iter: range)
	{
		std::ranges::copy(iter, this_iter);
		this_iter++;
	}

	return *this;
}

