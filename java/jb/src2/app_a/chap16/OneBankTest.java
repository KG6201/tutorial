public class OneBankTest extends Thread {
    @Override
    public void run() {
        while (true) {
            // 100円預け入れ
            OneBank.addMoney(100);
            // 100円引き出し
            OneBank.addMoney(-100);
        }
    }
    public static void main(String[] args) {
        new OneBankTest().start();
        new OneBankTest().start();
    }
}
