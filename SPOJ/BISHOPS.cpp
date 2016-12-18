/*
use BIGNUM to find 2*a-2
*/
#include <iostream>
#include <string>
const long long unsigned default_size=1000;
const long long unsigned default_increment=100;
class BIGNUM
{char *number;long long unsigned size;long long unsigned number_size;bool sign_bit;void resize(long long unsigned new_size);void init_from_str(std::string num_str);
BIGNUM(char* rev_str,long long unsigned num_size,bool signbit,bool delete_rev_str=true);
    public:
    BIGNUM(long long int_num=0);
    BIGNUM(const BIGNUM&);
    BIGNUM(std::string str_num);
    friend const BIGNUM operator+(const BIGNUM& num1,const BIGNUM& num2);
    friend const BIGNUM operator-(const BIGNUM& num1,const BIGNUM& num2);
    friend bool operator==(const BIGNUM& num1,const BIGNUM& num2);
    friend bool operator>(const BIGNUM& num1,const BIGNUM& num2);
    friend bool operator<(const BIGNUM& num1,const BIGNUM& num2);
    friend bool operator>=(const BIGNUM& num1,const BIGNUM& num2);
    friend bool operator<=(const BIGNUM& num1,const BIGNUM& num2);
    ~BIGNUM(){if(size!=0)delete [] number;}
    void show_num() const;
    char* get_num() const{return number;}
    long long unsigned get_num_size() const{return number_size;}
    const BIGNUM abs() const{return BIGNUM(number,number_size,false,false);}
};
BIGNUM::BIGNUM(long long int_num)
{
    size=0;
    resize(default_size);
    if(int_num<0)
    {
        sign_bit=true;
        int_num*=-1;
    }
    else
    sign_bit=false;
    int i=0;
    for(long long j=int_num;j>0;i++,j/=10)
    {
        number[i]=j%10;
    }
    if(int_num==0)
    number_size=1;
    else
    number_size=i;

}
BIGNUM::BIGNUM(std::string str_num)
{
    init_from_str(str_num);
}
BIGNUM::BIGNUM(const BIGNUM& bignum)
{
    std::string tmp;
    long long unsigned count=0;
    if(bignum.sign_bit)
    tmp.push_back('-');
    char *num_tmp=bignum.number;
    long long unsigned i=bignum.number_size-1;
    for(;i>0;i--)
    {
        tmp.push_back(num_tmp[i]+'0');
    }
    tmp.push_back(num_tmp[0]+'0');
    init_from_str(tmp);
}
BIGNUM::BIGNUM(char* rev_str,long long unsigned num_size,bool signbit,bool delete_rev_str)
{
    size=0;
    if(num_size>=default_size)
    resize(num_size+default_increment);
    else
    resize(default_size);

        number[0]=2;

    for(long long unsigned i=0;i<num_size;i++)
    {
        number[i]=rev_str[i];
    }
    number_size=num_size;
    sign_bit=signbit;
    if(delete_rev_str)
    delete [] rev_str;
}
void BIGNUM::show_num() const
{
    if(sign_bit)
    std::cout<<"-";
    for(long long unsigned i=number_size-1;i>0;i--)
    std::cout<<int(number[i]);
    std::cout<<int(number[0]);
}
void BIGNUM::resize(long long unsigned new_size)
{
    if(size==0)
    {
        number=new char[new_size];
        size=new_size;
        for(long long int i=0;i<size;i++)
        number[i]=0;
    }
}
void BIGNUM::init_from_str(std::string str_num)
{
    size=0;
    long long unsigned str_num_len=str_num.length();
    if(str_num_len>default_size)
    resize(str_num_len+default_increment);
    else
    resize(default_size);

    long long unsigned limit;
    if(str_num.at(0)=='-')
    {
        sign_bit=true;
        limit=str_num_len-2;
    }else
    {
        sign_bit=false;
        limit=str_num_len-1;
    }

    for(long long unsigned i=str_num_len-1;i>0;i--)
    number[str_num_len-1-i]=str_num.at(i)-'0';
    if(!sign_bit)
    number[limit]=str_num.at(0)-'0';
    number_size=limit+1;
}
bool operator==(const BIGNUM& num1,const BIGNUM& num2)
{
    if(num1.number_size!=num2.number_size || num1.sign_bit!=num2.sign_bit)
    return false;

    for(long long unsigned i=0;i<=num1.number_size;i++)
    {
        if(num1.number[i]!=num2.number[i])
        return false;
    }
    return true;
}
bool operator>(const BIGNUM& num1,const BIGNUM& num2)
{
    if(num1.number_size>num2.number_size)
    return !num1.sign_bit;
    if(num1.number_size<num2.number_size)
    return num2.sign_bit;

    if(num1.sign_bit!=num2.sign_bit)
    return !num1.sign_bit;

    for(long long unsigned i=num1.number_size-1;i>0;i--)
    {
        if(num1.number[i]!=num2.number[i])
        return num1.number[i]>num2.number[i];
    }
    return num1.number[0]>num2.number[0];
}
bool operator<(const BIGNUM& num1,const BIGNUM& num2)
{
    return num2>num1;
}
long long unsigned calc_size(const char *final_num,long long unsigned number1_size)
{
    long long unsigned i;
    for(i=number1_size-1;i>0;i--)
    if(final_num[i]!=0)
    break;
    return i+1;
}
void add_magnitude(const BIGNUM& num1,const BIGNUM& num2,char*& final_num,long long unsigned & final_num_size)
{
    char *number1,*number2;
        long long unsigned number1_size,number2_size;
        if(num1.get_num_size()>num2.get_num_size())
        {
            number1=num1.get_num();
            number2=num2.get_num();
            number1_size=num1.get_num_size();
            number2_size=num2.get_num_size();
        }
        else
        {
            number2=num1.get_num();
            number1=num2.get_num();
            number2_size=num1.get_num_size();
            number1_size=num2.get_num_size();
        }

        final_num=new char[number1_size+1];
        int carry=0;
        if(number1_size==number2_size)
        {
            for(long long unsigned i=0;i<number1_size-1;i++)
            {
                final_num[i]=carry+number1[i]+number2[i];
                carry=final_num[i]/10;
                final_num[i]%=10;
            }
            int x=number1[number1_size-1]+number2[number2_size-1]+carry;
            final_num[number1_size-1]=(x%10);
            final_num[number1_size]=(x/10);
            int y=x/10==0?0:1;
            final_num_size=number1_size+y;
        }else
        {
            for(long long unsigned i=0;i<number2_size;i++)
            {
                final_num[i]=carry+number1[i]+number2[i];
                carry=final_num[i]/10;
                final_num[i]%=10;
            }
            for(long long unsigned i=number2_size;i<number1_size-1;i++)
            {
                final_num[i]=carry+number1[i];
                carry=final_num[i]/10;
                final_num[i]%=10;
            }
            int x=number1[number1_size-1]+carry;
            final_num[number1_size-1]=x%10;
            final_num[number1_size]=x/10;
            int y=x/10==0?0:1;
            final_num_size=number1_size+y;
        }

}

