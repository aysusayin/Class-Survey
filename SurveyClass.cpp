#include "SurveyClass.h"
#include <map>

//constructor creates a linkedlist to store members
SurveyClass :: SurveyClass(){
    members = new LinkedList();
}
//copy constructor
SurveyClass :: SurveyClass(const SurveyClass &other){
    this->members = other.members;
}
//operation overload
SurveyClass& SurveyClass ::operator=(const SurveyClass& list){
    //if this object contains members in linked list. delete it and assign the parameters list to that.
    if(!this->members)
        delete members;
    this->members = new LinkedList(*(list.members));
}
//destructor
SurveyClass :: ~SurveyClass(){
    delete members;
}
//this method adds new member to linkedlist
void SurveyClass :: addMember(const Member& newMember){
    this->members->pushTail(newMember);
}
//this method calculates average age
float SurveyClass :: calculateAverageAge(){
     
    int size = this->members->length;
    if(size==0)
        return 0;
    float total=0;
    Node *tmp=members->head;
    while(tmp){
        total+=tmp->data.age;
        tmp = tmp->next;
    }
    //following lines rounds result to 2 digits after comma.
    int presicion = 1000*total/size;
    if(presicion%10>=5){
        presicion=(presicion+10)/10;
    }else
        presicion/=10;
    return (float) presicion/100;
}
//this method finds the most favourite color.
string SurveyClass :: findMostFavouriteColor(){
    if(this->members->length==0)
        return "";
    std::map<string,int> colorNumbers;
    Node *tmp = members->head;
    string maxColor=tmp->data.color;
//store all colors in map. key values are colors and values are how many times this color is said
    while (tmp){
        string color = tmp->data.color;
        auto it = colorNumbers.find(color);
        if(it!=colorNumbers.end()){
            colorNumbers[color]++;
        }else{
            colorNumbers[color]=1;
        }
        //most favourite color is stored in maxColor and after each loop it is checked if the newly added color is most favorite.
        if(colorNumbers[maxColor]<colorNumbers[color])maxColor=color;
        tmp=tmp->next;
    }
     return maxColor;

}


