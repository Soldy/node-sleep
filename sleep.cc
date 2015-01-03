#ifndef BUILDING_NODE_EXTENSION
#define BUILDING_NODE_EXTENSION
#endif // BUILDING_NODE_EXTENSION

#include <v8.h>
#include <node.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace v8;
using namespace node;


RETURNTYPE Sleep(const ARGUMENTS& args) {
  SCOPE;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    EXCEPTION("Expected number of seconds");
  }

  sleep(args[0]->Uint32Value());

  RETURN;
}

RETURNTYPE USleep(const ARGUMENTS& args) {
  SCOPE;

  if (args.Length() < 1 || !args[0]->IsUint32()) {
    EXCEPTION("Expected number of micro");
  }

  usleep(args[0]->Uint32Value());

  RETURN;
}


extern "C" void init(Handle<Object> target) {
  NODE_SET_METHOD(target, "sleep", Sleep);
  NODE_SET_METHOD(target, "usleep", USleep);
}


#ifdef NODE_MODULE
NODE_MODULE(node_sleep, init)
#endif

