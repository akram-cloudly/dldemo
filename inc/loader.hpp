#include <map>
#include <string>
#include <dlfcn.h>

class Loader
{
private:
  const char* libname;
  void* dlhandle;
  std::map<std::string, void*> *registered_functions;

public:
  Loader(const char* libname);
  void* get_function(const char* ftag);
};
