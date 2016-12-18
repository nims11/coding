#include<iosstream>
#include<string>
using namespace std;
struct sub_num
{
    int start,size;
};
void reverse(string &str)
{
    string str2;
    for(int i=str.length()-1;i>=0;i--)
    str2.push_back(str[i]);
    str=str2;
}
string multiply(const string &N1,const string &N2,struct sub_num SN1,struct sub_num SN2);
string add(const string &N1,const string &N2,struct sub_num SN1,struct sub_num SN2);
string multiply_by_10(const string &N,int pow);
string subtract(const string &N1,const string &N2,struct sub_num SN1,struct sub_num SN2);
//size(n1>n2);
string multiply(const string &N1,const string &N2,struct sub_num SN1,struct sub_num SN2)
{
    int pow_w=SN1.size/2;

    struct sub_num a0={SN1.start,pow_w};
    struct sub_num a1={pow_w,SN1.size-pow_w};
    struct sub_num b0={SN2.start,pow_w};
    struct sub_num b1={pow_w,SN2.size-pow_w};

    add_a0_a1=add(N1,N2,a0,a1);
    struct sub_num a0_a1={0,add_a0_a1.length()};
    add_b0_b1=add(N1,N2,b0,b1);
    struct sub_num b0_b1={0,add_b0_b1.length()}

    string q0=multiply(N1,N2,a0,b0);
    string q1=multiply(add_a0_a1,add_b0_b1,a0_a1,b0_b1);
    string q2=multiply(N1,N2,a1,b1);
    struct sub_num q0_num={0,q0.length()};
    struct sub_num q1_num={0,q2.length()};

    string p0=q0;
    string p1=subtract(q1,add(q0,q2,q0_num,q1_num));
    string p2=q2;

    return add(p0,add(multiply_by_10(p1,pow_w),multiply_by_10(p2,2*pow_w)));
}
int main()
{
    string N1,N2;
    cin>>N1>>N2;
    reverse(N1);
    reverse(N2);
    string res=multiply(N1,N2,struct sub_num(0,N1.length()),struct sub_num(0,N2.length()));
    reverse(res);
    cout<res<<endl;
    return 0;
}
