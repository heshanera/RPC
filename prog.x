#define VERSION_NUMBER 1

struct operands {
	string line<100>;
	char c;
};

program PROG1 {
   version VERSION {
     int SEARCH(operands) = 1;
   } = VERSION_NUMBER;
} = 444444;