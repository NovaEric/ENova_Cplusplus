#include<iostream>
using namespace std;

int main(){

	int cookies_box = 24;
	int box_container = 75;
	int cookies, cookies_left, boxes_left, total_container, total_cookies_box;


	cout << "Enter Total Cookies" <<endl;
	cin >> cookies;
	cout << "Total Cookies Wanted to ship: " << cookies << endl << "Total Cookies Allow per Box: " << cookies_box
		<< endl << "Total Cookies Allow per Container: " << box_container << endl;
	
	//cookies calculation

	total_cookies_box = cookies / cookies_box;
	cookies_left = cookies % cookies_box;

	//boxes calculation

	total_container = total_cookies_box / box_container;
	boxes_left = total_cookies_box % box_container;

	//outputs

	cout << "Total Boxes of Cookies: " << total_cookies_box << endl << "Total Cookies leftover: " 
		<< cookies_left << endl << "Total Containers per Cookies Box: " << total_container 
		<< endl << "Total Boxes of Cookies leftover: " << boxes_left << endl;

	system("pause");
	return main();


}