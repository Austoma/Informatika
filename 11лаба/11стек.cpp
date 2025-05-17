#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
using namespace std;

struct Node {
    char* key;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(const char* key) {
        Node* newNode = new Node;
        newNode->key = new char[strlen(key) + 1];
        strcpy(newNode->key, key);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "���� ����!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete[] temp->key;
        delete temp;
    }

    void removeByKey(const char* key) {
        Stack tempStack;
        while (!isEmpty()) {
            if (strcmp(top->key, key) == 0) {
                pop();
                break;
            }
            tempStack.push(top->key);
            pop();
        }
        while (!tempStack.isEmpty()) {
            push(tempStack.top->key);
            tempStack.pop();
        }
    }

    void insertAtPosition(const char* key, int position) {
        Stack tempStack;
        int currentPos = 0;
        while (!isEmpty() && currentPos < position) {
            tempStack.push(top->key);
            pop();
            currentPos++;
        }
        push(key);
        while (!tempStack.isEmpty()) {
            push(tempStack.top->key);
            tempStack.pop();
        }
    }

    void print() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->key << endl;
            current = current->next;
        }
    }

    void saveToFile(const char* filename) {
        ofstream file(filename);
        Node* current = top;
        while (current != nullptr) {
            file << current->key << endl;
            current = current->next;
        }
        file.close();
    }

    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "������ �������� �����!" << endl;
            return;
        }
        while (!isEmpty()) {
            pop();
        }
        char buffer[256];
        while (file.getline(buffer, 256)) {
            push(buffer);
        }
        file.close();
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Stack stack;
    stack.push("Apple");
    stack.push("Banana");
    stack.push("Cherry");

    cout << "���� ����� ���������� ���������:" << endl;
    stack.print();

    stack.removeByKey("Banana");
    cout << "���� ����� �������� �������� � ������ 'Banana':" << endl;
    stack.print();

    stack.insertAtPosition("Orange", 1);
    cout << "���� ����� ���������� 'Orange' �� ������� 1:" << endl;
    stack.print();

    stack.saveToFile("stack.txt");
    cout << "���� �������� � ���� 'stack.txt'" << endl;

    stack.loadFromFile("stack.txt");
    cout << "���� ������������ �� ����� 'stack.txt':" << endl;
    stack.print();

    return 0;
}
