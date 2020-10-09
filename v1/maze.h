// author - sonaspy@outlook.com
// coding - utf_8

/**
    ■ ↓ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
 ■ ■ ■ ■ ■ ■ ■ ■ → ↓ ■ ■           ■ ■                     ■           ■     ■ ■
 ■       ■   ■ ■ ■ → ↓   ■   ■ ■   ■       ■ ■               ■       ■   ■ ■ ■
 ■ ■     ■ ■   ■ → ↓       ■         ■       ■ ■ ■   ■   ■           ■         ■
 ■           ■     ■ ■     ■ ↓   ■       ■ ■   ■                         ■     ■
 ■ ■   ■   ■   ■ ■ ■     ↓     ■ ■                         ■   ■   ■     ■   ■
 ■       ■ ■ ■   ■ ■   ■ ■ ■ ■ ■   → → → ↓   ■   ■ ■ ■       ■ ■ ■       ■   ■
 ■   ■               ■ ■   ■   ■ ■ ■ ■   ■ ■ ■ ■ ↓       ■ ■             ■ ■ ■ ■
 ■ ■           ■ ■ ■           ↓ ■       ■     ■ ■   ■           ■ ■ ■ ■ ■ ■ ■
 ■ ■ ↓     ■         ■     ■   ■       ■   ■       ■ ■         ■ ■ ■           ■
    ■     ■ ■ ■   ↓                     ■ ■ ■   ■     ■         ■   ■ ■ ■ ■   ■
 ■   ■ ■   ■ ■ ■     ■ ■     ↓     ■     ■   ■         ■     ■ ■     ■ ■ ■ ■   ■
    ■   ■       ■ ↓     ■   ■         ■ ■   ■     ■     ■ ■               ■ ■ ■
    ■       ■ ■   ↓         ■ ■ ■   ■ ■   ■     ■               ■     ■ ■     ■
 ■ ■ ■   ■ ■ ■       ■     ↓   ■         ■ ■ ■       ■   ■       ■   ■   ■   ■
 ■ ■ ■ ■ ■   ■   ■ ■         ■ ■ ↓ ■ ■     ■ ■       ■ ■ ■ ■   ■ ■   ■ ■   ■ ■
 ■   ■   ■     ■ ■ ■   ■       → ↓   ■     ■ ■ ■     ■     ■         ■       ■
 ■   ■               ■ ■             ■ → ※ ■               ■   ■ ■ ■ ■   ■ ■ ■
 ■   ■ ■   ■     ■   ■     ■ ■       ■   ■   ■ ■     ■ ■ ■   ■   ■ ■   ■     ■
 ■   ■           ■     ■ ■ ■   ■ ■ ■ ■             ■ ■ ■     ■       ■       ■ ■
 ■       ■     ■ ■ ■         ■   ■ ■       ■ ■ ■     ■   ■   ■       ■ ■ ■ ■ ■
 ■       ■ ■   ■ ■ ■             ■ ■       ■               ■ ■         ■   ■ ■ ■
 ■ ■ ■ ■ ■         ■ ■     ■     ■   ■   ■       ■       ■ ■   ■ ■ ■ ■ ■   ■ ■
 ■   ■           ■ ■   ■   ■     ■         ■     ■ ■     ■       ■ ■ ■     ■ ■
 ■       ■ ■   ■ ■ ■   ■   ■ ■   ■ ■   ■   ■       ■ ■ ■ ■           ■       ■
 ■ ■       ■     ■ ■ ■ ■   ■   ■   ■   ■     ■       ■     ■ ■ ■ ■       ■ ■ ■
 ■ ■               ■ ■         ■   ■       ■     ■   ■     ■           ■ ■   ■
 ■               ■ ■ ■     ■ ■ ■     ■     ■ ■         ■   ■ ■ ■ ■             ■
 ■       ■     ■ ■ ■         ■ ■ ■ ■ ■   ■   ■             ■     ■   ■       ■
 ■   ■ ■       ■         ■     ■     ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■
 ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■   ■
 *
 *  This experiment designed a maze game through C++, which involves both simple
 C++ game idea and DFS traversal algorithm.
 *
 *  The game is divided into automatic operation and means operation:
 *      1.automatic operation is the use of breadth-first algorithm to
 automatically find the path until the exit;
 *      2.Manual operation is divided into up, down, left and right movement,
 corresponding to w,x,a and d respectively.
 *
 *  It is necessary to determine the next operation address for comparison.
 *  If the next operation is feasible, move and clear the current information.
 **/

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define __REACH_DST__ ((x == __max_x_size - 1) && (y == __max_y_size - 2))

