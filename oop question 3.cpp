#include<iostream>
using namespace std;

class User{
	public:
	string name;
	int age;
	string license;
	string contact;
	int userid;
	
	void registeruser(){
		cout<<"enter name = ";
		cin>>name;
		cout<<"enter age = ";
		cin>>age;
		cout<<"enter id = ";
		cin>>userid;
		cout<<"enter license type(Learner,Itermediate,Full) = ";
		cin>>license;
		cout<<"enter contact = ";
		cin>>contact;
		
	}
	
	void updatedetails(){
	cout<<"update name = ";
	cin>>name;
	cout<<"update age = ";
	cin>>age;
	cout<<"update id = ";
	cin>>userid;
	cout<<"update license type = ";
	cin>>license;
	cout<<"update contact = ";
	cin>>contact;
	}
	void displayuserinfo(){
		cout<<"User Details: \n";
		cout<<"name: "<<name<<"\n age: "<<age<<"\n userid: "<<userid<<"\n license type: "<<license<<"\n contact: "<<contact<<endl;
		
	}
};

class Vehicle{
	public:
		string model;
		double rentalprice;
		string eligibilitytype;
		
		Vehicle(string m,double r,string e){
			model=m;
			rentalprice=r;
			eligibilitytype=e;
			
		}
		void displayvehicledetails(){
			cout<<"Model: "<<model<<"\n Rentalprice: "<<rentalprice<<"\n Eligibility Type: "<<eligibilitytype;
			
		}
		bool iseligible(string license){
		  	 if (license == eligibilitytype) {
        return true; 
    } 
    else if (eligibilitytype == "Intermediate" && license == "Full") {
        return true;  
    } 
    else if (eligibilitytype == "Learner" && (license == "Intermediate" || license == "Full")) {
        return true; 
    }
    return false; 
}
		
};

class Rentalsystem{
	private:
		User* user;
		Vehicle** vehicles;
		int vehiclecount;
		
	public:
		Rentalsystem(){
			user= new User();
			vehiclecount=0;
			vehicles=new Vehicle*[10];
			
		}
		
		~Rentalsystem(){
			delete user;
			for(int i=0;i<vehiclecount;i++){
				delete vehicles[i];
			}
		}
		void addvehicle(string model,double price,string eligibility){
			if(vehiclecount<10){
				vehicles[vehiclecount++]=new Vehicle(model,price,eligibility);
			}else{
				cout<<"Vehicle storage full ! \n";
			}
		}
		
		void displayvehicles(){
			cout<<"Available vehicles: \n";
			for(int i=0;i<vehiclecount;i++){
				cout<<i+1<<".";
				vehicles[i]->displayvehicledetails();
			}
		}
		void rentvehicle(){
			cout<<"choose a vehicle to rent :";
			int choice;
			cin>>choice;
			
			if(choice>0 && choice <= vehiclecount){
				Vehicle* selectedvehicle = vehicles[choice - 1];
			
			
			if(selectedvehicle->iseligible(user->license)){
				cout<<"you have successfully rented "<<selectedvehicle->model<<" for $"<<selectedvehicle->rentalprice<<" per day"<<endl;
			}else{
				cout<<"you are not eligible to rent this vehicle "<<endl;
			}
		}else{
			cout<<"invalid choice \n";
		}
		}
		void start(){
			user->registeruser();
			displayvehicles();
			rentvehicle();
		}
};

int main(){
	Rentalsystem system;
	system.addvehicle("toyota corrola", 40.00,"learner");
	system.addvehicle("Honda Civic", 50.0, "Intermediate");
    system.addvehicle("BMW X5", 100.0, "Full");
	system.start();
	
	return 0;
}

