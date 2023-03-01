#include <windows.h>
#include <iostream>

using namespace std;

int main() {
    const char* PIPE_NAME = "\\\\.\\pipe\\myPipe";
    const char* MESSAGE = "Send from C++, UWU!";

    while (true)
    {
        HANDLE pipe = CreateFileA(PIPE_NAME, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (pipe == INVALID_HANDLE_VALUE) {
            cout << "Error connecting to pipe" << endl;
            return 1;
        }

        DWORD bytesWritten;
        if (!WriteFile(pipe, MESSAGE, strlen(MESSAGE), &bytesWritten, NULL)) {
            cout << "Error writing to pipe" << endl;
            CloseHandle(pipe);
            return 1;
        }

        Sleep(30);
        CloseHandle(pipe);
    }


    return 0;
}