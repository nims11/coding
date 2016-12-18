int GCD(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
