#include <iostream>

using namespace std;

static const int SIZE = 3;
int rgb[SIZE] = {0,0,0};

void setColor(int* color)
{
    for(int i=0; i<SIZE; i++)
        rgb[i] = *(color++);
}

//int main(int argc, char **argv)
//{
//    int myColor[] = {45,149,62};
//    int* p = myColor;
//    
//    setColor(p);    
//    
//	std::cout << "color: (" << rgb[0] << ", " 
//                            << rgb[1] << ", "
//                            << rgb[2] << ")" << std::endl;
//                            
//    // esto no se puede!                        
//    /*int a[] = {1, 2, 3};
//    int b[] = {4, 5, 6};*/
//                            
//	return 0;
//}
