#include <iostream>
#include "enums.h"                  // Подключаем заголовок, содержащий все перечисления
#include "InterfaceMyTypes.h"                  
#include "MyArray.h"  
#include "MyHashDirectBinding.h"  
#include "MyHashOpenAdressing.h"  






int main()
{
    using namespace LAB3;                           // Подключаем пространство имен нашей программы

    setlocale(LC_ALL, "Russian");                   // Задаем локаль
    Keys key{ Keys::Exit };                         // Задаем по умолчанию команду выхода


    InterfaceMyTypes<MyArray<int>, MyHashDirectBinding<int>, MyHashOpenAdressing<int>>
        window{ MyArray<int>(15), MyHashDirectBinding<int>(11), MyHashOpenAdressing<int>(11) };


    /* Запускаем бесконечный цикл ожидая ввод команды от пользователя  */
    while (true)
    {
        if (window.getFlagClearArrayAndHash()) window.showGeneratedRandom();

        system("cls");
        window.showHeader();                // Вывод заголовка
        window.showStatusType();            // Вывод служебной информации
        window.showStatusBar();             // Вывод "всплывающих сообщений"
        window.showMenu();                  // Вывод меню
        window.readKey();
    }

}

