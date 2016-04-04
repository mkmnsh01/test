import java.io.*;
import java.util.*;
import java.math.*;
 
public class Main {
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tokenizer=null;
    public static void main(String[] args) throws IOException {
        new Main().execute();
    }
    int ni() throws IOException{
        return Integer.parseInt(ns());
    }
    long nl() throws IOException{
        return Long.parseLong(ns());
    }
    double nd() throws IOException {
        return Double.parseDouble(ns());
    }
    String ns() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(br.readLine());
        return tokenizer.nextToken();
    }
 
    String nline() throws IOException{
        tokenizer=null;
        return br.readLine();
    }
 
    int totalCases, testNum;
 
    BigInteger modexp(BigInteger x, long n, BigInteger mmod) {
        BigInteger ret = BigInteger.ONE;
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = ret.multiply(x).mod(mmod);
            }
            x = x.multiply(x).mod(mmod);
            n >>= 1;
        }
        return ret;
    }
    void execute() throws IOException{
        totalCases = ni();
        BigInteger  a, d, n, x;
        BigInteger dmod = BigInteger.valueOf(215372682525L);
        for(testNum = 1; testNum <= totalCases; testNum++) {
            a = BigInteger.valueOf(nl());
            d = BigInteger.valueOf(nl());
            long n_l = nl();
            n = BigInteger.valueOf(n_l);
            x = BigInteger.valueOf(nl());
            if (x == BigInteger.ONE) {
                BigInteger ans2 = a.multiply(n.add(BigInteger.ONE));
                ans2 = ans2.add(d.multiply(n.multiply(n.add(BigInteger.ONE)).divide(BigInteger.valueOf(2))));
                ans2 = ans2.mod(dmod);
                System.out.println(ans2);
                continue;
            }
            BigInteger modmul = x.subtract(BigInteger.ONE).pow(2);
            BigInteger nmod = dmod.multiply(modmul);
            BigInteger ans = a.multiply(x.subtract(BigInteger.ONE)).multiply(modexp(x, n_l + 1, nmod).subtract(BigInteger.ONE));
            ans = ans.add(d.multiply(x).multiply(modexp(x, n_l, nmod).subtract(BigInteger.ONE)));
            ans = ans.subtract(d.multiply(n).multiply(x.subtract(BigInteger.ONE)));
            ans = ans.add(nmod.pow(2));
            ans = ans.mod(nmod);
            ans = ans.divide(modmul);
            System.out.println(ans);
        }
 
    }
 
}
 
