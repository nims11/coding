#include <iostream>
#include <cstring>
using namespace std;
const int size=160;
class BIGNUM{
    public:
char num[size];
int status;
BIGNUM()
{
    status=0;
}
void show();
};

void BIGNUM::show(){
    int realSize=strlen(num);
for(int i=realSize-1;i>=0;i--)
cout<<(int)(num[i]-1);
}

BIGNUM factorialTable[101];
int intLen(int num)
{
    int size=0;
    while(num!=0)
    {
        num /= 10;
        size++;
    }
    return size;
}
BIGNUM multiply(int a,BIGNUM b)
{
    BIGNUM temp;
    temp.status=1;
    int carry=0;
    int realSize=strlen(b.num);
    for(int i=0;i<realSize;i++)
    {
        int unit=(b.num[i]-1)*a+carry;
        carry=unit/10;
        unit %=10;
        temp.num[i]=unit+1;
    }
    int carrySize=intLen(carry);
    temp.num[realSize+carrySize]='\0';
    for(int i=0;i<carrySize;i++)
    {
        temp.num[realSize+i]=(carry%10)+1;
        carry /=10;
    }
    return temp;
}
BIGNUM factorial(int num)
{
    if(factorialTable[num].status==1)
    {
        return factorialTable[num];
    }

    return multiply(num,factorial(num-1));
}

int main()
{
    int n,num;
    factorialTable[1].num[0]=2;factorialTable[1].num[1]='\0';
    factorialTable[1].status=1;
    cin>>n;
    while(n--)
    {
        cin>>num;
        factorialTable[num]=factorial(num);
        factorialTable[num].show();
        cout<<endl;
    }

    return 0;
}
