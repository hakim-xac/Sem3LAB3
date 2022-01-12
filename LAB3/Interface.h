#pragma once
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include "enums.h"

namespace LAB3 {

	template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
	class Interface
	{
	/// <summary>
	/// Базовый класс интерфейса
	/// </summary>
	/// <typeparam name="TypeElem">Тип "myType"</typeparam>
	private:
		std::ostream& out				{ std::cout };								// буфер вывода
		size_t maxTableWidth			{ 110 };									// ширина выводимой строки
		int maxTableColumnsInArray		{ 5 };										// количество колонов при выводе массива
		std::queue <std::string> bufferForStatusBar	{};								// очередь для статус бара

		Interface() = delete;														// запрещаем создавать пустой класс

	protected:


		TypeArray myTypeArray;
		TypeHashDirectBinding myTypeHashTableDirectBinding;
		TypeHashOpenAdressing myTypeHashTableOpenAddressin;

		bool flagClearArrayAndHash{ true };


	public:


		Interface(TypeArray& myTypeArray
			, TypeHashDirectBinding& myTypeHashTableDirectBinding
			, TypeHashOpenAdressing& myTypeHashTableOpenAddressin
		)
		: myTypeArray(myTypeArray)
		, myTypeHashTableDirectBinding(myTypeHashTableDirectBinding)
		, myTypeHashTableOpenAddressin(myTypeHashTableOpenAddressin) {}

		Interface(TypeArray&& myTypeArray
			, TypeHashDirectBinding&& myTypeHashTableDirectBinding
			, TypeHashOpenAdressing&& myTypeHashTableOpenAddressin
		)
		: myTypeArray(myTypeArray)
		, myTypeHashTableDirectBinding(myTypeHashTableDirectBinding)
		, myTypeHashTableOpenAddressin(myTypeHashTableOpenAddressin) {}


		/// <summary>
		/// Геттеры некоторых полей
		/// </summary>
		constexpr size_t getMaxTableWidth()			const	{	return maxTableWidth;			}
		constexpr auto getMaxTableColumns()			const	{	return maxTableColumnsInArray;	}
		constexpr bool getFlagClearArrayAndHash()	const	{	return flagClearArrayAndHash;	}

		/// <summary>
		/// сеттеры некоторых полей
		/// </summary>
		void setFlagClearArray(bool flag)				{ flagClearArrayAndHash = flag;		}


		void addToStatusBar(const std::string& str, bool isFormated=true)
		{
			/// <summary>
			/// принимает lvalue строку и отправляет её в очередь статус бара
			/// </summary>
			/// 
			/// <param name="isFormated">Форматировать строки по умолчанию?</param>
			/// 
			if (!isFormated) {
				bufferForStatusBar.emplace(str);
				return;
			}

			bufferForStatusBar.emplace(delimiter());
			bufferForStatusBar.emplace(delimiter(' '));
			bufferForStatusBar.emplace(generatingStrings(str));
			bufferForStatusBar.emplace(delimiter(' '));
			bufferForStatusBar.emplace(delimiter());
		}


		void addToStatusBar(const std::string&& str, bool isFormated=true)
		{
			/// <summary>
			/// принимает rvalue строку и отправляет её в очередь статус бара
			/// </summary>
			/// 
			/// <param name="isFormated">Форматировать строки по умолчанию?</param>
			/// 
			if (!isFormated) {
				bufferForStatusBar.emplace(str);
				return;
			}

			bufferForStatusBar.emplace(delimiter());
			bufferForStatusBar.emplace(delimiter(' '));
			bufferForStatusBar.emplace(generatingStrings(str));
			bufferForStatusBar.emplace(delimiter(' '));
			bufferForStatusBar.emplace(delimiter());
		}


		constexpr void showHeader() 
		{
			/// <summary>
			/// выводит заголовок
			/// </summary>
			std::string header{ generatingStrings("Лабораторная работа № 3", "Изучение возможности хэширования данных для организации поиска. ") };
			std::string header2{ generatingStrings("Группа ПБ-11", "Хакимов А.C.") };

			std::string hr{ delimiter() };

			out << hr;
			out << header;
			out << delimiter('-');
			out << header2;
			out << hr;
		}


		constexpr void showMenu()
		{
			/// <summary>
			/// выводит меню
			/// </summary>
			std::string hr{ delimiter() };

			out << hr;
			out << delimiter(' ');
			out << generatingStrings("Нажмите на клавишу и нажмите ВВОД");
			out << delimiter('_');
			out << generatingStrings("( 1 )", "Распечатать массив на экран", '.');
			out << generatingStrings("( 2 )", "Распечатать хеш-таблицу на экран (метод ПРЯМОГО СВЯЗЫВАНИЯ)", '.');
			out << generatingStrings("( 3 )", "Распечатать хеш-таблицу на экран (метод ОТКРЫТОЙ АДРЕСАЦИИ)", '.');
			out << generatingStrings("( 5 )", "Обновить массив и хеш-таблицы новыми данными", '.');
			out << generatingStrings("( 6 )", "Задать новый размер массива и хеш-таблиц", '.');
			out << generatingStrings("( 0 )", "Выход", '.');
			out << hr;
		}


