












import dsa.
import java.io.

public class PM_KMP {






    public static int PM(String T, String P) {
        int[]    next = BuildNextImproved(P);
        int      i = 0;
        int      j = 0;
        while(j < P.length() && i < T.length()) {
            ShowProgress(T, P, i - j, j);
            ShowNextTable(next, i - j, P.length());
            System.out.println();
            if (0 > j || T.charAt(i) == P.charAt(j)) {
                i++;
                j++;
            } else
                j = next[j];
        }
        return(i - j);
    }

    protected static int[] BuildNext(String   P) {
        int[]    next = new int[P.length()];
        int      j = 0;
        int      t = next[0] = -1;
        while (j < P.length() - 1)
            if (0 > t || P.charAt(j) == P.charAt(t)) {
                j++;
                t++;
                next[j] = t;
            } else
                t = next[t];
        for (j = 0; j < P.length(); j++)  System.out.print("\t" + P.charAt(j));
        System.out.print("\n");
        ShowNextTable(next, 0, P.length());
        return(next);
    }

    protected static int[] BuildNextImproved(String P) {
        int[]    next = new int[P.length()];;
        int      j = 0;
        int      t = next[0] = -1;
        while (j < P.length() - 1)
            if (0 > t || P.charAt(j) == P.charAt(t)) {
                j++;
                t++;
                next[j] = (P.charAt(j) != P.charAt(t)) ? t : next[t];
            } else
                t = next[t];
        for (j = 0; j < P.length(); j++)  System.out.print("\t" + P.charAt(j));
        System.out.print("\n");
        ShowNextTable(next, 0, P.length());
        return(next);
    }


    protected static void ShowNextTable(
        int[] N,
        int      offset,
        int      length) {
        int      i;
        for (i = 0; i < offset; i++)   System.out.print("\t");
        for (i = 0; i < length; i++)   System.out.print("\t" + N[i]);
        System.out.print("\n\n");
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
}
