#include "gameClass.h"
gameClass::~gameClass()
{
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
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
	renderer->createWindowAndRenderer("Hi", windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
	// Dear imgui
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplSDL2_InitForSDLRenderer(renderer->window, renderer->renderer);
	ImGui_ImplSDLRenderer_Init(renderer->renderer);
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
	amogus.texture.scale(0.25);
	dog.position = {200, 200};
	return 0;
}

int gameClass::handleEvents()
{
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		eventHandler.handle(event);
		if (eventHandler.quit | eventHandler.keyESC)
			gameActive = 0;
		if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			SDL_GetWindowSize(renderer->window, &windowWidth, &windowHeight);
	}
	return 0;
}
int gameClass::gui()
{
	static bool monitoring;
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Debug"))
		{
			ImGui::MenuItem("Monitor", NULL, &monitoring);
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
	if (monitoring)
	{
		ImGui::Begin("Monitoring");
		ImGui::Text("Event time: %f", static_cast<double>((times[1] - times[0]) / static_cast<double>(SDL_GetPerformanceFrequency())));
		ImGui::Text("Update time: %f", static_cast<double>((times[2] - times[1]) / static_cast<double>(SDL_GetPerformanceFrequency())));
		ImGui::Text("Draw time: %f", static_cast<double>((times[3] - times[2]) / static_cast<double>(SDL_GetPerformanceFrequency())));
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::Text("");
		ImGui::Text("Player pos: [%f,%f]", player.position.x, player.position.y);
		ImGui::SliderInt(" X rotaion", player.rotationPoint.x, -200, 200);
		ImGui::End();
	}
	return 0;
}

int gameClass::update()
{
	// capture movement
	if (eventHandler.keyA)
		player.acceleration.x = -0.05;
	else if (eventHandler.keyD)
		player.acceleration.x = 0.05;
	else
		player.acceleration.x = 0;

	if (eventHandler.keyS)
		player.acceleration.y = 0.05;
	else if (eventHandler.keyW)
		player.acceleration.y = -0.05;
	else
		player.acceleration.y = 0;
	if (eventHandler.keyE)
	{
		*player.rotation += 5;
	}
	else if (eventHandler.keyQ)
	{
		*player.rotation -= 5;
	}
	// update
	player.update();
	dog.update();
	amogus.update();
	// GUI update
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	gui();
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
	amogus.draw();
	// imgui
	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	//  update
	renderer->update();
	return 0;
}

gameClass::gameClass()
{
	init();
	loadAssets();
	logger.log("Starting main loop ...");
	while (gameActive)
	{
		startTime = SDL_GetPerformanceCounter();
		handleEvents();
		eventTime = SDL_GetPerformanceCounter();
		update();
		updateTime = SDL_GetPerformanceCounter();
		draw();
		drawTime = SDL_GetPerformanceCounter();
		times[0] = startTime;
		times[1] = eventTime;
		times[2] = updateTime;
		times[3] = drawTime;
	}
}