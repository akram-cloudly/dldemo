#include <iostream>

#include "loader.hpp"
#include "mod.hpp"
// Library effective with Linux
#include <unistd.h>

using namespace std;

void main_call()
{
  shared_ptr<Mod> mod = create_mod_instance();
}



int main(int argc, char** argv)
{
  if(argc > 1)
    {
      init(argv[1]);
    }
  else
    {
      init(NULL);
    }
  cout << f1(3) << endl;
  main_call();
  // destroy_mod_instance(mod);
  
  return 0;
}
