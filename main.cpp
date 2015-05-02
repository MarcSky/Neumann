#include <iostream>

#define HEIGHT 20
#define WIDTH 20
#define ALIVE '*'
#define DEAD ' '
#define ITERATION 100
using namespace std;

int main() {
    int *grid = new int[HEIGHT * WIDTH];
    int x,y;

    time_t t;
    srand((unsigned) time(&t));
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            grid[x + y * HEIGHT] = rand() % 2;
        }
    }

    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            cout << grid[x + y * HEIGHT];
        }
        cout << endl;
    }

    int c;
    for (c = 0; c < ITERATION; c++) {
        for(y = 0; y < HEIGHT; y++) {
            for(x = 0; x < WIDTH; x++) {
                int cell = 0;

                //top
                if((y-1) >= 0 && grid[x + (y-1) * WIDTH]) cell++;

                //down
                if((y+1) <= HEIGHT - 1 && grid[x + (y+1) * WIDTH]) cell++;

                //right
                if((x+1) <= WIDTH - 1 && grid[(x+1) + y * WIDTH]) cell++;

                //left
                if((x-1) >= 0 && grid[(x-1) + y * WIDTH]) cell++;

                //condition
                if(cell == 1) cout << ALIVE;
                else cout<<DEAD;
            }
            cout << endl;
        }
        cout << endl << "==================================" << endl;
    }
    delete [] grid;
    return 0;
}