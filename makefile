PROG = clue 
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o basicSatchel.o eat.o entertain.o game.o map.o queueSatchel.o quiet.o satchel.o space.o vectorSatchel.o
SRCS = main.cpp basicSatchel.cpp eat.cpp entertain.cpp game.cpp map.cpp queueSatchel.cpp quiet.cpp satchel.cpp space.cpp vectorSatchel.cpp

HEADERS = basicSatchel.hpp eat.hpp entertain.hpp game.hpp map.hpp queueSatchel.hpp quiet.hpp satchel.hpp space.hpp vectorSatchel.hpp

${PROG}: ${OBJS}
	${CXX} ${OBJS} -o ${PROG}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${PROG}
