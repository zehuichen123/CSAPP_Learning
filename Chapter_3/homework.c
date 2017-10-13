3.1
注意点：除了$imm & ra，其他操作数都是从内存中进行寻址。没有指定比例系数则默认位1.
3.2
movl %eax,(%rsp) 因为%eax是32位，故两个字
movw (%rax),%dx %dx是16位，故一个字
movb $0xFF,%bl 0xFF和%bl都是一个byte
movq （%rdx),%rax 应为8bytes
3.3
movb $0xF,(%ebx)
error:can not use %ebx as address register(%ebx only have 32 bits,
while address register needs 64)
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
3.19
1）30
2) 46
3.20
A)／ 取整操作
B)  line1:先算出x+7
    line2:对%rdi进行自&
    line3:如果x为负数，就取x+7，为非负数取x
    line4:对取的数算数右移3位，及／8
3.21
long test(long x,long y){
	long val=8*x;
	if(y>0){
		if(x>=y){
			val=y&x;
		}
		else{
			val=y-x;
		}
	}
	else if(y<=-2){
		val=x+y;
	}
	return val;
}
3.22
1）12
2）20
3.23
A)
x:%rdi
y:%rcx
n:%rdx
B)
*p解引用只有在*p++的时候用到，而这个++在x+=y时用到，
故此时编译器直接在x+=y时多加一个1而不用额外保存p的值了
C)
line2:set x
line3:set %rcx=x
line4:set %rcx=x*x
line5:set %rdx=x+x
line7:set %rax=x*x+x+x+1
line8:n--
line9&10:check if n>0 
3.24
long loop_while(long a,long b){
	long result=1;
	while(a<b){
		result*=(a+b);
		a+=1;
	}
	return result;
}
3.25
long loop_while(long a,long b){
	long result=b;
	while(b>0){
		result=result*a;
		b-=a;
	}
	return result;
}
3.26
A)guarded-do
B)
long fun_a(unsigned long x){
	long val=0;
	while(x!=0){
		val^=x;
		x>>=1;
	}
	return val&0x1;
}
C)judge the 1s in x,odd return 0,even return 1.
3.28
A)
long fun_b(unsigned long x){
	long val=0;
	long i;
	for(i=64;i>=0;i--){
		val=(val*2)+(x&1);
		x>>=1;
}
B)
because compiler has known that i==64>0,so it is
unnecessary to check the value of i,thus do not have
an check-jump sentence here.
C)
make a minor of x,reverse the x of 2 arithmetic.
3.29
A)
the only check-jump sentence is at the top&&bottom
of loop. But do not handle the continue case.
B)
put the goto in place of continue.
3.30
A)
As the ja condition is judge if x+1>8;
which means x max is up to 7,now we have
9 quad.. In another words,the number of
them can represent as:-1,0,1,2,4,5,7(for
3 and 6 here have a .L2 quad, which 
can be understund as default).
B)
.L5,.L7
3.31
void switcher(long a,long b,long c,long *dest){
	long val;
	switch(a){
		case 5:{
			c=b^15;
			//fall through
		}
		case 0:{
			val=c+112;
			break;
		}
		case 2:
		case 7:{
			val=(c+b)<<2;
			break;
		}
		default:{
			val=b;
		}
		*dest=val;
	}
}
3.32
指令   %rdi.   %rsi.   %rax.  *%rsp
lea.  10 		-   	-	0x400565
sub.  10 		11 		- 	0x400565
callq 9 		11 		-   0x400565
movq  9 		11 		-   0x400555
imulq 9 		11 		9 	0x400555
retq  9 		11 		99  0x400565
retq  9 		11 		99  0x400565
mov   9 		11 		99 	   -
3.33
First,from %edi we can know that the First
parameter is 4 bytes,which is undoubted int.
And %rdx is long without any hesitation.Then
from addb we can know that %rcx is char*. 
But what is %sil?We can only know that complier
extract 8 bits out but do not actually know 
what the size of b.However, author told us 
sizeof(a)+sizeof(b)=6.So, sizeof(b) is 2.
SO b is short.
3.34
A)
from line 10-15, we can see that a0,..,a5 are
put into the registers respectively. 
B)
from line 16 and 18, we can see that a6 and a7
are put into the stack at %rsp and %rsp+8 respectively.
C)
because we have used up all registers saved by
callers. So we have to put the residual at stack.
3.35
A)
the x each time rfun is called
B)
long rfun(unsigned long x){
	if(x==0){
		return 0;
	}
	unsigned long nx=x>>2;
	long rv=rfun(nx);
	return rv+x;
}
3.36
table ignored
3.37
expression       dissembled code
s+1 			 leal2(%rdx),%rax
s[3] 			 movw6(%rdx),%ax
&s[i] 			 leal(%rdx,%rcx,2),%rax
s[4*i+1] 		 movw2(%rdx,%rcx,8),%ax
s+i-5 			 leal-10(%rdx,%rcx,2),%rax
/*attention:you need to multiply the size
 of data with the constant.Do NOT forget*/
3.38
from dissembled code, we can easily conclude 
that %rdi=i+5j and %rdx=7*i+j. So 5 and 7 are
the correct answer for M and N.Attention:you 
need to think it over which is M and which is N.
(Answer:M=5,N=7)
3.42
A)
long fun(struct ELE *ptr){
	long sum=0;
	while(ptr->v){
		sum+=ptr->v;
		ptr=ptr->p;
	}
}
B)
ignored
3.44
For this problem we should know that for every 
data structure,its start address must be the 
multiple of sizeof(this data structure).Consequencely,
this leads to memory alignment.
A.
0-3,4-7,8-11,12-15(here we leave 3 bytes for the 
last char data structure,because if we delcare like
this: struct P1[4], that is awful because for the 
second element ''s first int can not begin at the
k multiple address.)
B.C.D.E.ignored
3.45
A.B.54bytes(every element takes up 8 btyes)
C.if we declare like this:
struct p1{
	char d;
	char f;
	short b;
	int h;
	long g;
	double c;
	char* a;
	float e;
}
so we can get this struct with only 40 bytes.
	