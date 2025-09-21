# CC = gcc
# LEX = lex
# RM = rm -f

# TARGET_LEX = lexi.l
# LEX_C = lex.yy.c
# MAIN = lexical_analyzer.c

# EXEC = a.out
# TEST = test.nc
# OUTPUT = output.txt

# $(EXEC): $(LEX_C)
# 	$(CC) $(LEX_C) $(MAIN)

# $(LEX_C): $(TARGET_LEX)
# 	$(LEX) $(TARGET_LEX)

# clean:
# 	$(RM) $(LEX_C) $(EXEC) $(OUTPUT)

# run: $(EXEC)
# 	./$(EXEC) $(TEST) && ./$(EXEC) $(TEST) > $(OUTPUT)

a.out: lex.yy.c
	gcc lex.yy.c lexical_analyzer.c

lex.yy.c: lexi.l
	flex lexi.l 

clean: 
	rm a.out 
	rm -f lex.yy.c
	rm output.txt

run: 
	./a.out test.nc > output.txt