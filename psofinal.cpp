#include <iostream>
#include <cstdlib>
#include<math.h>
#include <time.h>
using namespace std;
	double particalcount=10;//粒子數 
	double w=1;//慣性之權重 
	double c1=2;//自體最佳之權重 
	double c2=2;//全域最佳之權重 
	double gbest[2];//全域最佳解 
	double min_pos=-100;//最小值 
	double max_pos=100;//最大值 
	double max_v=(max_pos-min_pos)/2;//速度範圍 

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
}swarm[10];

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
void refresh(){//位移 
		for(int i=0;i<particalcount;i++){
		swarm[i].velocity_x=w*swarm[i].velocity_x+RND()*c1*(swarm[i].pbest[0]-swarm[i].positionx)+RND()*c2*(gbest[0]-swarm[i].positionx);			
		swarm[i].velocity_y=w*swarm[i].velocity_y+RND()*c1*(swarm[i].pbest[1]-swarm[i].positiony)+RND()*c2*(gbest[1]-swarm[i].positiony);			
		if(swarm[i].velocity_x<-max_v) swarm[i].velocity_x=-max_v;      // 限制x最小速度
           else if(swarm[i].velocity_x>max_v) {							// 限制x最大速度
			swarm[i].velocity_x=max_v;}
		if(swarm[i].velocity_y<-max_v) swarm[i].velocity_y=-max_v;      // 限制y最小速度 
           else if(swarm[i].velocity_y>max_v) {							// 限制y最大速度
			swarm[i].velocity_y=max_v;}	

		swarm[i].positionx=swarm[i].positionx+swarm[i].velocity_x;
		swarm[i].positiony=swarm[i].positiony+swarm[i].velocity_y;
		
		if(swarm[i].positionx>max_pos) swarm[i].positionx=max_pos; // 限制最大位置
        else if(swarm[i].positionx<min_pos) {swarm[i].positionx=min_pos;} // 限制最小位置
		
		if(swarm[i].positiony>max_pos) swarm[i].positiony=max_pos; // 限制最大位置
        else if(swarm[i].positiony<min_pos) {swarm[i].positiony=min_pos;} // 限制最小位置
			}
		}
void refreshpbest(){//算pbest
		double temp;
		for(int i=0;i<particalcount;i++){			
			temp=fabs(swarm[i].pbest[0])+fabs(swarm[i].pbest[1]);	
			fitnessfunction(i);				
			if(temp>swarm[i].fitness){//更新後的fitness較小的話就丟進pbest				
				swarm[i].pbest[0]=swarm[i].positionx;
				swarm[i].pbest[1]=swarm[i].positiony;
				}
				
		}
}	
void refreshgbest(){//算gbest		
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
	srand( time(NULL) );
	int count=1;
	initial();
	for(int i=0;i<particalcount;i++){		
	fitnessfunction(i);
	}	
	refreshgbest();	
	while((int)gbest[0]!=0||(int)gbest[1]!=0){//兩個都跌代到0.多就結束	
	count++;
	refresh();//位移 
	refreshpbest();//算pbest 	
	refreshgbest();//算gbest
	cout<<"["<<gbest[0]<<"]"<<"["<<gbest[1]<<"]"<<"\n";	
	}
	cout<<"["<<(int)gbest[0]<<"]"<<"["<<(int)gbest[1]<<"] "<<count++<<"\n";			 
	return 0;
	}	
