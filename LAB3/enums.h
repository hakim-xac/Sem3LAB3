#pragma once
namespace LAB3 {
	enum class Keys {
		Exit = 48										// Key 0, ?????
		, PrintArray = 49								// Key 1, ??????????? ??????
		, PrintHashTableDirectBinding = 50				// Key 2, ??????????? ???-??????? (????? ??????? ??????????)
		, PrintHashTableOpenAdressingLineType = 51		// Key 3, ??????????? ???-??????? (????? ???????? ?????????, ??? ?????????? ???????? ???????????? ???????? ?????)
		, PrintHashTableOpenAdressingQuadType = 52		// Key 4, ??????????? ???-??????? (????? ???????? ?????????, ??? ?????????? ???????? ???????????? ???????????? ?????)
		, SearchNumber = 53								// Key 5, ????? ????? ? ???-??????? (????? ??????? ??????????)
		, SearchNumberLine = 54							// Key 5, ????? ????? ? ???-??????? (????? ???????? ?????????, ??? ?????????? ???????? ???????????? ???????? ?????)
		, SearchNumberQuad = 55							// Key 5, ????? ????? ? ???-??????? (????? ???????? ?????????, ??? ?????????? ???????? ???????????? ???????????? ?????)
		, UpdateArrayAndHashTable = 56					// Key 8, ???????? ?????? ? ??? ???????
		, ResizeArray = 57								// Key 9, ???????? ?????? ??????? ? ??????????? ???-???????
		, EmptyKey = -1
	};

	enum class isVisibleClearForDirectBinding {			// ????? ??????????? ???? ??? ????????????? ??????? ??????? ??????? ??????????
		ON
		, OFF
	};

	enum class TypeOpenAdressing {						// ????? ???? ??? ???????? ? ????????? ?????????? ???????? ? ?????? ???????? ??????????
		Line											// Line - ??? ???????? ??????
		, Quad											// Quad - ??? ???????????? ??????
	};

}




