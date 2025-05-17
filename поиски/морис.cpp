#include <iostream>
#include <string>
#include <vector>
#include<clocale>
using namespace std;

void computePrefixFunction(const string& pattern, vector<int>& pf) {
    int k = 0;
    pf[0] = 0; // ��������� �������� �������-�������
    for (int i = 1; i < pattern.length(); ++i) {
        while ((k > 0) && (pattern[i] != pattern[k])) {
            cout << "������������: " << pattern[i] << " != " << pattern[k] << ", �������� k �� " << pf[k - 1] << endl;
            k = pf[k - 1]; // ����� �� �������-�������
        }
        if (pattern[i] == pattern[k]) {
            k++;
            cout << "����������: " << pattern[i] << " == " << pattern[k - 1] << ", ����������� k �� " << k << endl;
        }
        pf[i] = k; // ���������� �������-�������
    }
}

string::size_type KMP(const string& S, int begin, const string& pattern) {
    vector<int> pf(pattern.length());
    computePrefixFunction(pattern, pf); // ���������� �������-�������

    int k = 0; // ������ ��� ��������
    for (int i = begin; i < S.length(); ++i) {
        while ((k > 0) && (pattern[k] != S[i])) {
            cout << "������������: " << pattern[k] << " != " << S[i] << ", �������� k �� " << pf[k - 1] << endl;
            k = pf[k - 1]; // ����� �� �������-�������
        }
        if (pattern[k] == S[i]) {
            cout << "����������: " << pattern[k] << " == " << S[i] << ", ����������� k �� " << (k + 1) << endl;
            k++;
        }
        if (k == pattern.length()) {
            cout << "������� ������ �� �������: " << (i - pattern.length() + 1) << endl;
            return (i - pattern.length() + 1); // ���������� ������� ������ ��������
        }
    }
    cout << "������� �� ������." << endl;
    return string::npos; // ������� �� ������
}

int main() {
    setlocale(LC_ALL, "rus");
    string pattern = "Raw";
    string ss = "���Rjjruo���Raw����";
    int begin = 3;

    cout << "�������� ����� �������� \"" << pattern << "\" � ������ \"" << ss << "\" ������� � ������� " << begin << "." << endl;
    KMP(ss, begin, pattern);
    return 0;
}
