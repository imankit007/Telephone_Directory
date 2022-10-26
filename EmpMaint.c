/******************************************************************************
 * Filename    : EmpMaint.c
 * Author      : Education & Research Dept, Infosys Technologies Limited
 * Date        : 11-Mar-2009
 * Description : Contains the functions required for the employee
 *		maintenance.
 *******************************************************************************/
/* Included the libraries here */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "filefunctions.h"
#include "functions.h"

/* Stores the Code of the next employee that may be added */

int giEmpCode;

void fnEmpMenu();

long int aliPhoneNumbert[100];

void generatePhoneNumbert()
{

    char acLine[46];
    int emp_id;
    char emp_name[26];
    int dep_id;
    char emp_location[6];
    long int phone_no;
    int i = 0;
    fnOpenFile(DEP_FILE);
    while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    {
        aliPhoneNumbert[i++] = 0;
    }
    fnCloseFile(DEP_FILE);

    fnOpenFile(EMP_FILE);

    while (fnReadFile(acLine, EMP_FILE, CURRENT) == 0)
    {
        sscanf(acLine, "%4d%25c%4d%5c%ld", &emp_id, &emp_name, &dep_id, &emp_location, &phone_no);

        int temp = dep_id - 1000;

        if (phone_no != 0)
        {
            aliPhoneNumbert[temp]++;
        }
    }

    fnCloseFile(EMP_FILE);

    // int x = 0;
    // printf("{");
    // for (int x = 0; x < 10; x++)
    // {
    //     printf(" %d ,", aliPhoneNumbert[x]);
    // }
    // printf("}");
}

/******************************************************************************
 * Function: fnInitializeEmpCode
 * Description: Reads all the employees in the employee file and initializes
 *		the global variable giEmpCode for any new employee to be added to
 *		the system. The emp file should've been opened in the program already!
 * Input Parameters: None
 ******************************************************************************/

int fnInitializeEmpCode()
{
    char chEmpDetails[50];

    // We open the emp.txt file
    fnOpenFile(EMP_FILE);
    printf("here");
    while (fnReadFile(chEmpDetails, EMP_FILE, CURRENT) == 0)
    {
        sscanf(chEmpDetails, "%d", &giEmpCode);
    }
    // printf("EMP_CODE: %d", giEmpCode);
    fnCloseFile(EMP_FILE);
}

/******************************************************************************
 * Function: fnAddEmp
 * Description: Adds a new employee entry into the Emp file
 *		The Emp file should've been opened in the program already!
 * Input Parameters: None
 * Returns: Zero on success. 1 if dept name exists already.
 ******************************************************************************/
void fnAddNewEmp()
{
    system("cls");
    char acLine[46];
    fnInitializeEmpCode();
    char emp_name[26];
    int dept_code;
    char dept_name[16];
    char emp_location[6];
    long tele_num = 0;
    int check;

    acLine[45] = '\0';
    emp_name[25] = '\0';
    dept_name[15] = '\0';
    emp_location[5] = '\0';

    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(15, 3);
    printf("======================================");

    fnGotoxy(20, 5);
    printf("Add an Employee");
    fnGotoxy(20, 6);
    printf("===============");

    fnGotoxy(15, 8);
    printf("Enter Employee Name");
    fnGotoxy(40, 8);
    printf(": .........................");

    fnGotoxy(15, 9);
    printf("Employee ID");
    fnGotoxy(40, 9);
    printf(": ___________ ");

    fnGotoxy(15, 10);
    printf("Enter department code");
    fnGotoxy(40, 10);
    printf(": .......");

    fnGotoxy(15, 11);
    printf("Enter department name");
    fnGotoxy(40, 11);
    printf(": ____________");

    fnGotoxy(15, 12);
    printf("Enter Location");
    fnGotoxy(40, 12);
    printf(": ........");

    giEmpCode++;

    fnGotoxy(42, 9);
    printf("%d", giEmpCode);

    fnGotoxy(25, 14);
    printf("Press any key to continue");

    fnGotoxy(42, 8);
    gets(emp_name);
    fnGotoxy(25, 16);
    fnDisplayDepts(16);
    fnGotoxy(42, 10);
    scanf("%d", &dept_code);
    fflush(stdin);
    check = fnGetDeptName(dept_name, dept_code);
    // printf("%s", fnCheckValidDepts(dept_code));
    fnHideDepts(16);
    fnGotoxy(42, 11);
    printf("%s", dept_name);

    fnGotoxy(42, 12);
    gets(emp_location);

    sprintf(acLine, "%4d%25s%4d%5s%7ld", giEmpCode, emp_name, dept_code, emp_location, tele_num);
    // printf("%s", acLine);
    fnOpenFile(EMP_FILE);
    fnWriteFile(acLine, EMP_FILE);
    fnCloseFile(EMP_FILE);
    fnGotoxy(15, 13);
    printf("Employee Added");
    getch();
    fnEmpMenu();
}

/******************************************************************************
 * Function: fnPrintEmps
 * Description: Prints all the employee details that exist in the
 *		file emp.txt
 * Input Parameters: None
 ******************************************************************************/
