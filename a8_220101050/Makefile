CC = gcc
YACC = bison
LEX = flex

ROLL_NO = 220101050

all: $(ROLL_NO)

$(ROLL_NO): $(ROLL_NO).tab.c lex.yy.c
	$(CC) -o $@ $^ -lm

$(ROLL_NO).tab.c $(ROLL_NO).tab.h: $(ROLL_NO).y
	$(YACC) -d $<

lex.yy.c: $(ROLL_NO).l $(ROLL_NO).tab.h
	$(LEX) $<

clean:
	rm -f $(ROLL_NO) lex.yy.c $(ROLL_NO).tab.c $(ROLL_NO).tab.h

test: $(ROLL_NO)
	./$(ROLL_NO)
