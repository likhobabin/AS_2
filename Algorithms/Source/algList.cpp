#include "algPrecompile.h"
#include "algList.h"
//

void tstList(void )
{
  list<int > list;
  //
  list.Add(9);
  list.Add(10);
  list.Add(-9);
  list.Add(0);
  list.Add(3);
  list.Add(5);
  //
  list.Reversed();
}