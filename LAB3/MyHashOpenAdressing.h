#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "enums.h"

namespace LAB3 {

	template <class Type>
	class MyHashOpenAdressing
	{
		std::vector <Type> hash;
		MyHashOpenAdressing() = delete;
	private:

		Type hashFunc(Type value);

	public:
		MyHashOpenAdressing(size_t size);

		auto begin();
		auto end();

		size_t getSize();

		void resize(size_t newSize);
		void clear();

		bool find(const Type& item, TypeOpenAdressing typeOpen);

		template <class Iter>
		std::pair<size_t, bool> generateHashTableOpenAdressing(Iter begin, Iter end, TypeOpenAdressing typeOpen);
	};
}




/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/





template <class Type>
Type LAB3::MyHashOpenAdressing<Type>
::hashFunc(Type value)
{
	return value % hash.size();
}


template <class Type>
LAB3::MyHashOpenAdressing<Type>
::MyHashOpenAdressing(size_t size)
	: hash(size, Type{}) {}



template <class Type>
auto LAB3::MyHashOpenAdressing<Type>
::begin()
{
	return hash.begin();
}


template <class Type>
auto LAB3::MyHashOpenAdressing<Type>
::end()
{
	return hash.end();
}


template <class Type>
size_t LAB3::MyHashOpenAdressing<Type>
::getSize()
{
	return hash.size(); 
}


template <class Type>
void LAB3::MyHashOpenAdressing<Type>
::resize(size_t newSize)
{
	hash.resize(newSize);
}


template <class Type>
void LAB3::MyHashOpenAdressing<Type>
::clear()
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
}

template<class Type>
bool LAB3::MyHashOpenAdressing<Type>::find(const Type& item, TypeOpenAdressing typeOpen)
{
	auto hs{ this->hashFunc(item) };
	Type d{ 1 };
	for(;;)
	{
		if (hash.at(hs) == item) return true;
		if (d >= hash.size()) return false;
		hs += d;
		if (hs >= hash.size()) hs -= hash.size();
		d += (typeOpen == TypeOpenAdressing::Line ? 1 : 2);		
	}

}


template <class Type>
template <class Iter>
std::pair<size_t, bool> LAB3::MyHashOpenAdressing<Type>
::generateHashTableOpenAdressing(Iter begin, Iter end, TypeOpenAdressing typeOpen)
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
	auto arrayLength{ std::distance(begin, end) };
	size_t collision{};
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		auto hs{ this->hashFunc(*it) };
		Type d{ 1 };
		for (;;)
		{
			if (hash.at(hs) == *it) break;
			if (hash.at(hs) == 0)
			{
				hash[hs] = *it;
				break;
			}
			if (d >= hash.size())
			{
				return { collision , true};
			}
			++collision;
			hs += d;
			if (hs >= hash.size()) hs -= static_cast<Type>(hash.size());
			d += (typeOpen == TypeOpenAdressing::Line ? 1 : 2);
		}
	}
	return { collision , false };
}
