public class CalcData {
    public static void main(String[] args) {
        double[] data = { 3.1, 4.1, 5.9, 2.6, 5.3, 9.7 };
        double sum = 0.0;
        for (double d : data) {
            sum += d;
        }
        System.out.println("sum = " + sum);
    }
}
