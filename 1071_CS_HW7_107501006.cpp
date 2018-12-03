#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <sstream>
#include <iterator>

using namespace std;

class splitstring : public string {
    /*
        Splits string.
        The reason of using this except of cin is to react to the situation of
            undesignated length.
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

template<typename InputIt>
/*
    Joining a iteratable with a specific string.
*/
std::string join(InputIt            begin,
                 InputIt            end,
                 const std::string& separator = ", ",
                 const std::string& concluder = "") {
    std::ostringstream ss;

    using value_type = typename std::iterator_traits<InputIt>::value_type;

    copy(begin, end - 1,
         std::ostream_iterator<value_type>(ss, separator.c_str()));

    ss << *(end - 1) << concluder;
    return ss.str();
}

vector<float> input(string word = "", string input = "") {
    /*
        Get input and split into a float vector.
    */
        if (word != "") cout << word << endl;
        if (input == (string) "") getline(cin, input);
        splitstring s(input);
        auto x = s.split(' ');
        vector<float> result(size(x));
        transform(x.begin(), x.end(), result.begin(),
                  [](auto i) { return stof(i); });
        return result;
    };

template<class T>
    void swap(T* x, T* y) {
        T tmp = *y;
        *y = *x;
        *x = tmp;
    }

template<class T>
/*
    Bubble sort.
*/
    void bSort(T *array, size_t length, function<bool(T, T)> f) {
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1; j++) {
                T *x = array + j;
                T *y = x + 1;
                if (f(*x, *y))
                    swap(x, y);
            }
        }
    }

int main(){
    cout << "Please insert and seperate each numbers with a space to sort: ";
    auto array = input();

    bSort<float>(array.data(), size(array), [](auto a, auto b) {return a > b;});
    cout << "Array in ascending order: " << join(array.begin(), array.end(), " ", "\n");

    bSort <float> (array.data(), size(array), [](auto a, auto b) { return a < b; });
    cout << "Array in descending order: " << join(array.begin(), array.end(), " ", "\n");

    return 0;
}