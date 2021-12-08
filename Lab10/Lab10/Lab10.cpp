#include <iostream>
#include <vector>
#include <conio.h>
#include "plog/Log.h"
#include "plog/Initializers/RollingFileInitializer.h"

//функция для ввода количества бочонков
int enter()
{
    int t = 0;
    while (true)
    {
        std::cin >> t;
        PLOG_INFO << "Input: " << t;
        if (std::cin.fail() || std::cin.peek() != '\n' || t < 1)
        {
            std::cin.clear();
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            std::cout << "Некорректный ввод. Число должно быть натуральное." << std::endl;
            PLOG_ERROR << "Incorrect input";
        }
        else return t;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    //инициализация логгера
    plog::init(plog::verbose, "Log.txt", 1000000, 5); 
    int N = 0;
    std::vector<int> numbers;
    std::cout << "Введите количество бочонков: " << std::endl;
    N = enter();
    //заполнение вектора бочонков натуральными числами от 1 до N
    for (int i = 0; i < N; i++)
    {
        numbers.push_back(i + 1);
    }  
    while (numbers.size() != 0)
    {
        std::cout << "Нажмите Enter чтобы достать бочонок: ";
        _getch();
        //создание случайного числа [0 <= t <= текущий размер вектора бочонков]
        int t = rand() % numbers.size();
        PLOG_INFO << "Random Number: " << t;
        //вывод соответствующего бочонка
        std::cout << "Бочонок №" << numbers.at(t) << std::endl;
        PLOG_INFO << "Value: " << numbers.at(t);
        //удаление этого бочонка из вектора бочонков
        numbers.erase(numbers.begin() + t);
    }
    std::cout << "Бочонки закончились";
    _getch();
    return 0;
}