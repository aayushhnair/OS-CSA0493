#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 10
#define MAX_NAME_LENGTH 20

struct employee {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
};

void write_employee_to_file(FILE *file, struct employee emp, int index) {
    fseek(file, sizeof(struct employee) * index, SEEK_SET);
    fwrite(&emp, sizeof(struct employee), 1, file);
}

struct employee read_employee_from_file(FILE *file, int index) {
    struct employee emp;
    fseek(file, sizeof(struct employee) * index, SEEK_SET);
    fread(&emp, sizeof(struct employee), 1, file);
    return emp;
}

int main() {
    FILE *file = fopen("employees.dat", "wb+");
    int i;
    struct employee emp;

    /* add employees to file */
    strcpy(emp.name, "John Smith");
    emp.age = 30;
    emp.salary = 50000;
    write_employee_to_file(file, emp, 0);

    strcpy(emp.name, "Jane Doe");
    emp.age = 25;
    emp.salary = 45000;
    write_employee_to_file(file, emp, 1);

    strcpy(emp.name, "Bob Johnson");
    emp.age = 35;
    emp.salary = 55000;
    write_employee_to_file(file, emp, 2);

    /* read and print employees from file */
    for (i = 0; i < 3; i++) {
        emp = read_employee_from_file(file, i);
        printf("Name: %s\nAge: %d\nSalary: %.2f\n", emp.name, emp.age, emp.salary);
    }

    fclose(file);
    return 0;
}
