//Header Files
//Inventory Management System For Provision /Grocery
// C_C++
//Tharun

#include<iostream>//input and output stream.
#include<stdlib.h>
#include<fstream>//file handling
#include<algorithm>//for sorting and searching
#include<cstdio>
#include<conio.h>
#include<vector>//stl library
#include<numeric>//for basic mathematical functions

//Namespace Standard.
using namespace std;

//Declarations of Functions
void addnew();
void addnew1();
void disp();
void displ();
void display1();
void Order();
void display();
void update();
void remove();
void orderDetails();
void ownerHompeage();
void staffHomepage();

//Storing items in the Class members
class Inventory
{
private:
	char name[20], pass[15];
	float price; int quantity;
 public:
	//Inventory();
	void get();
	void show();
	int  stockAvail(char nm[30]);
	virtual void withd(int qty);
	void update(int qty);
	~Inventory();
};
//Customer Class for Storing names and Bills
class Customer :virtual protected Inventory {
private:
	string s;
	string in;
public:
	Customer() {

	}
	//parameterized constructor 
	Customer(string name,string  num) {
		s = name;
		in= num;
	}
	//Exception Handling for name
	void setDetails() {
	Name:
		std::cin >> s;
		int i = 0;
		try {
			for (unsigned int i = 0;i < s.length();i++)
			{
				if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] == ' ')
				{

				}
				else {
					cout << "Enter valid Name:\n";
					break;
				}
			}
		}
		catch (string s)
		{
			goto Name;
		}
	}
	//Exception Handling for number
	void setDetails1(){
	Number:
		int j = 0;
		std::cin >> in;
		try {
			for (unsigned int j = 0;j < in.length();j++)
			{
				if (in[j] >= '0' && in[j] <= '9')
				{

				}
				else {
					cout << "Enter valid Number\n";
					break;
				}
			}
		}
		catch(string in){
		goto Number;
		}
	}
	//Displaying Customer Details
	void Cust()
	{
		cout<<"\n" <<"\t\t" << s <<"\t\t\t" << in<<"\n";
	}
	//Cost of the items;
	void billDetails() {
		cout << "price details: ";
	}
	~Customer() {
		exit(0);
	}
};

int n;
string str;
string in;
vector<int>tp;
vector<string>ts;
vector<int>tq;
vector<string>tpro;
vector<int>tqua;
vector<float>tpri;

//Creating objects for Class in C++.
Inventory In;
Customer Cu;
ifstream inputFile;
ofstream outputFile;
fstream fileIO;

//Inventory::Inventory()
//{
//}
//storing product details
void Inventory::get()
{

	std::cin >> name >> price >> quantity;
	tpro.push_back(name);
	tqua.push_back(quantity);
	tpri.push_back(price);
}

//Dislaying storing details
void Inventory::show()
{
	//sort(name.beg(), name.end(), greater());
	cout << "\n"
		<< name
		<< "\t\t\t"
		<< quantity
		<< "\t\t\t"
		<< price;
}

//checking Stock
int Inventory::stockAvail(char nm[30])
{
	if (strcmp(nm, name) == 0)
		return 0;
	else
		return 1;
}

//Updating the Stock while taking order
void Inventory::withd(int qty)
{
	if (quantity >= qty)
	{
		int pr =static_cast<int>( price * qty);
		quantity -= qty;
		cout << "\n\nStock updated.\n";
		cout << "\n\nTotal price to be paid:" << pr;
		tp.push_back(pr);
		if (quantity <= 5)
		{
			cout << "\n\nStock is Very low Update the Stock\n";
		}
		else
		{

		}
	}
	else
		cout << "\n\nInsufficient stock";
}

//updating by working owner
void Inventory::update(int qty)
{
	quantity = qty;
	cout << "\n\nStock updated.";
	if (quantity <= 5)
	{
	cout << "\n\nStock is low for Update Inform To owner!!!";
	}
	else
	{
	}
}

//Destroy the elements.
Inventory::~Inventory()	
{
	cout << "Application is closing!!";
}

//Main Method
int main()
{
	int a;
	cout << "\n\n		Welcome To Store\n";
Userpage:
	cout << "\n\t\t Inventory Management Homepage Users";
	cout << "\n\n\t\t 1.Owner Homepage\n\n\t\t "
		<< "2.Staff Homepage\n\n\t\t"
		<<" 3.Stays in Homepage\n\n\t\t"
		<<" 4.EXIT."
		<< "\n\n\n\t Choice : \t";
	std::cin >> a;
	if (a == 1)
	{
		ownerHompeage();
	}
	else if (a == 2)
	{
		staffHomepage();
	}
	else if (a==3)
	{
		
		goto Userpage;
		//exit(0);
	}
	else
	{
		cout << "Thanks for Shopping";
		exit(0);
	}

}

