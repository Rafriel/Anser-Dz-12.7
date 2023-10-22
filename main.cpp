#include <iostream>
#include <string>
using namespace std;

bool IsKPeriodic(const string& str, int k) {
    if (k <= 0 || str.length() % k != 0) {
        return false;
    }
    const int block_length = k;
    const int num_blocks = str.length() / block_length;
    const string first_block = str.substr(0, block_length);
    for (int i = 1; i < num_blocks; ++i) {
        const string block = str.substr(i * block_length, block_length);
        if (block != first_block) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string str = "abcabcabcabc";
    int k = 3;
    if (IsKPeriodic(str, k)) {
        cout << str << " is " << k << "-periodic" << endl;
    }
    else {
        cout << str << " is not " << k << "-periodic" << endl;
    }
    return 0;
}
