#include<iostream>
using namespace std;
int main()
{
int n = 10, N = 10;
int **a = new int* [n];
for(int i = 0;i<n;i++) a[i] = new int[N];
for(int i = 0;i<n;i++) delete [] a[i];
delete [] a;
}
