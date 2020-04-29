#include <cstdio>

int main() {
    int tc;
    scanf("%d", &tc);

    for(int i=0; i<tc; i++) {
        int box[52][52] = {0, };
        bool visited[52][52][3][3] = {false, };
        int n, r, pos_x, pos_y, vel_x, vel_y;
        scanf("%d %d", &n, &r);

        for(int j=0; j<r; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            box[x][y] = 1;
        }

        scanf("%d %d", &pos_y, &pos_x);

        if(pos_x == 0) {
            vel_x = 1;
            vel_y = 0;
        } else if(pos_x == n + 1) {
            vel_x = -1;
            vel_y = 0;
        } else if(pos_y == 0) {
            vel_x = 0;
            vel_y = 1;
        } else if(pos_y == n + 1) {
            vel_x = 0;
            vel_y = -1;
        }

        while(1) {
            pos_x += vel_x;
            pos_y += vel_y;

            if(pos_x < 1 || pos_x > n || pos_y < 1 || pos_y > n) goto break_while;

            if(box[pos_y][pos_x]) {
                if(vel_x == 1 && vel_y == 0) {
                    vel_x = 0;
                    vel_y = 1;
                } else if(vel_x == 0 && vel_y == 1) {
                    vel_x = -1;
                    vel_y = 0;
                } else if(vel_x == -1 && vel_y == 0) {
                    vel_x = 0;
                    vel_y = -1;
                } else if(vel_x == 0 && vel_y == -1) {
                    vel_x = 1;
                    vel_y = 0;
                }
            }
        }

        if(visited[pos_x][pos_y][vel_x + 1][vel_y] + 1) {
            pos_x = 0;
            pos_y = 0;
            goto break_while;
        }

        visited[pos_x][pos_y][vel_x + 1][vel_y + 1] = true;

        break_while:
        printf("%d %d\n", pos_y, pos_x);
    }

    return 0;
}