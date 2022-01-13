#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

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
		template <class Iter>
		void generateHashTableOpenAdressing(Iter begin, Iter end);
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


template <class Type>
template <class Iter>
void LAB3::MyHashOpenAdressing<Type>
::generateHashTableOpenAdressing(Iter begin, Iter end)
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		auto hs{ this->hashFunc(*it) };
		size_t d{ 1 };
		/// TODO
	}
}