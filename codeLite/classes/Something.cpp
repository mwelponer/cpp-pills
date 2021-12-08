#include "Something.h"

/* if the class variable is static we need to initialize it like this
usually into the header file */
//int Something::s_value { 1 };
// or like this
int Something::s_value = 1;
void Something::s_function(){
	s_value++;
}
