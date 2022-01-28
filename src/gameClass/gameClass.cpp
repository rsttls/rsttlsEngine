#include <gameClass/gameClass.h>
#include <iostream>
gameClass::~gameClass()
{
	TTF_CloseFont(textClass::font);
	delete renderer;
	TTF_Quit();
	SDL_Quit();
	logger.log("SDL and TTF deinitilized...\nExiting...");
}

int gameClass::init()
{
	// variables
	gameActive = 1;
	cameraX = 0;
	cameraY = 0;
	windowWidth = 640;
	windowHeight = 480;
	// renderer
	renderer = new rsttlsRenderer;
	renderer->createWindowAndRenderer("Hi", windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	logger.log("rsttlsRenderer created...");
	// ttf init
	if (TTF_Init() != 0)
		logger.log("Failed to initilize ttf...!");
	logger.log("TTF initilized...");
	// class static variables
	textClass::renderer = renderer;
	gameObject::renderer = renderer;
	gameObject::cameraX = &cameraX;
	gameObject::cameraY = &cameraY;
	logger.log("Variables assinged...");
	return 0;
}

int gameClass::loadAssets()
{
	// ttf
	textClass::font = TTF_OpenFont("assets/font.ttf", 36);
	if (textClass::font == nullptr)
		throw 2;
	logger.log("TTF loaded...");
	// textures
	player.loadTexture("assets/player.png");
	dog.loadTexture("assets/test.jpg");
	amogus.loadTexture("assets/amongus.png");
	logger.log("Textures loaded...");
	player.texture.scale(0.04);
	player1=player;
	amogus.texture.scale(0.25);
	dog.position = {200, 200};
	return 0;
}

int gameClass::handleEvents()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameActive = 0;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_a)
				moveLeft = 1;
			if (event.key.keysym.sym == SDLK_d)
				moveRight = 1;
			if (event.key.keysym.sym == SDLK_w)
				moveUp = 1;
			if (event.key.keysym.sym == SDLK_s)
				moveDown = 1;
			if (event.key.keysym.sym == SDLK_e)
				rotateRight = 1;
			if (event.key.keysym.sym == SDLK_q)
				rotateLeft = 1;
			if (event.key.keysym.sym == SDLK_ESCAPE)
				gameActive = 0;
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_a)
				moveLeft = 0;
			if (event.key.keysym.sym == SDLK_d)
				moveRight = 0;
			if (event.key.keysym.sym == SDLK_w)
				moveUp = 0;
			if (event.key.keysym.sym == SDLK_s)
				moveDown = 0;
			if (event.key.keysym.sym == SDLK_e)
				rotateRight = 0;
			if (event.key.keysym.sym == SDLK_q)
				rotateLeft = 0;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(renderer->window, &windowWidth, &windowHeight);
				break;

			default:
				break;
			}
		default:
			break;
		}
	}
	return 0;
}

int gameClass::update()
{
	if (moveLeft)
		player.acceleration.x = -0.05;
	else if (moveRight)
		player.acceleration.x = 0.05;
	else
		player.acceleration.x = 0;

	if (moveDown)
		player.acceleration.y = 0.05;
	else if (moveUp)
		player.acceleration.y = -0.05;
	else
		player.acceleration.y = 0;
	if (rotateRight)
	{
		player.rotation += 5;
		// debug.scale+=0.001;
	}
	else if (rotateLeft)
	{
		player.rotation -= 5;
		// debug.scale-=0.001;
	}

	player.update();
	player1.update();
	dog.update();
	amogus.update();
	/*debug.text = "Player position [";
	debug.text+=std::to_string(player.position.x);
	debug.text+=",";
	debug.text+=std::to_string(player.position.y);
	debug.text+="]";
	debug.update();*/
	// camera follows player
	cameraX = player.position.x - (windowWidth / 2);
	cameraY = player.position.y - (windowHeight / 2);
	return 0;
}

int gameClass::draw()
{
	// clear
	renderer->setColor(0, 0, 0, 255);
	renderer->clear();
	// custom
	dog.draw();
	player.draw();
	player1.draw();
	amogus.draw();
	// debug.draw();
	//  update
	renderer->update();
	return 0;
}

gameClass::gameClass()
{
	init();
	loadAssets();
	while (gameActive)
	{
		handleEvents();
		update();
		draw();
	}
}