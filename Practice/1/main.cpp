#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>

using namespace std;

void towers (int numDisks, char source, char dest, char auxiliary)
{
    static int step = 0;

    cout << "Towers (" << numDisks << ", " << source << ", " << dest << ", " << auxiliary << ")\n";
        if (numDisks == 1)
                cout << "\t\t\t\t\tStep " << ++step << ": Move from " << source << " to " << dest << endl;
        else
           {
            towers (numDisks - 1, source, auxiliary, dest);
             cout << "\t\t\t\t\tStep " << ++step << ": Move from " << source << " to " << dest << endl;
             towers (numDisks - 1, auxiliary, dest, source);
            }
        return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char f,g,h;
    towers(7,f,g,h);
    return a.exec();
}
