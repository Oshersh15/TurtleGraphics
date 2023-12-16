// This is the main SDL include file
#include <SDL2/SDL.h>
#ifdef _WIN32
#include <windows.h>
#endif

// include OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

// necessary C standard library includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINWIDTH    800
#define WINHEIGHT   600

int level;

typedef struct coordinate
{
	double x;
	double y;
} coord; // Struct is essentially a class, you are definining certain types of data which it will accept, ie create a variable from the coordinate struct called coord, you can then use coord.x/coord.y and assign the double data type to these two properties.

typedef struct turtletype
{
    coord current_pos;
    double move_target;
    double move_current;
	short pen;
    double angle;
} turtledef;

turtledef turtle;

void turtle_initialize()
{
	turtle.current_pos.x = WINWIDTH/2;
	turtle.current_pos.y = WINHEIGHT/2;
	turtle.angle = 0;
	turtle.pen = 1;
}

void pen_up()
{
	turtle.pen = 1;
}

void pen_down()
{
	turtle.pen = 0;
}

void turn(double inAngle)
{
	turtle.angle = turtle.angle + inAngle;
	if (turtle.angle < -180) turtle.angle = turtle.angle + 360;
	if (turtle.angle > 180) turtle.angle = turtle.angle - 360;
}

void move(double length)
{
	turtle.move_target = length;
	turtle.move_current = 0;
}

coord draw_line(coord start, double length, double angle)
{
	double angle_rad = (angle/180) * M_PI;
	coord end;
	end.x = start.x + (cos(angle_rad) * length);
	end.y = start.y + (sin(angle_rad) * length);

	GLint matrixmode=0;
	glGetIntegerv(GL_MATRIX_MODE, &matrixmode); /* get current matrix mode */
	glColor3d(0.5,0.5,0.5);
	glBegin(GL_LINE_LOOP);
		glVertex3d(start.x, start.y, 0.0f);
		glVertex3d(end.x, end.y, 0.0f);
	glEnd();
	glPopMatrix(); /* restore previous modelview matrix */
	glMatrixMode(matrixmode); /* set the previous matrix mode */

	return end;

}

int moving(SDL_Window *window)
{
	if(turtle.move_current < turtle.move_target)
	{
		turtle.move_current++;
		turtle.current_pos = draw_line(turtle.current_pos, 1, turtle.angle);
		SDL_GL_SwapWindow( window );
		return 1;
	}
	else if(turtle.move_current > turtle.move_target)
	{
		turtle.move_current--;
		turtle.current_pos = draw_line(turtle.current_pos, -1, turtle.angle);
		SDL_GL_SwapWindow( window );
		return 1;	
	}
	return 0;
}

void set1(SDL_Window *window)
{
	int startLine = 20;
	for(int x=0; x<3; x++)
	{
		for(int i=1; i<9; i++)
		{
			switch(level)
			{
				case 1:
					pen_down();
					turn(-120);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 2:
					pen_down();
					turn(-240);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 3:
					pen_down();
					turn(120);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 4:
					pen_down();
					turn(-240);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 5:
					pen_down();
					turn(120);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 6:
					pen_down();
					turn(-240);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 7:
					pen_down();
					turn(120);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 8:
					pen_down();
					turn(-240);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				default:
					level = 0;
					pen_up();
			}
	level=1;
		}
	}
}

void set2(SDL_Window *window)
{
	int startLine = 20;
	for(int x=0; x<4; x++)
	{
		for(int i=1; i<8; i++)
		{
			switch(level)
			{
				case 1:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 2:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 3:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 4:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 5:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 6:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 7:
					pen_down();
					turn(-90);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				default:
					level = 0;
					pen_up();
			}
	level=1;
		}
	}
}

