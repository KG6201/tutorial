import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class ColorApplet extends Applet implements MouseListener, MouseMotionListener {
    private int mousex = 0;
    private int mousey = 0;
    private final int R = 10;
    private int dr = 3;
    private int dg = 5;
    private int db = 7;
    private Color color = Color.white;

    private void nextColor() {
        int r = color.getRed();
        int g = color.getGreen();
        int b = color.getBlue();
        if (r + dr >= 256 || r + dr < 0) dr = -dr;
        if (g + dg >= 256 || g + dg < 0) dg = -dg;
        if (b + db >= 256 || b + db < 0) db = -db;
        r = (r + dr) % 256;
        g = (g + dg) % 256;
        b = (b + db) % 256;
        color = new Color(r, g, b);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        mousex = e.getX();
        mousey = e.getY();
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) {
    }

    @Override
    public void mouseClicked(MouseEvent e) {
    }

    @Override
    public void mouseEntered(MouseEvent e) {
    }

    @Override
    public void mouseExited(MouseEvent e) {
    }

    @Override
    public void mousePressed(MouseEvent e) {
        Dimension d = getSize();
        Graphics g = getGraphics();
        mousex = e.getX();
        mousey = e.getY();
        g.setColor(Color.white);
        g.fillRect(0, 0, d.width, d.height);
        repaint();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    @Override
    public void paint(Graphics g) {
        g.setColor(color);
        g.drawOval(mousex - R, mousey - R, 2 * R, 2 * R);
        nextColor();
    }

    @Override
    public void init() {
        addMouseListener(this);
        addMouseMotionListener(this);
    }
}
