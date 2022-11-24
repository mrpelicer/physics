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

	std::cout << "The " << N1 << "th prime is " << primes[N1-1] << std::endl;
	std::cout << "The " << N2 << "th prime is " << primes[N2-1] << std::endl;
	std::cout << "The " << N3 << "th prime is " << primes[N3-1] << std::endl;
	std::cout << "The " << N << "th prime is " << primes[N-1] << std::endl;
// WORKS, BUT INNEFICIENT:
//	size_t count=1, test_prime=1;
//	size_t residue=0;
//	bool isPrime=false;
//
//	while(count!=N){
//		test_prime+=2;
//		isPrime=true;	
//
//		for(size_t k=2; k<test_prime; k++){
//		 	residue=test_prime%k;
//			if(residue==0){
//				isPrime=false;
//				break;
//			}
//
//			std::cout <<test_prime << " " <<  residue << " " << k << " " << count << std::endl;
//		}
//
//  			if(isPrime){count++;}
//
//		
//		}
//	
//	std::cout << "sol: " << test_prime << " " <<count << " " << test_max << std::endl;
return 0;
}
