#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

const std::vector<std::string> STUDENT_NAMES = {"Tom", "Roger", "Jon", "Frank", "Alexandra"};
const std::vector<std::vector<int>> SCORES = {{90,80,95}, {85,72,80}, {90,75,85}, {70,88,75}, {95,85,80}};
const std::vector<std::string> SUBJECTS = {"Microelectronics", "Electromagnetics", "Electrical Circuits"};

class Student {
    public:
      Student(const std::string name, const std::vector<int> scores) {
          this->name = name;
          this->scores.insert( this->scores.end(), scores.begin(), scores.end() );
      }
      std::vector<int> getScores(){
          return this->scores;
      }

      float getAverage(){
          return std::accumulate( scores.begin(), scores.end(), 0.0) / scores.size(); 
      }

      std::string getName(){
          return this->name;
      }

      void print(){
          std::cout << name << "'s Scores-\n";
          for (int i = 0; i < SUBJECTS.size(); i++){
              std::cout << "\t" << SUBJECTS[i] << ": " << scores[i] << "\n";
          }
          std::cout << "\t--The average score of " << name << " is " << getAverage() << "\n" << std::endl;
      }

    private:
      std::vector<int> scores;
      std::string name;
};

class Students {
    public:
      Students(std::vector<Student> students){
          batchPush(students);
      }
      Students(Student student){
          push(student);
      }
      Students(){}

      void push(Student student){
          students.push_back(student);
      }

      void batchPush(std::vector<Student> students){
          students.insert( students.end(), students.begin(), students.end() );
      }

      std::vector<Student> search(std::string name) {
          std::vector<Student> result;
          std::copy_if(students.begin(), students.end(), std::back_inserter(result), [name](Student i){return i.getName() == name;} );
          return result;
      }

    private:
      std::vector<Student> students;
};

int main(){
    Students students;
    for (int i = 0; i < STUDENT_NAMES.size(); i++) {
        students.push(Student(STUDENT_NAMES[i], SCORES[i]));
    }

    std::string input;
    std::cout << "Search student (Ctrl-Z to stop): ";
    while (getline(std::cin, input)) {
        auto results = students.search(input);
        switch (results.size()) {
            case 0:
                std::cout << "Student \"" << input << "\" Not found.\n\n";
                break;
            case 1:
                results[0].print();
                break;
            default:
                std::cout << "Found More than a result!\n" << std::endl;
                break;
        }
        std::cout << "Search student (Ctrl-Z to stop): ";
    }
    return 0;
}