#include <stdio.h>
#include <string.h>

int main() {
	char s[10] = "hello";
	snprintf(s, 4, "%s", "jc");
	printf("%s\n%d %c", s, s[3], s[3]);
	printf("Server running...\n");
	return 0;
}
