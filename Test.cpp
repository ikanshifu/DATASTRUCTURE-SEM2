#include <iostream>

int main(){
	int age;
	char name[100];
	std::cout<<"Hello! Welcome to our program!"<<std::endl;
	std::cout<<"Please enter your name: ";
	std::cin>>name;
	std::cout<<"Please enter age: ";
	std::cin>>age;
	std::cout<<"Saving in..."<<std::endl;
	for(int i = 10;i>0;i--){
		std::cout<<i<<std::endl;
	}
	std::cout<<"Data sucessfully recorded"<<std::endl;
	std::cout<<"Your name is "<<name<<std::endl;
	std::cout<<"You are "<<age<<" years old"<<std::endl;
	
	
	
	return 0;
}
