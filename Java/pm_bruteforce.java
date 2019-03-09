












import dsa.
import java.io.

public class PM_BruteForce {






    public static int PM(String T, String P) {
        int      i;
        int      j;
        for (i = 0; i <= T.length() - P.length(); i++) {
            for (j = 0; j < P.length(); j++) {
                if (T.charAt(i + j) != P.charAt(j))   break;
            }
            if (j >= P.length()) break;
        }
        return(i);
    }
}
