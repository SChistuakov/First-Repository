#include "stdafx.h"
#include <string.h>
 
struct Stack {
     int value[50];
     int topIndex;
}

int top(Stack *stack)
{
	return stack->value[stack->topIndex];
}
int pop(Stack *stack)
{
	stack->topIndex--;
	return stack->value[stack->topIndex + 1];
};
void push(Stack *stack, int x)
{

}
int length(Stack *stack)
{
	return stack->topIndex;
}

int main(void)
{
       
        return 0;
}

