#include<iostream>
#include<fstream>
#include<cmath>

int main(){

	
    double gamma=0., k=1., m=1.;
    double x0=0., v0=1.;
	
	double frequency= sqrt(k/m);
	double period= 2.*M_PI/frequency;
	
	std::cout << "Frequency and period= " << frequency << " " << period << std::endl;
	
	std::ofstream otp_euler("data/euler.txt");
	std::ofstream otp_exact("data/exact.txt");
	
    double x=x0;
    double v=v0;
	double t=0.;
	double en=0.;
	
    double dt=0.02*period;
    double tmax=5.*period;
    int itmax= tmax/dt;
	
    double xtmp, vtmp;

    for(int it=0; it<=itmax; it++){
        xtmp=x;
        vtmp=v;
        
        t+=dt;
        x+=dt*vtmp;
        v+=(dt/m)*(-k*xtmp);
        
        en=m*v*v/2.+k*x*x/2.;
        
        otp_euler << t/period << " " << x << " " << v << " " << 2.*en << std::endl;
        otp_exact << t/period << " " << v0*sin(frequency*t) << " " << v0*frequency*cos(frequency*t) << std::endl;
    }

otp_euler.close();
otp_exact.close();
return 0;
}
