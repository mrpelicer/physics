//g++ ho_boost.cpp -I/usr/include/python3.6m -std=c++11  -lpython3.6m -lpthread && ./a.out 

#include <iostream>
#include <boost/array.hpp>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;
typedef boost::array< double , 2 > state_type;

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

struct push_back_state_and_time
{
    std::vector< state_type >& m_states;
    std::vector< double >& m_times;

    push_back_state_and_time( std::vector< state_type > &states , std::vector< double > &times )
    : m_states( states ) , m_times( times ) { }

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }
};

class ho_class{
	double gam;

public:

	ho_class(){ 
		gam=0.;
	}
	
	void setGamma(double gamma_){
	gam=gamma_;
	}
	
	void operator() (const state_type &x , state_type &dxdt , const double )
	{
	    dxdt[0]= x[1];
	    dxdt[1]= -x[0]-gam*x[1];
	}
};

void write( const state_type &x , const double t )
{
    std::cout << t << '\t' << x[0] << '\t' << x[1] << std::endl;
}

int main(int argc, char **argv)
{
   state_type x = {0., 1. }; // initial conditions (x, v) in [L], [L]/[T]. 
	ho_class ho;
	ho.setGamma(0.3);
	
	std::vector<state_type> x_vec;
	std::vector<double> t_vec;	
	
	double tmax=50.;
	double dt=1e-2;
	std::vector<double> x_save, v_save;
	/*
	size_t steps= integrate( ho , x , 0.0 , tmax , dt, push_back_state_and_time( x_vec , t_vec )  );
       
    for(size_t ii=0; ii<=steps; ii++){
	    std::cout << t_vec[ii] << " " << x_vec[ii][0] << " " << x_vec[ii][1] <<  std::endl;
	    x_save.push_back(x_vec[ii][0]);
  	    v_save.push_back(x_vec[ii][1]);
	 	}
 */
 
    runge_kutta4< state_type > stepper;
    for(double t=0.; t<=tmax; t+=dt){
        stepper.do_step( ho , x , t , dt );
			x_save.push_back(x[0]);
  	    	v_save.push_back(x[1]);
  	    	t_vec.push_back(t);
  	    	std::cout << t << " " << x_save[x_save.size()-1] << " " << v_save[v_save.size()-1] << std::endl;
  	    	t+=dt;
	}
    
    
     plt::figure_size(1200, 768);
     plt::named_plot("X (m)", t_vec, x_save);
     plt::named_plot("V (m/s)", t_vec, v_save);
    
     plt::xlabel("t(s)");
    
     plt::legend();
     plt::show();
    
    const char* filename = "./ho.png";
    std::cout << "Saving result to " << filename << std::endl;;
    plt::save(filename);
  
    return 0;
}
