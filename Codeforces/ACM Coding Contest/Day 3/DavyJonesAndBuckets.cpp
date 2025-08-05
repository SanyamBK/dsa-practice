#include<iostream>
using namespace std;
int main()
{
    int score;
    cout<<"Enter the score you got in the quiz"<<endl;
    cin>>score;
    if(9<=score<=10)
    {
        cout<<"Your score is A"<<endl;
    }
    else if(7<=score<=8)
    {
        cout<<"Your score is B"<<endl;
    }
    if(score<=6 && score >= 5)
    {
        cout<<"Your score is C"<<endl;
    }
    if(score<=5 && score >= 4)
    {
        cout<<"Your score is D"<<endl;
    }
    if(score<=4 && score >= 3)
    {
        cout<<"Your score is E"<<endl;
    }
    if(score<3)
    {
        cout<<"Your score is F"<<endl;
    }
    return 0;
}