#include <cstddef>

#include "loader.hpp"
#include "mod.hpp"

using namespace std;

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




shared_ptr<Mod> create_mod_instance()
{

  capture_source_as_str(shared_ptr<Mod> (*create_mod_instance)(), ftag);
  create_mod_instance = (shared_ptr<Mod> (*)()) loader->get_function(ftag);
  if(create_mod_instance)
    {
      return create_mod_instance();
    }
  return NULL;
}

void destroy_mod_instance(std::shared_ptr<Mod> ptr)
{
  // delete ptr;
}
