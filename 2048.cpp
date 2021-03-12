#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


int counter = 0;
int best = 999999;
int numberPeaces = 0;
int maxTent = 0 ;

vector<vector<int>> moveRight(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveLeft(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveDown(vector<vector<int>> vec, int nMatrix, int numMoves);
vector<vector<int>> moveUp(vector<vector<int>> vec, int nMatrix, int numMoves);
void play(vector<vector<int>> vec, int nMatrix, int numMoves);

vector<vector<int>> moveRight(vector<vector<int>> vec, int nMatrix)
{
    for (int i = 0; i < nMatrix; i++)
    {
        vector<int> v, w;
        int j;
        int vsize = 0;
        int wsize = 0;
        for (j = nMatrix - 1; j >= 0; j--)
        {
            if (vec[i][j] != 0)
            {
                v.push_back(vec[i][j]);
                vsize++;
            }
        }

        for (j = 0; j < vsize; j++)
        {
            if (j < vsize - 1 && v[j] == v[j + 1])
            {
                w.push_back(2 * v[j]);
                numberPeaces--;
                wsize++;
                j++;
            }
            else
            {
                w.push_back(v[j]);
                wsize++;
            }
        }

        for (j = 0; j < nMatrix; j++)
        {
            vec[i][j] = 0;
        }

        j = nMatrix - 1;

        for (int k = 0; k < wsize; k++)
        {
            vec[i][j] = w[k];
            j--;
        }
    }

    return vec;
}

vector<vector<int>> moveLeft(vector<vector<int>> vec, int nMatrix)
{
    for (int i = 0; i < nMatrix; i++)
    {
        vector<int> v, w;
        int j;
        int vsize = 0;
        int wsize = 0;
        for (j = 0; j < nMatrix; j++)
        {
            if (vec[i][j] != 0)
            {
                v.push_back(vec[i][j]);
                vsize++;
            }
        }

        for (j = 0; j < vsize; j++)
        {
            if (j < vsize - 1 && v[j] == v[j + 1])
            {
                w.push_back(2 * v[j]);
                numberPeaces--;
                wsize++;
                j++;
            }
            else
            {
                w.push_back(v[j]);
                wsize++;
            }
        }

        for (j = 0; j < nMatrix; j++)
        {
            vec[i][j] = 0;
        }

        j = 0;

        for (int k = 0; k < wsize; k++)
        {
            vec[i][j] = w[k];
            j++;
        }
    }

    return vec;
}

vector<vector<int>> moveDown(vector<vector<int>> vec, int nMatrix)
{
    for (int i = 0; i < nMatrix; i++)
    {
        int j;
        int vsize = 0;
        int wsize = 0;
        vector<int> v, w;
        for (j = nMatrix - 1; j >= 0; j--)
        {
            if (vec[j][i] != 0)
            {
                v.push_back(vec[j][i]);
                vsize++;
            }
        }

        for (j = 0; j < vsize; j++)
        {
            if (j < vsize - 1 && v[j] == v[j + 1])
            {
                w.push_back(2 * v[j]);
                numberPeaces--;
                j++;
                wsize++;
            }
            else
            {
                w.push_back(v[j]);
                wsize++;
            }
        }

        for (j = 0; j < nMatrix; j++)
        {
            vec[j][i] = 0;
        }

        j = nMatrix - 1;

        for (int k = 0; k < wsize; k++)
        {
            vec[j][i] = w[k];
            j--;
        }
    }
    return vec;
}

vector<vector<int>> moveUp(vector<vector<int>> vec, int nMatrix)
{   
    for (int i = 0; i < nMatrix; i++)
    {
        int j;
        vector<int> v, w;
        int vsize = 0;
        int wsize = 0;
        for (j = 0; j < nMatrix; j++)
        {
            if (vec[j][i])
            {
                v.push_back(vec[j][i]);
                vsize++;
            }
        }

        for (j = 0; j < vsize; j++)
        {
            if (j < vsize - 1 && v[j] == v[j + 1])
            {
                w.push_back(v[j] * 2);
                numberPeaces--;
                j++;
                wsize++;
            }
            else
            {
                w.push_back(v[j]);
                wsize++;
            }
        }

        for (j = 0; j < nMatrix; j++)
        {
            vec[j][i] = 0;
        }

        j = 0;

        for (int k = 0; k < wsize; k++)
        {
            vec[j][i] = w[k];
            j++;
        }
    }

    return vec;
}

void play(vector<vector<int>> vec, int nMatrix, int numMoves)
{
    vector<vector<int>> aux;
    int auxiliar = numberPeaces;

    if(numMoves == 0)
    {
        return;
    }

    if(numberPeaces == 1 && best >= maxTent-numMoves){
        best = maxTent-numMoves;
        return;
    }
    
    aux = moveLeft(vec, nMatrix);
    if(aux != vec){
        play(aux, nMatrix, numMoves-1); 
    }
    numberPeaces = auxiliar;


    aux = moveRight(vec, nMatrix);
    if(aux != vec){
        play(aux, nMatrix, numMoves-1); 
    }
    numberPeaces = auxiliar;


    aux = moveDown(vec, nMatrix);
    if(aux != vec){
        play(aux, nMatrix, numMoves-1); 
    }
    numberPeaces = auxiliar;


    aux = moveUp(vec, nMatrix);
    if(aux != vec){
        play(aux, nMatrix, numMoves-1); 
    }
    numberPeaces = auxiliar;

    return;
}

int main()
{
    vector<vector<int>> vec;
    int numberTestCases, nMatrix;
    string input;

    cin >> numberTestCases;

    for (int i = 0; i < numberTestCases; i++)
    {
        vec.clear();

        cin >> nMatrix >> maxTent;

        getline(cin, input);

        for (int k = 0; k < nMatrix; k++)
        {
            vector<int> vec1;

            getline(cin, input);
            istringstream ss(input);
            string word;
            while (ss >> word)
            {
                if(stoi(word) != 0){
                    numberPeaces++;
                }
                vec1.push_back(stoi(word));
            }
            vec.push_back(vec1);
        }
        play(vec, nMatrix, maxTent);
     
        if(best == 999999 || best > maxTent){
            cout << "no solution" << endl;
        }
        else{
            cout << best << endl;
        }
        best = 999999;
        numberPeaces = 0;
    }
}