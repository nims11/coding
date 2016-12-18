#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

class BIGNUM{
  char *number;
  int size;
  //void changeSize(int newSize);
  
public:
  bool negative;
  BIGNUM();
  BIGNUM(long n);
  BIGNUM(std::string n);
  ~BIGNUM();
  char *getNum();
  int getSize();
  int getLength();
  void show();
};
char* BIGNUM::getNum(){
  return number;
}
BIGNUM::BIGNUM(){
  size=200;
  negative=false;
  number=new char[size];
  for(int i=0;i<size;i++)
    number[i]='0';
  }
BIGNUM::BIGNUM(long n){
  size=200;
  negative=false;
  number=new char[size];
  int i;
  for(i=0;n>0;n/=10,i++)
    number[i]=n%10+'0';
  for(;i<size;i++)
    number[i]='0';
  }
  
BIGNUM::BIGNUM(std::string n){
  size=200;
  negative=false;
  number=new char[size];
  int i;
  int length=n.size();
  for(i=length-1;i>=0;i--)
    number[length-1-i]=n[i];
  
  for(i=length;i<size;i++)
    number[i]='0';
  }

BIGNUM::~BIGNUM(){
  delete [] number;
}
int BIGNUM::getLength(){
  int i;
  
  for(i=size-1;i>0;i--)
    if(number[i]!='0')
      break;
    return i+1;
}
void BIGNUM::show(){
  int length=getLength();
  if(negative)
    std::cout<<'-';
  for(int i=length-1;i>=0;i--)
    std::cout<<number[i];
}
int BIGNUM_gt(BIGNUM &a,BIGNUM &b)
{
  int lena=a.getLength(),lenb=b.getLength();
  if(lena > lenb)
    return 1;
  if(lena < lenb)
    return 0;
  char *a1=a.getNum();
  char *b1=b.getNum();
  for(int i=lena-1;i>=0;i--){
    if(a1[i] > b1[i])
      return 1;
    if(a1[i] < b1[i])
      return 0;
  }
  return -1;
}
BIGNUM& BIGNUM_Add(BIGNUM &a,BIGNUM &b)
{
  BIGNUM *result=new BIGNUM;
  char *sum=result->getNum();
  int len1=a.getLength();
  int len2=b.getLength();
  int len=len1>len2?len1:len2;
  int carry=0;
  char *a1=a.getNum();
  char *b1=b.getNum();
  int i;
  for(i=0;i<len;i++){
    int sum1=a1[i]-'0'+b1[i]-'0'+carry;
    carry=sum1/10;
    sum[i]+=sum1%10;
  }
  while(carry>0){
    int sum1=carry;
    carry=sum1/10;
    sum[i++]+=sum1%10;
  }
  
  return *result;
}

BIGNUM& BIGNUM_Sub(BIGNUM &a,BIGNUM &b)
{
  BIGNUM *result=new BIGNUM;
  char *diff=result->getNum();
  int len1=a.getLength();
  int len2=b.getLength();
  int len=len1>len2?len1:len2;
  bool carry=false;
  char *a1;
  char *b1;
  if(BIGNUM_gt(a,b)!=0){
    a1=a.getNum();
    b1=b.getNum();
  }else{
    result->negative=true;
    a1=b.getNum();
    b1=a.getNum();
  }
  
  for(int i=0;i<len;i++){
    if(!carry){
      if(a1[i]>=b1[i])
	diff[i]+=a1[i]-b1[i];
      else{
	carry=true;
	diff[i]+=a1[i]+10-b1[i];
    }}else{
      if(a1[i]-1>=b1[i]){
	diff[i]+=a1[i]-1-b1[i];
	carry=false;
      }else{
	carry=true;
	diff[i]+=a1[i]-1+10-b1[i];
      }
    }
  }
  
  return *result;
}
BIGNUM& BIGNUM_Divide(BIGNUM &a,int n){
  char quotient[150];
  int count=0;
  char *a1=a.getNum();
  int len=a.getLength();
  int carry=0;
  if(a1[len-1]-'0'<n)
    carry=a1[len-1]-'0';
  else{
    carry=(a1[len-1]-'0')%n;
    quotient[count++]=(a1[len-1]-'0')/n + '0';
  }
  for(int i=len-2;i>=0;i--){
    quotient[count++]=(a1[i]-'0'+carry*10)/n + '0';
    carry=(a1[i]-'0'+carry*10)%n;
  }
  quotient[count]='\0';
  BIGNUM *result=new BIGNUM(quotient);
  return *result;
}

int main()
{
  using namespace std;
  char n[102],d[102];
  while(cin.getline(n,102,'\n') && cin.getline(d,102,'\n')){
    BIGNUM n1(n);BIGNUM d1(d);
    BIGNUM x=BIGNUM_Divide(BIGNUM_Sub(n1,d1),2);
    BIGNUM_Add(x,d1).show();cout<<endl;
    x.show();cout<<endl;
    
  }
  return 0;
}