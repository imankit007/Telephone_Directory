/******************************************************************************
 * Filename    : TelDir.c
 * Author      : E&R, Infosys Technologies Limited
 * Date        : 04-July-2005
 * Description : Displays the main menu for telephone directory maintenace and
 *				invokes the respective functions
 ******************************************************************************/

/* Include files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>`

/* Declare constants and function prototypes */
#include "filefunctions.h"
#include "functions.h"

/* Forward declaration of functions defined in DeptMaint.c */
int fnInitializeDeptCode();
int fnAddDept(char acDeptName[]);
void fnAddNewDepartment();
void fnPrintDepts();
/* Forward declaration of functions defined in EmpMaint.c */
int fnInitializeEmpCode();
void fnAddNewEmp();
void fnPrintEmp();
void fnAddTeleNum();
/* Forward declaration of functions defined in TeleEnq.c */
void fnEnqByTeleNum();
void fnEnqByName();

/*Function prototype*/
void fnMainMenu();

void fnTeleDirMenu();
void fnLoginValidate(char acUserId[]);

/******************************************************************************
 * Function: fnDisplayTeleDirMenu
 * Description: Displays the Telephone Directory Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 *******************************************************************************/

int fnDisplayTeleDirMenu()
{

	system("cls");
	fnGotoxy(25, 4);
	printf("Telephone Directory Mainatinance System");
	fnGotoxy(25, 5);
	printf("========================================");
	fnGotoxy(25, 7);
	printf("Telephone Directory Maintenance Menu");
	fnGotoxy(25, 8);
	printf("====================================");
	fnGotoxy(25, 10);
	printf("1. Add Telephone Number");
	fnGotoxy(25, 11);
	printf("2. Goto Main Menu");
	fnGotoxy(25, 13);
	printf("Enter your choice :");

	char choice = getch();

	switch (choice)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	default:
		fnGotoxy(25, 13);
		printf("Enter a valid choice");
		fnTeleDirMenu();
	}
}

/******************************************************************************
 * Function: fnDisplayTeleEnqMenu
 * Description: Displays the Telephone Enquiry menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayTeleEnqMenu()
{
	char choice;

	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("========================================");
	fnGotoxy(25, 8);
	printf("Department Maintenance Menu");
	fnGotoxy(25, 9);
	printf("===========================");
	fnGotoxy(25, 11);
	printf("1. Enquiry on Employee Name");
	fnGotoxy(25, 12);
	printf("2. Enquiry on Telephone Number");
	fnGotoxy(25, 13);
	printf("3. Goto Main Menu");
	fnGotoxy(25, 15);
	printf("Enter your choice");

	char cUsrChoice = getch();

	switch (cUsrChoice)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	default:
		fnGotoxy(25, 15);
		printf("Enter a valid choice");
		fnTeleEnqMenu();
	}
}

/******************************************************************************
 * Function: fnTeleEnqMenu
 * Description: Handles the Telephone Enquiry menu. Calls fnDisplayTeleEnqMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/
void fnTeleEnqMenu()
{
	int iUsrChoice = fnDisplayTeleEnqMenu();

	switch (iUsrChoice)
	{
	case 1:
		fnEnqByName();
		break;
	case 2:
		fnEnqByTeleNum();
		break;
	case 3:
		fnMainMenu();
		break;
	}
}

/******************************************************************************
* Function: fnTeleDirMenu
* Description: Handles the Telephone Directory Maintenance menu. Calls
	fnDisplayTeleDirMenu function to display the menu. Choice of user is
	handled by this	function.
* Input Parameters: None
* Returns: None
******************************************************************************/

void fnTeleDirMenu()
{
	int iUsrChoice = fnDisplayTeleDirMenu();

	switch (iUsrChoice)
	{
	case 1:
		fnAddTeleNum();
		break;
	case 2:
		fnMainMenu();
		break;
	default:
		break;
	}
}

