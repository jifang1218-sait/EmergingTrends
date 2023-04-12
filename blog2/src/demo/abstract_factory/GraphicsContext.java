package demo.abstract_factory;

interface GraphicsContext {
	void setPen(Pen p);
	Pen getPen();
	void setBrush(Brush b);
	Brush getBrush();

	void drawHouse(Point p);
	void drawTree(Point p);
	void drawCar(Point p);
	void drawImage(Point p, Image img);
}