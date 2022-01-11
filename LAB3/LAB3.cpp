#include <iostream>
#include "enums.h"                  // Подключаем заголовок, содержащий все перечисления
#include "InterfaceMyTypes.h"                  
#include "MyArray.h"  
#include "MyHash.h"  






int main()
{
    using namespace LAB3;                           // Подключаем пространство имен нашей программы

    setlocale(LC_ALL, "Russian");                   // Задаем локаль
    Keys key{ Keys::Exit };                         // Задаем по умолчанию команду выхода


    InterfaceMyTypes<MyArray<int>, MyHash<int>>
        window{ MyArray<int>(15), MyHash<int>(11) };   



    /* Запускаем бесконечный цикл ожидая ввод команды от пользователя  */
    while (true)
    {
        if (window.getFlagClearArrayAndHash()) window.showGeneratedRandom();

        system("cls");
        window.showHeader();                // Вывод заголовка
        window.showStatusType();            // Вывод служебной информации
        window.showStatusBar();             // Вывод "всплывающих сообщений"
        window.showMenu();                  // Вывод меню
        key = static_cast<Keys>(std::cin.get());                            // Принимаем один символ
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем остальной буфер
        switch (key)
        {
        case Keys::Exit:                    // 0
            exit(0);                        // Выход из цикла
            break;
        case Keys::PrintArray:              // 1
            window.showPrintArray();        // Вывод массива на экран
            break;
        case Keys::PrintHashTable:          // 2
            window.showPrintHashTable();    // Вывод хеш-таблицы на экран
            break;
        case Keys::ClearArraiAndHashTable:  // 3
            window.showClearData(isVisibleClear::OFF);         // Очищаем список
            break;
        case Keys::ResizemyType:            // 9
            //window.showResizeList();      // Изменяем размер массива и очищаем его
            break;
        default:
            window.addToStatusBar("Введена не верная команда!");            // любая клавиша отсутствующая в перечислении Keys
            break;
        }
    }

}

