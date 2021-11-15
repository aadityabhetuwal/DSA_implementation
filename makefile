CC = g++
CFLAGS = -g

clean:
	rm *.exe
	rm *.o

$(FILE) : $(FILE).cpp
	$(CC) $(CFLAGS) -o $(FILE) $(FILE).cpp

%.o : %.c
	$(CC) $(CFLAGS) -c %.c