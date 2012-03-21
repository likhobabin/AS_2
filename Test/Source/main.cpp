#include "algPrecompile.h"
#include "algBinTree.h"
//

static void tstBinTree(void );
//

int main(int /*argc*/, const char** /*argv*/)
{
 tstBinTree();
 return(0);
}
//

static void tstBinTree(void )
{
 binTree<int > binTree;
 int val=0x3;
 
 binTree.Add(val);
 val = 0x6;
 binTree.Add(val);
 val = 0x4;
 binTree.Add(val);
 val=0xFFFFFFFF;//-1073741824 ... -1 <=> 0x80000000 ... 0xFFFFFFFF 
 binTree.Add(val);
 val=0x8;
 binTree.Add(val);
 val=2;
 binTree.Add(val);
 val = 5;
 binTree.Add(val);
 val = 7;
 binTree.Add(val);
 val=9;
 binTree.Add(val);
 val=-4;
 binTree.Add(val);
 val=-3;
 binTree.Add(val);
 val=-2;
 binTree.Add(val);
 val=-6;
 binTree.Add(val);
 //
 binTree.TraverseMaxMin();
 //
 binTree.Remove(-3);
 binTree.Remove(-2);
 binTree.Remove(-6);
 binTree.Remove(-4);
 binTree.Remove(9);
 binTree.Remove(8);
 binTree.Remove(6);
 //
 binTree.TraverseMaxMin();
}