//Adding New Items Function
void addnew()
{
	system("cls");
	cout << "\nEnter the Name followed "
		 <<"By the price and then by the quantity\n";
	disp();
	system("cls");
	cout << "\nEnter the No. of Products that you wish to add: ";
	std::cin >> n;
	if (n != 0)
	{
		int  sum = 0;
		outputFile.open("shop.txt", ios::binary | ios::app);
		for (int i = 0;i < n;i++)

		{
			if (i == 0)
			{
				system("cls");
			}
			cout << "\n\nInput the name, price and"
				<<" the quantity of item respectively\n\n";
			In.get();
			outputFile.write((char*)&In, sizeof(In));
			cout << "\n\nitem updated";
			std::cin.get();


		}
		cout << "\n\nStock Updated!!";


		outputFile.close();
		std::cin.get();
		system("cls");
		disp();
	}

	else
	{

		outputFile.close();
		std::cin.get();
		system("cls");
		cout << "\n\nNo items to be added";

	}
}

//adding customer deatils
void addnew1()
{
	string str;
	string str2;
	string temp="The products purchased from the Store Quantity and Price";
	fileIO.open("cust.txt",ios::out|ios::in | ios::binary);
	cout << "\n\nInput the Customer name, phone number Respectively  \n\n";
	Cu.setDetails();
	cin.get();
	Cu.setDetails1();
	fileIO.write((char*)&Cu, sizeof(Cu));
	fileIO << temp;
	std::cin.get();
	fileIO.close();
}

//customer Ordering Products
void Order()
{
	system("cls");
	char temp[100];int qty;
	int i = 0;
	long pos = 0;
	long pos1 = 0;
	disp();
	cout << "\n\nEnter the product's name \n" << endl;
	std::cin >> temp;
	ts.push_back(temp);
	cout << "\n\nEnter quantity: \n" << endl;
	std::cin >> qty;
	tq.push_back(qty);
	fileIO.open("shop.txt", ios::binary | ios::out|ios::in);
	outputFile.open("order.txt", ios::binary|ios::out);
	while (fileIO)
	{
		int pos = static_cast<int>(fileIO.tellp());
		fileIO.read((char*)&In, sizeof(In));
		if (In.stockAvail(temp) == 0)
		{
			In.withd(qty);
			fileIO.seekp(pos);
			fileIO.write((char*)&In, sizeof(In));
			i++;
			break;
		}
	}
	while (outputFile)
	{
		outputFile.write((char*)&In, sizeof(In));
		break;
	}
	if (i != 1)
		cout << "\n\n!!Record not found!!";
	fileIO.close();
	std::cin.get();
	outputFile.close();
	disp();
}

//Deleting the Products
void remove()
{
	
system("cls");
disp();
	int i = 0;
	char temp[30];
	cout << "\n\t\t\t\tDelete Record";
	cout << "\n\nEnter the name of the product:";
	std::cin >> temp;
	tpro.erase(remove(tpro.begin(), tpro.end(), temp), tpro.end());
	outputFile.open("temp.txt", ios::binary);
	inputFile.open("shop.txt", ios::binary);
	outputFile.seekp(0, ios::beg);
	while (!inputFile.eof())
	{
		inputFile.read((char*)&In, sizeof(In));
		if (!inputFile.eof())
			if (In.stockAvail(temp) == 0)
			{
				In.show();
				cout << "\n\n\t\tRecord deleted";
				i++;
			}
			else
				outputFile.write((char*)&In, sizeof(In));
	}
	if (i == 0)
		cout << "\n\n!!Record not found!!";
	inputFile.close();
	outputFile.close();
	remove("shop.txt");
	i=rename("temp.txt","shop.txt");
	if (i == 1)
	{

	}
}

//Displaying The Products
void disp()
{
	int i = 1;
	string item;
	cout << "\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\tPRICE";
	inputFile.open("shop.txt", ios::binary);
	while (!inputFile.eof())
	{
		inputFile.read((char*)&In, sizeof(In));
		if (!inputFile.eof())
		{
			if (inputFile.tellg() < 0)
			{
				i = 0; 
				break;
			}
			In.show();
		}
		
	}
	while (inputFile >> item)
	{
		tpro.push_back(item);
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
	}
	inputFile.close();
}

