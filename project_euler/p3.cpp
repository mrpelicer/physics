//What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>


int main(){

	std::vector<double> primes;
	
	size_t numb=600851475143;
	
	size_t max_factor=1;
	
	
	std::cout << numb << std::endl;
	while(numb%2==0){
		numb=numb/2;
		max_factor=2;
	}		

	
	for(size_t div=3; div<sqrt(numb); div+=2){
		while(numb%div==0){
			numb=numb/div;	
			max_factor=div;

		}
					std::cout << div << " " <<  numb << "	" << max_factor<< std::endl;
	}
	
	if(numb>2)max_factor=numb;

	std::cout << "Largest prime factor: " << max_factor << std::endl;
		
return 0;
}
