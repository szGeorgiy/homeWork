CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = program

all: $(TARGET)

$(TARGET): kurs.o
	$(CC) $(CFLAGS) -o $(TARGET) kurs.o -lm

kurs.o: kurs.c
	$(CC) $(CFLAGS) -c kurs.c

clean:
	rm -f $(TARGET) *.o