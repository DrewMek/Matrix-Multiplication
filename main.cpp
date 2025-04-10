#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
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

    vector<vector<double>> A(rowsA, vector<double>(colsA));
    vector<vector<double>> B(rowsB, vector<double>(colsB));
    vector<vector<double>> C(rowsA, vector<double>(colsB, 0.0));

    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsA; ++j)
            A[i][j] = rand() % 1001;

    for (int i = 0; i < rowsB; ++i)
        for (int j = 0; j < colsB; ++j)
            B[i][j] = 2.0 * (i - j);


    auto start = std::chrono::steady_clock::now();

    //ijk order (row major?)
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsB; ++j)
            for (int k = 0; k < colsA; ++k)
                C[i][j] += A[i][k] * B[k][j];
    auto end = std::chrono::steady_clock::now(); //calculation completed

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);


    if(rowsA < 10) //we dont want 1000x1000 matrices being printed
    {
        //printing the new NxN matrix
        for (int i = 0; i < rowsA; i++){
            cout << "\n";
            for (int j = 0 ; j < colsB; j++){
                cout << C[i][j];
                cout << ", ";
            }
        }
    }
    cout << "\nMatrix multiplication performed in " << duration.count() << " nanoseconds"
    << " or " << duration.count() / 1e9 << " seconds\n";

    /** double matrixOneB[3][2] = {
        {8, 5},
        {5, 1},
        {15, 4}
    };

    double matrixTwoB[2][3] = {
        {6, 20, 4},
        {88, 41, 29},
    };

    cout << "\nMatrix One (3x2):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrixOneB[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMatrix Two (2x3):\n";
    for (int i = 0; i < 2; i++) {  // Loop through rows
        for (int j = 0; j < 3; j++) {  // Loop through columns
            cout << matrixTwoB[i][j] << " ";
        }
        cout << "\n";
    }


    double matrixThreeB[3][3];
    auto start2 = std::chrono::steady_clock::now();
    //kij order
    for (int k = 0; k < M; k++){ //iterates through the shared dimension k

        for (int i = 0; i < N; i++){ //iterates through the rows
            for(int j = 0; j < N; j++){ //column iterator
                matrixThreeB[i][j] += (matrixOneB[i][k] * matrixTwoB[k][j]); //dot product!
            }
        }
    }

    auto end2 = std::chrono::steady_clock::now(); //calculation completed
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    cout << "\nMultiplied:";
    for (int i = 0; i < N; i++){
        cout << "\n";
        for (int j = 0 ; j < N; j++){
            cout << matrixThreeB[i][j];
            cout << ", ";
        }
    }
    cout << "\nMatrix multiplication performed in " << duration2.count() << " nanoseconds";
    **/
}
