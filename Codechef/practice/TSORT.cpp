#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("stream.txt");
void getInput(long *num)
{
    fin.ignore(1);
    long count=0;
    long t=0;
    while(!fin.eof())
    {
        char stream[65536];
        fin.read(stream,65536);
        long size=strlen(stream);
        for(long i=0;i<size;i++)
        {
            if(stream[i]=='\n')
            {
                //cout<<i<<" "<<t<<endl;
                num[count++]=t;
                t=0;
                continue;
            }else
            t=t*10+stream[i]-'0';
        }
    }
}
int main()
{
    long t;
    fin>>t;
    long *num=new long[t];
    long *count=new long[1000001];
    memset(count,0,1000001);
    getInput(num);
    for(long i=0;i<t;i++)
    count[num[i]]++;
    for(long i=1;i<1000001;i++)
    count[i]+=count[i-1];
    long *output=new long[t];
    for(long i=t-1;i>=0;i--)
    {
        output[count[num[i]]-1]=num[i];
        count[num[i]]--;
    }
//    for(long i=0;i<t;i++)
//    cout<<output[i]<<endl;
    delete [] num;
    delete [] count;
    delete [] output;
    return 0;
}
