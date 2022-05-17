//to access employee menu:
//Name: test
//ID: 100
//password: test
//to access admin in employee menu:
//password: executive

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdio>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<ctime>
#include<windows.h>
#include<process.h>
#include <cstdlib> 5
using namespace std;
#define AdminPass "executive"

void createAccount();
void customerMenu();
void loanMenu();
int transaction();
void bankStatement();
void employeeMenu();
void fxBlotter();
void adminMenu();
void empLoanMenu();
void foreignEmpMenu();
void animation();
void animation2();
void star();
void mainScreen();
void endScreen();
//void takeLoan();
void gotoxy(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
typedef struct blotter
{
	double foreignBuy[10];
	double foreignSell[10];
	double profit[10];
};
typedef struct foreignCurrency
{
	double USD;
	double Euro;
	double Pound;
	double CAD;
	double Dhiram;
	double Riyal;
	double Yuan;
};
foreignCurrency foreignBuyRates();
foreignCurrency foreignSellRates();
void foreignConversion(foreignCurrency& var, char choice);
void foreignMenu();
void animation()
{
	int r, q;
	char c = 219;
	gotoxy(30, 18);

	cout << "Loading...";

	gotoxy(30, 20);
	for (r = 1; r <= 10; r++)
	{
		for (q = 0; q <= 1; q++)
		{
			cout << c;
			Sleep(100);
		}
	}

}
void animation2()
{
	int r, q;
	char c = 219;
	gotoxy(30, 18);

	cout << "LOGGING IN ...";

	gotoxy(30, 20);
	for (r = 1; r <= 10; r++)
	{
		for (q = 0; q <= 1; q++)
		{
			cout << c;
			Sleep(100);
		}
	}

}
class Customer
{
	char name[30];
	int age;
	char address[100];
	char CNIC[15];
	int contactNum;
	char nationality[12];
	char incomeSource[20];
	long int monthlySalary;
public:
	Customer()
	{
		name[0] = '\0';
		age = 0;
		contactNum = 0;
		monthlySalary = 0;
		address[0] = '\0';
		CNIC[0] = '\0';
		nationality[0] = '\0';
		incomeSource[0] = '\0';
	}
	void getData()
	{
		cout << "Enter Name: ";
		gets_s(name);
		cout << "Enter Age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter CNIC: ";
		gets_s(CNIC);
		cout << "Enter Address: ";
		gets_s(address);
		cout << "Enter Contact Info: ";
		cin >> contactNum;
		cin.ignore();
		cout << "Enter Nationality: ";
		gets_s(nationality);
		cout << "Enter your Source of Income: ";
		gets_s(incomeSource);
		cout << "Enter your Monthly Income: ";
		cin >> monthlySalary;
	}
	void displayData()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "CNIC: " << CNIC << endl;
		cout << "Address: " << address << endl;
		cout << "Contact Number: " << contactNum << endl;
		cout << "Nationality: " << nationality << endl;
		cout << "Source of Income: " << incomeSource << endl;
		cout << "Monthly  Income: " << monthlySalary << endl;
	}
	void fileEval(long int num)
	{
		string temp;
		temp = to_string(num);
		temp += "loanEval.dat";
		ofstream file;
		file.open(temp, ios::out);
		file << "Account No: " << num << endl;
		file << "Name: " << name << endl;
		file << "Age: " << age << endl;
		file << "CNIC: " << CNIC << endl;
		file << "Address: " << address << endl;
		file << "Contact Number: " << contactNum << endl;
		file << "Nationality: " << nationality << endl;
		file << "Source of Income: " << incomeSource << endl;
		file << "Monthly  Income: " << monthlySalary << endl;
		file.close();
	}
	string getName()
	{
		return name;
	}
	void filing(fstream& f, bool x)
	{
		if (x)
		{
			f.write((char*)&name[0], sizeof(char)*30);
			f.write((char*)&age, sizeof(age));
			f.write((char*)&address[0], sizeof(char)*100);
			f.write((char*)&CNIC[0], sizeof(char)*15);
			f.write((char*)&contactNum, sizeof(contactNum));
			f.write((char*)&nationality[0], sizeof(char)*12);
			f.write((char*)&incomeSource[0], sizeof(char)*20);
			f.write((char*)&monthlySalary, sizeof(monthlySalary));
		}
		else
		{
			f.read((char*)&name[0], sizeof(char) * 30);
			f.read((char*)&age, sizeof(age));
			f.read((char*)&address[0], sizeof(char) * 100);
			f.read((char*)&CNIC[0], sizeof(char) * 15);
			f.read((char*)&contactNum, sizeof(contactNum));
			f.read((char*)&nationality[0], sizeof(char) * 12);
			f.read((char*)&incomeSource[0], sizeof(char) * 20);
			f.read((char*)&monthlySalary, sizeof(monthlySalary));
		}
	}
};
class Loan
{
	double loanBalance;
	double installment;
	int tenorYear;
	int tenorMonth;
	char type[10];
public:
	Loan()
	{
		loanBalance = 0;
		installment = 0;
		tenorYear = 0;
		tenorMonth = 0;
		type[0] = '\0';
	}
	void getData()
	{
		cout << "How much loan would you like to take?" << endl << "Amount: ";
		cin >> loanBalance;
		if (loanBalance < 250000 && loanBalance > 2000000)
		{
			exit(1);
		}
		cout << "What will be the tenor of your Loan?" << endl << "Tenor: ";
		cin >> tenorYear;
		if (tenorYear > 5 && tenorYear < 1)
		{
			exit(1);
		}
		cin.ignore();
		cout << "What is the purpose of your Loan?(Car/House/Personal)" << endl << "--> ";
		gets_s(type);
	}
	void fileEval(long int num)
	{
		string temp;
		temp = to_string(num);
		temp += "loanEval.dat";
		ofstream file;
		file.open(temp, ios::app);
		file << "Loan Amount: " << loanBalance << endl;
		file << "Loan Duration: " << tenorYear << " years" << endl;
		file << "Purpose of Loan: " << type << endl;
		file.close();
	}
	string getType() const
	{
		return type;
	}
	int getYear() const
	{
		return tenorYear;
	}
	double getBalance() const
	{
		return loanBalance;
	}
	void setBalance(const double amount)
	{
		loanBalance = amount;
	}
	void calculateInstallment()
	{
		int months;
		months = tenorYear * 12;
		months += tenorMonth;
		installment = loanBalance / months;
	}
	double getInstallment() const
	{
		return installment;
	}
	int payment(double const amount)
	{
		loanBalance = amount;
		if (tenorMonth == 0)
		{
			tenorYear--;
			tenorMonth = 11;
		}
		else
		{
			tenorMonth--;
		}
		if (tenorYear == 0 && tenorYear == 0)
		{
			return 0;
		}
	}
	void display()
	{
		cout << "Loan Amount: Rs." << loanBalance << endl;
		if (tenorYear == 1)
		{
			cout << "Loan Tenor: " << tenorYear << " year ";
		}
		else
		{
			cout << "Loan Tenor: " << tenorYear << " years ";
			
		}
		if (tenorMonth == 1)
		{
			cout << tenorMonth << " month" << endl;
		}
		else
		{
			cout << tenorMonth << " months" << endl;
		}
		cout << "Loan Purpose: " <<  type << endl;
		cout << "Monthly Installment: " << installment << endl;
	}
	void display(int)
	{
		cout << "Remaining Loan Amount: Rs." << loanBalance << endl;
		if (tenorYear == 1)
		{
			cout << "Remaining Loan Tenor: " << tenorYear << " year ";
		}
		else
		{
			cout << "Remaining Loan Tenor: " << tenorYear << " years ";

		}
		if (tenorMonth == 1)
		{
			cout << tenorMonth << " month" << endl;
		}
		else
		{
			cout << tenorMonth << " months" << endl;
		}
		cout << "Monthly Installment: " << installment << endl;
	}
	void setZero()
	{
		loanBalance = 0;
		tenorYear = 0;
		tenorMonth = 0;
		installment = 0;
		type[0] = '\0';
	}
	void filing(fstream& f, bool x)
	{
		if (x)
		{
			f.write((char*)&loanBalance, sizeof(loanBalance));
			f.write((char*)&installment, sizeof(installment));
			f.write((char*)&tenorYear, sizeof(tenorYear));
			f.write((char*)&tenorMonth, sizeof(tenorMonth));
			f.write((char*)&type[0], sizeof(char) * 10);
			
		}
		else
		{
			f.read((char*)&loanBalance, sizeof(loanBalance));
			f.read((char*)&installment, sizeof(installment));
			f.read((char*)&tenorYear, sizeof(tenorYear));
			f.read((char*)&tenorMonth, sizeof(tenorMonth));
			f.read((char*)&type[0], sizeof(char) * 10);
		}
	}
};

