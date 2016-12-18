void matpow(long long M[2][2],int n, long long x)
{
    if(n>1)
    {
        matpow(M,n/2,x);
        long long a = M[0][0], b = M[0][1], c = M[1][0], d = M[1][1];
        M[0][0] = ((a*a)%mod + (b*c)%mod)%mod;
        M[0][1] = ((a*b)%mod + (b*d)%mod)%mod;
        M[1][0] = ((a*c)%mod + (c*d)%mod)%mod;
        M[1][1] = ((b*c)%mod + (d*d)%mod)%mod;
    }
    if(n&1 && n>1)
    {
        long long a = M[0][0], b = M[0][1], c = M[1][0], d = M[1][1];
        M[0][0] = (x*(a+b))%mod;
        M[0][1] = (a*x)%mod;
        M[1][0] = (x*(c+d))%mod;
        M[1][1] = (c*x)%mod;
    }
}
long long fib(int n, long long start)
{
    long long M[2][2] = {{1,1},{1,0}};
    matpow(M,n,1);
    return start*M[0][0];
}
