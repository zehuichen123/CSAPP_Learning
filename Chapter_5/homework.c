5.1
0
5.2
we can do this simple problem with 
linear programming.Ignored.
5.3
Ignored
5.4
A.for O2 combine3,it works like more similiar
to curr in combine4.It is a temporary variable,
which store the result inside the loop but the 
difference between it and combine4 is that it 
refresh *dest every loop to gurantee *dest are
always the newest value.
B.Same.
C.This optimization will not influence the 
performance of the origin function. 
5.5
A.2n multification and n addition
B.To get the CPE of this circulation, we need 
to make the key path. In this case, we just 
need to calculate xpwr before we start the next
circulation. So, we just need to think out x=x*
xpwr; And obviously, the CPE of this statement 
is 5/1(only one multification)
5.6
A.n multification and n addition
B.As we mentioned before, the key path of this 
process is result, in other words, we must calculate
 variable result out before we start another ci-
 rculation. So ,the CPE of this statem is 3(addition)
 +5(multification).
C.A stupid question. We have already known that
the CPE of the 1st case is 5 and the 2nd case is 8.
Why I need to explain more???
5.7
just change one for statement in figure5-16: 
for(i=0;i<length-4;i+=5){
	acc=((((acc OP data[i]) OP data[i+1])
		OP data[i+2]) OP data[i+3]) OP data[i+4];
}
5.8
For in each multification, we would calculate 3
elements all together at a time. So do not forget
to divide 3 when calculate CPE:
A1:we always need to know r before we calculate,
so it is 15/3=5
A2:10/3=3.33
A3:5/3=1.67
A4:5/3=1.67
A5:10/3=3.33
5.9
while(i1<n&&i2<n){
	long temp1=src1[i1];
	long temp2=src2[i2];
	bool check=temp1>temp2;
	dest[id++]=check?temp1:temp2;
	i1+=check;
	i2+=(1-check);
}
5.10
A.Ignored
B.Ignored
C.Because they are data-related during this 
iteration and next iteration. So you need to 
excute each load and store finished before 
you begin your next iteration.
5.11
Emmmm, for this problem, we need to use a 
statistic provided by this book:the CPE of
instant load and store excution is 7 T(
including a + process which equals 1 T)
Concretely, we have (7-1)+3(float addition 
equals 3 T)=10 periods.
5.12
We can add a temp variable to avoid store 
and load p[i] frequently. In this way, we 
can easily let the adjancent iterations share
non-related data.
void psum1(float a[],float p[],long n){
	long i;
	p[0]=a[0];
	long cre=p[0];
	for(i=1;i<n;i++){
		p[i]=cre+a[i];
		cre+=a[i];
	}
}
