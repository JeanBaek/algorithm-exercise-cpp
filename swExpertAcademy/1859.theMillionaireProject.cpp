#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 테스트 케이스 수 입력
    int T;
    cin >> T;

    // 각 테스트 케이스에 대해 반복
    for (int tc = 1; tc <= T; ++tc) {
        // 테스트 케이스 입력
        int N;
        cin >> N;

        // 각 날의 매매가를 저장하는 벡터
        vector<int> prices(N);

        // 매매가 입력
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        // 최대 이익 계산
        long long maxProfit = 0;
        int maxPrice = prices[N - 1]; // 마지막 날의 매매가로 초기화

        // 거꾸로 탐색하여 최대 이익 계산
        for (int i = N - 2; i >= 0; --i) {
            // 현재 날의 매매가가 최댓값보다 큰 경우 최댓값 업데이트
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
            } else {
                // 현재 날에 판매할 때의 이익 누적
                maxProfit += maxPrice - prices[i];
            }
        }

        // 결과 출력
        cout << "#" << tc << " " << maxProfit << endl;
    }

    return 0;
}