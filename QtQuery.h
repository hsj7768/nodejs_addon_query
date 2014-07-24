/**
*****************************************************************************
**
** @file QtQuery.h
** QtQuery class를 선언한 파일.
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

#ifndef __QT_QUERY_H__
#define __QT_QUERY_H__

//#include <DatabaseConnector.h>
#include <ocilib.h>


using namespace v8;


/**
 * QtQuery class 선언
 *
 * @par History
 * -# Sungjin.Hong : 2014.04.15 : 최초작성
 */
class QtQuery : public node::ObjectWrap {
public:
    static void Init(v8::Handle<v8::Object> exports);

private:
    explicit QtQuery();
    ~QtQuery();
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> getUserId(const v8::Arguments& args);


    static v8::Persistent<v8::Function> constructor;
};


#endif // __QT_QUERY_H__
