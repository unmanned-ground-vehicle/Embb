#include <iostream>
//#include <stdlib.h>

using namespace std;

const float l=1.2; 		//Max width of vehicle allowed is 4 feet i.e. approximately 1.2m

float vel_right,vel_left;	// Vr and Vl
float vel_linear,vel_angular;	// Linear velocity and angular velocity of the vehicle
float R;			//Instantaneous Center of Curvature
float differential_velocity=0;	//Vr-Vl
float omega_l=0,omega_r=0;	//rpm of the left wheel and right wheel
float wheel_radius=0.15;	//radius of the wheel used
char dir;

int main()
{
	
	cout<<"Enter Angular Velocity of UGV \n";
	cin>>vel_angular;

	cout<<"Enter Linear Velocity of UGV \n";
	cin>>vel_linear;

	R = vel_linear/vel_angular;

	vel_right = vel_angular*(R+(l/2));
	vel_left = vel_angular*(R-(l/2));


	
	
	differential_velocity=vel_left-vel_right;

	if(differential_velocity ==0)
	{

		cout<<"Linear Velocity of right wheel (in m/s) should be : "<<vel_right<<" \n";
		cout<<"Linear Velocity of left wheel (in m/s) should be : "<<vel_left<<" \n";
	
		omega_l=(vel_left/wheel_radius)*9.55;
		omega_r=(vel_right/wheel_radius)*9.55;

		cout<<"RPM of left wheel required :"<<omega_l<<" rpm \n";
		cout<<"RPM of right wheel requires :"<<omega_r<<" rpm \n";

	}

	else
	{
		cout<<"Turn left or right (l/r) ? \n";
		cin>>dir;
		if(dir=='l')
		{
			omega_l=-1*vel_angular;
			omega_r=vel_angular;
		}
		else
		{
			omega_l=vel_angular;
			omega_r=-1*vel_angular;
		}

		cout<<"Linear Velocity of right wheel (in m/s) should be : "<<vel_right<<" \n";
                cout<<"Linear Velocity of left wheel (in m/s) should be : "<<vel_left<<" \n";

                omega_l=(vel_left/wheel_radius)*9.55;
                omega_r=(vel_right/wheel_radius)*9.55;

                cout<<"RPM of left wheel required :"<<omega_l<<" rpm \n";
                cout<<"RPM of right wheel requires :"<<omega_r<<" rpm \n";


	}
	return 0;	
}
