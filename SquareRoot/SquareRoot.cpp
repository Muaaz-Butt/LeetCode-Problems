#include <iostream>

using namespace std;

int mySqrt(int x) {
    long long int i = 1;
    while (i * i < x) {
        i++;
    }
    if (i * i > x) {
        i--;
    }
    return i;
}


