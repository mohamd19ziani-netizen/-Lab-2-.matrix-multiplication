#include <iostream>
#include <complex>
#include <vector>
#include <chrono>
#include <cblas.h>

using namespace std;

int main() {
    const int N = 4096;

    vector<complex<double>> A(N * N);
    vector<complex<double>> B(N * N);
    vector<complex<double>> C(N * N);

    for (int i = 0; i < N * N; i++) {
        A[i] = complex<double>(1.0, 1.0);
        B[i] = complex<double>(1.0, 1.0);
    }
i
    complex<double> alpha(1.0, 0.0);
    complex<double> beta(0.0, 0.0);

    auto start = chrono::high_resolution_clock::now();

    cblas_zgemm(
        CblasRowMajor,
        CblasNoTrans,
        CblasNoTrans,
        N,
        N,
        N,
        &alpha,
        A.data(),
        N,
        B.data(),
        N,
        &beta,
        C.data(),
        N
    );

    auto end = chrono::high_resolution_clock::now();

    double time =
        chrono::duration<double>(end - start).count();

    double operations = 2.0 * N * N * N;

    double mflops =
        operations / (time * 1e6);

    cout << "Author: зиани мохаммед" << endl;
    cout << "Group: 090304-РПИа-о25" << endl;

    cout << "Time: "
         << time
         << " sec"
         << endl;

    cout << "MFLOPS: "
         << mflops
         << endl;

    return 0;
}
