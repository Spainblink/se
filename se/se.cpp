// se.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
#include "Header.h"

int main()
{
    char playersChoiceChar;
    int playersChoiceInt;
    BattleField test1;
    test1.printField();
    do
    {
        std::cout << "Choose letter to shoot (from 'a' to 'j' only)" << std::endl;
        std::cin >> playersChoiceChar;

    } while (playersChoiceChar!='a'&& playersChoiceChar != 'b'&& playersChoiceChar != 'c'&& playersChoiceChar != 'd'&& playersChoiceChar != 'e'&& playersChoiceChar != 'f'&& playersChoiceChar != 'g'&& playersChoiceChar != 'h'&& playersChoiceChar != 'i'&& playersChoiceChar != 'j');
    do
    {
        std::cout << "Choose number to shoot (from '1' to '10' only)" << std::endl;
        std::cin >> playersChoiceInt;

    } while (playersChoiceInt!=1 && playersChoiceInt != 2 && playersChoiceInt != 3 && playersChoiceInt != 4 && playersChoiceInt != 5 && playersChoiceInt != 6 && playersChoiceInt != 7 && playersChoiceInt != 8 && playersChoiceInt != 9 && playersChoiceInt != 10);
    playerShot(playersChoiceChar, playersChoiceInt, test1);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
