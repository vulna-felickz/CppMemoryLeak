#include <iostream>
#include <cstring>

int main()
{
    const char *message = "Hello";
    char password[32];
    char buffer[256];
    
    // This will overflow - writing 256 bytes when message is only 6 bytes
    // It will write past buffer into password and beyond, corrupting the stack
    memcpy(buffer, message, 256);
    
    // Make it crash more dramatically by writing way beyond buffer bounds
    char small_buffer[8];
    char large_data[1024];
    memset(large_data, 'A', sizeof(large_data));
    
    // This will definitely overflow and corrupt stack/heap
    memcpy(small_buffer, large_data, 1024);
    
    // Try to use the corrupted buffer to trigger immediate crash
    std::cout << "If you see this, trying to access corrupted memory..." << std::endl;
    std::cout << small_buffer[2000] << std::endl;  // Access far beyond bounds

    // PR do it again
    // Try to use the corrupted buffer to trigger immediate crash
    std::cout << "If you see this, trying to access corrupted memory..." << std::endl;
    std::cout << small_buffer[2001] << std::endl;  // Access far beyond bounds
    
    return 0;
}
