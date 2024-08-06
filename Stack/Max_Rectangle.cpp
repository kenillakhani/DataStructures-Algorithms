#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    std::vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int *heights, int n)
{

    std::vector<int> next = nextSmallerElement(heights, n);
    std::vector<int> prev = prevSmallerElement(heights, n);

    int area = -1;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = std::max(area, newArea);
    }
    return area;
}
int maxRectangle(int arr[][4], int n)
{
    int area = largestRectangleArea(arr[0], 4);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j])
                arr[i][j] += arr[i - 1][j];
        }
        area = max(area, largestRectangleArea(arr[i], 4));
    }
    return area;
}
int main()
{
    int arr[][4] = {{0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum area of rectangle is: ";
    cout << maxRectangle(arr, n);
    cout << endl;
    return 0;
}