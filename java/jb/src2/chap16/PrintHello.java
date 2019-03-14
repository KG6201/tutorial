class LabelPrinter {
    String label = "no label";
    LabelPrinter(String label) {
        this.label = label;
    }
    @Override
    public static void run() {
        while (true) {
            System.out.println(label);
            Thread.sleep(1000);
        }
    }
}

public class PrintHello {
    public static void main(String[] args) {
        LabelPrinter th = new LabelPrinter("こんにちは！");
        th.start();
    }
}
