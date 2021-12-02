#include <unistd.h>
#include <stdio.h>
#define VERSION "0.0.1"
void print_help();
int main(int argc, char *argv[]) {
int index, c;
opterr = 0;
if (argc == 1)
print_help();
while ((c = getopt (argc, argv,
"hvf:")) != -1)
switch (c) {
case 'h':
print_help();
exit(0);

