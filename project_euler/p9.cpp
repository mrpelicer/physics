//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

#include <iostream>
#include <cmath>
#include <sstream>
#include <limits>
#include <vector>

int main(){
	size_t N=1000;
	size_t a, b;
	double c;
	bool condition =false;	

	for(int ia=1; ia<N/2; ia++){
	a=ia;		
	for(int ib=1; ib<=a; ib++){
	b=ib;
	c=sqrt( pow(a, 2)+pow(b, 2)); 
	
	if(a+b+c==N){
		condition=true;
		break;
	}
	std::cout << a << " " << b << " " << c << " " << a+b+c <<std::endl;
}
	
	if(condition)break;	

	
	}

std::cout << a << " " << b << " " << c << " " << a+b+c <<std::endl;

std::cout <<"multiplication: " << a*b*c <<std::endl;
	return 0;
}
