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
		Type hashFunc(Type value)
		{
			return value % hash.size();
		};

	public:
		MyHashDirectBinding(size_t size)
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


		void resize(size_t newSize)
		{
			hash.resize(newSize);
		}


		void clear()
		{
			size_t size{ hash.size() };
			hash.clear();
			hash.resize(size);
		}


		bool find(Type n)
		{
			for (auto it{ hash.begin() }, ite{ hash.end() }; it != ite; ++it)
			{
				if (std::find((*it).begin(), (*it).end(), n) != (*it).end()) return true;
			}
			return false;
		}


		template <class Iter>
		void generateHashTableDirectBinding(Iter begin, Iter end)
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

