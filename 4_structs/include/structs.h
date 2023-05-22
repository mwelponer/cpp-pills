/* struct is just a class in which members are public by default whereas in cpp
- class members are private by default
- struct are there to maintain compatibility with c
- struct are used mainly for plain data, like for example definition of a 2dVector 
that contains just two float variables. I will not use struct where there is 
inheritence 
- usually struct are defined inside the .h header
*/
struct Player {
	int x, y;
	int speed;
	
	void move(int xa, int ya){
		x += xa * speed;
		y += ya * speed;
	}
};