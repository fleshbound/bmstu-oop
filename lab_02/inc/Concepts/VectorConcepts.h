#pragma once

#include <concepts>
#include <iterator>

template<typename T>
concept	VectorType = requires
{
	std::semiregular<T>;
};

template<typename T, typename U>
concept	FriendlyVectorType = requires
{
	std::constructible_from<U, T>;
};

template<typename T>
concept FriendlyRange = requires(T &u)
{
	{ u.begin() } -> std::input_iterator;
	{ u.end() } -> std::sentinel_for<decltype(u.begin())>;
	std::constructible_from<T, typename std::iterator_traits<decltype(u.begin())>::reference>;
};

template<typename T, typename U>
concept	FriendlyContainer = requires(U &u)
{
	FriendlyRange<U>;

	{ u.empty() } noexcept -> std::same_as<bool>;
	{ u.get_dim() } noexcept -> std::same_as<typename T::size_type>;
};

template<typename T>
concept VectorEqualityRequires = requires
{
	VectorType<T>;
	std::equality_comparable<T>;
};

template<typename T, typename U>
concept VectorSumRequires = requires (T a, U b)
{
	FriendlyVectorType<T, U>;
	{ a + b } -> std::convertible_to<T>;
};

template<typename T, typename U>
concept VectorMulRequires = requires (T a, U b)
{
	FriendlyVectorType<T, U>;
	{ a * b } -> std::convertible_to<T>;
};

template<typename T, typename U>
concept VectorSubRequires = requires (T a, U b)
{
	FriendlyVectorType<T, U>;
	{ a - b } -> std::convertible_to<T>;
};

template<typename T>
concept VectorOnlyFloatPointingRequires = requires 
{
	std::floating_point<T>;
};

template<typename T, typename U>
concept VectorDivRequires = requires(T a, U b) 
{
	VectorOnlyFloatPointingRequires<T>;
	VectorOnlyFloatPointingRequires<U>;
	{ a / b } -> std::convertible_to<T>;
};

template<VectorType T>
class Vector;