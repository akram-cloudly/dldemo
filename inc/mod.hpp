#include <iostream>
#include <memory>

class Mod
{
  public:
  ~Mod()
  {
    std::cout << "Mod destructor is running" << std::endl;
  }

};

extern "C"
{
  void* function_map();
};

int init(const char* libname);
int f1(int arg);
std::shared_ptr<Mod> create_mod_instance();
 void destroy_mod_instance(Mod* ptr);

#define capture_source_as_str(src, strname) src; const static char* strname = #src;


