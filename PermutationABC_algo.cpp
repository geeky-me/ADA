#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
using namespace chrono;

// Function to generate a random string of given length
string generateRandomString(int length) {
    string str;
    for (int i = 0; i < length; i++) {
        char randomChar = 'a' + rand() % 26; // Generate a random lowercase letter
        str.push_back(randomChar);
    }
    return str;
}

// Recursive function to generate permutations
void generatePermutations(string prefix, string remaining, vector<string>& permutations) {
    if (remaining.empty()) {
        permutations.push_back(prefix);
        return;
    }

    for (int i = 0; i < remaining.length(); ++i) {
        string newPrefix = prefix + remaining[i];
        string newRemaining = remaining.substr(0, i) + remaining.substr(i + 1);
        generatePermutations(newPrefix, newRemaining, permutations);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    cout << "String Length\tTime Taken (nanoseconds)" << endl;
    cout << "---------------------------------------" << endl;

    for (int len = 5; len <= 12; ++len) {
        string str = generateRandomString(len);
        
        auto start_time = high_resolution_clock::now();
        vector<string> permutations;
        generatePermutations("", str, permutations);
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end_time - start_time).count();

        cout << "Length " << len << "\t\t" << duration << endl;
    }

    return 0;
}
