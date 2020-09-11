#include <iostream>
#include <string>
#include <vector>
#include "bits/stdc++.h"
#include <algorithm>
#include <math.h>
using namespace std;
long long mod(long long a, long long b)
{ return (a%b+b)%b; }

unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p)  
{  
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 

class Solver {
	string s;
	vector<long long>h1,h2;
	static const long long x=12345,m1=1000000007,m2=1000000009;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation
		long long n=s.length();
		h1=vector<long long>(n+1,0);
		h2=vector<long long>(n+1,0);
		for(long long i=1;i<=n;i++)
		{
			h1[i]=(x*h1[i-1]+s[i-1])%m1;
			h2[i]=(x*h2[i-1]+s[i-1])%m2;
		}
	}
	bool ask(int a, int b, int l) {
		long long h1_a=0,h1_b=0,h2_a=0,h2_b=0;
		long long x_l_1=power(x,l,m1);
		long long x_l_2=power(x,l,m2);
		h1_a=mod(h1[a+l]-x_l_1*h1[a],m1);
		h1_b=mod(h1[b+l]-x_l_1*h1[b],m1);
		h2_a=mod(h2[a+l]-x_l_2*h2[a],m2);
		h2_b=mod(h2[b+l]-x_l_2*h2[b],m2);
		return(h1_a==h1_b&&h2_a==h2_b);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}