//Difference between the square of the sum (S1^2) and the sum of the square (S2) of the first one hundred numbers.

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

int main(){
	

	size_t S1=0, S2=0;
	size_t difference;

	size_t N=100;
	
	S1=(N*(N+1))/2;

	for(size_t k=1; k<=N; k++){S2+=pow(k, 2);}

	difference=pow(S1, 2)-S2;


	std::cout << difference << std::endl;
return 0;
}
