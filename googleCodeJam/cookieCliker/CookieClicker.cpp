#include "CookieClicker.h"
#include <algorithm>

CookieClicker::CookieClicker(double price, double rate, double g)
:farmPrice(price), farmRate(rate), goal(g)
{
}

double CookieClicker::solve()
{
  return solveRec(2.0f);
}

double CookieClicker::solveRec(double rate)
{
  double timeToWin = goal/rate;
  double nextFarm = farmPrice/rate;
  double nextTimeToWin = goal/(farmRate+rate) + nextFarm;

  if(timeToWin < nextTimeToWin)
  {
    return timeToWin;
  }
  else
  {
    double timeToWinNextFarm = solveRec(farmRate+rate) + nextFarm;
    return std::min(timeToWin,timeToWinNextFarm);
  }
}

