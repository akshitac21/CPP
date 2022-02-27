//operator overloading via CodeBeauty

#include<list>
#include <iostream>
#include <string>
using namespace std;

struct YoutubeChannel
{
    string Name;
    int SubscribersCount;

    YoutubeChannel(string name, int subscribersCount) //constructor
    {
        Name = name;
        SubscribersCount = subscribersCount;
    }
    bool operator == (const YoutubeChannel& channel) const
    {
        return this->Name == channel.Name;
    }
};

ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel)
{
    COUT<<"Name: "<<ytChannel.Name << endl;
    COUT<<"Subscribers: "<<ytChannel.SubscribersCount<<endl;
    return COUT; 
}

struct MyCollection
{
    list<YoutubeChannel>myChannels;

    void operator += (YoutubeChannel& channel) //member funtion of MyCollection
    {
        //this->myChannels means give me myChannels from MyCollection structure
        this->myChannels.push_back(channel); //yt1 will be added to the list of myChannels
    }
    void operator -= (YoutubeChannel& channel) //member funtion of MyCollection
    {
        this->myChannels.remove(channel);
    }  
};

ostream& operator << (ostream& COUT, MyCollection& MyCollection)
{
    for(YoutubeChannel ytChannel : MyCollection.myChannels) //print elements of MyCollection
        COUT << ytChannel << endl;
    return COUT; 
    //for each youtube channel inside MyCollection.myChannels, print info of that channel
}

int main()
{
    YoutubeChannel yt1 = YoutubeChannel("Akshita", 75000); //yt1 is a data type of YoutubeChannel
    YoutubeChannel yt2 = YoutubeChannel("Second Channel", 80000); //yt1 is a data type of YoutubeChannel
    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2; //remove element
    cout << myCollection;
    //cout << yt1;
    //cout<<yt1<<yt2;
    //operator<<(cout,yt1);

}
