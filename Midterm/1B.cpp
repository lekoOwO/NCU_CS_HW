#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Matrix : public vector<vector<float>> {
   public:
    Matrix() : vector<vector<float>>(){};
    Matrix(vector<vector<float>> matrix) : vector<vector<float>>(matrix){};
    Matrix(int length, vector<float> element)
        : vector<vector<float>>(length, element){};

    void print(int width = 8) {
        for (int i = 0; i < std::size(*this); i++) {
            for (int j = 0; j < std::size((*this)[i]); j++) {
                std::cout << std::setw(width) << (*this)[i][j];
            }
            cout << endl;
        }
        return;
    }

    Matrix transpose() {
        Matrix newMatrix;
        for (int i = 0; i < std::size((*this)[0]); i++) {
            vector<float> newRow;
            for (int j = 0; j < std::size((*this)); j++) {
                newRow.push_back((*this)[j][i]);
            }
            newMatrix.push_back(newRow);
        }
        return newMatrix;
    }

    Matrix product(Matrix m2) {
        if (std::size((*this)[0]) != std::size(m2))
            return Matrix();
        else {
            int sizeOfMatrix = std::size(*this);
            Matrix result(sizeOfMatrix, vector<float>(sizeOfMatrix, 0));
            for (int i = 0; i < sizeOfMatrix; i++) {
                for (int j = 0; j < sizeOfMatrix; j++) {
                    auto v1 = (*this)[i];
                    vector<float> v2(std::size(v1), 0);
                    transform(m2.begin(), m2.end(), v2.begin(),
                              [j](auto k) { return k[j]; });
                    result[i][j] =
                        inner_product(v1.begin(), v1.end(), v2.begin(), 0);
                }
            }
            return result;
        }
    }
};

class splitstring : public string {
    /*
        Splits string.
        The reason of using this except of cin is to react to the situation of
            undesigned length.
        @param  <char> delim The char to split the string.
        @param  <int>  rep The counts of the split.
            Keep as default to split as much as possible.
        @return <vector<string>>
        Usage: auto a = (string)"Hello how are you?".split(' ');
    */
    vector<string> flds;

   public:
    template<class T>
    splitstring(T s) : string(s){};
    vector<string>& split(char delim, int rep = 0) {
        if (!flds.empty()) flds.clear();
        string work = data();
        string buf  = "";
        int i       = 0;
        while (i < work.length()) {
            if (work[i] != delim)
                buf += work[i];
            else if (rep == 1) {
                flds.push_back(buf);
                buf = "";
            } else if (buf.length() > 0) {
                flds.push_back(buf);
                buf = "";
            }
            i++;
        }
        if (!buf.empty()) flds.push_back(buf);
        return flds;
    }
};

Matrix createMatrix(string word = "") {
    /*
        Create a matrix by user input.
        @param  <string> word The word to show before a user input the matrix.
        @param  <int> height The height of the matrix. Keep it as default to
            create a square matrix.
        @return <Matrix>
    */
    auto input = [](string word = "", string input = "") {
        if (word != "") cout << word << endl;
        if (input == (string) "") getline(cin, input);
        string empty = "";
        if (input == empty)
            return vector<float>{-INFINITY};
        splitstring s(input);
        auto x = s.split(' ');
        vector<float> result(size(x));
        transform(x.begin(), x.end(), result.begin(),
                  [](auto i) { return stof(i); });
        return result;
    };

    cout << word << endl << endl;
    Matrix matrix;
    auto in = input();
    while( !(in == vector<float>{-INFINITY})) {
        matrix.push_back(in);
        in = input();
    }
    return matrix;
}

int main(void){
    Matrix matrixA = createMatrix(
        "Please enter matrix A.\nSeperate each numbers with a space and each "
        "line with ENTER.");
    Matrix matrixB = createMatrix(
        "Please enter matrix A.\nSeperate each numbers with a space and each "
        "line with ENTER.");
    matrixA.product(matrixB).print();
    return 0;
}

