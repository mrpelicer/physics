#include<iostream>
#include<fstream>
#include<cmath>

int main(){

	
    double gamma=0., k=1., m=1.;
    double x0=0., v0=1.;
	
	double frequency= sqrt(k/m);
	double period= 2.*M_PI/frequency;
	
	std::cout << "Frequency and period= " << frequency << " " << period << std::endl;
	
	std::ofstream otp_rk2("data/rk2.txt");
	std::ofstream otp_exact("data/exact.txt");
	
    double x=x0;
    double v=v0;
	double t=0.;
	double en=0.;

	
    double dt=0.02*period;
    double tmax=30.*period;
    int itmax= tmax/dt;
	
	double k1x, k2x;
	double k1v, k2v;

    for(int it=0; it<=itmax; it++){
        
        k1x= v;
        k1v= -k*x/m;
    
		k2x= v+dt*k1v;
        k2v= -k*(x +dt*k1x)/m;
        
        t+=dt;
        x+=(k1x+ k2x)*dt/2.;
        v+=(k1v+ k2v)*dt/2.;
        
        en=m*v*v/2.+k*x*x/2.;
        
        otp_rk2 << t/period << " " << x << " " << v << " " << 2.*en <<std::endl;
        otp_exact << t/period << " " << v0*sin(frequency*t) << " " << v0*k*cos(frequency*t)/m << std::endl;
    }

otp_rk2.close();
otp_exact.close();
return 0;
}
