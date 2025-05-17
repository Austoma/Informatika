#include <iostream>
#include <string>
#include <vector>
#include<clocale>
using namespace std;

void computePrefixFunction(const string& pattern, vector<int>& pf) {
    int k = 0;
    pf[0] = 0; // Начальное значение префикс-функции
    for (int i = 1; i < pattern.length(); ++i) {
        while ((k > 0) && (pattern[i] != pattern[k])) {
            cout << "Несовпадение: " << pattern[i] << " != " << pattern[k] << ", сдвигаем k на " << pf[k - 1] << endl;
            k = pf[k - 1]; // Сдвиг по префикс-функции
        }
        if (pattern[i] == pattern[k]) {
            k++;
            cout << "Совпадение: " << pattern[i] << " == " << pattern[k - 1] << ", увеличиваем k до " << k << endl;
        }
        pf[i] = k; // Заполнение префикс-функции
    }
}

string::size_type KMP(const string& S, int begin, const string& pattern) {
    vector<int> pf(pattern.length());
    computePrefixFunction(pattern, pf); // Вычисление префикс-функции

    int k = 0; // Индекс для паттерна
    for (int i = begin; i < S.length(); ++i) {
        while ((k > 0) && (pattern[k] != S[i])) {
            cout << "Несовпадение: " << pattern[k] << " != " << S[i] << ", сдвигаем k на " << pf[k - 1] << endl;
            k = pf[k - 1]; // Сдвиг по префикс-функции
        }
        if (pattern[k] == S[i]) {
            cout << "Совпадение: " << pattern[k] << " == " << S[i] << ", увеличиваем k до " << (k + 1) << endl;
            k++;
        }
        if (k == pattern.length()) {
            cout << "Паттерн найден на позиции: " << (i - pattern.length() + 1) << endl;
            return (i - pattern.length() + 1); // Возвращаем позицию начала паттерна
        }
    }
    cout << "Паттерн не найден." << endl;
    return string::npos; // Паттерн не найден
}

int main() {
    setlocale(LC_ALL, "rus");
    string pattern = "Raw";
    string ss = "лилRjjruoлилRawилил";
    int begin = 3;

    cout << "Начинаем поиск паттерна \"" << pattern << "\" в строке \"" << ss << "\" начиная с позиции " << begin << "." << endl;
    KMP(ss, begin, pattern);
    return 0;
}
