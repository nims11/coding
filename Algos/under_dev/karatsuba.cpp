#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;
const int BASE=1000;
const int BASE_pow=3;
int int_len(int x)
{
    if(x==0)
    return 1;
    int count=0;
    while(x!=0)
    {
        x/=10;
        count++;
    }
    return count;
}

void show(vector <int> &N)
{
    int i;
    for(i=N.size()-1;N[i]<=0 && i>0;i--);
    int start=i;
    for(;i>=0;i--)
    {
        int len=int_len(N[i]);
        for(int j=0;j<BASE_pow-len && i!=start;j++)
        printf("0");
        printf("%lld",N[i]);
    }
    printf("\n");
}
void add(vector <int> &N1,vector <int> &N2,int start1,int start2,int size1,int size2,vector <int> &N3)
{
    long long carry=0,x;
    for(int i=start1,j=start2;(i<start1+size1)||(j<start2+size2);i++,j++)
    {
        x=carry;
        if(i<size1+start1 && i<N1.size())
        x+=N1[i];
        if(j<size2+start2 && j<N2.size())
        x+=N2[j];
        N3.push_back(x%BASE);
        carry=x/BASE;
    }
    x=carry;
    if(x>0)
    N3.push_back(x);
}
void subtract(vector <int> &N1,vector <int> &N2,vector <int> &N3)
{
    bool carry=false;
    long long x;
    for(int i=0;i<N1.size();i++)
    {
        x=N1[i];
        if(carry)
        {
            carry=false;
            x--;
            if(x==-1)
            {
                x=BASE-1;
                carry=true;
            }
        }
        if(i<N2.size())
        if(x<N2[i])
        {
            x+=BASE;
            carry=true;
        }
        if(i<N2.size())
        N3.push_back(x-N2[i]);
        else
        N3.push_back(x);
    }
}
void trans(vector <int> &N1, int pow_w)
{
    if(N1.size()!=1 || N1[N1.size()-1]!=0)
for(int i=0;i<pow_w;i++)
N1.insert(N1.begin(),0);
}

void multiply_nor(vector <int> &N1,vector <int> &N2,int start,int size,vector <int> &N3)
{
   // vector< vector<int> > small_mul;
//   cout<<"*****"<<start<<" "<<size<<endl;
//   show(N1);show(N2);
    for(int i=start;i<size+start;i++)
    {
        int x=N2[i];
        vector<int> mul;
        int carry=0;
        for(int j=start;j<size+start;j++)
        {
            long long y=N1[j];
            long long z=x*y+carry;
            carry=z/BASE;
            mul.push_back(z%BASE);
        }
        while(carry>0)
        {
            mul.push_back(carry%BASE);
            carry/=BASE;
        }
        //small_mul.push_back(mul);
        carry=0;
//        cout<<N3.size()<<endl;
        for(int j=0;j<mul.size();j++)
        {
            if(j+i-start>=N3.size())
            {
                N3.push_back(carry+mul[j]);
                carry=N3[j+i-start]/BASE;
                N3[j+i-start]%=BASE;
            }else
            {
                N3[j+i-start]+=mul[j]+carry;
                carry=N3[j+i-start]/BASE;
                N3[j+i-start]%=BASE;
            }
        }
        while(carry>0)
        {
            N3.push_back(carry%BASE);
            carry/=BASE;
        }
    }
    for(int i=N3.size()-1;N3[i]==0 && i>0;i--)
    N3.erase(N3.begin()+i);
//    show(N3);
}
void multiply(vector <int> &N1,vector <int> &N2,int start,int size,vector <int> &N3)
{
    //cout<<"*1\n";
//    //cout<<"start "<<start<<" "<<size<<endl;
//    show(N1);
//    show(N2);
    static int count=0;

    count++;

    if(size==1)
    {
        int x=1;
        if(start<N1.size())
        x*=N1[start];
        else
        x=0;
        if(start<N2.size())
        x*=N2[start];
        else
        x=0;

        N3.push_back(x%BASE);
        x/=BASE;
        if(x!=0)
        N3.push_back(x);
//        multiply_nor(N1,N2,start,size,N3);
//        show(N3);
//cout<<"end "<<start<<" "<<size<<endl;

        return;
    }
    int pow_w=size/2;
    int a0_start=start;
    int a1_start=pow_w+start;
    int b0_start=start;
    int b1_start=pow_w+start;
    vector<int> a0_add_a1;
    add(N1,N1,a0_start,a1_start,pow_w,size-pow_w,a0_add_a1);
    vector<int> b0_add_b1;
    add(N2,N2,b0_start,b1_start,pow_w,size-pow_w,b0_add_b1);
    int size_add=a0_add_a1.size()>b0_add_b1.size()?a0_add_a1.size():b0_add_b1.size();
//cout<<"a0+a1: ";show(a0_add_a1);
//cout<<"b0+b1: ";show(b0_add_b1);
    vector<int> p0;
    multiply(N1,N2,start,pow_w,p0);
    vector<int> q1;
    multiply(a0_add_a1,b0_add_b1,0,size_add,q1);
    vector<int> p2;
    multiply(N1,N2,pow_w+start,size-pow_w,p2);
////    cout<<"p0: ";show(p0);
//    cout<<"q1: ";show(q1);
//    cout<<"p2: ";show(p2);

    vector<int> p1;
    vector<int> tmp;
    add(p0,p2,0,0,p0.size(),p2.size(),tmp);
    subtract(q1,tmp,p1);

    trans(p1,pow_w);
    trans(p2,2*pow_w);
    vector <int> tmp2;
    add(p1,p2,0,0,p1.size(),p2.size(),tmp2);
    add(p0,tmp2,0,0,p0.size(),tmp2.size(),N3);
    cout<<count<<endl;
//show(N3);
//cout<<"end "<<start<<" "<<size<<endl;
//cout<<"*4\n";
}

int main()
{
    int t;
    scanf("%d",&t);
//    t=1;
    while(t--)
    {
        int size1=0,size2=0,size3=0;
        string tmp;
        cin>>tmp;
        size1=(tmp.length()-1)/BASE_pow + 1;
        vector <int> N1(size1);
        for(int i=0;i<tmp.length();i++)
        {
            N1[((tmp.length()-1-i)/BASE_pow)]=N1[(tmp.length()-1-i)/BASE_pow]*10+tmp[i]-'0';
        }

        cin>>tmp;
        size2=(tmp.length()-1)/BASE_pow + 1;
        vector <int> N2(size2),N3;
        for(int i=0;i<tmp.length();i++)
        {
            N2[((tmp.length()-1-i)/BASE_pow)]=N2[(tmp.length()-1-i)/BASE_pow]*10+tmp[i]-'0';
        }

        int size=size1>size2?size1:size2;
        multiply_nor(N1,N2,0,size,N3);
        show(N3);
    }
    return 0;
}
