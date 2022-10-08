/******************************************************************************
 * Filename    : Functions.h
 * Author      :
 * Date        :
 * Description : Declaration of functions and constants required to use the
 *               functions defined in
 * Modification Log:
 ******************************************************************************/

/* Function declarations */
void trim(char *dest, char *src);
int fnGetDeptName(char dept_name[], int idept_id);
int fnCheckValidDepts(int idept_id);
void fnHideDepts();
void fnDisplayDepts();
void fnGotoxy(int coord_X, int coord_Y);