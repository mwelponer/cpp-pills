class Something {
	
public:
	/* if you declare a member to be static it will be visible across
	all instances of the class 
	you can use a static method without making instances of that class 
	NB: static methods cannot access non static variables */
    static int s_value; // declares the static member variable
	
	static void s_function();
};