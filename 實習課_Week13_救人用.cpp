#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

const int STUDENT_NUM = 5;
const int SUBJECT_NUM = 3;

const std::string STUDENT_NAMES[] = {"Tom", "Roger", "Jon", "Frank", "Alexandra"};
const int SCORES[STUDENT_NUM][SUBJECT_NUM] = {{90,80,95}, {85,72,80}, {90,75,85}, {70,88,75}, {95,85,80}};
const std::string SUBJECTS[] = {"Microelectronics", "Electromagnetics", "Electrical Circuits"};

class Student {
    public:
      Student(const std::string name, const int scores[SUBJECT_NUM]) {
          this->name = name;
          this->scores = scores;
      }
      Student(){}

      const int* getScores(){
          return this->scores;
      }

      float getAverage(){
          float acc = 0;
          for (int i = 0; i < SUBJECT_NUM; i++) {
              acc += scores[i];
          }
          return acc / SUBJECT_NUM;
      }

      std::string getName(){
          return this->name;
      }

      void print(){
          std::cout << name << "'s Scores-\n";
          for (int i = 0; i < SUBJECT_NUM; i++){
              std::cout << "\t" << SUBJECTS[i] << ": " << scores[i] << "\n";
          }
          std::cout << "\t--The average score of " << name << " is " << getAverage() << "\n" << std::endl;
      }

    private:
      const int* scores;
      std::string name;
};

class Students {
    public:
      Students(Student student){
          push(student);
      }
      Students(){}

      void push(Student& student){
          if (studentCount < STUDENT_NUM) {
              students[studentCount] = student;
              studentCount++;
          }
      }

      Student* search(std::string name) {
          for (int i = 0; i < STUDENT_NUM; i++) {
              if (students[i].getName() == name)
                  return students + i;
          }
          return nullptr;
      }

    private:
      int studentCount = 0;
      Student students[STUDENT_NUM];
};

int main(){
    Students students;
    for (int i = 0; i < STUDENT_NUM; i++) {
        Student* tmp = new Student(STUDENT_NAMES[i], SCORES[i]);
        students.push(*tmp);
    }

    std::string input;
    std::cout << "Search student (Ctrl-Z to stop): ";
    while (getline(std::cin, input) && input != "exit") {
        Student* result = students.search(input);
        if (result == nullptr) {
            std::cout << "Student \"" << input << "\" Not found.\n\n";
        } else {
            result->print();
        }
        std::cout << "Search student (Ctrl-Z to stop): ";
    }
    return 0;
}