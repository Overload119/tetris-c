CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = quadris
OBJECTS = quadris.o cell.o block.o grid.o level.o level0.o level1.o level2.o level3.o window.o
	DEPENDS = ${OBJECTS:.o=.d}

# Remove the -L/usr/X11/lib -I/usr/X11/include if compiling on server.

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
