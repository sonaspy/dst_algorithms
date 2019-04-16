/******************************************************************************************

 ******************************************************************************************/


#include "hanoi.h"

void move ( Stack<Disk>& Sa, Stack<Disk>& Sb ) { //将Sa顶部的盘子移至Sb顶部
   Sb.push ( Sa.pop() ); //pop a disk from stack A and push it into stack B
   displayHanoi();
}