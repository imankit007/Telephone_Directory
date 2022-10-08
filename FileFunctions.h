/******************************************************************************
 * Filename    : FileFunctions.h
 * Author      : Education & Research Dept, Infosys Technologies Limited
 * Date        : 24-Feb-2005
 * Description : Declaration of functions and constants required to use the
 *               functions defined in FileFunctions.c
 * Modification Log:
 ******************************************************************************/

/* Pre-defined constants */

/* Constants to choose Dept file or Employee file */
#define DEP_FILE 1
#define EMP_FILE 2

/* Constants to define position in file */
#define BEGIN 0
#define CURRENT 1

/* Length of records */
#define EMP_RECLEN 50
#define DEPT_RECLEN 50

/* Function declarations */

int fnOpenFile(int iFile);
int fnReadFile(char acLine[], int iFile, int ipos);
void fnWriteFile(char acLine[], int iFile);
int fnUpdateFile(char acLine[], int iFile);
int fnCloseFile(int iFile);

/******************************************************************************
 * End of FileFunctions.h
 ******************************************************************************/
