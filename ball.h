#include <raylib.h>
#include <iostream>
using namespace std;
class Ball
{
public:
    Ball();
    Ball(int x, int y, int r);
    float ball_y;
    float ball_x;
    float ball_radius;
    float ball_speed_x = 5;
    float ball_speed_y = 5;
    int cpu_score = 0;
    int player_score = 0;
    void draw();
    void update();
    void ResetBoard();
};