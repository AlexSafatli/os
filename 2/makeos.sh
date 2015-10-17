nasm -f elf32 loader.s # makes 32bits ELF o (object) file using loader.s file
ld -T link.ld -melf_i386 loader.o -o kernel.elf # produce an executable file by linking the kernel
wget http://littleosbook.github.com/files/stage2_eltorito # acquire GRUB
mkdir -p iso/boot/grub # creates folder structure
cp stage2_eltorito iso/boot/grub/ # copy bootloader
cp kernel.elf iso/boot/ # copy kernel
cp menu.lst iso/boot/grub/ # copy GRUB configuration file
# now generate the ISO image (https://littleosbook.github.io/ 2.3.4)
genisoimage -R                              \
            -b boot/grub/stage2_eltorito    \
            -no-emul-boot                   \
            -boot-load-size 4               \
            -A os                           \
            -input-charset utf8             \
            -quiet                          \
            -boot-info-table                \
            -o os.iso                       \
            iso