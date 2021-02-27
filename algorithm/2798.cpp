#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, answer = 0;
    vector<int> cards;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    for(int i = 0; i < cards.size() - 2; i++) {
        for(int j = i + 1; j < cards.size() - 1; j++) {
            for(int k = j + 1; k < cards.size(); k++) {
                if(cards[i] + cards[j] + cards[k] <= m)
                    answer = max(answer, cards[i] + cards[j] + cards[k]);
            }
        }
    }
    cout << answer << endl;
    
    return 0;
}