/******************************************************************************
 * Function: fnDisplayEmpMenu
 * Description: Displays the Employee Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayEmpMenu()
{
	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("=======================================");
	fnGotoxy(25, 8);
	printf("Employee Maintenance Menu");
	fnGotoxy(25, 9);
	printf("=========================");
	fnGotoxy(25, 11);
	printf("1. Add Employee");
	fnGotoxy(25, 12);
	printf("2. Print Employee Details");
	fnGotoxy(25, 13);
	printf("3. Goto Main Menu");
	fnGotoxy(25, 15);
	printf("Enter your choice : ");

	char cUsrChoice = getch();

	switch (cUsrChoice)
	{
	case '1':
		return 1;
		break;

	case '2':
		return 2;
		break;

	case '3':
		return 3;
		break;

	default:
		fnGotoxy(25, 17);
		printf("Enter a valid choice");
		fnEmpMenu();
		break;
	}
}

/******************************************************************************
 * Function: fnDisplayDepartmentMenu
 * Description: Displays the Department Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayDepartmentMenu()
{
	char choice;
	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("========================================");
	fnGotoxy(25, 8);
	printf("Department Maintenance Menu");
	fnGotoxy(25, 9);
	printf("===========================");
	fnGotoxy(25, 11);
	printf("1. Add Departments");
	fnGotoxy(25, 12);
	printf("2. Print Department Details");
	fnGotoxy(25, 13);
	printf("3. Goto Main Menu");
	fnGotoxy(25, 15);
	printf("Enter your choice : ");

	choice = getch();

	switch (choice)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	default:
		fnGotoxy(25, 15);
		printf("Enter a valid choice!!");
		fnDepartmentMenu();
	}
}

/******************************************************************************
 * Function: fnEmpMenu
 * Description: Handles the Employee Maintenance menu. Calls fnDisplayEmpMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/

void fnEmpMenu()
{
	int iUsrChoice = fnDisplayEmpMenu();

	switch (iUsrChoice)
	{
	case 1:
		fnAddNewEmp();
		break;
	case 2:
		fnPrintEmp();
		break;
	case 3:
		fnMainMenu();
		break;
	default:
		break;
	}
}

/******************************************************************************
 * Function: fnDepartmentMenu
 * Description: Handles the Department menu. Calls fnDisplayDepartmentMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/

void fnDepartmentMenu()
{
	int choice = fnDisplayDepartmentMenu();
	switch (choice)
	{
	case 1:
		fnAddNewDepartment();
		break;
	case 2:
		fnPrintDepts();
		break;
	case 3:
		fnMainMenu();
		break;

	default:
		break;
	}
}

/******************************************************************************
 * Function: fnDisplayMainMenu
 * Description: Displays the main menu of telephone directory system. Then
 *		waits for user's input using scanf function. Until the user types in
 *		a selection, control will not be returned to the calling function.
 * Input Parameters: None
 * Returns: The user's choice
 ******************************************************************************/

int fnDisplayMainMenu()
{
	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("=======================================");
	fnGotoxy(25, 8);
	printf("Main Menu");
	fnGotoxy(25, 9);
	printf("=========");
	fnGotoxy(25, 11);
	printf("1. Department Maintenance");
	fnGotoxy(25, 12);
	printf("2. Employee Maintenance");
	fnGotoxy(25, 13);
	printf("3. Telephone Directory Maintenance");
	fnGotoxy(25, 14);
	printf("4. Telephone Enquiry Menu");
	fnGotoxy(25, 15);
	printf("5. Exit");
	fnGotoxy(25, 17);
	printf("Enter your choice : ");

	char choice = getch();

	switch (choice)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		exit(0);
	default:
		printf("Enter a valid choice");
		fnMainMenu();
	}
}

/******************************************************************************
 * Function: fnMainMenu
 * Description: Calls fnDisplayMainMenu and waits for user's choice. Upon
 *     user's selection, does appropriate action. If user chooses 'exit'
 *     option, returns control back to the calling function.
 * Input Parameters: None
 * Returns : None
 ******************************************************************************/

void fnMainMenu()
{
	int choice = fnDisplayMainMenu();

	switch (choice)
	{
	case 1:
		fnDepartmentMenu();
		break;
	case 2:
		fnEmpMenu();
		break;
	case 3:
		fnTeleDirMenu();
		break;
	case 4:
		fnTeleEnqMenu();
		break;
	}
}

/******************************************************************************
* Function: fnLogin
Description: Check for valid User Id and calls fnMainMenu.
If invalid employee id is entered for User Id, error message "Login Denied"
is displayed and quits the application.
* Input Parameters: None
* Return : None
******************************************************************************/
void fnLogin()
{

	fnLoginScreen();
}

void fnLoginScreen()
{

	char chUserID[10];
	system("cls");
	fnGotoxy(25, 4);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 5);
	printf("========================================");
	fnGotoxy(25, 7);
	printf("Login Screen");
	fnGotoxy(25, 8);
	printf("============");
	fnGotoxy(32, 11);
	printf("Enter User ID 	:  ......");
	// scanf("%s", chUserID);

	getch();
	fnMainMenu();
}
void fnLoginValidate(char acUserId[])
{
}

/******************************************************************************
 * Function: main
 * Description: Entry point of program.
 * Input Parameters: None
 ******************************************************************************/

int main(int argc, char **argv)
{
	/* calling fnLogin function to generate login screen*/
	fnLogin();

	/* Return a success code to Operating System */
	return 0;
}

/******************************************************************************
 * End of TelDir.c
 ******************************************************************************/
