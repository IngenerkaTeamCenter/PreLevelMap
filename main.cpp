//¬ыбор уровней карты. —делал яхонтов ќлег

#include "TXLib.h"

struct Road
{
  double x, y;
};

void drawRoad (Road r)
{
    txSetColor(RGB (100, 0, 0));
    txSetFillColor(RGB (100, 0, 0));
    txRectangle(r.x - 20, r.y - 20, r.x + 20, r.y + 20);
};

struct Wall {
    double x, y;
};

void drawWall(Wall w)
{
    txSetColor(RGB(128, 128, 128));
    txSetFillColor(RGB(128, 128, 128));
    txRectangle(w.x - 22, w.y - 22, w.x + 22, w.y + 22);
}

struct Level
{
    Road roads[300];
    int roadsCount;
    Wall walls[300];
    int wallsCount;
};

void createLevel(Level &l, string filename)
{
    l.roadsCount = 0;
    l.wallsCount = 0;
    FILE *file = fopen(filename.c_str(), "r");

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            char symbol;
            fscanf(file, " %c", &symbol);
            if (symbol == '#')
            {
                l.walls[l.wallsCount].y = 40 * i + 20;
                l.walls[l.wallsCount].x = 40 * j + 20;
                l.wallsCount++;
            }
            else
            {
                l.roads[l.roadsCount].y = 40 * i + 20;
                l.roads[l.roadsCount].x = 40 * j + 20;
                l.roadsCount++;
            }
        }
    }
    fclose(file);
};

void drawLevel(Level l)
{
    for (int i = 0; i < l.roadsCount; i++)
        drawRoad(l.roads[i]);
    for (int i = 0; i < l.wallsCount; i++)
        drawWall(l.walls[i]);
}


int main()
{
    Level l0;

//    char str[20];
//    cout Ђ "¬ведите номер уровн€\n" Ђ endl;
//    cin ї l;

    txCreateWindow(800, 600);
    txBegin();

    createLevel(l0, "level0.txt");
    drawLevel(l0);
//    destroyLevel(l0);
}
