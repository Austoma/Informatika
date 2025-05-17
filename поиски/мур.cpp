#include <iostream>
#include <string>
#include<clocale>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]) {
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1; // Инициализация всех символов как -1
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i; // Заполнение таблицы
}

void search(string txt, string pat) {
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar); // Создание таблицы плохих символов

    int s = 0; // Сдвиг
    cout << "Начинаем поиск подстроки \"" << pat << "\" в строке \"" << txt << "\"." << endl;

    while (s <= (n - m)) {
        int j = m - 1; // Индекс для паттерна
        cout << "Текущий сдвиг: " << s << endl;

        // Сравнение паттерна с текстом
        while (j >= 0 && pat[j] == txt[s + j]) {
            cout << "Сравниваем: " << pat[j] << " с " << txt[s + j] << endl;
            j--;
        }

        if (j < 0) {
            cout << "Паттерн найден на сдвиге: " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1; // Сдвиг по таблице плохих символов
        } else {
            cout << "Паттерн не совпадает. Сдвигаем на: " << max(1, j - badchar[txt[s + j]]) << endl;
            s += max(1, j - badchar[txt[s + j]]); // Сдвиг по таблице плохих символов
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
