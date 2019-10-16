SRC=./src
GXX=g++
BIN=./bin

build: ${SRC}/main.cpp ${SRC}/gomoku.cpp
	@mkdir -p ${BIN}
	${GXX} ${SRC}/main.cpp ${SRC}/gomoku.cpp -o ${BIN}/gomoku

clean: gomoku
	rm -rf gomoku