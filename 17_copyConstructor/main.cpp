#include <iostream>
#include <cstring>

class String 
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0; // null terminator
    }
    
    /* this is the copy constructor!! that guarantees that 
	m_buffer of a String object copy will be created on a 
	new block of memory. 
    other is the string we are going to duplicate */
    String(const String& other)
        : m_size(other.m_size)
    {
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);
    }
    
    /* if we don't want to allow the object to be duplicated 
    this is the way */
    //String(const String& other) = delete;
    
    ~String()
    {
        delete[] m_buffer;
    }
};


int main()
{
    String string = String("Mike");
    String another = string;
	return 0;
}
