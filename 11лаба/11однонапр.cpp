#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <clocale>
struct list {
    struct list* next;
    int info;
};
// ������� ��� ����� ����������
int input_info(int* info) {
    fflush(stdin);
    scanf("%d", info);
    return *info;
}
// ������� ��� ������ �������� ������
void printOn(struct list* ptr) {
    printf("%d ", ptr->info);
}
// ������� ��� ����������� ����� ������
void display(struct list* head) {
    if (head == NULL) {
        puts("������ ����");
        return;
    }
    while (head != NULL) {
        printOn(head);
        head = head->next;
    }
    printf("\n");
}
// ������� ��� ����������� ������
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
// ������� ��� ���������� �������� � ������ ������
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
// ������� ��� �������� �������� �� ������ �� ��������
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

// ������� ��� ������� �������� �� ��������� �������
void insertAtPosition(struct list** head, int info, int position) {
    if (position < 0) {
        puts("������������ �������");
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
            puts("������� ������� �� ������� ������");
            free(new_ptr);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        puts("������� ������� �� ������� ������");
        free(new_ptr);
        return;
    }

    new_ptr->next = temp->next;
    temp->next = new_ptr;
}

// ������� ��� ������ ������ � ����
void writeToFile(struct list* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("������ �������� �����");
        return;
    }
    while (head != NULL) {
        fprintf(file, "%d\n", head->info);
        head = head->next;
    }
    fclose(file);
}
// ������� ��� �������������� ������ �� �����
struct list* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("������ �������� �����");
        return NULL;
    }
    struct list* head = NULL;
    int info;
    while (fscanf(file, "%d", &info) != EOF) {
        addToEnd(&head, info); // ���������� addToEnd ��� ����������� �������
    }
    fclose(file);
    return head;
}
int main(void) {
    setlocale(LC_ALL, "rus");
    struct list* head = NULL;
    int info, key, position;
    char ch;

    // �������� ������
    puts("������� �����, ���� �� ������, 0 - ����� ������:");
    while (1) {
        if (input_info(&info) == 0) {
            break; // ���� ��������, ���� ������ 0
        }
        add(&head, info);
    }

    // ������ ������
    puts("*** ���� ������ ***");
    display(head);

    // �������� ��������
    puts("������� ���� ��� ��������:");
    scanf("%d", &key);
    delet(&head, key);
    puts("*** ������ ����� �������� ***");
    display(head);

    // ���������� �������� �� ��������� �������
    puts("������� ����� ��� ����������:");
    scanf("%d", &info);
    puts("������� ������� ��� ����������:");
    scanf("%d", &position);
    insertAtPosition(&head, info, position);
    puts("*** ������ ����� ���������� ***");
    display(head);

    // ������ ������ � ����
    writeToFile(head, "list.txt");

    // ����������� ������
    destroy(&head);
    puts("*** ������ ����� ����������� ***");
    display(head);

    // �������������� ������ �� �����
    head = readFromFile("list.txt");
    puts("*** ��������������� ������ ***");
    display(head);

    // ����������� ������
    destroy(&head);
    puts("*** ������ ����� ����������� ***");
    display(head);

    system("pause");
    return 0;
}
