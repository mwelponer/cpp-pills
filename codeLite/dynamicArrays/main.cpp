#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    
    Vertex(int x, int y, int z) : x(x), y(y), z(z) {}
    
    // copy constructor
    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {   
        std::cout << "copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}


/* very important! if we are using a vector as parameter for a 
 function, ALWAYS pass it by reference! */
void function(const std::vector<Vertex>& vertices){}


int main()
{
	std::vector<Vertex> vertices;
    
    // optimization 1 : we reserve the space for 2 vertices so 
    // the vector doesn't need to resize twice 
    vertices.reserve(2); 
    
    
    // optimization 2 : emplace_back will create a Vertex with the parameters we pass
    //vertices.push_back(Vertex(1, 2, 3));
    //vertices.push_back(Vertex(4, 5, 6));
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);
    
    for(int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;
    
    // we can alternatively write
    for(Vertex v : vertices)
        std::cout << v << std::endl;
        
    // even better to avoid copies
    for(Vertex& v : vertices)
        std::cout << v << std::endl;   

    vertices.erase(vertices.begin() + 1); // will delete the second element

    vertices.clear(); // will remove all elements
}
