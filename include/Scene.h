#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <algorithm>

class Scene
{
	private:
		void gererEvenements();
		void animer();
		void dessiner();
		void dessinerTerrain();
		void afficher();
		void chargerTextures();
		void texture(std::string);
		void dessinerSkybox();

		sf::RenderWindow window;
		bool continuer;
		const unsigned short int LARGEUR_ECRAN = 1280,
		      			 HAUTEUR_ECRAN = 960;
	//	unsigned short int dex = 1;
	//	sf::Texture texture[dex];
		std::vector<sf::Texture> textures;
		std::vector<std::string> texCharger;
		sf::Texture tex;


	public:
		Scene();
		~Scene();
		void executer();
};

#endif // SCENE_H_INCLUDED
