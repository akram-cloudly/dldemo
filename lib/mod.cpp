#include <cstddef>

#include "loader.hpp"
#include "mod.hpp"

const char* configured_libname = NULL;
Loader* loader = NULL;

void* function_map()
{
  return NULL;
}

int init(const char* libname)
{
  if(configured_libname == NULL)
    {
      configured_libname = libname;
      loader = new Loader(libname);
    }
  
  return 0;
}



int f1(int arg)
{
  capture_source_as_str(int (*f1)(int), ftag);
  f1 = (int (*)(int)) loader->get_function(ftag);
  if(f1)
    {
      return f1(arg);
    }
  return -1;
}





Mod* create_mod_instance()
{
  return NULL;
}

void destroy_mod_instance(Mod* ptr)
{
  
}
