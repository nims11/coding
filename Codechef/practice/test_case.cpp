#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream fout("stream.txt");
    fout<<500<<endl;
    for(int i=0;i<500;i++)
    fout<<i<<endl;
    return 0;
}
