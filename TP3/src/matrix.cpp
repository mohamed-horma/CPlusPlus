#include <iostream>
#include <stdexcept> // for std::out_of_range
#include "matrix.h"
#include <cstring> // for std::memcpy


using namespace std;

//default constructor
Matrix::Matrix() : _n(0), _m(0), _array(nullptr) {
    #ifdef DBUG_ON
    cout << "+++Matrix()" << endl;
    cout << "Address of current object: " << this << endl;
    #endif

}


Matrix::Matrix(int n, int m): _n(n), _m(m) {
    #ifdef DBUG_ON
    cout << "+++Matrix(n,m)" << endl;
    cout << "Address of current object: " << this << endl;
    #endif
    
    _array = new double[_n*_m];
    
}

// --- Destructeur ---
Matrix::~Matrix() {
    
    delete [] _array;
    _array = nullptr;
}


double* Matrix::operator[](int i) {
    if (i < 0 || i >= _n) {
        throw std::out_of_range("Matrix::operator[]: row index out of range");
    }
    return _array + i*_m;
}
// --- Constructeur par copie ---
Matrix::Matrix(const Matrix& other): _n(other._n), _m(other._m){
    #ifdef DBUG_ON
    cout << "rrrMatrix(n,m)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &other << endl;
    #endif
    _array = new double[_n*_m];

    std::memcpy(_array, other._array, _n * _m * sizeof(double));
    
}
// --- Opérateur d'affectation par copie ---
Matrix& Matrix::operator = (const Matrix& M){
    #ifdef DBUG_ON
    cout << "op=Matrix(n,m)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &M << endl;
    #endif 

    if (this == &M){
        return *this;
    }

    delete [] _array;
    _array = nullptr;
    _n = M._n;
    _m = M._m;
    _array = new double[_n*_m];
    std::memcpy(_array, M._array, _n * _m * sizeof(double));

    return *this;
}

// --- Constructeur par déplacement ---
Matrix::Matrix(Matrix&& tmp): _n(tmp._n), _m(tmp._m), _array(tmp._array) {
    #ifdef DBUG_ON
    cout << "dddMatrix(n,m)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &tmp << endl;
    #endif
    tmp._array = nullptr;
    tmp._n = 0;
    tmp._m = 0;
}

// --- Opérateur d'affectation par déplacement ---
Matrix& Matrix::operator = (Matrix&& M){
    #ifdef DBUG_ON
    cout << "opd=Matrix(n,m)" << endl;
    cout << "Address of current object: " << this << endl;
    cout << "Address of parameter object: " << &M << endl;
    #endif

    if (this!=&M){
        delete [] _array;
        _array = M._array;
        _n = M._n;
        _m = M._m;

        M._array = nullptr;
        M._n = 0;
        M._m = 0;
    }
    return *this;
}

//
double Matrix::get(int i, int j) const {
    if (i < 0 || i >= _n || j < 0 || j >= _m)
        throw std::out_of_range("Matrix::get: index out of range");
    return _array[i*_m + j];
}

void Matrix::set(int i, int j, double value) {
    if (i < 0 || i >= _n || j < 0 || j >= _m)
        throw std::out_of_range("Matrix::set: index out of range");
    _array[i*_m + j] = value;
}


Matrix operatorPlus(const Matrix& A, const Matrix& B) {
    if (A._n != B._n || A._m != B._m) {
        throw std::invalid_argument("Matrix::operator+: matrices must have the same dimensions");
    }
    Matrix C(A._n, A._m);
    for (int i = 0; i < A._n * B._m; i++) {
        for (int j = 0; j < A._m; j++) {
            C._array[i] = A._array[i] + B._array[i];
        }
    }
    return C;
}

Matrix operatorMult(const Matrix& A, const Matrix& B) {
    if (A._m != B._n) {
        throw std::invalid_argument("Matrix::operator*: incompatible matrix dimensions");
    }
    Matrix C(A._n, B._m);
    for (int i = 0; i < A._n; i++) {
        for (int j = 0; j < B._m; j++) {
            double sum=0;
            for (int k = 0; k < A._m; k++ ) {
                sum += A._array[i*A._m + k] * B._array[k*B._m + j];
            }
            C._array[i*C._m + j] = sum;
        }
    }
    return C;
}

Matrix operatorMinus(const Matrix& A, const Matrix& B) {
    if (A._n != B._n || A._m != B._m)
        throw std::invalid_argument("Matrix sizes must match for subtraction");

    Matrix result(A._n, A._m);
    for (int i = 0; i < A._n*B._m; i++){
        result._array[i] = A._array[i] - B._array[i];
    }
        

    return result;
}

Matrix Matrix::operatorMinusUnaire() const {
    Matrix result(_n, _m);
    for (int i = 0; i < _n*_m; i++)
            result._array[i] = -_array[i];
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& M) {
    os << "[ ";
    for (int i = 0; i < M._n; i++) {
        os << "[ ";
        for (int j = 0; j < M._m; j++) {
            os << M._array[i * M._m + j];
            if (j < M._m - 1) os << ", ";
        }
        os << " ]";
        if (i < M._n - 1) os << ", ";
    }
    os << " ]";
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& M) {
    for (int i = 0; i < M._n * M._m; ++i)
        is >> M._array[i];
    return is;
}

bool Matrix::isSquare() const {
    return _n == _m;
}


Matrix Matrix::transpose() const {
    if (_n == 0 || _m == 0)
        throw "Transpose error: empty matrix.";

    Matrix T(_m, _n);
    for (int i = 0; i < _n; ++i)
        for (int j = 0; j < _m; ++j)
            T._array[j*_n + i] = _array[i*_m + j];

    return T;
}

Matrix Matrix::identity(int n) {
    if (n <= 0)
        throw "Identity error: size must be positive.";

    Matrix I(n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            I._array[i*n + i] =1.0;

    return I;
}











