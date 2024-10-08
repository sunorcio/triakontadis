# to compile for linux, get the following binaries from its source or from your own distribution:
#  glew - https://github.com/nigels-com/glew
#  SDL2 - https://github.com/libsdl-org/SDL
#  opengl drivers




default_rule: test




#(linux^windows)
TARGET_OS = linux
#(dynamic^static)
TARGET_BUILD = dynamic
#(off^on)
TARGET_DEBUG = off
TARGET_BIN = isola_example




ifeq (${TARGET_OS},linux)
 CC = clang
else ifeq (${TARGET_OS},windows)
 CC = x86_64-w64-mingw32-gcc
else
 $(error wrong TARGET_OS value)
endif

ifeq (${TARGET_BUILD},dynamic)
else ifeq (${TARGET_BUILD},static)
else
 $(error wrong TARGET_BUILD value)
endif

ifeq (${TARGET_DEBUG},on)
else ifeq (${TARGET_DEBUG},off)
else
 $(error wrong TARGET_BUILD value)
endif




HDR = ${shell find . -type f -name '*.h' ! -path '*/bin/*'} #${wildcard ./*.h} ${wildcard isola/*.h} ${wildcard scene/*/*.h} ${wildcard module/*/*.h}
SRC = ${shell find . -type f -name '*.c' ! -path '*/bin/*'} #${wildcard ./*.c} ${wildcard ./isola/*.c} ${wildcard ./scene/*/*.c} ${wildcard module/*/*.c}
OBJ = ${SRC:.c=.o}

GLOBALDEPS = bin Makefile ${HDR} #${SRC}




ifeq (${TARGET_OS},linux)

 INCS = -I./

 ifeq (${TARGET_BUILD},dynamic)
  LIBS = -lSDL2 -lGLEW -lGLU -lGL -lm
 else ifeq (${TARGET_BUILD},static)
  LIBS = -Wl,-Bstatic -lSDL2 -lGLEW -Wl,-Bdynamic -lGLU -lGL ${shell sdl2-config --static-libs}
 endif


 #CFLAGS = -DISOLA_DBG -DGLEW_STATIC -Weverything
 CFLAGS = ${INCS} -Wall -Wextra -pedantic -std=c89 -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable -Wno-unused-result \
		  -Wno-sign-compare -MJ $@.json -Wno-c99-designator -Wno-unsafe-buffer-usage -O0 -pipe -march=native -D_REENTRANT
 #LDFLAGS = -v
 LDFLAGS = ${LIBS} -flto=full

 ifeq (${TARGET_DEBUG},on)
  #CFLAGS += -Weverything
  CFLAGS += -g
 endif


else ifeq (${TARGET_OS},windows)

 INCS = -I./ -I./bin/glew-2.2.0/include -I./bin/SDL2-2.30.3/x86_64-w64-mingw32/include
 LIBS = -L./bin/glew-2.2.0/lib/Release/x64 -L./bin/SDL2-2.30.3/x86_64-w64-mingw32/lib \
		-Wl,-Bstatic -static-libgcc -lmingw32 -lSDL2main -lSDL2 -lglew32s -lglu32 -lopengl32 -lm \
		-ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -lsetupapi -lcfgmgr32 -luuid


 #CFLAGS = -DISOLA_DBG #-g
 CFLAGS = ${INCS} -Wall -Wextra -Wpedantic -std=c89 -O3 -pipe -DGLEW_STATIC -D_REENTRANT -DWIN32_LEAN_AND_MEAN \
		  -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable -Wno-unused-result -Wno-sign-compare -Wno-old-style-declaration
 #LDFLAGS = #-v #-mwindows
 LDFLAGS = ${LIBS}

 ifeq (${TARGET_DEBUG},on)
 endif


endif




${OBJ}:%.o : %.c
	${CC} -c $< -o $@ ${CFLAGS}

${OBJ}: ${GLOBALDEPS}




ifeq (${TARGET_OS},linux)

test: ${TARGET_BIN} compdb
	./${TARGET_BIN}
#	make clean

bin:
	mkdir bin


else ifeq (${TARGET_OS},windows)

test: ${TARGET_BIN}
#	make clean

bin:
	mkdir bin
	wget https://github.com/libsdl-org/SDL/releases/download/release-2.30.3/SDL2-devel-2.30.3-mingw.zip -P bin/
	wget https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip -P bin/
	unzip bin/SDL2* -d bin/
	unzip bin/glew* -d bin/
	rm bin/*.zip -f


endif




all: ${TARGET_BIN}

${TARGET_BIN}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

compdb: ${OBJ}
	./compdb.sh

clean:
	rm ${OBJ} -f
	rm ${OBJ:.o=.o.json} -f

update: clean
	rm bin -rf

ISOLA_DIR = ~/main/isola/isola
isola:
	cp ${ISOLA_DIR} . -r

windows:
	make TARGET_OS=windows TARGET_BUILD=static




.PHONY: default_rule test all clean compdb update isola windows
