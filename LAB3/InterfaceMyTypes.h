#pragma once
#include "Interface.h"
#include <limits>
#include <tuple>



namespace LAB3 {

	/// <summary>
	/// ��������� ��������� ��� ����� ������� TypeArray
	/// </summary>
	/// <typeparam name="TypeArray">��� �������, ������������� ��� �������� ��������� �����</typeparam>
	/// <typeparam name="TypeHashDirectBinding">��� �������, ������������� ��� �������� ����� � ��������
	///  ���-������� ��������� ����� ������� ����������</typeparam>
	/// <typeparam name="TypeHashOpenAdressing">��� �������, ������������� ��� �������� ����� � ��������
	///  ���-������� ��������� ����� �������� ����������</typeparam>
	template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
	class InterfaceMyTypes : public Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
	{
	private:


		/// <summary>
		/// ����� ������� �� ����� ��������� � ������� ������: "out"
		/// </summary>
		template <class Iter>
		void printArray(Iter begin, Iter end, const std::string&& defaultString);


		/// <summary>
		/// ����� ���-������� �� ����� ��������� � ������� ������: "out"
		/// </summary>
		template <class Iter>
		void printHashTableDirectBinding(Iter begin, Iter end, const std::string&& defaultString);


		/// <summary>
		/// ����� ���-������� �� ����� ��������� � ������� ������: "out"
		/// </summary>
		template <class Iter>
		void printHashTableOpenAdressing(Iter begin, Iter end, const std::string&& defaultString);
		

	public:
		InterfaceMyTypes( TypeArray myTypeArray
						, TypeHashDirectBinding myTypeHashTableDirectBinding
						, TypeHashOpenAdressing myTypeHashTableOpenAddressin
		);


		/// <summary>
		/// ����� ���������� � ������� ���������
		/// </summary>
		void showGeneratedRandom(isVisibleClearForDirectBinding visibleStatus = isVisibleClearForDirectBinding::ON);

		/// <summary>
		/// ����� ������ �������
		/// </summary>
		void showPrintArray();

		/// <summary>
		/// ����� ������ ���-�������
		/// </summary>
		void showPrintHashTableDirectBinding();	

		/// <summary>
		/// ����� ������ ���-�������
		/// </summary>
		void showPrintHashTableOpenAdressing(TypeOpenAdressing typeOpen);

		/// <summary>
		/// ����� ���������� �� ���������� ������
		/// </summary>
		void showUpdateData(isVisibleClearForDirectBinding visibleStatus = isVisibleClearForDirectBinding::ON);

		/// <summary>
		/// ����� ���������� �� ��������� ������
		/// </summary>
		void showResizeData();

		/// <summary>
		/// ����� ���������� � ������ � ������ (����� ������� ����������)
		/// </summary>
		void searchNumber();

		/// <summary>
		/// ����� ���������� � ������ � ������ (����� �������� ���������)
		/// </summary>
		void searchNumberOpenAdressing(TypeOpenAdressing typeOpen);

		/// <summary>
		/// ���������� ���� ������� � ��� ���������
		/// </summary>
		void readKey();
	};	
}






