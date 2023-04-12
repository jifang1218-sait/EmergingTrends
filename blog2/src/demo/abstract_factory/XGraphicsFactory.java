package demo.abstract_factory;

class XGraphicsFactory implements GraphicsFactory {
	public XGraphicsFactory() {
		System.out.println("XGraphicsFactory::XGraphicsFactory");
	}

	@Override
	public Pen createPen() {
		return new XPen();
	}

	@Override
	public Brush createBrush() {
		return new XBrush();
	}

	@Override
	public Image createImage() {
		return new XImage();
	}

	@Override
	public GraphicsContext createGraphicsContext() {
		return new XGraphicsContext();
	}
}