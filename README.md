nodejs_addon_query
==================

ocilib를 사용하여 C++에서 oracle 데이터를 출력.

ocilib v3.12.1 사용
http://orclib.sourceforge.net/


****************example*******************
#include "ocilib.h"
 
int main(int argc, char *argv[])
{
    OCI_Connection* cn;
    OCI_Statement* st;
    OCI_Resultset* rs;
 
    OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);
 
    cn = OCI_ConnectionCreate("db", "usr", "pwd", OCI_SESSION_DEFAULT);
    st = OCI_StatementCreate(cn);
 
    OCI_ExecuteStmt(st, "select intcol, strcol from table");
 
    rs = OCI_GetResultset(st);
 
    while (OCI_FetchNext(rs))
    {
        printf("%i - %s\n", OCI_GetInt(rs, 1), OCI_GetString(rs,2));
    }
 
    OCI_Cleanup();
 
    return EXIT_SUCCESS;
}
******************************************
