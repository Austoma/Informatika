#include <iostream>
#include <cstring>
#include<clocale>
char* userStrstr(const char* haystack, char* needle)
{
    std::cout << "Начинаем поиск подстроки \"" << needle << "\" в строке \"" << haystack << "\"." << std::endl;

    for (const char* hp = haystack; hp != haystack + strlen(haystack); ++hp)
    {
        std::cout << "Проверяем символ: '" << *hp << "' (позиция " << (hp - haystack) << ")" << std::endl;

        const char* np = needle;
        const char* tmp = hp;

        // Начинаем сравнение подстроки
        bool match = true;
        for (; np != needle + strlen(needle); ++np)
        {
            if (*tmp != *np)
            {
                match = false;
                std::cout << "Не совпадает: '" << *tmp << "' != '" << *np << "'" << std::endl;
                break;
            }
            else
            {
                std::cout << "Совпадает: '" << *tmp << "' == '" << *np << "'" << std::endl;
                ++tmp;
            }
        }

        // Если все символы совпали
        if (match)
        {
            std::cout << "Найдена подстрока \"" << needle << "\" начиная с позиции " << (hp - haystack) << "." << std::endl;
            return (char*)hp; // Возвращаем указатель на начало найденной подстроки
        }
    }

    std::cout << "Подстрока \"" << needle << "\" не найдена." << std::endl;
    return nullptr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    char first[] = "Hello, dyadya Vasya!";
    char second[] = "Vasya";

    if (userStrstr(first, second))
    {
        std::cout << "Подстрока найдена: " << second << std::endl;
    }
    else
    {
        std::cout << "Подстрока не найдена." << std::endl;
    }

    return 0;
}
