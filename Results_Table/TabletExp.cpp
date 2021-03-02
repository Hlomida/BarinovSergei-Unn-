#define _CRT_SECURE_NO_WARNINGS
#include "InsTab.h"
#include <iomanip>
#include <conio.h>


int main()
{
        void line();
        void star();
        InsTab at;
        /*at.Imput();
        cout << "Imbeded value of " << at.NewData;*/
        float avg;

        at.Add();
        /*struct cricketer
        {
        }rec[5];*/

        /*
        for (int i = 0; i < 5; i++)
        {
            cout << "\nEnter Students' name:-";
            cin >> rec[i].name;
            cout << "Enter Math mark:-";
            cin >> rec[i].math;
            cout << "Enter PE mark:-";
            cin >> rec[i].pe;
            cout << "Enter Programming mark:-";
            cin >> rec[i].prog;
            rec[i].avg = float(rec[i].math) / rec[i].pe;
        }
        */


        cout << "\n\n\n";
        cout << setw(49) << "Last Exam\n";
        line();
        cout << setw(15) << "Students' name" << setw(15) << "Math" << setw(10) << "PE"
            << setw(20) << "Programming\n";
        line();
        at.Show();
        cout << endl;
        line();
        cout << endl << endl << endl;
        star();
        cout << setw(43) << "Finish\n";
        star();
        _getch();
        exit(0);
}



void line()
{
    for (int i = 1; i < 41; i++)
        cout << "--";

    cout << "\n";
}



void star()
{
    for (int i = 1; i < 41; i++)
        cout << "**";

    cout << "\n";
}
