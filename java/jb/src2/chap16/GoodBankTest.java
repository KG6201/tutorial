public class GoodBankTest extends Thread {
    GoodBank bank;
    public GoodBankTest(GoodBank bank) {
        this.bank = bank;
    }
    @Override
    public void run() {
        while (true) {
            // 100円預け入れ
            bank.addMoney(100);
            // 100円引き出し
            bank.addMoney(-100);
        }
    }
    public static void main(String[] args) {
        GoodBank bank = new GoodBank();   // GoodBankを生成
        new GoodBankTest(bank).start();
        new GoodBankTest(bank).start();
    }
}
