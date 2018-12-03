#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

struct Fibonacci {
   public:
    Fibonacci(int num) { this->add(num - 1); }
    int add(int num = 1) {
        for (int i = 0; i < num; i++)
            this->fib.push_back(this->fib.end()[-1] + this->fib.end()[-2]);
        return this->fib.back();
    }
    int sum(int index = -1) {
        if (index < 0)
            return std::accumulate(this->fib.begin(), this->fib.end(), 0);
        else if (this->fib.size() < index)
            add(index - this->fib.size());
        return std::accumulate(this->fib.begin(), this->fib.begin() + index + 1,
                               0);
    }
    std::vector<int> getFib() { return this->fib; }

   private:
    std::vector<int> fib = {0, 1};
};

template<typename InputIt>
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

int main() {
    int num;
    std::cout << "Please input an integer n where n is the footstep of a fib "
                 "sequence: ";
    std::cin >> num;
    Fibonacci fib(num);
    auto      fibSeq = fib.getFib();
    std::cout << "The Fibonacci sequence is: "
              << join(fibSeq.begin(), fibSeq.end()) << std::endl;
    std::cout << "The sum of this sequence is " << fib.sum();

    return 0;
}
