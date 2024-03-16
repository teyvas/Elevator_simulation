#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstdlib>
#include<cmath>
#define pb push_back

int main(){
     long long number_of_floors, time_total=0, passangers_total,
     requests_total, passenger_per_trip;
     int lift_place;
     std::vector<int> callings_total;
     std:: map<int, int>statistic;
         int time_of_sim=30;

     std:: cout<<"Input the number of floors: ";
     std:: cin>>number_of_floors;
     
     std:: cout<<"Input time duration: ";
     std:: cin>>time_of_sim; std:: cout<<'\n';
     std:: cout<<"Time between floors (in seconds): ";
     int interval;
     std:: cin>>interval;
     std:: cout<<"Simulating passengers calls..."<<'\n';


     lift_place=number_of_floors;

     srand(time(0));
     for(int i=0; i<time_of_sim;i++){
          callings_total.pb(1+ (rand() % number_of_floors) );

     }
     

     for(auto e:callings_total){
          statistic[e]++;
          std::cout<<"Passenger calls from floor "<<e<<"\n";
     }
     std::cout<<std::endl;
     std :: map<int,int>::iterator it;

   

     for(int i=0; i < callings_total.size() ;i ++){
          time_total+=abs(lift_place-callings_total[i])*interval;
          lift_place=callings_total[i];
          
     }

     std:: cout<<"Simulation completed."<<"\n"<<"Analyses..."<<'\n';

     std:: cout<<"Total calls: "<<callings_total.size()<<'\n';
     if(time_total/60!=0){
          std:: cout<<"Total time needed for all calls: "<<time_total/60<<" minutes"<<'\n';
     }
     else{
          std:: cout<<"Total time needed for all calls: "<<time_total<<" seconds"<<'\n';
     }
     
     std:: cout<<"Frequency of calls from each floor: "<<std::endl;


     for(it=statistic.begin(); it!=statistic.end(); it++){
          std:: cout<<"Floor "<<it->first<<": "<<it->second<<" calls" <<'\n';
     }
     
    
}