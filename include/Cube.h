#ifndef CUBE_H
#define CUBE_H

#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "ConteneurTextures.h"


class Cube
{
    public:
        Cube(std::string nomFichier);
        ~Cube();

        void dessiner();

    protected:
        float x;
        float y;
        float z;

        void texture(std::string);

        ConteneurTextures conteneurTextures;
        std::vector <std::string> textures;
        std::string nom;
};

#endif // CUBE_H
