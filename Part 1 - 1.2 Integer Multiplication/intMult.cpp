#include <chrono>
#include <iostream>
#include "intMult.h"

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
    long long result = x * y;
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Base C++ multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return " << result << "\n";

    t1 = chrono::high_resolution_clock::now();
    result = MultiplyGradeSchoolAlgorithm(x, y);
    t2 = chrono::high_resolution_clock::now();
    cout << "Grade School multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return " << result << "\n";

    t1 = chrono::high_resolution_clock::now();
    result = RecursiveAlgorithm(x, y);
    t2 = chrono::high_resolution_clock::now();
    cout << "Recursive multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return " << result << "\n";

    t1 = chrono::high_resolution_clock::now();
    result = KaratsubaAlgorithm(x, y);
    t2 = chrono::high_resolution_clock::now();
    cout << "Karatsuba multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return " << result << "\n";

    return 0;
}

void CollectDigits(vector<int>& digits, int num) {
    if (num > 9) {
        CollectDigits(digits, num / 10);
    }
    digits.push_back(num % 10);
}

long MultiplyGradeSchoolAlgorithm(int x, int y) {
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
            retVal += x * yCurr;
        }
        place++;
    }

    return retVal;
}

long RecursiveAlgorithm(int x, int y) {
    long long retVal = 0;

    // First if statements is our base case.
    // We are going to define our base C++
    // multiplication as when either x or y reaches
    // a single-digit length.
    if (x <= 9 || y <= 9) {
        return x * y;
    }

    return retVal;
}

long KaratsubaAlgorithm(int x, int y) {
    long long retVal = 0;

    return retVal;
}
