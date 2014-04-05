#ifndef GCJ_LAWN_H__
#define GCJ_LAWN_H__

class Lawn
{
  public:
    Lawn(int a, int b);
    void set(int i, int j, int height);
    void solve();
    bool isPossible();
    void display();

  private:
    int ** heightGrid;
    bool ** isPossibleGrid; 
    int n,m;
    bool possible, hasBeenSolve;
};

#endif

