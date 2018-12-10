#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class splitstring : public string {
    /*
        Splits string.
        The reason of using this except of cin is to react to the situation of
            undesigned length.
        @param  <char> delim The char to split the string.
        @param  <int>  rep The counts of the split.
            Keep as default to split as much as possible.
        @return <vector<string>>
        Usage: auto a = (splitstring)"Hello how are you?".split(' ');
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

// switch for string
typedef std::uint64_t hash_t;  
   
constexpr hash_t prime = 0x100000001B3ull;  
constexpr hash_t basis = 0xCBF29CE484222325ull;  
  
hash_t hash_(char const* str)  
{  
    hash_t ret{basis};  
   
    while(*str){  
        ret ^= *str;  
        ret *= prime;  
        str++;  
    }  
   
    return ret;  
}  

constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)  
{  
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;  
} 

constexpr unsigned long long operator "" _hash(char const* p, size_t)  
{  
    return hash_compile_time(p);  
}  


class Calculator {
    public:
      void operator=(float initValue) {this->data = initValue;}
      void operator+=(float x) {this->data += x;}
      void operator*=(float x) {this->data *= x;}
      void operator-=(float x) {this->data -= x;}
      void operator/=(float x) {this->data /= x;}
      friend ostream& operator<<(ostream& os, const Calculator& x){  
            os << x.data;  
            return os;  
      }  
  
    private:
      float data;
};

int main(){
    string input;
    getline(cin, input);
    auto parsed = splitstring(input).split('>');
    Calculator x;
    regex push = regex(R"((?:<)(\S+)(?:\s*)(.*))");

    for (auto e: parsed) {
        smatch sm;
        regex_match (e, sm, push);
        switch (hash_(&sm[1].str()[0u])){
            case "init"_hash:
                x = (stof(sm[2].str()));
                break;
            case "add"_hash:
                x += (stof(sm[2].str()));
                break;
            case "multiply"_hash:
                x *= (stof(sm[2].str()));
                break;
            case "subtract"_hash:
                x -= (stof(sm[2].str()));
                break;
            case "divide"_hash:
                x /= (stof(sm[2].str()));
                break;
            case "display"_hash:
                cout << x << endl;
                break;
            default:
                cout << "Error: " << sm[0].str() << '>' << endl;
                break;
        }
    }
    return 0;
}