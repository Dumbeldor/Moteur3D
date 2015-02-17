#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>  

class Scene
{
	private:
		void gererEvenements();
		void animer();
		void dessiner();
		void dessinerTerrain();
		void afficher();
		void chargerTextures();

		sf::RenderWindow window;
		bool continuer;
		const unsigned short int LARGEUR_ECRAN = 1280, 
		      			 HAUTEUR_ECRAN = 960;
	//	unsigned short int dex = 1;
	//	sf::Texture texture[dex];
		std::vector<sf::Texture> textures;
		sf::Texture texture;
		

	public:
		Scene();
		~Scene();
		void executer();
};

#endif // SCENE_H_INCLUDED
