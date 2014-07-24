/**
*****************************************************************************
**
** @file QtQuery.cpp
** QtQuery를 정의한 파일.
**
** Copyright (C) 2009 Nousco Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nousco Corporation (ehr-info@nousco.com)
**
** @par History
** -# Sungjin.Hong : 2014.04.15 : 최초작성
**
****************************************************************************/
/* vi: set ts=4 sw=4 sts=4 expandtab: */

#include <node.h>
#include "QtQuery.h"


using namespace v8;


Persistent<Function> QtQuery::constructor;


/**
 * @brief 생성자
 *
 * @par History
 * -# Sungjin.Hong : 2014.04.15 : 최초작성
 */
QtQuery::QtQuery(){}



/**
 * @brief 생성자
 *
 * @par History
 * -# Sungjin.Hong : 2014.04.15 : 최초작성
 */
QtQuery::~QtQuery(){}



/**
 * @brief 초기화
 *
 * @par History
 * -# Sungjin.Hong : 2014.07.20 : 최초작성
 */
void QtQuery::Init(Handle<Object> exports) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("QtQuery"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prepare Property
    tpl->PrototypeTemplate()->Set(String::NewSymbol("getUserId"),
            FunctionTemplate::New(getUserId)->GetFunction());

    // constructor
    constructor = Persistent<Function>::New(tpl->GetFunction());
    exports->Set(String::NewSymbol("QtQuery"), constructor);
}



Handle<Value> QtQuery::getUserId(const Arguments& args)
{
    HandleScope scope;

    /*
    qDebug() << "QtQuery::getUserId";

    QString findStartDay;
    findStartDay = "SELECT USID ";
    findStartDay += "FROM NMBI_USER ";

    qDebug() << findStartDay;

    DatabaseConnector* dc = DatabaseConnector::getInstance();

    qDebug() << "DatabaseConnector getInstance()";

    QSqlQuery result = dc->dbExecuteQuery(findStartDay);

    qDebug() << "query result : ";

    if (result.isActive()) {
        while (result.next()) {
            qDebug() << result.value(0).toString();
        }
    }

    qDebug() << "return result";
    */


    OCI_Connection* cn;
    OCI_Statement* st;
    OCI_Resultset* rs;
 
    OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT);
 
    //cn = OCI_ConnectionCreate("ORA8I_K", "nousco", "nousco123", OCI_SESSION_DEFAULT);
    cn = OCI_ConnectionCreate("192.168.100.55:1521/orcl", "nousco", "nousco123", OCI_SESSION_DEFAULT);
    st = OCI_StatementCreate(cn);

    printf("SELECT * FROM NMBI_USER\n");
 
    OCI_ExecuteStmt(st, "SELECT USID FROM NMBI_USER");
 
    rs = OCI_GetResultset(st);
 
    while (OCI_FetchNext(rs))
    {
        printf("%s\n", OCI_GetString(rs, 1));
    }
 
    OCI_Cleanup();


    return scope.Close(String::New("test"));
}



/**
 * @brief New Operator
 *
 * @param args : 생성자
 * @return QtQuery Instance
 *
 * @par History
 * -# Sungjin.Hong : 2014.07.22 : 최초작성
 */
Handle<Value> QtQuery::New(const Arguments& args) {
    HandleScope scope;

    if (args.IsConstructCall()) {
        QtQuery* obj = new QtQuery();
        obj->Wrap(args.This());

        return args.This();

    } else {
        const unsigned argc = 1;
        Local<Value> argv[argc] = { args[0] };

        return scope.Close(constructor->NewInstance(argc, argv));
    }
}

