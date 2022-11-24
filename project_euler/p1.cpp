//SUM THE MULTIPLES OF 3 AND 5 SMALLER THEN 1000.

#include <iostream>
#include<cmath>

int main(){

	double sum=0.;
	for(int n=1; n<1000; n++){
		if(n%3==0 || n%5==0){sum+=n;}		
	}
	std::cout << sum << std::endl;
		
return 0;
}
