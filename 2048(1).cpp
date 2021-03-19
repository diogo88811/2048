#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
int best;
int numberPeaces = 0;
int maxTent = 0;
int slide = 0;
bool accpet = false;
int counter = 0;
vector<vector<int>> moveRight(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveLeft(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveDown(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveUp(vector<vector<int>> vec, int nMatrix, int numMoves);
void play(vector<vector<int>> vec, int nMatrix, int numMoves);

void printMatrix(vector<vector<int>> vec, int nMatrix){  
    for(int i = 0; i < nMatrix; i++){
        for(int j = 0; j < nMatrix; j++){
            cout << vec[i][j] << " "; 
        }
        cout << endl;
    }
}

bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

vector<vector<int>> moveRight(vector<vector<int>> vec, int nMatrix)
{
    slide = 0;
    int temp = -9999;
    int j = nMatrix - 1;
    int k = nMatrix - 1;
    for (int i = 0; i < nMatrix; i++)
    {
        temp = -9999;
        j = nMatrix - 1;
        k = nMatrix - 1;
        while (j >= 0)
        {
            if (vec[i][j] == 0 && j > temp)
            {
                temp = j;
            }
            if (vec[i][j] != 0 && j < temp)
            {
                vec[i][temp] = vec[i][j];
                vec[i][j] = 0;
                slide = 1;
                temp--;
            }
            if (vec[i][k] != 0 && vec[i][k - 1] != 0)
            {
                if (vec[i][k] == vec[i][k - 1])
                {
                    vec[i][k] = vec[i][k] * 2;
                    numberPeaces--;
                    slide = 1;
                    vec[i][k - 1] = 0;
                    temp = k - 1;
                    k--;
                }
                else
                {
                    k--;
                }
            }
            j--;
        }
    }

    return vec;
}

vector<vector<int>> moveLeft(vector<vector<int>> vec, int nMatrix)
{
    int temp;
    int j;
    int k;
    slide = 0;
    for (int i = 0; i < nMatrix; i++)
    {
        temp = 9999;
        j = 0;
        k = 0;
        while (j < nMatrix)
        {
            if (vec[i][j] == 0 && j < temp)
            {
                temp = j;
            }
            if (vec[i][j] != 0 && j > temp)
            {
                vec[i][temp] = vec[i][j];
                vec[i][j] = 0;
                slide = 1;
                temp++;
            }
            if (vec[i][k + 1] != 0 && vec[i][k] != 0)
            {
                if (vec[i][k + 1] == vec[i][k])
                {
                    vec[i][k] = vec[i][k] * 2;
                    slide = 1;
                    numberPeaces--;
                    vec[i][k + 1] = 0;
                    temp = k + 1;
                    k++; 
                }
                else
                {
                    k++;
                }
            }
            j++;
        }
    }

    return vec;
}

vector<vector<int>> moveDown(vector<vector<int>> vec, int nMatrix)
{
    slide = 0;
    int temp = -9999;
    int j = nMatrix - 1;
    int k = nMatrix - 1;
    for (int i = 0; i < nMatrix; i++)
    {
        temp = -9999;
        j = nMatrix - 1;
        k = nMatrix - 1;
        while (j >= 0)
        {
            if (vec[j][i] == 0 && j > temp)
            {
                temp = j;
            }
            if (vec[j][i] != 0 && j < temp)
            {
                vec[temp][i] = vec[j][i];
                vec[j][i] = 0;
                slide = 1;
                temp--;
            }
            if (k >= 1)
            {
                if (vec[k][i] != 0 && vec[k - 1][i] != 0)
                {
                    if (vec[k][i] == vec[k - 1][i])
                    {
                        vec[k][i] = vec[k][i] * 2;
                        slide = 1;
                        numberPeaces--;
                        vec[k - 1][i] = 0;
                        temp = k - 1;
                        k--;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            j--;
        }
    }
    return vec;
}

vector<vector<int>> moveUp(vector<vector<int>> vec, int nMatrix)
{
    slide = 0;
    int temp;
    int j;
    int k;
    for (int i = 0; i < nMatrix; i++)
    {
        temp = 9999;
        j = 0;
        k = 0;
        while (j < nMatrix)
        {
            if (vec[j][i] == 0 && j < temp)
            {
                temp = j;
            }
            if (vec[j][i] != 0 && j > temp)
            {
                vec[temp][i] = vec[j][i];
                vec[j][i] = 0;
                slide = 1;
                temp++;
            }
            if (k <= nMatrix - 2)
            {
                if (vec[k + 1][i] != 0 && vec[k][i] != 0)
                {
                    if (vec[k + 1][i] == vec[k][i])
                    {
                        vec[k][i] = vec[k][i] * 2;
                        slide = 1;
                        numberPeaces--;
                        vec[k + 1][i] = 0;
                        temp = k + 1;
                        k++;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
            j++;
        }
    }

    return vec;
}

void play(vector<vector<int>> vec, int nMatrix, int numMoves)
{
    vector<vector<int>> aux;
    int auxiliar = numberPeaces;
    float auxCount = numberPeaces;
    int count1 = 0;
    counter++;

    if (numberPeaces == 1)
    {   
        if (best >= maxTent - numMoves)
        {
            accpet = true;
            best = maxTent - numMoves;
        }
        return;
    }

    if (numMoves < 0)
    {   
        return;
    }

    while (auxCount > 1)
    {
        auxCount = ceil(auxCount / 2);
        count1++;
    }

    if (count1 + (maxTent - numMoves) >= best)
    {   
        if (count1 + (maxTent - numMoves) > best)
        {
            return;
        }
        else if (count1 + (maxTent - numMoves) == best && accpet == true)
        {
            return;
        }
    }

    if (best <= maxTent - numMoves)
    {   
        return;
    }

    aux = moveDown(vec, nMatrix);
    if (slide == 1)
    {
        play(aux, nMatrix, numMoves - 1);
    }

    numberPeaces = auxiliar;

    aux = moveRight(vec, nMatrix);
    if (slide == 1)
    {
        play(aux, nMatrix, numMoves - 1);
    }
    numberPeaces = auxiliar;

    aux = moveUp(vec, nMatrix);
    if (slide == 1)
    {
        play(aux, nMatrix, numMoves - 1);
    }
    numberPeaces = auxiliar;

    aux = moveLeft(vec, nMatrix);
    if (slide == 1)
    {
        play(aux, nMatrix, numMoves - 1);
    }
    numberPeaces = auxiliar;
    return;
}

int main()
{
    vector<vector<int>> vec;
    vector<int> vec1;
    int numberTestCases, nMatrix, numbers;
    int sum = 0;
    float auxCount;
    int count1 = 0;
    cin >> numberTestCases;

    for (int i = 0; i < numberTestCases; i++)
    {
        vec.clear();

        cin >> nMatrix >> maxTent;
        best = maxTent;

        for (int k = 0; k < nMatrix; k++)
        {
            vec1.clear();
            for (int i = 0; i < nMatrix; i++)
            {
                cin >> numbers;
                if (numbers != 0)
                {
                    numberPeaces++;
                    sum += numbers;
                }
                vec1.push_back(numbers);
            }
            vec.push_back(vec1);
        }

        auxCount = numberPeaces;
        while (auxCount > 1)
        {
            auxCount = ceil(auxCount / 2);
            count1++;
        }


        if(isPowerOfTwo(sum) && count1 <= maxTent){
            play(vec, nMatrix, maxTent);
        }
        if (accpet == false)
        {
            cout << "no solution" << endl;
        }
        else
        {
            cout << best << endl;
        }
        sum = 0;
        accpet = false;
        count1 = 0;
        numberPeaces = 0;
    }
}