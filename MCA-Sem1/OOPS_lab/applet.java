import java.applet.Applet;
import java.awt.Graphics;
import java.awt.*;

/*<applet code="applet.class" width="350" height="150"> </applet>*/
public class applet extends Applet {
	public void init() {
		setBackground(Color.RED);
		System.out.println("init() method is called");
	}

	public void start() {
		System.out.println("Start() method is called");
	}

	public void paint(Graphics g) {
		System.out.println("Paint(() method is called");
	}

	public void stop() {
		System.out.println("Stop() method is Called");
	}

	public void destroy() {
		System.out.println("Destroy() method is Called");
	}
}