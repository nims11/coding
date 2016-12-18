#include <iostream>
#include <cstring>
using namespace std;
bool FLAG=true;
bool isOperator(char ch)
{
    switch(ch)
    {
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
        return true;
    }
    return false;
}
void insert(int i,char exp[],int j)
{
    char tmp=exp[i];
    for(int k=i+1;k<=j;k++)
    exp[k-1]=exp[k];
    exp[j]=tmp;
}
void toPost(char exp[],int openBracket,int closeBracket)
{
    int localFlag=0;
    for(int i=openBracket+1;i<closeBracket;i++)
    {
        if(exp[i]=='[')
        {localFlag+=1;}
        else if(exp[i]==']')
        {
            localFlag-=1;
        }

        if(localFlag==0)
        {
            i++;
            if(isOperator(exp[i]))
            {
                int localFlag=0;
                for(int j=i+1;j<closeBracket;j++)
                {
                    if(exp[j]=='[')
                    {localFlag+=1;}
                    else if(exp[j]==']')
                    {
                        localFlag-=1;
                    }

                    if(localFlag==0)
                    {
                        insert(i,exp,j);
                        break;
                    }
                }
            }
            break;
        }
    }
}
void divideNconquer(char exp[])
{
    int size=strlen(exp);
    int openBracket=-1;
    int closeBracket=-1;
    for(int i=0;i<size;i++)
    {
        if(exp[i]=='(')
        openBracket=i;
        else if(exp[i]==')')
        {
            closeBracket=i;
            toPost(exp,openBracket,closeBracket);
            exp[openBracket]='[';
            exp[closeBracket]=']';
            break;
        }
    }
    if(openBracket==-1)
    FLAG=false;
}
int main()
{
    char exp[500];
    int n,size;
    cin>>n;
    while(n--)
    {
        cin>>exp;
        while(FLAG)
        divideNconquer(exp);
        FLAG=true;
        size=strlen(exp);
        for(int i=0;i<size;i++)
        if(exp[i]!='[' && exp[i]!=']')
        cout<<exp[i];
        cout<<endl;
    }
    return 0;
}
