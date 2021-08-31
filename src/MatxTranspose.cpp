#include <iostream>
#include <vector>


//[3,2,5] -> [3,1,9]
//[1,3,1]  -> [2,3,7]
//[9,7,3] -> [5,1,3]
std::vector<std::vector<int>> mtxTranspose(std::vector<std::vector<int>> matxIn)
{
    std::vector<std::vector<int>> matxOut;
    
    for (int i = 0; i < matxIn.size(); ++i)
    {
        std::vector<int> rowIn = matxIn[i];
        std::vector<int> rowNew;
        
        for (int j = 0; j < rowIn.size(); ++j)
        {
            rowNew.push_back(matxIn[j][i]);
        }

        matxOut.push_back(rowNew);
    }

    return matxOut;
}


//[3,2,5] -> [3,1,9]
//[1,3,1]  -> [2,3,5]
//[9,7,3] -> [5,1,3]
int main()
{
    std::vector<std::vector<int>> matxIn;
    std::vector<std::vector<int>> matxOut;

    matxIn.push_back({3,2,5});
    matxIn.push_back({1,3,1});
    matxIn.push_back({9,7,3});

    matxOut = mtxTranspose(matxIn);

    for (int i = 0; i < matxOut.size(); ++i)
    {
        std::vector<int> row = matxOut[i];

        for (int j = 0; j < row.size(); ++j)
        {
            std::cout << row[j] << ",";
        }
        std::cout << "\n";
    }

    std::cout << "Hello World!\n";

    return 0;
}
