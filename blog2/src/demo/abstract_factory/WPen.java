// Windows platform
package demo.abstract_factory;

class WPen implements Pen {
	public WPen() {
		System.out.println("WPen::WPen");
	}

	@Override
	public void setColor(RGB v) { 
		System.out.println("WPen::setColor"); 
	}

	@Override
	public void setWidth(int width) { 
		System.out.println("WPen::setWidth");
	}

	@Override
	public void drawLine(Point from, Point to) {
		System.out.println("WPen::drawLine");
	}

	@Override
	public void drawRect(Point topLeft, Point bottomRight) {
		System.out.println("WPen::drawRect");
	}
}
