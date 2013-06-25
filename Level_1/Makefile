BIN=analizer
BIN_OBJ=analizer.o

TST=semtex1
TST_OBJ=semtex1.o

REV=semtex1_decrypt
REV_OBJ=semtex1_decrypt.o

.PHONY : all

ALL : $(BIN) $(TST) $(REV)

$(BIN) : $(BIN_OBJ)
	$(CC) -o $@ $^

$(TST) : $(TST_OBJ)
	$(CC) -o $@ $^

$(REV) : $(REV_OBJ)
	$(CC) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $<

.PHONY : clean

clean : 
	$(RM) $(BIN) $(BIN_OBJ) $(TST) $(TST_OBJ) $(REV) $(REV_OBJ)


