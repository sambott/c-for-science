/* We really don't want UNICODE here */
#undef UNICODE

/* if we are building in Windows, use the Windows header file 
unixODBC does not require this.
*/
#ifdef WIN32
#include <Windows.h>
#endif /* WIN32 */

#include <sqlext.h>
#include <stdio.h>

/*
This is a basic C program that makes use of ODBC to connect to a data source (named "ccoursetest").

One can set this datasource up using the Windows ODBC datamanager at "C:\Windows\SysWOW64\odbcad32.exe",
or by using /usr/bin/ODBCConfig (via "yum install unixODBC unixODBC-devel unixODBC-kde")

The database can be anything the OS supports (I tested MS Access and Linux MySQL).

If compiling under Linux:
gcc odbctest.c -o odbctest -lodbc -ggdb

*/


int main()
{
	SQLHENV		lpEnv = NULL;
	SQLHDBC		lpDbc = NULL;
	SQLHSTMT	lpStmt = NULL;
	SQLSMALLINT numCols = 0;

	/* This DSN needs to be created in the odbc administrator (I created it in user variables) */
	char *pszConnStr = "DSN=ccoursetest"; 

	/* "Table1" contains 3 columns, [1] Integer ID, [2] String name, [3] Integer Number */
	char *pszSQLStatement = "SELECT * FROM Table1;"; 

	SQLLEN		ind1, ind2, ind3;
	SQLUINTEGER col1, col3;
	SQLCHAR	col2[1024];
	SQLRETURN	rval;


	/* Allocate an environment handle */
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &lpEnv) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to allocate an environment handle.\n");
		return(-1);
	}

	/* Set an environment variable - ODBC 2 please */
	if (SQLSetEnvAttr(lpEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC2, 0) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to request ODBC v2 behaviour.\n");
		return -1;
	}

	/* Allocate a handle for the connection */
	if (SQLAllocHandle(SQL_HANDLE_DBC,lpEnv,&lpDbc) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to allocate connection handle.\n");
		return -1;
	}

	/* Make the SQL connection, again please note that "ccoursetest" must be set up with the ODBC data manager */
	if (SQLDriverConnect(lpDbc, SQL_NULL_HANDLE, pszConnStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT) != SQL_SUCCESS)
	{
		SQLCHAR sqlState[6] = {0};
		SQLINTEGER sqlNativeError = 0;
		SQLCHAR messageText[1024] = {0};
		SQLSMALLINT textLength = 0;
		if (SQLGetDiagRec(SQL_HANDLE_DBC, lpDbc, 1, sqlState, &sqlNativeError, messageText, sizeof(messageText)/sizeof(messageText[0]),
 		&textLength) == SQL_SUCCESS)
		{
			fprintf(stderr, "STATE: %s, Message %s\n", sqlState, messageText);
		}
		fprintf(stderr, "Unable to connect to datasource.\n");
		return -1;
	}

	/* Allocate a hanlde for the SQL statement we're going to make */
	if (SQLAllocHandle(SQL_HANDLE_STMT, lpDbc, &lpStmt) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to allocate statement handle.\n");
		return -1;
	}

	/* Execute our SQL SELECT */
	if (SQLExecDirect(lpStmt, pszSQLStatement, SQL_NTS) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to execute SQL statement.\n");
		return -1;
	}

	/* Retrieve the number of columns returned */
	if (SQLNumResultCols(lpStmt, &numCols) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to retrieve column count returned from statement.\n");
		return -1;
	}

	/* We are expecting three columns in this example */
	if (numCols != 3)
	{
		fprintf(stderr, "Expected 3 results in SQL query, got %d instead.\n", numCols);
		return -1;
	}

	/*
		The results from our SQL query are bound to variables in memory directly,
		note that the column numbering starts at 1!

		Column 1 - "ID" - an integer ID
		Column 2 - "Name" - a SQL string
		Column 3 - "Number" - a SQL integer
	*/
	if (SQLBindCol(lpStmt, 1, SQL_C_ULONG, &col1, sizeof(col1), &ind1) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to bind column 1.\n");
		return -1;
	}

	if (SQLBindCol(lpStmt, 2, SQL_C_CHAR, col2, sizeof(col2), &ind2) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to bind column 2.\n");
		return -1;
	}

	if (SQLBindCol(lpStmt, 3, SQL_C_ULONG, &col3, sizeof(col3), &ind3) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to bind column 3.\n");
		return -1;
	}

	/*
		Now we have bound everything, we ask SQL to Fetch the data,
		a Fetch will populate the variables we've just bound and return SQL_SUCCESS.

		If we've gone through all the rows, it will return SQL_NO_DATA - and we're done.
	*/

	for(;;)
	{
		rval = SQLFetch(lpStmt);

		if (rval == SQL_ERROR)
		{
			fprintf(stderr, "Unable to fetch data.\n");
			return -1;
		}

		if (rval == SQL_NO_DATA)
		{
			fprintf(stderr, "Finished displaying all records.\n");
			break;
		}

		/* literally just print the data out*/
		printf("%d %s %d\n", col1, col2, col3);
	}

	/* Now that we've finished, we need to de-allocate everything we've allocated */

	if (SQLFreeStmt(lpStmt, SQL_CLOSE) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to free statement handle.\n");
		return -1;
	}

	if (SQLDisconnect(lpDbc) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to disconnect from datasource.\n");
		return -1;
	}

	if (SQLFreeConnect(lpDbc) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to free connection handle.\n");
		return -1;
	}

	if (SQLFreeEnv(lpEnv) != SQL_SUCCESS)
	{
		fprintf(stderr, "Unable to free environment handle.\n");
		return -1;
	}
	
	fprintf(stderr, "Program execution completed successfully!\n");
	return 0;
}
