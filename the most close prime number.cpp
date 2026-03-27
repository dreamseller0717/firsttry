#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    int a[10000];
    cin >> N;
    
    // 输入验证
    if (N <= 0 || N > 10000) {  // 添加了N<=0的判断
        cout << "INCORRECT INPUT!";
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] <= 0 || a[i] >= 1000000) {  // 根据题目M<1000000，且M>0
            cout << "INCORRECT INPUT!";
            return 0;
        }
    }
    
    // 生成素数标记数组（埃氏筛法）
    const int MAX = 1000000;
    bool isPrime[MAX];
    // 初始化所有数为素数
    for (int i = 0; i < MAX; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;  // 0和1不是素数
    
    // 埃氏筛法
    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // 处理每个查询
    for (int i = 0; i < N; i++) {
        int num = a[i];
        
        // 如果本身就是素数
        if (isPrime[num]) {
            cout << num << " 0" << endl;
            continue;
        }
        
        // 向左找最近的素数
        int left = num - 1;
        while (left >= 2 && !isPrime[left]) {
            left--;
        }
        
        // 向右找最近的素数
        int right = num + 1;
        while (right < MAX && !isPrime[right]) {
            right++;
        }
        
        // 计算距离
        int leftDist = (left >= 2) ? num - left : 10000000;  // 如果左边没找到，设为很大
        int rightDist = (right < MAX) ? right - num : 10000000;  // 如果右边没找到，设为很大
        
        // 根据题目要求输出
        // 注意：如果left<2，表示左边没找到素数（这种情况很少，但需处理）
        if (leftDist <= rightDist && left >= 2) {
            // 左边距离 <= 右边距离，或者等距时选左边
            cout << left << " " << leftDist << endl;
        } else if (right < MAX) {
            // 右边更近，或者左边没有素数
            cout << right << " " << rightDist << endl;
        } else if (left >= 2) {
            // 右边越界，只能用左边的
            cout << left << " " << leftDist << endl;
        } else {
            // 理论上不会到这里，因为至少有一个素数
            cout << "ERROR" << endl;
        }
    }
    
    return 0;
}