#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <termios.h>
#include <algorithm>

using namespace std;

#define REACH_DST ((x == MAX_X - 1) && (y == MAX_Y - 2))

// X -> vertical direction . Y -> horizontal direction

const int MAX_X = 20,
          MAX_Y = 30;

bool flag = false,
     slow = false,
     autogame = true;

int Maze[MAX_X][MAX_Y];

class PathOfMaze
{
  private:
    struct _Node
    {
        int x;
        int y;
        char direction;
        _Node *next;
    };
    _Node *_start_point;

  public:
    PathOfMaze()
    {
        _start_point = nullptr;
    }

    ~PathOfMaze()
    {
        _Node *p = _start_point;

        while (_start_point != nullptr)
        {
            _start_point = _start_point->next;
            delete p;
            p = _start_point;
        }
    }

    void push(int xx, int yy, char _direct)
    {
        try
        {
            _Node *new_node = new _Node;
            new_node->x = xx;
            new_node->y = yy;
            new_node->direction = _direct;
            new_node->next = nullptr;

            if (_start_point == nullptr)
                _start_point = new_node;
            else
            {
                new_node->next = _start_point;
                _start_point = new_node;
            }
        }
        catch (bad_alloc)
        {
            cout << "Allocate  memory Failed.\n";
        }
    }

    _Node *pop(int &xx, int &yy)
    {
        if (_start_point != nullptr)
        {
            _Node *p = _start_point;
            _start_point = _start_point->next;
            xx = p->x;
            yy = p->y;
            delete p;
        }
        return _start_point;
    }

    void print()
    {
        if (_start_point != nullptr)
        {
            _Node *p = _start_point;
            while (p != nullptr)
            {
                cout << " " << p->x << " " << p->y << " " << p->direction << endl;
                p = p->next;
            }
        }
        else
            cout << "Empty! Failed!" << endl;
    }
};

void createMaze()
{
    int node_number = MAX_X * MAX_Y;
    int x, y;

    fill(*Maze, *Maze + MAX_X * MAX_Y, 1);

    srand((unsigned)time(NULL));

    for (int i = 0; i < node_number; i++)
    {
        x = rand() % (MAX_X - 2) + 1;
        y = rand() % (MAX_Y - 2) + 1;
        Maze[x][y] = 0;
    }

    Maze[1][1] = 0;                 // entrance
    Maze[MAX_X - 2][MAX_Y - 2] = 0; // exit

    Maze[0][1] = 3;
    Maze[MAX_X - 1][MAX_Y - 2] = 0;
}

void printMaze()
{
    int x, y;

    system("clear");

    for (x = 0; x < MAX_X; x++)
    {
        for (y = 0; y < MAX_Y; y++)
        {
            switch (Maze[x][y])
            {
            case 0: // the node is available for move
                cout << "  ";
                break;
            case 1:
                cout << "■ ";
                break;
            case 2:
                cout << "× ";
                break;
            case 3:
                cout << "↓ ";
                break;
            case 4:
                cout << "→ ";
                break;
            case 5:
                cout << "← ";
                break;
            case 6:
                cout << "↑ ";
                break;
            case 7:
                cout << "※ ";
                break;
            default:
                cout << "?";
                break;
            }
        }
        cout << endl;
    }

    if (slow)
    {
        sleep(1);
    }
}

void maze_feasible(PathOfMaze &s)
{

    int _backup[MAX_X][MAX_Y];
    for (int x = 0; x < MAX_X; x++)
        for (int y = 0; y < MAX_Y; y++)
            _backup[x][y] = Maze[x][y];

    int x = 1, y = 1; // start coordinate.

    while (true)
    {
        _backup[x][y] = 2; // setting guard. prevent from rolling back immediately.

        if (_backup[x + 1][y] == 0)
        {
            s.push(x, y, 'D'); // Down

            _backup[x][y] = 3;
            ++x;
            _backup[x][y] = 7; // current locate

            if (REACH_DST)
            {
                flag = true;
                return;
            }
            else
                continue;
        }

        else if (_backup[x][y + 1] == 0)
        {
            s.push(x, y, 'R'); // Right

            _backup[x][y] = 4;
            ++y;
            _backup[x][y] = 7;
            if (REACH_DST)
            {
                flag = true;
                return;
            }
            else
                continue;
        }

        else if (_backup[x - 1][y] == 0)
        {
            s.push(x, y, 'U'); // Up

            _backup[x][y] = 6;
            --x;
            _backup[x][y] = 7;
            if (REACH_DST)
            {
                flag = true;
                return;
            }
            else
                continue;
        }

        else if (_backup[x][y - 1] == 0)
        {
            s.push(x, y, 'L');

            _backup[x][y] = 5;
            --y;
            _backup[x][y] = 7;
            if (REACH_DST)
            {
                flag = true;
                return;
            }
            else
                continue;
        }

        // Reached the dead space. So, Look back upon until when a suitable path has been found.
        else if (s.pop(x, y) == nullptr && _backup[x - 1][y] != 0 && _backup[x][y - 1] != 0 && _backup[x][y + 1] != 0 && _backup[x + 1][y] != 0)
        {
            _backup[0][1] = 7;
            if (_backup[1][1] != 1)
                _backup[1][1] = 2;
            return;
        }
    }
}

