#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <ranges>

#include "BaseVector.h"
#include "../Concepts/VectorConcepts.h"

template <typename T>
class Iterator;

template <typename T>
class ConstIterator;

template <VectorType T>
class Vector: public BaseVector
{
    friend class Iterator<T>;
    friend class ConstIterator<T>;

public:
	/* Aliases */
    using value_type = T;
    using size_type = size_t;
    using iterator = Iterator<T>;
    using const_interator = ConstIterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using difference_type = typename iterator::difference_type;
    using reference = typename iterator::reference;
    using const_reference = typename const_iterator::reference;
    using pointer = typename iterator::pointer;
    using const_pointer = typename const_iterator::pointer;
    
	/* Constructors */

    Vector() = default;
    explicit Vector(const size_t dim);

    explicit Vector(const Vector<T> &other);
    Vector(Vector<T> &&other) noexcept;

    template<VectorType U>
	explicit Vector(const Vector<U> &other) requires FriendlyVectorType<T, U>;

    template<typename Container> requires FriendlyContainer<T, Container>
    explicit Vector(const Container &other);

	Vector(T *array, const size_t dim);

	template <std::input_iterator Iter, std::sentinel_for<Iter> Iter_e>
		requires std::constructible_from<T, typename std::iterator_traits<Iter>::reference>
	Vector(const Iter begin, const Iter_e end);
	
	explicit Vector(FriendlyRange auto range);
	
	Vector(std::initializer_list<T> list);

	/* Assignment */

	Vector<T>& operator =(const Vector<T> &other);
	Vector<T>& operator =(Vector<T> &&other) noexcept;
	Vector<T>& operator =(std::initializer_list<T> list);

	template<VectorType U>
	Vector<T>& operator =(const Vector<U> &other) requires FriendlyVectorType<T, U>;

	template<typename Container> requires FriendlyContainer<T, Container>
	Vector<T>& operator =(const Container &other);

	// +
	template<typename U> requires VectorSumRequires<T, U>
	Vector<T>& operator +=(const Vector<U> &other);

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T>& operator +=(const U &value);

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T>& sum_vector(const Vector<U> &other);

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T>& sum_value(const U &value);

	// -
	template<typename U> requires VectorSubRequires<T, U>
	Vector<T>& operator -=(const Vector<U> &other);

	template<typename U> requires VectorSubRequires<T, U>
	Vector<T>& operator -=(const U &value);

	template<typename U> requires VectorSubRequires<T, U>
	Vector<T>& sub_vector(const Vector<U> &other);

	template<typename U> requires VectorSubRequires<T, U>
	Vector<T>& sub_value(const U &value);

	// *
	template<typename U> requires VectorMulRequires<T, U>
	Vector<T>& operator *=(const Vector<U> &other);

	template<typename U> requires VectorMulRequires<T, U>
	Vector<T>& operator *=(const U &value);

	template<typename U> requires VectorMulRequires<T, U>
	Vector<T>& mul_vector(const Vector<U> &other);

	template<typename U> requires VectorMulRequires<T, U>
	Vector<T>& mul_value(const U &value);

	// /
	template<typename U> requires VectorDivRequires<T, U>
	Vector<T>& operator /=(const Vector<U> &other);

	template<typename U> requires VectorDivRequires<T, U>
	Vector<T>& operator /=(const U &value);

	template<typename U> requires VectorDivRequires<T, U>
	Vector<T>& div_vector(const Vector<U> &other);

	template<typename U> requires VectorDivRequires<T, U>
	Vector<T>& div_value(const U &value);

	/* Equality */

	template<typename U> requires VectorEqualityRequires<U>
	bool operator ==(const Vector<U> &other) const;

	template<typename U> requires VectorEqualityRequires<U>
	bool operator !=(const Vector<U> &other) const;

	template<typename U> requires VectorEqualityRequires<U>
	bool equality(const Vector<U> &other) const;

	/* Sum */

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator +(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator +(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> sum_vector(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> sum_value(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	friend Vector<T> operator +(const U &value, const Vector<T> &vector);

	/* Sub */

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator -(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator -(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> sub_vector(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> sub_value(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	friend Vector<T> operator -(const U &value, const Vector<T> &vector);

	/* Mul */

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator *(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator *(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> mul_vector(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> mul_value(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	friend Vector<T> operator *(const U &value, const Vector<T> &vector);

	/* Div */

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator /(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> operator /(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> div_vector(const Vector<U> &other) const;

	template<typename U> requires VectorSumRequires<T, U>
	Vector<T> div_value(const U &value) const;

	template<typename U> requires VectorSumRequires<T, U>
	friend Vector<T> operator /(const U &value, const Vector<T> &vector);


	/* Destructor */

    ~Vector() noexcept = default;

    
private:
    std::shared_ptr<T[]> _coordinates = nullptr;
	
	Vector<T> &_realloc_coordinates();
	Vector<T> &_check_source_pointer(T *pointer);
	Vector<T> &_copy_coordinates_from_range(auto &range);
};