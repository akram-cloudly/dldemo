CC = g++
CFLAGS = -g
CPPFLAGS = 
TARGET = dldemo


SUBDIR = src lib

SRCS = $(wildcard *.cpp $(foreach fd, $(SUBDIR), $(fd)/*.cpp))

OUTDIR = ./bin
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:cpp=o))

MAIN_OBJS = $(OBJDIR)/src/main.o $(OBJDIR)/lib/loader.o $(OBJDIR)/lib/mod.o


INCLUDE_DIR = ./inc
INCS = $(wildcard *.hpp $(foreach fd, $(INCLUDE_DIR), $(fd)/*.hpp))

.PHONY: clean echoes


all: $(TARGET)

clean:
	rm -rf "$(OBJDIR)" "$(OUTDIR)"

mod: $(OUTDIR)/mod_a.so $(OUTDIR)/mod_b.so

$(TARGET): $(MAIN_OBJS) $(INCS)
	mkdir -p $(OUTDIR)
	$(CC) -o $(OUTDIR)/$@ $(MAIN_OBJS)

$(OBJDIR)/%.o: %.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_DIR)


$(OBJDIR)/mod_a.o: mod/mod_a.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_DIR) -fPIC

$(OBJDIR)/mod_b.o: mod/mod_b.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_DIR) -fPIC


$(OUTDIR)/mod_a.so: $(OBJDIR)/mod_a.o
	$(CC) -o $@ $< -shared
$(OUTDIR)/mod_b.so: $(OBJDIR)/mod_b.o
	$(CC) -o $@ $< -shared

echoes:
	@echo "INC files: $(INCS)"  
	@echo "SRC files: $(SRCS)"
	@echo "OBJ files: $(OBJS)"
