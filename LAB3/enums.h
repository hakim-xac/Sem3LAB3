#pragma once
namespace LAB3 {
	enum class Keys {
		Exit = 48									// Key 0, Выход
		, PrintArray = 49							// Key 1, Распечатать массив
		, PrintHashTableDirectBinding = 50			// Key 2, Распечатать хеш-таблицу (метод ПРЯМОГО СВЯЗЫВАНИЯ)
		, PrintHashTableOpenAddressing = 51			// Key 3, Распечатать хеш-таблицу (метод ОТКРЫТОЙ АДРЕСАЦИИ)
		, SearchNumber = 52							// Key 4, Поиск числа в хеш-таблице
		, UpdateArrayAndHashTable = 53				// Key 5, Очистить массив и хеш таблицу
		, ResizeArray = 54							// Key 6, Изменить размер массива и пересоздать хеш-таблицу
		, EmptyKey = -1
	};

	enum class isVisibleClear {
		ON
		, OFF
	};

}