class Account :public Customer
{
	double balance;
	long int const accountNo;
	char type[10];
	char pin[10];
	struct tm timer;
	Loan loan;
	
public:
	string getPin() const
	{
		return pin;
	}
	Account() :accountNo(0)
	{
		memset(pin,'\0',sizeof(pin));
		balance = 0;
		type[0] = '\0';
		time_t now;
		time(&now);
		localtime_s(&timer,&now);
	}
	Account(char t[10], long int x) : accountNo(x)
	{
		balance = 0;
		memset(pin, '\0', sizeof(pin));
		strcpy_s(type, t);
		time_t now;
		time(&now);
		localtime_s(&timer, &now);
	}
	void getData(char t[10])
	{
		Customer::getData();
		if (strcmp(type, "Current") == 0)
		{
			cout << "Enter First Deposit (Above Rs. 5000): ";
			cin >> balance;
		}
		else if (strcmp(type, "Savings") == 0)
		{
			cout << "Enter First Deposit (Above Rs. 5000): ";
			cin >> balance;
		}
		else if (strcmp(type, "Asaan") == 0)
		{
			cout << "Enter First Deposit (Above Rs. 100): ";
			cin >> balance;
		}
		createPin();
	}
	void createPin()
	{
		char temp;
		char pin2[10] = {'\0'};
		int count;
		cout << "Enter a 4 digit PIN for your Account: ";
		for (count = 0; count < 4; count++)
		{
			temp = _getch();
			if (temp == 13)
			{
				break;
			}
			pin[count] = temp;
			cout << "*";
		}
		if (strlen(pin) > 4 || strlen(pin) < 4)
		{
			cout << "\nInvalid PIN Entry, Please make PIN of only 4-digits." << endl;
			createPin();
		}
		else
		{
			cout << "\nRe-type PIN: ";
			for (count = 0; count < 4; count++)
			{
				temp = _getch();
				if (temp == 13)
				{
					break;
				}
				cout << "*";
				pin2[count] = temp;
			}
			if (strcmp(pin, pin2) == 0)
			{
				cout << "\nPIN Matched.\n";
			}
			else
			{
				cout << "\nPIN doesnot match please try again." << endl;
				createPin();
			}
		}
		cin.ignore();

	}
	void displayData()
	{
		Customer::displayData();
		cout << "Account Balance: " << balance << endl;
		cout << "Account Type: " << type << endl;
	}
	void getData()
	{
		cout << "Enter First Deposit: " << endl;
		cin >> balance;
	}
	double getBalance() const
	{
		return balance;
	}
	string getType() const
	{
		return type;
	}
	double getMonthly() const
	{
		return loan.getInstallment();
	}
	void setBalance(const double balance)
	{
		this->balance = balance;
	}
	const long int getAccountNum() const
	{
		return accountNo;
	}
	double getLoanBal() const
	{
		return loan.getBalance();
	}
	void fileData()
	{
		string temp;
		temp = to_string(accountNo);
		temp += ".dat";
		fstream myFile;
		myFile.open(temp, ios::out);
		filing(myFile,true);
		myFile.close();
		myFile.open("accountNums.dat", ios::app);
		myFile << accountNo << endl;
		myFile.close();
	}
	void setZero()
	{
		loan.setZero();
	}
	void takeLoan()
	{
		loan.getData();
		string temp;
		temp = to_string(accountNo);
		temp += "loanEval.dat";
		fileEval(accountNo);
		fstream file;
		file.open(temp, ios::app);
		file << "Account Balance: " << balance << endl;
		file << "Account Type: " << type << endl;
		file << "--------------------------------------" << endl;
		file.close();
		loan.fileEval(accountNo);
		file.open(temp, ios::app);
		if (loan.getType() == "Car" || loan.getType() == "car")
		{
			string model;
			cout << "Which Car will you be taking a loan for? (Company + Model)";
			getline(cin,model);
			file << "Car Model: " << model << endl;
		}
		else if (loan.getType() == "House" || loan.getType() == "house")
		{
			string type;
			int size;
			cout << "Which type of Housing?(House/Apartment): ";
			getline(cin, type);
			cout << "Size of Area(Sq/Yard): ";
			cin >> size;
			file << "Type of Housing: " << type << endl;
			file << "Size of Area: " << size << " sq/yard" << endl;
		}
		file.close();
		file.open("loanEvalAcc.dat", ios::app);
		file << accountNo << endl;
		file.close();
		cin.ignore();
	}
	void checkLoanStatus()
	{
		string temp, x;
		temp = to_string(accountNo);
		temp += "loanEval.dat";
		ifstream file;
		file.open(temp);
		if (file.is_open())
		{
			file.seekg(-2, file.end);

			bool keepLooping = true;
			while (keepLooping) {
				char ch;
				file.get(ch);
				if ((int)file.tellg() <= 1) {
					file.seekg(0);
					keepLooping = false;
				}
				else if (ch == '\n') {
					keepLooping = false;
				}
				else {
					file.seekg(-2, file.cur);
				}
			}
		}
		getline(file, x);
		file.close();
		int len = temp.length();
		char tempArr[30];
		strcpy_s(tempArr, temp.c_str());
		if (x == "Approved")
		{
			cout << "Your Loan has been Approved for Rs." << loan.getBalance() << endl;
			loan.calculateInstallment();
			cout << "Your Monthly Installment for Loan is Rs." << loan.getInstallment() << endl;
			cout << "Loan Payment must be completed in " << loan.getYear() << " years" << endl;
			cout << "Failure to complete loan payment in " << loan.getYear() << " years will result in 20% increase in Amount per annum." << endl;
			remove(tempArr);
		}
		else if (x == "Denied")
		{
			cout << "Your Loan has been denied." << endl;
			loan.setZero();
			remove(tempArr);
		}
		else
		{
			cout << "Your request is still under evaluation please come back later." << endl;
		}

	}
	int payLoan()
	{
		char choice;
		double loanBal;
		cout << "  -Payment Methods-\n\n";
		cout << "1. Account Balance" << endl;
		cout << "2. Cash" << endl;
		choice = _getch();
		if (choice == '1')
		{
			if (balance > loan.getInstallment())
			{
				cout << "\n\n Funds are sufficient, Do you want to continue with payment?" << endl;
				cout << "Press 'y' for Yes or 'n' for No." << endl;
				choice = _getch();
				if (choice == 'y' || choice == 'Y')
				{
					loanBal = loan.getBalance();
					loanBal -= loan.getInstallment();
					loan.payment(loanBal);
					if (loan.getBalance() <= 0)
					{
						cout << "Congratulations your loan has been fully payed.\n\n";
						setZero();
					}
				}
				else
				{
					cout << "Payment not made.\n\n";
					system("pause");
					return 0;
				}
			}
			else
			{
				cout << "Funds are Insufficient." << endl;
			}
			
		}
		else if (choice == '2')
		{
			double amount;
			cout << "Enter Amount you want to pay: ";
			cin >> amount;
			cin.ignore();
			if (amount >= loan.getInstallment())
			{
				loanBal = loan.getBalance();
				loanBal -= amount;
				loan.payment(loanBal);
				if (loan.getBalance() <= 0)
				{
					cout << "Congratulations your loan has been fully payed.\n\n";
					setZero();
				}
			}
			else if (amount < loan.getInstallment())
			{
				cout << "Amount is less than Monthly Installment amount, Monthly Installment will update." << endl;
				cout << "Is that okay? Press 'y' for Yes or 'n' for No." << endl;
				if (choice == 'y' || choice == 'Y')
				{
					loanBal = loan.getBalance();
					loanBal -= amount;
					loan.payment(loanBal);
					if (loan.getBalance() <= 0)
					{
						cout << "Congratulations your loan has been fully payed.\n\n";
						setZero();
					}
					else 
					{
						loan.calculateInstallment();
						cout << "\n\nYour Monthly Installment has been updated to Rs." << loan.getInstallment() << endl;
					}
					
				}
				else
				{
					cout << "Payment not made.\n\n";
					system("pause");
					return 0;
				}

			}
		}
	}
	void custLoanDisplay()
	{
		loan.display(0);
	}
	void empLoanDisplay()
	{
		loan.display();
	}
	bool checkYear()
	{
		struct tm temp;
		time_t now;
		time(&now);
		localtime_s(&temp, &now);
		if (temp.tm_year > timer.tm_year)
		{
			timer.tm_year = temp.tm_year;
			return true;
		}
		else
		{
			return false;
		}
	}
	double restriction() 
	{
		if (getType() == "Current")
		{
			return 50000;
		}
		else if (getType() == "Savings")
		{
			return 50000;
		}
		else if (getType() == "Asaan")
		{
			return 10000;
		}
	}
	void withdraw()
	{
		fstream fs;
		string temp;
		char choice;
		double amount;
		temp = to_string(accountNo);
		temp += "statement.dat";
		fs.open(temp, ios::app);
		cout << "Enter Amount you want to withdraw: ";
		cin >> amount;
		if (balance > amount && amount < restriction())
		{
			cout << "Account Balance is sufficient for transaction" << endl;
			cout << "Do you want to continue with Transaction? Press 'y' for Yes or 'n' for No." << endl;
			choice = _getch();
			if (choice == 'y' || choice == 'Y')
			{
				fs << "  -Amount Withdrawn from Account-" << endl;
				fs << "Previous Account Balance: Rs." << balance << endl;
				fs << "Withdrawal Amount: Rs." << amount << endl;
				balance -= amount;
				fs << "New Account Balance: Rs." << balance << endl;
				time_t now = time(0);
				char dt[30];
				ctime_s(dt, sizeof(dt), &now);
				fs << "Transaction Time: " << dt << endl << endl;
				fs.close();
			}
			else if(choice == 'n' || choice == 'N')
			{
				fs.close();
				exit(1);
			}
		}
		else
		{
			if (amount > balance)
			{
				cout << "Funds are Insufficient for transaction." << endl;
			}
			else if (amount > restriction())
			{
				cout << "Amount is greater than the restricted amount, which is Rs." << restriction() << endl;
			}
		}
		cin.ignore();
	}
	void deposit()
	{
		fstream fs;
		string temp;
		char choice;
		double amount;
		temp = to_string(accountNo);
		temp += "statement.dat";
		fs.open(temp, ios::app);
		cout << "Enter Amount you want to deposit: ";
		cin >> amount;
		if (amount > 0)
		{
			cout << "Do you want to continue with Transaction? Press 'y' for Yes or 'n' for No." << endl;
			choice = _getch();
			if (choice == 'y' || choice == 'Y')
			{
				fs << "  -Amount Deposited into Account-" << endl;
				fs << "Previous Account Balance: Rs." << balance << endl;
				fs << "Deposit Amount: Rs." << amount << endl;
				balance += amount;
				fs << "New Account Balance: Rs." << balance << endl;
				time_t now = time(0);
				char dt[30];
				ctime_s(dt, sizeof(dt), &now);
				fs << "Transaction Time: " << dt << endl << endl;
			}
			else if (choice == 'n' || choice == 'N')
			{
				exit(1);
			}
		}
		cin.ignore();
	}
	void transfer(Account& obj)
	{
		fstream fp,fs;
		string temp;
		char choice;
		double amount,tempBal;
		temp = to_string(accountNo);
		temp += "statement.dat";
		fs.open(temp, ios::app);
		temp = to_string(obj.getAccountNum());
		temp += "statement.dat";
		fp.open(temp, ios::app);
		cout << "Enter Amount you want to transfer: ";
		cin >> amount;
		if (amount < balance)
		{
			cout << "Do you want to continue with Transaction? Press 'y' for Yes or 'n' for No." << endl;
			choice = _getch();
			if (choice == 'y' || choice == 'Y')
			{
				fs << "  -Amount Transfered to-" << endl;
				fs << "Name: " << obj.getName() << endl;
				fs << "Account No.: " << obj.getAccountNum() << endl;
				fs << "Previous Account Balance: Rs." << balance << endl;
				fs << "Deposit Amount: Rs." << amount << endl;
				balance -= amount;
				fs << "New Account Balance: Rs." << balance << endl;
				time_t now = time(0);
				char dt[30];
				ctime_s(dt, sizeof(dt), &now);
				fs << "Transaction Time: " << dt << endl << endl;
				fp << "  -Amount Transfered from-" << endl;
				fp << "Name: " << getName() << endl;
				fp << "Account No.: " << accountNo << endl;
				fp << "Previous Account Balance: Rs." << obj.getBalance() << endl;
				fp << "Deposit Amount: Rs." << amount << endl;
				tempBal = obj.getBalance();
				tempBal += amount;
				obj.setBalance(tempBal);
				fp << "New Account Balance: Rs." << obj.getBalance() << endl;
				now = time(0);
				ctime_s(dt, sizeof(dt), &now);
				fp << "Transaction Time: " << dt << endl << endl;
			}
			else if (choice == 'n' || choice == 'N')
			{
				exit(1);
			}
		}
		cin.ignore();
	}
	double calSavingsProfit()
	{
		double rate, profit;
		string temp;
		fstream fp;
		fp.open("savingsRate.dat", ios::in);
		fp.read((char*)&rate, sizeof(rate));
		fp.close();
		temp = to_string(accountNo);
		temp += "statement.dat";
		fp.open(temp, ios::app);
		rate = rate / 100;
		fp << "  -Yearly Profit Added-" << endl;
		fp << "Previous Account Balance: Rs." << balance << endl;
		profit = balance * rate;
		fp << "Total Yearly Profit: Rs." << profit << endl;
		balance += profit;
		fp << "New Account Balance: Rs." << balance << endl << endl;
		fp.close();
		return profit;
	}
	bool accCheck(string pin, string name)
	{
		if (pin == getPin() && name == getName())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void displayLoan()
	{
		loan.display();
	}
	void filing(fstream& f, bool x)
	{
		if (x)
		{
			Customer::filing(f, x);
			f.write((char*)&balance, sizeof(balance));
			f.write((char*)&accountNo, sizeof(accountNo));
			f.write((char*)&pin, sizeof(char)*4);
			f.write((char*)&type[0], sizeof(char)*10);
			f.write((char*)&timer, sizeof(struct tm));
			loan.filing(f, x);
		}
		else
		{
			Customer::filing(f, x);
			f.read((char*)&balance, sizeof(balance));
			f.read((char*)&accountNo, sizeof(accountNo));
			f.read((char*)&pin, sizeof(char)*4);
			f.read((char*)&type[0], sizeof(char)*10);
			f.read((char*)&timer, sizeof(struct tm));
			loan.filing(f, x);
		}
	}
};
bool checkCredentials(Account obj);
class Employee
{
	char name[20];
	const int iDNum;
	char password[10];
public:
	Employee():iDNum(0)
	{
		name[0] = '\0';
		password[0] = '\0';
	}
	Employee(char n[20], int iD, char pass[10]):iDNum(iD)
	{
		strcpy_s(name, n);
		strcpy_s(password, pass);
	}
	bool checkNull()
	{
		if (name[0] == '\0' || iDNum == 0 || password[0] == '\0')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void createEmployee()
	{
		Employee empTemp;
		int num = 100;
		cout << "Enter Name: ";
		gets_s(name);
		fstream file;
		file.open("employeeList.dat", ios::in);
		
		
		if (!file.fail())
		{
			while (1)
			{
				file.read((char*)&empTemp, sizeof(Employee));
				if (empTemp.getID() == num)
				{
					num++;
					continue;
				}
				else
				{
					char temp[10],pass[10] = {'\0'};
					int count;
					cout << "Enter Password(less than 10 characters): ";
					for (count = 0; count < 10; count++)
					{
						temp[count] = _getch();
						if (temp[count] == 13)
						{
							break;
						}
						pass[count] = temp[count];
						cout << "*";
					}
					char tempName[20];
					strcpy_s(tempName, name);
					Employee newEmp(tempName, num, pass);
					fstream myFile;
					myFile.open("employeeList.dat", ios::app);
					myFile.write((char*)&newEmp, sizeof(Employee));
					myFile.close();

				}
				if (file.eof())
				{
					break;
				}
			}
			file.close();
		}
		else
		{
			char temp[10], pass[10] = { '\0' };
			int count;
			cout << "Enter Password(less than 10 characters): ";
			for (count = 0; count < 10; count++)
			{
				temp[count] = _getch();
				if (temp[count] == 13)
				{
					break;
				}
				pass[count] = temp[count];
				cout << "*";
			}
			char tempName[20];
			strcpy_s(tempName, name);
			Employee newEmp(tempName, num, password);
			fstream myFile;
			myFile.open("employeeList.dat", ios::app);
			myFile.write((char*)&newEmp, sizeof(Employee));
			myFile.close();
		}
		
	}
	bool login()
	{
		char name[20] = { '\0' };
		int iDNum,count;
		char password[10] = {'\0'};
		char temp[10];
		cout << "Enter Name: ";
		gets_s(name);
		cout << "Enter Employee ID: ";
		cin >> iDNum;
		cin.ignore();
		cout << "Enter Password: ";
		for (count = 0; count < 10; count++)
		{
			temp[count] = _getch();
			if (temp[count] == 13)
			{
				break;
			}
			password[count] = temp[count];
			cout << "*";
		}
		fstream fp,fs;
		fp.open("employeeList.dat", ios::in);
		while (fp.is_open())
		{
			fp.read((char*)this, sizeof(Employee));
			if (fp.eof())
			{
				cout << endl << "Invalid Login Credentials." << endl << endl;
				system("pause");
				return false;
			}
			if (strcmp(this->name, name) == 0 && this->iDNum == iDNum && strcmp(this->password, password) == 0)
			{
				fs.open("employeeLogs.dat", ios::app);
				time_t now = time(0);
				char dt[30];
				ctime_s(dt,sizeof(dt),&now);
				fs << "Employee Name: " << name << endl;
				fs << "Employee ID: " << iDNum << endl;
				fs << "Time In: " << dt << endl << endl;
				fs.close();
				return true;
			}
		}
		fp.close();
	}
	void timeOut()
	{
		fstream fs;
		fs.open("employeeLogs.dat", ios::app);
		time_t now = time(0);
		char dt[30];
		ctime_s(dt, sizeof(dt), &now);
		fs << "Employee Name: " << name << endl;
		fs << "Employee ID: " << iDNum << endl;
		fs << "Time out: " << dt << endl << endl;
		fs.close();
	}
	void updateSavingRate()
	{
		double rate;
		fstream fp;
		cout << "Enter New Savings Account Rate: ";
		cin >> rate;
		fp.open("savingsRate.dat", ios::out);
		if (!fp.is_open())
		{
			cout << "File not open." << endl;
		}
		fp.write((char*)&rate, sizeof(rate));
		fp.close();
	}
	void readEmp()
	{
		Employee temp;
		fstream file;
		int count = 1;
		file.open("employeeList.dat", ios::in);
		while (!file.eof())
		{
			file.read((char*)&temp, sizeof(Employee));
			if (file.eof())
			{
				break;
			}
			cout << count << ". ";
			temp.display();
			count++;
		}
		
		file.close();
		
	}
	void loanEval()
	{
		string temp, x;
		long int num;
		fstream fp,fs;
		char c;
		fp.open("loanEvalAcc.dat", ios::in);
		fs.open("activeLoan.dat", ios::app);
		while (!fp.eof())
		{
			fp >> num;
			if (fp.eof())
			{
				break;
			}
			temp = to_string(num);
			temp += "loanEval.dat";
			fstream file, file2;
			file.open(temp, ios::in);
			file2.open("loanEvaluations.dat", ios::app);
			while (getline(file, x))
			{
				cout << x << endl;
				file2 << x << endl;
			}
			file.close();
			file.open(temp, ios::app);
			cout << "To Approve press 'a' or 'A' else to Deny press 'd' or 'D'" << endl;
			c = _getch();
			if (c == 'a' || c == 'A')
			{
				file2 << "Approved" << endl;
				file2 << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
				file << "Approved";
				fs << num << endl;
			}
			else if (c == 'd' || c == 'D')
			{
				file2 << "Denied" << endl;
				file2 << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
				file << "Denied";
			}
			file2.close();
			system("cls");
		}
		fp.close();
		fs.close();
		cout << endl << "All Pending Evaluations have been completed." << endl;
		remove("loanEvalAcc.dat");
		
	}
	void createBlotterRecord()
	{
		system("cls");
		char choice;
		double rupeesBuy[7];
		double rupeesSell[7];
		blotter fx;
		foreignCurrency buy, sell;

		fstream fbuy, fsell;
		fbuy.open("foreignExchangeBuy.dat", ios::in);
		fsell.open("foreignExchangeSell.dat", ios::in);
		fstream file;
		file.open("fxBlotterRecord.dat", ios::app);
		fbuy.read((char*)&buy, sizeof(struct foreignCurrency));
		fsell.read((char*)&sell, sizeof(struct foreignCurrency));

		string currency[7] = { "USD","Euro","Pound","CAD","Dhiram","Riyal","Yuan" };


		cout << "Enter amount of " << currency[0] << " Bought: ";
		cin >> fx.foreignBuy[0];
		rupeesBuy[0] = fx.foreignBuy[0] * buy.USD;
		cout << "Enter amount of " << currency[0] << " Sold: ";
		cin >> fx.foreignSell[0];
		rupeesSell[0] = fx.foreignSell[0] * sell.USD;
		fx.profit[0] = rupeesSell[0] - rupeesBuy[0];
		cout << endl;
		cout << "Enter amount of " << currency[1] << " Bought: ";
		cin >> fx.foreignBuy[1];
		rupeesBuy[1] = fx.foreignBuy[1] * buy.Euro;
		cout << "Enter amount of " << currency[1] << " Sold: ";
		cin >> fx.foreignSell[1];
		rupeesSell[1] = fx.foreignSell[1] * sell.Euro;
		fx.profit[1] = rupeesSell[1] - rupeesBuy[1];
		cout << endl;
		cout << "Enter amount of " << currency[2] << " Bought: ";
		cin >> fx.foreignBuy[2];
		rupeesBuy[2] = fx.foreignBuy[2] * buy.Pound;
		cout << "Enter amount of " << currency[2] << " Sold: ";
		cin >> fx.foreignSell[2];
		rupeesSell[2] = fx.foreignSell[2] * sell.Pound;
		fx.profit[2] = rupeesSell[2] - rupeesBuy[2];
		cout << endl;
		cout << "Enter amount of " << currency[3] << " Bought: ";
		cin >> fx.foreignBuy[3];
		rupeesBuy[3] = fx.foreignBuy[3] * buy.CAD;
		cout << "Enter amount of " << currency[3] << " Sold: ";
		cin >> fx.foreignSell[3];
		rupeesSell[3] = fx.foreignSell[3] * sell.CAD;
		fx.profit[3] = rupeesSell[3] - rupeesBuy[3];
		cout << endl;
		cout << "Enter amount of " << currency[4] << " Bought: ";
		cin >> fx.foreignBuy[4];
		rupeesBuy[4] = fx.foreignBuy[4] * buy.Dhiram;
		cout << "Enter amount of " << currency[4] << " Sold: ";
		cin >> fx.foreignSell[4];
		rupeesSell[4] = fx.foreignSell[4] * sell.Dhiram;
		fx.profit[4] = rupeesSell[4] - rupeesBuy[4];
		cout << endl;
		cout << "Enter amount of " << currency[5] << " Bought: ";
		cin >> fx.foreignBuy[5];
		rupeesBuy[5] = fx.foreignBuy[5] * buy.Riyal;
		cout << "Enter amount of " << currency[5] << " Sold: ";
		cin >> fx.foreignSell[5];
		rupeesSell[5] = fx.foreignSell[5] * sell.Riyal;
		fx.profit[5] = rupeesSell[5] - rupeesBuy[5];
		cout << endl;
		cout << "Enter amount of " << currency[6] << " Bought: ";
		cin >> fx.foreignBuy[6];
		rupeesBuy[6] = fx.foreignBuy[6] * buy.Yuan;
		cout << "Enter amount of " << currency[6] << " Sold: ";
		cin >> fx.foreignSell[6];
		rupeesSell[6] = fx.foreignSell[6] * sell.Yuan;
		fx.profit[6] = rupeesSell[6] - rupeesBuy[6];
		fbuy.close();
		fsell.close();
		system("cls");

		cout << " --------------------------------------------------------------------\n";
		Sleep(50);
		cout << "|   Currency   |     Bought     |    Sold    |   Total Profit(PKR)   |\n";
		Sleep(50);
		cout << " --------------------------------------------------------------------\n";
		Sleep(50);

		for (int count = 0; count < 7; count++)
		{
			cout << "|" << setw(8) << currency[count] << "\t|" << setw(8) << fx.foreignBuy[count] << "\t|" << setw(8) << fx.foreignSell[count] << "\t|" << setw(8) << fx.profit[count] << "\t|\n";
			Sleep(50);
		}

		for (int count = 0; count < 7; count++)
		{
			if (fx.foreignBuy[count] > fx.foreignSell[count])
			{
				cout << "You need to sell " << fx.foreignBuy[count] - fx.foreignSell[count] << " " <<currency[count] << " by the end of the day\n";
			}
			else if (fx.foreignSell[count] > fx.foreignBuy[count])
			{
				cout << "You need to buy " << fx.foreignSell[count] - fx.foreignBuy[count] << " " <<currency[count] << " by end of the day\n";
			}
		}
		time_t now = time(0);
		char dt[30];
		ctime_s(dt, sizeof(dt), &now);
		cout << "Press enter to make record, else press any key to exit..";
		choice = _getch();
		if (choice == 13)
		{
			file << "Record for " << dt << "\n";
			file << " --------------------------------------------------------------------\n";
			file << "|   Currency   |     Bought     |    Sold    |   Total Profits(PKR)   |\n";
			file << " --------------------------------------------------------------------\n";
			for (int count = 0; count < 7; count++)
			{
				file << "|" << setw(8) << currency[count] << "\t|" << setw(8) << fx.foreignBuy[count] << "\t|" << setw(8) << fx.foreignSell[count] << "\t|" << setw(8) << fx.profit[count] << "\t|\n";

			}
			for (int count = 0; count < 7; count++)
			{
				if (fx.foreignBuy[count] > fx.foreignSell[count])
				{
					file << "You need to sell " << fx.foreignBuy[count] - fx.foreignSell[count] << " " << currency[count] << " by the end of the day\n";
				}
				else if (fx.foreignSell[count] > fx.foreignBuy[count])
				{
					file << "You need to buy " << fx.foreignSell[count] - fx.foreignBuy[count] << " " << currency[count] << " by end of the day\n";
				}
			}
			file << endl;
			file.close();

		}
		else 
		{
		}
		cin.ignore();
	}
	void displayBlotterRecord() {

		system("cls");
		string temp;
		int count;
		char pass[20] = {'\0'}, ch[20];

		star();
		cout << "Password Protected";
		star();
		fflush(stdin);
		cout << "\n\n\nEnter Admin Password: ";
		for (count = 0; count < 20; count++)
		{
			ch[count] = _getch();
			if (ch[count] == 13)
			{
				break;
			}
			pass[count] = ch[count];
			cout << "*";
		}
		system("pause");
		system("cls");
		cout << "\t\t -*-FX Blotter Records-*-\n\n";
		if (strcmp(pass,AdminPass) == 0) 
		{
			fstream fp;
			fp.open("fxBlotterRecord.dat", ios::in);
			while (getline(fp,temp))
			{
				cout << temp << endl;
			}
			fp.close();
		}
		else
		{
			cout << "Invalid Password, Try Again\n\n";
		}
	}
	void setForeignCurrency()
	{
		foreignCurrency var;
		cout << "Enter USD buying rate: ";
		cin >> var.USD;
		cout << "Enter Euro buying rate: ";
		cin >> var.Euro;
		cout << "Enter Pound buying rate: ";
		cin >> var.Pound;
		cout << "Enter CAD buying rate: ";
		cin >> var.CAD;
		cout << "Enter UAE Dhiram buying rate: ";
		cin >> var.Dhiram;
		cout << "Enter Saudi Riyal buying rate: ";
		cin >> var.Riyal;
		cout << "Enter Chinese Yuan buying rate: ";
		cin >> var.Yuan;
		
		fstream file;
		file.open("foreignExchangeBuy.dat", ios::out);
		file.write((char*)&var, sizeof(foreignCurrency));
		file.close();

		cout << "Enter USD selling rate: ";
		cin >> var.USD;
		cout << "Enter Euro selling rate: ";
		cin >> var.Euro;
		cout << "Enter Pound selling rate: ";
		cin >> var.Pound;
		cout << "Enter CAD selling rate: ";
		cin >> var.CAD;
		cout << "Enter UAE Dhiram selling rate: ";
		cin >> var.Dhiram;
		cout << "Enter Saudi Riyal selling rate: ";
		cin >> var.Riyal;
		cout << "Enter Chinese Yuan selling rate: ";
		cin >> var.Yuan;

		file.open("foreignExchangeSell.dat", ios::out);
		file.write((char*)&var, sizeof(foreignCurrency));
		file.close();
	}
	void display()
	{
		static int i = 5, j= 35;
		cout << name;
		gotoxy(j, i);
		cout << iDNum << endl << endl;
		i += 2;
	}
	int getID() const
	{
		return iDNum;
	}
};
void star() {

	for (int count = 0; count < 5; count++)
	{
		Sleep(50);
		cout << "*";
		Sleep(50);
		cout << "-";
	}
}

void createAccount()
{
	system("cls");
	cout << "\t\t\t\t\t";
	star();
	cout << "ACCOUNT MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 1. Current\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 2. Savings\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 3. Asaan\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 4. Exit\n\n\n";
	char type[10];
	long int num = 1000000;
	long int accTemp, count;
	char choice;
	fstream file;
	file.open("accountNums.dat",ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			for (count = 0; ; count++)
			{
				file >> accTemp;
				if (file.eof())
				{
					break;
				}
				if (accTemp == num)
				{
					num++;
					file.seekg(0, file.beg);
				}
			}
		}
	}
	file.close();
	choice = _getch();
	system("cls");
	fflush(stdin);
	if (choice == '1')
	{
		strcpy_s(type, "Current");
		Account obj(type, num);
		obj.getData(type);
		if (obj.getBalance() > 5000)
		{
			obj.fileData();
			cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
		}
		else
		{
			cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required.";
			cout << "Do you want to try again?" << endl;
			cout << "1. Yes" << endl << "2. No" << endl;
			choice = _getch();
			if (choice == '1')
			{
				double amount;
				cout << "Enter First Deposit: ";
				cin >> amount;
				if (amount > 5000)
				{
					obj.setBalance(amount);
					obj.fileData();
					cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
				}
				else
				{
					cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required." << endl;
					cout << "Please try again later.";
				}
			}
			else if (choice == '2')
			{
			
			}
			else
			{
				cout << "Invalid Input, try again later";
			}
		}
	}
	else if (choice == '2')
	{
		strcpy_s(type, "Savings");
		Account obj(type, num);
		obj.getData(type);
		if (obj.getBalance() > 5000)
		{
			obj.fileData();
			cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
		}
		else
		{
			cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required.";
			cout << "Do you want to try again?";
			cout << "1. Yes" << endl << "2. No" << endl;
			choice = _getch();
			if (choice == '1')
			{
				double amount;
				cout << "Enter First Deposit: ";
				cin >> amount;
				if (amount > 5000)
				{
					obj.setBalance(amount);
					obj.fileData();
					cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
				}
				else
				{
					cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required." << endl;
					cout << "Please try again later.";
				}
			}
			else if (choice == '2')
			{
				
			}
			else
			{
				cout << "Invalid Input, try again later";
			}
		}
	}
	else if (choice == '3')
	{
		strcpy_s(type, "Asaan");
		Account obj(type, num);
		obj.getData(type);
		if (obj.getBalance() > 100)
		{
			obj.fileData();
			cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
		}
		else
		{
			cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required.";
			cout << "Do you want to try again?";
			cout << "1. Yes" << endl << "2. No" << endl;
			choice = _getch();
			if (choice == '1')
			{
				double amount;
				cout << "Enter First Deposit: ";
				cin >> amount;
				if (amount > 100)
				{
					obj.setBalance(amount);
					obj.fileData();
					cout << "Your Account has successfully been created, your Account Number is " << obj.getAccountNum() << endl;
				}
				else
				{
					cout << "Your Deposit is insufficent to create account, amount greater than Rs.5000 is required." << endl;
					cout << "Please try again later.";
				}
			}
			else if (choice == '2')
			{
				
			}
			else
			{
				cout << "Invalid Input, try again later";

			}
		}
	}
	else if (choice == '4')
	{

	}
	else
	{
		cout << "Wrong Input, Try Again.";
		createAccount();
	}

}
void foreignConversion(foreignCurrency& var, char choice)
{
	double result, amount;
	char c;
	if (choice == '1')
	{
		cout << "Which Currency do you want to buy? " << endl;
		c = _getch();
		cout << "How much do you want to convert?: Rs.";
		cin >> amount;
		if (c == '1')
		{
			result = amount / var.USD;
			cout << "Converted Amount: " << result << " USD" << endl;
		}
		else if (c == '2')
		{
			result = amount / var.Euro;
			cout << "Converted Amount: " << result << " Euro" << endl;
		}
		else if (c == '3')
		{
			result = amount / var.Pound;
			cout << "Converted Amount: " << result << " Pound" << endl;
		}
		else if (c == '4')
		{
			result = amount / var.CAD;
			cout << "Converted Amount: " << result << " CAD" << endl;
		}
		else if (c == '5')
		{
			result = amount / var.Dhiram;
			cout << "Converted Amount: " << result << " Dhiram" << endl;
		}
		else if (c == '6')
		{
			result = amount / var.Riyal;
			cout << "Converted Amount: " << result << " Riyal" << endl;
		}
		else if (c == '7')
		{
			result = amount / var.Yuan;
			cout << "Converted Amount: " << result << " Yuan" << endl;
		}
		else
		{
			cout << "Invalid Input Try Again." << endl;
			system("pause");
			system("cls");
			foreignMenu();
		}
	}
	else if (choice == '2')
	{
		cout << "Which Currency do you want to sell? " << endl;
		c = _getch();
		cout << "How much do you want to convert?: Rs.";
		cin >> amount;
		if (c == '1')
		{
			result = amount * var.USD;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '2')
		{
			result = amount * var.Euro;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '3')
		{
			result = amount * var.Pound;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '4')
		{
			result = amount * var.CAD;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '5')
		{
			result = amount * var.Dhiram;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '6')
		{
			result = amount * var.Riyal;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else if (c == '7')
		{
			result = amount * var.Yuan;
			cout << "Converted Amount: Rs." << result << endl;
		}
		else
		{
			cout << "Invalid Input Try Again." << endl;
			system("pause");
			system("cls");
			foreignMenu();
		}
	}
	cin.ignore();
}
void foreignMenu()
{
	system("cls");
	cout << "\t\t\t\t\t";
	star();
	cout << "FOREIGN EXCHANGE MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 1. Foreign Currency Buy Rate\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 2. Foreign Currency Sell Rate\n\n\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB 3. Exit\n\n";
	char choice;
	choice = _getch();
	foreignCurrency var;
	system("cls");
	if (choice == '1')
	{
		var = foreignBuyRates();
		foreignConversion(var, choice);
	}
	else if (choice == '2')
	{
		var = foreignSellRates();
		foreignConversion(var, choice);
	}
}
foreignCurrency foreignSellRates()
{
	foreignCurrency var;
	fstream file;
	file.open("foreignExchangeSell.dat", ios::in);
	file.read((char*)&var, sizeof(foreignCurrency));
	cout << "1. USD Selling Rate: " << var.USD << endl;
	cout << "2. Euro Selling Rate: " << var.Euro << endl;
	cout << "3. Pound Selling Rate: " << var.Pound << endl;
	cout << "4. CAD Selling Rate: " << var.CAD << endl;
	cout << "5. UAE Dhiram Selling Rate: " << var.Dhiram << endl;
	cout << "6. Saudi Riyal Selling Rate: " << var.Riyal << endl;
	cout << "7. Chinese Yuan Selling Rate: " << var.Yuan << endl << endl;
	return var;
}
foreignCurrency foreignBuyRates()
{
	foreignCurrency var;
	fstream file;
	file.open("foreignExchangeBuy.dat", ios::in);
	file.read((char*)&var, sizeof(foreignCurrency));
	cout << "1. USD Buying Rate: " << var.USD << " USD" << endl;
	cout << "2. Euro Buying Rate: " << var.Euro << " Euro" << endl;
	cout << "3. Pound Buying Rate: " << var.Pound << "Pound" << endl;
	cout << "4. CAD Buying Rate: " << var.CAD << " CAD" << endl;
	cout << "5. UAE Dhiram Buying Rate: " << var.Dhiram << " Dhiram" << endl;
	cout << "6. Saudi Riyal Buying Rate: " << var.Riyal << " Riyal" << endl;
	cout << "7. Chinese Yuan Buying Rate: " << var.Yuan << " Yuan" << endl << endl;
	return var;
}
void menu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "MAIN MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Customer\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Employee\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Exit\n\n\n";
	choice = _getch();
	if (choice == '1')
	{
		customerMenu();
	}
	else if (choice == '2')
	{
		system("cls");
		cout << "\t\t\t\t\t-*-*-*-EMPLOYEE LOGIN-*-*-*-\n\n\n\n";
		Employee obj;
		if (obj.login())
		{
			animation2();
			employeeMenu();
			obj.timeOut();
		}
		else
		{
			menu();
		}

	}
	else if (choice == '3')
	{
		endScreen();
		exit(1);
	}
	else
	{
		cout << "Invalid Input, try again. \n\n";
		system("pause");
		menu();
	}
}
int transaction()
{
	system("cls");
	char choice;
	Account obj,obj2;
	cout << "\t\t\t\t\t";
	star();
	cout << "TRANSACTION MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Withdraw Amount\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Deposit Amount\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Bank Transfer\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Exit\n\n";
	choice = _getch();
	if (choice >= '4')
	{
		return 0;
	}
	string accNum, temp;
	fstream fp, fs;
	cout << "Enter Account No: ";
	getline(cin, accNum);
	temp = accNum;
	temp += ".dat";
	fp.open(temp, ios::in);
	if (!fp.is_open())
	{
		cout << "Invalid Account Number, Try Again." << endl << endl;
		system("pause");
		transaction();
	}
	obj.filing(fp, false);
	fp.close();
	if (choice == '1')
	{
		if (checkCredentials(obj))
		{
			obj.withdraw();
			fp.open(temp,ios::out);
			obj.filing(fp, true);
			fp.close();
		}
	}
	else if (choice == '2')
	{
		if (checkCredentials(obj))
		{
			obj.deposit();
			fp.open(temp, ios::out);
			obj.filing(fp, true);
			fp.close();
		}
	}
	else if (choice == '3')
	{
		if (checkCredentials(obj))
		{
			cout << "Enter Account Number of Receiver: ";
			getline(cin, accNum);
			accNum += ".dat";
			fp.open(accNum, ios::in);
			obj2.filing(fp, false);
			obj2.displayData();
			fp.close();
			obj.transfer(obj2);
			fp.open(accNum, ios::out);
			obj2.filing(fp, true);
			fp.close();
			fp.open(temp, ios::out);
			obj.filing(fp, true);
			fp.close();
		}
	}
}
void bankStatement()
{
	system("cls");
	Account obj;
	string accNum,temp;
	char choice;
	fstream fp,fs;
	cout << "Enter Account No.: ";
	getline(cin, accNum);
	temp = accNum;
	temp += "statement.dat";
	fp.open(temp, ios::in);
	temp = accNum;
	temp += ".dat";
	fs.open(temp, ios::in);
	obj.filing(fs, false);
	if (!fs.is_open())
	{
		cout << "File has not been opened." << endl;
	}
	fs.close();
	if (obj.getType() == "Savings")
	{
		if (obj.checkYear())
		{
			obj.calSavingsProfit();
			fs.open(temp, ios::out);
			obj.filing(fs, true);
			fs.close();
		}
		
	}
	if (fp.is_open())
	{
		if (checkCredentials(obj))
		{
			cout << endl << "Current Account Balance: " << obj.getBalance() << endl << endl;
			while (getline(fp,temp))
			{
				cout << temp <<endl;
			}
		}
		else
		{
			cout << "Invalid Credentails, Try Again." << endl;
		}
		fp.close();
	}
	else
	{
		cout << "No transactions have been made." << endl;
	}
}
void customerMenu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "CUSTOMER MENU";
	star();
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\xDB 1. Create New Account\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Bank Statement\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Transaction\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Loan Details\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 5. Foreign Exchange\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 6. Exit\n\n";
	choice = _getch();
	if (choice == '1')
	{
		createAccount();
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if (choice == '2')
	{
		bankStatement();
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if (choice == '3')
	{
		transaction();
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if (choice == '4')
	{
		loanMenu();
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if (choice == '5')
	{
		foreignMenu();
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if (choice == '6')
	{
		system("cls");
		menu();
	}
	else
	{
		cout << "Invalid Input, Try again." << endl << endl;
		system("pause");
		system("cls");
		customerMenu();

	}
}
void allAccounts()
{
	Account obj;
	int count = 1;
	long int temp;
	string fileName;
	fstream fp,fs;
	fp.open("accountNums.dat", ios::in);
	cout << setw(7) << "Name" << setw(20) << "Account No." << endl << endl;
	while (!fp.eof())
	{
		fp >> temp;
		if (fp.eof())
		{
			break;
		}
		fileName = to_string(temp);
		fileName += ".dat";
		fs.open(fileName, ios::in);
		obj.filing(fs, false);
		cout << count << ". " << obj.getName() << setw(15) << obj.getAccountNum() << endl << endl;
		fs.close();
		count++;
	}

}
void employeeMenu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "EMPLOYEE MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Customer Accounts\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Loan Details\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Update Bank Rates\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. FX Blotter\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 5. Admin\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 6. Exit\n\n";
	choice = _getch();
	if (choice == '1')
	{
		system("cls");
		cout << "\t\t\t\t\t";
		star();
		cout << "CUSTOMER ACCOUNTS";
		star();
		cout << "\n\n\n\n";
		cout << "\t\t\t\t\xDB 1. List of All Accounts\n\n\n";
		cout << "\t\t\t\t\xDB 2. Find Specific Account Details\n\n\n";
		cout << "\t\t\t\t\xDB 3. Exit\n\n";
		choice = _getch();
		system("cls");
		if (choice == '1')
		{
			allAccounts();
		}
		else if (choice == '2')
		{
			Account obj;
			string accNum;
			fstream fp;
			cout << "Enter Account No: ";
			getline(cin, accNum);
			accNum += ".dat";
			fp.open(accNum, ios::in);
			obj.filing(fp, false);
			fp.close();
			obj.displayData();
			if (obj.getMonthly() > 0)
			{
				cout << "Loan Status: Active" << endl << endl;
				cout << "Do you want to see loan details? 'y' for Yes or 'n' for No" << endl;
				choice = _getch();
				if (choice == 'y' || choice == 'Y')
				{
					obj.empLoanDisplay();
				}
				else if (choice == 'n' || choice == 'N')
				{
					exit(1);
				}
			}
			else
			{
				cout << "Loan Status: None" << endl << endl;
			}

		}
		else if (choice == '3')
		{
			cout << "\n\n\n";
			system("pause");
			employeeMenu();
		}
	}
	else if (choice == '2')
	{
		empLoanMenu();
		cout << "\n\n\n";
		system("pause");
		employeeMenu();
	}
	else if (choice == '3')
	{
		foreignEmpMenu();
		cout << "\n\n\n";
		system("pause");
		employeeMenu();
		
	}
	else if (choice == '4')
	{
		fxBlotter();
		cout << "\n\n";
		system("pause");
		employeeMenu();
	}
	else if (choice == '5')
	{
		system("cls");
		int count;
		char temp[10], password[10] = {'\0'};
		cout << "\n\t\t-*-*-Password Protected-*-*-\n\n";
		cout << "Admin Password: ";
		for (count = 0; count < 10; count++)
		{
			temp[count] = _getch();
			if (temp[count] == 13)
			{
				break;
			}
			password[count] = temp[count];
			cout << "*";
		}
		if (strcmp(password, AdminPass) == 0)
		{
			adminMenu();
		}
		else
		{
			cout << "\n\nPassword is incorrect.\n\n";
			system("pause");
			employeeMenu();
		}
		cout << "\n\n";
		system("pause");
		employeeMenu();
	}
	else if (choice == '6')
	{
		system("cls");
		menu();
	}
	else
	{
		cout << "Invalid Input, Try again." << endl << endl;
		system("pause");
		employeeMenu();
	}
}
void foreignEmpMenu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "BANK RATES";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Foreign Exchange Rates\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Savings Account Rate\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Exit\n\n";
	Employee emp;
	choice = _getch();
	if (choice == '1')
	{
		system("cls");
		cout << "	CURRENT FOREIGN RATE\n\n";
		foreignBuyRates();
		foreignSellRates();
		cout << "Do you want to update exchange rates? Press 'y' for Yes or 'n' for No." << endl;
		choice = _getch();
		if (choice == 'y' || choice == 'Y')
		{
			emp.setForeignCurrency();
		}
		else if (choice == 'n' || choice == 'N')
		{
			
		}
		else
		{
			cout << "Invalid Input, Try Again.\n\n";
		}
	}
	else if (choice == '2')
	{
		emp.updateSavingRate();
	}
	else if (choice == '3')
	{
		
	}
	else
	{
		cout << "Invalid Input, Try Again later." << endl;
	}
}
void adminMenu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "ADMIN MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Add New Employee Data\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Check Employee Log\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Employee List\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Exit\n\n";
	choice = _getch();
	if (choice == '1')
	{
		Employee emp;
		emp.createEmployee();
		cout << "\n\n";
		system("pause");
		adminMenu();
	}
	else if (choice == '2')
	{
		string temp;
		fstream fp;
		fp.open("employeeLogs.dat", ios::in);
		while (getline(fp, temp))
		{
			cout << temp << endl;
		}
		fp.close();
		cout << "\n\n\n";
		system("pause");
		adminMenu();
	}
	else if (choice == '3')
	{
		system("cls");
		int count;
		fstream fp;
		Employee emp;
		fp.open("employeeList.dat", ios::in);
		cout << "\t\t-*-List of Employees-*-\n\n\n";
		cout << "\t Name" << setw(25) << "ID\n\n";
		emp.readEmp();
		cout << "\n\n\n";
		system("pause");
		adminMenu();
	}
	else if (choice == '4')
	{
		
	}
	else
	{
		cout << "Invalid Input, try again.\n\n";
		system("pause");
		adminMenu();
	}
}
void fxBlotter()
{
	system("cls");
	char choice;
	Employee emp;
	cout << "\t\t\t\t\t";
	star();
	cout << "FX BLOTTER MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Create Blotter Record\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Display Blotter Records(Admin Access only)\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Exit\n\n";
	choice = _getch();
	if (choice == '1')
	{
		emp.createBlotterRecord();
	}
	else if (choice == '2')
	{
		emp.displayBlotterRecord();
	}
	else if (choice == '3') 
	{

	}
	else
	{
		cout << "Invalid Input, Try Again.\n\n";
		system("pause");
		fxBlotter();
	}

}
bool checkCredentials(Account acc)
{
	string name;
	int count;
	char temp;
	char pin[10] = { '\0' };
	cout << "Enter Name: ";
	getline(cin, name);
	cout << "Enter PIN: ";
	for (count = 0; count < 5; count++)
	{
		temp = _getch();
		if (temp == 13)
		{
			break;
		}
		pin[count] = temp;
		cout << "*";
	}
	if (acc.accCheck(pin, name))
	{
		system("cls");
		return true;
	}
	else
	{
		"Invalid Credentials, Try again.\n\n";
		return false;
	}
}
void loanMenu()
{
	system("cls");
	char choice;
	Account obj;
	string accNum, name, temp;
	int pin = '\0';
	fstream fp;
	cout << "\t\t\t\t\t";
	star();
	cout << "LOAN MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. Take a Loan\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Pay Loan\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Check Loan Status\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Check Loan Details\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 5. Exit\n\n\n";
	choice = _getch();
	if (choice == '1')
	{
		system("cls");
		cout << "Enter Account No: ";
		getline(cin, accNum);
		temp = accNum;
		temp += ".dat";
		fp.open(temp, ios::in);
		if (!fp.is_open())
		{
			cout << "Invalid Account Number." << endl;
			exit(1);
		}
		obj.filing(fp, false);
		fp.close();
		
		if (checkCredentials(obj))
		{
			obj.takeLoan();
			fp.open(temp, ios::out);
			obj.filing(fp, true);
			fp.close();
		}
		else
		{
			system("pause");
			loanMenu();
		}
	}
	else if (choice == '2')
	{
		cout << "Enter Account No: ";
		getline(cin, accNum);
		temp = accNum;
		temp += ".dat";
		fp.open(temp, ios::in);
		if (!fp.is_open())
		{
			cout << "Invalid Account Number." << endl;
		}
		obj.filing(fp, false);
		fp.close();

		if (checkCredentials(obj))
		{
			obj.payLoan();
			fp.open(temp, ios::out);
			obj.filing(fp, true);
			fp.close();
		}
		else
		{
			system("pause");
			loanMenu();
		}
		cout << "\n\n";
		system("pause");
		customerMenu();
	}
	else if(choice == '3')
	{
		cout << "Enter Account No: ";
		getline(cin, accNum);
		temp = accNum;
		temp += ".dat";
		fp.open(temp, ios::in);
		if (!fp.is_open())
		{
			cout << "Invalid Account Number." << endl;
			exit(1);
		}
		obj.filing(fp, false);
		fp.close();
		if (checkCredentials(obj))
		{
			obj.checkLoanStatus();
			fp.open(temp, ios::out);
			obj.filing(fp, true);
			fp.close();
		}
	}
	else if (choice == '4')
	{
		cout << "Enter Account No: ";
		getline(cin, accNum);
		temp = accNum;
		temp += ".dat";
		fp.open(temp, ios::in);
		if (!fp.is_open())
		{
			cout << "Invalid Account Number." << endl;
			exit(1);
		}
		obj.filing(fp, false);
		fp.close();
		if (checkCredentials(obj))
		{
			obj.custLoanDisplay();
		}
		
	}
	else if (choice == '5')
	{
		employeeMenu();
	}
	else
	{
		cout << "Invalid Input, Try Again." << endl << endl;
		system("pause");
		loanMenu();
	}
}
void empLoanMenu()
{
	system("cls");
	char choice;
	cout << "\t\t\t\t\t";
	star();
	cout << "LOAN MENU";
	star();
	cout << "\n\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 1. List of Active Loans\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 2. Evaluate Loans\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 3. Check Loan Details\n\n\n";
	Sleep(200);
	cout << "\t\t\t\t\xDB 4. Exit\n\n\n";
	choice = _getch();
	if (choice == '1')
	{
		system("cls");
		fstream fp,fs,f;
		string temp,temp2,num;
		Account acc;
		int count = 1;
		fp.open("activeLoan.dat", ios::in);
		if (!fp.is_open())
		{
			cout << "There are no active loans" << endl;
		}
		else
		{
			cout << setw(7) << "Name" << setw(20) << "Account No."  << setw(20) << "Remaining Amount" << endl << endl;
		}
		while (getline(fp, temp))
		{
			num = temp;
			temp += ".dat";
			fs.open(temp, ios::in);
			acc.filing(fs, false);
			fs.close();
			if (acc.getLoanBal() <= 0)
			{
				cout << count << ". " << acc.getName() << setw(15) << acc.getAccountNum() << setw(15) << "Completed" << endl << endl;
				
			}
			else
			{
				cout << count << ". " << acc.getName() << setw(15) << acc.getAccountNum() << setw(15) << acc.getLoanBal() << endl << endl;
			}
		}
		fp.close();
		
	}
	else if (choice == '2')
	{
		system("cls");
		Employee emp;
		emp.loanEval();
	}
	else if (choice == '3')
	{
		system("cls");
		Account acc;
		fstream fp;
		string accNum;
		cout << "Enter Customer Account: ";
		getline(cin, accNum);
		accNum += ".dat";
		fp.open(accNum, ios::in);
		acc.filing(fp, false);
		fp.close();
		acc.custLoanDisplay();
	}
	else if (choice == '4')
	{

	}
	else
	{
		cout << "Invalid Input, try again.\n\n";
		system("pause");
		empLoanMenu();
	}
}
void mainScreen()
{
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n";
	Sleep(100);
	cout << "\t\t\t\t\xB2\t\t\t\t\t\t\t\xB2\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB\t\t\t WELCOME\t\t\t\xDB\n";
	Sleep(100);
	cout << "\t\t\t\t\xB2\t\t\t   TO\t\t\t\t\xB2\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB\t\t\tFAST BANK\t\t\t\xDB\n";
	Sleep(100);
	cout << "\t\t\t\t\xB2\t\t\t\t\t\t\t\xB2\n";
	Sleep(100);
	cout << "\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n";
	Sleep(100);
	cout << "\t\t\t\t\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n";
	Sleep(2000);
}
void endScreen()
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xB2\t\t\t\t\t\t\t\xB2\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xB2\t\t\tProject\t\t\t\t\xB2\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t  by\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xB2\t\t Aayaan Khurram 20K-1606\t\t\xB2\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t Umer Farooq 20K-1625\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xB2\t\t\t\t\t\t\t\xB2\n");
	Sleep(100);
	printf("\t\t\t\t\xDB\t\t\t\t\t\t\t\xDB\n");
	Sleep(100);
	printf("\t\t\t\t\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\n");
	Sleep(2000);
}
int main()
{
	system("color 74");
	mainScreen();
	menu();
	Employee obj;

}
