#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
unsigned long long PolyHash(string S,unsigned long long p,unsigned long long x)
{
	unsigned long long hash=0;
	for(long long i=S.length()-1;i>=0;i--)
	{
		hash=(hash*x+S[i])%p;
	}
	return hash;
}
long long mod(long long a, long long b)
{ return (a%b+b)%b; }
std::vector<unsigned long long> PrecomputeHashes(string T,unsigned long long P_len, unsigned long long p, unsigned long long x)
{
	vector<unsigned long long> H (T.length()-P_len+1);
	string S=T.substr(T.length()-P_len,P_len);
	H[T.length()-P_len]=PolyHash(S,p,x);	
	ull y = 1;
	for(ull i = 1 ;i<=P_len;i++)
	{
		y=(y*x)%p;
	}
	for(long long i = T.length()-P_len-1 ;i>=0;i--)
	{
		long long a=(T[i]-y*T[i+P_len]);
		a=mod(a,p);
		H[i]=(x*H[i+1]+a)%p;
	}
	return H;
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
	//unsigned long long p=100000007;
	unsigned long long p = 7727;
	unsigned long long x=rand()%((p-1)-1 + 1) + 1;
    std::vector<int> result;
	unsigned long long pHash = PolyHash(s,p,x);
	vector<unsigned long long> H = PrecomputeHashes(t, s.length(), p, x);
	for (size_t i = 0; i <=t.length()-s.length(); ++i)
	{
		if(pHash!=H[i])
			continue;
		if(t.substr(i,s.length())==s)
			result.push_back(i);
	}
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}