#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cassert>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
class BIGNUM
{
    long long *N;
    int BASE;
    int BASE_pow;
    int max_size;
    bool sign;

    int int_len(long long x);
    void do_carry();
    void compress();
public:
    int size;
    BIGNUM();
    ~BIGNUM(){delete []N;}
    BIGNUM(const BIGNUM &x);

    void print();
    string get_str();
    void load_from_LL(long long x);
    void load_from_str(const char *tmp);
    BIGNUM add_mag(const BIGNUM &x);
    BIGNUM sub_mag(const BIGNUM &x);
    int cmp(const BIGNUM &x); // 0-> x is equal, -1 -> x is smaller, 1 -> x is greater
    int cmp_mag(const BIGNUM &x);

    BIGNUM operator-()
    {
        if(this->size == 1 && this->N[0] == 0)
            return *this;
        BIGNUM ret = *this;
        ret.sign = !this->sign;
        return ret;
    }

    BIGNUM operator+()
    {
        return *this;
    }

    BIGNUM operator+(const BIGNUM &x);
    BIGNUM operator-(const BIGNUM &x);
    BIGNUM operator*(const BIGNUM &x);

    bool operator<(const BIGNUM &x)
    {
        return cmp(x) == 1;
    }
    bool operator>(const BIGNUM &x)
    {
        return cmp(x) == -1;
    }
    bool operator==(const BIGNUM &x)
    {
        return cmp(x) == 0;
    }
    bool operator<=(const BIGNUM &x)
    {
        return cmp(x)+1 > 0;
    }
    bool operator>=(const BIGNUM &x)
    {
        return cmp(x)-1<0;
    }

    friend void test();
};
BIGNUM::BIGNUM():BASE(1000000), BASE_pow(6), max_size(3500), sign(false)
{
    // Default setting is enough for operations on 10000 digits
    N = new long long[max_size];
    N[0] = 0;
    size = 1;
}
BIGNUM::BIGNUM(const BIGNUM &x)
{
    size = x.size; BASE = x.BASE; BASE_pow = x.BASE_pow; max_size = x.max_size; sign = x.sign;
    N = new long long[max_size];
    for(int i=0;i<size;i++)
        N[i] = x.N[i];
}
int BIGNUM::int_len(long long x)
{
    int count=0;
    do
    {
        x/=10;
        count++;
    }while(x!=0);
    return count;
}

