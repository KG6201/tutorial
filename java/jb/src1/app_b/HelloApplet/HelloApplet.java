import java.awt.*;
import java.applet.*;

public class HelloApplet extends Applet {
    @Override
    public void paint(Graphics g) {
        FontMetrics f = g.getFontMetrics();
        int x = 0;
        int y = f.getAscent();
        g.drawString("HelloApplet", x, y);
    }
}
