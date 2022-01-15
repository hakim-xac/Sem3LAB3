#pragma once
namespace LAB3 {
	enum class Keys {
		Exit = 48										// Key 0, �����
		, PrintArray = 49								// Key 1, ����������� ������
		, PrintHashTableDirectBinding = 50				// Key 2, ����������� ���-������� (����� ������� ����������)
		, PrintHashTableOpenAdressingLineType = 51		// Key 3, ����������� ���-������� (����� �������� ���������, ��� ���������� �������� ������������ �������� �����)
		, PrintHashTableOpenAdressingQuadType = 52		// Key 4, ����������� ���-������� (����� �������� ���������, ��� ���������� �������� ������������ ������������ �����)
		, SearchNumber = 53								// Key 5, ����� ����� � ���-�������
		, UpdateArrayAndHashTable = 54 					// Key 6, �������� ������ � ��� �������
		, ResizeArray = 55								// Key 7, �������� ������ ������� � ����������� ���-�������
		, EmptyKey = -1
	};

	enum class isVisibleClear {
		ON
		, OFF
	};

	enum class TypeOpenAdressing {
		Line, Quad
	};

}




