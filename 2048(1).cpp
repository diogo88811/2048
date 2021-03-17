#include <iostream>
#include <vector>
#include <sstream>
#include <math.h> 
#include <chrono>
using namespace std;
using namespace std::chrono;
int counter = 0;
int best = 999999;
int numberPeaces = 0;
int maxTent = 0;
int slide = 0;
vector<vector<int>> moveRight(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveLeft(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveDown(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveUp(vector<vector<int>> vec, int nMatrix, int numMoves);
void play(vector<vector<int>> vec, int nMatrix, int numMoves);

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
            if (k > 1)
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
            if (k < nMatrix - 2)
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
    counter++;
    float auxCount = numberPeaces;
    int count1 = 0;
    while(auxCount > 1){
        auxCount = ceil(auxCount / 2);
        count1 ++;
    }

    if(count1 + (maxTent - numMoves) >= best){
        return;
    }


    if (numMoves < 0)
    {
        return;
    }
    if (best <= maxTent - numMoves)
    {
        return;
    }

    if (numberPeaces == 1)
    {
        if (best > maxTent - numMoves)
        {
            best = maxTent - numMoves;
        }
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

    cin >> numberTestCases;

    for (int i = 0; i < numberTestCases; i++)
    {
        vec.clear();

        cin >> nMatrix >> maxTent;
        best = maxTent +1 ;

        for (int k = 0; k < nMatrix; k++)
        {
            vec1.clear();
            for (int i = 0; i < nMatrix; i++)
            {
                cin >> numbers;
                if (numbers != 0)
                {
                    numberPeaces++;
                }
                vec1.push_back(numbers);
            }
            vec.push_back(vec1);
        }

        auto start = high_resolution_clock::now();
        play(vec, nMatrix, maxTent);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time: " << duration.count() << "\n";


        if (best == maxTent + 1 || best > maxTent)
        {
            cout << "no solution" << endl;
        }
        else
        {
            cout << best << endl;
        }
        cout << counter << endl;
        counter = 0;
        numberPeaces = 0;
    }
}