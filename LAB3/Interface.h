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
	/// ������� ����� ����������
	/// </summary>
	/// <typeparam name="TypeElem">��� "myType"</typeparam>
	private:
		std::ostream& out										{ std::cout };			// ����� ������
		size_t maxTableWidth									{ 110 };				// ������ ��������� ������
		int maxTableColumnsInArray								{ 5 };					// ���������� ������� ��� ������ �������
		std::queue <std::string> bufferForStatusBar				{};						// ������� ��� ������ ����
		Keys activeKey											{ Keys::EmptyKey };

		Interface() = delete;															// ��������� ��������� ������ �����

	protected:


		TypeArray myTypeArray;
		TypeHashDirectBinding myTypeHashTableDirectBinding;
		TypeHashOpenAdressing myTypeHashTableOpenAdressin;

		void addToStatusBar(const std::string& str, bool isFormated = true);
		void addToStatusBar(const std::string&& str, bool isFormated = true);

		bool flagClearArrayAndHash								{ true };


	public:

		Interface(TypeArray& myTypeArray
			, TypeHashDirectBinding& myTypeHashTableDirectBinding
			, TypeHashOpenAdressing& myTypeHashTableOpenAddressin
		);

		Interface(
			TypeArray&& myTypeArray
			, TypeHashDirectBinding&& myTypeHashTableDirectBinding
			, TypeHashOpenAdressing&& myTypeHashTableOpenAddressin
		);

		constexpr size_t getMaxTableWidth()			const;
		constexpr auto getMaxTableColumns()			const;
		constexpr bool getFlagClearArrayAndHash()	const;
		Keys getActiveKey()							const;
		void setActiveKey(Keys key);

		void setFlagClearArray(bool flag);

		constexpr void showHeader();
		constexpr void showMenu();
		void showStatusBar();
		void showStatusType();

		constexpr  std::string delimiter(char del = '=') const;

		constexpr const std::string generatingStrings(const std::string& str, char del = ' ') const;
		constexpr const std::string generatingStrings(const std::string&& str, char del = ' ') const;

		constexpr const std::string generatingStrings(const std::string& str, const std::string& str2, char del = ' ') const;
		constexpr const std::string generatingStrings(const std::string&& str, const std::string&& str2, char del = ' ') const;

	};
}


/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/



template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::Interface(
	TypeArray& myTypeArray
	, TypeHashDirectBinding& myTypeHashTableDirectBinding
	, TypeHashOpenAdressing& myTypeHashTableOpenAdressin
	)
	: myTypeArray(myTypeArray)
	, myTypeHashTableDirectBinding(myTypeHashTableDirectBinding)
	, myTypeHashTableOpenAdressin(myTypeHashTableOpenAdressin) {}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::Interface(
	TypeArray&& myTypeArray
	, TypeHashDirectBinding&& myTypeHashTableDirectBinding
	, TypeHashOpenAdressing&& myTypeHashTableOpenAddressin
	)
	: myTypeArray(myTypeArray)
	, myTypeHashTableDirectBinding(myTypeHashTableDirectBinding)
	, myTypeHashTableOpenAdressin(myTypeHashTableOpenAdressin) {}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr size_t LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::getMaxTableWidth() const
{
	return maxTableWidth;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr auto LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::getMaxTableColumns() const 
{
	return maxTableColumnsInArray;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr bool LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::getFlagClearArrayAndHash() const 
{
	return flagClearArrayAndHash;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
LAB3::Keys LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::getActiveKey() const
{
	return activeKey;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::setActiveKey(Keys key)
{
	activeKey = key;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::setFlagClearArray(bool flag)
{
	flagClearArrayAndHash = flag;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::addToStatusBar(const std::string& str, bool isFormated)
{
	return addToStatusBar(std::move(str), isFormated);
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::addToStatusBar(const std::string&& str, bool isFormated)
{
	/// <summary>
	/// ��������� rvalue ������ � ���������� � � ������� ������ ����
	/// </summary>
	/// 
	/// <param name="isFormated">������������� ������ �� ���������?</param>
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


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showHeader()
{

	std::string header{ generatingStrings("������������ ������ � 3", "�������� ����������� ����������� ������ ��� ����������� ������. ") };
	std::string header2{ generatingStrings("������ ��-11", "������� �.C.") };

	std::string hr{ delimiter() };

	out << hr;
	out << header;
	out << delimiter('-');
	out << header2;
	out << hr;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showMenu()
{
	std::string hr{ delimiter() };

	out << hr;
	out << delimiter(' ');
	out << generatingStrings("������� �� ������� � ������� ����");
	out << delimiter('_');
	out << generatingStrings("( 1 )", "����������� ������ �� �����", '.');
	out << generatingStrings("( 2 )", "����������� ���-������� �� ����� (����� ������� ����������)", '.');
	out << generatingStrings("( 3 )", "����������� ���-������� �� ����� (����� �������� ���������)", '.');
	out << generatingStrings("( 4 )", "����� ����� � ���-�������", '.');
	out << generatingStrings("( 5 )", "�������� ������ � ���-������� ������ �������", '.');
	out << generatingStrings("( 6 )", "������ ����� ������ ������� � ���-������", '.');
	out << generatingStrings("( 0 )", "�����", '.');
	out << hr;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showStatusBar()
{
	std::string hr{ delimiter(' ') };

	out << hr;

	while (!bufferForStatusBar.empty())
	{
		out << bufferForStatusBar.front();
		bufferForStatusBar.pop();
	}

	out << hr;
}



template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
void LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::showStatusType()
{
	out << generatingStrings("������ ������� � ���-�������:", getFlagClearArrayAndHash() ? "�����" : "���������");
	out << delimiter('-');
	out << generatingStrings("���������� ��������� �������:", std::to_string(myTypeArray.getSize()));
	out << delimiter('-');
	out << generatingStrings("���������� ��������� ���-�������:", std::to_string(myTypeHashTableDirectBinding.getSize()));
	out << delimiter();
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr std::string LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::delimiter(char del) const
{

	std::string result(maxTableWidth, del);
	result.at(0) = '#';	result[result.size() - 2] = '#'; result.back() = '\n';
	return result;
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr const std::string LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::generatingStrings(const std::string& str, char del) const
{
	return generatingStrings(std::move(str), del);
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr const std::string LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::generatingStrings(const std::string&& str, char del) const
{
	/// <summary>
	/// ���������� ������������� ������ � ������� str �� ������
	/// ��������� rvalue ������
	/// </summary>
	/// <param name="del">��������� "�������" ���� ��������</param>
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


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr const std::string LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::generatingStrings(const std::string& str, const std::string& str2, char del) const
{
	return generatingStrings(std::move(str), std::move(str2), std::move(del));
}


template <class TypeArray, class TypeHashDirectBinding, class TypeHashOpenAdressing>
constexpr const std::string LAB3::Interface<TypeArray, TypeHashDirectBinding, TypeHashOpenAdressing>
::generatingStrings(const std::string&& str, const std::string&& str2, char del) const
{
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