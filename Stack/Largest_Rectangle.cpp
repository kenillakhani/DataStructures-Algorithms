#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

        vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

        vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = -1;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = std::max(area, newArea);
        }
        return area;
    }

int main()
{
     vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);

    cout << "Largest Rectangle Area is : " << largestRectangleArea(arr) << endl; 
    return 0;
}