#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solv(string digits, string out, int index, vector<string> &ans, string mapping[])
{

    if (index >= digits.size())
    {
        ans.push_back(out);
        return;
    }

    int num = digits[index] - '0';

    for (int i = 0; i < mapping[num].size(); i++)
    {
        out.push_back(mapping[num][i]);
        solv(digits, out, index + 1, ans, mapping);
        out.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{

    vector<string> ans;

    if (digits.size() == 0)
        return ans;

    string out = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solv(digits, out, 0, ans, mapping);

    return ans;
}

int main()
{
    string s = "232";

    vector<string> ans = letterCombinations(s);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}