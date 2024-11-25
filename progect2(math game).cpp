
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int num;
int counter_right;
int counter_false;
short choicelevel;
short choiceopr;

enum enlevel {
    Easy = 1, med, Hard, Mix
};

enum enopreation_type {
    add = 1, sub, mul, Div, mix
};

void hm_round() {
    cout << "How many Questions do you want to answer ?\n";
    cin >> num;
}

void exe() {
    enlevel your_choice;
    your_choice = static_cast<enlevel>(choicelevel);

    enopreation_type type;
    int result;
    int user_result;
    char opr = ' ';
    type = static_cast<enopreation_type>(choiceopr);

    for (int i = 1; i <= num; i++) {
        int n1, n2;

        // Adjusted number generation to avoid zero for n1 and n2
        if (choicelevel == Easy) {
            n1 = rand() % 9 + 1;  // 1-9
            n2 = rand() % 9 + 1;  // 1-9
        }
        else if (choicelevel == med) {
            n1 = rand() % 99 + 1; // 1-99
            n2 = rand() % 99 + 1; // 1-99
        }
        else if (choicelevel == Hard) {
            n1 = rand() % 999 + 1; // 1-999
            n2 = rand() % 999 + 1; // 1-999
        }
        else if (choicelevel == Mix) {
            int num_choice = rand() % 3 + 1;
            switch (num_choice) {
            case 1:
                n1 = rand() % 9 + 1;
                n2 = rand() % 9 + 1;
                break;
            case 2:
                n1 = rand() % 99 + 1;
                n2 = rand() % 99 + 1;
                break;
            case 3:
                n1 = rand() % 999 + 1;
                n2 = rand() % 999 + 1;
                break;
            }
        }

        // Handle operation type
        if (choiceopr == add) {
            result = n1 + n2;
            opr = '+';
        }
        else if (choiceopr == sub) {
            result = n1 - n2;
            opr = '-';
        }
        else if (choiceopr == mul) {
            result = n1 * n2;
            opr = '*';
        }
        else if (choiceopr == Div) {
            while (n2 == 0) {
                n2 = rand() % 9 + 1;  // Ensure n2 is not zero for division
            }
            result = n1 / n2;
            opr = '/';
        }
        else if (choiceopr == mix) {
            int level_choice = rand() % 4 + 1;
            switch (level_choice) {
            case 1:
                result = n1 + n2;
                opr = '+';
                break;
            case 2:
                result = n1 - n2;
                opr = '-';
                break;
            case 3:
                result = n1 * n2;
                opr = '*';
                break;
            case 4:
                while (n2 == 0) {
                    n2 = rand() % 9 + 1;  // Ensure n2 is not zero
                }
                result = n1 / n2;
                opr = '/';
                break;
            }
        }

        cout << "------------------------------------\n";
        cout << "Question [" << i << "/" << num << "]\n";
        cout << n1 << endl << n2 << opr << endl << "------" << endl;
        cin >> user_result;

        if (user_result == result) {
            cout << "Right result :-)\n";
            system("color 2F");
            counter_right++;
        }
        else {
            cout << "Wrong answer :-(\n";
            cout << "The right answer is: " << result << endl;
            system("color 4F");
            counter_false++;
        }
    }
}

void final_result() {
    cout << "-------------------------------\n";
    cout << "Final result is ";
    if (counter_right >= counter_false) {
        cout << "PASS\n";
       
    }
    else {
        cout << "Fail\n";
        system("color 4F");
    }
    cout << "-------------------------------\n";
    cout << setw(25) << "Number of questions" << ":" << num << endl;
    cout << setw(25) << "Questions level" << ":";
    if (choicelevel == Easy)
    {
        cout << "Easy" << endl;
    }
    else if (choicelevel ==med )
    {
        cout << "med" << endl;
    }
    else if (choicelevel == Hard)
    {
        cout << "Hard" << endl;
    }
    else if (choicelevel == Mix)
    {
        cout << "Mix" << endl;
    }
    cout << setw(25) << "Op type" << ":";
    if (choiceopr == add)
    {
        cout << "Add" << endl;
    }
    else if (choiceopr == sub)
    {
        cout << "sub" << endl;
    }
    else if (choiceopr == mul)
    {
        cout << "mul" << endl;
    }
    else if (choiceopr == Div)
    {
        cout << "Div" << endl;
    }
    else if (choiceopr == mix)
    {
        cout << "mix" << endl;
    }
    cout << setw(25) << "Number of right answers" << ":" << counter_right << endl;
    cout << setw(25) << "Number of wrong answers" << ":" << counter_false << endl;
    cout << "-------------------------------\n";
}


void game() {
    hm_round();
    enlevel your_choice;
    cout << "Enter Questions level: [1]Easy, [2]Med, [3]Hard, [4]Mix ?\n";
    cin >> choicelevel;

    cout << "Which operation type: [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ?\n";
    cin >> choiceopr;

    exe();
    final_result();
}
void replay() {
    cout << "------------------------------------\n";
    cout << "Do you want to play again? y/n ";
    char answer = ' ';
    cin >> answer;

    // Correct comparison of both 'y' and 'Y'
    if (answer == 'y' || answer == 'Y') {
        system("cls");  // Clear screen
        system("color 0F");  // Reset color to default
        game();  // Restart the game
    }
    else if (answer == 'n' || answer == 'N') {
        cout << "\nGOOD LUCK\n";
    }
}
int main() {
    srand((unsigned)time(NULL));
    game();
    replay();
}