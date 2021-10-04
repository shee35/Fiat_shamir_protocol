//--------------------BOB--------------------------

#include<bits/stdc++.h>
using namespace std;

#define USER_INPUT

int32_t GetRandomNumber(const int32_t min, const int32_t max)
{
	return (rand() % (max - min)) + min;
}

int32_t GetRandomSign()
{
   
    if((rand()%2)&1)
    return -1;
    else
    return 1;
}

class NumberGenerator
{
	int32_t min = 100;
	int32_t max = 10000;
	std::vector<int> primeNumbers;

	void GeneratePrimeNumbers(int32_t min, int32_t max)
	{
		primeNumbers.clear();

		for (int32_t i = min; i != max + 1; i++) {
			int32_t j;
			for (j = 2; j < i; j++) {
				if (i % j == 0) {
					break;
				}
			}
			if (i == j) {
				primeNumbers.push_back(i);
			}
		}
	}
	
	
public:
	NumberGenerator(int32_t min_ = 100, int32_t max_ = 10000)
	{
		min = min_;
		max = max_;
	}
	int32_t GetLargePrimeNumber()
	{
		GeneratePrimeNumbers(min, max);

		int32_t index = GetRandomNumber(0, primeNumbers.size());
		return primeNumbers[ index ];
	}
};




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


    std::cout<<"HI ! I AM BOB(Verifier) \n\n";
	auto numGen = NumberGenerator(1, 30);

	int32_t p = numGen.GetLargePrimeNumber();
	int32_t q = numGen.GetLargePrimeNumber();
	
	int32_t n = p * q;
    cout<<"Prime Number 1 is p = "<<p<<"\n\n";
    cout<<"Prime Number 2 is q = "<<q<<"\n\n";
	std::cout<<"n = " << p << "*" << q << " = " << n << " (public)"<<"\n\n";

	int32_t v ;
	std::cout<<"Enter v  (your public key)"<<"\n\n";
	std::cin>>v;

	
	int32_t x;
	std::cout<<"Enter value of x = "<<"\n\n";
	std::cin>>x;

	int32_t e = GetRandomNumber(0, 2);
	std::cout<<"e = " << e<<"\n\n";

	int32_t y = 0;

#ifdef USER_INPUT
	std::cout << "Give value of y, such that y = r * s^e: ";
	std::cin >> y;
#else
	y = r * pow(s, e);
	y = y % n;
	p("y = " << y);
#endif

	int32_t y_sq_mod_n = (y * y) % n;
	std::cout<<"y^2 mod n = " << y_sq_mod_n<<"\n\n";

	int32_t test = (x * (int)pow(v, e)) % n;
	std::cout<<"Tested Value = " << test<<"\n";

	if (y_sq_mod_n == test) {
		std::cout<<"YES ! ALICE IS AUTHENTICATED TO LOGIN"<<"\n";
	} else {
		std::cout<<"NO! ALICE IS NOT AUTHENTICATED TO LOGIN"<<"\n";
	}


	return 0;
}