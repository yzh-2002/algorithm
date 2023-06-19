#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @description: 根据子串获取next数组（本质是寻找子串"前缀"和"后缀"的最长共有元素长度）
 * @pattern: 目标搜寻子串
 */
void getNext(string pattern, vector<int> &next)
{
    int len = 0;
    next[0] = 0; // 子串首字母永远对应0
    for (int i = 1; i < pattern.size(); i++)
    {
        int j = next[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
}

/**
 * @origin:源串
 */
int kmp(string origin, string pattern)
{
    vector<int> next(pattern.size());
    getNext(pattern, next);
    int i, j = 0;
    while (i < origin.size() && j < pattern.size())
    {
        if (origin[i] == pattern[j]){
            i++;
            j++;
        }else{
            if (j>0){
                j =next[j-1];
            }else{
                i++;
            }
        }
        if (j==pattern.size()){
            return i-j;
        }else{
            return -1;
        }
    }
}

int main() {
    string text = "ABABABCABAABABABD";
    string pattern = "ABABABD";
    int pos = kmp(text, pattern);
    if (pos != -1) {
        cout << "Pattern found at position " << pos << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}