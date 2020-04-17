#include <stdio.h>

int main() {
    int n, m, b;
    scanf("%d %d %d", &n, &m, &b);

    int world[500][500];
    int lowest_time = 2147483647, lowest_z = 2147483647, highest_z = 0, result_z = -1;

    for(int y=0; y<n; y++) {
        for(int x=0; x<m; x++) {
            scanf("%d", &world[x][y]);

            if(world[x][y] < lowest_z)
                lowest_z = world[x][y];
            
            if(world[x][y] > highest_z)
                highest_z = world[x][y];
        }
    }

    for(int z=highest_z; z>=lowest_z; z--) {
        int time = 0;
        int build = 0, destroy = 0;

        for(int y=0; y<n; y++) {
            for(int x=0; x<m; x++) {
                if(world[x][y] > z) {
                    destroy += world[x][y] - z;
                } else if(world[x][y] < z) {
                    build += z - world[x][y];
                }
            }
        }

        if(build > destroy + b)
            continue;

        time = build + destroy * 2;

        if(time < lowest_time) {
            lowest_time = time;
            result_z = z;
        }
    }

    printf("%d %d", lowest_time, result_z);

    return 0;
}