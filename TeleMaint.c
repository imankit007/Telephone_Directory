/******************************************************************************
 * Filename    : DeptMaint.c
 * Author      : Education & Research Dept, Infosys Technologies Limited
 * Date        : 11-Mar-2009
 * Description : Contains the functions required for the department
 *		maintenance.
 *******************************************************************************/

/* Include files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "FileFunctions.h"
#include "Functions.h"

void fnTeleDirMenu();

long int aliPhoneNumber[100];

void generatePhoneNumber()
{

    char acLine[46];
    int emp_id;
    char emp_name[26];
    int dep_id;
    char emp_location[6];
    long int phone_no;

    // fnOpenFile(DEP_FILE);
    // while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    // {
    //     aliPhoneNumber[i] = 0;
    // }
    // fnCloseFile(DEP_FILE);

    fnOpenFile(EMP_FILE);

    while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    {
        sscanf(acLine, "%4d%25c%4d%5c%ld", &emp_id, &emp_name, &dep_id, &emp_location, &phone_no);

        int temp = dep_id - 1000;

        if (phone_no > aliPhoneNumber[temp])
        {
            aliPhoneNumber[temp] = phone_no;
        }
    }

    fnCloseFile(EMP_FILE);
}

void fnAddTeleNum()
{
    system("cls");

    generatePhoneNumber();

    int dept_code;
    char input[50];
    char empDetails[46];
    char empDetails_t[46];
    char empDetails_n[46];
    char emp_name[26];
    int emp_id;
    int dep_id;
    char emp_location[6];
    long int phone_no;
    long int phone_no_max = INT_MIN;

    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(15, 3);
    printf("======================================");
    fnGotoxy(20, 5);
    printf("Add a Telephone Number");
    fnGotoxy(20, 6);
    printf("======================");

    fnGotoxy(20, 8);
    printf("Eneter Employee Id");
    fnGotoxy(50, 8);
    printf(": ....");

    fnGotoxy(20, 10);
    printf("Location");
    fnGotoxy(50, 10);
    printf(": ______");

    fnGotoxy(20, 12);
    printf("Department code");
    fnGotoxy(50, 12);
    printf(": ____");

    fnGotoxy(20, 14);
    printf("Telephone Number Allocated");
    fnGotoxy(55, 14);
    printf(": _______");

    fnGotoxy(52, 8);
    gets(input);

    int inpemp_id = atoi(input);
    if (inpemp_id == NULL)
    {
        fnGotoxy(20, 16);
        printf("Enter a valid Employee ID");
        fnGotoxy(20, 17);
        printf("Press any key to continue");
        getch();
        fnTeleDirMenu();
    }
    else
    {
        fnOpenFile(EMP_FILE);
        while (fnReadFile(empDetails, EMP_FILE, CURRENT) == 0)
        {
            sscanf(empDetails, "%4d%25c%4d%5c%ld", &emp_id, &emp_name, &dep_id, &emp_location, &phone_no);

            dept_code = dep_id;
            emp_name[25] = '\0';
            emp_location[5] = '\0';
            if (emp_id == inpemp_id)
            {
                if (phone_no != 0)
                {
                    fnGotoxy(20, 16);
                    printf("A phone number has alredy been assigned to the Employee.");
                    fnGotoxy(20, 17);
                    printf("Press any key to continue");
                    getch();
                    fnTeleDirMenu();
                }
                fnGotoxy(52, 10);
                trim(emp_location, emp_location);
                printf("%s", emp_location);

                fnGotoxy(52, 12);
                printf("%d", dep_id);
                if (aliPhoneNumber[dep_id - 1000] == 0)
                {
                    phone_no_max = dep_id * 1000 + 1;
                }
                else
                {
                    phone_no_max = aliPhoneNumber[dep_id - 1000] + 1;
                }

                fnGotoxy(57, 14);
                printf("%ld", phone_no_max);
                empDetails_n[45] = '\n';
                getch();

                sprintf(empDetails_n, "%4d%25s%4d%5s%7ld", emp_id, emp_name, dep_id, emp_location, phone_no_max);

                fnUpdateFile(empDetails_n, EMP_FILE);
                fnCloseFile(EMP_FILE);

                fnGotoxy(20, 16);
                printf("Telephone Number Added!");
                fnGotoxy(20, 17);
                printf("Press any key to continue");
                getch();
                fnTeleDirMenu();
            }
        }
        fnTeleDirMenu();
    }
}
