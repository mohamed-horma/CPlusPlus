#ifndef M_H
#define M_H

#define DBUG_ON

class Matrix{
    
    private:
        int _n,_m;
        double* _array;
    
    public:
        Matrix();

        Matrix(int n, int m);

        ~Matrix();

        
        //Matrix()
        
        //Constructor of copy
        Matrix(const Matrix& other);
        
        //Affectation operator
        Matrix& operator = (const Matrix& M);
        
        //Constructor by deplacement
        Matrix(Matrix&& M);
        
        //Affectation operator by deplacement
        Matrix& operator = (Matrix&& M);
        
        double* operator[](int i);

        double get(int i, int j) const;
        void set(int i, int j, double value);

         // --- Opérateurs arithmétiques ---
        friend Matrix operatorPlus(const Matrix& A, const Matrix& B);
        friend Matrix operatorMinus(const Matrix& A, const Matrix& B);
        friend Matrix operatorMult(const Matrix& A, const Matrix& B);
        Matrix operatorMinusUnaire() const;  // unaire


        // --- Flux d’entrée/sortie ---
        friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
        friend std::istream& operator>>(std::istream& is, Matrix& M);

        //Is it a square matrix?
        bool isSquare() const;

        //Transpose of a matrix
        Matrix transpose() const;
        

        //Identity matrix
        static Matrix identity(int n);

        
        
};
    


#endif