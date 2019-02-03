#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

template<typename InputIt>
std::string join(InputIt            begin,
                 InputIt            end,
                 const std::string& separator = ", ",
                 const std::string& concluder = "") {
    std::ostringstream ss;

    using value_type = typename std::iterator_traits<InputIt>::value_type;

    std::copy(begin, end - 1,
         std::ostream_iterator<value_type>(ss, separator.c_str()));

    ss << *(end - 1) << concluder;
    return ss.str();
}

std::vector<float> f1(float x0, float ratio, int nums){
    std::vector<float> result;
    for (; nums; nums--) {
        result.push_back(std::pow(ratio, size(result)) * x0);
    }
    return result;
}


int main(int argc, char* argv[]){
    float x0 = std::stof(argv[1]);
    float ratio = std::stof(argv[2]);
    int nums = std::stoi(argv[3]);

    auto result = f1(x0, ratio, nums);

    std::cout << "<" << join(std::begin(result), std::end(result), ", ", ">");
    return 0;
}