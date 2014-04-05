#include "Lawn.h"

#include <cstdlib>
#include <iostream>

  Lawn::Lawn(int a, int b)
:heightGrid(NULL), isPossibleGrid(NULL),
  n(a), m(b), possible(true), hasBeenSolve(false)
{
  heightGrid = new int*[n];
  isPossibleGrid = new bool*[n];
  for(int i=0; i<n; i++)
  {
    heightGrid[i] = new int[m];
    isPossibleGrid[i] = new bool[m];
    for(int j=0; j<m; j++)
    {
      heightGrid[i][j] = -1;
      isPossibleGrid[i][j] = false;
    }
  }
}

void Lawn::set(int i, int j, int height)
{
  heightGrid[i][j] = height;
}

void Lawn::solve()
{
  if(!hasBeenSolve)
  {
    /* go through each line */
    for(int i=0; i<n; i++)
    {
      int lineMax = 0;
      /* Search for maximum */
      for(int j=0; j<m; j++)
        if(lineMax < heightGrid[i][j])
          lineMax = heightGrid[i][j];

      /* Update isPossibleGrid */
      for(int j=0; j<m; j++)
        if(lineMax == heightGrid[i][j])
          isPossibleGrid[i][j] = true;
    }

    /* go through each line */
    for(int i=0; i<m; i++)
    {
      int lineMax = 0;
      /* Search for maximum */
      for(int j=0; j<n; j++)
        if(lineMax < heightGrid[j][i])
          lineMax = heightGrid[j][i];

      /* Update isPossibleGrid */
      for(int j=0; j<n; j++)
        if(lineMax == heightGrid[j][i])
          isPossibleGrid[j][i] = true;
    }

    /* Check if it's possible */
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(!isPossibleGrid[i][j])
          possible = false;
    hasBeenSolve = true;
  }
}

bool Lawn::isPossible()
{
  solve();
  return possible;
}

void Lawn::display()
{
  std::cout << "Size: " << n << " " << m << std::endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
      std::cout << heightGrid[i][j];
    std::cout << std::endl;
  }
}

