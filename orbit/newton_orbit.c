#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1
#define M 1
#define L 8
#define c 1
#define r0 55
#define p0 M_PI
#define vr0 0.0
#define R 1e-5
#define t0 0.0
#define tf 12000
#define dt 1e-5
#define mult (int) (tf/(dt*10000))


double f(double r){
	return (-1.0)*G*M/(r*r) + L*L/(r*r*r);
}

double g(double vr){
	return vr;
}

double h(double r){
	return L/(r*r);
}

int main(int argc, char **argv ){

	int counter= 0;
	double r= r0, p= p0, t= t0, vr= vr0;
	double f1, g1, h1;
	FILE* outp= fopen("nwt.dat", "w");
			
	while(t< tf){
	
/*	if(r<= R){
			fprintf(outp, "%e %e %e\n", 0.0, 0.0, t);
			exit(1);
		}*/
	
	if(counter%mult == 0){
			fprintf(outp, "%e %e %e\n", r*cos(p), r*sin(p), t);
	}
	f1= f(r);
	g1= g(vr);
	h1= h(r);
	
		r+= dt*g1;
		vr+= dt*f1;
		p+= dt*h1;
		t+= dt;
		counter++;
	}
		
fclose(outp);
	return 0;
}
