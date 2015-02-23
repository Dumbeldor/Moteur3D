#include "Cube.h"

Cube::Cube(std::string nomFichier)
{
    std::fstream fichier(nomFichier.c_str(), std::fstream::in);

    if(fichier.is_open())
    {
        std::string ligne;

        while(getline(fichier, ligne))
        {
            if(ligne.compare(0, 3, "id ") == 0)
            {
                this->conteneurTextures.ajouter(ligne.begin() + 3, ligne.end());
            }
            else if(ligne.compare(0, 2, "x ") == 0)
                this->x = float((ligne.begin() + 2, ligne.end()));
        }
    }
}

Cube::~Cube()
{
    //dtor
}
