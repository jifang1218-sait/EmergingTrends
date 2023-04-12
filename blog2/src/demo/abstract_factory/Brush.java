package demo.abstract_factory;

interface Brush {
	void setColor(RGB v);
	void fillRect(Point topLeft, Point bottomRight);
}
