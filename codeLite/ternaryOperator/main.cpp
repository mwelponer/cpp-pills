#include <iostream>

static int s_level = 1;
static int s_speed = 2;

int main(int argc, char **argv)
{	
	s_speed = s_level > 5 ? 10 : 5;
	
	/* menas the same as writing the following
	if (s_level > 5) 
		s_speed = 10;
	else
		s_speed = 5;*/
		
		
	// another example
	std::string rank; 
	if( s_level > 10)
		rank = "master";
	else
		rank = "beginner";
	
	// this actually runs little faster as we don't need to create an intermediate string variable
	std::string anotherRank = s_level > 10 ? "master" : "beginner";
	
	
	// another example more complicated
	s_speed = s_level > 5 ? s_level > 10 ? 15 : 10 : 5;
	/*this means 
	if s_level > 5 & also > 10 set speed to 15 otherwise 10 otherwise 5*/
		
	//return 0;
}
