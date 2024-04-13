#include <iostream>

#include "loader.hpp"
#include "mod.hpp"

using namespace std;





int main(int argc, char** argv)
{
  if(argc > 1)
    {
      init(argv[1]);
    }
  cout << f1(3) << endl;


  
  return 0;
}
