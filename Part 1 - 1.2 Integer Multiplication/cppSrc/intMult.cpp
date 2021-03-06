#include <chrono>
#include "intMult.h"

int main(int argc, char *argv[]) {
    int x, y;
    vector<int> xDigits;
    vector<int> yDigits;
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
    CollectDigits(xDigits, x);
    CollectDigits(yDigits, y);
    result = RecursiveAlgorithm(xDigits, yDigits);
    t2 = chrono::high_resolution_clock::now();
    cout << "Recursive multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return " << result << "\n";

    t1 = chrono::high_resolution_clock::now();
    result = RecursiveAlgorithm(x, y);
    t2 = chrono::high_resolution_clock::now();
    cout << "Recursive multiplication (v2) took "
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

int GetInteger(vector<int> digits) {
    int place = 0;
    int retVal = 0;

    while (digits.size() > 0) {
            retVal += digits.back() * (pow(10, place));
            digits.pop_back();
            place++;
    }

    return retVal;
}

int GetIntegerLength(int num) {
    int retVal = 0;
    while (num > 0) {
        num /= 10;
        retVal++;
    }
    return retVal;
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
        retVal += x * yCurr * (pow(10, place));
        place++;
    }

    return retVal;
}

long RecursiveAlgorithm(vector<int> xDigits, vector<int> yDigits) {
    int x = 0;
    int y = 0;
    int place = 0;
    int xSize = xDigits.size();
    int ySize = yDigits.size();
    int n = xSize > ySize ? xSize : ySize; // Max size
    // aDigits and bDigits are left and right halves of xDigits
    // cDigits and dDigits are left and right halves of yDigits
    vector<int> aDigits, bDigits, cDigits, dDigits;
    long long ac = 0;
    long long ad = 0;
    long long bc = 0;
    long long bd = 0;
    long long retVal = 0;

    // First if statements is our base case.
    // We are going to define our base C++ multiplication as when either x or y reaches a single-digit length.
    if (xSize == 1 && ySize == 1) {
        x = xDigits.back();
        y = yDigits.back();

        return x * y;
    }
    else if (xSize == 1) {
        x = xDigits.back();
        xDigits.pop_back();
        y = GetInteger(yDigits);

        return x * y;
    }
    else if (ySize == 1) {
        y = yDigits.back();
        yDigits.pop_back();
        x = GetInteger(xDigits);

        return x * y;
    }
    else {
        if (xSize >= ySize * 2) {
            vector<int> aDigits(xDigits.begin(), xDigits.begin() + (xSize / 2));
            vector<int> bDigits(xDigits.begin() + (xSize / 2), xDigits.end());
            vector<int> dDigits(yDigits.begin(), yDigits.end());

            ac = 0;
            ad = RecursiveAlgorithm(aDigits, dDigits);
            bc = 0;
            bd = RecursiveAlgorithm(bDigits, dDigits);
        }
        else if (ySize >= xSize * 2) {
            vector<int> bDigits(xDigits.begin(), xDigits.end());
            vector<int> cDigits(yDigits.begin(), yDigits.begin() + (ySize / 2));
            vector<int> dDigits(yDigits.begin() + (ySize / 2), yDigits.end());

            ac = 0;
            ad = 0;
            bc = RecursiveAlgorithm(bDigits, cDigits);
            bd = RecursiveAlgorithm(bDigits, dDigits);
        }
        else {
            vector<int> aDigits(xDigits.begin(), xDigits.begin() + (xSize / 2));
            vector<int> bDigits(xDigits.begin() + (xSize / 2), xDigits.end());
            vector<int> cDigits(yDigits.begin(), yDigits.begin() + (ySize / 2));
            vector<int> dDigits(yDigits.begin() + (ySize / 2), yDigits.end());

            ac = RecursiveAlgorithm(aDigits, cDigits);
            ad = RecursiveAlgorithm(aDigits, dDigits);
            bc = RecursiveAlgorithm(bDigits, cDigits);
            bd = RecursiveAlgorithm(bDigits, dDigits);
        }

        // 10^n * ac + 10^(n/2) * (ad + bc) + bd
        return pow(10, n) * ac + pow(10, n / 2) * (ad + bc) + bd;
    }

    return retVal;
}

