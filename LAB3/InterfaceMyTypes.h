#pragma once
#include "Interface.h"
#include <limits>

namespace LAB3 {
	template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
	class InterfaceMyTypes : public Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
	{
	private:

		template <class Iter>
		void printArray(Iter begin, Iter end, const std::string&& defaultString)
		{
			/// <summary>
			/// Форматирует вывод списка, за основу берет строку из параметра defaultString
			/// </summary>
			/// <param name="string">шаблон строки</param>
			std::string result{};
			for (auto it{ begin }, ite{ end }; it != ite; ++it) {

				std::string tmp{ defaultString };
				std::string num{ std::to_string(*it) };

				size_t len{ static_cast<size_t>(std::distance(this->myTypeArray.begin(), it)) };
				if ((len + 1) % this->getMaxTableColumns() != 0) {
					tmp.replace(tmp.size() - 1, 1, "|");
				}
				tmp.replace((tmp.length() - num.length()) / 2, num.length(), num);
				result += tmp;

				if ((len + 1) % this->getMaxTableColumns() == 0) {
					this->addToStatusBar(this->generatingStrings(result), false);
					this->addToStatusBar(this->delimiter('-'), false);
					result.clear();
				}
			}
			if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
		}


		template <class Iter>
		void printHashTableDirectBinding(Iter begin, Iter end, const std::string&& defaultString)
		{
			std::string result{};
			for (auto it{ begin }, ite{ end }; it != ite; ++it) {
				std::string tmp{ defaultString };
				std::string line{ std::to_string(std::distance(begin, it)) + ": ["};
				for (auto it2{ (*it).begin() }, ite2{ (*it).end() }; it2 != ite2; ++it2) {
					line += " " + std::to_string(*it2) + ",";
				}
				line += " ]";
				auto countElem{ std::distance((*it).begin(), (*it).end()) };
				this->addToStatusBar(this->generatingStrings(std::move(line), "count: " + std::to_string(countElem)), false);
			}

			if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
		}


		template <class Iter>
		void printHashTableOpenAdressing(Iter begin, Iter end, const std::string&& defaultString)
		{
			std::string result{};
			for (auto it{ begin }, ite{ end }; it != ite; ++it) {

				std::string tmp{ defaultString };
				std::string num{ std::to_string(*it) };

				size_t len{ static_cast<size_t>(std::distance(this->myTypeHashTableOpenAddressin.begin(), it)) };
				if ((len + 1) % this->getMaxTableColumns() != 0) {
					tmp.replace(tmp.size() - 1, 1, "|");
				}
				tmp.replace((tmp.length() - num.length()) / 2, num.length(), num);
				result += tmp;

				if ((len + 1) % this->getMaxTableColumns() == 0) {
					this->addToStatusBar(this->generatingStrings(result), false);
					this->addToStatusBar(this->delimiter('-'), false);
					result.clear();
				}
			}
			if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
		}

	public:
		InterfaceMyTypes(TypeArray myTypeArray
			, TypeHashDirectBinding myTypeHashTableDirectBinding
			, TypeHashOpenAdressing myTypeHashTableOpenAddressin
		)
		: Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>(
			myTypeArray
			, myTypeHashTableDirectBinding
			, myTypeHashTableOpenAddressin
		) {}

		void showGeneratedRandom(isVisibleClear visibleStatus = isVisibleClear::ON)
		{
			/// <summary>
			/// выводит информацию о событии, генерация случайными числами
			/// </summary>	
			this->myTypeArray.createRandom();
			this->myTypeHashTableDirectBinding.generateHashTableDirectBinding(this->myTypeArray.begin(), this->myTypeArray.end());
			this->myTypeHashTableOpenAddressin.generateHashTableOpenAdressing(this->myTypeArray.begin(), this->myTypeArray.end());
			
			this->setFlagClearArray(false);
			if (visibleStatus == isVisibleClear::ON)
			{
				this->addToStatusBar("Массив успешно создан и заполнен случайными числами!");
			}
			else
			{
				this->addToStatusBar("Массив успешно обновлен и заполнен новыми случайными числами!");
			}
		}

