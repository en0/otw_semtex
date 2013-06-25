BIN=Solution
OBJ=$(patsubst %.c, %.c.o, $(wildcard *.c))

$(BIN) : $(OBJ)
	$(CC) -o $@ $^

%.c.o : %.c
	$(CC) -o $@ -c $<

.PHONY : clean

clean : 
	$(RM) $(BIN) $(OBJ)


