#pragma once
namespace LAB3 {
	enum class Keys {
		Exit = 48										// Key 0, Выход
		, PrintArray = 49								// Key 1, Распечатать массив
		, PrintHashTableDirectBinding = 50				// Key 2, Распечатать хеш-таблицу (метод ПРЯМОГО СВЯЗЫВАНИЯ)
		, PrintHashTableOpenAddressingLineType = 51		// Key 3, Распечатать хеш-таблицу (метод ОТКРЫТОЙ АДРЕСАЦИИ, для разрешений коллизий использованы линейные пробы)
		, PrintHashTableOpenAddressingQuadType = 52		// Key 4, Распечатать хеш-таблицу (метод ОТКРЫТОЙ АДРЕСАЦИИ, для разрешений коллизий использованы квадратичные пробы)
		, SearchNumber = 53								// Key 5, Поиск числа в хеш-таблице
		, UpdateArrayAndHashTable = 54 					// Key 6, Очистить массив и хеш таблицу
		, ResizeArray = 55								// Key 7, Изменить размер массива и пересоздать хеш-таблицу
		, EmptyKey = -1
	};

	enum class isVisibleClear {
		ON
		, OFF
	};

}




