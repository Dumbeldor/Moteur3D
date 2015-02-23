/*
 Programme :  Moteur de jeu 3D
 But :   Apprentissage
 Auteur : Vincent Glize
 Remarques : Programme sans grande prétention.
*/

#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "include/Scene.h"




int main(int argc, char *argv[])
{
	//Executation scene
	std::cout << "test" << std::endl;
	Scene scene;
	scene.executer();



	return 0;
}
