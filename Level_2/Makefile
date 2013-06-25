.PHONY : all
	
all : evil.so semtex2

evil.so : evil.c
	$(CC) -o $<.o -c $<
	$(CC) -shared -o $@ $<.o

semtex2 : semtex2.c
	$(CC) -o $@ $^

.PHONY : clean
	
clean : 
	$(RM) evil.so evil.c.o semtex2


