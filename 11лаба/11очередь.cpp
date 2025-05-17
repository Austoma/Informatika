#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
using namespace std;

struct Node {
    char* key;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const char* key) {
        Node* newNode = new Node;
        newNode->key = new char[strlen(key) + 1];
        strcpy(newNode->key, key);
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete[] temp->key;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void removeByKey(const char* key) {
        Queue tempQueue;
        while (!isEmpty()) {
            if (strcmp(front->key, key) == 0) {
                dequeue();
                break;
            }
            tempQueue.enqueue(front->key);
            dequeue();
        }
        while (!tempQueue.isEmpty()) {
            enqueue(tempQueue.front->key);
            tempQueue.dequeue();
        }
    }

    void insertAtPosition(const char* key, int position) {
        Queue tempQueue;
        int currentPos = 0;
        while (!isEmpty() && currentPos < position) {
            tempQueue.enqueue(front->key);
            dequeue();
            currentPos++;
        }
        enqueue(key);
        while (!tempQueue.isEmpty()) {
            enqueue(tempQueue.front->key);
            tempQueue.dequeue();
        }
    }

    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->key << endl;
            current = current->next;
        }
    }

    void saveToFile(const char* filename) {
        ofstream file(filename);
        Node* current = front;
        while (current != nullptr) {
            file << current->key << endl;
            current = current->next;
        }
        file.close();
    }

    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Ошибка открытия файла!" << endl;
            return;
        }
        while (!isEmpty()) {
            dequeue();
        }
        char buffer[256];
        while (file.getline(buffer, 256)) {
            enqueue(buffer);
        }
        file.close();
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Queue queue;
    queue.enqueue("Apple");
    queue.enqueue("Banana");
    queue.enqueue("Cherry");

    cout << "Очередь после добавления элементов:" << endl;
    queue.print();

    queue.removeByKey("Banana");
    cout << "Очередь после удаления элемента с ключом 'Banana':" << endl;
    queue.print();

    queue.insertAtPosition("Orange", 1);
    cout << "Очередь после добавления 'Orange' на позицию 1:" << endl;
    queue.print();

    queue.saveToFile("queue.txt");
    cout << "Очередь сохранена в файл 'queue.txt'" << endl;

    queue.loadFromFile("queue.txt");
    cout << "Очередь восстановлена из файла 'queue.txt':" << endl;
    queue.print();

    return 0;
}
