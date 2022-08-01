#include <iostream>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
void addnew();
void Order();
void disp();
void update();
void remove();
void orderDetails();
void ownerHompeage();
void staffHomepage();
class Inventory
{
	char name[20], pass[15];
	float price; int quantity;
public:
	void get();
	void show();
	int  stockAvail(char nm[30]);
	void withd(int qty);
	void update(int qty);
};
int n;
Inventory In;
ifstream inputFile;
ofstream outputFile;
fstream fileIO;
void Inventory::get()
{
	cin >> name >> price >> quantity;
}
void Inventory::show()
{
	cout << "\n"
		<< name
		<< "\t\t\t"
		<< quantity
		<< "\t\t\t"
		<< price;
}
int Inventory::stockAvail(char nm[30])
{
	if (strcmp(nm, name) == 0)
		return 0;
	else
		return 1;
}
void Inventory::withd(int qty)
{
	if (quantity >= qty)
	{
		quantity -= qty;
		cout << "\n\nStock updated.\n";
		cout << "\n\nTotal price to be paid:" << price * qty;
		if (quantity <= 5)
		{
			cout << "Stock is Very low Update the Stock";
		}
		else
		{

		}
	}
	else
		cout << "\n\nInsufficient stock";
}
void Inventory::update(int qty)
{
	quantity += qty;
	cout << "\n\nStock updated.";
}
int main()
{
	int a, b;
	cout << "\n\n		Welcome To Store\n";
	system("cls");
	cout << "\n\t\t Inventory Management Homepage By Users";
	cout << "\n\n\t\t 1.Owner Homepage\n\n\t\t "
		<< "2.Staff Homepage"
		<< "\n\n\n\t Choice : \t";
	cin >> a;
	if (a == 1)
	{
		ownerHompeage();
	}
	else if (a == 2)
	{
		staffHomepage();
	}
}
void addnew()
{
	system("cls");
	cout << "\nEnter the Name followed By the price and then by the quantity\n";
	disp();
	system("cls");
	cout << "\nEnter the No. of Products that you wish to add: ";
	cin >> n;
	if (n != 0)
	{
		int j, l, sum = 0;
		outputFile.open("shop.dat", ios::binary | ios::app);
		for (int i = 0;i < n;i++)

		{
			if (i == 0)
			{
				system("cls");
			}
			cout << "\n\nInput the name, price and the quantity of item respectively\n\n";
			In.get();
			outputFile.write((char*)&In, sizeof(In));
			cout << "\n\nitem updated";
			cin.get();


		}
		cout << "\n\nStock Updated!!";


		outputFile.close();
		cin.get();
		system("cls");
		disp();
	}

	else
	{

		outputFile.close();
		cin.get();
		system("cls");
		cout << "\n\nNo items to be added";

	}
}
void Order()
{
	system("cls");
	char temp[100];int qty;
	int i = 0;
	long pos = 0;
	disp();
	cout << "\n\nEnter the product's name \n" << endl;
	cin >> temp;
	cout << "\n\nEnter quantity: \n" << endl;
	cin >> qty;
	fileIO.open("shop.dat", ios::binary | ios::out | ios::in);
	while (fileIO)
	{
		pos = fileIO.tellp();
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
	if (i != 1)
		cout << "\n\n!!Record not found!!";
	fileIO.close();
	cin.get();
	system("cls");
	disp();
}
void disp()
{
	int i = 1;
	
	cout << "\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\tPRICE";
	inputFile.open("shop.dat", ios::binary);
	while (!inputFile.eof())
	{
		inputFile.read((char*)&In, sizeof(In));
		if (!inputFile.eof())
		{
			if (inputFile.tellg() < 0)
			{
				i = 0; break;
			}
			In.show();
		}
	}
	if (i == 0)
	{
		cout << "\n\n\t\t\t!!Empty record room!!";
	}
	inputFile.close();
}
void update()
{
	system("cls");
	char temp[100];int qty;
	int i = 0;
	long pos = 0;
	disp();
	cout << "\n\nEnter the products name \n" << endl;
	cin >> temp;
	cout << "\n\nEnter quantity: \n" << endl;
	cin >> qty;
	fileIO.open("shop.dat", ios::binary | ios::out | ios::in);
	while (fileIO)
	{
		pos = fileIO.tellp();
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
	system("cls");
	cin.get();
	disp(); cin.get();
}
void remove()
{
	
system("cls");
disp();
	int i = 0;
	char temp[30];
	cout << "\n\t\t\t\tDelete Record";
	cout << "\n\nEnter the name of the product:";
	cin >> temp;
	outputFile.open("temp.dat", ios::binary);
	inputFile.open("shop.dat", ios::binary);
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
	remove("shop.dat");
	rename("shop.dat","temp.dat");
	
}
void orderDetails()
{
	int i;
OrderDetails:
	system("cls");
	cout << "\n\n\t\t\t\tStaff MENU"
		<< "\n1. Sell"
		<< "\n2. Exit:";
	cout << "\n\n Enter your Choice :\t";
	cin >> i;
	if (i == 1)
	{
		Order();
		goto OrderDetails;
	}
	else
	{
		system("cls");
		exit(0);
	}
}
void ownerHompeage()
{
	int b;
	system("cls");
	disp();
OnwerHomepage:
	cout << "\n\n\n\t\t\t    Onwer Homepage\n"
		<< "1. Add Product\n"
		<< "2. Remove Product\n"
		<< "3. Update Product\n"
		<< "4. Display Products\n"
		<< "5. Exit:";
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
		remove();
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
		disp();
		goto OnwerHomepage;
	}
	else
	{
		system("cls");

		exit(0);
	}
}
void staffHomepage()
{
	int b;
	system("cls");
StaffHomepage:
	system("cls");
	cout << "\n\n\t\t\tStaff Homepage\n"
		<< "1. Display stock"
		<< "\n2.Order Details"
		<< "\n3.Exit";
	cout << "\n\n Enter your Choice :\t";
	cin >> b;
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
		cout << "\n\n\n\t\t\tThank You!!";
		exit(0);
	}
	else
	{
		system("cls");
		goto StaffHomepage;
	}
}