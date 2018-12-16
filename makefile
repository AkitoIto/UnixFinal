CC := gcc
EXEC := pi mighty dealer hand pitboss
SRC := pi.c
CFLAG := -Wall
#GSL header file and library
INC := -I ~/src/include
LIB := -L ~/src/lib -lgsl -lgslcblas
$(EXEC):
	$(CC) $(CFLAG) -o pi -lm -I ~/src/include -L ~/src/lib $(SRC) -lgsl -lgslcblas 
	$(CC) $(CFLAG) -o mighty mighty.c
	$(CC) $(CFLAG) -o dealer dealer.c -lm -I ~/src/include -L ~/src/lib -lgsl -lgslcblas 
	$(CC) $(CFLAG) -o hand hand.c -lm $(INC) $(LIB)
	$(CC) $(CFLAG) -o pitboss pitboss.c
clean:
	rm -f $(EXEC)
	rm -f bar.txt
