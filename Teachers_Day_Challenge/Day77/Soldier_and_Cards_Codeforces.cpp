/*
Problem: Soldier and Cards
Platform: Codeforces
Problem Number: 546C
Topic: Queue, Simulation

Approach:
1. Store both players' cards in queues.
2. In every round:
   - Remove the front card from both queues.
   - Compare the cards.
   - The player with the larger card puts both cards
     at the back of their queue.
3. Keep track of every state of the game.
4. If a state appears again, the game will repeat forever.
   Therefore, output -1.
5. If one player's queue becomes empty:
   - The other player wins.
   - Output the number of rounds and the winner.

State:
The complete state consists of:
   - Player 1's queue
   - Player 2's queue

Time Complexity:
O(number of unique states * n)

Space Complexity:
O(number of unique states * n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int k1;
    cin >> k1;

    queue<int> q1;

    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        q1.push(x);
    }

    int k2;
    cin >> k2;

    queue<int> q2;

    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        q2.push(x);
    }

    // Store previously encountered states
    set<pair<vector<int>, vector<int>>> states;

    int rounds = 0;

    while (!q1.empty() && !q2.empty()) {

        // Convert queues into vectors to represent the state
        vector<int> v1, v2;

        queue<int> temp1 = q1;
        queue<int> temp2 = q2;

        while (!temp1.empty()) {
            v1.push_back(temp1.front());
            temp1.pop();
        }

        while (!temp2.empty()) {
            v2.push_back(temp2.front());
            temp2.pop();
        }

        pair<vector<int>, vector<int>> state = {v1, v2};

        // Same state means the game will repeat forever
        if (states.count(state)) {
            cout << -1;
            return 0;
        }

        states.insert(state);

        // Play one round
        int a = q1.front();
        q1.pop();

        int b = q2.front();
        q2.pop();

        rounds++;

        if (a > b) {

            q1.push(b);
            q1.push(a);
        }

        else {

            q2.push(a);
            q2.push(b);
        }
    }

    cout << rounds << " ";

    if (q1.empty())
        cout << 2;
    else
        cout << 1;

    return 0;
}