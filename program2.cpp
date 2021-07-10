#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415
//array size
#define size 10 

//class shape
class Shape{
	public:
		Shape(){}
		virtual double getArea(){
			return 0;
		}
		virtual void read(){}
		virtual void print(){}
};//end of class shape

//class Point
class Point{
	private:
		double x;
		double y;
	public:
		Point(){
			x=0.0;
			y=0.0;
		}
		void set(double x,double y){
			this->x=x;
			this->y=y;
		}
		double getX(){
			return x;
		}
		double getY(){
			return y;
		}
};//end of class point

//class Circle inherit the class Shape
class Circle:public Shape{
	private:
		double radius;
	public:
		Point p; //composition
		Circle(){
			radius=0.0;
		}
		void read(){
			double x,y;
			cout<<"enter the center coordinates of the circle (x y)=> ";
			cin>>x>>y;
			p.set(x,y);
			cout<<"Enter the circle's radius=> ";
			cin>>radius;
		}
		double getArea(){
			return PI*pow(radius,2);
		}
		void print() {
			cout<<"Circle's center: X= "<<p.getX()<<" Y= "<<p.getY()<<endl;
			cout<<"Circle's radius = "<<radius<<endl;
			cout<<"Circle's area = "<<getArea()<<endl;
		}
};
//class Reactangle inherit the class Shape
class Reactangle:public Shape{
	//private method
	private:
		double getHeight(){
			double height;
			height=p2.getY()-p1.getY();
			//if the height is negatie, making it positive
			if(height<0){
				height=-1*height;
				return height;
			}
			else
				return height;		
		}//end of getHeight
		double getWidth(){
			double width;
			width=p2.getX()-p1.getX();
			//if the width is negatie, making it positive
			if(width<0){
				width=-1*width;
				return width;
			}
			else
				return width;
		}//end of getWidth
	public:
		Point p1,p2;//composition 
		Reactangle(){}
		double getArea() {
			return(getWidth()*getHeight());
		}
		void read() {
			double x1,y1;
			double x2,y2;
			cout<<"Enter the top left corner coordinates of the rectangle (x y) => ";
			cin>>x1>>y1;
			
			p1.set(x1,y1);//passing the coordinates to the class Point
			cout<<"Enter the bottom right corner coordinates of the rectangle (x y) => ";
			cin>>x2>>y2;
			
			p2.set(x2,y2);//passing the coordinates to the class Point
		}
		void print(){
			cout<<"Rectangle's top left corner: X= "<<p1.getX()<<" Y= "<<p1.getY()<<endl;
			cout<<"Rectangle's bottom right corner: X= "<<p2.getX()<<" Y= "<<p2.getY()<<endl;
			cout<<"Rectangle's width = "<<getWidth()<<endl;
			cout<<"Rectangle's height = "<<getHeight()<<endl;
			cout<<"Rectangle's area = "	<<getArea()<<endl;
		}
};

int main(){
	Shape *s; //pointer of class Shape
	Reactangle r[size];//array of object of Reactangle class
	Circle c1[size]; //array of Circle class
	
	int i=0,flag[size];
	double totalArea=0.0;//hold the total area od all shapes
	int choice,choice2;
	while(true){
			//menu 
		cout<<"==========[MENU]============"<<endl;
		cout<<"1. Add a shape"<<endl;
		cout<<"2. Print all shapes"<<endl;
		cout<<"3. Calculate total area"<<endl;
		cout<<"4. Exit"<<endl<<endl;
		cout<<"Your choice => ";	
		cin>>choice;
		cout<<endl<<endl;
		if(choice==1){
			cout<<"What type of shape you want to enter?"<<endl;
			cout<<"1. Circle"<<endl;
			cout<<"2. Rectangle"<<endl<<endl;
			cout<<"Your choice => ";
			cin>>choice2;
			if(choice2==1){
				s=&c1[i];
				s->read();
				s->getArea();
				flag[i]=1;
			}
			else{
				s=&r[i];
				s->read();
				s->getArea();
				flag[i]=2;
			}
			cout<<endl<<endl;
		}// end of if
		//print the shape 
		else if(choice==2){
			cout<<endl<<"==========[SHAPE]============"<<endl;
			for(int y=0;y<i;y++){
					cout<<"shape "<<y+1<<endl;
				if(flag[y]==1){
					s=&c1[y];
					s->print();
				}
				else if(flag[y]==2){
					s=&r[y];
					s->print();	
				}
			}//end of for loop
			cout<<endl<<endl;
		}//end of first else if
		//second else if
		else if(choice==3){
			for(int y=0;y<i;y++){
				if(flag[y]==1){
					s=&c1[y];
					totalArea=totalArea+s->getArea();
				}
				else if(flag[y]==2){
					s=&r[y];
					totalArea=totalArea+s->getArea();	
				}
			}//end of for loop
			cout<<endl<<"Total Area= "<<totalArea<<endl<<endl;
		}//end of second else if 
		else if(choice==4)
			exit(1);
	i++;	
	}//end of while loop
}