void fnPrintEmp()
{
    system("cls");
    fnOpenFile(EMP_FILE);
    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(25, 6);
    printf("======================================");
    fnGotoxy(30, 8);
    printf("Display all the Employees");
    fnGotoxy(30, 9);
    printf("=========================");
    fnGotoxy(15, 11);
    printf("Employee ID");
    fnGotoxy(33, 11);
    printf("Employee Name");
    fnGotoxy(51, 11);
    printf("Department Code");
    fnGotoxy(71, 11);
    printf("Location");
    fnGotoxy(84, 11);
    printf("Phone no.");
    char empDetails[46];
    char emp_name[26];

    int emp_id;
    int dep_id;
    char emp_location[6];
    long int phone_no;
    int i = 0;

    empDetails[45] = '\0';
    emp_name[25] = '\0';
    emp_location[5] = '\0';

    while (fnReadFile(empDetails, EMP_FILE, CURRENT) == 0)
    {
        // printf("%s\n", empDetails);
        // getch();
        sscanf(empDetails, "%4d%25c%4d%5c%ld", &emp_id, &emp_name, &dep_id, &emp_location, &phone_no);

        fnGotoxy(18, 12 + i);
        printf("%d", emp_id);
        fnGotoxy(31, 12 + i);
        trim(emp_name, emp_name);
        printf("%s", emp_name);
        fnGotoxy(54, 12 + i);
        printf("%d", dep_id);
        fnGotoxy(72, 12 + i);
        trim(emp_location, emp_location);
        printf("%s", emp_location);
        fnGotoxy(85, 12 + i);
        printf("%ld", phone_no);
        i = i + 1;
    }
    fnCloseFile(EMP_FILE);
    fnGotoxy(25, 13 + i);
    printf("Enter any key to continue:");
    getch();
    fnEmpMenu();
}

void fnChangeEmpDept()
{
    int dept_code;
    char input[50];
    char empDetails[46];
    char empDetails_t[46];
    char empDetails_n[46];
    char emp_name[26];
    char emp_location[6];
    char dept_name[16];
    int emp_id;
    int dep_id;
    int newDep_id;
    long phone_no;

    dept_name[15] = '\0';

    char ip[50];

    system("cls");
    generatePhoneNumbert();
    fflush(stdin);
    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(15, 3);
    printf("======================================");

    fnGotoxy(20, 5);
    printf("Change Department of Employee");
    fnGotoxy(20, 6);
    printf("=============================");

    fnGotoxy(15, 8);
    printf("Enter the Employee ID");
    fnGotoxy(40, 8);
    printf(": ....");

    fnGotoxy(15, 9);
    printf("Employee Name");
    fnGotoxy(40, 9);
    printf(": _______________");

    fnGotoxy(15, 10);
    printf("Current Department");
    fnGotoxy(40, 10);
    printf(": _______________");

    fnGotoxy(15, 11);
    printf("New Department Code");
    fnGotoxy(40, 11);
    printf(": ....");

    fnGotoxy(15, 12);
    printf("New Department Name");
    fnGotoxy(40, 12);
    printf(": _______________");

    fnGotoxy(15, 14);
    printf("Press any key to continue");

    fnGotoxy(42, 8);
    gets(ip);
    int inemp_id = atoi(ip);
    // check valid emp id
    if (inemp_id == 0)
    {
        fnGotoxy(15, 13);
        printf("Enter a valid Employee ID");
        fnGotoxy(15, 14);
        printf("Press any key to continue");
        getch();
        fnEmpMenu();
    }

    fnOpenFile(EMP_FILE);
    while (fnReadFile(empDetails, EMP_FILE, CURRENT) == 0)
    {
        sscanf(empDetails, "%4d%25c%4d%5c%ld", &emp_id, &emp_name, &dep_id, &emp_location, &phone_no);

        emp_name[25] = '\0';
        emp_location[5] = '\0';

        if (emp_id == inemp_id)
        {
            fnGotoxy(42, 9);
            trim(emp_name, emp_name);
            printf("%s", emp_name);

            fnGotoxy(42, 10);
            fnGetDeptName(dept_name, dep_id);
            printf("%s", dept_name);
            // printf("%d", dep_id);

            fnDisplayDepts(16);
            fnGotoxy(42, 11);
            fflush(stdin);
            scanf("%d", &newDep_id);
            fnHideDepts(16);

            if (fnCheckValidDepts(newDep_id) == 0)
            {
                fnGotoxy(15, 13);
                printf("Department Not Found!!");
                fnGotoxy(15, 14);
                printf("Press any key to continue");
                getch();
                fnEmpMenu();
            }

            fnGetDeptName(dept_name, newDep_id);
            fnGotoxy(42, 12);
            printf("%s", dept_name);

            empDetails_n[45] = '\n';
            phone_no = 0;
            if (aliPhoneNumbert[newDep_id - 1000] == 0)
            {
                phone_no = newDep_id * 1000 + 1;
            }
            else
            {
                phone_no = (newDep_id * 1000) + aliPhoneNumbert[newDep_id - 1000] + 1;
            }
            fnGotoxy(15, 16);
            // printf(">>>>%ld", phone_no);
            sprintf(empDetails_n, "%4d%25s%4d%5s%7ld", emp_id, emp_name, newDep_id, emp_location, phone_no);
            fnUpdateFile(empDetails_n, EMP_FILE);
            fnCloseFile(EMP_FILE);

            fnGotoxy(15, 13);
            printf("Employee Transferred");
            fnGotoxy(15, 14);
            printf("Press any key to continue");
            getch();
            fnEmpMenu();
        }
    }
    fnGotoxy(15, 13);
    printf("Employee Not Found!!");
    fnGotoxy(15, 14);
    printf("Press any key to continue");
    getch();
    fnEmpMenu();
}