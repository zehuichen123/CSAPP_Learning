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
注意点：对于移位操作，如果使用寄存器中的数作为immediate，那么必须是
从%cl中取数，确保移位k数值的大小。
shift_left_rightn:
	movq %rdi,%rax //get x
	salq $4,%rax   //x<<=4
	movl %esi,%ecx //get n(4 bytes)
	sarq %cl,%rax //x>>=n
3.10
long arith2(long x,long y,long z){
	long t1=y|x;
	long t2=t1>>3;
	long t3=~t2;
	long t4=z-t3;
	return t4;
}
3.11
1）将%rdx设置为0
2）movq $0,%rdx
3) oxrq版本需要3个字节，而使用movq需要7个字节
// skip for multiply
3.13
这里需要注意通过set和test的特定类型进行进一步判断unsigned/signed.
1)int
2)short
3)unsigned char
4)long/unsigned long/某种指针
3.14
1）long
2）short／unsigned short
3）unsigned char
4）int
3.15
这题考的就是pc-relative（PC相对寻址）至于到底是啥么玩意自己
看书，用法这里提一下，其实jmp的最后地址就是jmp的最后一个byte
+jmp下一个语句的地址。
1）0x4003fe
2）0x400431
3）0x400547
4）这题我们读目标偏移量需要倒着读：
0xffffff73=(10)-141
故最后结果是0x400560
3.16
A.
void cond(long a,long *p){
	if(p&&a>*p){
		goto elite;
	}
	return;
elite:
	*p=a;
}
B.
因为if语句其实有两种情况，else 被省略了。
3.17
略（比较简单
至于第二问，其实没有什么区别，只是前者比较写起来简单，少了一个else
3.18
这种题关键不能心态急
long test(long x,long y,long z){
	long val=x+y+z;
	if(x<-3){
		if(y>=z){
			val=y*z;
		}
		else{
			val=x*y;
		}
	}
	else if(x>2){
		val=x*z;
	}
	return val;
}







	