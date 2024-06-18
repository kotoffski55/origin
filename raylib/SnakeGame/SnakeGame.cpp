// SnakeGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 24, 255 };

int cellSize = 30;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
	double  currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

class Snake
{
public:
	deque<Vector2> snake_body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	Vector2 direction = { 1 ,0 };


	void Draw()
	{
		for (unsigned int i = 0; i < snake_body.size(); i++)
		{
			float x = snake_body[i].x;
			float y = snake_body[i].y;
			Rectangle segment = { x * cellSize, y * cellSize,(float) cellSize, (float)cellSize };
			DrawRectangleRounded(segment,0.5, 6, darkGreen);
		}
	}

	void Update()
	{
		snake_body.pop_back();
		snake_body.push_front(Vector2Add(snake_body[0], direction));
	}
};

class Food
{
public:
	Texture2D texture;
	Vector2 position;
	Food()
	{
		Image image = LoadImage("graphics/food.png");
		texture = LoadTextureFromImage(image);
		UnloadImage(image);
		position = GenerateRandomPos();
	}
	~Food()
	{
		UnloadTexture(texture);
	}

	Vector2 GenerateRandomPos()
	{
		float x = GetRandomValue(0, cellCount - 1);
		float y = GetRandomValue(0, cellCount - 1);
		return Vector2{ x, y };
	}
	

	void Draw()
	{
		//DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen );
		DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
	}
};

int main()
{
	InitWindow(cellSize * cellCount, cellSize * cellCount, "SNAKE");
	SetTargetFPS(60);
	Food food;
	Snake snake;

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		if (eventTriggered(0.2))
		{
			snake.Update();
		}
		if (IsKeyPressed(KEY_UP))
		{
			snake.direction = { 0, -1 };
		}
		//Drawing
		ClearBackground(green);
		food.Draw();
		snake.Draw();


		EndDrawing();
	}

	CloseWindow();
	return 0;
}

