// PONGgame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<raylib.h>

using namespace std;
int player_score = 0;
int cpu_score = 0;

class Ball
{
public:
	float x, y;
	int speed_x, speed_y;
	int radius;
	void drawBall()
	{
		DrawCircle(x, y, radius, WHITE);
	}
	void updateBallPosition()
	{
		x += speed_x;
		y += speed_y;

		if (y + radius >= GetScreenHeight() || y - radius <= 0)
		{
			speed_y *= -1;
		}
		if (x + radius >= GetScreenWidth())
		{
			cpu_score++;
			ResetBall();
		}
		if (x - radius <= 0)
		{
			player_score++;
			ResetBall();
		}
	}
	void ResetBall()
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;

		int speed_choices[2] = { -1, 1 };
		speed_x *= speed_choices[GetRandomValue(0, 1)];
		speed_y *= speed_choices[GetRandomValue(0, 1)];
	}

};

class Padlle
{
protected:
	void LimitMovement()
	{
		if (y < 0)
		{
			y = 0;
		}
		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}
	}
public:
	float x, y;
	float width, height;
	int speed_y;

	void drawPaddle()
	{
		DrawRectangle(x, y, width, height, WHITE);
	}
	void Update()
	{
		if (IsKeyDown(KEY_UP))
		{
			y = y - speed_y;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y = y + speed_y;
		}
		LimitMovement();
	}
};

class CpuPadlle : public Padlle
{
public:
	void Update(int ball_y)
	{
		if (y + height / 2 > ball_y)
		{
			y = y - speed_y;
		}
		if (y + height / 2 <= ball_y)
		{
			y = y + speed_y;
		}
		LimitMovement();
	}
};

int main()
{
	
	const int screen_width = 1280;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "PONG game");
	SetTargetFPS(60);

	Ball ball;
	ball.radius = 20;
	ball.x = screen_width / 2;
	ball.y = screen_height / 2;
	ball.speed_x = 7;
	ball.speed_y = 7;

	Padlle padllePlayer;
	padllePlayer.width = 25;
	padllePlayer.height = 120;
	padllePlayer.x = screen_width - padllePlayer.width - 10;
	padllePlayer.y = screen_height / 2 - padllePlayer.height / 2;
	padllePlayer.speed_y = 6;

	CpuPadlle padlleCpu;
	padlleCpu.height = 120;
	padlleCpu.width = 25;
	padlleCpu.x = 10;
	padlleCpu.y = screen_height / 2 - padlleCpu.height / 2;
	padlleCpu.speed_y = 6;


	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		//Updating
		ball.updateBallPosition();
		padllePlayer.Update();
		padlleCpu.Update(ball.y);

		//Checking collision
		if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{padllePlayer.x, padllePlayer.y, padllePlayer.width, padllePlayer.height}))
		{
			ball.speed_x *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ padlleCpu.x, padlleCpu.y, padlleCpu.width, padlleCpu.height }))
		{
			ball.speed_x *= -1;
		}
		//Drawing 
		ClearBackground(BLACK);
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		ball.drawBall();
		//DrawRectangle(10, screen_height /2 - 60, 25, 120, WHITE);
		padllePlayer.drawPaddle();
		padlleCpu.drawPaddle();
		DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
