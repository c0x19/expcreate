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
	fputs("elf = ELF(libc_so)\n\n", fp);

	fputs("# context.log_level = 'debug'\n", fp);
	fputs("# gdb.attach(p)\n\n", fp);

	fputs("def sl(s):\n", fp);
	fputs("\tp.sendline(s)\n\n", fp);

	fputs("def rv(s):\n", fp);
	fputs("\tp.recvuntil(s)\n\n", fp);

	fputs("def getaddr64():\n", fp);
	fputs("\treturn u64(p.recv(6).ljust(8, '\\x00'))\n\n", fp);

	fputs("def getaddr32():\n", fp);
	fputs("\treturn u32(p.recv(4))\n\n", fp);


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
	fputs("# elf.address = libc_base\n", fp);
	fputs("# system = elf.symbols['system']\n", fp);
	fputs("# bin_sh = elf.search('/bin/sh').next() \n\n", fp);


	fputs("# [+]heap\n", fp);
	fputs("# def mycreate():\n", fp);
	fputs("# \trv('')\n", fp);
	fputs("# \tsl('')\n\n", fp);

	fputs("# def mydelete():\n", fp);
	fputs("# \trv('')\n", fp);
	fputs("# \tsl('')\n\n", fp);

	fputs("# def myedit():\n", fp);
	fputs("# \trv('')\n", fp);
	fputs("# \tsl('')\n\n", fp);

	fputs("# def myshow():\n", fp);
	fputs("# \trv('')\n", fp);
	fputs("# \tsl('')\n", fp);
	if(fp != NULL){
		fclose(fp);
	}
	system("subl exp.py");
	return 0;
}