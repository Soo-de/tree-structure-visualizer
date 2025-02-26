# COMPILER AND FLAGS
CXX = mingw32-g++
CXXFLAGS = -I./include -std=c++11

# FILES
SRCS = src\main.cpp src\listmanipulator.cpp src\node.cpp src\bstnode.cpp
OBJS = $(SRCS:src\%.cpp=lib\%.o)

# OUTPUT FILE
EXEC = .\bin\my_program.exe

# MAKE
all: compile run

# COMPILE
compile: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# OBJECT FILES
lib\%.o: src\%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# RUN
run:
	$(EXEC)

# CLEAR
clean:
	del /Q lib\*.o $(EXEC)
