PRO=cjk_string
SOURCE=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SOURCE))

all:${PRO}

${PRO}:${OBJ}
	g++ -o $@ $^

clean:
	rm -f ${OBJ} ${PRO}