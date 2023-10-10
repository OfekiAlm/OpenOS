cd src
make
cp kernel.bin ../iso/kernel/kernel.bin
make clean
cd ..
mkisofs -R -input-charset utf8 -b boot/grub/stage2_eltorito -boot-info-table -no-emul-boot -boot-load-size 4 -o os.iso iso
qemu-system-x86_64 -cdrom os.iso
