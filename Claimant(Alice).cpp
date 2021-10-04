///-------------------------Alice---------------------

#include<bits/stdc++.h>
using namespace std;


int32_t GetRandomNumber(const int32_t min, const int32_t max)
{
	return (rand() % (max - min)) + min;
}



int32_t getCoprime(int32_t n)
{
	int32_t coprime;
	
	do {
		coprime = GetRandomNumber(1, n);
	}
	while (__gcd(n, coprime) != 1);
	
	return coprime;
}

int main()
{
	srand(time(NULL));


      std::cout<<"HI ! I AM ALICE (Claimant) \n\n";


    
    cout<<"Enter values of p and q: "<<"\n\n";
    
	int32_t p ;
	int32_t q ;
    std::cin>> p>>q;

	int32_t n = p * q;

	std::cout<<"n = " << p << "*" << q << " = " << n << " (public)"<<"\n\n";

	int32_t s = getCoprime(n);
	std::cout<<"s = " << s << " (your[Alice] secret)"<<"\n\n";

	int32_t v = (s * s) % n;
	std::cout<<"v = " << v << " give it to Bob (public: s*s)"<<"\n\n";

	int32_t r = GetRandomNumber(1, n);
	std::cout<<"r = " << r << " (A's private)"<<"\n\n";
	
	int32_t x = (r * r) % n;
	std::cout<<"x = " << x<<"\n\n";

	int32_t e ;
	std::cout<<"Enter e challenge from Bob "<<"\n\n";
    std::cin>>e;
    
	int32_t y ;
	y = r * pow(s, e) ;
	std::cout << "Calculated y = "<<y;

	return 0;
}