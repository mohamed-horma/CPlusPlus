#include <iostream>
#include <stdexcept>
#include "matrix.h"

using namespace std;

int main() {
    try {
        cout << "*******************************************************************" << endl;
        cout << "******************** Test default constructor ********************" << endl;
        cout << "*******************************************************************" << endl;
        Matrix M1;
        cout << "M1 = " << M1 << endl;

        cout << "\n*******************************************************************" << endl; 
        cout << "******************** Test constructor with arguments ********************" << endl;
        cout << "*******************************************************************" << endl;
        Matrix M2(2, 2);
        Matrix M3(2, 2);
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                M2[i][j] = i + j;
                M3[i][j] = 2 * j;
            }
        }

        cout << "M2 = " << M2 << endl;
        cout << "M3 = " << M3 << endl;

        cout << "\n******************** Test copy constructor ********************" << endl;
        Matrix M4(M3);
        cout << "M4 (copied from M3) = " << M4 << endl;

        cout << "\n******************** Test assignment operator (=) ********************" << endl;
        Matrix M5;
        M5 = M2;
        cout << "M5 = M2 -> " << M5 << endl;

        cout << "\n******************** Test move constructor ********************" << endl;
        Matrix M6(move(M5));
        cout << "M6 (moved from M5) = " << M6 << endl;

        cout << "\n******************** Test get() and set() ********************" << endl;
        cout << "Element (1,1) in M2: " << M2.get(1,1) << endl;
        M2.set(1,1,99.9);
        cout << "After set(1,1,99.9): " << M2 << endl;

        cout << "\n******************** Test operator +, -, * ********************" << endl;
        Matrix M8 = operatorPlus(M2, M3);
        cout << "M2 + M3 = " << M8 << endl;

        Matrix M9 = operatorMinus(M2, M3);
        cout << "M2 - M3 = " << M9 << endl;

        cout << "Create two matrices for multiplication..." << endl;
        Matrix A(2,3), B(3,2);
        for (int i=0;i<2;i++)
            for (int j=0;j<3;j++)
                A[i][j] = i + j + 1;

        for (int i=0;i<3;i++)
            for (int j=0;j<2;j++)
                B[i][j] = (i==j)?2:1;

        cout << "A = " << A << endl;
        cout << "B = " << B << endl;
        Matrix C = operatorMult(A,B);
        cout << "A * B = " << C << endl;

        cout << "\n******************** Test unary minus ********************" << endl;
        Matrix M10 = M2.operatorMinusUnaire();
        cout << "-M2 = " << M10 << endl;

        cout << "\n******************** Test isSquare() ********************" << endl;
        cout << "M2 is square? " << (M2.isSquare() ? "Yes" : "No") << endl;
        Matrix M11(2,3);
        cout << "Rect(2x3) is square? " << (M11.isSquare() ? "Yes" : "No") << endl;

        cout << "\n******************** Test transpose() ********************" << endl;
        Matrix T = C.transpose();
        cout << "Transpose of (A*B) = " << T << endl;

        cout << "\n******************** Test identity() ********************" << endl;
        Matrix I = Matrix::identity(3);
        cout << "3x3 Identity matrix = " << I << endl;

        cout << "\n******************** Test input operator >> ********************" << endl;
        Matrix M12(2,2);
        cout << "Enter 4 values for a 2x2 matrix (row by row): ";
        cin >> M12;
        cout << "You entered: " << M12 << endl;

    } catch (const char* msg) {
        cerr << "Caught exception (const char*): " << msg << endl;
    } catch (const std::exception& e) {
        cerr << "Caught std::exception: " << e.what() << endl;
    }

    cout << "\n******************** End of tests ********************" << endl;
    return 0;
}
