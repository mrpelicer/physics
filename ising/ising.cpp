//compile as g++ ising.cpp -lgsl -lgslcblas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<gsl/gsl_rng.h>

#define Nx 25     //tamanho da rede
#define Ny 25     //tamanho da rede
#define Ti 1.0    //temperatura inicial
#define Tf 4.0    //' ' final
#define DT 0.1    //' ' step
#define MC 1e7    //# de passos monte carlo 
#define NT 1e3    //# do passo do transiente

int main(int argc, char ** argv){

  int i, j, k, ip1, im1, jp1, jm1;
  int *rede;
  double E;   //energia após cada interação
  double M;   // magnetização após []
  double E1;  // <E>
  double E2;  //<E^2>
  double M1;  //<M>
  double M2;  //<M^2>
  double Cv;  // calor específico a vol. cte.
  double Xm;  //susceptibilidade magnética
  double DE;  //Delta E
  double T;   //temperature
  gsl_rng_default_seed= (argc==2) ? atoi(argv[1]) : time(NULL);
  gsl_rng *w = gsl_rng_alloc(gsl_rng_taus);

  rede= (int *) calloc(Nx*Ny, sizeof(int));
        
  for(i=0; i<Nx; i++){
  for(j=0; j<Ny; j++){
      
    if(gsl_rng_uniform(w)<0.5) rede[i*Ny+j] = 1;
    else                       rede[i*Ny+j] = -1;
  
  }
  }

  for(T=Ti; T<Tf; T+=DT){
    //transiente - começo
    for(k=0; k<NT; k++){
      i=gsl_rng_uniform(w)*Nx;
      j=gsl_rng_uniform(w)*Ny;

      ip1= (i+1)%Nx;
      im1= (i-1+Nx)%Nx;
      jp1= (j+1)%Ny;
      jm1= (j-1+Ny)%Ny;
      DE= 2.*rede[i*Ny+j]*(rede[ip1*Ny+j]+ rede[im1*Ny+j]+
                           rede[i*Ny+jp1]+ rede[i*Ny+jm1]);
      if(gsl_rng_uniform(w)<exp(-DE/T)){
        rede[i*Ny+j] *= -1;
      }
    }



    //transiente - fim

    E= M = 0.0;
//energia e magnetização
    for(i=0; i<Nx; i++){
    for(j=0; j<Ny; j++){
      ip1= (i+1)%Nx;
      jp1= (j+1)%Ny;
      E-= rede[i*Ny+j]*(rede[ip1*Ny+j]+rede[i*Ny+jp1] );
      M+= rede[i*Ny+j];
    }
    }

//método monte carlo
    E1=E2=M1=M2=0.;
    for(k=0; k<MC; k++){
      i=gsl_rng_uniform(w)*Nx;
      j=gsl_rng_uniform(w)*Ny;

      ip1= (i+1)%Nx;
      im1= (i-1+Nx)%Nx;
      jp1= (j+1)%Ny;
      jm1= (j-1+Ny)%Ny;
      DE= 2.*rede[i*Ny+j]*(rede[ip1*Ny+j]+ rede[im1*Ny+j]+
                           rede[i*Ny+jp1]+ rede[i*Ny+jm1]);
      if(gsl_rng_uniform(w)<exp(-DE/T)){
        rede[i*Ny+j] *= -1;
        E+=DE;
        M+=2*rede[i*Ny+j];

      }
      E1+=E;
      E2+=E*E;
      M1+=fabs(M);
      M2+=M*M;
    }

    Cv = (E2/MC - E1*E1/(MC*MC))/(T*T); 
    Xm = (M2/MC - M1*M1/(MC*MC))/(T);
    printf("%e %e %e %e %e \n", T, E1/MC, 
    Cv,
    M1/MC,
    Xm
    );
 
 
  }


  free(rede);
  gsl_rng_free(w);
  return 0;

}
