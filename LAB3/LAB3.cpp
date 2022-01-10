#include <iostream>
#include "enums.h"                  // Подключаем заголовок, содержащий все перечисления
#include "InterfaceMyTypes.h"                  
#include "myArray.h"  
#include "MyHash.h"  






int main()
{
    using namespace LAB3;                           // Подключаем пространство имен нашей программы

    setlocale(LC_ALL, "Russian");                   // Задаем локаль
    Keys key{ Keys::Exit };                         // Задаем по умолчанию команду выхода


    InterfaceMyTypes<myArray<int>, MyHash<int>>
        window{ myArray<int>(15), MyHash<int>(11) };   



    /* Запускаем бесконечный цикл ожидая ввод команды от пользователя  */
    while (true)
    {
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
        case Keys::CreateRandommyType:      // 1
            window.showGeneratedRandom();   // Заполняем список случайными значениями
            break;
        case Keys::AscendingmyType:         // 2
            //window.showAscendingList();   // Сортируем список по убыванию
            break;
        case Keys::DesciningmyType:         // 3
           // window.showDescendingList();  // Сортируем списрк по возрастанию
            break;
        case Keys::ShufflemyType:           // 4
            //window.showShuffleList();     // Перемешиваем список
            break;
        case Keys::PrintArray:              // 5
            window.showPrintArray();        // Вывод списка на экран
            break;
        case Keys::PrintHashTable:          // 6
            window.showPrintHashTable();    // Очищаем список
            break;
        case Keys::ResizemyType:            // 9
            //window.showResizeList();      // Изменяем размер списка и очищаем его
            break;
        default:
            window.addToStatusBar("Введена не верная команда!");            // любая клавиша отсутствующая в перечислении Keys
            break;
        }
    }

}

