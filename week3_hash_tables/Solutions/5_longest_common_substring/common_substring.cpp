#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define MOD (1e9 + 7)
struct Answer {
	int i, j, len;
};

unsigned long long mod(unsigned long long a,unsigned long long b)
{ return (a%b+b)%b; }

unsigned long long pow(unsigned long long x, unsigned long long y)  
{  
    int res = 1;     // Initialize result  
  
    x = mod(x,MOD); // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = mod((res*x),MOD);  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = mod((x*x),MOD);  
    }  
    return res;  
} 

bool kcs(string s1,string s2,int m,int&a,int&b)
{
	unsigned long long hs1 = 0,hs2;
	unsigned long long B = 1;
	map<string,unsigned long long> M;
	map<string,unsigned long long> a_final;
	map<string,unsigned long long> b_final;
	string st="";
	st = s1.substr(0,m);
	for(unsigned long long i=0;i<m;i++)
	{
		unsigned long long t = pow(B,i);
	    t=(unsigned long long)(s1[i]-'a')*t;
		hs1 = hs1 + t;
	}

	M[st]=hs1;
	a_final[st]=0;
	for(unsigned long long i=m;i<s1.length();i++)
	{
		st = s1.substr(i-m+1,m);
		hs1 = hs1 - (unsigned long long)(s1[i-m]-'a');
		unsigned long long t = pow(B,m-1);
		hs1 = hs1/B + (unsigned long long)(s1[i]-'a')*t;
		M[st] = hs1;
		a_final[st]=i-m+1;
	}
	
	hs2 = 0;
	st = "";
	st = s2.substr(0,m);
	for(unsigned long long i=0;i<m;i++)
	{
		unsigned long long t = pow(B,i);
		hs2 =  hs2 + (unsigned long long)(s2[i]-'a')*t;
	}
	
	if(M[st] == hs2)
	{
		a=min(a_final[st],(unsigned long long)(s1.length()-1));
		b=0;
		return true;
	}
	
	for(unsigned long long i=m;i<s2.length();i++)
	{
		st = s2.substr(i-m+1,m);
		hs2 = hs2 - (unsigned long long)(s2[i-m]-'a');
		unsigned long long t = pow(B,m-1);
		hs2 = hs2/B + (unsigned long long)(s2[i]-'a')*t;
		b_final[st]=i-m+1;
		if(M[st]==hs2)
		{
			a=min(a_final[st],(unsigned long long)(s1.length()-1));
			b=min(b_final[st],(unsigned long long)(s2.length()-1));
			return true;
		}
	}
	return false;
}
Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	unsigned long long l = 0 , r = min(s.length(),t.length());
	while(l<=r){
		int mid = l + (r-l)/2;
		if(kcs(s,t,mid,ans.i,ans.j)){
			l = mid+1;
		}
		else
			r = mid -1;
	}
	ans.len=l-1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}