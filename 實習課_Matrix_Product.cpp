#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Matrix : public vector<vector<int>> {
   public:
    Matrix() : vector<vector<int>>(){};
    Matrix(vector<vector<int>> matrix) : vector<vector<int>>(matrix){};
    Matrix(int length, vector<int> element)
        : vector<vector<int>>(length, element){};

    void print(int width = 4) {
        for (int i = 0; i < std::size(*this); i++) {
            for (int j = 0; j < std::size((*this)[i]); j++) {
                std::cout << std::setw(width) << (*this)[i][j];
            }
            cout << endl;
        }
        return;
    }

    Matrix cof() {
        /*
            Returns a matrix of cofactors.
            @return <Matrix>
        */
        Matrix result(std::size(*this), vector<int>{});
        switch (std::size(*this)) {
            case 3:
                vector<int> indexes = {0, 1, 2};
                for (int i = 0; i < std::size(*this); i++) {
                    vector<int> firstStageIndexes;
                    std::copy_if(indexes.begin(), indexes.end(),
                                 std::back_inserter(firstStageIndexes),
                                 [i](int k) { return k != i; });
                    for (int j = 0; j < std::size(*this); j++) {
                        vector<int> secondStageIndexes;
                        std::copy_if(indexes.begin(), indexes.end(),
                                     std::back_inserter(secondStageIndexes),
                                     [j](int k) { return k != j; });
                        int elem = (*this)[firstStageIndexes[0]]
                                          [secondStageIndexes[0]] *
                                       (*this)[firstStageIndexes[1]]
                                              [secondStageIndexes[1]] -
                                   (*this)[firstStageIndexes[1]]
                                          [secondStageIndexes[0]] *
                                       (*this)[firstStageIndexes[0]]
                                              [secondStageIndexes[1]];
                        elem *= pow(-1, i + j);  // 正負號
                        result[i].push_back(elem);
                    }
                }
                break;
        }
        return result;
    }

    int det() {
        /*
            Returns the determinant of a matrix.
            @return <int>
        */
        switch (std::size(*this)) {
            case 2:
                return (*this)[0][0] * (*this)[1][1] -
                       (*this)[0][1] * (*this)[1][0];
            case 3:
                Matrix result = (*this).cof();
                return (*this)[0][0] * result[0][0] +
                       (*this)[0][1] * result[0][1] +
                       (*this)[0][2] * result[0][2];
        }
        return 0;
    }

    Matrix product(Matrix m2) {
        if (std::size((*this)[0]) != std::size(m2))
            return Matrix();
        else {
            int sizeOfMatrix = std::size(*this);
            Matrix result(sizeOfMatrix, vector<int>(sizeOfMatrix, 0));
            for (int i = 0; i < sizeOfMatrix; i++) {
                for (int j = 0; j < sizeOfMatrix; j++) {
                    vector<int> v1 = (*this)[i];
                    vector<int> v2(std::size(v1), 0);
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

Matrix createMatrix(string word = "", int height = -1) {
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
        splitstring s(input);
        auto x = s.split(' ');
        vector<int> result(size(x));
        transform(x.begin(), x.end(), result.begin(),
                  [](auto i) { return stoi(i); });
        return result;
    };

    cout << word << endl << endl;
    Matrix matrix;
    matrix.push_back(input());
    if (height == -1) height = size(matrix[0]);
    for (int i = 0; i < height - 1; i++) { matrix.push_back(input()); }
    return matrix;
}

int main(void) {
    auto m1 =
        createMatrix("Please input the first matrix whose height == 3.", 3);
    auto m2 =
        createMatrix("\nPlease input the first matrix whose height == 2.", 2);
    auto result = m1.product(m2);
    cout << endl << "The matrix product: " << endl << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << setw(4) << result[i][j];
        }
        cout << endl;
    }
    return 0;
}