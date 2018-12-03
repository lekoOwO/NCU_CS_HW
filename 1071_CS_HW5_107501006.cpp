/**
    1071_CS_HW5_107501006.cpp

    @author Rex Tseng
    @version 1.2 25/10/2018
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
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

    Matrix cof() {
        /*
            Returns a matrix of cofactors.
            @return <Matrix>
        */
        Matrix result(std::size(*this), vector<float>{});
        switch (std::size(*this)) {
            case 3:
                vector<float> indexes = {0, 1, 2};
                for (int i = 0; i < std::size(*this); i++) {
                    vector<float> firstStageIndexes;
                    std::copy_if(indexes.begin(), indexes.end(),
                                 std::back_inserter(firstStageIndexes),
                                 [i](auto k) { return k != i; });
                    for (int j = 0; j < std::size(*this); j++) {
                        vector<float> secondStageIndexes;
                        std::copy_if(indexes.begin(), indexes.end(),
                                     std::back_inserter(secondStageIndexes),
                                     [j](auto k) { return k != j; });
                        auto elem = (*this)[firstStageIndexes[0]]
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

    float det() {
        /*
            Returns the determinant of a matrix.
            @return <float>
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
        vector<float> result(size(x));
        transform(x.begin(), x.end(), result.begin(),
                  [](auto i) { return stof(i); });
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
    Matrix matrix = createMatrix(
        "Please enter an matrix.\nSeperate each numbers with a space and each "
        "line with ENTER.");
    cout << endl << "Matrix of cofactors: " << endl << endl;
    matrix.cof().print();
    cout << endl << "Determinant: " << matrix.det() << endl;
    return 0;
}
