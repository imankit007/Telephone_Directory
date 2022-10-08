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

#include "Filefunctions.h"

/* Stores the Code of the next department that may be added */
int giDeptCode;

int iFlag;
int iFlag2;

void fnDepartmentMenu();

/******************************************************************************
 * Function: fnInitializeDeptCode
 * Description: Reads all the departments in the department file and initializes
 *		the global variable giDeptCode for any new department to be added to
 *		the system. The Dept file should've been opened in the program already!
 * Input Parameters: None
 ******************************************************************************/

void fnInitializeDeptCode()
{
    char deptDetails[20];
    // char dept_name[4];

    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%d%*s", &giDeptCode);
    }
    // printf("DEPT_CODE: %d \n", giDeptCode);
}

/******************************************************************************
 * Function: fnAddDept
 * Description: Adds a new department entry into the Dept file
 *		The Dept file should've been opened in the program already!
 * Input Parameters: None
 * 	char acDeptName[] - Name of the new dept
 * Returns: Zero on success. 1 if dept name exists already.
 ******************************************************************************/

int fnAddDept(char acDeptName[])
{
    char acLine[20];
    char tempDeptName[16];
    int i;
    for (int i = 1000; i <= giDeptCode; i++)
    {
        if (i == 1000)
            fnReadFile(acLine, DEP_FILE, BEGIN);
        else
            fnReadFile(acLine, DEP_FILE, CURRENT);

        sscanf(acLine, "%*d, %s", tempDeptName);
        if (strcasecmp(acDeptName, acLine) == 0)
        {
            return 1;
        }
    }

    sprintf(acLine, "%4d%15s", giDeptCode, acDeptName);
    fnWriteFile(acLine, DEP_FILE);
    fnCloseFile(DEP_FILE);
    fnDepartmentMenu();
    return 0;
}

/******************************************************************************
 * Function: fnPrintDepts
 * Description: Prints all the department codes and names that exist in the
 *		file dept.txt
 * Input Parameters: None
 ******************************************************************************/

void fnPrintDepts()
{
    system("cls");
    fnOpenFile(DEP_FILE);
    fnGotoxy(25, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(25, 3);
    printf("======================================");
    fnGotoxy(30, 5);
    printf("Display all the Departments");
    fnGotoxy(30, 6);
    printf("===========================");
    fnGotoxy(25, 7);
    printf("Department Code");
    fnGotoxy(50, 7);
    printf("Department Name");
    char deptDetails[20];
    char dept_name[16];

    deptDetails[19] = '\0';
    dept_name[15] = '\0';

    int dept_id;
    int i = 0;
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%4d%15c", &dept_id, &dept_name);
        trim(dept_name, dept_name);
        fnGotoxy(30, 9 + i);
        printf("%d", dept_id);
        fnGotoxy(56, 9 + i);
        printf("%s", dept_name);
        i = i + 2;
    }
    fnGotoxy(25, 11 + i);
    fnCloseFile(DEP_FILE);
    printf("Enter any key to continue :");
    getch();
    fnDepartmentMenu();
}

/******************************************************************************
 * Function: fnAddNewDepartment
 * Description: Allows user to visually add a new department into the system
 * Input Parameters: None
 ******************************************************************************/

void fnAddNewDepartment()
{

    fnOpenFile(DEP_FILE);
    if (giDeptCode == NULL)
        fnInitializeDeptCode();

    char dept_name[20];
    system("cls");
    fnGotoxy(15, 2);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(15, 3);
    printf("======================================");
    fnGotoxy(20, 5);
    printf("Add a Department");
    fnGotoxy(20, 6);
    printf("================");
    fnGotoxy(15, 8);
    printf("Enter Department Name");
    fnGotoxy(40, 8);
    printf(": ...............");
    fnGotoxy(15, 9);
    printf("Department Code");
    fnGotoxy(40, 9);
    printf(": ____");
    giDeptCode++;

    fnGotoxy(42, 9);
    printf("%d", giDeptCode);
    fnGotoxy(15, 12);
    printf("Press any key to continue");
    fnGotoxy(42, 8);
    gets(dept_name);
    if (strlen(dept_name) > 15)
    {
        printf("The Department name should not exceed 15 character");
        printf("Press any key to reenter Department Name");
        getch();
        fnAddNewDepartment();
    }
    else
    {
        if (fnAddDept(dept_name) == 1)
        {
            printf("The Department already exits!!");
            printf("Press any key to reenter Department Name");
            fnAddNewDepartment();
        }
        else
        {
            printf("Department added");
            printf("Enter any key to continue....");
        }
    }
    getch();
    fnDepartmentMenu();
}

/******************************************************************************
 * End of DeptMaint.c
 ******************************************************************************/
