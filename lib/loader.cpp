#include <cstddef>

#include "loader.hpp"
#include "mod.hpp"


Loader::Loader(const char* _libname)
{
  libname = _libname;
  if(libname)
    {
      dlhandle = dlopen(libname, RTLD_NOW);
      void* (*rf)() = (void* (*)())dlsym(dlhandle, "function_map");
      if(rf)
	{
	  registered_functions = (std::map<std::string, void*>*) rf();
	}
      else
	{
	  registered_functions = new std::map<std::string, void*>();
	}
    }
  else
    {
      registered_functions = new std::map<std::string, void*>();
    }
  
}

void* Loader::get_function(const char* ftag)
{
  if(registered_functions)
    {
      return (*registered_functions)[ftag];
    }
  return NULL;
}