//Displaying Invoice
void display()
{
	int i = 1;
	char ch[] = __DATE__;
	char ch1[] = __TIME__;
	cout << "\n\n\t\t\t Invoice\t\n";
	cout << "\n\t" <<"Date: " << ch << "\t"<<"Time: " 
		<< ch1 << "\n";
	cout << "\n\t\tCustomer Name\t\tCustomer No.\t\t";
	inputFile.open("cust.txt", ios::binary);
	while (!inputFile.eof())
	{
		inputFile.read((char*)&Cu, sizeof(Cu));
		if (!inputFile.eof())
		{
			if (inputFile.tellg() < 0)
			{
				i = 0;
			
			}
			Cu.Cust();
			break;
		}
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
	}
	display1();
	cout << "\n\tProducts\tQuantity";
	for (unsigned int i = 0;i < ts.size(); i++) {
		cout << "\n\t" << ts.at(i) << "\t\t" << tq.at(i);
	}
	cout << "\n\tTotal Price:";
	cout << "\t" << accumulate(tp.begin(), tp.end(), 0);
	tp.clear();
	ts.clear();
	tq.clear();
	inputFile.close();
}

//displaying order items
void display1()
{/*
	int i = 1;
	inputFile.open("order.txt", ios::binary);
	while (!inputFile.eof())
	{
		inputFile.read((char*)&Cu, sizeof(Cu));
		if (!inputFile.eof())
		{
			if (inputFile.tellg() < 0)
			{
				i = 0;
				break;
			}
		}
	}
	inputFile.close();
*/}

//Updating the Product
void update()
{
	system("cls");
	char temp[100];int qty;
	int i = 0;
	long pos = 0;
	disp();
	cout << "\n\nEnter the products name \n" << endl;
	std::cin >> temp;
	cout << "\n\nEnter quantity: \n" << endl;
	std::cin >> qty;
	fileIO.open("shop.txt", ios::binary | ios::out | ios::in);
	while (fileIO)
	{
		int pos = static_cast<int>(fileIO.tellp());
		fileIO.read((char*)&In, sizeof(In));
		if (In.stockAvail(temp) == 0)
		{

			In.update(qty);
			fileIO.seekp(pos);
			fileIO.write((char*)&In, sizeof(In));
			i++;
			break;
		}
	}
	if (i != 1)
		cout << "\n\n!!Record not found!!";
	fileIO.close();
	std::cin.get();
	disp(); 
	std::cin.get();
}

//staff Operations 
void orderDetails()
{
	int i;
	system("cls");
	addnew1();
OrderDetails:
	
	cout << "\n\n\t\t\t\tStaff MENU"
		 << "\n1. Order "
		 << "\n2. Generate Bill"
		 << "\n3. EXIT"
		 << "\n4. Back";
	cout << "\n\n Enter your Choice :\t";
	std::cin >> i;
	if (i == 1)
	{
		Order();
		goto OrderDetails;
	}
	else if (i == 2)
	{
		cin.get();
		display();
		cout << "\n\nCash Only..Thanks for Shopping.!";
		goto OrderDetails;
	}
	else if(i==3)
	{
		system("cls");
		In.~Inventory();
		Cu.~Customer();
	}
	else
	{
		staffHomepage();
	}
}

//Mainmenu of Owner
void ownerHompeage()
{
	int b;
	system("cls");
	disp();
OnwerHomepage:
	cout << "\n\n\n\t\t\t    Onwer Homepage\n"
		<< "1. Add Product\n"
		<< "2. Display Product\n"
		<< "3. Update Product\n"
		<< "4. Remove Products\n"
		<< "5. Userpage";
	cout << "\n\n\n Enter your Choice :\t";
	cin >> b;
	if (b == 1)
	{
		system("cls");
		addnew();
		goto OnwerHomepage;
	}
	else if (b == 2)
	{
		system("cls");
		displ();
		goto OnwerHomepage;
	}
	else if (b == 3)
	{
		system("cls");
		update();
		goto OnwerHomepage;
	}
	else if (b == 4)
	{
		system("cls");
		remove();
		goto OnwerHomepage;
	}
	else
	{
		system("cls");

		main();
	}
}

//Mainmenu of Staff
void staffHomepage()
{
	int b;
	system("cls");
StaffHomepage:
	cout << "\n\n\t\t\tStaff Homepage\n"
		<< "1.Display stock"
		<< "\n2.Order Details"
		<< "\n3.User page";
	cout << "\n\n Enter your Choice :\t";
	std::cin >> b;
	if (b == 1)
	{
		disp();
		goto StaffHomepage;
	}
	else if (b == 2)
	{
		orderDetails();
		goto StaffHomepage;
	}
	else if (b == 3)
	{
		main();
	}
	else
	{
		system("cls");
		goto StaffHomepage;
	}
}

//Sorting the Products
void displ()
{
	
	cout << "PRODUCTS\n";
	auto ascending = [](auto a, auto b) -> bool {
		return a < b;
	};
	sort(tpro.begin(), tpro.end(), ascending);
	for (auto z : tpro)
	{
	cout << z << "\n";
	}
}