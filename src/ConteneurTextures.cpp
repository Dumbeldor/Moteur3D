#include "../include/ConteneurTextures.h""

ConteneurTextures::Textures ConteneurTextures::textures;


ConteneurTextures::Texture ConteneurTextures::ajouter(std::string nomFichier)
{
    Texture& texture = this->textures[nomFichier];

    //Si texture n'existe pas !
    if(texture.compteur)
    {
        //Creation texture
        this->charger(nomFichier, texture.texture, texture.largeur, texture.hauteur);
    }
    //Utilisation texture en plus
    texture.compteur++;
    return texture;
}

void ConteneurTextures::charger(const std::string nomFichier, sf::Texture texture, int l, int h)
{
    // Creationde la surface SFML a partir du fichier de la texture
    if((l / 2) != 0)
        std::cout << "Attention : la largeur doit être une puissance de 2" << std::endl;
    if((h / 2) != 0)
        std::cout << "Attention : la hauteur doit être une puissance de 2" << std::endl;
    if (!texture.loadFromFile(nomFichier))
    {
        std::cout<<"Erreur chargement de la texture : " << nomFichier <<std::cout;
    }

}

void ConteneurTextures::supprimer(std::string nomFichier)
{
    // Recuperation de la texture
    Texture texture = this->textures[nomFichier];

    // Si la texture existe
    if (texture.compteur != 0)
    {
        texture.compteur--;
    }

    // Si la texture n'est plus utilisée
    if (0 == texture.compteur)
    {
        this->textures.erase(nomFichier);
    }
}

ConteneurTextures::Texture ConteneurTextures::texture(std::string nomFichier)
{
    return this->textures[nomFichier];
}


