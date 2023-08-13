CC = gcc
TARGET = main
SRC = main.c src/config/configParser.c

CFLAGS =
FLAGS =
LIBS =  -ljson-c

INC=-Iinclude/


OBJ = $(SRC:%.cpp=%.o)

%.cpp.o: 
	$(CC) -c $(CFLAGS) $<  -o $@ 
$(TARGET): $(OBJ)
	$(CC) $(FLAGS)  -o $(TARGET) $(OBJ) $(LIBS) $(INC)
clean:
	rm *.o $(TARGET) 