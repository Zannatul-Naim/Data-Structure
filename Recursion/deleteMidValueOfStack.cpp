class Solution
{
    public:
    void deleteMid(stack<int>&s, int n, int cnt = 0)
    {
        if(s.empty()) return;
        if(cnt == n/2) {
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        deleteMid(s, n, cnt+1);
        s.push(top);
    }
};
