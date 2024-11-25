
#include <iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;
int computer = 0;
    int user = 0;
    int no_winner = 0;
    int num;


enum engame { stone = 1, paper = 2, scissor = 3 };


void result(int user_choice,int com_choice)
{
    
    engame choice = static_cast<engame>(com_choice);
    engame choice2 = static_cast<engame>(user_choice);
  
    if (user_choice == stone && com_choice == paper)
    {

        cout << "Round winner : [computer] ";
        system("color 4F");
        computer++;

    }
    else if (user_choice == stone && com_choice == scissor)
    {
        cout << "Round winner : [you] ";
        system("color 2F");
        user++;
    }
    
    else if (user_choice == stone && com_choice == stone)
    {

        cout << "Round winner : [no winner] ";
        system("color 6F");
        no_winner++;
    }
    else if (user_choice == paper && com_choice == stone)
    {

        cout << "Round winner : [you] ";
        user++;
        system("color 2F");
    }
    else if (user_choice == paper && com_choice == paper)
    {

        cout << "Round winner : [no winner] ";
        system("color 6F");
        no_winner++;
    }
    else if (user_choice == paper && com_choice == scissor)
    {

        cout << "Round winner :  [computer] ";
        system("color 4F");
        computer++;
    }
    else if (user_choice == scissor && com_choice == scissor)
    {

        cout << "Round winner :  [no winner] ";
        system("color 6F");
        no_winner++;
    }
    else if (user_choice == scissor && com_choice == stone)
    {

        cout << "Round winner :  [computer] ";
        system("color 4F");
        computer++;
    }
    else if (user_choice == scissor && com_choice == paper)
    {

        cout << "Round winner :  [you] ";
        system("color 2F");
        user++;
    }
    
    

}
void final_result(int num_round,int n1,int n2,int n3)
{
    cout << "             -------------------------------------------          \n";
    cout << "                +++ G A M E   O V E R +++ \n";
    cout << "             -------------------------------------------          \n";
    cout << "             ---------------[Game Results]--------------          \n";
    cout << "             "<< setw(15) <<"Game rounds" <<setw(5)<<":" << num_round << endl;
    cout << "             "<< setw(15)<<"Player won times" << setw(4) << ":" << n2 << endl;
    cout << "             "<< setw(15)<<"Computer won times" << setw(2) << ":" << n1 << endl;
    cout << "             "<<setw(15)<<"draw times" << setw(5) << ":" << n3 << endl;
    cout << "             " << setw(15) << "final winner" << setw(5) << ":";
    if (n1 == n2)
    {
        cout << "no winner" << endl;
    }
    else if (n1 > n2)
    {
        cout << "Computer" << endl;
    }
    else if (n1 < n2)
    {
        cout << "you" << endl;
    }

}

void game()
{
    cout << "how many round you want to play 1:10 ?\n\n";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        
        int my_ans = 0;
        
        cout << "\n\nround [" << i << "] begin:\n\n";
        cout << "your choice:[1]stone, [2]paper, [3]scissor ?";
        cin >> my_ans;
        
       
        
           
            
        engame choice = static_cast<engame>(my_ans);

        cout <<endl<< "\n\n\n\n-----------round" << i << "-----------\n";
        cout << "player choice:";
        if (choice == stone)
        {
            cout << " stone\n";
        }
        else if (choice == paper)
        {
            cout << " paper\n";
        }
        else if (choice == scissor)
        {
            cout << " scissor\n";
        }
        else
        {

            cout << "Invalid choice. Please choose between 1 and 3.\n";
        }




        int computer_choice = rand() % (3 - 1 + 1) + 1;
        engame com_choice = static_cast<engame>(computer_choice);
        cout << "computer choice :";
        if (com_choice == stone)
        {
            cout << "stone\n";
        }
         else if (com_choice == paper)
        {
            cout << "paper\n";
        }
         else if (com_choice == scissor)
        {
            cout << "scissor\n";
        }
        result(choice, com_choice);
       
        cout << endl << endl;
        
    }
    final_result(num, computer, user, no_winner);
    
}
void replay()
{char answer;
do
{ 
    cout << "\n Do you want to play again ?y/n\n";
    
    cin >> answer;
    if (answer == 'y' || 'Y');
    {
        system("cls");
        system("color 0F");
        game();
    }
} while (answer == 'y' || 'Y');
 
    
}


int main()
{
    srand((unsigned)time(NULL));
    game();
    replay();
    
}

