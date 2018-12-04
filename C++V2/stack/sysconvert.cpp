


static char digit[]  
   = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void convert ( Stack<char>& S , __int64 n, int base ) {  
   if(!n) return;
   else {  
      S.push ( digit[n % base] );  
      convert ( S, n / base, base );  
   }
}

void convert_no_recursive( Stack<char>& S , __int64 n, int base){
   while(n > 0){
       S.push ( digit[n % base] ); 
       n /= base;
   }
}
