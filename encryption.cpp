#include "encryption.h"
#include <cctype>

string encrypt(const string& input) {
    string result = input;
    for (char& c : result) {
        if (isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            }
            else if (c == 'Z') {
                c = 'A';
            }
            else {
                c += 1;
            }
        }
    }
    return result;
}

string decrypt(const string& input) {
    string result = input;
    for (char& c : result) {
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            }
            else if (c == 'A') {
                c = 'Z';
            }
            else {
                c -= 1;
            }
        }
    }
    return result;
}
