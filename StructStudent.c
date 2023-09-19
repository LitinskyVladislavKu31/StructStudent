#include <stdio.h>
#include <stdlib.h>

// Структура для представлення студента
struct Student {
    char Surname[50];
    char Name[50];
    char Patronymic[50];
    int age;
    int Number_cours;
    char Spec_name[50];
};

// Функція для додавання студента до списку
void addStud(struct Student *students, int *countStudent) {
    if (*countStudent < 100) {
        struct Student newStudent;
        printf("Введіть Прізвище студента: ");
        scanf("%s", newStudent.Surname);
        printf("Введіть Ім'я студента: ");
        scanf("%s", newStudent.Name);
        printf("Введіть По батькові студента: ");
        scanf("%s", newStudent.Patronymic);
        printf("Введіть вік студента: ");
        scanf("%d", &newStudent.age);
        printf("Введіть номер курсу студента: ");
        scanf("%d", &newStudent.Number_cours);
        printf("Введіть спеціальність студента: ");
        scanf("%s", newStudent.Spec_name);

        students[*countStudent] = newStudent;
        (*countStudent)++;

        printf("Студента додано до списку.\n");
    } else {
        printf("Список студентів повний.\n");
    }
}

// Функція для виведення всього списку студентів
void PrintStud(struct Student *students, int countStud) {
    printf("Список студентів:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("|   Прізвище   |    Ім'я    |  По батькові  | Вік | Курс |   Спеціальність   |\n");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < countStud; i++) {
        printf("| %-13s | %-10s | %-14s | %-3d | %-4d | %-18s |\n",
               students[i].Surname, students[i].Name, students[i].Patronymic,
               students[i].age, students[i].Number_cours, students[i].Spec_name);
    }

    printf("-----------------------------------------------------------------------------\n");
}

int main() {
    struct Student students[100];
    int countStudent = 0;

    while (1) {
        printf("Виберіть опцію:\n");
        printf("1. Додати студента\n");
        printf("2. Вивести список студентів\n");
        printf("3. Вийти\n");

        int choose;
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                addStud(students , &countStudent);
                break;
            case 2:
                PrintStud(students, countStudent);
                break;
            case 3:
                printf("До побачення!\n");
                return 0;
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
                break;
        }
    }

    return 0;
}
