package demo.abstract_factory;

interface Pen {
	void setColor(RGB v);
	void setWidth(int width);
	void drawLine(Point from, Point to);
	void drawRect(Point topLeft, Point bottomRight);
	void drawPolygon(Point[] polygon);
}