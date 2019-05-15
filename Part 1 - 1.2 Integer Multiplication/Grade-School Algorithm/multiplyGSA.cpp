#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CollectDigits(vector<int>& digits, long long num) {
    if (num > 9) {
        CollectDigits(digits, num / 10);
    }
    digits.push_back(num % 10);
}

int MultiplyGradeSchoolAlgorithm(int x, int y)
{
    vector<int> yDigits;
    CollectDigits(yDigits, y);
    int place = 0;
    long long yCurr;
    long long retVal = 0;

    while (!yDigits.empty())
    {
        yCurr = yDigits.back();
        yDigits.pop_back();
        if (place > 0)
        {
            retVal += x * yCurr * (pow(10, place));
        }
        else
        {
            retVal += x & yCurr;
        }
    }

    return retVal;
}

int main(int argc, char *argv[]) {
    int x, y;
    if (argc >= 3)
    {
        x = stoi(argv[1]);
        y = stoi(argv[2]);
    }
    else
    {
        cout << "Too few parameters were input. Please input two integer values.\n";
        return 1;
    }

    auto t1 = chrono::high_resolution_clock::now();
    int result = x * y;
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Base C++ multiplication took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds to return " << result << "\n";

    t1 = chrono::high_resolution_clock::now();
    result = MultiplyGradeSchoolAlgorithm(x, y);
    t2 = chrono::high_resolution_clock::now();
    cout << "Grade School multiplication took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds to return " << result << "\n";

    return 0;
}