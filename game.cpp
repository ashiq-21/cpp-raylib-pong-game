#include <game.h>

Game::Game()
{
    screenWidth = 1280;

    screenHeight = 800;
}

void Game::Initiate()
{
    ball = Ball(screenWidth / 2, screenHeight / 2, 20);

    Player = Paddle(screenWidth - 35, (screenHeight / 2) - 60, 25, 120);

    cpu = CpuPaddle(10, (screenHeight / 2) - 60, 25, 120);
}

void Game::checkCollision()
{
    if (CheckCollisionCircleRec(Vector2{ball.ball_x, ball.ball_y},
                                ball.ball_radius, Rectangle{Player.x, Player.y, Player.width, Player.height}))
    {
        ball.ball_speed_x *= -1;
    }

    if (CheckCollisionCircleRec(Vector2{ball.ball_x, ball.ball_y},
                                ball.ball_radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
    {
        ball.ball_speed_x *= -1;
    }
}

void Game::draw()
{

    DrawCircle(screenWidth / 2, screenHeight / 2, 150, GREEN);

    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

    cpu.draw();

    Player.draw();

    ball.draw();
}

void Game::update()
{
    ball.update();

    Player.update();

    cpu.update(ball.ball_y);

    checkCollision();
}
