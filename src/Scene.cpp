#include "../include/Scene.h"



Scene::Scene()
{
	window.create(sf::VideoMode(this->LARGEUR_ECRAN, this->HAUTEUR_ECRAN, 32), "Test OpenGL", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(double)this->LARGEUR_ECRAN/this->HAUTEUR_ECRAN, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	this->continuer = true;
	this->chargerTextures();
}
Scene::~Scene()
{

}
void Scene::executer()
{
	while(this->continuer)
	{
		gererEvenements();
		animer();
		dessiner();
		afficher();
	}

}

void Scene::gererEvenements()
{
	sf::Event event;

	//tant qu'il y a des évènements à traiter...
	while (window.pollEvent(event))
	{
		// on regarde le type de l'évènement...
		switch (event.type)
		{
			// fenêtre fermée
			case sf::Event::Closed:
				this->continuer = false;
				break;

			case sf::Event::KeyPressed:
				break;

			default:
				break;
		}

	}
}

void Scene::afficher()
{
	glFlush();
	window.display();
}

void Scene::animer()
{ }

void Scene::dessiner()
{
	// Vidage de l'écran
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Placer camera !
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(3,4,2,0,0,0,0,0,1);

	//Dessins du terrain
	this->dessinerTerrain();

	//Dessins de la skybox
	this->dessinerSkybox();
}

void Scene::dessinerTerrain()
{
	sf::Texture::bind(&this->textures[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	// Position des sommets de la texture dans la scene
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(-10,-10,-1);
	glTexCoord2i(10,0);     glVertex3i(10,-10,-1);
	glTexCoord2i(10,10);    glVertex3i(10,10,-1);
	glTexCoord2i(0,10);     glVertex3i(-10,10,-1);
	// Fin de la "série" de quadrilatères
	glEnd();


	//Cube
	sf::Texture::bind(&this->textures[1]);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);  glVertex3d(1,1,0);
	glTexCoord2d(1,0);  glVertex3d(-1,1,0);
	glTexCoord2d(1,1);  glVertex3d(-1,1,2);
	glTexCoord2d(0,1);  glVertex3d(1,1,2);

	glTexCoord2d(0,1);  glVertex3d(1,-1,2);
	glTexCoord2d(0,0);  glVertex3d(1,-1,0);
	glTexCoord2d(1,0);  glVertex3d(1,1,0);
	glTexCoord2d(1,1);  glVertex3d(1,1,2);

	glTexCoord2d(0,1);  glVertex3d(-1,-1,2);
	glTexCoord2d(0,0);  glVertex3d(-1,-1,0);
	glTexCoord2d(1,0);  glVertex3d(1,-1,0);
	glTexCoord2d(1,1);  glVertex3d(1,-1,2);

	glTexCoord2d(0,1);  glVertex3d(-1,1,2);
	glTexCoord2d(0,0);  glVertex3d(-1,1,0);
	glTexCoord2d(1,0);  glVertex3d(-1,-1,0);
	glTexCoord2d(1,1);  glVertex3d(-1,-1,2);


	glEnd();


}

void Scene::dessinerSkybox()
{
    sf::Texture::bind(&this->textures[2]);
    glBegin(GL_QUADS);

    glTexCoord2d(0, 1); glVertex3d(-1, -1, 1);
    glTexCoord2d(0, 0); glVertex3d(-1, -1, -1);
    glTexCoord2d(1, 0); glVertex3d(-1, 1, -1);
    glTexCoord2d(1, 1); glVertex3d(-1, 1, 1);

    glEnd();

    sf::Texture::bind(&this->textures[4]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0); glVertex3d(1, -1, -1);
    glTexCoord2d(1, 0); glVertex3d(-1, -1, -1);
    glTexCoord2d(1, 1); glVertex3d(-1, -1, 1);
    glTexCoord2d(0, 1); glVertex3d(1, -1, 1);
    glEnd();

    sf::Texture::bind(&this->textures[7]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 1); glVertex3d(-1, -1, -1);
    glTexCoord2d(0, 0); glVertex3d(1, -1, -1);
    glTexCoord2d(1, 0); glVertex3d(1, 1, -1);
    glTexCoord2d(1, 1); glVertex3d(-1, 1, -1);
    glEnd();

}
void Scene::chargerTextures()
{
	this->texture("img/metal.jpg");     // metal : 0
	this->texture("img/metal.jpg"); //La même texture peut être chargé qu'une seul fois !
	this->texture("img/glass.jpg");     // glass : 1
	this->texture("img/skybox/nord.bmp");      // nord : 2
	this->texture("img/skybox/sud.bmp");       // sud: 3
	this->texture("img/skybox/ouest.bmp");     //  ouest: 4
	this->texture("img/skybox/est.bmp");       // est : 5
	this->texture("img/skybox/haut.bmp");      // haut : 6
	this->texture("img/skybox/bas.bmp");       // bas :7
}

void Scene::texture(std::string nomTex)
{
    if (find (texCharger.begin(), texCharger.end(), nomTex) != texCharger.end())
        std::cout << "Texture : " << nomTex << " deja charge" << std::endl;
    else
    {
        if(!this->tex.loadFromFile(nomTex))
        {
            std::cout<<"Erreur chargement de la texture : " << nomTex <<std::cout;
        }
        this->textures.push_back(this->tex);
        this->texCharger.push_back(nomTex);
    }
}
