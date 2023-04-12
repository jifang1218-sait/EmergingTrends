package demo.abstract_factory;

interface Image {
	void rotate(double rad);
	void scale(double factor);
	void transform(Matrix m);
}