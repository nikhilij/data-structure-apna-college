class Solution
{
public:
    string roundToNearest(string str)
    {
        // Complete the function
        int n = str.length();
        int end = n - 1;
        int last = str[end] - '0';
        if (last >= 5)
        {
            int i = n - 2;
            while (i >= 0 && s[i] == '9')
            {
                str[i] = '0';
                i--;
            }

            str[end] = '0';
        }
    }
};