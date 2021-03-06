#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <map>

class ConteneursTextures{
    protected:
        typedef struct Texture
        {
            sf::Texture texture;
            int compteur;
            int largeur;
            int hauteur;
        };
        typedef std::map<std::string, Texture> Tex;
        Tex textures;


        void charger(const std::string, sf::Texture, int, int);

    public:
        Texture ajouter(std::string nomFichier);
        void supprimer(std::string nomFichier);
        Texture texture(std::string nomFichier);
}

#endif // TEXTURES_H_INCLUDED
