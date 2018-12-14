CC := gcc
EXEC := pi
SRC := pi.c


$(EXEC):
	$(CC) -o $(EXEC) -lm -I ~/src/include -L ~/src/lib $(SRC) -lgsl -lgslcblas 

clean:
	rm -f $(EXEC)
