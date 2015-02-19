#include "chargerImg.h"

GLuint chargerTexture(std::string fichier)
{
    //identifiant de la texture initialisé à 0
    GLuint identifiant_texture = 0;

    //chargement de l'image dont le nom de fichier est reçu en paramètre
    sf::Texture tex;
    if (!tex.loadFromFile(fichier))
        return EXIT_FAILURE;

    //parametrage de la texture
    glGenTextures(1, &identifiant_texture);
    glBindTexture(GL_TEXTURE_2D, identifiant_texture);
    sf::Vector2u v = tex.getSize();
    int x = v.x;
    int y = v.y;
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, x, y, GL_RGBA, GL_UNSIGNED_BYTE, tex.GetPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    //renvoi de l'identifiant
    return identifiant_texture;
}
