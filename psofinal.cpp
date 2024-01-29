#include <iostream>
#include <cstdlib>
#include<math.h>
using namespace std;
	double particalcount=20;//�ɤl�� 
	double w=1;//�D�ʤ��v�� 
	double c1=2;//����̨Τ��v�� 
	double c2=2;//����̨Τ��v�� 
	double gbest[2];//����̨θ� 
	double min_pos=-100;//�̤p�� 
	double max_pos=100;//�̤j�� 
	double max_v=(max_pos-min_pos);//�t�׽d�� 

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
void refresh(){//�첾 
		for(int i=0;i<particalcount;i++){
		swarm[i].velocity_x=w*swarm[i].velocity_x+RND()*c1*(swarm[i].pbest[0]-swarm[i].positionx)+RND()*c2*(gbest[0]-swarm[i].positionx);			
		swarm[i].velocity_y=w*swarm[i].velocity_y+RND()*c1*(swarm[i].pbest[1]-swarm[i].positiony)+RND()*c2*(gbest[1]-swarm[i].positiony);			
		if(swarm[i].velocity_x<-max_v) swarm[i].velocity_x=-max_v;      // ����x�̤p�t��
           else if(swarm[i].velocity_x>max_v) {							// ����x�̤j�t��
			swarm[i].velocity_x=max_v;}
		if(swarm[i].velocity_y<-max_v) swarm[i].velocity_y=-max_v;      // ����y�̤p�t�� 
           else if(swarm[i].velocity_y>max_v) {							// ����y�̤j�t��
			swarm[i].velocity_y=max_v;}	

		swarm[i].positionx=swarm[i].positionx+swarm[i].velocity_x;
		swarm[i].positiony=swarm[i].positiony+swarm[i].velocity_y;
		
		if(swarm[i].positionx>max_pos) swarm[i].positionx=max_pos; // ����̤j��m
        else if(swarm[i].positionx<min_pos) {swarm[i].positionx=min_pos;} // ����̤p��m
		
		if(swarm[i].positiony>max_pos) swarm[i].positiony=max_pos; // ����̤j��m
        else if(swarm[i].positiony<min_pos) {swarm[i].positiony=min_pos;} // ����̤p��m
			}
		}
void refreshpbest(){//��pbest
		double temp;
		for(int i=0;i<particalcount;i++){			
			temp=fabs(swarm[i].pbest[0])+fabs(swarm[i].pbest[1]);	
			fitnessfunction(i);				
			if(temp>swarm[i].fitness){//��s�᪺fitness���p���ܴN��ipbest				
				swarm[i].pbest[0]=swarm[i].positionx;
				swarm[i].pbest[1]=swarm[i].positiony;
				}
				
		}
}	
void refreshgbest(){//��gbest		
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
	while((int)gbest[0]!=0||(int)gbest[1]!=0){//��ӳ��^�N��0.�h�N����	
	count++;
	refresh();//�첾 
	refreshpbest();//��pbest 	
	refreshgbest();//��gbest
	cout<<"["<<gbest[0]<<"]"<<"["<<gbest[1]<<"]"<<"\n";	
	}
	cout<<"["<<(int)gbest[0]<<"]"<<"["<<(int)gbest[1]<<"] "<<count++<<"\n";			 
	return 0;
	}	

