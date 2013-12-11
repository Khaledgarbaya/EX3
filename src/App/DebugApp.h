#ifndef DEBUGAPP_H
#define DEBUGAPP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

namespace EX3
{
    class DebugApp
    {
        public:
            DebugApp();
            ~DebugApp();
            void Run();

        private:
            void InitGL();
            int SetViewport(int width, int height);
            void Render();

            SDL_Renderer* displayRenderer;
    };
}

#endif // DEBUGAPP_H
