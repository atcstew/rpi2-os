###############################################################################
# A make file to generate kernel images from C source
# -by Aidan Stewart 06/04/17
###############################################################################
#TODO: add linker ma, script allow assembly mixing


# The toolchain to use. arm-none-eabi works, but there does exist 
# arm-bcm2708-linux-gnueabi.
toolchain = arm-none-eabi

#GCC command line args
gcc-opts = -MMD -g -Wall -mfpu=neon-vfpv4 -mcpu=cortex-a7 -mfloat-abi=hard -c -nostdlib

#AS command line args
as-opts = -g -mcpu=cortex-a7 -I -O

#LD command line args
ld-opts = --no-undefined -entry _start linker.ld


# Rule to make/rebuild everything.
all :
	@make clean
	@mkdir temp/

	
	
	@$(toolchain)-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c source/boot.s -o boot.o 2> debug/assembler.txt
	@$(toolchain)-gcc $(gcc-opts) source/*.c 2> debug/compiler.txt


	@#uncomment to include external libraries
	@#cp  lib/*.o temp/
	@mv  *.o 	temp/
	@mv  temp/*.o  ./build
	
	@$(toolchain)-ld  $(ld-opts) build/*.o 2> debug/linker.txt
	@mv		a.out	./build/output.elf
	@$(toolchain)-objcopy ./build/output.elf -O binary kernel/kernel7.img 
	@$(toolchain)-objdump -d ./build/output.elf > debug/dissassembly.txt
	
	@rmdir temp/
	@mv  *.d debug/dependencies/
	@cat debug/compiler.txt
	@cat debug/linker.txt
	@echo Make Completed
	

#fix a failed compile	
clean:
	@rm -rf temp/
	@rm -rf ./*.o
	@rm -rf *.d
	@rm -rf *.out
	@rm -f build/*.o 
	@rm -f build/output.elf
	@rm -f kernel/kernel7.img
	

	
