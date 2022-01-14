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
		void generateHashTableOpenAdressingLineType(Iter begin, Iter end);

		template <class Iter>
		bool generateHashTableOpenAdressingQuadType(Iter begin, Iter end);
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
::generateHashTableOpenAdressingLineType(Iter begin, Iter end)
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
	size_t cnt{};
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		auto hs{ this->hashFunc(*it) };	
		auto copyHs{ hs };
		auto itHs{std::next(it, hs)};
		++cnt;

		/// TODO
	}
}


template <class Type>
template <class Iter>
bool LAB3::MyHashOpenAdressing<Type>
::generateHashTableOpenAdressingQuadType(Iter begin, Iter end)
{
	size_t size{ hash.size() };
	hash.clear();
	hash.resize(size);
	auto arrayLength{ std::distance(begin, end) };
	size_t collision{};
	auto hs{ *begin };
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		hs = this->hashFunc(*it);
		size_t d{ 1 };
		for (;;)
		{
			if (hash.at(hs) == *it) break;
			if (hash.at(hs) == 0)
			{
				hash[hs] = *it;
				break;
			}
			if (d >= arrayLength)
			{
				return true;
			}
			++collision;
			hs += d;
			if (hs >= size) hs -= size;
			++d;
		}
		/// TODO
	}
	return false;
}



/*

  int i;
  for (i = 0; i < m; i++)
	table[i] = 0;
  collisions = 0;
  int h, h0, g;
  for (i = 0; i < n; i++) {
	h = HashF(a[i]);
	h0 = h;
	g = 1;
	while (1) {
	  if (table[h] == a[i])
		break;
	  if (table[h] == 0) {
		table[h] = a[i];
		break;
	  }
	  if (g >= m) {
		overflow = true;
		return;
	  }
	  collisions++;
	  h = h0 + g;
	  if (h >= m)
		h -= m;
	  g++;
	}
  }
  overflow = false;
*/