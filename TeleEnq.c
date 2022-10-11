#include "FileFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

void fnTeleEnqMenu();

void fnEnqByTeleNum()
{
    system("cls");
    long int telephone_number;
    char acLine[46];
    char employee_name[26];
    int emp_id;
    char emp_location[3];
    char department_name[16];
    int check;
    int dept_code;
    long int temp_no;
    fnOpenFile(EMP_FILE);
    fnGotoxy(15, 4);
    printf("Telephone Directory Maintenance System\n");
    fnGotoxy(15, 5);
    printf("======================================\n");
    fnGotoxy(20, 7);
    printf("Telephone Number Enquiry\n");
    fnGotoxy(20, 8);
    printf("========================\n");
    fnGotoxy(15, 10);
    printf("Enter Telephone number");
    fnGotoxy(40, 10);
    printf(": .......");
    fnGotoxy(15, 11);
    printf("Employee Name");
    fnGotoxy(40, 11);
    printf(": _________________________");
    fnGotoxy(15, 12);
    printf("Location");
    fnGotoxy(40, 12);
    printf(": _______");
    fnGotoxy(15, 13);
    printf("Department Name");
    fnGotoxy(40, 13);
    printf(": _______________");

    fnGotoxy(15, 15);
    printf("Press any key to continue");

    fnGotoxy(42, 10);
    scanf("%ld", &telephone_number);

    while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    {
        sscanf(acLine, "%4d%25c%4d%5c%7ld ", &emp_id, employee_name, &dept_code, emp_location, &temp_no);
        if (telephone_number == temp_no)
        {
            // sscanf(employee_name, "%s", employee_name);
            trim(employee_name, employee_name);
            fnGotoxy(42, 11);
            printf("%s\n", employee_name);
            sscanf(emp_location, "%s", emp_location);
            fnGotoxy(42, 12);
            trim(emp_location, emp_location);
            printf("%s", emp_location);
            // printf("DEPT code  :  %d\n", dept_code);
            fnGetDeptName(department_name, dept_code);
            fnGotoxy(42, 13);
            printf("%s", department_name);
            check++;
            break;
        }
    }
    if (check == 0)
    {
        fnGotoxy(15, 14);
        printf("Number not present!");
    }
    getch();
    fnCloseFile(EMP_FILE);
    fnTeleEnqMenu();
}
void fnEnqByName()
{
    system("cls");
    fflush(stdin);
    char emp_name[26];
    char acLine[46];
    char employee_name[26];
    int emp_id;
    char emp_location[6];
    char department_name[16];
    int check = 0;
    int dept_code;
    employee_name[25] = '\0';
    department_name[16] = '\0';
    emp_location[5] = '\0';

    fnOpenFile(EMP_FILE);
    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(15, 3);
    printf("======================================");
    fnGotoxy(20, 5);
    printf("Telephone Enquiry by Name");
    fnGotoxy(20, 6);
    printf("=========================");
    fnGotoxy(15, 8);
    printf("Enter the Employee Name");
    fnGotoxy(45, 8);
    printf(": ..");
    fnGotoxy(47, 8);
    gets(emp_name);

    fnGotoxy(10, 10);
    printf("Name");
    fnGotoxy(35, 10);
    printf("Location");
    fnGotoxy(53, 10);
    printf("DeptName");
    fnGotoxy(70, 10);
    printf("TelNumber");

    int i = 0;

    // printf("-%s-\n", emp_name);
    while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    {
        long int temp_no;
        sscanf(acLine, "%4d%25c%4d%5c%ld ", &emp_id, &employee_name, &dept_code, &emp_location, &temp_no);
        trim(employee_name, employee_name);
        trim(emp_location, emp_location);
        char str1[26];
        strcpy(str1, employee_name);
        char str2[26];
        strcpy(str2, emp_name);
        char *search = strstr(strlwr(str1), strlwr(str2));
        fnGetDeptName(department_name, dept_code);
        if (search != NULL)
        {
            fnGotoxy(9, 12 + i);
            printf("%s", employee_name);
            fnGotoxy(36, 12 + i);
            printf("%s", emp_location);
            fnGotoxy(52, 12 + i);
            printf("%s", department_name);
            fnGotoxy(71, 12 + i);
            printf("%ld", temp_no);
            i = i + 2;
            check++;
        }
    }
    if (check == 0)
    {
        fnGotoxy(15, 10);
        printf("Employee not found!");
    }

    fnCloseFile(EMP_FILE);
    getch();
    fnTeleEnqMenu();
}