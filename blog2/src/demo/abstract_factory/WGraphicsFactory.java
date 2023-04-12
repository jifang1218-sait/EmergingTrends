package demo.abstract_factory;

class WGraphicsFactory implements GraphicsFactory {
	public WGraphicsFactory() {
		System.out.println("WGraphicsFactory::WGraphicsFactory");
	}

	@Override
	public Pen createPen() {
		return new WPen();
	}

	@Override
	public Brush createBrush() {
		return new WBrush();
	}

	@Override
	public Image createImage() {
		return new WImage();
	}

	@Override
	public GraphicsContext createGraphicsContext() {
		return new WGraphicsContext();
	}
}
