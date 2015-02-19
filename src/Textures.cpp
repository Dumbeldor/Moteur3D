#include "../include/Textures.h""

Texture ConteneursTextures::ajouter(std::string nomFichier)
{
    Texture& texture = this->textures[nomFichier];

    //Si texture n'existe pas !
    if(texture.compteur)
    {
        //Creation texture
        this->chargerTexture(nomFichier, &texture.texture, &texture.largeur, &texture.hauteur);
    }
    //Utilisation texture en plus
    texture.compteur++;
    return texture;
}

void Textures::charger(const std::string nomFichier, sf::Texture texture)
{
    // Creationde la surface SDL a partir du fichier de la texture
    if (!Texture.LoadFromFile(nomFichier))
    {
        std::cout<<"Erreur chargement de la texture : " << nomFichier <<std::cout;
    }

}

void Textures::supprimer(std::string nomFichier)
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
