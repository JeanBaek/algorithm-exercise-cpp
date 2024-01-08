#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Agent {
    int a, b, c;
};

bool compareAgents(const Agent& agent1, const Agent& agent2) {
    return max(agent1.a, max(agent1.b, agent1.c)) < max(agent2.a, max(agent2.b, agent2.c));
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;

        vector<Agent> agents(n);
        for (int i = 0; i < n; ++i) {
            cin >> agents[i].a >> agents[i].b >> agents[i].c;
        }

        sort(agents.begin(), agents.end(), compareAgents);

        int result = -1;
        for (int i = 0; i < n; ++i) {
            int power = agents[i].a;
            int intelligence = agents[i].b;
            int agility = agents[i].c;

            int remaining_power = 0, remaining_intelligence = 0, remaining_agility = 0;

            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    remaining_power += agents[j].a;
                    remaining_intelligence += agents[j].b;
                    remaining_agility += agents[j].c;
                }
            }

            int min_remaining = min(
                    remaining_power - max(0, agents[i].a),
                    min(remaining_intelligence - max(0, agents[i].b), remaining_agility - max(0, agents[i].c))
            );

            int total_remaining = remaining_power + remaining_intelligence + remaining_agility;

            if (min_remaining >= max(max(power, intelligence), agility) && (result == -1 || total_remaining < result)) {
                result = total_remaining;
            }
        }

        cout << "#" << tc << " " << result << endl;
    }

    return 0;
}
