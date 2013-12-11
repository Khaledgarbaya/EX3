#include "DebugApp.h"

using namespace EX3;

DebugApp::DebugApp()
{
}

DebugApp::~DebugApp()
{
}

void DebugApp::Run()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* displayWindow;

    SDL_RendererInfo displayRendererInfo;
    SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &displayWindow, &displayRenderer);
    SDL_GL_CreateContext( displayWindow);
    SDL_GetRendererInfo(displayRenderer, &displayRendererInfo);
    /*TODO: Check that we have OpenGL */
    if ((displayRendererInfo.flags & SDL_RENDERER_ACCELERATED) == 0 ||
        (displayRendererInfo.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
        /*TODO: Handle this. We have no render surface and not accelerated. */
    }

    InitGL();

    SetViewport(800, 600);

    Render();

    SDL_Delay(5000);
    SDL_Quit();
}

void DebugApp::InitGL()
{
    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    /* Depth buffer setup */
    glClearDepth( 1.0f );

    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

int DebugApp::SetViewport(int width, int height)
{
    /* Height / width ration */
    GLfloat ratio;

    /* Protect against a divide by zero */
    if ( height == 0 ) {
        height = 1;
    }

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return 1;
}

void DebugApp::Render()
{
    /* Set the background black */
    glClearColor( 0.3f, 0.6f, 0.9f, 1.0f );
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    /* Move Left 1.5 Units And Into The Screen 6.0 */
    glLoadIdentity();

    glTranslatef( 0.0f, 0.0f, -3.0f );

    glBegin( GL_QUADS );                /* Draw A Quad */
      glColor4f( 1.0f, 0.0f, 0.0f, 1.0f);
      glVertex3f( -1.0f,  1.0f, 0.0f ); /* Top Left */
      glColor4f( 0.0f, 1.0f, 0.0f, 1.0f);
      glVertex3f(  1.0f,  1.0f, 0.0f ); /* Top Right */
      glColor4f( 0.0f, 0.0f, 1.0f, 1.0f);
      glVertex3f(  1.0f, -1.0f, 0.0f ); /* Bottom Right */
      glColor4f( 0.0f, 0.0f, 1.0f, 1.0f);
      glVertex3f( -1.0f, -1.0f, 0.0f ); /* Bottom Left */
    glEnd( );                           /* Done Drawing The Quad */

    SDL_RenderPresent(displayRenderer);
}
