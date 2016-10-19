#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
  ifstream fin(argv[1]);
  string source = argv[2];
  double threshold = atof(argv[3]);
  int lenS = source.size();
  
 
  string word;
  int lenD;

  double subDist;
  double delDist;
  double insDist;
  
  while (!fin.eof())
  {
    fin >> word;
    double** matrix = new double*[lenS+1];
    lenD = word.size();
    for (int m = 0; m < lenS+1; m++)
    {
      matrix[m] = new double[lenD+1];
      matrix[m][lenD] = lenS - m;
    }

    for (int n = 0; n < lenD; n++)
    {
      matrix[lenS][n] = lenD - n;
    }
    
    for (int i = lenS - 1; i >= 0; i--)
    { 
      for (int j = lenD - 1; j >= 0; j--)
      {
        if (source[i] == word[j])
	{
          matrix[i][j] = matrix[i+1][j+1];
	}
        else
	{
          subDist = 1 + matrix[i+1][j+1];
          delDist = 1 + matrix[i][j+1];
          insDist = 1 + matrix[i+1][j];
          matrix[i][j] = min(min(subDist,delDist),insDist);
        }
      }
    }
    

    if (matrix[0][0] <= threshold)
    {
      cout << word << endl;
    }

    for (int e = 0; e < lenS+1; e++)
    {
      delete[] matrix[e];
    }
    delete[] matrix;
  }
  
}
