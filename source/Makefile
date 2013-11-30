CXX = g++
CXXFLAGS = -Wall -g -MMD

#everything
EXEC = chess
OBJECTS = main.o window.o chessgame.o scoreboard.o gamestate.o square.o action.o chessmove.o castle.o enpassant.o promotion.o resign.o piecefactory.o piece.o rook.o pawn.o knight.o queen.o bishop.o king.o player.o humanplayer.o computerplayer.o playerfactory.o undo.o
DEPENDS = ${OBJECTS:.o=.d}

#for testing
TEST_EXEC = test
TESTOBJECTS = maintest.o window.o chessgame.o scoreboard.o gamestate.o square.o action.o chessmove.o castle.o enpassant.o promotion.o resign.o piecefactory.o piece.o rook.o pawn.o knight.o queen.o bishop.o king.o player.o humanplayer.o playerfactory.o
TESTDEPENDS = ${TESTOBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

${TEST_EXEC}: ${TESTOBJECTS}
	${CXX} ${CXXFLAGS} ${TESTOBJECTS} -o ${TEST_EXEC} -lX11

-include ${TESTDEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC} ${TESTOBJECTS} ${TESTDEPENDS} ${TEST_EXEC} 2> /dev/null
