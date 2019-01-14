#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MultiplyGradeSchoolAlgorithm(int x, int y)
{
    vector<int> yDigits;
    CollectDigits(yDigits, y);
    int place = 1;

    while (!yDigits.empty)
    {
        //do stuff - have a meeting to get to.
    }
}

void CollectDigits(vector<int>& digits, long long num) {
    if (num > 9) {
        CollectDigits(digits, num / 10);
    }
    digits.push_back(num % 10);
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
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Base C++ multiplication took "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";

    return 0;
}