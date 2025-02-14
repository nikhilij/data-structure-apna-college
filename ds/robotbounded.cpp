#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string &s)
    {
        int x = 0, y = 0;
        // basicall there could be 4 directions // north // west // south // east
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int dirIndex = 0;
        for (char inst : s)
        {
            if (inst == 'G')
            {
                x += directions[dirIndex][0];
                y += directions[dirIndex][1];
            }
            else if (inst == 'L')
            {
                dirIndex = (dirIndex + 1) % 4;
            }
            else
            {
                dirIndex = (dirIndex + 3) % 4;
            }
        }
        return (x == 0 && y == 0) || dirIndex != 0;
    }
};

int main()
{
    Solution solution;
    string instructions;
    cout << "Enter the robot instructions: ";
    cin >> instructions;
    if (solution.isRobotBounded(instructions))
    {
        cout << "The robot is bounded in a circle." << endl;
    }
    else
    {
        cout << "The robot is not bounded in a circle." << endl;
    }
    return 0;
}