void set3(SDL_Window *window)
{
	int startLine = 20;
	for(int x=0; x<5; x++)
	{
		for(int i=1; i<9; i++)
		{
			switch(level)
			{
				case 1:
					pen_down();
					turn(-70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 2:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 3:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 4:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 5:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 6:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 7:
					pen_down();
					turn(-80);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				case 8:
					pen_down();
					turn(70);
					move(startLine*i);

					while(moving(window)) SDL_Delay(10);
					level++;
					break;
				default:
					level = 0;
					pen_up();
			}
	level=1;
		}
	}
}


int main(int argc, char *argv[])
{
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = WINWIDTH;
	int winHeight = WINHEIGHT;
	int go; // main loop active flag
	int hThrust=0,vThrust=0;
	char winTitle[80]="Osher's Turtle Graphics!!!";

	turtle_initialize();

	/* This is our initialisation phase

	   SDL_Init is the main initialisation function for SDL
	   It takes a 'flag' parameter which we use to tell SDL what systems we are going to use
	   Here, we want to initialise everything, so we give it the flag for this.
	   This function also returns an error value if something goes wrong,
	   so we can put this straight in an 'if' statement to check and exit if need be */
	if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
		perror("Whoops! Something went very wrong, cannot initialise SDL :("); /* Something went very wrong in the initialisation, all we can do is exit */
		perror(SDL_GetError());
		return -1;
	}

	int choice;
	int colour;
	printf("choose a background colour: 1 for Black / 2 for Red / 3 for Green / 4 for Blue \n");
	fflush(stdout);
	scanf("%d", &colour);
	printf("pick a number: 1 / 2 / 3 \n");
	fflush(stdout);
	scanf("%d", &choice);

	if(choice>0) level=1;
	else level=0;

	SDL_Window *window = SDL_CreateWindow(winTitle, winPosX, winPosY,winWidth, winHeight,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN); /* Now we have got SDL initialised, we are ready to create an OpenGL window! */
	SDL_Renderer *renderer;
	//window = SDL_CreateWindow("SDL_RenderClear",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);

	switch(colour)
	{
		case 1:
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			break;
		case 4:
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
			break;
		default:
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
	}


	if( window == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		exit(EXIT_FAILURE); /* crash out if there has been an error */
	}
	
	/* Use OpenGL 1.5 compatibility */
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 1 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 5 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY );
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16); /* set up Z-Buffer */
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); /* enable double buffering */
	
	/* SDL_GLContext is the OpenGL rendering context - this is the equivalent to the SDL_Renderer when drawing pixels to the window */
	SDL_GLContext context = SDL_GL_CreateContext( window );
	if( context == NULL )
	{
		printf( "OpenGL Rendering Context could not be created! SDL Error: %s\n", SDL_GetError() );
		exit(EXIT_FAILURE); /* crash out if there has been an error */
	}

	/* Set up the parts of the scene that will stay the same for every frame. */
	glFrontFace(GL_CCW);     /* Enforce counter clockwise face ordering (to determine front and back side) */
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_FLAT); /* enable flat shading - Gouraud shading would be GL_SMOOTH */

	/* Set up the camera/viewing volume (projection matrix) and the timer */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)(winWidth-1),0.0,(GLdouble)(winHeight-1));
	glViewport(0,0,winWidth,winHeight);


	/* We are now preparing for our main loop. This loop will keep going round until we exit from our program by changing the int 'go' to the value false (0). */
	go = 1;
	while( go )
	{	
		/* Here we are going to check for any input events. Basically when you press the keyboard or move the mouse, the parameters are stored as something called an 'event' or 'message'. SDL has a queue of events. */	
		SDL_Event incomingEvent;
		double fraction=0.0;

		/* SDL_PollEvent will check if there is an event in the queue - this is the program's 'message pump'.
		If there is nothing in the queue it will not sit and wait around for an event to come along. Instead for an empty queue it will simply return 'false' (0).
		If there is an event, the function will return 'true' (!=0) and it will fill the 'incomingEvent' we have given it as a parameter with the event data */
		while( SDL_PollEvent( &incomingEvent ) )
		{

			/* If we get in here, we have an event and need to figure out what to do with it. For now, we will just use a switch based on the event's type */
			switch( incomingEvent.type )
			{
				case SDL_QUIT:
				/* The event type is SDL_QUIT.
				This means we have been asked to quit - probably the user clicked on the 'x' at the top right corner of the window.
				To quit we need to set our 'go' variable to false (0) so that we can escape out of the main loop. */
					go = 0;
					SDL_GL_DeleteContext(context);   
					SDL_DestroyWindow( window );
					printf("Context clear\n");
					break;
				case SDL_KEYDOWN:
				switch( incomingEvent.key.keysym.sym )
				{
					case SDLK_LEFT:
					case SDLK_a:
					hThrust=1;
					break;
					case SDLK_RIGHT:
					case SDLK_d:
					hThrust=-1;
					break;
					case SDLK_UP:
					case SDLK_w:
					vThrust=1;
					break;
				}
				break;
				case SDL_KEYUP:
				switch( incomingEvent.key.keysym.sym )
				{
					case SDLK_LEFT:
					case SDLK_a:
					hThrust=0;
					break;
					case SDLK_RIGHT:
					case SDLK_d:
					hThrust=0;
					break;
					case SDLK_UP:
					case SDLK_w:
					vThrust=0;
					break;
					case SDLK_ESCAPE: go = 0;
					break;
				}
				break;
			}
		}

		if(choice==1) set1(window);
		else if(choice==2) set2(window);
		else if(choice==3) set3(window);

		SDL_GL_SwapWindow( window ); /* This does the double-buffering page-flip, drawing the scene onto the screen. */
	}

/* If we get outside the main loop, it means our user has requested we exit. */
/* Our cleanup phase, hopefully fairly self-explanatory ;) */
SDL_GL_DeleteContext(context);  
SDL_DestroyWindow( window );
SDL_Quit();

	return 0;
}
