#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <clocale>

int main() {
    setlocale(LC_ALL, "rus");
    FILE *f1, *f2;
    char str_buf[512];
    char shortest_word[100] = ""; // Для хранения самого короткого слова
    int shortest_word_length = 1000; // Начальное значение длины слова
    int line_number = 0; // Номер текущей строки
    int skipped_line = 0; // Номер строки, которую нужно пропустить

    // Открываем файл F1 для чтения
    f1 = fopen("./file1.txt", "r");
    if (f1 == NULL) {
        perror("Error opening the F1 file");
        return 1;
    }

    // Находим строку с самым коротким словом
    while (fgets(str_buf, sizeof(str_buf), f1) != NULL) {
        line_number++;
        char *word = strtok(str_buf, " \n"); // Разделяем строку на слова
        while (word != NULL) {
            int word_length = strlen(word);
            if (word_length < shortest_word_length) {
                shortest_word_length = word_length;
                strcpy(shortest_word, word);
                skipped_line = line_number; // Запоминаем номер строки
            }
            word = strtok(NULL, " \n");
        }
    }
    // Открываем файл F2 для записи
    f2 = fopen("./file2.txt", "w");
    if (f2 == NULL) {
        perror("Error opening the F2 file");
        fclose(f1);
        return 1;
    }
    line_number = 0; // Сбрасываем счетчик строк
    while (fgets(str_buf, sizeof(str_buf), f1) != NULL) {
        line_number++;
        if (line_number != skipped_line) {
            // Копируем строку в файл F2, если это не строка с самым коротким словом
            fprintf(f2, "%s", str_buf);
        }
    }
    // Закрываем файлы
    fclose(f1);
    fclose(f2);
    // Выводим номер пропущенной строки
    printf("Line number with the shortest word: %d\n", skipped_line);

    return 0;
}
