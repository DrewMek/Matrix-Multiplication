#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

/* Dot Product is used in multiplying two matrices as long as the number of columns
 * is equal to the number of rows, this can be expressed as  (M*N), and (N*P), representing
 * each matrix.  We can set the range of for loops by using N, applying this rule ^
 */

int main(){
    cout << "Multiplying Two Matrices\n___________________________";

    double matrixOne[3][2] = {
        {4, 3},
        {9, 5},
        {11, 1}
    };

    double matrixTwo[2][3] = {
        {9, 12, 8},
        {6, 5, 4},
    };

    cout << "\nMatrix One (3x2):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrixOne[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nMatrix Two (2x3):\n";
    for (int i = 0; i < 2; i++) {  // Loop through rows
        for (int j = 0; j < 3; j++) {  // Loop through columns
            cout << matrixTwo[i][j] << " ";
        }
        cout << "\n";
    }

    double matrixThree[3][3];

    auto start = std::chrono::steady_clock::now();

    int N = 3; //size of our new matrixThree
    int M = 2; //amount of rows in M1, and the columns in M2;

    //ijk order (row major?)
        for (int i = 0; i < N; i++){ //iterates through rows

            for (int j = 0; j < N; j++){ //columns
                matrixThree[i][j] = 0; //required so we don't reuse the last loop's calculation

                for(int k = 0; k < M; k++){ //iterates through shared size 'n'
                    matrixThree[i][j] += (matrixOne[i][k] * matrixTwo[k][j]); //dot product!
                }
            }
        }
    auto end = std::chrono::steady_clock::now(); //calculation completed

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    //printing the new NxN matrix
    for (int i = 0; i < N; i++){
        cout << "\n";
        for (int j = 0 ; j < N; j++){
            cout << matrixThree[i][j];
            cout << ", ";
        }
    }

    cout << "\nMatrix multiplication performed in " << duration.count() << " nanoseconds\n";


    double matrixOneB[3][2] = {
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
}
