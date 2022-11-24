//Nth prime number

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

#define MAX_PRIME 2e6


void FillPrimes(std::vector<size_t> &primes){

	std::vector<bool> isPrime(MAX_PRIME);
	std::fill(isPrime.begin(), isPrime.end(), true);



	for(size_t n=2; n*n<MAX_PRIME; n++){
	
		if(isPrime[n]==true){
			for(size_t i=n*n; i<MAX_PRIME; i+=n){
				isPrime[i]=false;
			}
		}

	}

	for(size_t p=2; p<MAX_PRIME; p++){
		if(isPrime[p]){primes.push_back(p);}
	}	
	


}

int main(){
	size_t N1=1000;
	size_t N2=2000;
	size_t N3=3000;
	size_t N= 10001;

	std::vector<size_t> primes;
	FillPrimes(primes);

	long sum=0.;
	for(int i=0; i<=primes.size(); i++){
		sum+=primes[i];
	}
	
	
	std::cout.precision(17);


	std::cout << primes[0] << " " << primes[primes.size()-1] << " Sum: " << sum << std::endl;

return 0;
}
