#include <iostream>
#include <fstream>

unsigned char* inc(unsigned char* p, unsigned char* m) {
	if (p == m + 255) {
		return m;
	} else {
		return p + 1;
	}
}

int main(int argc, char* argv[]) {
	std::string filename(argv[1]);

	FILE* qy_file = fopen(filename.c_str(), "r");
	if (qy_file == nullptr) {
		return EXIT_FAILURE;
	}
	
	char* mems = NULL;
	mems = new char[256];//memcells
	char* cur = mems;//where we are

	unsigned char cmd = 0;
	while ((cmd = fgetc(qy_file)) != 255) {
  	switch (cmd) {
			case 'q': {
				std::cout << "Hello, World!";
				break;
			}
			case 'w': {
				std::cin >> *cur;
				std::cout << *cur; //sadly, only one line
				break;
			}
			case 'e': {
				std::cout << "e"; //only works as quine when program has a bunch of e
				break;
			}
			case '0': {
				*cur = 0;
				break;
			}
			case '1': {
				*cur = 1;
				break;
			}
			case '2': {
				*cur = 2;
				break;
			}
			case '3': {
				*cur = 3;
				break;
			}
			case '4': {
				*cur = 4;
				break;
			}
			case '5': {
				*cur = 5;
				break;
			}
			case '6': {
				*cur = 6;
				break;
			}
			case '7': {
				*cur = 7;
				break;
			}
			case '8': {
				*cur = 8;
				break;
			}
			case '9': {
				*cur = 9;
				break;
			}
			case ')': {
				if (cur == (mems + 255)) {
					cur = mems;
				} else {
					cur++;
				}
				break;
			}
			case '(': {
				if (cur == mems) {
					cur = mems + 255;
				} else {
					cur--;
				}
				break;
			}
			case '&': {//multi-digit WOW
				unsigned char t = *cur;
				unsigned char o = *(inc(cur, mems));
				*(inc(cur, mems)) = 0;
				*cur = (unsigned char)(10 * t + o);
				break;
			}
			case '+': {
				unsigned char a = *cur;
				unsigned char b = *(inc(cur, mems));
				*(inc(cur, mems)) = 0;
				*cur = (unsigned char)(a + b);
				break;
			}
			case '-': {
				unsigned char a = *cur;
				unsigned char b = *(inc(cur, mems));
				*(inc(cur, mems)) = 0;
				*cur = (unsigned char)(a - b);
				break;
			}
			case '*': {
				unsigned char a = *cur;
				unsigned char b = *(inc(cur, mems));
				*(inc(cur, mems)) = 0;
				*cur = (unsigned char)(a * b);
				break;
			}
			case '/': {
				unsigned char a = *cur;
				unsigned char b = *(inc(cur, mems));
				*(inc(cur, mems)) = 0;
				*cur = (unsigned char)(a / b);
				break;
			}
			case 'o': {
				std::cout << *cur;
				break;
			}
			case 'i': {
				std::cin >> *cur;
				break;
			}
			case '\n': {
				std::fill(mems, mems + 255, 0);
				break;
			}
		}
  }
	std::cout << std::endl;
	fclose(qy_file);

	return EXIT_SUCCESS;
}