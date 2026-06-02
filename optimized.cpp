#include <iostream>
#include <complex>
#include <chrono>
using namespace std;

const int N = 256;
const int B = 32;

complex<double> A[256][256], C[256][256];

int main(){

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i][j]={1,1};
            C[i][j]={0,0};
        }

    auto start=chrono::high_resolution_clock::now();

    for(int ii=0;ii<N;ii+=B)
    for(int jj=0;jj<N;jj+=B)
    for(int kk=0;kk<N;kk+=B)

        for(int i=ii;i<ii+B;i++)
        for(int j=jj;j<jj+B;j++)
        for(int k=kk;k<kk+B;k++)
            C[i][j]+=A[i][k]*A[k][j];

    auto end=chrono::high_resolution_clock::now();

    double t=chrono::duration<double>(end-start).count();

    double c=2.0*N*N*N;
    cout<<"Optimized time: "<<t<<endl;
    cout<<"MFLOPS: "<<c/(t*1e6)<<endl;
}
