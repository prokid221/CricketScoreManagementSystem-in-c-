//
//  cricket score management system.cpp
//
//
//  Created by Gagan Chowdary on 21/06/16.
//
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class cricket
{
public:
    string team1;     //Name of team A
    string team2;     //Name of team B
    int Overs;          //Stores Overs
    void OpenWelcome()   //Opening file
    {
        system("clear");
        cout<<"Opening file"<<endl;
        cout<<"------------"<<endl;
        cout<<"Welcome to crickect score management system"<<endl;
    }
    void GetName()       //Input Team A and B
    {
        cout<<"Enter name of Team 1 :"<<endl;
        cin>>team1;
        cout<<"Enter name of Team 2 :"<<endl;
        cin>>team2;
    }
    void NoOfOvers()     // Input of Overs
    {
        cout<<"Enter number of overs"<<endl;
        cin>>Overs;
    }
    void rules()
    {
        cout<<"commands\t-\tused for\nnoball\t-\tfor Noball\nout\t-\tfor Out\nwide\t-\tfor Wide ball\n";
    }
};
int main()
{
    cricket obj;
    obj.OpenWelcome();
    obj.GetName();
    obj.NoOfOvers();
    int balls[2];       // created array [0]=team1 and [1]=team2
    int player[2];
    string scr;
    balls[0]= obj.Overs*6;
    balls[1]= balls[0];
    player[0]=10;
    player[1]=player[0];
    static int score[2];        //static used to initialized score =0
    fstream file("storage.txt",ios::in|ios::out|ios::app);
    file<<"Start of the Match"<<endl<<endl;
    for (int j=0;j<2;j++)      //loop for two innings
    {
        if (j==0) {
            system("clear");
            cout<<"Batting :"<<obj.team1<<" Bowling :"<<obj.team2<<endl;    // shows which team is playing
            file<<"Team 1 : "<<obj.team1<<"\tBatting"<<endl;
            }
        if (j==1) {
            system("clear");
            cout<<"Target : "<<score[0]<<endl;
            cout<<"Batting :"<<obj.team2<<" Bowling :"<<obj.team1<<endl;
            file<<"Team 2 : "<<obj.team2<<"\tBatting"<<endl;

        }
        obj.rules();

        for (int i=1 ;i <= balls[j];i++)            //Inputs score and conditions for adding score
        {
            if(score[1]>score[0] || player[1]==0){break;}
            int b ;
            int c ;
            b=i/6 ;
            c=i%6 ;
            
        cout<<"Over : "<<b<<"."<<c<<" Score :"<<score[j]<<" No of wickets : "<<10-player[j]<<endl<<"Enter score :"<<endl;
        cin>>scr;
            system("clear");

        if (scr == "1")
            {
                score[j]=score[j]+1;
                system("clear");
            }
        else if (scr == "2")
            {
                score[j]=score[j]+2;
                system("clear");
            }
       else if (scr == "3")
            {
                score[j]=score[j]+3;
                system("clear");
            }
       else if (scr == "4")
            {
                score[j]=score[j]+4;
                system("clear");
            }
       else if (scr == "5")
            {
                score[j]=score[j]+5;
                system("clear");
            }
       else if (scr == "6")
            {
                score[j]=score[j]+6;
                system("clear");
            }
       else if (scr == "wide")
            {
                score[j]=score[j]+1;
                i=i-1;
                system("clear");
                file<<"wide"<<endl;
            }
       else if (scr == "noball")
            {
                score[j]=score[j]+1;
                i=i-1;
                system("clear");
                file<<"noball"<<endl;
            }
       else if (scr == "out")
            {
                player[j]=player[j]-1;
                system("clear");
                file<<"out"<<endl;
                
            }
       else if (player[j]==0)
            {
                system("clear");
                cout<<"All out"<<endl;
                cout<<score[j]<<endl;
                break;
            }
            else if(scr=="score")
            {
                cout<<"The Score is : "<<score[j]<<endl;;
                i=i-1;
            }
       else if (j==1 && score[0]<=score[1])
            {
                if (score[0]==score[1]) {
                cout<<"Its already draw"<<endl;
           }
           else
               break;
       }
        else
          {
              cout<<"Please enter correct value"<<endl;
              i=i-1;
          }

            file<<"Score : "<<score[j]<<"\tBalls : "<<i<<endl;
            
            
        }
        
        
    }
    if (score[1]>score[0]) {
        cout << "Match completed :"<<obj.team2<<" won by"<<endl;       //condition for wining
        cout<<score[1]-score[0]<<endl;
    }
    if (score[1]<score[0]) {
        cout<< "Match completed :"<<obj.team1<<" won by "<<endl;
        cout<<score[0]-score[1]<<endl;
    }
    if (score[1]==score[0]) {
        cout<<"Match completed, its a draw"<<endl;
        cout<<score[0]<<endl;
    }
    file<<"End !!! see you tommorow"<<endl<<endl;
    file.close();

    
    return 0;
}
