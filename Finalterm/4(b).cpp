#include <iostream>
#include <string>

class guessNumber{
    public:
        guessNumber(std::string ans){
            answer = ans;
        }

        bool guess(std::string guess){
            if (guess == "exit") {
                return true;
            }

            int A = 0, B = 0;
            for (int i = 0; i < std::size(answer); i++ ) {
                if (guess[i] == answer[i]) A++;
                else if (answer.find(guess[i]) != std::string::npos)
                    B++;
            }

            std::cout << A << "A" << B << "B\n";
            return A == std::size(answer);
        }
      
    private:
      std::string answer;
};

int main(){
    std::string answer;
    std::cout << "Enter the correct answer: ";
    std::cin >> answer;
    guessNumber game(answer);

    bool bye = false;
    while (!bye) {
        std::string guess;
        std::cin >> guess;

        bye = game.guess(guess);
    }
    return 0;
}