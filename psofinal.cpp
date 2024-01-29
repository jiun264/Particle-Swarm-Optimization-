#include <iostream>
#include <cstdlib>
#include<math.h>
using namespace std;
	double particalcount=20;//采计 
	double w=1;//篋┦ぇ舦 
	double c1=2;//砰程ㄎぇ舦 
	double c2=2;//办程ㄎぇ舦 
	double gbest[2];//办程ㄎ秆 
	double min_pos=-100;//程 
	double max_pos=100;//程 
	double max_v=(max_pos-min_pos);//硉絛瞅 

double RND(){	
	return ((1.0*rand())/RAND_MAX);
}
struct partical
{
	double positionx;
	double positiony;
	double velocity_x;
	double velocity_y;
	double fitness;
	double pbest[2];
}swarm[20];

void initial(){
	for(int i=0;i<particalcount;i++){
	swarm[i].positionx=(rand()%201)-100;//-100~100
	swarm[i].positiony=(rand()%201)-100;//-100~100
	swarm[i].velocity_x=((rand()%201)-100);
	swarm[i].velocity_y=((rand()%201)-100);
	swarm[i].pbest[0]=swarm[i].positionx;
	swarm[i].pbest[1]=swarm[i].positiony;
}
}
void fitnessfunction(int i){	
		swarm[i].fitness=fabs(swarm[i].positionx)+fabs(swarm[i].positiony);	
		cout<<swarm[i].fitness<<" ";
}
void refresh(){//簿 
		for(int i=0;i<particalcount;i++){
		swarm[i].velocity_x=w*swarm[i].velocity_x+RND()*c1*(swarm[i].pbest[0]-swarm[i].positionx)+RND()*c2*(gbest[0]-swarm[i].positionx);			
		swarm[i].velocity_y=w*swarm[i].velocity_y+RND()*c1*(swarm[i].pbest[1]-swarm[i].positiony)+RND()*c2*(gbest[1]-swarm[i].positiony);			
		if(swarm[i].velocity_x<-max_v) swarm[i].velocity_x=-max_v;      // x程硉
           else if(swarm[i].velocity_x>max_v) {							// x程硉
			swarm[i].velocity_x=max_v;}
		if(swarm[i].velocity_y<-max_v) swarm[i].velocity_y=-max_v;      // y程硉 
           else if(swarm[i].velocity_y>max_v) {							// y程硉
			swarm[i].velocity_y=max_v;}	

		swarm[i].positionx=swarm[i].positionx+swarm[i].velocity_x;
		swarm[i].positiony=swarm[i].positiony+swarm[i].velocity_y;
		
		if(swarm[i].positionx>max_pos) swarm[i].positionx=max_pos; // 程竚
        else if(swarm[i].positionx<min_pos) {swarm[i].positionx=min_pos;} // 程竚
		
		if(swarm[i].positiony>max_pos) swarm[i].positiony=max_pos; // 程竚
        else if(swarm[i].positiony<min_pos) {swarm[i].positiony=min_pos;} // 程竚
			}
		}
void refreshpbest(){//衡pbest
		double temp;
		for(int i=0;i<particalcount;i++){			
			temp=fabs(swarm[i].pbest[0])+fabs(swarm[i].pbest[1]);	
			fitnessfunction(i);				
			if(temp>swarm[i].fitness){//穝fitness耕杠碞メ秈pbest				
				swarm[i].pbest[0]=swarm[i].positionx;
				swarm[i].pbest[1]=swarm[i].positiony;
				}
				
		}
}	
void refreshgbest(){//衡gbest		
	double min=swarm[0].fitness;
	for(int i=1;i<particalcount;i++){
		if(swarm[i].fitness<min)
		{
		min=swarm[i].fitness;
		gbest[0]=swarm[i].pbest[0];
		gbest[1]=swarm[i].pbest[1];
		}	
	}
} 
int main(void){
	int count=1;
	initial();
	for(int i=0;i<particalcount;i++){		
	fitnessfunction(i);
	}	
	refreshgbest();	
	while((int)gbest[0]!=0||(int)gbest[1]!=0){//ㄢ常禴0.碞挡	
	count++;
	refresh();//簿 
	refreshpbest();//衡pbest 	
	refreshgbest();//衡gbest
	cout<<"["<<gbest[0]<<"]"<<"["<<gbest[1]<<"]"<<"\n";	
	}
	cout<<"["<<(int)gbest[0]<<"]"<<"["<<(int)gbest[1]<<"] "<<count++<<"\n";			 
	return 0;
	}	

