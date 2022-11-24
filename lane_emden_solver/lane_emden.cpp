// compile as g++ lane_emden.cpp -I/usr/include/python3.6m/ -lpython3.6m  
// Change 3.6m accordingly to your the version of your python library.
#include <iostream>
#include <cmath>
#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;
typedef boost::array< double , 2 > state_type;

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

class lane_emden_class{
	double n;

public:
	lane_emden_class(){ n=0.;}

	void setExponent(double n_){
		n=n_;
	}
	
	void operator() (const state_type &x , state_type &dxdt , const double t)
	{
		 if(t!=0.){dxdt[0]= x[1]/(t*t);}
		 else{dxdt[0]=0.;}

	    dxdt[1]= -t*t*pow(x[0], n);
	}
};


int main(int argc, char **argv)
{
   state_type fields = {1., 0. }; // initial conditions (theta, phi)=(1, 0).
	lane_emden_class le;
	
	std::vector<state_type> fields_vec;
	std::vector<double> theta_vec, Dtheta_vec, xi_vec;	
	runge_kutta4< state_type > stepper;
	
	double n=1.;
	le.setExponent(n);
	double xi=0.;
	double dxi=1e-4;
	do{
        stepper.do_step( le , fields , xi , dxi);
			theta_vec.push_back(fields[0]);
  	    	Dtheta_vec.push_back(fields[1]);
  	    	xi_vec.push_back(xi);
  	    	xi+=dxi;
    }while(fields[0]>0.);
    
    double ec=1.;
    double k=1.;
    double a=sqrt(k*(1.+n)*pow(ec, 1./n - 1.)/(4.*M_PI) );
    double Radius= a*xi_vec[xi_vec.size()-1];
    double Mass= -4.*M_PI*ec*pow(a, 3.)*pow(xi_vec[xi_vec.size()-1], 2.)*Dtheta_vec[Dtheta_vec.size()-1];
    
    std::cout << Radius << " " << Mass << std::endl;
    
  
    plt::figure_size(1200, 768);
    plt::plot(xi_vec, theta_vec);
    
    plt::xlabel("xi");
    plt::xlabel("theta");
    
//    plt::legend();
    plt::show();
    
//    const char* filename = "./ho.png";
//   std::cout << "Saving result to " << filename << std::endl;;
//    plt::save(filename);
    return 0;
}