		void showStatusBar()
		{
			/// <summary>
			/// выводит статус бар
			/// </summary>
			std::string hr{ delimiter(' ')};

			out << hr;

			while (!bufferForStatusBar.empty())
			{
				out << bufferForStatusBar.front();
				bufferForStatusBar.pop();
			}			

			out << hr;
			
		}


		void showStatusType()
		{
			/// <summary>
			/// выводит служебную информацию о типе
			/// </summary>
			out << generatingStrings("Статус Массива и Хеш-таблицы:", getFlagClearArrayAndHash() ? "ПУСТО" : "ЗАПОЛНЕНЫ");
			out << delimiter('-');
			out << generatingStrings("количество элементов массива:", std::to_string(myTypeArray.getSize()));
			out << delimiter('-');
			out << generatingStrings("количество элементов хеш-таблицы:", std::to_string(myTypeHashTableDirectBinding.getSize()));
			out << delimiter();
		}



		constexpr  std::string delimiter(char del = '=') const
		{
			/// <summary>
			/// задает строку разделитель, между информацией при выводе
			/// </summary>
			/// <param name="del"> символ разделителя</param>
			/// <returns></returns>
			std::string result(maxTableWidth, del);
			result.at(0) = '#';	result[result.size() - 2] = '#'; result.back() = '\n';
			return result;
		}


		const std::string generatingStrings(const std::string& str, char del = ' ') const
		{
			/// <summary>
			/// генерирует форматируемую строку с текстом str по центру
			/// принимает lvalue строку
			/// </summary>
			/// <param name="del">заполняем "пустоты" этим символом</param>
			
			try {
				if (str.empty()) throw std::exception("Dont empty string! -> LAB2::MyList::generatingStrings(const std::string& str)");
				int parity{ str.length() % 2 == 0 };
				size_t middleSize{ maxTableWidth > (str.length() + 2) ? (maxTableWidth - str.length() - 2) / 2 : 0 };

				std::string middle(middleSize - parity, del);
				std::string result{ "#" + middle + str + (parity ? " " : "") + middle + "#\n" };

				return result;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what();
				return std::string();
			}
		}


		const std::string generatingStrings(const std::string&& str, char del = ' ') const
		{
			/// <summary>
			/// генерирует форматируемую строку с текстом str по центру
			/// принимает rvalue строку
			/// </summary>
			/// <param name="del">заполняем "пустоты" этим символом</param>
			try {
				if (str.empty()) throw std::exception("Dont empty string! -> LAB2::MyList::generatingStrings(const std::string& str)");
				int parity{ str.length() % 2 == 0 };
				size_t middleSize{ maxTableWidth > (str.length() + 2) ? (maxTableWidth - str.length() - 2) / 2 : 0 };

				std::string middle(middleSize - parity, del);
				std::string result{ "#" + middle + str + (parity ? " " : "") + middle + "#\n" };

				return result;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what();
				return std::string();
			}
		}


		const std::string generatingStrings(const std::string& str, const std::string& str2, char del = ' ') const 
		{
			/// <summary>
			/// генерирует форматируемую строку с текстом str слева от края и str2 справа от края
			/// принимает lvalue строки
			/// </summary>
			/// <param name="del">заполняем "пустоты" этим символом</param>
			try {
				size_t len{ str.length() + str2.length() + 11 };
				size_t middleSize{ maxTableWidth > len ? maxTableWidth - len : 11 };

				std::string middle(middleSize, del);
				std::string result{ "#    " + str + middle + str2 + "    #\n" };

				return result;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what();
				return std::string();
			}
		}


		const std::string generatingStrings(const std::string&& str, const std::string&& str2, char del = ' ') const
		{
			/// <summary>
			/// генерирует форматируемую строку с текстом str слева от края и str2 справа от края
			/// принимает rvalue строки
			/// </summary>
			/// <param name="del">заполняем "пустоты" этим символом</param>
			try {
				size_t len{ str.length() + str2.length() + 11 };
				size_t middleSize{ maxTableWidth > len ? maxTableWidth - len : 11 };

				std::string middle(middleSize, del);
				std::string result{ "#    " + str + middle + str2 + "    #\n" };

				return result;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what();
				return std::string();
			}
		}

	};
}