/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
												/* ����������� ������� */





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
::showGeneratedRandom(isVisibleClearForDirectBinding visibleStatus)
{

	/// <summary>
	/// ������� ���������� � �������, ��������� ���������� �������
	/// </summary>	
	this->myTypeArray.createRandom();
	this->myTypeHashTableDirectBinding.generateHashTableDirectBinding(this->myTypeArray.begin(), this->myTypeArray.end());

	this->setFlagClearArray(false);
	if (visibleStatus == isVisibleClearForDirectBinding::ON)
	{
		this->addToStatusBar("������ ������� �������������� ���������� �������!");
	}
	else
	{
		this->addToStatusBar("������ ������� ��������� ������ ���������� �������!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintArray()
{
	/// <summary>
	/// �������� ������ ���� �� �� ���� � ����������� ���� ����
	/// </summary>
	if (!this->getFlagClearArrayAndHash()) {

		this->addToStatusBar("����� �������");

		auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->getMaxTableColumns() };
		printArray(this->myTypeArray.begin(), this->myTypeArray.end(), std::string(lengthColumn, ' '));

	}
	else {
		this->addToStatusBar("������ ��� �� ��������!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintHashTableDirectBinding()
{
	if (!this->getFlagClearArrayAndHash()) {

		this->addToStatusBar("����� ��� �������");
		this->addToStatusBar(this->generatingStrings("����� ��������", "����� ������� ����������"), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->delimiter(' '), false);

		size_t lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTableDirectBinding.getSize() };

		printHashTableDirectBinding(this->myTypeHashTableDirectBinding.begin(), this->myTypeHashTableDirectBinding.end(), std::string(lengthColumn, ' '));
	}
	else {
		this->addToStatusBar("���-������� ��� �� ���������!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showPrintHashTableOpenAdressing(TypeOpenAdressing typeOpen)
{
	if (!this->getFlagClearArrayAndHash()) {


		auto [countCollision, isOverFlow] = this->myTypeHashTableOpenAdressing.generateHashTableOpenAdressing(this->myTypeArray.begin(), this->myTypeArray.end(), typeOpen);
			
		this->addToStatusBar("����� ��� �������");
		std::string activeType{ typeOpen == TypeOpenAdressing::Line ? "��������" : "������������"};
		this->addToStatusBar(this->generatingStrings("����� ��������", "����� �������� ��������� ("+ activeType +" �����)"), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->generatingStrings("���������� ��������:", std::to_string(countCollision)), false);
		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->generatingStrings("���� �� ������������:", (isOverFlow ? "��" : "���")), false);
		

		this->addToStatusBar(this->delimiter('-'), false);
		this->addToStatusBar(this->delimiter(' '), false);

		std::string textNumber	{ "����� ������:" };
		std::string textItem	{ "�����:       " };

		auto lengthColumn{ (this->getMaxTableWidth() - 10 - textNumber.size()) / this->getMaxTableColumns() };
		int countLines{ static_cast<int>(std::ceil(static_cast<double>(this->myTypeHashTableOpenAdressing.getSize()) / this->getMaxTableColumns())) };

		this->addToStatusBar(this->delimiter(), false);
		for (int i{}; i < countLines; ++i)
		{
			auto start{ this->getMaxTableColumns() * i  };
			auto finish{ this->getMaxTableColumns() * (i + 1)  };
			if (finish > this->myTypeHashTableOpenAdressing.getSize()) finish = this->myTypeHashTableOpenAdressing.getSize();
			auto begin{ std::next(this->myTypeHashTableOpenAdressing.begin(), start) };
			auto end{ std::next(this->myTypeHashTableOpenAdressing.begin(), finish) };


			std::string line{};
			for (auto it{ begin }, ite{ end }; it != ite; ++it)
			{
				std::string tmpString{ std::string(lengthColumn, ' ') };

				std::string its{ std::to_string(std::distance(begin, it) + start ) };
				tmpString.replace((tmpString.length() - its.length()) / 2, its.length(), its);
				if (it != ite) tmpString.replace(0, 1, "|");
				line += tmpString;
			}
			this->addToStatusBar(this->generatingStrings(textNumber, std::move(line)), false);
			this->addToStatusBar(this->delimiter('.'), false);

			line.clear();
			for (auto it{ begin }, ite{ end }; it != ite; ++it)
			{
				std::string tmpString{ std::string(lengthColumn, ' ') };
				std::string its{ std::to_string(*it) };
				tmpString.replace((tmpString.length() - its.length()) / 2, its.length(), its);
				if (it != ite) tmpString.replace(0, 1, "|");
				line += tmpString;
			}
			this->addToStatusBar(this->generatingStrings(textItem, std::move(line)), false);
			line.clear();
			if( i < countLines - 1) this->addToStatusBar(this->delimiter('-'), false);
		}

		this->addToStatusBar(this->delimiter(), false);				
	}
	else {
		this->addToStatusBar("���-������� ��� �� ���������!");
	}
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showUpdateData(isVisibleClearForDirectBinding visibleStatus)
{
	if (!this->getFlagClearArrayAndHash()) {

		this->myTypeArray.clear();
		this->myTypeHashTableDirectBinding.clear();
		this->setFlagClearArray(!this->getFlagClearArrayAndHash());
		if (visibleStatus == isVisibleClearForDirectBinding::ON) this->addToStatusBar("������ ������� �������!");
	}
	else {
		this->addToStatusBar("��� ���� ����� ��������, ����� ������� ���������!");
	}
}

template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showResizeData()
{
	std::cout << this->delimiter('-');
	std::cout << this->generatingStrings("������� ����� ������ ���-�������:");
	std::cout << this->delimiter('-');
	size_t newHashSize;
	std::cin >> newHashSize;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->addToStatusBar("������ ����� ������!");
		return;
	}
	this->myTypeHashTableDirectBinding.resize(newHashSize);
	this->myTypeHashTableOpenAdressing.resize(newHashSize);

	std::cout << this->delimiter('-');
	std::cout << this->generatingStrings("������� ����� ������ �������:");
	std::cout << this->delimiter('-');

	size_t newArraySize;
	std::cin >> newArraySize;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->addToStatusBar("������ ����� ������!");
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
	std::cout << this->generatingStrings("������� ����� ��� ������ � ���-������� (����� ������� ����������):");
	std::cout << this->delimiter('-');
	int tmp{};
	std::cin >> tmp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->addToStatusBar("������ ����� ������!");
		return;
	}
	std::string showIsFind{ "����� " + std::to_string(tmp) + " " };
	showIsFind += (this->myTypeHashTableDirectBinding.find(tmp) ? " �������!" : " �� �������!");
	this->addToStatusBar(std::move(showIsFind));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::searchNumberOpenAdressing(TypeOpenAdressing typeOpen)
{
	this->myTypeHashTableOpenAdressing.generateHashTableOpenAdressing(this->myTypeArray.begin(), this->myTypeArray.end(), typeOpen);

	std::cout << this->delimiter('-');
	std::cout << this->generatingStrings("������� ����� ��� ������ � ���-������� (����� �������� ����������):");
	std::cout << this->delimiter('-');
	int tmp{};
	std::cin >> tmp;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->addToStatusBar("������ ����� ������!");
		return;
	}
	std::string showIsFind{ "����� " + std::to_string(tmp) + " " };
	showIsFind += (this->myTypeHashTableOpenAdressing.find(tmp, typeOpen) ? " �������!" : " �� �������!");
	this->addToStatusBar(std::move(showIsFind));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::InterfaceMyTypes<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::readKey()
{
	if (this->getActiveKey() == Keys::EmptyKey)
	{
		this->setActiveKey(static_cast<Keys>(std::cin.get()));	// ��������� ���� ������
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ��������� �����
	}
	switch (this->getActiveKey())
	{
	case Keys::Exit:                                    // 0
		exit(0);                                        // ����� �� �����
		break;
	case Keys::PrintArray:                              // 1
		showPrintArray();                        // ����� ������� �� �����
		break;
	case Keys::PrintHashTableDirectBinding:             // 2
		showPrintHashTableDirectBinding();       // ����� ���-������� �� ����� (����� ������� ����������)
		break;
	case Keys::PrintHashTableOpenAdressingLineType:     // 3
		showPrintHashTableOpenAdressing(TypeOpenAdressing::Line);	// ����� ���-������� �� ����� (����� �������� ���������, ��� ���������� �������� ������������ �������� �����)
		break;
	case Keys::PrintHashTableOpenAdressingQuadType:     // 4
		showPrintHashTableOpenAdressing(TypeOpenAdressing::Quad);	// ����� ���-������� �� ����� (����� �������� ���������, ��� ���������� �������� ������������ ������������ �����)
		break;
	case Keys::SearchNumber:                     // 5
		searchNumber();		                     // ����� ����� � ���-������� (����� ������� ����������)
		break;
	case Keys::SearchNumberLine:                 // 6
		searchNumberOpenAdressing(TypeOpenAdressing::Line);			// ����� ����� � ���-������� (����� �������� ���������, ������������ �������� �����)
		break;
	case Keys::SearchNumberQuad:                 // 7
		searchNumberOpenAdressing(TypeOpenAdressing::Quad);		    // ����� ����� � ���-������� (����� �������� ���������, ������������ ������������ �����)
		break;
	case Keys::UpdateArrayAndHashTable:          // 8
		showUpdateData(isVisibleClearForDirectBinding::OFF);     // ��������� ������ � ���-������� ������ �������
		break;
	case Keys::ResizeArray:                      // 9
		showResizeData();                        // �������� ������ ������� � ������� ���, ���������� ����� ������ ������� � ���-�������
		break;
	default:
		this->addToStatusBar("������� �� ������ �������!");            // ����� ������� ������������� � ������������ Keys
		break;
	}
	this->setActiveKey(Keys::EmptyKey);
}
