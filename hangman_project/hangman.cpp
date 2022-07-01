#include<fstream>
#include<ios>
#include<limits>
#include<iostream>
#include<string>
using namespace std;

string indentation="\t\t\t\t\t";
char ch;

void PRINT_INSTRUCTIONS()
{
	system("clear");
        cout<<"\n\n\n\n\n";
        cout<<indentation<<"\t\t     HANGMAN"<<endl;
        cout<<indentation<<"\t\t   INSTRUCTIONS"<<endl;
        cout<<endl<<endl;
        cout<<indentation<<"You will be given a word with dashed characters."<<endl;
        cout<<indentation<<"You have to enter a letter."<<endl;
        cout<<indentation<<"If the letter is present in the word then all its occurences will be filled"<<endl;
        cout<<indentation<<"otherwise you will loose one chance."<<endl;
        cout<<indentation<<"There will be a total of 5 chances."<<endl;
        cout<<endl<<indentation<<"   ALL THE BEST!!"<<endl;
}


void WON_MESSAGE()
{
	cout<<indentation<<"\t\t      Hurray!!"<<endl;
        cout<<indentation<<"\t\tYou got the answer right"<<endl;
}


void LOST_MESSAGE(string wd)
{
	cout<<indentation<<"\t\tOOPs your chances are over.\n";
        cout<<indentation<<"\t\tThe correct word is "<<wd<<endl;
}



void PLAY()
{
	int chances;
        char junk;
        string wd;
        string check="";
        int num_words=46;


	ifstream fin;
        fin.open("words.txt",ios::in);


	while(ch=='Y')
        {
                chances=5;
                srand(time(0));
                int num=1+(rand()%6);

                for(int i=1;i<num;i++)
                        fin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(fin,wd,'\n');
                wd.pop_back();

                check.assign(wd.size(),'_');
                while(wd!=check && chances>0)
                {
                        system("clear");
                        for(int i=0;i<17;i++)
                                cout<<endl;
                        cout<<indentation<<"\t\t";

                        for(int i=0;i<check.size();i++)
                                cout<<check[i]<<" ";
                        cout<<endl;
                        cout<<indentation<<"\t\tChances remaining: "<<chances<<endl;
                        cout<<indentation<<"\t\tEnter an alphabet: ";
                        cin>>ch;
                        junk=getchar();
                        if(wd.find(ch)>=wd.size())
                                chances--;
                        else
                        {
                                for(int i=0;i<wd.size();i++)
                                        if(wd[i]==ch)
                                                check[i]=ch;
                        }
                }
                system("clear");
                for(int i=0;i<18;i++)
                        cout<<endl;

                if(wd==check)
                {
                        cout<<indentation<<"\t\t   ";

                        for(int i=0;i<check.size();i++)
                                cout<<check[i]<<" ";
                        cout<<endl;

                        WON_MESSAGE();
                }
                else
                {
                        LOST_MESSAGE(wd);
                }

                junk=getchar();
                system("clear");
                for(int i=0;i<18;i++)
                        cout<<endl;
                cout<<indentation<<"\t\tPress 'Y' to play the game again."<<endl;
                cout<<indentation<<"\t\tPress 'N' to quit the game."<<endl;
                cout<<indentation<<"\t\t      ";
                cin>>ch;
                junk=getchar();
        }
	fin.close();
}



int main()
{
	char junk;

	PRINT_INSTRUCTIONS();

	cout<<indentation<<"Press 'Y' to continue to the game."<<endl;
        cout<<indentation<<"Press 'N' to quit the game."<<endl;
	cout<<indentation<<"      ";
	cin>>ch;
	junk=getchar();

	PLAY();

	system("clear");
	for(int i=0;i<15;i++)
		cout<<endl;
	cout<<indentation<<"\t\t\tTHANK YOU";
	junk=getchar();
	system("clear");
	return 0;
}