// X -> vertical direction . Y -> horizontal direction
class GameFrame;
class PathOfMaze;
class Maze;
char getch();

class Maze {
   public:
    friend class PathOfMaze;
    friend class GameFrame;
    void createMaze();
    void printMaze();
    void maze_feasible_check(PathOfMaze &s);
    void move();
    void autoMove(PathOfMaze &s);
    Maze() {
        __flag = false;
        __slow_rhythm = false;
        __auto_game = true;
    }
    ~Maze() {}

   private:
    static const int __max_x_size = 30;
    static const int __max_y_size = 45;
    bool __flag;
    bool __slow_rhythm;
    bool __auto_game;
    int __maze[__max_x_size][__max_y_size];
};

class PathOfMaze {
   private:
    struct __Coordinate {
        int x, y;
        char direction;
        __Coordinate *next;
    };
    __Coordinate *__start_point;

   public:
    friend class Maze;
    friend class GameFrame;
    PathOfMaze() { __start_point = nullptr; }

    ~PathOfMaze() {
        __Coordinate *p = __start_point;

        while (__start_point != nullptr) {
            __start_point = __start_point->next;
            delete p;
            p = __start_point;
        }
    }

    void push(int xx, int yy, char _direct);

    __Coordinate *pop(int &xx, int &yy);

    void print();
};

class GameFrame {
   public:
    friend class PathOfMaze;
    friend class GameFrame;
    void game_entrance();
    void StartGame();

   private:
    class Maze __maze_map;
};

void GameFrame::StartGame() {
    __maze_map.__flag = false;
    while (!__maze_map.__flag) {
        PathOfMaze Map;

        __maze_map.createMaze();

        __maze_map.maze_feasible_check(Map);
        system("clear");
        std::cout << "\t*                loading.              *" << std::endl;
        system("clear");
        std::cout << "\t*                loading..             *" << std::endl;
        system("clear");
        std::cout << "\t*                loading...            *" << std::endl;
    }

    __maze_map.printMaze();
    std::cout << "\n\n              input the \"enter\" to continue"
              << std::endl;
    getchar();

    if (!__maze_map.__auto_game) {
        __maze_map.move();
        std::cout << "\n\n              input the \"enter\" to continue"
                  << std::endl;
        getchar();
        game_entrance();
    }

    else {
        PathOfMaze stack1;
        __maze_map.autoMove(stack1);
    }
    __maze_map.printMaze();
    std::cout << "\n\n              input the \"enter\" to continue"
              << std::endl;
    getchar();
    game_entrance();
}

void GameFrame::game_entrance() {
    system("clear");
    int num;
    std::cout << "\t================================================"
              << std::endl;
    std::cout << "\t*                                              *"
              << std::endl;
    std::cout << "\t*               1.DISPLAY THE PATH.            *"
              << std::endl;
    std::cout << "\t*                                              *"
              << std::endl;
    std::cout << "\t*               2.AUTO MOVE SHOW               *"
              << std::endl;
    std::cout << "\t*                                              *"
              << std::endl;
    std::cout << "\t*               3.MOVE BY YOURSELF             *"
              << std::endl;
    std::cout << "\t*                                              *"
              << std::endl;
    std::cout << "\t*               4.EXIT GAME                    *"
              << std::endl;
    std::cout << "\t*                                              *"
              << std::endl;
    std::cout << "\t================================================"
              << std::endl;
    __maze_map.__slow_rhythm = false;

    switch (getch()) {
        case '1':
            __maze_map.__auto_game = true;
            StartGame();
            break;
        case '2':
            __maze_map.__auto_game = true;
            __maze_map.__slow_rhythm = true;
            StartGame();
            break;
        case '3':
            __maze_map.__auto_game = false;
            StartGame();
            break;
        case '4':
            exit(1);
            break;
        default:
            std::cout << "\n\n              Error! input the \"enter\" to "
                         "return back!"
                      << std::endl;
            getchar();
            game_entrance();
    }
    getchar();
}

