package demo.abstract_factory;

interface GraphicsFactory {
	Pen createPen();
	Brush createBrush();
	Image createImage();
	GraphicsContext createGraphicsContext();
}
