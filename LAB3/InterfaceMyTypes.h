#pragma once
#include "Interface.h"
#include <limits>



namespace LAB3 {
	template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
	class InterfaceMyTypes : public Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
	{
	private:

		template <class Iter>
		void printArray(Iter begin, Iter end, const std::string&& defaultString);

		template <class Iter>
		void printHashTableDirectBinding(Iter begin, Iter end, const std::string&& defaultString);


		template <class Iter>
		void printHashTableOpenAdressing(Iter begin, Iter end, const std::string&& defaultString);				// TODO
		

	public:
		InterfaceMyTypes( TypeArray myTypeArray
						, TypeHashDirectBinding myTypeHashTableDirectBinding
						, TypeHashOpenAdressing myTypeHashTableOpenAddressin
		);

		void showGeneratedRandom(isVisibleClear visibleStatus = isVisibleClear::ON);
		void showPrintArray();

		void showPrintHashTableDirectBinding();
		void showPrintHashTableOpenAdressingLineType();
		void showPrintHashTableOpenAdressingQuadType();

		void showUpdateData(isVisibleClear visibleStatus = isVisibleClear::ON);
		void showResizeData();
		void searchNumber();
		void readKey();
	};	
}






/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/





template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
template <typename Iter>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::printArray(Iter begin, Iter end, const std::string&& defaultString)
{
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


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
template <typename Iter>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::printHashTableDirectBinding(Iter begin, Iter end, const std::string&& defaultString)
{
	std::string result{};
	for (auto it{ begin }, ite{ end }; it != ite; ++it) {
		std::string tmp{ defaultString };
		std::string line{ std::to_string(std::distance(begin, it)) + ": [" };
		for (auto it2{ (*it).begin() }, ite2{ (*it).end() }; it2 != ite2; ++it2) {
			line += " " + std::to_string(*it2) + ",";
		}
		line += " ]";
		auto countElem{ std::distance((*it).begin(), (*it).end()) };
		this->addToStatusBar(this->generatingStrings(std::move(line), "count: " + std::to_string(countElem)), false);
	}

	if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
template <typename Iter>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::printHashTableOpenAdressing(Iter begin, Iter end, const std::string&& defaultString)
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
			std::cout << "n: " << result << "|\n";
			system("pause");
		if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
	
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::InterfaceMyTypes(TypeArray myTypeArray
	, TypeHashDirectBinding myTypeHashTableDirectBinding
	, TypeHashOpenAdressing myTypeHashTableOpenAddressin)
	: Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>(
		myTypeArray
		, myTypeHashTableDirectBinding
		, myTypeHashTableOpenAddressin
		) {}

template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showGeneratedRandom(isVisibleClear visibleStatus)
{

	/// <summary>
	/// выводит информацию о событии, генерация случайными числами
	/// </summary>	
	this->myTypeArray.createRandom();
	this->myTypeHashTableDirectBinding.generateHashTableDirectBinding(this->myTypeArray.begin(), this->myTypeArray.end());

	this->setFlagClearArray(false);
	if (visibleStatus == isVisibleClear::ON)
	{
		this->addToStatusBar("Данные успешно сгенерированны случайными числами!");
	}
	else
	{
		this->addToStatusBar("Данные успешно обновлены новыми случайными числами!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintArray()
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


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintHashTableDirectBinding()
{
	if (!this->getFlagClearArrayAndHash()) {

		this->addToStatusBar("Вывод Хеш таблицы");
		this->addToStatusBar(this->generatingStrings("метод создания", "метод прямого связывания"), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->delimiter(' '), false);

		size_t lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableDirectBinding.getSize() };

		printHashTableDirectBinding(this->myTypeHashTableDirectBinding.begin(), this->myTypeHashTableDirectBinding.end(), std::string(lengthColumn, ' '));
	}
	else {
		this->addToStatusBar("Хеш-таблица ещё не заполнена!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintHashTableOpenAdressingLineType()
{
	if (!this->getFlagClearArrayAndHash()) {

		this->myTypeHashTableOpenAdressin.generateHashTableOpenAdressingLineType(this->myTypeArray.begin(), this->myTypeArray.end());


		this->addToStatusBar("Вывод Хеш таблицы");
		this->addToStatusBar(this->generatingStrings("метод создания", "метод открытой адресации(линейные пробы)"), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->delimiter(' '), false);

		
		//auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableOpenAdressing.getSize() };
		/////TODO
	}
	else {
		this->addToStatusBar("Хеш-таблица ещё не заполнена!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintHashTableOpenAdressingQuadType()
{
	if (!this->getFlagClearArrayAndHash()) {

		this->myTypeHashTableOpenAdressin.generateHashTableOpenAdressingQuadType(this->myTypeArray.begin(), this->myTypeArray.end());


		this->addToStatusBar("Вывод Хеш таблицы");
		this->addToStatusBar(this->generatingStrings("метод создания", "метод открытой адресации(квадратичные пробы)"), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->delimiter(' '), false);

		//auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableOpenAdressing.getSize() };
		/////TODO
	}
	else {
		this->addToStatusBar("Хеш-таблица ещё не заполнена!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showUpdateData(isVisibleClear visibleStatus)
{
	if (!this->getFlagClearArrayAndHash()) {

		this->myTypeArray.clear();
		this->myTypeHashTableDirectBinding.clear();
		this->setFlagClearArray(!this->getFlagClearArrayAndHash());
		if (visibleStatus == isVisibleClear::ON) this->addToStatusBar("Данные успешно очищены!");
	}
	else {
		this->addToStatusBar("Для того чтобы очистить, нужно сначала заполнить!");
	}
}

template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showResizeData()
{
	std::cout << this->delimiter('-');
	std::cout << this->generatingStrings("Введите новый размер Хеш-таблицы:");
	std::cout << this->delimiter('-');
	size_t newHashSize;
	std::cin >> newHashSize;
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


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::searchNumber()
{
	std::cout << this->delimiter('-');
	std::cout << this->generatingStrings("Введите число для поиска в Хеш-таблице:");
	std::cout << this->delimiter('-');
	int tmp{};
	std::cin >> tmp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->addToStatusBar("ОШИБКА ВВОДА ДАННЫХ!");
		return;
	}
	std::string showIsFind{ "Число " + std::to_string(tmp) + " " };
	showIsFind += (this->myTypeHashTableDirectBinding.find(tmp) ? " Найдено!" : " Не найдено!");
	this->addToStatusBar(std::move(showIsFind));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::readKey()
{
	if (this->getActiveKey() == Keys::EmptyKey)
	{
		this->setActiveKey(static_cast<Keys>(std::cin.get()));	// Принимаем один символ
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем остальной буфер
	}
	switch (this->getActiveKey())
	{
	case Keys::Exit:                                    // 0
		exit(0);                                        // Выход из цикла
		break;
	case Keys::PrintArray:                              // 1
		showPrintArray();                        // Вывод массива на экран
		break;
	case Keys::PrintHashTableDirectBinding:             // 2
		showPrintHashTableDirectBinding();       // Вывод хеш-таблицы на экран (метод ПРЯМОГО СВЯЗЫВАНИЯ)
		break;
	case Keys::PrintHashTableOpenAddressingLineType:    // 3
		showPrintHashTableOpenAdressingLineType();      // Вывод хеш-таблицы на экран (метод ОТКРЫТОЙ АДРЕСАЦИИ, Для разрешения коллизий использованы линейные пробы)
		break;
	case Keys::PrintHashTableOpenAddressingQuadType:    // 3
		showPrintHashTableOpenAdressingQuadType();      // Вывод хеш-таблицы на экран (метод ОТКРЫТОЙ АДРЕСАЦИИ, Для разрешения коллизий использованы линейные пробы)
		break;
	case Keys::SearchNumber:                     // 4
		searchNumber();		                     // Поиск числа в Хеш
		break;
	case Keys::UpdateArrayAndHashTable:                 // 5
		showUpdateData(isVisibleClear::OFF);     // Обновляем массив и хеш-таблицу новыми данными
		break;
	case Keys::ResizeArray:                      // 6
		showResizeData();                        // Изменяем размер массива и очищаем его, генерируем новые данные массива и хеш-таблицу
		break;
	default:
		this->addToStatusBar("Введена не верная команда!");            // любая клавиша отсутствующая в перечислении Keys
		break;
	}
	this->setActiveKey(Keys::EmptyKey);
}
