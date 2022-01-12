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
		Type hashFunc(Type value)
		{
			return value % hash.size();
		};

	public:
		MyHashOpenAdressing(size_t size)
			: hash(size, Type()) {}


		auto begin() { return hash.begin(); }
		auto end() { return hash.end(); }
		auto cbegin() { return hash.cbegin(); }
		auto cend() { return hash.cend(); }
		auto rbegin() { return hash.rbegin(); }
		auto rend() { return hash.rend(); }
		auto crbegin() { return hash.crbegin(); }
		auto crend() { return hash.crend(); }


		size_t getSize() { return hash.size(); }


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




		template <class Iter>
		void generateHashTableOpenAdressing(Iter begin, Iter end)
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
	};
}

