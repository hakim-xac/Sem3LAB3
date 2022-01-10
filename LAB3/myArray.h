#pragma once
#include <vector>
#include <ctime>
#include <algorithm>

namespace LAB3 {

	template<class Type>
	class myArray
	{
	private:
		std::vector <Type> array;
		myArray() = delete;
	public:
		myArray(size_t size)
		: array(size)	{}

		/*
		* Задаем итераторы
		*/
		auto begin()		{	return array.begin();	}
		auto end()			{	return array.end();		}
		auto cbegin()		{	return array.cbegin();	}
		auto cend()			{	return array.cend();	}
		auto rbegin()		{	return array.rbegin();	}
		auto rend()			{	return array.rend();	}
		auto crbegin()		{	return array.crbegin();	}
		auto crend()		{	return array.crend();	}


		size_t getSize()	{	return array.size();	}

		void createRandom()
		{
			/*
			*	Создает массив со случайными значениями в диапазоне [0, max(type<int>)) <-(псевдокод)
			*/
			srand(static_cast<unsigned int>(time(0)));
			std::for_each(array.begin(), array.end(), [](Type& item) {
				item = rand() % std::numeric_limits<Type>::max();
				});
		}
	};
}
