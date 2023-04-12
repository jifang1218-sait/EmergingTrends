// *nix platform
package demo.abstract_factory;

class XPen implements Pen {
	public XPen() {
		System.out.println("XPen::XPen");
	}

	@Override
	public void setColor(RGB v) { 
		System.out.println("XPen::SetColor");
	}

	@Override
	public void setWidth(int width) { 
		System.out.println("XPen::setWidth");
	}

	@Override
	public void drawLine(Point from, Point to) { 
		System.out.println("XPen::drawLine");
	}

	@Override
	public void drawRect(Point topLeft, Point bottomRight) { 
		System.out.println("XPen::drawRect");
	}
}
