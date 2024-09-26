#include<iostream>
#include<vector>
using namespace std;


class MyCalendar {
public:

    vector<pair<int,int>>pairs;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto pair:pairs){
            int r_start=pair.first;
            int r_end=pair.second;
            if(start<r_end && end>r_start) return false;
        }
    pairs.push_back(make_pair(start,end));
    return true;
    }
};

int main(){
    MyCalendar* myCalendar=new MyCalendar();
    cout<<myCalendar->book(10,20)<<endl;
    cout<<myCalendar->book(15,25)<<endl;
    cout<<myCalendar->book(20,30)<<endl;
    delete myCalendar;
}