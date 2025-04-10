#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <cblas.h>

using namespace std;

/* Dot Product is used in multiplying two matrices as long as the number of columns
 * is equal to the number of rows, this can be expressed as  (M*N), and (N*P), representing
 * each matrix.  We can set the range of for loops by using N, applying this rule ^
 */

int main(){
    cout << "Multiplying Two Matrices\n___________________________\n";

    int rowsA, colsA, rowsB, colsB;
    cout << "Enter rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for matrix A: ";
    cin >> colsA;
    cout << "Enter rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible (colsA != rowsB)\n";
        return -1;
    }
    srand(time(0));

    vector<double> A(rowsA * colsA);
    vector<double> B(rowsB * colsB);
    vector<double> C(rowsA * colsB, 0.0);
    vector<double> C_blas(rowsA * colsB, 0.0);  //for OpenBLAS

    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsA; ++j)
            A[i * colsA + j] = rand() % 1001;

    for (int i = 0; i < rowsB; ++i)
        for (int j = 0; j < colsB; ++j)
            B[i * colsB + j] = 2.0 * (i - j);


    auto start = std::chrono::high_resolution_clock::now();

    //ijk order (row major?)
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsB; ++j)
            for (int k = 0; k < colsA; ++k)
                C[i * colsB + j] += A[i * colsA + k] * B[k * colsB + j];
    auto end = std::chrono::high_resolution_clock::now(); //calculation completed

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);


    if(rowsA < 10) //we dont want 1000x1000 matrices being printed
    {
        //printing the new NxN matrix
        for (int i = 0; i < rowsA; i++){
            cout << "\n";
            for (int j = 0 ; j < colsB; j++){
                cout << C[i * colsB + j];
                cout << ", ";
            }
        }
    }
    cout << "\nMatrix multiplication performed in " << duration.count() << " nanoseconds"
    << " or " << duration.count() / 1e9 << " seconds\n";

    auto start2 = std::chrono::high_resolution_clock::now();

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rowsA, colsB, colsA,
            1.0, &A[0], colsA,
                 &B[0], colsB,
            0.0, &C_blas[0], colsB);

    auto end2 = std::chrono::high_resolution_clock::now(); //calculation completed

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);

    cout << "\nMatrix multiplication using openBLAS performed in " << duration2.count() << " nanoseconds"
    << " or " << duration2.count() / 1e9 << " seconds\n";
}
