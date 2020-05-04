#include <stdio.h>
#include <stdbool.h>
#include <string.h>

unsigned char memory[32] = {0, };
unsigned int acc = 0, pc = 0;
bool is_halted = false;
int temp = -1;

int main() {
    do {
        memset(memory, 0, 32);
        acc = 0, pc = 0;
        is_halted = false;

        for(int i=0; i<32; i++) {
            int foo;

            if(i == 0 && temp != -1) {
                foo = temp;
                temp = -1;
            } else {
                scanf("%d", &foo);
            }
            
            for(int j=1; j<=128; j*=2) {
                int bar = foo % 10;

                memory[i] += bar * j;
                foo /= 10;
            }
        }

        while(!is_halted) {
            char opcode  = (memory[pc] & 0b11100000) >> 5;
            char operand = (memory[pc] & 0b00011111);

            pc ++;

            if(pc > 0b11111) pc &= 0b11111;

            switch(opcode) {
                case 0b000:
                    memory[operand] = acc;
                    break;
                case 0b001:
                    acc = memory[operand];
                    break;
                case 0b010:
                    if(acc == 0) pc = operand;
                    break;
                case 0b100:
                    acc --;
                    break;
                case 0b101:
                    acc ++;
                    break;
                case 0b110:
                    pc = operand;
                    break;
                case 0b111:
                    is_halted = true;
                    break;
            }

            if(acc > 0b11111111) acc &= 0b11111111;
        }

        int result[8] = {0, };

        for(int i=0; i<8; i++) {
            result[7 - i] = acc % 2;
            acc /= 2;
        }

        for(int i=0; i<8; i++) {
            printf("%d", result[i]);
        }

        printf("\n");
    } while(scanf("%d", &temp) != EOF);

    return 0;
}