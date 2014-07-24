#include <node.h>
#include "QtQuery.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
    QtQuery::Init(exports);
}

NODE_MODULE(QtQuery, InitAll)
