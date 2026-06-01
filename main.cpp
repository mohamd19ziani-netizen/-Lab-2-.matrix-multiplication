#include <iostream>
#include <complex>
#include <vector>
#include <chrono>

using namespace std;

int main() {

    const int N = 256;

    vector<vector<complex<double>>> A(
        N,
        vector<complex<double>>(N)
    );

    vector<vector<complex<double>>> B(
        N,
        vector<complex<double>>(N)
    );

    vector<vector<complex<double>>> C(
        N,
        vector<complex<double>>(N)
    );

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = complex<double>(1.0, 1.0);
            B[i][j] = complex<double>(1.0, 1.0);
        }
    }

    auto start =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            for (int k = 0; k < N; k++) {

                C[i][j] +=
                    A[i][k] * B[k][j];
            }
        }
    }

    auto end =
        chrono::high_resolution_clock::now();

    double time =
        chrono::duration<double>(
            end - start
        ).count();

    double operations =
        2.0 * N * N * N;

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
