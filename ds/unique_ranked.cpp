// wap to get the ranks of the players according to leaderboard 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    // Remove duplicates from the ranked scores
    vector<int> uniqueRanked;
    for (int score : ranked) {
        if (uniqueRanked.empty() || uniqueRanked.back() != score) {
            uniqueRanked.push_back(score);
        }
    }

    vector<int> result;
    int position = uniqueRanked.size(); // Start at the end of uniqueRanked
    for (int score : player) {
        // Move position to the right place for the current player's score
        while (position > 0 && score >= uniqueRanked[position - 1]) {
            position--;
        }
        result.push_back(position + 1); // Rank is 1-based
    }

    return result;
}

int main() {
    int n, m;
    
    // Read leaderboard scores
    cin >> n;
    vector<int> ranked(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranked[i];
    }
    
    // Read player's scores
    cin >> m;
    vector<int> player(m);
    for (int i = 0; i < m; ++i) {
        cin >> player[i];
    }
    
    vector<int> ranks = climbingLeaderboard(ranked, player);
    
    for (int rank : ranks) {
        cout << rank << endl;
    }
    
    return 0;
}
