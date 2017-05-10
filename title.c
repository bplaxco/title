#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 255

int main(int argc, char *argv[])
{
	char *title;
	char buf[BUF_SIZE];
	int i;
	int offset;
	int width;
	size_t title_len;

	if (argc != 3) {
		fprintf(stderr, "title <width> <title>\n");
		return 1;
	}

	width = atoi(argv[1]);

	if (!width) {
		fprintf(stderr, "Width must be a number greater than zero.\n");
		return 1;
	}

	if (width > (BUF_SIZE / 2)) {
		fprintf(stderr, "The max width is %d.\n", BUF_SIZE / 2);
		return 1;
	}

	title = argv[2];
	title_len = strlen(title);
	offset = (width / 2) - (title_len / 2);

	for (i = 0; i < offset; i ++) {
		buf[i] = ' ';
	}

	buf[i] = '\0';
	strcat(buf, title);
	printf("%s\n", buf);
	return 0;
}
