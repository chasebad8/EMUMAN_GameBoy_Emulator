all: src/main.c ./src/decoder.c ./src/mmu.c ./src/log_files.c ./src/cpu.c
	mkdir -p obj
	gcc -o ./obj/test ./src/main.c ./src/decoder.c ./src/mmu.c ./src/log_files.c ./src/cpu.c

clean:
	rm -f -r obj