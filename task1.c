
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Student;


int idExists(int id){
    FILE *f = fopen("students.txt", "r");
    Student s;

    if (f == NULL){
        return 0;
    }

    while (fscanf(f, "%d %29s %d", &s.id, s.name, &s.age) == 3){
        if (s.id == id){
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}


void addStudent(){
    Student s;

    printf("ID kiriting: ");
    if (scanf("%d", &s.id) != 1 || s.id <= 0){
        printf("Noto'g'ri ID!\n");
        return;
    }

    if (idExists(s.id)){
        printf("Bu ID allaqachon mavjud!\n");
        return;
    }

    printf("Ism kiriting: ");
    if (scanf("%29s", s.name) != 1){
        printf("Ism noto'g'ri!\n");
        return;
    }

    printf("Yosh kiriting: ");
    if (scanf("%d", &s.age) != 1){
        printf("Yosh noto'g'ri!\n");
        return;
    }

    if (s.age < 10 || s.age > 100){
        printf("Yosh 10 dan 100 gacha bo'lishi kerak!\n");
        return;
    }

    FILE *f = fopen("students.txt", "a");

    if (f == NULL){
        printf("Fayl ochilmadi!\n");
        return;
    }

    fprintf(f, "%d %s %d\n", s.id, s.name, s.age);

    fclose(f);

    printf("Student muvaffaqiyatli qo'shildi!\n");
}


void showStudents(){
    FILE *f = fopen("students.txt", "r");
    Student s;

    if (f == NULL){
        printf("Studentlar mavjud emas!\n");
        return;
    }

    printf("\n%-8s %-20s %-5s\n", "ID", "NAME", "AGE");
    printf("-----------------------------------\n");

    while (fscanf(f, "%d %29s %d", &s.id, s.name, &s.age) == 3){
        printf("%-8d %-20s %-5d\n", s.id, s.name, s.age);
    }

    fclose(f);
}


void searchStudent(){
    int id;
    int found = 0;
    Student s;

    printf("Qidirilayotgan ID: ");

    if (scanf("%d", &id) != 1){
        printf("Noto'g'ri ID!\n");
        return;
    }

    FILE *f = fopen("students.txt", "r");

    if (f == NULL){
        printf("Studentlar mavjud emas!\n");
        return;
    }

    while (fscanf(f, "%d %29s %d", &s.id, s.name, &s.age) == 3){
        if (s.id == id){
            printf("\nID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);

            found = 1;
            break;
        }
    }

    if (found == 0){
        printf("Student topilmadi!\n");
    }

    fclose(f);
}


void deleteStudent(){
    int id;
    int found = 0;
    Student s;

    printf("O'chiriladigan student ID: ");

    if (scanf("%d", &id) != 1){
        printf("Noto'g'ri ID!\n");
        return;
    }

    FILE *f = fopen("students.txt", "r");

    if (f == NULL){
        printf("Fayl mavjud emas!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");

    if (temp == NULL){
        printf("Vaqtinchalik fayl ochilmadi!\n");
        fclose(f);
        return;
    }

    while (fscanf(f, "%d %29s %d", &s.id, s.name, &s.age) == 3){
        if (s.id == id){
            found = 1;
        }
        else{
            fprintf(temp, "%d %s %d\n", s.id, s.name, s.age);
        }
    }

    fclose(f);
    fclose(temp);

    if (found == 1){
        remove("students.txt");

        if (rename("temp.txt", "students.txt") == 0){
            printf("Student muvaffaqiyatli o'chirildi!\n");
        }
        else{
            printf("Fayl nomini o'zgartirishda xato!\n");
        }
    }
    else{
        remove("temp.txt");
        printf("Student topilmadi!\n");
    }
}
int main(){
    int choice;

    do{
        printf("\n===== STUDENT CRUD =====\n");
        printf("1. Student qo'shish\n");
        printf("2. Barcha studentlarni ko'rish\n");
        printf("3. ID bo'yicha qidirish\n");
        printf("4. Studentni o'chirish\n");
        printf("5. Chiqish\n");

        printf("Tanlang: ");

        if (scanf("%d", &choice) != 1){
            printf("Noto'g'ri tanlov!\n");
            return 0;
        }

        switch (choice){
            case 1:addStudent();break;

            case 2:showStudents();break;

            case 3:searchStudent();break;

            case 4:deleteStudent();break;

            case 5:printf("Dastur tugadi!\n");break;

            default:printf("Bunday tanlov mavjud emas!\n");
        }

    } while (choice != 5);

    return ;
}