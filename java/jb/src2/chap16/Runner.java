class Runner extends Thread {
    private boolean running = true;
    public void stopRunning() {
        running = false;
    }
    @Override
    public void run() {
        while (running) {
            doCommand();
        }
    }
}
