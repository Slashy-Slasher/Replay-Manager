#include "Replay-Manager.h"
#include <raylib.h>
#include <raymath.h>
#include <cstdlib>
#include <string>

class view
{
public:
	Vector2 test;
	int screenWidth;
	int screenHeight;
	Vector3 color;

	view(Vector2 tester, int width, int height)
	{
		this->test = tester;

		this->screenWidth = width;
		this->screenHeight = height;


		color = {255.0f, 255.0f, 255.0f};
		initilize_window();
	}

	void initilize_window()
	{
		InitWindow(this->screenWidth, this->screenHeight, "Replay Window");
		SetTargetFPS(60); // Set desired framerate (frames-per-second)
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	void change_background_color(Color new_color)
	{
		ClearBackground(new_color);
	}
};



class model
{

};



int main()
{
	std::string VLC_PATH = R"(C:\Program Files\VideoLAN\VLC\vlc.exe)";
	std::string TEST_VIDEO_PATH = R"(C:\Users\Alexander\Videos\Hunt  Showdown 2024.02.13 - 23.32.18.02.Dvr-00.02.35.185-00.02.50.497.mp4)";

	const int startTime = 7;   // seconds
	const int stopTime = 15;  // seconds

	// Build command: both VLC path and video path quoted once
	std::string cmd = "\"" + VLC_PATH + "\" --start-time=" + std::to_string(startTime) +
		" --stop-time=" + std::to_string(stopTime) +
		" \"" + TEST_VIDEO_PATH + "\" vlc://quit";

	view screen = view({0,0}, 800, 800);
	int test = 0;
	std::cout << test;
	InitWindow(screen.screenWidth, screen.screenHeight, "Replay Window");
	SetTargetFPS(60); // Set desired framerate (frames-per-second)
	while (!WindowShouldClose())
	{
		BeginDrawing();
		DrawFPS(5, 0);


		
		system(cmd.c_str());
		
		

		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow(); // Close window and unload OpenGL context

	return 0;
}

