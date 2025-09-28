#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Hello World!" << endl;
    cout << "Program name: " << argv[0] << endl;

   if (argc > 1) 
   {
        cout << "Command-line arguments:" << endl;

        for (int i = 1; i < argc; ++i) 
        {
            cout << i << "argv{: " << argv[i] << endl;
        }
    } else 
    {
        cout << "No command line arguments" << endl;
    }

    return 0;
}
