#pragma once
#include "Interface.h"

namespace LAB3 {
	template <class TypeArray, class TypeHash>
	class InterfaceMyTypes : public Interface<TypeArray, TypeHash>
	{
	private:

		template <class Iter>
		void printArray(Iter begin, Iter end, const std::string&& defaultString)
		{
			/// <summary>
			/// ����������� ����� ������, �� ������ ����� ������ �� ��������� defaultString
			/// </summary>
			/// <param name="string">������ ������</param>
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
		void printHashTable(Iter begin, Iter end, const std::string&& defaultString)   //TODO
		{
			std::string result{};
			for (auto it{ begin }, ite{ end }; it != ite; ++it) {
				std::string tmp{ defaultString };
				std::cerr << "n: " << (*it).size() << "\n";

			}
			system("pause");
			if (!result.empty()) this->addToStatusBar(this->generatingStrings(result));
		}

	public:
		InterfaceMyTypes(TypeArray myTypeArray, TypeHash myTypeHash )
			: Interface<TypeArray, TypeHash>(myTypeArray, myTypeHash) {}

		void showGeneratedRandom()
		{
			/// <summary>
			/// ������� ���������� � �������, ��������� ���������� �������
			/// </summary>
			this->myTypeArray.createRandom();
			this->myTypeHashTable.generateHashTable(this->myTypeArray.begin(), this->myTypeArray.end());
			this->setFlagClearArray(false);
			this->addToStatusBar("������ ������� �������� ���������� �������!");
		}

		void showPrintArray()
		{
			/// <summary>
			/// �������� ������ ���� �� �� ���� � ����������� ���� ����
			/// </summary>
			if (!this->getFlagClearArrayAndHash()) {

				this->addToStatusBar("����� �������");

				int lengthColumn{ (this->getMaxTableWidth() - 10) / this->getMaxTableColumns() };
				printArray(this->myTypeArray.begin(), this->myTypeArray.end(), std::string(lengthColumn, ' '));

			}
			else {
				this->addToStatusBar("������ ��� �� ��������!");
			}
		}


		void showPrintHashTable()
		{
			if (!this->getFlagClearArrayAndHash()) {

				this->addToStatusBar("����� ��� �������");
				auto lengthColumn{ (this->getMaxTableWidth() - 10) / this->myTypeHashTable.getSize()};
				printHashTable(this->myTypeHashTable.begin(), this->myTypeHashTable.end(), std::string(lengthColumn, ' '));
			}
			else {
				this->addToStatusBar("���-������� ��� �� ���������!");
			}
		}


		
	};
}
