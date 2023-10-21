#include <vector>
#include <iostream>
using namespace std;
class NumMatrix
{
private:
    vector<vector<int> > sums;
public:
    NumMatrix(vector<vector<int> > matrix) {
        cout<<"size:"<<matrix.size()<<endl;
        if(matrix.size() == 0 || matrix[0].size() ==0) {
            return;
        }
        sums = vector<vector<int> >(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for (int i = 0; i < matrix.size(); i++)
        {
            int rowSum = 0;
            for(int j =0 ; j< matrix[i].size(); j++){
                rowSum +=matrix[i][j];
                sums[i+1][j+1] = sums[i][j+1] + rowSum;
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] -sums[row2+1][col1] + sums[row1][col1];
    }
    ~NumMatrix(){}
};

// NumMatrix::NumMatrix(/* args */)
// {
// }

// NumMatrix::~NumMatrix()
// {
// }