char getch()
{
    char ch;

    static struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    system("stty -echo");
    ch = getchar();
    system("stty echo");

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void move()
{
    int x = 1, y = 1;

    while (true)
    {
        switch (getch())
        {
        case 's':
            if (Maze[x + 1][y] == 0)
            {

                Maze[x][y] = 0;
                ++x;
                Maze[x][y] = 7;
                printMaze();
                if (REACH_DST)
                {
                    cout << "\n\n              reach the destination successfully" << endl;
                    return;
                }
            }
            break;
        case 'd':
            if (Maze[x][y + 1] == 0)
            {
                if (Maze[x][y + 1] == 0)
                {
                    Maze[x][y] = 0;
                    ++y;
                    Maze[x][y] = 7;
                    printMaze();
                    if (REACH_DST)
                    {
                        cout << "\n\n              reach the destination successfully" << endl;
                        return;
                    }
                }
            }

            break;
        case 'w':
            if (Maze[x - 1][y] == 0)
            {
                Maze[x][y] = 0;
                --x;
                Maze[x][y] = 7;
                printMaze();
                if (REACH_DST)
                {
                    cout << "\n\n              reach the destination successfully" << endl;
                    return;
                }
            }
            break;
        case 'a':
            if (Maze[x][y - 1] == 0)
            {
                Maze[x][y] = 0;
                --y;
                Maze[x][y] = 7;
                printMaze();
                if (REACH_DST)
                {
                    cout << "\n\n              reach the destination successfully" << endl;
                    return;
                }
            }
            break;
        }
    }
}

void autoMove(PathOfMaze &s)
{
    int x = 1,
        y = 1;
    while (true)
    {
        Maze[x][y] = 2; // setting guard. prevent from rolling back immediately.

        if (Maze[x + 1][y] == 0)
        {
            s.push(x, y, 'D');
            Maze[x][y] = 3;
            x = x + 1;
            Maze[x][y] = 7;
            if (slow)
                printMaze();
            if (REACH_DST)
            {
                s.push(x, y, '*');
                cout << "\n\n              reach the destination successfully" << endl;
                return;
            }
            else
                continue;
        }

        else if (Maze[x][y + 1] == 0)
        {
            s.push(x, y, 'R');
            Maze[x][y] = 4;
            y = y + 1;
            Maze[x][y] = 7;
            if (slow)
                printMaze();
            if (REACH_DST)
            {
                s.push(x, y, '*');
                cout << "\n\n              reach the destination successfully" << endl;
                return;
            }
            else
                continue;
        }

        else if (Maze[x - 1][y] == 0)
        {
            s.push(x, y, 'U');
            Maze[x][y] = 6;
            x = x - 1;
            Maze[x][y] = 7;
            if (slow)
                printMaze();
            if (REACH_DST)
            {
                s.push(x, y, '*');
                cout << "\n\n              reach the destination successfully" << endl;
                return;
            }
            else
                continue;
        }

        else if (Maze[x][y - 1] == 0)
        {
            s.push(x, y, 'L');
            Maze[x][y] = 5;
            y = y - 1;
            Maze[x][y] = 7;
            if (slow)
                printMaze();
            if (REACH_DST)
            {
                s.push(x, y, '*');
                cout << "\n\n              reach the destination successfully" << endl;
                return;
            }
            else
                continue;
        }

        else if (s.pop(x, y) == nullptr && Maze[x - 1][y] != 0 && Maze[x][y - 1] != 0 && Maze[x][y + 1] != 0 && Maze[x + 1][y] != 0)
        {
            cout << "\n\n              No suitable path" << endl;
            Maze[0][1] = 7;
            if (Maze[1][1] != 1)
                Maze[1][1] = 2;
            return;
        }
    }
}

void GameEntrance();

void StartGame()
{

    flag = false;
    while (!flag)
    {
        PathOfMaze Map;

        createMaze();

        maze_feasible(Map);

        system("clear");
        cout << "\t*                loading.              *" << endl;
        system("clear");
        cout << "\t*                loading..             *" << endl;
        system("clear");
        cout << "\t*                loading...            *" << endl;
    }

    printMaze();
    cout << "\n\n              input the \"enter\" to continue" << endl;
    getchar();

    if (!autogame)
    {
        move();
        cout << "\n\n              input the \"enter\" to continue" << endl;
        getchar();
        GameEntrance();
    }

    else
    {
        PathOfMaze stack1;
        autoMove(stack1);
    }
    printMaze();
    cout << "\n\n              input the \"enter\" to continue" << endl;
    getchar();
    GameEntrance();
}

void GameEntrance()
{
    system("clear");
    int num;
    cout << "\t==============================================" << endl;
    cout << "\t*                                            *" << endl;
    cout << "\t*               1.display the path.          *" << endl;
    cout << "\t*                                            *" << endl;
    cout << "\t*               2.auto move show             *" << endl;
    cout << "\t*                                            *" << endl;
    cout << "\t*               3.play by yourself           *" << endl;
    cout << "\t*                                            *" << endl;
    cout << "\t*               4.exit game                  *" << endl;
    cout << "\t*                                            *" << endl;
    cout << "\t==============================================" << endl;
    slow = false;

    switch (getch())
    {
    case '1':
        autogame = true;
        StartGame();
        break;
    case '2':
        autogame = true;
        slow = true;
        StartGame();
        break;
    case '3':
        autogame = false;
        StartGame();
        break;
    case '4':
        exit(1);
        break;
    default:
        cout << "\n\n              Error! input the \"enter\" to return back!" << endl;
        getchar();
        GameEntrance();
    }
    getchar();
}

int main(int argc, char **argv)
{
    GameEntrance();
    return 0;
}