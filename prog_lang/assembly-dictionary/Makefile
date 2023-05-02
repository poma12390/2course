ASM=nasm
ASMFLAGS=-f elf64
LD=ld

PROGRAM=lab2

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

$(PROGRAM): main.o lib.o dict.o 
	$(LD) -o $@ $+ 

.PHONY: clean

clean:
	$(RM) *.o
	$(RM) main
