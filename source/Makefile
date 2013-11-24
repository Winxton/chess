CXX = g++
CXXFLAGS = -Wall -g -MMD

#everything
EXEC = chess
OBJECTS = main.o gamestate.o square.o chessmove.o piecefactory.o piece.o rook.o
DEPENDS = ${OBJECTS:.o=.d}

#for testing
TEST_EXEC = test
TESTOBJECTS = maintest.o
TESTDEPENDS = ${TESTOBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

${TEST_EXEC}: ${TESTOBJECTS}
	${CXX} ${CXXFLAGS} ${TESTOBJECTS} -o ${TEST_EXEC}

-include ${TESTDEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC} ${TESTOBJECTS} ${TESTDEPENDS} ${TEST_EXEC} 2> /dev/null
