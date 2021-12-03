#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

/**
 * Inserts the given item into the int array. Not ideal since it has to resize the int array nearly every time.
 *
 * The story behind this is I wanted a dynamically allocated structure but my friend would denounce me if I used vector.
 *
 * @param array The int array to resize.
 * @param i The int to add into the array.
 * @param n The length of the array.
 */
void resize (int **array, int i, int n) {
    int *temp = new int[n + 1];
    for (int j = 0; j < n; j++) temp[j] = (*array)[j];
    temp[n] = i;
    delete (*array);
    *array = temp;
}

/**
 * Converts the given string which represents a binary number into the corresponding decimal value.
 *
 * @param s The string to convert.
 * @return The decimal value of the given string.
 */
int convertBinary (string s) {
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        r *= 2;
        if (s[i] == '1') r++;
    }
    return r;
}

/**
 * You need to use the binary numbers in the diagnostic report to generate two new binary numbers (called the gamma rate and the
 * epsilon rate). The power consumption can then be found by multiplying the gamma rate by the epsilon rate
 *
 * Each bit in the gamma rate can be determined by finding the most common bit in the corresponding position of all numbers in
 * the diagnostic report.
 *
 * The epsilon rate is calculated in a similar way; rather than use the most common bit, the least common bit from each position
 * is used.
 *
 * @param filename The file to open and read from to get input.
 */
void part1 (string filename) {
    ifstream *file = new ifstream();
    file->open(filename);
    if (!file->is_open()) return; // Failed to open file.
    string input;
    *file >> input;
    int *gammaCounts = new int[input.size()]{0};
    int elapsed = 1;
    for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
    while (!file->eof()) {
        *file >> input;
        elapsed++;
        for (int i = 0; i < input.size(); i++) if (input[i] == '1') gammaCounts[i]++;
    }
    string temp = "";
    for (int i = 0; i < input.size(); i++) { gammaCounts[i] > (elapsed / 2) ? temp += '1' : temp += '0'; }
    unsigned int gamma = convertBinary(temp);
    cout << "The Power Consumption is: " << gamma * (~gamma % (int)pow(2, input.size())) << endl;
}

/**
 * Part 2 has quite the lengthy definition even for the important information. You can find it in `description.md`.
 *
 * @parm filename The file to open and read from to get input.
 */
void part2 (string filename) {
    ifstream *file = new ifstream();
    file->open(filename);
    if (!file->is_open()) return; // Failed to open file.
    string input;
    *file >> input;
    int length = input.size();
    int *list = new int[1]{0};
    int size = 1;
    list[0] = convertBinary(input);
    while (!file->eof()) {
        *file >> input;
        resize(&list, convertBinary(input), size);
        size++;
    }
    int remaining = size;
    for (int i = 1; i <= length; i++) {
        if (remaining == 1) break;
        int onesCount = 0;
        int power = pow(2, length - i); // This is the bit we are counting.
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) == power) onesCount++;
        }
        int require = 0;
        if (onesCount >= (remaining / 2.0)) require = power;
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) != require) {
                list[j] = -1;
                remaining--;
            }
        }
        if (remaining < 4) {
            for (int j = 0; j < size; j++) if (list[j] != -1) cout << list[j] << endl;
        }
    }
    int oxygen = -1;
    for (int i = 0; i < size; i++) {
        if (list[i] != -1) {
            oxygen = list[i];
            break;
        }
    }
    cout << "Oxygen Generator Rating: " << oxygen << endl;
    list = new int[1]{0};
    size = 1;
    file->clear();
    file->seekg(0);
    *file >> input;
    list[0] = convertBinary(input);
    while (!file->eof()) {
        *file >> input;
        resize(&list, convertBinary(input), size);
        size++;
    }
    remaining = size;
    for (int i = 1; i <= length; i++) {
        if (remaining == 1) break;
        int onesCount = 0;
        int power = pow(2, length - i); // This is the bit we are counting.
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) == power) onesCount++;
        }
        int require = 0;
        if (onesCount < (remaining / 2.0)) require = power;
        for (int j = 0; j < size; j++) {
            if (list[j] == -1) continue;
            if ((list[j] & power) != require) {
                list[j] = -1;
                remaining--;
            }
        }
    }
    int carbon = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] != -1) {
            carbon = list[i];
            break;
        }
    }
    cout << "CO2 Scrubber Rating: " << carbon << endl;
    cout << "Life Support Rating: " << carbon * oxygen << endl;
}

/**
 * The main execution point of the program.
 */
int main () {
    string file = "input.txt";
    part1(file);
    part2(file);
}
