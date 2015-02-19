#include "../include/Objet3DStatique.h"
/*
Objet3DStatique::Objet3DStatique(std::string nomFichier)
{
    //init

    this->positionX = 0.0;
    this->positionY = 0.0;
    this->positionZ = 0.0;
    this->angleHorizontal = 0.0;

    //Ouverture fichier
    std::fstream fichier(nomFichier.c_str(), std::fstream::in);

    //succès
    if(fichier.is_open())
    {
        std::string ligne;

        this->textures.get
        // Lecture de chaques lignes
        while(getline(fichier, ligne))
        {
            // Chargement nom
            if (0 == ligne.compare(0, 4, "nom "))
            {
                this->nom.assign(ligne.begin() + 4, ligne.end());
            }

            // Chargement d'une texture
            else if (0 == ligne.compare(0, 6, "image "))
            {
                // Lecture du nom de fichier de la texture
                std::string nomFichierTexture;
                nomFichierTexture.assign(ligne.begin() + 6, ligne.end());

                // Si la texture n'est pas deja creee
                if(find(this->textures.begin(), this->textures.end(), nomFichierTexture) != this->textures.end())
                {
                    // On cré la texture
                    this->texture(nomFichierTexture);
                }
            }

            // Debut de coordonnees
            else if (0 == ligne.compare(0, 1, "{"))
            {

            }

            // Commentaire et ligne vide
            else if (0 == ligne.compare(0, 1, "#") || ligne.empty())
            {
            }
        }
    }
    else
    {
        std::cout<<"Erreur lors de l'ouverture du fichier " << nomFichier.c_str() << std::endl;
    }
    }

}

void Objet3DStatique::texture(std::string nomTex)
{
    if(this->tex.loadFromFile(nomTex))
	{
		std::cout<<"Erreur chargement de la texture : metal.jpg"<<std::cout;
	}
	this->textures.push_back(this->tex);
	this->nomTex[nomTex] = this->textures.size() -1;
}

*/
