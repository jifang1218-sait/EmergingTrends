package demo.abstract_factory;

class WBrush implements Brush {
	public WBrush() {
		System.out.println("WBrush::WBrush");
	}

	@Override
	public void setColor(RGB v) {
		System.out.println("WBrush::setColor");
  }

	@Override
	public void fillRect(Point topLeft, Point bottomRight) { 
		System.out.println("WBrush::fillRect");
	}
}
