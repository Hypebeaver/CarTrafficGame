CC = gcc
CFLAGS = -Wall -pedantic -Werror -ansi
OBJ = traffic.o fileIO.o map.o random.o car.o move.o terminal.o PlayerAndCar.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

car.o : car.c car.h macro.h random.h PlayerAndCar.h
	$(CC) $(CFLAGS) -c car.c

fileIO.o : fileIO.c fileIO.h PlayerAndCar.h car.h
	$(CC) $(CFLAGS) -c fileIO.c

move.o : PlayerAndCar.h move.h
	$(CC) $(CFLAGS) -c move.c

map.o : map.c map.h PlayerAndCar.h
	$(CC) $(CFLAGS) -c map.c

random.o : random.c random.h
	$(CC) $(CFLAGS) -c random.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

PlayerAndCar.o : PlayerAndCar.h macro.h
	$(CC) $(CFLAGS) -c PlayerAndCar.c

traffic.o : traffic.c fileIO.h PlayerAndCar.h map.h macro.h terminal.h car.h move.h
	$(CC) $(CFLAGS) -c traffic.c

clean :
	rm -f $(EXEC) $(OBJ)
