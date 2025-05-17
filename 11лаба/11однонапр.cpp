#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
struct list {
    struct list* next;
    int info;
};
// Функция для ввода информации
int input_info(int* info) {
    fflush(stdin);
    scanf("%d", info);
    return *info;
}
// Функция для печати элемента списка
void printOn(struct list* ptr) {
    printf("%d ", ptr->info);
}
// Функция для отображения всего списка
void display(struct list* head) {
    if (head == NULL) {
        puts("Список пуст");
        return;
    }
    while (head != NULL) {
        printOn(head);
        head = head->next;
    }
    printf("\n");
}
// Функция для уничтожения списка
void destroy(struct list** head) {
    struct list* current = *head;
    struct list* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
// Функция для добавления элемента в начало списка
void add(struct list** head, int info) {
    struct list* new_ptr = (struct list*)malloc(sizeof(struct list));
    new_ptr->info = info;
    new_ptr->next = *head;
    *head = new_ptr;
}
void addToEnd(struct list** head, int info) {
    struct list* new_ptr = (struct list*)malloc(sizeof(struct list));
    new_ptr->info = info;
    new_ptr->next = NULL;

    if (*head == NULL) {
        *head = new_ptr;
        return;
    }

    struct list* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_ptr;
}
// Функция для удаления элемента из списка по значению
void delet(struct list** head, int key) {
    struct list* temp = *head, *prev = NULL;
    if (temp != NULL && temp->info == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->info != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Функция для вставки элемента на указанную позицию
void insertAtPosition(struct list** head, int info, int position) {
    if (position < 0) {
        puts("Некорректная позиция");
        return;
    }

    struct list* new_ptr = (struct list*)malloc(sizeof(struct list));
    new_ptr->info = info;

    if (position == 0) {
        new_ptr->next = *head;
        *head = new_ptr;
        return;
    }

    struct list* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            puts("Позиция выходит за пределы списка");
            free(new_ptr);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        puts("Позиция выходит за пределы списка");
        free(new_ptr);
        return;
    }

    new_ptr->next = temp->next;
    temp->next = new_ptr;
}

// Функция для записи списка в файл
void writeToFile(struct list* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    while (head != NULL) {
        fprintf(file, "%d\n", head->info);
        head = head->next;
    }
    fclose(file);
}
// Функция для восстановления списка из файла
struct list* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return NULL;
    }
    struct list* head = NULL;
    int info;
    while (fscanf(file, "%d", &info) != EOF) {
        addToEnd(&head, info); // Используем addToEnd для правильного порядка
    }
    fclose(file);
    return head;
}
int main(void) {
    setlocale(LC_ALL, "rus");
    struct list* head = NULL;
    int info, key, position;
    char ch;

    // Создание списка
    puts("Введите числа, одно за другим, 0 - конец списка:");
    while (1) {
        if (input_info(&info) == 0) {
            break; // Ввод завершен, если введен 0
        }
        add(&head, info);
    }

    // Печать списка
    puts("*** ВЕСЬ СПИСОК ***");
    display(head);

    // Удаление элемента
    puts("Введите ключ для удаления:");
    scanf("%d", &key);
    delet(&head, key);
    puts("*** СПИСОК ПОСЛЕ УДАЛЕНИЯ ***");
    display(head);

    // Добавление элемента на указанную позицию
    puts("Введите число для добавления:");
    scanf("%d", &info);
    puts("Введите позицию для добавления:");
    scanf("%d", &position);
    insertAtPosition(&head, info, position);
    puts("*** СПИСОК ПОСЛЕ ДОБАВЛЕНИЯ ***");
    display(head);

    // Запись списка в файл
    writeToFile(head, "list.txt");

    // Уничтожение списка
    destroy(&head);
    puts("*** СПИСОК ПОСЛЕ УНИЧТОЖЕНИЯ ***");
    display(head);

    // Восстановление списка из файла
    head = readFromFile("list.txt");
    puts("*** ВОССТАНОВЛЕННЫЙ СПИСОК ***");
    display(head);

    // Уничтожение списка
    destroy(&head);
    puts("*** СПИСОК ПОСЛЕ УНИЧТОЖЕНИЯ ***");
    display(head);

    system("pause");
    return 0;
}
