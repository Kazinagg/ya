#include <iostream>
#include <list>

using namespace std;

int main() {
    string world;
    string pressing;

    list<char> result;
    auto cursor = result.begin();

    cin >> world;
    cin >> pressing;

    for (int cur = 0; cur < pressing.size(); cur++) {
        if (pressing[cur] != '<') {
            result.insert(cursor, pressing[cur]);
        } else {
            string command = pressing.substr(cur, pressing.find('>', cur) - cur + 1);
            if (command == "<delete>" && cursor != result.end()) {
                cursor = result.erase(cursor);
            } else if (command == "<bspace>" && cursor != result.begin()) {
                cursor = result.erase(--cursor);
            } else if (command == "<left>" && cursor != result.begin()) {
                cursor--;
            } else if (command == "<right>" && cursor != result.end()) {
                cursor++;
            }
            cur += command.size() - 1;
        }
    }

    string finalResult(result.begin(), result.end());
    if (finalResult == world) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
