#include<stdlib.h>
#include<stdio.h>

int main(){
	FILE *fp = fopen("exp.py", "w");
	if(fp == NULL){
		printf("[-]open file error\n");
		return 0;
	}
	fputs("from pwn import *\n", fp);
	fputs("# from LibcSearch import *\n\n", fp);
	fputs("p = process('./pwn')\n", fp);
	fputs("# p = remote('127.0.0.1', 7777)\n", fp);
	fputs("libc_so = '/home/nik/pwn/libc.so.6'\n", fp);
	fputs("elf = ELF('./pwn')\n", fp);
	fputs("# libc = ELF(libc_so)\n\n", fp);


	fputs("# context.log_level = 'debug'\n", fp);
	fputs("# gdb.attach(p)\n\n", fp);

	fputs("def sl(s):\n", fp);
	fputs("\treturn p.sendline(s)\n\n", fp);

	fputs("def ru(s):\n", fp);
	fputs("\treturn p.recvuntil(s)\n\n", fp);

	fputs("def rv(s=null):\n", fp);
	fputs("\tif s == null:\n", fp);
	fputs("\t\treturn p.recv()\n", fp);
	fputs("\telse:\n", fp);
	fputs("\t\treturn p.recv(s)\n\n", fp);



	fputs("def getaddr64():\n", fp);
	fputs("\treturn u64(rv(6).ljust(8, '\\x00'))\n\n", fp);

	fputs("def getaddr32():\n", fp);
	fputs("\treturn u32(rv(4))\n\n", fp);


	fputs("p.interactive()\n\n", fp);


	fputs("# [+]elf\n", fp);
	fputs("# puts_plt = elf.plt['puts']\n", fp);
	fputs("# puts_got = elf.got['puts']\n", fp);
	fputs("# bss = elf.bss(offset) #offset:number and can be null\n\n", fp);

	fputs("# [+]shellcode\n", fp);
	fputs("# context(arch='i386', os='linux')\n", fp);
	fputs("# shellcode = asm(shellcraft.sh())\n\n", fp);

	fputs("# [+]libcsearch\n", fp);
	fputs("# libc = LibcSearcher('__libc_start_main', libc_start_main) # the 2nd para is like d90\n", fp);
	fputs("# system_offset = libc.dump('system')\n", fp);
	fputs("# bin_sh_offset = libc.dump('str_bin_sh') \n\n", fp);

	fputs("# [+]libc_base\n", fp);
	fputs("# libc.address = libc_base\n", fp);
	fputs("# system = libc.symbols['system']\n", fp);
	fputs("# bin_sh = libc.search('/bin/sh').next() \n\n", fp);


	fputs("# [+]heap\n", fp);
	fputs("# def create(n, s):\n", fp);
	fputs("# \tsendlineafter(':', '')\n", fp);
	fputs("# \tsendlineafter(':', str(n))\n", fp);
	fputs("# \tsendlineafter(':', s)\n\n", fp);


	fputs("# def delete(n):\n", fp);
	fputs("# \tsendlineafter(':', '')\n", fp);
	fputs("# \tsendlineafter(':', str(n))\n\n", fp);

	fputs("# def edit(n, s):\n", fp);
	fputs("# \tsendlineafter(':', '')\n", fp);
	fputs("# \tsendlineafter(':', str(n))\n", fp);
	fputs("# \tsendlineafter(':', s)\n\n", fp);


	fputs("# def show(n):\n", fp);
	fputs("# \tsendlineafter(':', '')\n", fp);
	fputs("# \tsendlineafter(':', str(n))\n\n", fp);
	if(fp != NULL){
		fclose(fp);
	}
	system("subl exp.py");
	return 0;
}