/**
    1071_CS_HW2_107501006.cpp

    @author Rex Tseng
    @version 1.3 03/10/2018
*/

#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

using namespace std;

const int MONTH_DAYS_[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const vector<int> MONTH_DAYS(MONTH_DAYS_, MONTH_DAYS_ + size(MONTH_DAYS_));

const string DAY_TO_CHINESE_[] = {"日", "一", "二", "三", "四", "五", "六"};
const vector<string> DAY_TO_CHINESE(DAY_TO_CHINESE_,
                                    DAY_TO_CHINESE_ + size(DAY_TO_CHINESE_));

const int INITDAY = 1;  // 1/1 是星期一

struct Date {
   public:
    int month;
    int day;
    Date(int month, int day) {
        this->month = month;
        this->day   = day;
    }
    bool isValid() {
        /*
            Check if the Date is valid.
            @return <bool>
        */
        if (!(this->month && this->day)) {
            return false;
        } else if (this->month < 1 || this->month > 12 || this->day < 1) {
            return false;
        } else if (this->day > MONTH_DAYS[this->month - 1]) {
            return false;
        } else {
            return true;
        }
    };

    int getDay() {
        /*
            Return the day of the input days count.
            @return <int>
                Sunday: 0
                Monday: 1
                ...
                Saturday: 6
        */
        return (this->getDays() + INITDAY - 1) % 7;
    };

   private:
    int getDays() {
        /*
            Counts days from Jan 1st to the specific date.
            @return <int> the count
        */
        return accumulate(MONTH_DAYS.begin(),
                          MONTH_DAYS.begin() + this->month - 1, 0) +
               this->day;
    };
};

int main(void) {
    string input;
    smatch sm;
    cout << "請輸入日期 (例如: 5/20): ";
    getline(cin, input);
    if (regex_match(input, sm,
                    regex("(?:.*?)(\\d{1,2})(?:.*)/(?:.*?)(\\d{1,2})(?:.*)"))) {
        Date date(stoi(sm[1]), stoi(sm[2]));
        if (!date.isValid()) {
            cout << "日期錯誤！" << endl;
            return 87;
        }
        cout << date.month << " 月 " << date.day << " 日是星期"
             << DAY_TO_CHINESE[date.getDay()] << endl;
        return 0;
    } else {
        cout << "輸入錯誤！" << endl;
        return 87;
    }
}
