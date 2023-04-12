
class XGraphicsContext implements GraphicsContext {
	// actually, fields can be saved into an abstract class 
	// between WGraphicsContext and GraphicsContext. 
	private Pen _pen; 
	private Brush _brush;

	public XGraphicsContext() {
		System.out.println("XGraphicsContext::XGraphicsContext");
	}

	@Override
	public void setPen(Pen p) { _pen = p; }

	@Override
	public Pen getPen() { return _pen; }

	@Override
	public void setBrush(Brush b) { _brush = b; }

	@Override
	public Brush getBrush() { return _brush; }

	@Override
	public void drawHouse(Point p) { 
		System.out.println("XGraphicsContext::drawHouse");
	}

	@Override
	public void drawTree(Point p) { 
		System.out.println("XGraphicsContext::drawTree");
	}

	@Override
	public void drawCar(Point p) { 
		System.out.println("XGraphicsContext::drawCar");
	}

	@Override
	public void drawImage(Point p, Image img) { 
		System.out.println("XGraphicsContext::drawImage");
	}
}