CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = quadris
OBJECTS = quadris.o cell.o block.o grid.o level.o level0.o level1.o
	DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
