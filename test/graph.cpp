#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int maxNode = 10000;
    int depth = 6;  // 뎁스의 최대 높이 (여기서는 6으로 설정)

    // 최대 노드 번호가 10000인 경우, 노드의 최대 깊이를 계산
    int maxDepth = 0;
    int totalNodes = 0;
    while (totalNodes + (maxDepth + 1) <= maxNode) {
        maxDepth++;
        totalNodes += maxDepth;
    }

    int nodeNumber = 1;

    // 뎁스별로 노드 출력
    for (int i = 1; i <= maxDepth; ++i) {
        // 해당 뎁스의 노드 출력
        for (int j = 1; j <= i; ++j) {
            if (nodeNumber > maxNode) {
                break;
            }

            // 노드 번호 출력
            cout << setw(2) << nodeNumber << " ";

            // 다음 노드 번호로 이동
            nodeNumber++;
        }

        // 개행 출력
        cout << endl;
    }

    return 0;
}
