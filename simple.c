#include<stdio.h>
#include<stdbool.h>

bool running = true;
int ip = 0;
int sp = -1;

int stack[256];

typedef enum {
    PSH,
    ADD,
    POP,
    HLT
} InstructionSet;

// sample program

const int program[]={
    PSH, 10,
    POP,
    PSH, 5,
    PSH, 6,
    ADD,
    HLT

};

int fetch(){
    return program[ip];
}
void eval(int instr){
    switch (instr)
    {
    case HLT:{
        running = false;
        printf("done\n");
        break;
        }
     case PSH:{
        sp++;
        stack[sp] = program[++ip];
        break;
        }
    case POP:{
        int val_popped = stack[sp--];
        printf("popped %d\n",val_popped);
        break;
    }
    case ADD:{
        // ADD adds last two numbers available in the stack
        // first we need to pop the stack to get the last loaded number
        int a = stack[sp--];
        // then we pop the top of the stack and get the last before loaded number
        int b = stack[sp--];

        // we then add the result and push it back into the stack
        int result = b + a;
        sp++;
        stack[sp] = result;
        break;
    }
    
    default:
        break;
    }
}
int main(){
    while(running){
        eval(fetch());
        ip++; // increment the ip every iteration
    }
    printf("The final result of operation = %d\n",stack[sp]);
}