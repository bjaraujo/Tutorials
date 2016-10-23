
#include <iostream>

class Triangle;
class Rectangle;

class Renderer {

public:
	virtual void startRendering() = 0;
	virtual void endRendering() = 0;
	virtual void render(Triangle* aTriangle) = 0;
	virtual void render(Rectangle* aRectangle) = 0;

};

class OpenGLRenderer : public Renderer {

public:

	virtual void startRendering() {

		std::cout << "Start rendering scene with OpenGL" << std::endl;

	};

	virtual void render(Triangle* aTriangle) {

		std::cout << "--> Rendering triangle" << std::endl;

	};

	virtual void render(Rectangle* aRectangle) {

		std::cout << "--> Rendering rectangle" << std::endl;

	};

	virtual void endRendering() {

		std::cout << "End rendering scene" << std::endl;

	};

};

class DirectXRenderer : public Renderer {

public:

	virtual void startRendering() {

		std::cout << "Start rendering scene with DirectX" << std::endl;

	};

	virtual void render(Triangle* aTriangle) {

		std::cout << "--> Rendering triangle" << std::endl;

	};

	virtual void render(Rectangle* aRectangle) {

		std::cout << "--> Rendering rectangle" << std::endl;

	};

	virtual void endRendering() {

		std::cout << "End rendering scene" << std::endl;

	};

};

class Shape {

public:

	virtual void draw(Renderer& aRenderer) = 0;

};

class Triangle : public Shape {

public:

	virtual void draw(Renderer& aRenderer) {

		aRenderer.render(this);

	};

};

class Rectangle : public Shape {

public:

	virtual void draw(Renderer& aRenderer) {

		aRenderer.render(this);

	};

};

void main()
{

	Triangle aTriangle;
	Rectangle aRectangle;

	OpenGLRenderer anOpenGLRenderer;

	anOpenGLRenderer.startRendering();

	aTriangle.draw(anOpenGLRenderer);
	aRectangle.draw(anOpenGLRenderer);

	anOpenGLRenderer.endRendering();

	DirectXRenderer aDirectXRenderer;

	aDirectXRenderer.startRendering();

	aTriangle.draw(aDirectXRenderer);
	aRectangle.draw(aDirectXRenderer);

	aDirectXRenderer.endRendering();

	system("pause");

}