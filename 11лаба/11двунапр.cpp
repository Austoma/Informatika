#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// Структура для двунаправленного списка
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// Функция для создания нового узла
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Функция для добавления элемента в конец списка
void addToEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// Функция для отображения списка
void display(struct Node* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Функция для удаления элемента по значению
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Список пуст\n");
        return;
    }
    struct Node* temp = *head;

    // Если удаляемый элемент — первый
    if (temp->data == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Поиск элемента для удаления
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // Если элемент не найден
    if (temp == NULL) {
        printf("Элемент не найден\n");
        return;
    }

    // Если элемент найден, перестраиваем связи
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Функция для вставки элемента на указанную позицию
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Некорректная позиция\n");
        return;
    }

    struct Node* newNode = createNode(data);

    // Вставка в начало
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Вставка в середину или конец
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Позиция выходит за пределы списка\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Позиция выходит за пределы списка\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
// Функция для уничтожения списка
void destroyList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
// Функция для записи списка в файл
void writeToFile(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    while (head != NULL) {
        fprintf(file, "%d\n", head->data);
        head = head->next;
    }
    fclose(file);
}
// Функция для восстановления списка из файла
struct Node* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return NULL;
    }
    struct Node* head = NULL;
    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        addToEnd(&head, data);
    }
    fclose(file);
    return head;
}
int main() {
    setlocale(LC_ALL, "rus");
    struct Node* head = NULL;
    int data, key, position;

    // Создание списка
    printf("Введите числа, одно за другим, 0 - конец списка:\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        addToEnd(&head, data);
    }
    // Печать списка
    printf("*** ВЕСЬ СПИСОК ***\n");
    display(head);

    // Удаление элемента
    printf("Введите ключ для удаления:\n");
    scanf("%d", &key);
    deleteNode(&head, key);
    printf("*** СПИСОК ПОСЛЕ УДАЛЕНИЯ ***\n");
    display(head);

    // Вставка элемента на указанную позицию
    printf("Введите число для добавления:\n");
    scanf("%d", &data);
    printf("Введите позицию для добавления:\n");
    scanf("%d", &position);
    insertAtPosition(&head, data, position);
    printf("*** СПИСОК ПОСЛЕ ДОБАВЛЕНИЯ ***\n");
    display(head);

    // Запись списка в файл
    writeToFile(head, "list.txt");

    destroyList(&head);
    printf("*** СПИСОК ПОСЛЕ УНИЧТОЖЕНИЯ ***\n");
    display(head);

    head = readFromFile("list.txt");
    printf("*** ВОССТАНОВЛЕННЫЙ СПИСОК ***\n");
    display(head);

    destroyList(&head);
    printf("*** СПИСОК ПОСЛЕ УНИЧТОЖЕНИЯ ***\n");
    display(head);

    return 0;
}
