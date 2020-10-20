CXX = g++
CXXFLAGS = -std=c++14 -O3
SRC = src/direction.cpp src/maze.cpp src/main.cpp
OBJ = direction.o maze.o main.o
PROGNAME = maze

maze: ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ ${OBJ}

all:
	${CXX} ${CXXFLAGS} ${SRC} -o ${PROGNAME}

${OBJ}:
	${CXX} ${CXXFLAGS} ${SRC} -c

clean:
	rm -rf *.o *.txt ${PROGNAME}