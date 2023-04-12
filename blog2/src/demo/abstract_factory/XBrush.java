
class XBrush implements Brush {
	public XBrush() {
		System.out.println("XBrush::XBrush");
	}

	@Override
	public void setColor(RGB v) { 
		System.out.println("XBrush::setColor");
	}

	@Override
	public void fillRect(Point topLeft, Point bottomRight) { 
		System.out.println("XBrush::fillRect");
	}
}
