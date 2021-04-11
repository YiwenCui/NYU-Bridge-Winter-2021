#include <iostream>
using namespace std;

int main() {
    int maxStars = 12;
    int toPrint = 1;

    for (int i = 0; i < maxStars; ++i) {
        // print out starting spaces for current row. let's assume maxStars >= 2, then...
        // first row has maxStars - 1 spaces since i = 0 and i % maxStars = 0. The range of iterations is [0, maxStars - 1), for a total of maxStars - 1 - 0 iterations.
        // second row has maxStars - 2 spaces since i = 1 and i % maxStars = 1. The range of iterations is [1, maxStars - 1), for a total of maxStars - 1 - 1 iterations.
        // and so on...
        for (int j = i % maxStars; j < maxStars - 1; ++j) {
            std::cout << ' ';
        }

        // print out either stars or spaces. if k index is even, print star, if k index is odd, print a space.
        for (int k = 0; k < toPrint; ++k) {
						//if (k % 2 == 0) {
            //    std::cout << '*';
            //}
            //else {
            //    std::cout << ' ';
            //}

						// this cout does the same thing as the commented if-else right above, but in one line using the conditional operator in C++.
            std::cout << (k % 2 == 0 ? '*' : ' ');
        }

        std::cout << '\n';
        toPrint += 2;
    }

    // have to subtract 4 here. First 2 because the last iteration of previous for-loop ends with toPrints += 2.
    // Another 2 subtracted away because we want the beginning of the second-half to print with less stars and spaces than the last.
    // the rest of the for-loop is the same as the first, but we're going in reverse.
    toPrint -= 4;
    for (int i = maxStars - 2; i >= 0; --i) {
        for (int j = i % maxStars; j < maxStars - 1; ++j) {
            std::cout << ' ';
        }

        for (int k = 0; k < toPrint; ++k) {
            std::cout << (k % 2 == 0 ? '*' : ' ');
        }

        std::cout << '\n';
        toPrint -= 2;
    }

    return 0;
}
            