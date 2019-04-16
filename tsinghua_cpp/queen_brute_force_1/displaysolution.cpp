/******************************************************************************************

 ******************************************************************************************/

#include "queen.h"

void displaySolution ( int* solu, int n ) { //���n*n�Ŀ��в���
   ( Step == runMode ) ? system ( "cls" ) : printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < n; j++ ) {
         printf ( ( j == solu[i] ) ? "��" : "[]" );
      }
      printf ( "\n" );
   }
   if ( Step == runMode ) {
      cout  << nSolu << " solution(s) found after " << nCheck << " check(s)\a";
      getchar();
   } else
      printf ( "\n" );
}