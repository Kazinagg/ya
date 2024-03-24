#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMinIndices(const vector<int>& prices) {
    vector<int> indices;
    int currentMinIndex = min_element(prices.begin(), prices.end()) - prices.begin();
    indices.push_back(currentMinIndex);

    while (currentMinIndex != 0) {
        // Находим минимальный элемент слева от текущего минимального
        currentMinIndex = min_element(prices.begin(), prices.begin() + currentMinIndex) - prices.begin();
        indices.push_back(currentMinIndex);
    }

    // Переворачиваем вектор, чтобы индексы шли в правильном порядке
    // reverse(indices.begin(), indices.end());
    return indices;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> price(N);
    for (int& _price : price) {
        cin >> _price;
    }

    vector<int> minIndices = findMinIndices(price);

    for (int index : minIndices) {
        cout << index << ' ';
    }
    cout << endl;

    return 0;
}
