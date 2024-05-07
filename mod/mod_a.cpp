#include <iostream>
#include <cstddef>
#include <map>
#include <string>
#include <memory>


#include "mod.hpp"

using namespace std;

class Mod_a : public Mod{
  public:
  ~Mod_a()
  {
    std::cout << "Mod_a destructor is running" << std::endl;
  }
};

void* function_map()
{
  std::map<std::string, void*> *registered_functions;
  registered_functions = new std::map<std::string, void*>();
  (*registered_functions)["int (*f1)(int)"] = (void*) f1;
  (*registered_functions)["shared_ptr<Mod> (*create_mod_instance)()"] = (void*) create_mod_instance; 
  
  return registered_functions;
}



int f1(int arg)
{
  cout << "mod_a f1(" << arg << ")" << endl;
  return arg * arg;
}

shared_ptr<Mod> create_mod_instance()
{
  // Mod *mod_a = new Mod_a();
  
  cout << "mod_a create_mod_instance" << endl;

  return make_shared<Mod_a> ();
}