		void showPrintArray()
		{
			/// <summary>
			/// Печатает список если он не пуст и информирует если пуст
			/// </summary>
			if (!this->getFlagClearArrayAndHash()) {

				this->addToStatusBar("Вывод массива");

				auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->getMaxTableColumns() };
				printArray(this->myTypeArray.begin(), this->myTypeArray.end(), std::string(lengthColumn, ' '));

			}
			else {
				this->addToStatusBar("Массив ещё не заполнен!");
			}
		}


		void showPrintHashTableDirectBinding()
		{
			if (!this->getFlagClearArrayAndHash()) {

				this->addToStatusBar("Вывод Хеш таблицы");
				this->addToStatusBar(this->generatingStrings("метод создания", "метод прямого связывания"), false);
				this->addToStatusBar(this->delimiter('-'), false);
				this->addToStatusBar(this->delimiter(' '), false);

				size_t lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableDirectBinding.getSize() };
				
				printHashTableDirectBinding(this->myTypeHashTableDirectBinding.begin(), this->myTypeHashTableDirectBinding.end(), std::string(lengthColumn, ' '));
				
				std::cout << this->delimiter('-');
				std::cout << this->generatingStrings("Введите число для поиска в Хеш-таблице:");
				std::cout << this->delimiter('-');
				int tmp;
				std::cin >> tmp;
				std::string showIsFind{ "Число " + std::to_string(tmp) + " " };
				showIsFind += (this->myTypeHashTableDirectBinding.find(tmp) ? " Найдено!" : " Не найдено!");
				this->addToStatusBar(std::move(showIsFind));
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			else {
				this->addToStatusBar("Хеш-таблица ещё не заполнена!");
			}
		}


		void showPrintHashTableOpenAdressing()
		{
			if (!this->getFlagClearArrayAndHash()) {

				this->addToStatusBar("Вывод Хеш таблицы");
				this->addToStatusBar(this->generatingStrings( "метод создания", "метод открытой адресации"), false);
				this->addToStatusBar(this->delimiter('-'), false);
				this->addToStatusBar(this->delimiter(' '), false);
				
				auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableOpenAddressin.getSize() };
				printHashTableOpenAdressing(this->myTypeHashTableOpenAddressin.begin(), this->myTypeHashTableOpenAddressin.end(), std::string(lengthColumn, ' '));
				
			}
			else {
				this->addToStatusBar("Хеш-таблица ещё не заполнена!");
			}
		}


		void showUpdateData(isVisibleClear visibleStatus = isVisibleClear::ON)
		{
			if (!this->getFlagClearArrayAndHash()) {
				
				this->myTypeArray.clear();
				this->myTypeHashTableDirectBinding.clear();
				this->setFlagClearArray(!this->getFlagClearArrayAndHash());
				if(visibleStatus == isVisibleClear::ON) this->addToStatusBar("Данные успешно очищены!");
			}
			else {
				this->addToStatusBar("Для того чтобы очистить, нужно сначала заполнить!");
			}

		}


		void showResizeData()
		{
			std::cout << this->delimiter('-');
			std::cout << this->generatingStrings("Введите новый размер Хеш-таблицы:");
			std::cout << this->delimiter('-');
			size_t newHashSize;
			std::cin  >> newHashSize;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				this->addToStatusBar("ОШИБКА ВВОДА ДАННЫХ!");
				return;
			}
			this->myTypeHashTableDirectBinding.resize(newHashSize);

			std::cout << this->delimiter('-');
			std::cout << this->generatingStrings("Введите новый размер массива:");
			std::cout << this->delimiter('-');

			size_t newArraySize;
			std::cin >> newArraySize;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				this->addToStatusBar("ОШИБКА ВВОДА ДАННЫХ!");
				return;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			this->myTypeArray.resize(newArraySize);

			showGeneratedRandom();
		}		
	};
}
