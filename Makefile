#### Start of system configuration section ####

# use gcc or gcc-3.3

CC = gcc
LD = gcc
PROG = sha.so
CXX = gcc
CPP = gcc

# Compiler flags
# NOTE: add -g for debug, remove for release!
CPPFLAGS = -MD -Wall -I./
LDFLAGS = -fPIC -shared -Wl,-soname,$(PROG).1,-R./
LIBS = -lpthread -lstdc++ -L../../vendor/lua/src/.libs -llua

#### End of system configuration section ####

#### Source and object files

SRC_LOCAL =		$(wildcard ./*.cpp ./extra/*.cpp)
SRC_SHA   =		$(wildcard ./sha/sha1.c)
OBJ_LOCAL =		$(patsubst %.cpp,%.o,$(SRC_LOCAL))
OBJ_SHA   =		$(patsubst %.c,%.o,$(SRC_SHA))
OBJS	= $(OBJ_SHA) $(OBJ_LOCAL)
SRCS	= $(SRC_SHA) $(SRC_LOCAL)
DEPS	= $(patsubst %.o,%.d,$(OBJS))

#### Make rules

all : sha

sha : $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o $(PROG) $(OBJS) $(LIBS)

clean :
	@rm *.o
	@rm $(PROG)

-include $(DEPS)
