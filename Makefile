all: src/main.c ./src/decoder.c ./src/mmu.c
	mkdir -p obj
	gcc -o ./obj/test ./src/main.c ./src/decoder.c ./src/mmu.c

clean:
	rm -f -r obj