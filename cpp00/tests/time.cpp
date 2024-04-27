#include <iostream>
#include <ctime>

int main() {
    // Get current time
    time_t rawTime = time(NULL);

    std::cout << "CurrentTime: " << rawTime << std::endl;

    // Convert time to struct tm
    struct tm *localTime = localtime(&rawTime);

    std::cout << "Years since 1900: " << localTime->tm_year << std::endl;
    char timestamp[50];
    // Format the timestamp
    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << "Current timestamp: " << timestamp;

    return 0;
}