long RecursiveAlgorithm(int x, int y) {
    int xSize = GetIntegerLength(x);
    int ySize = GetIntegerLength(y);
    int n = xSize > ySize ? xSize : ySize; // Max size
    long long ac = 0;
    long long ad = 0;
    long long bc = 0;
    long long bd = 0;

    // First if statements is our base case.
    // We are going to define our base C++ multiplication as when either x or y reaches a single-digit length.
    if (xSize == 1 || ySize == 1) {
        return x * y;
    }
    else {
        if (xSize >= ySize * 2) {
            ac = 0;
            ad = RecursiveAlgorithm((x / (int)pow(10, n/2)), y);
            bc = 0;
            bd = RecursiveAlgorithm((x % (int)pow(10, n/2)), y);
        }
        else if (ySize >= xSize * 2) {
            ac = 0;
            ad = 0;
            bc = RecursiveAlgorithm(x, (y / (int)pow(10, n/2)));
            bd = RecursiveAlgorithm(x, (y % (int)pow(10, n/2)));
        }
        else {
            ac = RecursiveAlgorithm((x / (int)pow(10, n/2)), (y / (int)pow(10, n/2)));
            ad = RecursiveAlgorithm((x / (int)pow(10, n/2)), (y % (int)pow(10, n/2)));
            bc = RecursiveAlgorithm((x % (int)pow(10, n/2)), (y / (int)pow(10, n/2)));
            bd = RecursiveAlgorithm((x % (int)pow(10, n/2)), (y % (int)pow(10, n/2)));
        }

        // 10^n * ac + 10^(n/2) * (ad + bc) + bd
        return pow(10, n) * ac + pow(10, n / 2) * (ad + bc) + bd;
    }
}

long KaratsubaAlgorithm(int x, int y) {
    int xSize = GetIntegerLength(x);
    int ySize = GetIntegerLength(y);
    int n = xSize > ySize ? xSize : ySize; // Max size
    int abcd[4] = {0, 0, 0, 0};
    long long ac = 0;
    long long bd = 0;
    long long pq = 0;

    // First if statements is our base case.
    // We are going to define our base C++ multiplication as when either x or y reaches a single-digit length.
    if (xSize == 1 || ySize == 1) {
        return x * y;
    }
    else {
        if (xSize >= ySize * 2) {
            abcd[0] = (x / (int)pow(10, n/2));
            abcd[1] = (x % (int)pow(10, n/2));
            abcd[3] = (y % (int)pow(10, n/2));
            ac = 0;
            bd = KaratsubaAlgorithm(abcd[1], abcd[3]);
            pq = KaratsubaAlgorithm((abcd[0] + abcd[1]), abcd[3]);
        }
        else if (ySize >= xSize * 2) {
            abcd[1] = (x % (int)pow(10, n/2));
            abcd[2] = (y / (int)pow(10, n/2));
            abcd[3] = (y % (int)pow(10, n/2));
            ac = 0;
            bd = KaratsubaAlgorithm(abcd[1], abcd[3]);
            pq = KaratsubaAlgorithm(abcd[1], (abcd[2] + abcd[3]));
        }
        else {
            abcd[0] = (x / (int)pow(10, n/2));
            abcd[1] = (x % (int)pow(10, n/2));
            abcd[2] = (y / (int)pow(10, n/2));
            abcd[3] = (y % (int)pow(10, n/2));
            ac = KaratsubaAlgorithm(abcd[0], abcd[2]);
            bd = KaratsubaAlgorithm(abcd[1], abcd[3]);
            pq = KaratsubaAlgorithm((abcd[0] + abcd[1]), (abcd[2] + abcd[3]));
        }

        // 10^n * ac + 10^(n/2) * (pq - ac - bd) + bd
        return pow(10, n) * ac + pow(10, n / 2) * (pq - ac - bd) + bd;
    }
}
