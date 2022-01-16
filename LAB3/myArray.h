#pragma once
#include <vector>
#include <ctime>
#include <algorithm>

namespace LAB3 {

	template<class Type>
	class MyArray
	{
	private:
		std::vector <Type> array;
		MyArray() = delete;
	public:
		MyArray(size_t size);

		/*
		* Задаем итераторы
		*/
		auto begin();
		auto end();


		size_t getSize();


		void clear();
		void resize(size_t newSize);
		void createRandom();
	};
}



/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



template<class Type>
LAB3::MyArray<Type>
::MyArray(size_t size) : array(size) {}


template<class Type>
auto LAB3::MyArray<Type>
::begin()
{
	return array.begin();
}


template<class Type>
auto LAB3::MyArray<Type>
::end()
{
	return array.end();
}


template<class Type>
size_t LAB3::MyArray<Type>
::getSize()
{
	return array.size();
}


template<class Type>
void LAB3::MyArray<Type>
::clear()
{
	size_t size{ array.size() };
	array.clear();
	array.resize(size);
}


template<class Type>
void LAB3::MyArray<Type>
::resize(size_t newSize)
{
	array.resize(newSize);
}


template<class Type>
void LAB3::MyArray<Type>
::createRandom()
{
	srand(static_cast<unsigned int>(time(0)));
	std::for_each(array.begin(), array.end(), [](Type& item) {
		item = rand() % (std::numeric_limits<Type>::max() - 1 ) + 1;
	});
}