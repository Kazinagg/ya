#include <iostream>
#include <cctype>

using namespace std;

bool isNicknameSuitable(string);

int main() {
    string nick;
    cin >> nick;

    if (isNicknameSuitable(nick)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}


bool isNicknameSuitable(string nickname) {
    if (nickname.length() < 8) {
        return false;
    }

    bool isNumbers = false, isLower = false, isUpper = false;

    for (char c : nickname) {
        if (std::isdigit(c)) {
            isNumbers = true;
        }
        if (std::islower(c)) {
            isLower = true;
        }
        if (std::isupper(c)) {
            isUpper = true;
        }
    }

    return isNumbers and isLower and isUpper;
}