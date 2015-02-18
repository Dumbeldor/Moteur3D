#ifndef OBJET3DSTATIQUE_H_INCLUDED
#define OBJET3DSTATIQUE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

class Objet3DStatique
{
    public:
        Objet3DStatique(std::string);
        void dessiner3D();

        //Position
        float16 positionX;
        float16 positionY;
        float16 positionZ;

        //Angle  vertical en Z
        float16 angleHorizontal;

    private:
        std::vector<sf::Texture> textures;
		sf::Texture tex;

}


#endif // OBJET3DSTATIQUE_H_INCLUDED
