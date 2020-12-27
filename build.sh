i686-elf-gcc -c kernel.c -Iinclude -o kernel.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra 
i686-elf-as boot.s -o boot.o
nasm ./gdt.asm -f elf32 -o ./gdt_asm.o
i686-elf-gcc -Iinclude -T linker.ld -o myos.exec -ffreestanding -O2 -nostdlib boot.o gdt_asm.o kernel.o -lgcc
#nasm ./gdt.asm -o ./gdt_asm.o

mkdir ./isodir ./isodir/boot ./isodir/boot/grub
cp ./myos.exec ./isodir/boot/myos.exec
cp ./grub.cfg ./isodir/boot/grub/grub.cfg
grub-mkrescue -o myos.iso isodir
qemu-system-x86_64 ./myos.iso -serial file:serial.log