void PathOfMaze::push(int xx, int yy, char _direct) {
    try {
        __Coordinate *new_node = new __Coordinate;
        new_node->x = xx;
        new_node->y = yy;
        new_node->direction = _direct;
        new_node->next = nullptr;

        if (__start_point == nullptr)
            __start_point = new_node;
        else {
            new_node->next = __start_point;
            __start_point = new_node;
        }
    } catch (std::bad_alloc) {
        std::cout << "Allocate  memory Failed.\n";
    }
};

PathOfMaze::__Coordinate *PathOfMaze::pop(int &xx, int &yy) {
    if (__start_point != nullptr) {
        __Coordinate *p = __start_point;
        __start_point = __start_point->next;
        xx = p->x;
        yy = p->y;
        delete p;
    }
    return __start_point;
};

void PathOfMaze::print() {
    if (__start_point != nullptr) {
        __Coordinate *p = __start_point;
        while (p != nullptr) {
            std::cout << " " << p->x << " " << p->y << " " << p->direction
                      << std::endl;
            p = p->next;
        }
    } else
        std::cout << "Empty! Failed!" << std::endl;
}

void Maze::createMaze() {
    int node_number = __max_x_size * __max_y_size, x, y;

    std::fill(*__maze, *__maze + __max_x_size * __max_y_size, 1);

    srand((unsigned)time(NULL));

    for (int i = 0; i < node_number; i++) {
        x = rand() % (__max_x_size - 2) + 1;
        y = rand() % (__max_y_size - 2) + 1;
        __maze[x][y] = 0;
    }

    __maze[1][1] = 0;                                // entrance
    __maze[__max_x_size - 2][__max_y_size - 2] = 0;  // exit

    __maze[0][1] = 3;
    __maze[__max_x_size - 1][__max_y_size - 2] = 0;
};

void Maze::printMaze() {
    int x, y;
    system("clear");

    for (x = 0; x < __max_x_size; x++) {
        for (y = 0; y < __max_y_size; y++) {
            switch (__maze[x][y]) {
                case 0:  // the node is available for move
                    std::cout << "  ";
                    break;
                case 1:
                    std::cout << "■ ";
                    break;
                case 2:
                    std::cout << "× ";
                    break;
                case 3:
                    std::cout << "↓ ";
                    break;
                case 4:
                    std::cout << "→ ";
                    break;
                case 5:
                    std::cout << "← ";
                    break;
                case 6:
                    std::cout << "↑ ";
                    break;
                case 7:
                    std::cout << "※ ";
                    break;
                default:
                    std::cout << "?";
                    break;
            }
        }
        std::cout << std::endl;
    }

    if (__slow_rhythm) sleep(1);
}

void Maze::maze_feasible_check(PathOfMaze &s) {
    int backup__[__max_x_size][__max_y_size];
    for (int x = 0; x < __max_x_size; x++)
        for (int y = 0; y < __max_y_size; y++) backup__[x][y] = __maze[x][y];

    int x = 1, y = 1;  // start coordinate.

    while (true) {
        backup__[x][y] =
            2;  // setting guard. prevent from rolling back immediately.

        if (backup__[x + 1][y] == 0) {
            s.push(x, y, 'D');  // Down

            backup__[x][y] = 3;
            ++x;
            backup__[x][y] = 7;  // current locate

            if (__REACH_DST__) {
                __flag = true;
                return;
            } else
                continue;
        }

        else if (backup__[x][y + 1] == 0) {
            s.push(x, y, 'R');  // Right

            backup__[x][y] = 4;
            ++y;
            backup__[x][y] = 7;
            if (__REACH_DST__) {
                __flag = true;
                return;
            } else
                continue;
        }

        else if (backup__[x - 1][y] == 0) {
            s.push(x, y, 'U');  // Up

            backup__[x][y] = 6;
            --x;
            backup__[x][y] = 7;
            if (__REACH_DST__) {
                __flag = true;
                return;
            } else
                continue;
        }

        else if (backup__[x][y - 1] == 0) {
            s.push(x, y, 'L');

            backup__[x][y] = 5;
            --y;
            backup__[x][y] = 7;
            if (__REACH_DST__) {
                __flag = true;
                return;
            } else
                continue;
        }

        // Reached the dead space. So, Look back upon until when a suitable path
        // has been found.
        else if (s.pop(x, y) == nullptr && backup__[x - 1][y] != 0 &&
                 backup__[x][y - 1] != 0 && backup__[x][y + 1] != 0 &&
                 backup__[x + 1][y] != 0) {
            backup__[0][1] = 7;
            if (backup__[1][1] != 1) backup__[1][1] = 2;
            return;
        }
    }
}

