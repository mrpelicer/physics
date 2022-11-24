//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

int main(){
	

	size_t smallest;
	size_t min=2, max=20;
	bool divisible=false;

	size_t test=max;

	while(!divisible){
	divisible=true;
	
		for(size_t a=min; a<=max; a++){	
	 	if(test%a!=0){divisible=false;} 
		}

		if(divisible){smallest=test;}
		else{test+=max;}
	}

	std::cout << smallest << std::endl;
return 0;
}
