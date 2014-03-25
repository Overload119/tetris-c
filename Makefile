CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = quadris
OBJECTS = quadris.o grid.o level.o level0.o block.o cell.o
	DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
