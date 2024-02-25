#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;

class shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;

public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};
void shopping ::menu()
{
m:
	int choice;
	string email;
	string password;

	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|             Supermarket Menu                   |\n";
	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|             1) ADMINISTRATOR                   |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|             2) BUYER                           |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|             3) EXIT                            |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|               Select                           |\n";
	cout << "\t\t|------------------------------------------------|\n";
	cout << "\t\t|---------->>  : ";
	cin >> choice;

	switch (choice)
	{

	case 1:
	    cout << "\t\t|________________________________________________|\n";
		cout << "\t\t|                    LOGIN                       |\n";
		cout << "\t\t|________________________________________________|\n";
		cout << "\t\t|    Email:    ";
		cin >> email;
		cout << "\t\t|------------------------------------------------|\n";
		cout << "\t\t| Password:  ";
		cin >> password;

		if (email == "niyobarry@gmail.com" && password == "pass")
		{
			administrator();
		}
		else
		{
			cout << "\t\t|         INVALID EMAIL OR PASSWORD !        |\n";
		}
		break;
	case 2:
	{
		buyer();
	}
	case 3:
	{
		exit(0);
	}
	default:
	{
		cout << "\t\t|         Select From The Given Options          |\n";
	}
	}
	goto m;
}

void shopping ::administrator()
{
m:
	int choice;
	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|                   ADMINISTRATOR                |\n";
	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|            1) ADD the product                  |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|            2) MODIFY the product               |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|            3) DELETE the product               |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|            4) BACK  to main menu               |\n";
	cout << "\t\t|                                                |\n";
    cout << "\t\t|               Select                           |\n";
	cout << "\t\t|------------------------------------------------|\n";
	cout << "\t\t|---------->>  : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		add();
		break;

	case 2:
		edit();
		break;

	case 3:
		rem();
		break;

	case 4:
		menu();
		break;

	default:
		cout << "invalid Choice!";
	}
	goto m;
}

void shopping ::buyer()
{
m:
	int choice;
	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|                   BUYER                        |\n";
	cout << "\t\t|________________________________________________|\n";
	cout << "\t\t|                 1. BUY product                 |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                 2. GO back                     |\n";
	cout << "\t\t|                                                |\n";
	cout << "\t\t|                 Select                         |\n";
	cout << "\t\t|------------------------------------------------|\n";
	cout << "\t\t|---------->>  : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		receipt();
		break;
	case 2:
		menu();
		break;
	default:
		cout << "\t\t|         INVALID CHOICE !!        |\n";
	}
	goto m;
}

void shopping ::add()
{
m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	cout << "\t\t|________________________________________________|\n";
    cout << "\t\t                   ADD  new product              |\n";
	cout << "\t\t ________________________________________________|\n";
	cout << "\n\n\t\t   Product CODE     : ";
	cin >> pcode;
	cout << "\n\n\t\t   Product NAME     : ";
	cin >> pname;
	cout << "\n\n\t\t   Product PRICE    : ";
	cin >> price;
	cout << "\n\n\t\t   product DISCOUNT : ";
	cin >> dis;

	data.open("database.txt", ios::in);

	if (!data)
	{
		data.open("database.txt", ios::app | ios::out),
		data <<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;

		while (!data.eof())
		{

			if (c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();


		if (token == 1)
		{
			
			cout << "\n\n\t\t|         Product Already Exists. CHOOSE another one!      |\n";
			goto m;
		}
		else
		{
			data.open("database.txt", ios::app | ios::out),
			data <<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
		}
	}
	cout << "\n\n\t\t|         Record Inserted      |\n";
}

void shopping ::edit()
{
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	int p;
	int d;
	string n;

	cout << "\t\t|________________________________________________|\n";
    cout << "\t\t                   MODIFY A Product              |\n";
	cout << "\t\t ________________________________________________|\n";
	cout << "\n\n\t\t product code : ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n\t\t|         File does not exist!      |\n";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);

		data>>pcode>>pname>>price>>dis;

		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout << "\n\n\t\t new product code : ";
				cin >> c;
				cout << "\n\n\t\t name of the product : ";
				cin >> n;
				cout << "\n\n\t\t price of the product : ";
				cin >> p;
				cout << "\n\n\t\t discount of the product : ";
				cin >> d;

				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<dis<<"\n";
				cout << "\n\n\t\t_____________Record edited__________________\n";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "n\n\t\t NO RECORD OF THE PRODUCT, SORRY! TRY AGAIN \n";
		}
	}
}

void shopping ::rem()
{

	fstream data, data1;
	int pkey;
	int token = 0;

	cout << "\t\t|________________________________________________|\n";
    cout << "\t\t                   MODIFY A Product              |\n";
	cout << "\t\t ________________________________________________|\n";
	cout << "\n\n\t\t product code : ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n\t\t|         File does not exist!      |\n";
	}
	else
	{
		data1.open("database1.txt", ios::app | ios::out);

		data >> pcode >> pname >> price >> dis;

		while (!data.eof())
		{
			if (pkey == pcode)
			{

				cout << "\n\n\t\t_____________Product Deleted successfully!__________________\n";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt", "database.txt");

		if (token == 0)
		{
			cout << "\n\n\t\t|         Incorrect Product code!      |\n";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n_________________________________________________________\n";
	cout << "\n\n||ProNo\t\t||Name\t\t||Price\t\t||discount\n";
	cout << "\n\n_________________________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof())
	{
		cout << "\n\n||" << pcode << "\t\t||" << pname << "\t\t||" << price << "\t\t||"<< dis <<"\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void shopping ::receipt()
{
	fstream data;

	int arrc[100];
	int arrq[100];
	string choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;

	cout << "\t\t|________________________________________________|\n";
    cout << "\t\t                   Available GOODS               |\n";
	cout << "\t\t ________________________________________________|\n";

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\n\t\t|        Database does not Exist!      |\n";
	}
	else
	{
		data.close();
		
		list();
		cout << "\n\n\t\t_______________________________________"<< endl;
		cout << "\n\n\t\t             take order                "<< endl;
		cout << "\n\n\t\t_______________________________________" << endl;

		do
		{
		m:
			cout << "\n\n enter product code : ";
			cin >> arrc[c];
			cout << "\n\n enter product quantity : ";
			cin >> arrq[c];
			for (int i=0; i<c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n\t\t|        Product Already Listed. Choose Another Product      |\n";
					goto m;
				}
			}
			c++;
			cout << "\n\n do you want to buy another product or not? if YES then press y else press n : ";
			cin >> choice;

		} 
		while (choice == "y");

		cout << " \n\n\t\t__________________________ RECIEPT _______________________________________\n";
		cout << "\n Product no \t product name \t product quantity \t price \t amount \t discount \n";

		for (int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof())
			{
				if (pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n\n||" << pcode << "\t\t||" << pname << "\t\t||" << arrq[i] << "\t\t||" << price << "\t\t||" << amount << "\t\t||" << dis << "\t\t||\n";
				}
				data >> pcode >> pname >> price >> dis;
			}
		}

		data.close();
	}

	cout << "\n\n______________________________________________________________________________________\n";
	cout << "\n Total amount : " << total<<"\n";
}
int main()
{
	shopping s;
	s.menu();
}
