#include "SDL.h"
#include <iostream>

int WIN_SIZE = 512;

enum Directions {
	LEFT, RIGHT, UP, DOWN
};

SDL_Renderer *renderer;


void move(int *x, int *y, int dx, int dy) {
	SDL_RenderDrawLine(renderer, *x, *y, dx + *x, dy + *y);

	*x += dx;
	*y += dy;
}


void hilbert(int *x, int *y, int dir, int len, int lvl) {
	if (lvl == 1) {
		switch (dir) {
		case LEFT:
			move(x, y, 1 * len, 0);
			move(x, y, 0, 1 * len);
			move(x, y, -1 * len, 0);
			break;
		case RIGHT:
			move(x, y, -1 * len, 0);
			move(x, y, 0, -1 * len);
			move(x, y, 1 * len, 0);
			break;
		case UP:
			move(x, y, 0, 1 * len);
			move(x, y, 1 * len, 0);
			move(x, y, 0, -1 * len);
			break;
		case DOWN:
			move(x, y, 0, -1 * len);
			move(x, y, -1 * len, 0);
			move(x, y, 0, 1 * len);
			break;

		default:
			break;
		}
	}
	else {
		switch (dir) {
		case LEFT:
			hilbert(x, y, 2, len, lvl - 1);
			move(x, y, 1 * len, 0);
			hilbert(x, y, 0, len, lvl - 1);
			move(x, y, 0, 1 * len);
			hilbert(x, y, 0, len, lvl - 1);
			move(x, y, -1 * len, 0);
			hilbert(x, y, 3, len, lvl - 1);
			break;
		case RIGHT:
			hilbert(x, y, 3, len, lvl - 1);
			move(x, y, -1 * len, 0);
			hilbert(x, y, 1, len, lvl - 1);
			move(x, y, 0, -1 * len);
			hilbert(x, y, 1, len, lvl - 1);
			move(x, y, 1 * len, 0);
			hilbert(x, y, 2, len, lvl - 1);
			break;
		case UP:
			hilbert(x, y, 0, len, lvl - 1);
			move(x, y, 0, 1 * len);
			hilbert(x, y, 2, len, lvl - 1);
			move(x, y, 1 * len, 0);
			hilbert(x, y, 2, len, lvl - 1);
			move(x, y, 0, -1 * len);
			hilbert(x, y, 1, len, lvl - 1);
			break;
		case DOWN:
			hilbert(x, y, 1, len, lvl - 1);
			move(x, y, 0, -1 * len);
			hilbert(x, y, 3, len, lvl - 1);
			move(x, y, -1 * len, 0);
			hilbert(x, y, 3, len, lvl - 1);
			move(x, y, 0, 1 * len);
			hilbert(x, y, 0, len, lvl - 1);
			break;

		default:
			break;
		}
	}
}


void newHilbert(int lvl) {
	SDL_SetRenderDrawColor(renderer, 59, 110, 165, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	int length = WIN_SIZE / 2;

	int x = 0;
	int y = 0;

	int dir = UP;

	for (int i = 1; i < lvl; i++) {
		length /= 2;				//divide el tamaño de las lineas para que entre en la ventana
	}

	x = y = length / 2;				//para centrar
	hilbert(&x, &y, dir, length, lvl);

	SDL_RenderPresent(renderer);
}


int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Hilbert curvez", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_SIZE, WIN_SIZE, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	std::cout << "Use the mouse wheel to increase/decrease the order" << std::endl;

	int lvl = 1;

	newHilbert(lvl);

	bool running = true;
	SDL_Event evnt;
	while (running) {
		while (SDL_PollEvent(&evnt)) {
			if (evnt.type == SDL_QUIT) {
				running = false;
				break;
			}
			else if (evnt.type == SDL_MOUSEWHEEL) {
				if (evnt.wheel.y > 0) {
					lvl++;
					std::cout << "Level: " << lvl << std::endl;
					newHilbert(lvl);
				}
				else if (evnt.wheel.y < 0) {
					if (lvl > 1) {
						lvl--;
						std::cout << "Level: " << lvl << std::endl;
					}
					newHilbert(lvl);
				}
			}
		}
	}
	return 0;
}