void Maze::move() {
    int x = 1, y = 1;

    while (true) {
        switch (getch()) {
            case 's':
                if (__maze[x + 1][y] == 0) {
                    __maze[x][y] = 0;
                    ++x;
                    __maze[x][y] = 7;
                    printMaze();
                    if (__REACH_DST__) {
                        std::cout << "\n\n              reach the destination "
                                     "successfully"
                                  << std::endl;
                        return;
                    }
                }
                break;
            case 'd':
                if (__maze[x][y + 1] == 0) {
                    if (__maze[x][y + 1] == 0) {
                        __maze[x][y] = 0;
                        ++y;
                        __maze[x][y] = 7;
                        printMaze();
                        if (__REACH_DST__) {
                            std::cout << "\n\n              reach the "
                                         "destination successfully"
                                      << std::endl;
                            return;
                        }
                    }
                }

                break;
            case 'w':
                if (__maze[x - 1][y] == 0) {
                    __maze[x][y] = 0;
                    --x;
                    __maze[x][y] = 7;
                    printMaze();
                    if (__REACH_DST__) {
                        std::cout << "\n\n              reach the destination "
                                     "successfully"
                                  << std::endl;
                        return;
                    }
                }
                break;
            case 'a':
                if (__maze[x][y - 1] == 0) {
                    __maze[x][y] = 0;
                    --y;
                    __maze[x][y] = 7;
                    printMaze();
                    if (__REACH_DST__) {
                        std::cout << "\n\n              reach the destination "
                                     "successfully"
                                  << std::endl;
                        return;
                    }
                }
                break;
        }
    }
}

void Maze::autoMove(PathOfMaze &s) {
    int x = 1, y = 1;
    while (true) {
        __maze[x][y] =
            2;  // setting guard. prevent from rolling back immediately.

        if (__maze[x + 1][y] == 0) {
            s.push(x, y, 'D');
            __maze[x][y] = 3;
            x = x + 1;
            __maze[x][y] = 7;
            if (__slow_rhythm) printMaze();
            if (__REACH_DST__) {
                s.push(x, y, '*');
                std::cout
                    << "\n\n              reach the destination successfully"
                    << std::endl;
                return;
            } else
                continue;
        }

        else if (__maze[x][y + 1] == 0) {
            s.push(x, y, 'R');
            __maze[x][y] = 4;
            y = y + 1;
            __maze[x][y] = 7;
            if (__slow_rhythm) printMaze();
            if (__REACH_DST__) {
                s.push(x, y, '*');
                std::cout
                    << "\n\n              reach the destination successfully"
                    << std::endl;
                return;
            } else
                continue;
        }

        else if (__maze[x - 1][y] == 0) {
            s.push(x, y, 'U');
            __maze[x][y] = 6;
            x = x - 1;
            __maze[x][y] = 7;
            if (__slow_rhythm) printMaze();
            if (__REACH_DST__) {
                s.push(x, y, '*');
                std::cout
                    << "\n\n              reach the destination successfully"
                    << std::endl;
                return;
            } else
                continue;
        }

        else if (__maze[x][y - 1] == 0) {
            s.push(x, y, 'L');
            __maze[x][y] = 5;
            y = y - 1;
            __maze[x][y] = 7;
            if (__slow_rhythm) printMaze();
            if (__REACH_DST__) {
                s.push(x, y, '*');
                std::cout
                    << "\n\n              reach the destination successfully"
                    << std::endl;
                return;
            } else
                continue;
        }

        else if (s.pop(x, y) == nullptr && __maze[x - 1][y] != 0 &&
                 __maze[x][y - 1] != 0 && __maze[x][y + 1] != 0 &&
                 __maze[x + 1][y] != 0) {
            std::cout << "\n\n              No suitable path" << std::endl;
            __maze[0][1] = 7;
            if (__maze[1][1] != 1) __maze[1][1] = 2;
            return;
        }
    }
}
char getch() {
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