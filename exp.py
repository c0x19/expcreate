from pwn import *
# from LibcSearch import *

p = process('./pwn')
# p = remote('127.0.0.1', 7777)
libc_so = '/home/nik/pwn/libc.so.6'
elf = ELF('./pwn')

# libc = ELF(libc_so)

# context.log_level = 'debug'
# gdb.attach(p)

def sl(s):
	return p.sendline(s)

def ru(s):
	return p.recvuntil(s)

def rv(s=null):
	if s == null:
		return p.recv()
	else:
		return p.recv(s)

def getaddr64():
	return u64(rv(6).ljust(8, '\x00'))

def getaddr32():
	return u32(rv(4))

p.interactive()

# [+]elf
# puts_plt = elf.plt['puts']
# puts_got = elf.got['puts']
# bss = elf.bss(offset) #offset:number and can be null

# [+]shellcode
# context(arch='i386', os='linux')
# shellcode = asm(shellcraft.sh())

# [+]libcsearch
# libc = LibcSearcher('__libc_start_main', libc_start_main) # the 2nd para is like d90
# system_offset = libc.dump('system')
# bin_sh_offset = libc.dump('str_bin_sh') 

# [+]libc_base
# libc.address = libc_base
# system = libc.symbols['system']
# bin_sh = libc.search('/bin/sh').next() 

# [+]heap
# def create(n, s):
# 	sendlineafter(':', '')
# 	sendlineafter(':', str(n))
# 	sendlineafter(':', s)

# def delete(n):
# 	sendlineafter(':', '')
# 	sendlineafter(':', str(n))

# def edit(n, s):
# 	sendlineafter(':', '')
# 	sendlineafter(':', str(n))
# 	sendlineafter(':', s)

# def show(n):
# 	sendlineafter(':', '')
# 	sendlineafter(':', str(n))