void BIGNUM::print()
{
    if(sign)
        printf("-");
    for(int i=size-1;i>=0;i--)
    {
        int len=int_len(N[i]);
        for(int j=0;j<BASE_pow-len && i!=size-1;j++)
        printf("0");
        printf("%d",N[i]);
    }
}
string BIGNUM::get_str()
{
    string ret;
    int i, len;
    for(i=size-1;N[i]<=0 && i>0;i--);
    int start=i;
    if(sign)
        ret.push_back('-');
    for(;i>=0;i--)
    {
        int len=int_len(N[i]);
        for(int j=0;j<BASE_pow-len && i!=start;j++)
        ret.push_back('0');
        string foo;
        int x = N[i];
        do
        {
            foo.push_back(x%10 + '0');
            x/=10;
        }while(x);
        reverse(foo.begin(), foo.end());
        ret += foo;
    }
    return ret;
}
void BIGNUM::load_from_LL(long long x)
{
    if(x<0)
    {
        sign = true;
        x *= -1;
    }else
        sign = false;
    size = 0;
    do
    {
        N[size++] = x%BASE;
        x /= BASE;
    }while(x);
}
void BIGNUM::load_from_str(const char *tmp)
{
    if(tmp[0] == '-')
    {
        sign = true;
        tmp++;
    }else
        sign = false;
    int len=strlen(tmp);
    size=(len-1)/BASE_pow + 1;
    for(int i=0;i<size;i++)
        N[i] = 0;
    for(int i=0;i<len;i++)
    {
        N[((len-1-i)/BASE_pow)]=N[(len-1-i)/BASE_pow]*10+tmp[i]-'0';
    }
    if(size == 1 && N[0] == 0)
        sign = false;
}
int BIGNUM::cmp(const BIGNUM &x)
{
    if(sign && !x.sign)
        return 1;
    if(!sign && x.sign)
        return -1;
    int LT = -1, GT = 1;
    if(sign && x.sign)
        LT = 1, GT = -1;
    if(size<x.size)
        return GT;
    if(size>x.size)
        return LT;
    int idx = size-1;
    while(idx>=0)
    {
        if(N[idx] < x.N[idx])
            return GT;
        if(N[idx] > x.N[idx])
            return LT;
        idx--;
    }
    return 0;
}
int BIGNUM::cmp_mag(const BIGNUM &x)
{
    int LT = -1, GT = 1;
    if(size<x.size)
        return GT;
    if(size>x.size)
        return LT;
    int idx = size-1;
    while(idx>=0)
    {
        if(N[idx] < x.N[idx])
            return GT;
        if(N[idx] > x.N[idx])
            return LT;
        idx--;
    }
    return 0;
}
BIGNUM BIGNUM::add_mag(const BIGNUM &x)
{
    BIGNUM ret;
    int size1 = this->size, size2 = x.size;
    int lt = min(size1, size2), i;
    ret.size = max(size1, size2);
    for(i=0;i<lt;i++)
        ret.N[i] = this->N[i]+x.N[i];
    if(ret.size == this->size)
    {
        for(;i<ret.size;i++)
            ret.N[i] = this->N[i];
    }else
    {
        for(;i<ret.size;i++)
            ret.N[i] = x.N[i];
    }
    ret.do_carry();
    return ret;
}
BIGNUM BIGNUM::sub_mag(const BIGNUM &x)
{
    BIGNUM ret;
    int c = 0;
    ret.size = 0;
    int lt = min(x.size, size);
    int i;
    for(i=0;i<lt;i++)
    {
        ret.N[ret.size] = this->N[i]+(BASE-(i!=0)-x.N[i])+c;
        c = ret.N[ret.size]/BASE;
        ret.N[ret.size] %= BASE;
        ret.size++;
    }
    lt = max(x.size, size);
    if(lt == x.size)
    {
        for(;i<lt;i++)
        {
            ret.N[ret.size] = (BASE-1-x.N[i])+c;
            c = ret.N[ret.size]/BASE;
            ret.N[ret.size] %= BASE;
            ret.size++;
        }
    }else
    {
        for(;i<lt;i++)
        {
            ret.N[ret.size] = this->N[i]+(BASE-1)+c;
            c = ret.N[ret.size]/BASE;
            ret.N[ret.size] %= BASE;
            ret.size++;
        }
    }
    ret.compress();
    if(!c)
    {
        ret.sign = true;
        for(int i=0;i<ret.size;i++)
        {
            ret.N[i] = BASE-(i!=0)-ret.N[i];
        }
    }
    ret.compress();
    return ret;
}
void BIGNUM::compress()
{
    while(N[size-1] == 0 && size>1)size--;
}
void BIGNUM::do_carry()
{
    int c = 0;
    for(int i=0;i<size;i++)
    {
        N[i] += c;
        c = N[i]/BASE;
        N[i] %= BASE;
    }
    if(c)
        N[size++] = c;
}
inline BIGNUM BIGNUM::operator+(const BIGNUM &x)
{
    if(!sign && !x.sign)    // (+) + (+)
    {
        BIGNUM ret = this->add_mag(x);
        return ret;
    }
    if(sign && x.sign)     // (-) + (-)
    {
        BIGNUM ret = this->add_mag(x);
        ret.sign = true;
        return ret;
    }
    if(sign && !x.sign)    // (-) + (+)
    {
        BIGNUM ret = sub_mag(x);
        if(!(ret.size == 1 && ret.N[0] == 0))ret.sign = !ret.sign;
        return ret;
    }
    // (+) + (-)
    BIGNUM ret = sub_mag(x);
    return ret;
}
inline BIGNUM BIGNUM::operator-(const BIGNUM &x)
{
    if(!sign && !x.sign)    // (+) - (+)
    {
        BIGNUM ret = this->sub_mag(x);
        return ret;
    }
    if(sign && x.sign)     // (-) - (-)
    {
        BIGNUM ret = this->sub_mag(x);
        if(!(ret.size == 1 && ret.N[0] == 0))ret.sign = !ret.sign;
        return ret;
    }
    if(sign && !x.sign)    // (-) - (+)
    {
        BIGNUM ret = add_mag(x);
        ret.sign = true;
        return ret;
    }
    // (+) - (-)
    BIGNUM ret = add_mag(x);
    return ret;
}
BIGNUM BIGNUM::operator*(const BIGNUM &x)
{
    BIGNUM ret;
    ret.size = size+x.size-1;
    for(int i=0;i<ret.size;i++)
        ret.N[i] = 0;
    for(int i=0;i<x.size;i++)
    {
        for(int j=0;j<size;j++)
            ret.N[i+j] += x.N[i]*N[j];
    }
    ret.do_carry();
    ret.compress();
    ret.sign = (sign ^ x.sign);
    if(ret.sign && (ret.size == 1 && ret.N[0] == 0))
        ret.sign = false;
    return ret;
}
void test()
{
    cout<<"TESTING START..."<<endl;
    string str;
    // initialization
    BIGNUM n1;
    assert(n1.size == 1);
    assert(n1.N[0] == 0);

    // load_from_LL
    cout<<"TESTING load_from_LL...";
    n1.load_from_LL(0);
    assert(n1.get_str() == "0");

    n1.load_from_LL(-0);
    assert(n1.get_str() == "0");

    n1.load_from_LL(123);
    assert(n1.get_str() == "123");

    n1.load_from_LL(1234567);
    assert(n1.get_str() == "1234567");

    n1.load_from_LL(1234567890987654);
    assert(n1.get_str() == "1234567890987654");

    n1.load_from_LL(-123);
    assert(n1.get_str() == "-123");

    n1.load_from_LL(-1234567);
    assert(n1.get_str() == "-1234567");

    n1.load_from_LL(-1234567890987654);
    assert(n1.get_str() == "-1234567890987654");

    BIGNUM n2(n1);
    assert(n1.get_str() == "-1234567890987654");

    cout<<"OK"<<endl;
    // load_from_str
    cout<<"TESTING load_from_str...";
    str = "0";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "-0";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == "0");

    str = "123";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "1234567";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "1234567890987654";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "-123";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "-1234567";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    str = "-1234567890987654";
    n1.load_from_str(str.c_str());
    assert(n1.get_str() == str);

    cout<<"OK"<<endl;
    // cmp
    cout<<"TESTING cmp and comparision operators...";
    long long nums[7] = {0, 123, -123, 1234567, -1234567, 1234567890987654, -1234567890987654};
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            n1.load_from_LL(nums[i]);
            n2.load_from_LL(nums[j]);
            int res;
            if(nums[i] == nums[j])res = 0;
            else if(nums[i] < nums[j]) res = 1;
            else res = -1;
            assert(n1.cmp(n2) == res);
            assert((n1<n2) == (nums[i]<nums[j]));
            assert((n1>n2) == (nums[i]>nums[j]));
            assert((n1==n2) == (nums[i]==nums[j]));
            assert((n1<=n2) == (nums[i]<=nums[j]));
            assert((n1>=n2) == (nums[i]>=nums[j]));
        }
    cout<<"OK"<<endl;
    // add_mag
    cout<<"TESTING add_mag...";
    BIGNUM n3;
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            if(nums[i]>=0 && nums[j]>=0)
            {
                n1.load_from_LL(nums[i]);
                n2.load_from_LL(nums[j]);
                n3.load_from_LL(nums[i]+nums[j]);
                assert(n1.add_mag(n2) == n3);
            }
        }
    cout<<"OK"<<endl;

    //sub_mag
    cout<<"TESTING sub_mag...";
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            if(nums[i]>=0 && nums[j]>=0)
            {
                n1.load_from_LL(nums[i]);
                n2.load_from_LL(nums[j]);
                n3.load_from_LL(nums[i]-nums[j]);

                assert(n1.sub_mag(n2) == n3);
            }
        }
    cout<<"OK"<<endl;

    //operator - unary
    cout<<"TESTING operator- (unary)...";
    for(int i=0;i<7;i++)
    {
        n1.load_from_LL(nums[i]);
        n2.load_from_LL(-nums[i]);

        assert(-n1 == n2);
    }
    cout<<"OK"<<endl;

    //cmp_mag
    cout<<"TESTING cmp_mag...";
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            n1.load_from_LL(abs(nums[i]));
            n2.load_from_LL(abs(nums[j]));
            int x;
            if(abs(nums[i])<abs(nums[j]))
                x = 1;
            else if(abs(nums[i])>abs(nums[j]))
                x = -1;
            else
                x = 0;
            assert(n1.cmp_mag(n2) == x);
        }
    }
    cout<<"OK"<<endl;

    //operator +
    cout<<"TESTING operator+ (binary)...";
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            n1.load_from_LL(nums[i]);
            n2.load_from_LL(nums[j]);
            n3.load_from_LL(nums[i]+nums[j]);
            assert(n1+n2 == n3);
        }
    cout<<"OK"<<endl;

    //operator + (unary)
    cout<<"TESTING operator+ (unary)...";
    for(int i=0;i<7;i++)
    {
        n1.load_from_LL(nums[i]);
        n3.load_from_LL(+nums[i]);
        assert(+n1 == n3);
    }
    cout<<"OK"<<endl;

    //operator -
    cout<<"TESTING operator- (binary)...";
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            n1.load_from_LL(nums[i]);
            n2.load_from_LL(nums[j]);
            n3.load_from_LL(nums[i]-nums[j]);
            assert(n1-n2 == n3);
        }
    cout<<"OK"<<endl;

    //operator *
    cout<<"TESTING operator* (binary)...";
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            if(abs(nums[i])<1e9 && abs(nums[j]) <1e9)
            {
                n1.load_from_LL(nums[i]);
                n2.load_from_LL(nums[j]);
                n3.load_from_LL(nums[i]*nums[j]);
                assert(n1*n2 == n3);
            }
        }
    cout<<"OK"<<endl;

    cout<<"TESTING FINISH!"<<endl;
}
int main()
{
    test();
}
