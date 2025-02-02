﻿#ifndef _FE_CORE_FARRAY_HXX_
#define _FE_CORE_FARRAY_HXX_
/*
Copyright © from 2022 to present, UNKNOWN STRYKER. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include <FE/prerequisites.h>
#include <FE/iterator.hxx>

// std
#include <array>




BEGIN_NAMESPACE(FE)

/*
The FE::farray class template is a fixed-size array container that extends std::array
providing additional functionalities such as dynamic element addition and iterator support while maintaining a specified capacity.
*/
template <typename T, size Capacity>
class farray : public std::array<T, Capacity>
{
public:
	using base_type = std::array<T, Capacity>;
	using value_type = typename base_type::value_type;
	using size_type = typename base_type::size_type;
	using difference_type = typename base_type::difference_type;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const pointer;
	using iterator = FE::iterator<FE::contiguous_iterator<T>>;
	using const_iterator = FE::const_iterator<FE::contiguous_iterator<T>>;
	using reverse_iterator = FE::reverse_iterator<FE::contiguous_iterator<T>>;
	using const_reverse_iterator = FE::const_reverse_iterator<FE::contiguous_iterator<T>>;

private:
	size_type m_array_size = 0;
	
public:
	_FE_FORCE_INLINE_ void push_back(T&& value_p) noexcept
	{
		FE_NEGATIVE_ASSERT(this->m_array_size == Capacity, "${%s@0}: FE::farray is out of capacity. Unable to push an element to the back of the container.");

		base_type::operator[](this->m_array_size) = std::move(value_p);
		++this->m_array_size;
	}

	_FE_FORCE_INLINE_ void push_back(const T& value_p) noexcept
	{
		FE_NEGATIVE_ASSERT(this->m_array_size == Capacity, "${%s@0}: FE::farray is out of capacity. Unable to push an element to the back of the container.");

		base_type::operator[](this->m_array_size) = value_p;
		++this->m_array_size;
	}

	template<typename... Arguments>
	_FE_FORCE_INLINE_ reference emplace_back(Arguments&&... arguments_p) noexcept
	{
		FE_NEGATIVE_ASSERT(this->m_array_size == Capacity, "${%s@0}: FE::farray is out of capacity. Unable to emplace an element to the back of the container.");
		this->push_back(std::forward<Arguments&&>(arguments_p)...);
		return this->back();
	}


	_FE_FORCE_INLINE_ void pop_back() noexcept
	{
		FE_NEGATIVE_ASSERT(this->m_array_size == 0, "${%s@0}: Unable to pop an empty FE::farray.");

		--this->m_array_size;
	}


	_FE_FORCE_INLINE_ size_type capacity() const noexcept
	{
		return base_type::size();
	}

	_FE_FORCE_INLINE_ size_type size() const noexcept
	{
		return this->m_array_size;
	}


	_FE_FORCE_INLINE_ reference back() noexcept
	{
		return base_type::operator[](this->m_array_size - 1);
	}

	_FE_FORCE_INLINE_ const_reference back() const noexcept
	{
		return base_type::operator[](this->m_array_size - 1);
	}
	

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ iterator begin() noexcept 
	{
		return iterator{ base_type::begin().operator->() };
	}

	_FE_FORCE_INLINE_ const_iterator cbegin() const noexcept 
	{
		return const_iterator{ base_type::begin().operator->() };
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ iterator end() noexcept 
	{
		return this->begin() + this->m_array_size;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ const_iterator cend() const noexcept 
	{
		return this->cbegin() + this->m_array_size;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ reverse_iterator rbegin() noexcept 
	{
		return (this->begin() + this->m_array_size) - 1;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ const_reverse_iterator rbegin() const noexcept 
	{
		return (this->begin() + this->m_array_size) - 1;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ const_reverse_iterator crbegin() const noexcept 
	{
		return (this->cbegin() + this->m_array_size) - 1;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ reverse_iterator rend() noexcept 
	{
		return this->begin() - 1;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ const_reverse_iterator rend() const noexcept 
	{
		return this->begin() - 1;
	}

	_FE_FORCE_INLINE_ _FE_CONSTEXPR17_ const_reverse_iterator crend() const noexcept 
	{
		return this->cbegin() - 1;
	}
};


END_NAMESPACE
#endif 