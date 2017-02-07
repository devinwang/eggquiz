
#include <stdio.h>


int get_result(){
	unsigned long i = 0;
	__asm__(
	"movq %1, %%rsi;\n\t"		// loop begining
	"_loop_begin%=: \n\t"
	"incq %%rsi;\n\t"

	"movq %%rsi, %%rax;\n\t"	// 1 take all
	"movq $1, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $0, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 2 left 1
	"movq $2, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $1, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 3 take all
	"movq $3, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $0, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 4 left 1
	"movq $4, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $1, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 5 left 4
	"movq $5, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $4, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 6 left 3
	"movq $6, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $3, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 7 take all
	"movq $7, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $0, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 8 left 1
	"movq $8, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $1, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %%rax;\n\t"	// 9 take all
	"movq $9, %%rbx;\n\t"
	"xor %%rdx, %%rdx\n\t"
	"divq %%rbx, %%rax;\n\t"
	"cmpq $0, %%rdx;\n\t"
	"jne _loop_begin%=\n\t;"

	"movq %%rsi, %0;"
	:"=r"(i)
	:"r"(i)
	:"%rax","%rbx","%rcx","%rdx", "%rsi");
	return i;
}

int main(){
	int result = get_result();
	printf("Result: %d\n", result);
	return 0;
}
