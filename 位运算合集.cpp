#include<stdio.h>

//0和1，让世界运转！

//善用掩码：mask=1<<k;
// &  :按位与运算符，当且仅当两个位都为1时，结果为1（& mask可读取某一位）
// |  :按位或运算符，当两个位有一个为1时，结果为1 （| mask可设置某一位为 1）
// ^  :按位异或运算符，当两个位不同时，结果为1   （^ mask可对某一位取反）
// ~  :按位取反运算符，0变1，1变0，包括符号位   （& ~mask可设置某一位为 0）
// << :左移运算符，高位丢弃!低位补0
// >> :右移运算符，低位丢弃!高位补0（无符号时）或补符号位（有符号）

void print_binary(int n); //打印二进制形式（不包括高位0）
bool isPowerOfTwo(int x); //判断是否为2的幂次方  
bool isPowerOfFour(int x);//判断是否为4的幂次方
bool isAlternatingBits(int x); //判断二进制表示中是否交替出现0和1
int hanmingweight(int x); //求汉明重量(即二进制表示中1的个数) 
int hanmingdistance(int x,int y); //求汉明距离(即两个数的二进制中不同位的个数)
void swap(int *x,int *y); //不用中间量交换两个数
int MultiplyBy3(int x);   //不用乘法实现乘3
int Multiply(int x,int y);//不用乘法实现a*b
int GetSum(int a,int b); //不用加法实现a+b
int FlipKthBit(int b,int k);//对二进制数的第k位取反
int Flip(int b);         //倒序

int main()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);

    print_binary(a);
    print_binary(b);
    printf("\n");

    bool isPower=isPowerOfTwo(a);
    if(isPower)
        printf("%d是2的幂次方\n",a);
    else
        printf("%d不是2的幂次方\n",a);

    bool isPower4=isPowerOfFour(a);
    if(isPower4)
        printf("%d是4的幂次方\n",a);
    else
        printf("%d不是4的幂次方\n",a);

    bool isAlter=isAlternatingBits(a);
    if(isAlter)
        printf("%d的二进制表示中交替出现0和1\n",a);
    else
        printf("%d的二进制表示中不交替出现0和1\n",a);   

    int han=hanmingweight(a);
    printf("%d的汉明重量是%d\n",a,han);

    int hanDis=hanmingdistance(a,b);
    printf("%d和%d的汉明距离是%d\n",a,b,hanDis);

    swap(&a,&b);//传入地址！
    printf("交换前a=%d,b=%d\n",b,a);
    printf("交换后a=%d,b=%d\n",a,b);

    int mul3=MultiplyBy3(a);
    printf("%d乘3的结果是%d\n",b,mul3);

    int mul=Multiply(a,b);
    printf("%d乘%d的结果是%d\n",b,a,mul);

    int sum=GetSum(a,b);
    printf("%d加%d的结果是%d\n",b,a,sum);

    int flipk=FlipKthBit(b,k);
    printf("%d的二进制数的第%d位取反结果是%d\n",b,k,flipk);

    int flip=Flip(b);
    printf("%d的二进制倒序后的结果是%d\n",b,flip);

    return 0;
}

void print_binary(int n){
    printf("%d的二进制表示为：", n);
    
    if(n == 0) {
        printf("0\n");
        return;//特殊情况
    }
    // 找到最高位的1
    int sign=0;
    for(int i=31;i>=0;i--) {
        if(n&(1<<i)) {
            printf("1");
            sign=1;
        } else if(sign) {
            printf("0");
        }
    }
    printf("\n");
}

bool isPowerOfTwo(int x)    
{
    if(x>0 && (x & (x - 1)) == 0 )
        return true;
    else
        return false;
}

bool isPowerOfFour(int x)
{
    if(x>0 && (x & (x - 1)) == 0 && x%3==1)
        return true;
    else
        return false;
}

bool isAlternatingBits(int x)
{
    while(x)
    {
    if((x&3)==3 || (x&3)==0)//注意优先级！！a&b==c等价于a&(b==c)
        return false;
    x>>=1;  
    }
    return true;
}

int hanmingweight(int x)
{
    int cnt=0;
    while(x!=0)
    {
        if(x&1) 
            cnt++;
        x>>=1;
    }
    return cnt;
}

int hanmingdistance(int x,int y)
{
    int dif=x^y;// ^ 异或，不同位为1，相同位为0
    return hanmingweight(dif);
}

void swap(int *x, int *y)//指针传参
{
    if (x != y) {        //避免地址相同时异或结果为0
        *x=*x^*y;    //y^y=0
        *y=*x^*y;    //(*x^y)^y=*x
        *x=*x^*y;    //(*x^y)^*x=*y
    } 
}

int MultiplyBy3(int x)
{
    return (x<<1)+x;     //左移一位相当于乘2，再加上x相当于乘3
}

int Multiply(int x,int y)
{
    // 前提：a、b非负
    int result=0;
    while (y>0) {
        if ((y&1)==1) { //相当于b%2==1
            result+=x;
        }
        x<<=1; //左移1位，相当于乘以2
        y>>=1; //遍历b的每一位，判断是否需要累加当前权重的a
    }
    return result;
}   

int GetSum(int a,int b)
{
    while(b!=0)
    {
        int c;          
        c=(a & b)<<1; //计算进位
        a=a^b;        //计算非进位和
        b=c;          //将进位赋值给b,直到无进位为止
    }          
    return a;
}

int FlipKthBit(int b,int k)
{
    int mask=1<<k; //掩码,即第 k位为 1，其他位为0
    return b^mask; //与 1异或，可以对该位取反
}

int Flip(int b)
{
    int result=0;
    while(b!=0)
    {
        result<<=1;        //结果左移一位，为最低位腾出位置
        result|=(b&1);    //将a的最低位加到result的最低位
        b>>=1;            //a右移一位，处理下一位
    }
    return result;
    
}