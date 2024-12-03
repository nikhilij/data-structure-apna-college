// set matrix zero for a given m x n integer matrix, if an element is 0 set its enitre rwo and column to 0's

// and we do not need extra space for that

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        cout << n <<endl;
        int m = matrix[0].size();
        vector<int> x, y;

        // Step 1: Store the row and column indices of the zeros
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        // Step 2: Set the entire row to 0 for each zero found
        for (int i = 0; i < x.size(); i++)
        {
            int index = x[i];
            for (int j = 0; j < m; j++)
            {
                matrix[index][j] = 0;
            }
        }

        // Step 3: Set the entire column to 0 for each zero found
        for (int i = 0; i < y.size(); i++)
        {
            int index = y[i];
            for (int j = 0; j < n; j++)
            {
                matrix[j][index] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution solution;

    // Initialize a matrix
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    // Print the original matrix
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    // Call the function to set zeroes
    solution.setZeroes(matrix);

    // Print the modified matrix
    cout << "Modified matrix after setting zeroes:" << endl;
    printMatrix(matrix);

    return 0;
}
