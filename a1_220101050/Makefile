ASM_FILES = saq9.asm saq13.asm sbq7.asm sbq10.asm
OBJ_FILES = saq9.o saq13.o sbq7.o sbq10.o
EXEC_FILES = saq9 saq13 sbq7 sbq10

%.o: %.asm
	nasm -f elf32 $< -o $@

%: %.o
	gcc -m32 $< -o $@

all: $(EXEC_FILES)

run_saq9: saq9
	./saq9

run_saq13: saq13
	./saq13

run_sbq7: sbq7
	./sbq7

run_sbq10: sbq10
	./sbq10

clean:
	rm -f $(OBJ_FILES) $(EXEC_FILES)
