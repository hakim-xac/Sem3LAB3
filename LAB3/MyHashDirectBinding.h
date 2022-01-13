#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

namespace LAB3 {

	template <class Type>
	class MyHashDirectBinding
	{
		std::vector <std::list<Type>> hash;
		MyHashDirectBinding() = delete;
	private:
		Type hashFunc(Type value);

	public:
		MyHashDirectBinding(size_t size);

		auto begin();
		auto end();

		size_t getSize();

		void resize(size_t newSize);
		void clear();
		bool find(Type n);

		template <class Iter>
		void generateHashTableDirectBinding(Iter begin, Iter end);

	};
}



/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/





template <class Type>
LAB3::MyHashDirectBinding<Type>
::MyHashDirectBinding(size_t size)
: hash(size, std::list<Type>()) {}


template <class Type>
Type LAB3::MyHashDirectBinding<Type>
::hashFunc(Type value)
{
	return value % hash.size();
}


template <class Type>
auto LAB3::MyHashDirectBinding<Type>
::begin()
{
	return hash.begin();
}


template <class Type>
auto LAB3::MyHashDirectBinding<Type>
::end()
{
	return hash.end();
}


template <class Type>
size_t LAB3::MyHashDirectBinding<Type>
::getSize()
{
	return hash.size();
}


template <class Type>
void LAB3::MyHashDirectBinding<Type>
::resize(size_t newSize)
{
	hash.resize(newSize);
}


template <class Type>
void LAB3::MyHashDirectBinding<Type>
::clear()
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
}


template <class Type>
bool LAB3::MyHashDirectBinding<Type>
::find(Type n)
{
	for (auto it{ hash.begin() }, ite{ hash.end() }; it != ite; ++it)
	{
		if (std::find((*it).begin(), (*it).end(), n) != (*it).end()) return true;
	}
	return false;
}


template <class Type>
template <class Iter>
void LAB3::MyHashDirectBinding<Type>
::generateHashTableDirectBinding(Iter begin, Iter end)
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		auto hs{ this->hashFunc(*it) };
		hash[hs].push_back(*it);
	}
}