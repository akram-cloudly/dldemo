#include <iostream>
#include <cstddef>
#include <map>
#include <string>


#include "mod.hpp"

using namespace std;

void* function_map()
{
  std::map<std::string, void*> *registered_functions;
  registered_functions = new std::map<std::string, void*>();

  (*registered_functions)["int (*f1)(int)"] = (void*) f1;
  
  return registered_functions;
}



int f1(int arg)
{
  cout << "mod_b f1(" << arg << ")" << endl;
  return arg * arg * arg;
}




