












import dsa.
import java.io.

public class PM_BM {
    final static int CARD_CHAR_SET = 256;






    public static int PM(String T, String P) {
        int[]    BC = BuildBC(P);
        int[]    GS = BuildGS(P);
        int i = 0;
        while (T.length() - P.length() >= i) {
            int j = P.length() - 1;
            while (P.charAt(j) == T.charAt(i + j))
                if (0 > --j)   break;
            ShowProgress(T, P, i, j);
            System.out.print("\n");
            if (0 > j)
                break;
            else
                i += MAX(GS[j], j - BC[T.charAt(i+j)]);
        }
        return(i);
    }











    protected static int[] BuildBC(String P) {
        int[] BC = new int[CARD_CHAR_SET];
        int   j;
        for (j = 0; j < CARD_CHAR_SET; j++)
            BC[j] = -1;
        for (j = 0; j < P.length(); j++)
            BC[P.charAt(j)] = j;
        System.out.println("-- BC[] Table ---------------");
        for (j = 0; j < CARD_CHAR_SET; j++)
            if (0 <= BC[j])   System.out.print("\t" + (char)j);
        System.out.println();
        for (j = 0; j < CARD_CHAR_SET; j++)
            if (0 <= BC[j])   System.out.print("\t" + BC[j]);
        System.out.println("\n");
        return(BC);
    }

















    protected static int[] ComputeSuffixSize(String P) {
        int      m = P.length();
        int[] SS = new int[m];
        int      s, t;
        int      j;
        SS[m-1]  =  m;
        s  =  m - 1;
        t = m - 2;
        for (j = m - 2; j >= 0; j--) {
            if ((j > s) && (j - s > SS[(m-1-t)+j]))
                SS[j] =  SS[(m-1-t)+j];
            else {
                t = j;
                s = MIN(s, j);
                while ((0 <= s) && (P.charAt(s) == P.charAt((m - 1 - t) + s)))
                    s--;
                SS[j] = t - s;
            }
        }
        System.out.println("-- SS[] Table -------");
        for (j = 0; j < m; j++)  System.out.print("\t" + P.charAt(j));
        System.out.println();
        for (j = 0; j < m; j++)  System.out.print("\t" + SS[j]);
        System.out.println("\n");
        return(SS);
    }





    protected static int[] BuildGS(String P) {
        int      m = P.length();
        int[] SS = ComputeSuffixSize(P);
        int[] GS = new int[m];
        int      j;
        for (j = 0; j < m; j++) GS[j] = m;
        int   i = 0;
        for (j = m - 1; j >= -1; j--)
            if (-1 == j || j + 1 == SS[j])
                for (; i < m - j - 1; i++)
                    if (GS[i] == m)
                        GS[i] = m - j - 1;
        for (j = 0; j < m - 1; j++)
            GS[m-SS[j] - 1] = m - j - 1;
        System.out.println("-- GS[] Table ---------------");
        for (j = 0; j < m; j++)  System.out.print("\t" + P.charAt(j));
        System.out.println();
        for (j = 0; j < m; j++)  System.out.print("\t" + GS[j]);
        System.out.println("\n");
        return(GS);
    }

    protected static void ShowProgress(
        String   T,
        String   P,
        int         i,
        int         j) {
        int         t;
        System.out.println("-------------------------------------------");
        for (t = 0; t < T.length(); t++)  System.out.print("\t" + T.charAt(t));
        System.out.print("\n");
        if (0 <= i + j) {
            for (t = 0; t < i + j; t++)  System.out.print("\t");
            System.out.print("\t|");
        }
        System.out.println();
        for (t = 0; t < i; t++) System.out.print("\t");
        for (t = 0; t < P.length(); t++)  System.out.print("\t" + P.charAt(t));
        System.out.print("\n");
        System.out.println();
    }

    protected static int MAX(int a, int b) {
        return (a > b) ? a : b;
    }

    protected static int MIN(int a, int b) {
        return (a < b) ? a : b;
    }
}
