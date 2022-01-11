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
        window{ MyArray<int>(15), MyHash<int>(11), MyHash<int>(11) };   



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
        case Keys::Exit:                                    // 0
            exit(0);                                        // Выход из цикла
            break;
        case Keys::PrintArray:                              // 1
            window.showPrintArray();                        // Вывод массива на экран
            break;
        case Keys::PrintHashTableDirectBinding:             // 2
            window.showPrintHashTable();                    // Вывод хеш-таблицы на экран (метод ПРЯМОГО СВЯЗЫВАНИЯ)
            break;
        case Keys::PrintHashTableOpenAddressing:            // 3
            window.showPrintHashTable();                    // Вывод хеш-таблицы на экран (метод ОТКРЫТОЙ АДРЕСАЦИИ)
            break;
        case Keys::UpdateArrayAndHashTable:                 // 5
            window.showUpdateData(isVisibleClear::OFF);     // Обновляем массив и хеш-таблицу новыми данными
            break;
        case Keys::ResizeArray:                             // 6
            window.showResizeData();                        // Изменяем размер массива и очищаем его, генерируем новые данные массива и хеш-таблицу
            break;
        default:
            window.addToStatusBar("Введена не верная команда!");            // любая клавиша отсутствующая в перечислении Keys
            break;
        }
    }

}

