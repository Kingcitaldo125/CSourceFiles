#include <iostream>
#include <vector>


//[3,2,5] -> [3,1,9]
//[1,3,1]  -> [2,3,7]
//[9,7,3] -> [5,1,3]
inline std::vector<std::vector<int>> mtxTranspose(std::vector<std::vector<int>> matxIn)
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
    std::vector<int> r1;
    std::vector<int> r2;
    std::vector<int> r3;

    r1.push_back(3);
    r1.push_back(2);
    r1.push_back(5);

    r2.push_back(1);
    r2.push_back(3);
    r2.push_back(1);

    r3.push_back(9);
    r3.push_back(7);
    r3.push_back(3);

    matxIn.push_back(r1);
    matxIn.push_back(r2);
    matxIn.push_back(r3);

    matxOut = mtxTranspose(matxIn);

    for (int i = 0; i < matxOut.size(); ++i)
    {
        std::vector<int> row = matxOut[i];

        for (int j = 0; j < row.size(); ++j)
        {
            std::cout << row[j] << ",";
        }
    }

    std::cout << "Hello World!\n";

    return 0;
}
