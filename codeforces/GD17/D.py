from fractions import Fraction
k, pa, pb = map(int, input().split())

pa_pow = [1]
pb_pow = [1]
papb_pow = [1]
for i in range(k+10):
    pa_pow.append(pa_pow[-1]*pa)
    pb_pow.append(pb_pow[-1]*pb)
    papb_pow.append(papb_pow[-1]*(pa+pb))

C = Fraction(pa_pow[k-1]*pb, papb_pow[k])
cur = Fraction((pa + pb) * (k*pb + pa), pb*pb)

ans = Fraction(0, 1)


poss = [(0,0,0),]
def generate(a, b, cur_k):
    global poss
    if(cur_k + a >= k):
        return
    generate(a+1, b, cur_k)
    if a > 0:
        poss.append((a, b+1, cur_k + a))
        generate(a, b+1, cur_k+a)

generate(0, 0, 0)
for (a, b, cur_k) in poss:
    p = Fraction(pa_pow[a] * pa_pow[b] , papb_pow[a+b])
    ans += C * (cur + cur_k*p)


mod = 1000000007
def POW(r, n):
    ans = 1
    while n > 0:
        if(n&1):
            ans = (ans * r)%mod
        n >>= 1
        r = (r*r)%mod
    return ans
P, Q = ans.numerator, ans.denominator

print((P*POW(Q, mod-2))%mod)
