CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = primefactor

all: $(TARGET)

$(TARGET): primefactor.o
	$(CC) $(CFLAGS) $^ -o $@

primefactor.o: primefactor.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
