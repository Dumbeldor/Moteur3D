#ifndef OBJET3DSTATIQUE_H_INCLUDED
#define OBJET3DSTATIQUE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "ConteneurTextures.h"

class Objet3DStatique
{
    public:
        Objet3DStatique(std::string);
        ~Objet3DStatique();
        void dessiner3D();

        //Position
        float positionX;
        float positionY;
        float positionZ;

        //Angle  vertical en Z
        float angleHorizontal;

    private:
        void texture(std::string);

        ConteneurTextures conteneurTextures;
        std::vector <std::string> textures;
		std::string nom;

};


#endif // OBJET3DSTATIQUE_H_INCLUDED
