#include <iostream>
#include <complex>
#include <chrono>

using namespace std;

const int N = 4096;
const int B = 64;

complex<double> A[N][N], C[N][N];

int main() {

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i][j] = {1.0,1.0};
            C[i][j] = {0.0,0.0};
        }

    auto start = chrono::high_resolution_clock::now();

    for(int ii=0; ii<N; ii+=B)
    for(int jj=0; jj<N; jj+=B)
    for(int kk=0; kk<N; kk+=B)

        for(int i=ii; i<ii+B; i++)
        for(int j=jj; j<jj+B; j++)
        for(int k=kk; k<kk+B; k++)
            C[i][j] += A[i][k] * A[k][j];

    auto end = chrono::high_resolution_clock::now();

    double t = chrono::duration<double>(end-start).count();

    double c = 2.0 * N * N * N;
    double mflops = c / (t * 1e6);

    cout << "Author: зиани мохаммед\n";
    cout << "Group: 090304-РПИа-о25\n";
    cout << "Optimized Time: " << t << " sec\n";
    cout << "MFLOPS: " << mflops << endl;

    return 0;
}
