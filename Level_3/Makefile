BIN=brute
BIN_OBJ=$(BIN).o lock.o

TST=semtex3
TST_OBJ=$(TST).o lock.o

TARGETS=$(BIN) $(TST)
OBJS=$(BIN_OBJ) $(TST_OBJ)

.PHONY : all

all : $(TARGETS)
$(BIN) : $(BIN_OBJ)
$(TST) : $(TST_OBJ)

$(TARGETS) : 
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $<

.PHONY : clean

clean : 
	$(RM) $(TARGETS) $(OBJS)


