#include "Cube.h"

Cube::Cube(GLfloat rotationXnew, GLfloat rotationYnew, bool turnMasknew, bool turnFuckednew) {
    rotationX = rotationXnew;
    rotationY = rotationYnew;
    turnMask = turnMasknew;
    turnFucked = turnFuckednew;
}

void Cube::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    const GLfloat rotationSpeed = 10;

    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_UP:
            rotationX -= rotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            rotationX += rotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            rotationY += rotationSpeed;
            break;
        case GLFW_KEY_LEFT:
            rotationY -= rotationSpeed;
            break;
        case GLFW_KEY_1:
            turnMask = !turnMask;
            break;
        case GLFW_KEY_2:
            turnFucked = !turnFucked;
            break;
        }
    }

    std::cout << key << std::endl;
    std::cout << rotationX << " " << rotationY << std::endl;
}

void Cube::DrawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength) {
    GLfloat halfSideLength = edgeLength * 0.5f;

    static const GLfloat MainCube[] = {
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,

        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,

        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,

        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength
    };

    GLfloat CubeEdges[] = {
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,

        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength
    };

    static const GLfloat CubeColor[] = {
        0.583f,  0.771f,  0.014f,
        0.609f,  0.115f,  0.436f,
        0.327f,  0.483f,  0.844f,
        0.822f,  0.569f,  0.201f,
        0.435f,  0.602f,  0.223f,
        0.310f,  0.747f,  0.185f,
        0.597f,  0.770f,  0.761f,
        0.559f,  0.436f,  0.730f,
        0.359f,  0.583f,  0.152f,
        0.483f,  0.596f,  0.789f,
        0.559f,  0.861f,  0.639f,
        0.195f,  0.548f,  0.859f,
        0.014f,  0.184f,  0.576f,
        0.771f,  0.328f,  0.970f,
        0.406f,  0.615f,  0.116f,
        0.676f,  0.977f,  0.133f,
        0.971f,  0.572f,  0.833f,
        0.140f,  0.616f,  0.489f,
        0.997f,  0.513f,  0.064f,
        0.945f,  0.719f,  0.592f,
        0.543f,  0.021f,  0.978f,
        0.279f,  0.317f,  0.505f,
        0.167f,  0.620f,  0.077f,
        0.347f,  0.857f,  0.137f,
        0.055f,  0.953f,  0.042f,
        0.714f,  0.505f,  0.345f,
        0.783f,  0.290f,  0.734f,
        0.722f,  0.645f,  0.174f,
        0.302f,  0.455f,  0.848f,
        0.225f,  0.587f,  0.040f,
        0.517f,  0.713f,  0.338f,
        0.053f,  0.959f,  0.120f,
        0.393f,  0.621f,  0.362f,
        0.673f,  0.211f,  0.457f,
        0.820f,  0.883f,  0.371f,
        0.982f,  0.099f,  0.879f
    };

    if (turnMask) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, CubeEdges);
        glDrawArrays(GL_QUADS, 0, 24);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, MainCube);
    glColorPointer(3, GL_FLOAT, 0, CubeColor);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

}

int Cube::delay(int milliseconds) {
    clock_t goal = milliseconds + clock();
    while (goal > clock());
    return 1;
}

bool Cube::MainLoopDraw(bool drawConsole){
    srand(time(nullptr));

    HWND consoleWindow;
    AllocConsole();
    consoleWindow = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(consoleWindow, drawConsole);

    GLFWwindow* window;

    if (!glfwInit())
        return false;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cube", NULL, NULL);

    //glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);


    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (!window) {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, screenWidth, screenHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -500);

        if (!turnFucked) {
            rotationX += rand() % 4 + 2;
            rotationY = rotationX;
        }
        else {
            rotationX += rand() % 4 + 2;
            rotationY += rotationX;
        }

        std::cout << rotationX << " " << rotationY << std::endl;
        delay(50);
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);

        glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

        DrawCube(halfScreenWidth, halfScreenHeight, 0, 200);

        glPopMatrix();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return true;
}