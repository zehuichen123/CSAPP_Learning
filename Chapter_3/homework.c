3.1
注意点：除了$imm & ra，其他操作数都是从内存中进行寻址。没有指定比例系数则默认位1.
3.2
movl %eax,(%rsp) 因为%eax是32位，故两个字
movw (%rax),%dx %dx是16位，故一个字
movb $0xFF,%bl 0xFF和%bl都是一个byte
movq （%rdx),%rax 应为8bytes
3.3
movb $0xF,(%ebx)
error:can not use %ebx as address register(%ebx only have 32 bits,while address register needs 64)
movl %rax,(%rsp)
error:needs movq
movw (%rax),4(%rsp)
error:can not have both source and destination be memory references.
movb %al,%sl
error:no register Id called %sl
movq %rax,$0x123
error:immediate can not use as destination
movl %eax,%rdx
error:destination operand incorrect size
movb %si,8(%rbp)
error:mismatch instruction suffix and register ID
3.4
注意点：对于算术符号拓展，可以保证拓展后的数值与原来的一致性。
注意点2:对于signed向unsigned向上拓展，应为算术拓展。e.g.
char m=-3;
unsigned int b=(unsigned)m;
此时，b应为4294967293，可见是算术符号拓展。
char->int 
	movsbl (%rdi),%eax (将char转换成int)
	movl %eax,(%rsi).  (存4字节)
unsigned char->long
	movzbq (%rdi),%rax
	movq %rax,(%rsi)
unsigned->unsigned char
	movl (%rdi),%eax
	movb %al,(%rsi)		(截取低位字节)
3.5
void decode1(long *xp,long *yp,long *zp){
	long temp1=*xp;
	long temp2=*yp;
	long temp3=*zp;
	*yp=temp1;
	*zp=temp2;
	*xp=temp3;
	return;
}
3.6
本题主要是考察使用leaq(load effective address)来骚操作表示乘法
1) 6+x
2) x+y
3) x+4y
4) 7+9x
5) 10+4y
6) 9+x+2y
3.7
同上的意思，美名其曰逆向工程
long 5*x+2*y+8*z;
3.8
1) 0x100
2) 0xA8
3) 0x110
4) 0x14
5) 0x0
6) 0xFD
3.9









	