#include <cstdlib>

#include <iostream>

#define SIZE 1000000

long * collatzTable;

long collatzSequence(long i)
{
  if(i <= SIZE && collatzTable[i-1] != -1)
  {
    return collatzTable[i-1];
  }
  else
  {
    if((i%2) == 0)
    {
      long res = collatzSequence(i/2)+1;

      if(i <= SIZE)
        collatzTable[i-1] = res;
      
      return res;

    }
    else
    {
      long res = collatzSequence(i*3+1)+1;

      if(i <= SIZE)
        collatzTable[i-1] = res;

      return res;
    }
  }
}

int main(int argc, char * argv[])
{
  collatzTable = new long[SIZE];

  /* Init */
  collatzTable[0] = 1;
  for(long i=1; i<SIZE; i++)
  {
    collatzTable[i] = -1;
  }

  /* Compute */
  long max = -1;
  long maxI = -1;
  for(long i=1; i<=SIZE; i++)
  {
    long res = collatzSequence(i);
    if(res > max)
    {
      max = res;
      maxI = i;
    }
  }

  delete collatzTable;

  std::cout << "The longuest chain start from " << maxI << " and is " << max << std::endl;

  return 0;
}
