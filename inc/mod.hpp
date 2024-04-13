

class Mod
{

};

extern "C"
{
  void* function_map();
};

int init(const char* libname);
int f1(int arg);

#define capture_source_as_str(src, strname) src; const static char* strname = #src;
