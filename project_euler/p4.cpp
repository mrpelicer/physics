//Largest palindrome from the product of three digit numbers

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

size_t invert_function(size_t n){

	size_t inv=0;

	while(n>0){
		inv=10*inv+(n%10);
		n=n/10;		
	}
	
	return inv;
}

int main(){
/*
	size_t number = 1234;
	size_t inverse=invert_function(number);
	std::cout <<  number << " " << inverse << std::endl;
*/

	size_t min=100, max=999;
	size_t product, inverse;

	bool palindrome;
	size_t largest=0;

	for(size_t a=min; a<=max; a++){
	for(size_t b=max; b>a; b--){
		product= a*b;
		inverse=invert_function(product);	
		(product-inverse==0) ? palindrome=true : palindrome=false;

		if(palindrome){
			if(product>largest) largest=product;
		
			std::cout << a << " " << b << " " << product << " " << inverse << " " << largest << std::endl;
		}
	}
	}

	std::cout << "Largest palidrome: " << largest << std::endl; 
return 0;
}
