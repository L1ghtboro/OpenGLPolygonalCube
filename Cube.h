#pragma once
#include "Modules.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

class Cube {
	GLfloat rotationX;
	GLfloat rotationY;
	bool turnMask;
	bool turnFucked;
	int counterTurnes = 1;
	int delay(int milliseconds);
public:
	Cube(GLfloat rotationXnew, GLfloat rotationYnew, bool turnMasknew, bool turnFuckednew);
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
	bool MainLoopDraw(bool drawConsole);
};