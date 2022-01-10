#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

namespace LAB3 {

	template <class Type>
	class MyHash
	{
		std::vector <std::list<Type>> hash;
		MyHash() = delete;
	private:
		Type hashFunc(Type value)
		{
			return value % hash.size();
		};

	public:
		MyHash(size_t size)
		: hash(size, std::list<Type>()) {}


		auto begin()		{	return hash.begin();	 }
		auto end()			{	return hash.end();		 }
		auto cbegin()		{	return hash.cbegin();	 }
		auto cend()			{	return hash.cend();		 }
		auto rbegin()		{	return hash.rbegin();	 }
		auto rend()			{	return hash.rend();		 }
		auto crbegin()		{	return hash.crbegin();	 }
		auto crend()		{	return hash.crend();	 }


		size_t getSize()	{	return hash.size();		 }


		template <class Iter>
		void generateHashTable(Iter begin, Iter end)
		{
			size_t size{ hash.size() };
			hash.clear();
			hash.resize(size);
			for (auto it{ begin }, ite{ end }; it != ite; ++it) {
				auto hs{ this->hashFunc(*it) };
				hash[hs].push_back(*it);
			}
		}

	};
}
