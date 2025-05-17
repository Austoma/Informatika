#include <iostream>
#include <cstring>
#include<clocale>
char* userStrstr(const char* haystack, char* needle)
{
    std::cout << "�������� ����� ��������� \"" << needle << "\" � ������ \"" << haystack << "\"." << std::endl;

    for (const char* hp = haystack; hp != haystack + strlen(haystack); ++hp)
    {
        std::cout << "��������� ������: '" << *hp << "' (������� " << (hp - haystack) << ")" << std::endl;

        const char* np = needle;
        const char* tmp = hp;

        // �������� ��������� ���������
        bool match = true;
        for (; np != needle + strlen(needle); ++np)
        {
            if (*tmp != *np)
            {
                match = false;
                std::cout << "�� ���������: '" << *tmp << "' != '" << *np << "'" << std::endl;
                break;
            }
            else
            {
                std::cout << "���������: '" << *tmp << "' == '" << *np << "'" << std::endl;
                ++tmp;
            }
        }

        // ���� ��� ������� �������
        if (match)
        {
            std::cout << "������� ��������� \"" << needle << "\" ������� � ������� " << (hp - haystack) << "." << std::endl;
            return (char*)hp; // ���������� ��������� �� ������ ��������� ���������
        }
    }

    std::cout << "��������� \"" << needle << "\" �� �������." << std::endl;
    return nullptr;
}

int main()
{
    setlocale(LC_ALL, "rus");
    char first[] = "Hello, dyadya Vasya!";
    char second[] = "Vasya";

    if (userStrstr(first, second))
    {
        std::cout << "��������� �������: " << second << std::endl;
    }
    else
    {
        std::cout << "��������� �� �������." << std::endl;
    }

    return 0;
}