void sub_magnitude(const BIGNUM& num1,const BIGNUM& num2,char*& final_num,long long unsigned & final_num_size)
{
    char *number1,*number2;
    if(num1.abs()==num2.abs())
    {
        final_num=new char[1];
        final_num[0]='0';
        final_num_size=1;
        return;
    }
    long long unsigned number1_size,number2_size;
    if(num1.abs()>num2.abs())
    {
        number1=num1.get_num();
        number2=num2.get_num();
        number1_size=num1.get_num_size();
        number2_size=num2.get_num_size();
    }else
    {
        number1=num2.get_num();
        number2=num1.get_num();
        number1_size=num2.get_num_size();
        number2_size=num1.get_num_size();
    }

    bool carry=false;
    long long unsigned i=0;
    final_num=new char[number1_size];
    for(i=0;i<number2_size;i++)
    {


        if(carry)
        {
            if(number1[i]-1<number2[i])
            {
                final_num[i]=number1[i]-1+10-number2[i];
            }else
            {
                final_num[i]=(10+number1[i]-1)%10-number2[i];
                if(number1[i]!=0)carry=false;
            }

        }else
        {
            if(number1[i]<number2[i])
            {
                carry=true;
                final_num[i]=number1[i]+10-number2[i];
            }else
                final_num[i]=number1[i]-number2[i];
        }
    }

    for(;i<number1_size;i++)
    {
        if(carry)
        {
            final_num[i]=(10+number1[i]-1)%10;
            if(number1[i]!=0)carry=false;
        }else
        final_num[i]=number1[i];
    }


    final_num_size=calc_size(final_num,number1_size);

}
const BIGNUM operator+(const BIGNUM& num1,const BIGNUM& num2)
{
        long long unsigned final_num_size;
    char* final_num;
    bool final_sign_bit=num1.sign_bit;
        add_magnitude(num1,num2,final_num,final_num_size);
        return BIGNUM(final_num,final_num_size,final_sign_bit);
}
const BIGNUM operator-(const BIGNUM& num1,const BIGNUM& num2)
{
    bool final_sign_bit=num1.sign_bit;
        long long unsigned final_num_size;
    char* final_num;
    if(num1==num2)
    {
        final_num_size=1;
        final_sign_bit=false;
        final_num=new char(0);
    }else
    {
        if(num1.sign_bit && num2.sign_bit)
        {
            final_sign_bit=num1.abs()>num2.abs();
            sub_magnitude(num1,num2,final_num,final_num_size);
        }else if(!num1.sign_bit && !num2.sign_bit)
        {
            final_sign_bit=num1<num2;
            sub_magnitude(num1,num2,final_num,final_num_size);
        }else
        {
            final_sign_bit=num1.sign_bit;
            add_magnitude(num1,num2,final_num,final_num_size);
        }
    }
    return BIGNUM(final_num,final_num_size,final_sign_bit);
}
int main()
{
using namespace std;
BIGNUM two(2);
string str;
while(getline(cin,str))
{
    if(str.length()==1 && str[0]=='1')
    cout<<1<<endl;
    else
    {
        BIGNUM a(str);
        BIGNUM b=a+a-two;
        b.show_num();
        cout<<endl;
    }
}
}
