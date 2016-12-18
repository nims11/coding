import java.util.*;
class primes{
	int primes[] = new int[4000];
	int count = 0;
	void generate_primes(int n) {
		primes[count++] = 2;
		int lt = (int)Math.sqrt(n);
		for(int i=3;i<=lt;i++) {
			if(isprime(i)) primes[count++] = i;
		}
	}
	boolean isprime(int n) {
		if(n==1) return false;
		int i = 0;
		int lt = (int)Math.sqrt(n);
		while(primes[i] <= lt && i<count) {
			if(n % primes[i] == 0)
				return false;
			i++;
		}
		return true;
	}
}
public class PRIME1 {
	public static void main (String args[]) {
		primes P = new primes();
		P.generate_primes(1000000000);
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- != 0) {
			int n = in.nextInt(),m = in.nextInt();
			while(n<=m) {
				if(P.isprime(n))
					System.out.println(n);
				n++;
			}
			System.out.println();
		}
	}
}

