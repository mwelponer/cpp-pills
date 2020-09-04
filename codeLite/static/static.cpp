
static int s_var = 5;
int var = 6;

int nother = 7;
/* make it static is like to declare this variable private in a class
no other translation unit are going to see this variable
so the extern in main.cpp will not see it i.e. this variable will 
be visible only instide this cpp file */
static int s_nother = 8;


void function() {}

static void s_function() {}