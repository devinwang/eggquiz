
#include <stdio.h>

#define RULE_TPL(qty, left)  "movq %%rsi, %%rax;\n\t" \
	"movq $"#qty", %%rbx;\n\t" \
	"xor %%rdx, %%rdx\n\t" \
	"divq %%rbx, %%rax;\n\t" \
	"cmpq $"#left", %%rdx;\n\t" \
	"jne _loop_begin%=\n\t;"

unsigned long get_result(){
	unsigned long i = 0;

	__asm__(
	"movq %1, %%rsi;\n\t"		// loop begining
	"_loop_begin%=: \n\t"
	"incq %%rsi;\n\t"

	RULE_TPL(1, 0)			// 1 take all
	RULE_TPL(2, 1)			// 2 left 1
	RULE_TPL(3, 0)			// 3 take all
	RULE_TPL(4, 1)			// 4 left 1
	RULE_TPL(5, 4)			// 5 left 4
	RULE_TPL(6, 3)			// 6 left 3
	RULE_TPL(7, 0)			// 7 take all
	RULE_TPL(8, 1)			// 8 left 1
	RULE_TPL(9, 0)			// 9 take all

	"movq %%rsi, %0;"
	:"=r"(i)
	:"r"(i)
	:"%rax","%rbx","%rcx","%rdx", "%rsi");
	return i;
}

int main(){
	unsigned long result = get_result();
	printf("Result: %lu\n", result);
	return 0;
}

