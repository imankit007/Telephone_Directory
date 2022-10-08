

#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#include "FileFunctions.h"
#include "Functions.h"

void fnGotoxy(int coord_X, int coord_Y)
{
    COORD coord;

    coord.X = coord_X;
    coord.Y = coord_Y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void trim(char *dest, char *src)
{
    if (!src || !dest)
        return;

    int len = strlen(src);

    if (!len)
    {
        *dest = '\0';
        return;
    }
    char *ptr = src + len - 1;

    // remove trailing whitespace
    while (ptr > src)
    {
        if (!isspace(*ptr))
            break;
        ptr--;
    }

    ptr++;

    char *q;
    // remove leading whitespace
    for (q = src; (q < ptr && isspace(*q)); q++)
        ;

    while (q < ptr)
        *dest++ = *q++;

    *dest = '\0';
}

int fnGetDeptName(char dept_name[], int idept_id)
{
    char deptDetails[20];
    int dept_id;
    fnOpenFile(DEP_FILE);
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%4d%15c", &dept_id, dept_name);
        trim(dept_name, dept_name);
        if (idept_id == dept_id)
        {
            fnCloseFile(DEP_FILE);
            return 1;
        }
    }
    fnCloseFile(DEP_FILE);
    return 0;
}

int fnCheckValidDepts(int idept_id)
{
    char deptDetails[20];
    int dept_id;
    char dept_name[16];
    // dept_name = "ece";
    fnOpenFile(DEP_FILE);
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%d%s", &dept_id, &dept_name);
        if (idept_id == dept_id)
        {
            fnGotoxy(48, 13);
            printf("%s", dept_name);
            fnCloseFile(DEP_FILE);
            return 1;
        }
    }
    fnCloseFile(DEP_FILE);
    return 0;
}

void fnHideDepts()
{
    fnOpenFile(DEP_FILE);
    char deptDetails[20];
    int i = 0, j;
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        fnGotoxy(30, 20 + i);
        for (j = 0; j < 40; j++)
        {
            printf(" ");
        }
        i++;
    }
    fnCloseFile(DEP_FILE);
}

void fnDisplayDepts()
{
    fnOpenFile(DEP_FILE);
    char deptDetails[20];
    char dept_name[16];
    int dept_id;
    int i = 0;
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%4d%s", &dept_id, &dept_name);
        fnGotoxy(30, 20 + i);
        printf("%d", dept_id);
        fnGotoxy(56, 20 + i);
        printf("%s", dept_name);
        i++;
    }
    fnCloseFile(DEP_FILE);
}