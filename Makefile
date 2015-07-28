#be careful, write directory names without "/"
src_dir := src
include_dir := include
obj_dir := obj
depend_dir := depend

program := bin/test1
source_files := $(wildcard $(src_dir)/*.cpp)
#same as object_files := $(source_files:%.c=%.o)
object_files := $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(source_files))
depend_files := $(patsubst $(src_dir)/%.cpp, $(depend_dir)/%.d, $(source_files))

CC := g++
DFLAG := -MM
IFLAG := $(addprefix -I, $(include_dir))
#  -Q - shows every function that was compiled, and after tells how much time was spend to compile programm
#  -Wconversion - shows warnings when code has implicit type conversion
#  -Wold-style-cast - shows warnings when there is old C-style type conversion or implicit
#  -Wshadow - shows warnings when local variable blocks global variable or another local variable

CFLAGS := -Wall -DDEBUG -Werror -Wshadow -Wold-style-cast -O0 -pedantic-errors -ggdb -pg -std=c++11
LIBS := -lGL -lGLU -lSDL2 -lSDL2_image 

all: $(program)

$(program): $(object_files)
	$(CC) $(CFLAGS) $(object_files) -o $@ $(LIBS)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	$(CC) $(DFLAG) $(IFLAG) -MT $@ $< -o $(patsubst $(src_dir)/%.cpp, $(depend_dir)/%.d, $<)
	$(CC) -c $(CFLAGS) $(IFLAG) $< -o $@

.PHONY: clean
clean:
	rm -rf $(object_files) $(depend_files) $(program) gmon.out

include $(wildcard $(depend_dir)/*.d)
