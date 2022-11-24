//SUM ALL EVEN FIBONNACI NUMBERS SMALLER THEN 4e6
#include <iostream>
#include<cmath>
#include <limits>

typedef std::numeric_limits< double > dbl;

int main(){

	double long sum=0.;
	int fib1=1, fib2=1, fibn=1;

	
	
	while(fibn<4e6){
		std::cout << fibn << std::endl;
		if(fibn%2==0){sum+=fibn;}
		
		fibn=fib1+fib2;
		fib2=fib1;
		fib1=fibn;

	};	

	std::cout.precision(dbl::max_digits10);	
	std::cout << "sum: " << sum << std::endl;
		
return 0;
}
