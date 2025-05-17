#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// ��������� ��� ���������������� ������
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
// ������� ��� �������� ������ ����
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("������ ��������� ������\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// ������� ��� ���������� �������� � ����� ������
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
// ������� ��� ����������� ������
void display(struct Node* head) {
    if (head == NULL) {
        printf("������ ����\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ������� ��� �������� �������� �� ��������
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("������ ����\n");
        return;
    }
    struct Node* temp = *head;

    // ���� ��������� ������� � ������
    if (temp->data == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // ����� �������� ��� ��������
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // ���� ������� �� ������
    if (temp == NULL) {
        printf("������� �� ������\n");
        return;
    }

    // ���� ������� ������, ������������� �����
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// ������� ��� ������� �������� �� ��������� �������
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("������������ �������\n");
        return;
    }

    struct Node* newNode = createNode(data);

    // ������� � ������
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // ������� � �������� ��� �����
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("������� ������� �� ������� ������\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("������� ������� �� ������� ������\n");
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
// ������� ��� ����������� ������
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
// ������� ��� ������ ������ � ����
void writeToFile(struct Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("������ �������� �����\n");
        return;
    }
    while (head != NULL) {
        fprintf(file, "%d\n", head->data);
        head = head->next;
    }
    fclose(file);
}
// ������� ��� �������������� ������ �� �����
struct Node* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �������� �����\n");
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

    // �������� ������
    printf("������� �����, ���� �� ������, 0 - ����� ������:\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        addToEnd(&head, data);
    }
    // ������ ������
    printf("*** ���� ������ ***\n");
    display(head);

    // �������� ��������
    printf("������� ���� ��� ��������:\n");
    scanf("%d", &key);
    deleteNode(&head, key);
    printf("*** ������ ����� �������� ***\n");
    display(head);

    // ������� �������� �� ��������� �������
    printf("������� ����� ��� ����������:\n");
    scanf("%d", &data);
    printf("������� ������� ��� ����������:\n");
    scanf("%d", &position);
    insertAtPosition(&head, data, position);
    printf("*** ������ ����� ���������� ***\n");
    display(head);

    // ������ ������ � ����
    writeToFile(head, "list.txt");

    destroyList(&head);
    printf("*** ������ ����� ����������� ***\n");
    display(head);

    head = readFromFile("list.txt");
    printf("*** ��������������� ������ ***\n");
    display(head);

    destroyList(&head);
    printf("*** ������ ����� ����������� ***\n");
    display(head);

    return 0;
}
