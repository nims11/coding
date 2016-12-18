int gcd(int a, int b)
{
    while(a%=b^=a^=b^=a);
    return a+b;
}
