#include<iostream>
#include<string>
#include<ctime>
#include<stdlib.h>
#include<windows.h>

using namespace std;


class Thegame
{
private:

    int tries;
    int showncounter;
    string response;//This stores the users secret word
    string shown;// This is used to show user how far they came in guessing

public:
    void resetword();// A function used to restore the hangman word for multiple uses
    void hangmandrawing();// A function used to draw the hangman figure
    void tryLetters();//function that used the different letters used in the hangman setting
    void storetheword(string HangmanWord);// this function stores the word in the private variable making it untouchable
    void addTries();
    void completehangman();
};
void Thegame::tryLetters()//the implementation of guessing the letters in a series of unhidden letters
{
    int loop=1;
    char letter;
    int showncounter=0;

    for(int i=0; i<(int)response.length(); i++)
    {
        if(isalnum(response[i]))//checks if the location of the string is a number or alphabet and then changes it to a -
        {
            shown=shown+"-";//this is it
            showncounter++;
        }
        else
        {
            shown=shown+response[i];//else if its something like a exclamation point or something like it leave it as it is
        }
    }
    cout<<shown<<endl;

    cout<<"What letter do you think is here?"<<endl;
    cin>>letter;

    for(int b=0; b<(int)response.size(); b++)
    {
        if(response[b]==letter || toupper(letter)==response[b])
        {
            shown[b]=letter;
        }

    }

    cout<<shown<<endl;
    cout<<"You have "<<tries<<" tries left."<<endl;
    while(loop)
    {
        int tracker=0;//used to keep track of the tries of the user for the hangman picture
        int showntracker=0;// this is used to keep track of the revised hashes to win the game

        cout<<"What letter do you think is here? or enter (?) to leave"<<endl;
        cin>>letter;

        if(letter=='?')
        {
            break;
        }
        for(int b=0; b<(int)response.size(); b++)
        {
            if(response[b]==letter || toupper(letter)==response[b])
            {
                shown[b]=letter;
                tracker=1;
            }
            else if(response[b]!=letter || response[b]!=toupper(letter))//iteration to keep track of any thing different we dont want
            {
                tracker=tracker+0;
            }
        }

        for(int d=0; d<showncounter; d++)
        {
            if(shown[d]=='-' || shown[d]==' ')
            {
                showntracker=1;
            }
            else if(shown[d]!='-')
            {
                showntracker=showntracker+0;
            }
        }

        if(tracker==0)
        {
            addTries();
            hangmandrawing();
        }

        if(showntracker==0 || shown==response)
        {
            loop=0;
            cout<<"Secret Word: "<<response<<endl;
            cout<<"CONGRATS YOU WIN!!!"<<endl;
            cout<<"Play the game again... Thank you"<<endl;
            resetword();
        }
        cout<<shown<<endl;

        if(tries>0 && showntracker!=0 && shown!=response)

        {
            cout<<"You have "<<tries<<" tries left."<<endl;
        }
        if(tries==0)
        {
            loop=0;
            cout<<"Sorry you lose"<<endl;
            cout<<"THE SECRET WORD WAS: "<<response<<endl;
            cout<<"Try the game again... Thank you"<<endl;
            resetword();

            cout<<endl;
            cout<<endl;
        }

    }
}
void Thegame::storetheword(string x)//simply placing the secret phrase in a private variable
{
    response=x;
}
void Thegame::resetword()//resetting the word and dashes back to its original nature for multiple attempts
{
    response="";
    shown="";
    tries=7;
}
void Thegame::addTries()
{
    tries--;
}
void Thegame::hangmandrawing()
{
    if(tries==6 || tries==7)
    {
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |         " <<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==5)
    {
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |       \\  " <<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==4)
    {
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 " <<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==3)
    {
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /" <<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==2)
    {
        cout << " ___________"<<endl;
        cout << " |        }"<<endl;
        cout << " |      \\ 0 /" <<endl;
        cout << " |         |"<<endl;
        cout << "_|______________"<<endl;
    }
    else if(tries==1)
    {
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /"<<endl;
        cout << " |          | "<<endl;
        cout << " |         /  "<<endl;
        cout << "_|______________"<<endl;
    }
    else
    {
        cout << " ___________"<<endl;
        cout << " |         }"<<endl;
        cout << " |       \\ 0 /"<<endl;
        cout << " |          | "<<endl;
        cout << " |         / \\ "<<endl;
        cout << "_|______________"<<endl;
    }
}
int main()
{
    Thegame obj;
    int choice;//the bread and butter of the classes letter the user over and over until they get tired
    int loop=1;//used for the while loop below
    char ans='n';//the original condition of the while loop
    string usersWord;// the secret word the user enters
    string Hint;// the Hint for the hangman game

    while(ans=='n' || ans=='N')
    {
        cout << "Hello, my name is **Badrinath** and WELCOME TO MY GAME OF HANGMAN!!!!!!!!! " << endl;
        cout<<endl;
        cout<<"RULE#1: This is a 2 players game"<<endl;
        cout<<"RULE#2: PLAYER 1,(has to do the following things below) "<<endl;
        cout<<"When you are past this screen: PLEASE! Enter the #1 AND and follow it by doing #2 "<<endl;
        cout<<"RULE#3: PLAYER 2,(After Player 1, has did all the previous things >> press any key to your choosing)"<<endl;
        cout<<"GOOD LUCK!!!!"<<endl;
        cout<<endl;
        cout<<"Once you read the instructions press any key to continue"<<endl;
        cin>>ans;
    }
    while(loop)
    {
        cout<<"***************************"<<endl;
        cout<<"1)PUT IN THE WORD         *"<<endl;
        cout<<"2)INSERT IN A HINT        *"<<endl;
        cout<<"3)DISPLAY THE HINT        *"<<endl;
        cout<<"4)START GUESSING          *"<<endl;
        cout<<"5)RESET EVERYTHING        *"<<endl;
        cout<<"6)EXIT FROM THE GAME      *"<<endl;
        cout<<"***************************"<<endl;
        cout<<"Your choice here >";
        cin>>choice;
        if(choice==1)
        {
            HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
            DWORD mode = 0;
            GetConsoleMode(hStdin, &mode);
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
            cout << "Put in the secret phrase" << endl;
            cin.ignore();
            getline(cin,usersWord);//cin>>usersword
            SetConsoleMode(hStdin, mode);
            obj.storetheword(usersWord);
            cout<<"YOUR SECRET WORD WAS SUCCESSFUL!!"<<endl;
            cout<<endl;
            cout<<endl;
        }

        else if(choice==2)
        {
            cout<<"Enter a Hint for the player who is guessing"<<endl;
            cin.ignore();
            cin>>Hint;
            cout<<endl;
            cout<<endl;
        }
        else if(choice==3)
        {
            cout<<"The Hint is:"<<Hint<<endl;
            cout<<"------------------------------"<<endl;
            cout<<endl;
            cout<<endl;

        }
        else if(choice==4)
        {
            obj.tryLetters();
        }
        else if(choice==5)
        {
            obj.resetword();
            cout<<"EVERYTHING HAS BEEN RESET"<<endl;
            cout<<endl;
            cout<<endl;
        }
        else if(choice==6)
        {
            cout<<"Thank you for trying out the game."<<endl;
            cout<<"Peace!!"<<endl;
            loop=0;
        }

    }

}
