CC = gcc
CFLAGS = -W -Wall
TARGET = test

all : $(TARGET)
$(TARGET) : test.c
	$(CC) $(CFLAGS) -o $(TARGET) test.c

clean:
	rm -f *.o test
