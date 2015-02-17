#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#define LARGEUR_ECRAN 1280
#define HAUTEUR_ECRAN 960

sf::RenderWindow window;
double angleZ = 0;
double angleX = 0;
sf::Texture test;
sf::Texture texture2;
sf::Texture triangle;


void Dessiner();

int main(int argc, char *argv[])
{
	//const unsigned short int LARGEUR_ECRAN=640, HAUTEUR_ECRAN=480;
	window.create(sf::VideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32), "Test OpenGL", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(double)LARGEUR_ECRAN/HAUTEUR_ECRAN, 1, 1000);
	glEnable(GL_DEPTH_TEST);

	//texture
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	if(!test.loadFromFile("glass.jpg"))
	{
	}
	if(!texture2.loadFromFile("metal.jpg"))
	{
	}
	if(!triangle.loadFromFile("triangle.jpg"))
		std::cout << "erreur chargement texture triangle.jpg"<<std::endl;


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// on stoppe le programme
				window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				// on ajuste le viewport lorsque la fenêtre est redimensionnée
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}
		angleZ++;
		//angleX++;
		Dessiner();

	}


	return 0;
}

void Dessiner()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );

	gluLookAt(3,4,2,0,0,0,0,0,1);

	glRotated(angleZ,0,0,1);
	glRotated(angleX,1,0,0);

	//texture

	sf::Texture::bind(&test);
	glBegin(GL_QUADS);
	glTexCoord2d(0,1);  glVertex3d(1,1,1);
	glTexCoord2d(0,0);  glVertex3d(1,1,-1);
	glTexCoord2d(1,0);  glVertex3d(-1,1,-1);
	glTexCoord2d(1,1);  glVertex3d(-1,1,1);

	glTexCoord2d(0,1);  glVertex3d(1,-1,1);
	glTexCoord2d(0,0);  glVertex3d(1,-1,-1);
	glTexCoord2d(1,0);  glVertex3d(1,1,-1);
	glTexCoord2d(1,1);  glVertex3d(1,1,1);

	glTexCoord2d(0,1);  glVertex3d(-1,-1,1);
	glTexCoord2d(0,0);  glVertex3d(-1,-1,-1);
	glTexCoord2d(1,0);  glVertex3d(1,-1,-1);
	glTexCoord2d(1,1);  glVertex3d(1,-1,1);

	glTexCoord2d(0,1);  glVertex3d(-1,1,1);
	glTexCoord2d(0,0);  glVertex3d(-1,1,-1);
	glTexCoord2d(1,0);  glVertex3d(-1,-1,-1);
	glTexCoord2d(1,1);  glVertex3d(-1,-1,1);


	glEnd();

	sf::Texture::bind(&triangle);
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0,0);      glVertex3d(4,1,-1);
	glTexCoord2d(1,0);      glVertex3d(2,1,-1);
	glTexCoord2d(0.5,1);    glVertex3d(3,0,1);

	glTexCoord2d(0,0);      glVertex3d(4,-1,-1);
	glTexCoord2d(1,0);      glVertex3d(2,-1,-1);
	glTexCoord2d(0.5,1);    glVertex3d(3,0,1);

	glTexCoord2d(0,0);      glVertex3d(4,1,-1);
	glTexCoord2d(1,0);      glVertex3d(4,-1,-1);
	glTexCoord2d(0.5,1);    glVertex3d(3,0,1);

	glTexCoord2d(0,0);      glVertex3d(2,-1,-1);
	glTexCoord2d(1,0);      glVertex3d(2,1,-1);
	glTexCoord2d(0.5,1);    glVertex3d(3,0,1);





	glEnd();





	sf::Texture::bind(&texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(-10,-10,-1);
	glTexCoord2i(10,0);     glVertex3i(10,-10,-1);
	glTexCoord2i(10,10);    glVertex3i(10,10,-1);
	glTexCoord2i(0,10);     glVertex3i(-10,10,-1);
	glEnd();

	/*	glBegin(GL_QUADS);


		glColor3ub(255,0,0);
		glVertex3d(1,1,1);
		glVertex3d(1,1,-1);
		glVertex3d(-1,1,-1);
		glVertex3d(-1,1,1);

		glColor3ub(0,255,0);
		glVertex3d(1,-1,1);
		glVertex3d(1,-1,-1);
		glVertex3d(1,1,-1);
		glVertex3d(1,1,1);

		glColor3ub(0,0,255);
		glVertex3d(-1,-1,1);
		glVertex3d(-1,-1,-1);
		glVertex3d(1,-1,-1);
		glVertex3d(1,-1,1);

		glColor3ub(255,255,0); //face jaune
		glVertex3d(-1,1,1);
		glVertex3d(-1,1,-1);
		glVertex3d(-1,-1,-1);
		glVertex3d(-1,-1,1);

		glColor3ub(0,255,255); //face cyan
		glVertex3d(1,1,-1);
		glVertex3d(1,-1,-1);
		glVertex3d(-1,-1,-1);
		glVertex3d(-1,1,-1);

		glColor3ub(255,0,255); //face magenta
		glVertex3d(1,-1,1);
		glVertex3d(1,1,1);
		glVertex3d(-1,1,1);
		glVertex3d(-1,-1,1);

		glEnd();
		*/

	glFlush();
	window.display();
}
