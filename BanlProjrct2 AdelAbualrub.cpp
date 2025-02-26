#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <thread>f
#include <chrono>
#include <fstream>

#pragma warning(disable :4996);
using namespace std;
string FileName = "NewFile.txt";
string UserFileNaame="UserFileName.txt";
void CreateFileIfNotExist(string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);  // Create a new file
	if (MyFile.is_open()) {
		cout << "New file '" << FileName << "' created successfully.\n";
		// You can write initial content to the file if needed:
		// MyFile << "Initial content or headers\n";
		MyFile.close();
	}
	else {
		cout << "Failed to create the file. Exiting program.\n";
		exit(0);
	}
}
int RandomNum(int from, int to) {

	int Rand = rand() % (to - from + 1) + from;
	return Rand;



}

void SaveVectorTofile(string FileName, vector <string> V) {
	fstream Myfile;
	Myfile.open(FileName, ios::out);
	if (Myfile.is_open()) {
		for (string& Line : V) {
			if (Line != " ") {

				Myfile << Line << endl;

			}
		}
		Myfile.close();
	}
}
void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent) {
	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read Mod
	if (MyFile.is_open()) {
		string line;
		while (getline(MyFile, line)) {
			vFileContent.push_back(line);



		}


		MyFile.close();


	}
	else cout << "Error";




}
void PrintFromFile(string FileName) {
	fstream MyFile;
	string line;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		while (getline(MyFile, line)) {

			cout << line << endl;



		}



		MyFile.close();
	}
}
void PrintName() {
	string name;
	cout << "Enter your name\n";


	getline(cin, name);
	cout << name;



}
int ReadNumber() {
	int num = 0;
	cout << "Please enter number\n";
	cin >> num;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> num;




	}
	return num;




}
void DeleteRecordFromFile(string FileName, string Record) {
	vector <string> Vf;
	LoadDataFromFileToVector(FileName, Vf);
	for (string& N : Vf) {
		if (N == Record)
			N = "";






	}
	SaveVectorTofile(FileName, Vf);






}









void ReadNumberV(vector<int>& Vnum) {
	char ReadNumberr = 'y';
	while (ReadNumberr == 'y' || ReadNumberr == 'Y') {
		int num = ReadNumber();
		Vnum.push_back(num);
		cout << "Do you want to enter more number Yes::y, No::n\n"
			;
		cin >> ReadNumberr;

	}



}
void PrintVector(vector <int> Vnum) {
	cout << " Number Inside vector\n";
	for (int& num : Vnum)
		cout << num << endl;



}



string EnterString() {
	string s;
	cout << "Please enter astring\n";
	getline(cin, s);
	return  s;


}

string  StringToUpper(string name) {
	for (int i = 0; i < name.length(); i++) {

		name[i] = toupper(name[i]);

	}

	cout << "string after upper \n";
	return name;
}
string StringToLower(string name) {
	for (int i = 0; i < name.length(); i++) {

		name[i] = tolower(name[i]);

	}


	return name;
}
char InvertChar(char s) {
	if (islower(s))
		s = toupper(s);
	else
		s = tolower(s);

	return s;

}
string InvertAllLetter(string name) {

	for (int i = 0; i < name.length(); i++) {
		name[i] = InvertChar(name[i]);
	}
	return name;
}

void PrintEachWordInStrring(string s, string del) {
	short pos = 0;
	string sword;
	while ((pos = s.find(del)) != std::string::npos) {

		sword = s.substr(0, pos);
		cout << sword << " \n";
		s.erase(0, pos + del.length());

	}
	cout << s;

}

vector<string> SplitString(string S1, string Delim) {
	vector<string> vString;
	size_t pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {
		vString.push_back(S1);
	}
	return vString;
}
string TrimLift(string MyString) {
	int pos = 0;
	for (int i = 0; i < MyString.length(); i++) {
		if (MyString[i] != ' ')
		{
			return MyString.substr(i, MyString.length() - 1);
		}

	}

	return "";

}

string JoinString(vector <string> Vs, string sip) {
	string Adel;


	for (string& R : Vs) {
		Adel = Adel.append(R) + sip;
	}
	cout << "Vector after Joining\n";
	return Adel.substr(0, Adel.length() - sip.length());
}
string JoinString(string Vs[100], string sip) {
	string Adel;

	for (int i = 0; i < Vs->length(); i++) {

		Adel += Vs[i] + sip;



	}
	cout << "Array after joining string\n";
	return Adel.substr(0, Adel.length() - sip.length());
}
string  ReversString(string MyString) {
	string NewString;
	for (int i = MyString.length(); i >= 0; i--) {

		if (MyString[i] == ' ') {


			NewString += MyString.substr(i, MyString.length());
			MyString.erase(i, MyString.length());
		}


	}

	NewString += " " + MyString;
	return TrimLift(NewString);

}

struct sClientInfo {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0.0;
	bool IsAcountNumberExists = false;


};
sClientInfo ReadInfo() {
	sClientInfo s;
	cout << "Enter Account number\n";
	getline(cin >> ws, s.AccountNumber);
	s.IsAcountNumberExists = true;
	cout << "Enter  PinCode\n";
	getline(cin, s.PinCode);
	cout << "Enter Name\n";
	getline(cin, s.Name);
	cout << "Enter phone number\n";
	cin >> s.Phone;
	cout << "Enter Account Balance\n";
	cin >> s.AccountBalance;
	return s;


}
sClientInfo ReadInfo(string AccountNumber) {
	sClientInfo s;

	s.AccountNumber = AccountNumber;

	cout << "Enter  PinCode\n";
	getline(cin >> ws, s.PinCode);
	cout << "Enter Name\n";
	getline(cin, s.Name);
	cout << "Enter phone number\n";
	cin >> s.Phone;
	cout << "Enter Account Balance\n";
	cin >> s.AccountBalance;
	return s;


}

string ConvertRecordToLine(sClientInfo s, string Seperator) {
	string r = "";
	r = s.AccountNumber + Seperator + s.PinCode + Seperator + s.Name + Seperator + s.Phone + Seperator + to_string(s.AccountBalance);

	return r;
}
sClientInfo ConvertLineToRecord(string line, string Seperator) {
	sClientInfo Client;
	vector<string> Vstring = SplitString(line, Seperator);

	if (Vstring.size() >= 5) { 
		Client.AccountNumber = Vstring[0];
		Client.PinCode = Vstring[1];
		Client.Name = Vstring[2];
		Client.Phone = Vstring[3];
		Client.AccountBalance = stod(Vstring[4]);
	}
	else {
		cerr << "Error: Invalid line format. Expected 5 fields.\n"; 
		Client.AccountNumber = "";
		Client.PinCode = "";
		Client.Name = "";
		Client.Phone = "";
		Client.AccountBalance = 0.0;
	}

	return Client;
}

///////////////////////////////////////////////////////////////////////////////////////
void AddClientToFile(string info, string FileName) {

	fstream MyFile;
	MyFile.open(FileName, ios::app);
	if (MyFile.is_open()) {
		MyFile << info << endl;




		MyFile.close();
	}
	else  cout << "⚠️ Error: Could not open file " << FileName << endl;



}
vector <sClientInfo> LoadDataClientFromFile(string FileName) {
	vector <sClientInfo> VclientInfo;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sClientInfo NeC;
		while (getline(MyFile, Line)) {
			NeC = ConvertLineToRecord(Line, "+++");
			VclientInfo.push_back(NeC);


		}
		MyFile.close();


	}
	else {
		cout << "File Did not open\n";
		exit(0);
		
	}
	
	return VclientInfo;
}

bool IsAcountNumberEntered(string AccountNumber, string FileName) {
	vector <sClientInfo>Vf = LoadDataClientFromFile(FileName);
	for (int i = 0; i < Vf.size(); i++) {

		if (AccountNumber == Vf[i].AccountNumber) {
			cout << "Your account number is already exists\n";
			return 1;
		}

	}
	return false;
}
///////////////////////////////////////////
void AddClient(string FileName) {
	char E = 'y';
	string info;
	while (E == 'y' || E == 'Y') {
		sClientInfo i;
		string Acc;
		cout << "Enter Account Number\n";
		cin >> i.AccountNumber;
		Acc = i.AccountNumber;
		string AccountNUmber = i.AccountNumber;
		while ((IsAcountNumberEntered(AccountNUmber, FileName))) {
			cout << "Enter a new account number\n ";
			cin >> AccountNUmber;
			i.AccountNumber = AccountNUmber;
		}


		i = ReadInfo(AccountNUmber);



		info = ConvertRecordToLine(i, "+++");
		AddClientToFile(info, FileName);


		cout << "Client Added Successfully, Do you want to add more clients yes :: y or Y no :: N or n\n";
		cin >> E;
		cin.ignore();





	}
}

void PrintClientRecord(sClientInfo Client) {
	cout << "| " << setw(15) << Client.AccountNumber;
	cout << "| " << setw(10) << Client.PinCode;
	cout << "| " << setw(40) << Client.Name;
	cout << "| " << setw(12) << Client.Phone;
	cout << "| " << setw(12) << Client.AccountBalance << endl;
}
void PrintClientRecordBalance(sClientInfo Client) {
	cout << "| " << setw(15) << Client.AccountNumber;

	cout << "| " << setw(40) << Client.Name;

	cout << "| " << setw(12) << Client.AccountBalance << endl;
}

void PrintAllClientsData(vector<sClientInfo> vClients) {
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s)).";
	cout << "\n__________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number"
		<< "| " << setw(10) << "Pin Code"
		<< "| " << setw(40) << "Client Name"
		<< "| " << setw(12) << "Phone"
		<< "| " << setw(12) << "Balance" << endl;
	cout << "__________________________________________________________________________________________\n";

	for (sClientInfo& Client : vClients) {
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "__________________________________________________________________________________________\n";

}

string ReadAccountNumber() {
	string AccountNumber;
	cout << "Please enter Acount number\n";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientDataFromAccountNumber(string AccountNumber, sClientInfo& Client) {
	vector <sClientInfo> SS = LoadDataClientFromFile(FileName);
	for (sClientInfo& R : SS) {
		if (R.AccountNumber == AccountNumber) {
			Client = R;
			return 1;

		}

	}

	return false;

}

void PrintClientCard(sClientInfo Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}


vector <sClientInfo> DeleteClientFromRecord(sClientInfo Client) {
	vector <sClientInfo> vClient = LoadDataClientFromFile(FileName);
	char DeleteClient = 'N';
	cout << "\nAre you sure you Want to delete the client (" << Client.AccountNumber << ") Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> DeleteClient;
	if (toupper(DeleteClient) == 'Y')
	{



		for (int i = 0; i < vClient.size();) {
			if (vClient[i].AccountNumber == Client.AccountNumber) {

				vClient.erase(vClient.begin() + i);

				return vClient;
				cout << "Client Deleted Successfully\n";
			}
			i++;

		}
		return vClient;
	}
	return vClient;
}

void DeleteClientFromFile(vector <sClientInfo> Info, string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (sClientInfo& S : Info) {
			In = ConvertRecordToLine(S, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << FileName << endl;





}
vector <sClientInfo> UpdateClientInfoFromRecord(sClientInfo Client) {
	char UpdateClient = 'N';
	cout << "\nAre you sure you Want to Update the client (" << Client.AccountNumber << ") info Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> UpdateClient;
	vector <sClientInfo> vClient = LoadDataClientFromFile(FileName);
	if (toupper(UpdateClient) == 'Y')
	{



		for (int i = 0; i < vClient.size();) {
			if (vClient[i].AccountNumber == Client.AccountNumber) {
				cout << "Enter PinCode :";
				getline(cin >> ws, vClient[i].PinCode);
				cout << "\nEnter Name:";
				getline(cin, vClient[i].Name);
				cout << "\nEnter Phone:";
				getline(cin, vClient[i].Phone);
				cout << "\nEnter Account Balance:";
				cin >> vClient[i].AccountBalance;

				cout << "Client Updated Successfully\n";
				return vClient;

			}
			i++;

		}
		return vClient;
	}
	return vClient;


}
void UpdateClientFromFile(vector <sClientInfo> Info, string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (sClientInfo& S : Info) {
			In = ConvertRecordToLine(S, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << FileName << endl;





}
void ShowwClientsData() {
	vector <sClientInfo> R1 = LoadDataClientFromFile(FileName);
	PrintAllClientsData(R1);



}
void ShowAddClient() {
	cout << "------------------------------------------\n";
	cout << "\t  Add New Client Screan\n";
	cout << "------------------------------------------\n";
	AddClient(FileName);


}
void ShowDeleteClient() {
	cout << "------------------------------------------\n";
	cout << "\t  Delete Screan\n";
	cout << "------------------------------------------\n";
	vector <sClientInfo> R1 = LoadDataClientFromFile(FileName);
	string AccountNumber = ReadAccountNumber();
	sClientInfo Client;
	if (FindClientDataFromAccountNumber(AccountNumber, Client)) {

		PrintClientCard(Client);
		R1 = DeleteClientFromRecord(Client);
		DeleteClientFromFile(R1, FileName);

	}
	else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";



}
void ShowUpdateClient() {
	cout << "------------------------------------------\n";
	cout << "\t  Update Screan\n";
	cout << "------------------------------------------\n";
	vector <sClientInfo> R1 = LoadDataClientFromFile(FileName);
	string AccountNumber = ReadAccountNumber();
	sClientInfo Client;
	if (FindClientDataFromAccountNumber(AccountNumber, Client)) {

		PrintClientCard(Client);
		R1 = UpdateClientInfoFromRecord(Client);
		UpdateClientFromFile(R1, "NewFile.txt");

	}
	else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";



}

void ShowFindClient() {
	cout << "------------------------------------------\n";
	cout << "\t  Find Client Screan\n";
	cout << "------------------------------------------\n";
	string AccountNumber = ReadAccountNumber();
	sClientInfo Client;
	if (FindClientDataFromAccountNumber(AccountNumber, Client)) {
		PrintClientCard(Client);


	}
	else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";




}
vector <sClientInfo> DepositFromRecord(sClientInfo Client) {
	vector <sClientInfo> vClient = LoadDataClientFromFile(FileName);
	char DoDeposit = 'N';
	double DepositAmmount = 0;
	cout << "\nenter deposit amount\n";
	cin >> DepositAmmount;

	cout << "\nAre you sure you Want to perfrom this transactin  (" << Client.AccountNumber << ") Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> DoDeposit;
	if (toupper(DoDeposit) == 'Y')
	{



		for (int i = 0; i < vClient.size();) {
			if (vClient[i].AccountNumber == Client.AccountNumber) {

				vClient[i].AccountBalance = (vClient[i].AccountBalance) + DepositAmmount;
				cout << "The Depost has been successfully completed.\n";
				cout << "Your new Balance is : " << vClient[i].AccountBalance << " " << endl;
				return vClient;

			}
			i++;

		}

		return vClient;
	}
	return vClient;
}

void DepositClientFromFile(vector <sClientInfo> Info, string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (sClientInfo& S : Info) {
			In = ConvertRecordToLine(S, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << FileName << endl;





}

vector <sClientInfo> WithDrawFromRecord(sClientInfo Client) {
	vector <sClientInfo> vClient = LoadDataClientFromFile(FileName);
	char DoWithdRow = 'N';
	double Withdraw = 0;
	cout << "\nenter Withdraw amount\n";
	cin >> Withdraw;

	cout << "\nAre you sure you Want to perfrom this transactin  (" << Client.AccountNumber << ") Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> DoWithdRow;
	if (toupper(DoWithdRow) == 'Y')
	{



		for (int i = 0; i < vClient.size();) {
			if (vClient[i].AccountNumber == Client.AccountNumber) {
				while (vClient[i].AccountBalance < Withdraw) {
					cout << "Amount Exceeds the balance, you can withdraw up to : " << vClient[i].AccountBalance << "\n";
					cout << "Enter another amount\n";
					cin >> Withdraw;
				}
				vClient[i].AccountBalance = (vClient[i].AccountBalance) - Withdraw;
				cout << "The withdrawal has been successfully completed.\n";
				cout << "Your new Balance is : " << vClient[i].AccountBalance << " " << endl;

				return vClient;

			}
			i++;

		}
		return vClient;
	}
	return vClient;
}
void WithdrawClientFromFile(vector <sClientInfo> Info, string FileName) {
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (sClientInfo& S : Info) {
			In = ConvertRecordToLine(S, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << FileName << endl;





}
void ShowDepositMinue() {
	cout << "------------------------------------------\n";
	cout << "\t  Deposit Screan\n";
	cout << "------------------------------------------\n";
	vector <sClientInfo> R1 = LoadDataClientFromFile("NewFile.txt");
	string AccountNumber = ReadAccountNumber();
	sClientInfo Client;
	if (FindClientDataFromAccountNumber(AccountNumber, Client)) {

		PrintClientCard(Client);
		R1 = DepositFromRecord(Client);
		DepositClientFromFile(R1, "NewFile.txt");

	}
	else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";



}
void ShowWithDrawMinue() {
	cout << "------------------------------------------\n";
	cout << "\t  Deposit Screan\n";
	cout << "------------------------------------------\n";
	vector <sClientInfo> R1 = LoadDataClientFromFile("NewFile.txt");
	string AccountNumber = ReadAccountNumber();
	sClientInfo Client;
	if (FindClientDataFromAccountNumber(AccountNumber, Client)) {

		PrintClientCard(Client);
		R1 = WithDrawFromRecord(Client);
		WithdrawClientFromFile(R1, "NewFile.txt");

	}
	else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";



}
void PrintAllClientsDataBalance(vector<sClientInfo> vClients) {
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << " Client(s)).";
	cout << "\n__________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number"
		<< "| " << setw(40) << "Client Name"

		<< "| " << setw(12) << "Balance" << endl;
	cout << "__________________________________________________________________________________________\n";

	for (sClientInfo& Client : vClients) {
		PrintClientRecordBalance(Client);
		cout << endl;
	}

	cout << "__________________________________________________________________________________________\n";

}
void PrintTotalBalance() {
	vector < sClientInfo> Data = LoadDataClientFromFile(FileName);
	double TotalBalance = 0;
	for (int i = 0; i < Data.size(); i++) {
		TotalBalance += Data[i].AccountBalance;
	}

	cout << "Total Balnce is :" << TotalBalance << endl;

}
void ShowwClientsDataBalance() {
	vector <sClientInfo> R1 = LoadDataClientFromFile("NewFile.txt");
	PrintAllClientsDataBalance(R1);


	cout << "\t"; PrintTotalBalance();
}
void ShowTransactionMenu() {
	cout << "============================================================\n";
	cout << "\t\t  " << "Transaction menue\n";
	cout << "============================================================\n";
	cout << "[1] Deposit.\n";
	cout << "[2] Withdraw.\n";
	cout << "[3] Total Balances.\n";
	cout << "[4] Main Menue.\n";
	cout << "========================================\n";
	cout << "Choose what do you want to do ? [1 to 4] ?";

}
void  Enterrr();

void ShowMainMenueScrean();
void Transaction() {
	bool t = true;
	int num = 0;
	ShowTransactionMenu();
	while (t) {
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			ShowDepositMinue();
			system("pause");
			system("cls");
			ShowTransactionMenu();
			break;


		case 2:

			system("cls");
			ShowWithDrawMinue();
			system("pause");

			system("cls");
			ShowTransactionMenu();
			break;
		case 3:
			system("cls");
			ShowwClientsDataBalance();
			system("pause");
			system("cls");
			ShowTransactionMenu();
			break;
		case 4:
			system("cls");

			ShowMainMenueScrean();

			Enterrr();

			break;


		default:
			system("cls");
			cout << "Invalid option.\n";
			t = 0;
			break;

		}
	}
}

struct stUserInfo {
	string UserName;
	string Password;
	int Permissions;


};
void PrintUserCard(stUserInfo User)
{
	cout << "\nThe following are the User details:\n";
	cout << "\nUserName: " << User.UserName;
	cout << "\nPassword : " << User.Password;
	cout << "\nPermissions : " << User.Permissions;
	cout << endl;
}

stUserInfo ReadUseerInfo(){
	stUserInfo Userinfo;
	cout << "Please enter UserName?\n";
	cin >> Userinfo.UserName;
	cout << "Please enter your password\n";
	cin >> Userinfo.Password;
	char C = 'n';
	cout << "Do you need to give full access? Y/N ";
	Userinfo.Permissions = 0;
	cin >> C;
	if (toupper(C) == 'Y')
		Userinfo.Permissions = -1;
	else {
		cout << "\nDo you want to give access to :\n";

		cout << "Show client list ?Y/N? ";
		cin >> C;

		if (toupper(C) == 'Y')
			Userinfo.Permissions = 1;
		cout << "\nAdd New Cliet Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 2;

		cout << "\nDelete Client Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 4;
		cout << "\nUpdate Client Info ? Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 8;
		cout << "\nFind Client.?Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 16;
		cout << "\nTransaction?Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 32;
		cout << "\nMange Users?Y/N?";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 64;

		if (Userinfo.Permissions == 127)
			Userinfo.Permissions = -1;

			

	}
	return Userinfo;

}
stUserInfo ReadUseerInfo(string UserName) {

	
	stUserInfo Userinfo;
	Userinfo.UserName = UserName;
	cout << "Please enter your password\n";
	cin >> Userinfo.Password;
	char C = 'n';
	cout << "Do you need to give full access? Y/N ";
	Userinfo.Permissions = 0;
	cin >> C;
	if (toupper(C) == 'Y')
		Userinfo.Permissions = -1;
	else {
		cout << "\nDo you want to give access to :\n";

		cout << "Show client list ?Y/N? ";
		cin >> C;

		if (toupper(C) == 'Y')
			Userinfo.Permissions = 1;
		cout << "\nAdd New Cliet Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 2;

		cout << "\nDelete Client Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 4;
		cout << "\nUpdate Client Info ? Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 8;
		cout << "\nFind Client.?Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 16;
		cout << "\nTransaction?Y/N? ";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 32;
		cout << "\nMange Users?Y/N?";
		cin >> C;
		if (toupper(C) == 'Y')
			Userinfo.Permissions += 64;

		if (Userinfo.Permissions == 127)
			Userinfo.Permissions = -1;


	}
	return Userinfo;

}
stUserInfo ReadUseerInfo(string UserName ,bool A) {


	stUserInfo Userinfo;
	Userinfo.UserName = UserName;
	cout << "Please enter your password\n";
	cin >> Userinfo.Password;
	char C = 'n';

	Userinfo.Permissions = -1;

	return Userinfo;

}
vector <stUserInfo> LoadDataUsersFromFile(string UserFileNaame);
bool IsUserNameEntered(string UserName, string UserFileNaame) {
	vector <stUserInfo>Vf = LoadDataUsersFromFile(UserFileNaame);
	for (int i = 0; i < Vf.size(); i++) {

		if (UserName == Vf[i].UserName) {
			
			return 1;
		}

	}
	return false;
}

string ConvertUserInfoToLine(stUserInfo U, string sip="+++") {
	string Users="";
	
		Users = U.UserName + sip + U.Password + (string)sip + (to_string (U.Permissions));


	return Users;
}

stUserInfo ConvertLineUsersToRecord(string Line, string sep) {
	vector <string> U = SplitString(Line, sep);
	stUserInfo Users;

	if (U.size() >= 3) {
		Users.UserName = U[0];
		Users.Password = U[1];
		Users.Permissions = stoi(U[2]);
	}
	else {
	
		cerr << "Error: Invalid line format. Expected 3 fields.\n";
		Users.UserName = "";
		Users.Password = "";
		Users.Permissions = 0;
	}
	return Users;
}
void AddUserToFile(string info, string UserFileNaame) {

	fstream MyFile;
	MyFile.open(UserFileNaame, ios::app |ios::out);
	if (MyFile.is_open()) {
		MyFile << info << endl;




		MyFile.close();
	}
	else  cout << "⚠️ Error: Could not open file " << UserFileNaame << endl;



}
vector <stUserInfo> LoadDataUsersFromFile(string UserFileNaame) {
	vector <stUserInfo> VUsersInfo;

	fstream MyFile;
	MyFile.open(UserFileNaame, ios::in);
	if (MyFile.is_open()) {
		string Line;
		stUserInfo NeU;
		while (getline(MyFile, Line)) {
			NeU = ConvertLineUsersToRecord(Line, "+++");
			VUsersInfo.push_back(NeU);


		}
		MyFile.close();


	}
	else {
		cout << "File Did not open\n";
		exit(0);

	}
	return VUsersInfo;
}
void PrintUserRecord(stUserInfo User) {
	cout << "| " << setw(15) << User.UserName;
	cout << "| " << setw(10) << User.Password;
	cout << "| " << setw(40) << User.Permissions;
	
}

void PrintAllUsersData(vector<stUserInfo>  UserIn) {
	cout << "\n\t\t\t\t\tClient List (" << UserIn.size() << " Client(s)).";
	cout << "\n__________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "UserName"
		<< "| " << setw(10) << "Password"
		<< "| " << setw(40) << "Permiissions" << endl;
	cout << "__________________________________________________________________________________________\n";

	for (stUserInfo Users:UserIn ) {
		PrintUserRecord(Users);
		cout << endl;
	}

	cout << "__________________________________________________________________________________________\n";

}
/*
void AddUser( string FileName) {

	stUserInfo Users;
	 vector <stUserInfo> VUsers;
	 
	
	 char C='y';
	
	 while (toupper(C)=='Y')
	 {
		// Users = ReadUseerInfo();
		 cout << "Please enter username\n";
		 cin >> Users.UserName;
		
		 string UserName;
		
		 while (IsUserNameEntered(Users.UserName,UserFileNaame)) {
			  UserName;
			 cout << " \nUser already exists Enter a new username\n ";
			 cin >> UserName;
			 Users.UserName = UserName;
		 }
		 Users = ReadUseerInfo(UserName);


		 VUsers.push_back(Users);
		 string info = ConvertUserInfoToLine(Users, "+++");
		 AddUserToFile(info, UserFileNaame);

		 cout << "User Added Successfully, Do you want to add more Users yes :: y or Y no :: N or n\n";
		 cin >> C;
		 cin.ignore();

	 }
	


}
*/    




/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// </summary>
/// <param name="FileName"></param>
void AddUser(string UserFileName) {
    stUserInfo Users;
    vector<stUserInfo> VUsers;
    char C = 'y';

    while (toupper(C) == 'Y') {
        cout << "Please enter username: ";
        cin >> Users.UserName;

        
        while (IsUserNameEntered(Users.UserName, UserFileNaame)) {
            cout << "\nUser already exists! Enter a new username: ";
            cin >> Users.UserName; 
        }

        Users = ReadUseerInfo(Users.UserName);

        VUsers.push_back(Users);
        string info = ConvertUserInfoToLine(Users, "+++");
        AddUserToFile(info, UserFileNaame);

        cout << "User Added Successfully! Do you want to add more users? (y/n): ";
        cin >> C;
        cin.ignore();
    }
}


vector <stUserInfo> DeleteUserFromRecord(stUserInfo User) {
	vector <stUserInfo> Vuser = LoadDataUsersFromFile(UserFileNaame);
	char DeleteUser = 'N';
	cout << "\nAre you sure you Want to delete this user (" << User.UserName << ") Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> DeleteUser;
	if (toupper(DeleteUser) == 'Y')
	{



		for (int i = 0; i < Vuser.size();) {
			if (Vuser[i].UserName == User.UserName) {

				Vuser.erase(Vuser.begin() + i);

				return Vuser;
				cout << "User Deleted Successfully\n";
			}
			i++;

		}
		return Vuser;
	}
	return Vuser;
}

void DeleteUserFromFile(vector <stUserInfo>  UserInfo, string UserFileNaame) {
	fstream MyFile;
	MyFile.open(UserFileNaame, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (stUserInfo& Suser : UserInfo) {
			In = ConvertUserInfoToLine(Suser, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << UserFileNaame << endl;





}

string ReadUserName() {
	string userName;
	cout << "Please enter UserNaame\n";
	cin >> userName;
	return userName;


}

bool FindUserDataFromUserName(string UserName, stUserInfo& Info) {
	vector <stUserInfo> SS = LoadDataUsersFromFile(UserFileNaame);
	for (stUserInfo& R : SS) {
		if (R.UserName == UserName) {
			Info = R;
			return 1;

		}

	}

	return false;

}





vector <stUserInfo> UpdateUserInfoFromRecord(stUserInfo User) {
	char UpdateUser = 'N';
	cout << "\nAre you sure you Want to Update the User (" << User.UserName << ") info Y: 'Y'OR 'y'||NO :'N' or'n' ?";
	cin >> UpdateUser;
	vector <stUserInfo> vUser = LoadDataUsersFromFile(UserFileNaame);
	if (toupper(UpdateUser) == 'Y')
	{
		


		for (int i = 0; i < vUser.size(); i++) {
			if (vUser[i].UserName == User.UserName) {
				// الآن نتحقق إذا Admin أو لا
				if (vUser[i].UserName == "Admin") {
					cout << "⚠️ You can't change permissions for 'Admin'.\n";
					vUser[i] = ReadUseerInfo(vUser[i].UserName, true);
				}
				else {
					vUser[i] = ReadUseerInfo(vUser[i].UserName);
				}
				cout << "✅ User updated successfully\n";
				DeleteUserFromFile(vUser, UserFileNaame); // لا تنسى حفظ التعديلات
				return vUser;
			}
		}
	}
	return vUser;


}
void UpdateUserFromFile(vector <stUserInfo> Info, string UserFileNaame) {
	fstream MyFile;
	MyFile.open(UserFileNaame, ios::out);
	string In;
	if (MyFile.is_open()) {
		for (stUserInfo& S : Info) {
			In = ConvertUserInfoToLine(S, "+++");
			MyFile << In << endl;


		}

		MyFile.close();

	}
	else cout << "⚠️ Error: Could not open file " << UserFileNaame << endl;





}


void ShowAddUser() {
	cout << "------------------------------------------\n";
	cout << "\t  Add New User Screan\n";
	cout << "------------------------------------------\n";
	AddUser(UserFileNaame);


}
void ShowUsersData() {
	vector <stUserInfo> R1 = LoadDataUsersFromFile(UserFileNaame);
	PrintAllUsersData(R1);



}
bool CheckIfUserIsAdminOrNot(stUserInfo User) {
	if (User.UserName =="Admin")
		return 1;
	else
		return 0;




}
void ShowDeleteUser() {
	cout << "------------------------------------------\n";
	cout << "\t  Delete User Screan\n";
	cout << "------------------------------------------\n";
	vector <stUserInfo> R1 = LoadDataUsersFromFile(UserFileNaame);
	string UserName = ReadUserName();
	stUserInfo User;
	if (FindUserDataFromUserName(UserName, User)) {
		if (CheckIfUserIsAdminOrNot(User)) {


			cout << "Cant deleted admin user\n";
			
			return;
		}
		PrintUserCard(User);
		R1 = DeleteUserFromRecord(User);
		DeleteUserFromFile(R1, UserFileNaame);
		cout << "User deleted successfully\n";

	}
	else cout << "\nUser with username (" << UserName << ") is Not Found!";



}
void ShowUpdateUser() {
	cout << "------------------------------------------\n";
	cout << "\t  Update User Screan\n";
	cout << "------------------------------------------\n";
	vector <stUserInfo> R1 = LoadDataUsersFromFile(UserFileNaame);
	string UserName = ReadUserName();
	stUserInfo User;
	if (FindUserDataFromUserName(UserName, User)) {

		PrintUserCard(User);
		R1 = UpdateUserInfoFromRecord(User);
		UpdateUserFromFile(R1, UserFileNaame);

	}
	else cout << "\nUser with UserName (" << UserName << ") is Not Found!\n";



}
void ShowFindUser() {
	cout << "------------------------------------------\n";
	cout << "\t  Find User Screan\n";
	cout << "------------------------------------------\n";
	string UserName = ReadUserName();
	stUserInfo User;
	if (FindUserDataFromUserName(UserName, User)) {
		PrintUserCard(User);


	}
	else cout << "\nUser with UserName (" << UserName << ") is Not Found!\n";




}

void  ShowUserMenu() {
	cout << "======================================" << endl;
	cout << "        Manage Users Menu Screen      " << endl;
	cout << "======================================" << endl;
	cout << "[1] List Users." << endl;
	cout << "[2] Add New User." << endl;
	cout << "[3] Delete User." << endl;
	cout << "[4] Update User." << endl;
	cout << "[5] Find User." << endl;
	cout << "[6] Main Menue." << endl;
	cout << "======================================" << endl;
	cout << "Choose what do you want to do? [1 to 6]? ";







}
bool CheckUserPassword(stUserInfo Us) {
	vector <stUserInfo> User = LoadDataUsersFromFile(UserFileNaame);
	for (stUserInfo R : User) {
		if (Us.UserName == R.UserName) {
			if (Us.Password==R.Password)
			{
				return true;
			}


		}


	}
	return false;

}
void GiveTheUserTheirPermissions(stUserInfo &Uss) {
	vector <stUserInfo> User = LoadDataUsersFromFile(UserFileNaame);
	for (stUserInfo& I : User) {
		if (I.UserName == Uss.UserName) {
			Uss.Permissions = I.Permissions;


		}


	}



}
string EnterUserName() {

	

	cout << "Please enter your username: ";
	string user;
	getline(cin >>ws, user);
	return user;

}
string EnterUserName(bool V) {


	
	cout << "UserName didnt found, Please enter your username: ";
	string user;
	getline(cin>>ws, user);
	return user;

}
bool LogIn(stUserInfo& LogInUser) {
	
	
	LogInUser.UserName=EnterUserName();
	
	while (!(IsUserNameEntered(LogInUser.UserName, UserFileNaame))) {
	//	cout << "UserName didnt find ";
		LogInUser.UserName = EnterUserName(0);
	}
	cout << "Enter your Password\n";
	
	getline(cin, LogInUser.Password);
	while (!CheckUserPassword(LogInUser)) {

		cout << "Invalid Password plese enter the correct password\n";
		getline(cin, LogInUser.Password);
	}

	GiveTheUserTheirPermissions(LogInUser);
	return true;
}
stUserInfo UserP;
void Enterrr();
void ShowLogInScreen() {
	cout << "------------------------------\n";
	cout << "         Login Screen         \n";
	cout << "------------------------------\n";
	
	if (LogIn(UserP)) {//////// out of range here
		ShowMainMenueScrean();
		Enterrr();
	}
	
}
void ShowMainMenueScrean();
void User() {
	short num=0;
	ShowUserMenu();
	bool A = 1;
	while (A) {
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			ShowUsersData();
			system("pause");
			system("cls");
			ShowUserMenu();
			break;


		case 2:

			system("cls");
			ShowAddUser();
			system("pause");

			system("cls");
			ShowUserMenu();
			break;
		case 3:
			system("cls");
			ShowDeleteUser();
			system("pause");
			system("cls");
			ShowUserMenu();
			break;
		case 4:
			system("cls");
			ShowUpdateUser();
			system("pause");
			system("cls");
			ShowUserMenu();

			break;
		case 5:
			system("cls");
			ShowFindUser();
			system("pause");
			system("cls");
			ShowUserMenu();
			break;
		case 6 :
			system("cls");
			ShowMainMenueScrean();
			Enterrr();
		default:
			system("cls");
			cout << "Invalid option.\n";
			A = 0;
			break;

		}
	}



	}








enum enMainMenue { ShowClientsData = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Exist = 6 };


void ShowMainMenueScrean() {
	system("cls");
	cout << "============================================================\n";
	cout << "\t\t  " << "Main Menue Screan\n";
	cout << "============================================================\n\n";
	cout << "[1] Show Client List.\n";
	cout << "[2] Add New Client.\n";
	cout << "[3] Delete Client.\n";
	cout << "[4] Update Client Info.\n";
	cout << "[5] Find Client.\n";
	cout << "[6] Transaction\n";
	cout << "[7] Mange Users.\n";
	cout << "[8]LogOut\n";
	cout << "============================================================\n";
	cout << "Choose what do you want to do?[1 to 7]?";


}
void ShowEndScrean() {
	cout << "------------------------------------------\n";
	cout << "\t  Program Ends\n";
	cout << "------------------------------------------\n";

}
void AccessDeniedMessage() {
	cout << "-----------------------------------\n";
	cout << " Access Denied,\n";
	cout << " You don't Have Permission To Do this,\n";
	cout << " Please Contact Your Admin.\n";
	cout << "-----------------------------------\n";
	system("pause");
	ShowMainMenueScrean();
}

void Enterrr() {
	bool t = true;
	int num = 0;
	while (t) {
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			if ((UserP.Permissions & 1) == 1) {
				ShowwClientsData();
				system("pause");
				system("cls");
				ShowMainMenueScrean();
			}
			else AccessDeniedMessage();
			break;


		case 2:
			if ((UserP.Permissions & 2) == 2) {
				system("cls");
				ShowAddClient();
				system("pause");
				ShowMainMenueScrean();
			}
			else AccessDeniedMessage();
			break;
		case 3:
			if ((UserP.Permissions & 4) == 4) {
				system("cls");
				ShowDeleteClient();
				system("pause");
				ShowMainMenueScrean();
			}
			else AccessDeniedMessage();
			break;
		case 4:
			if ((UserP.Permissions & 8) == 8) {
				system("cls");
				ShowUpdateClient();
				system("pause");
				ShowMainMenueScrean();
			}
			else AccessDeniedMessage();

			break;
		case 5:
			if ((UserP.Permissions & 16)==16) {
				system("cls");
				ShowFindClient();
				system("pause");

				ShowMainMenueScrean();
			}
			else AccessDeniedMessage();

			break;
		case 6:
			if ((UserP.Permissions & 32) == 32) {
				system("cls");
				Transaction();
			}
			else
AccessDeniedMessage();

			break;
		case 7:
			if ((UserP.Permissions & 64) == 64) {
				system("cls");
				User();
			}
			AccessDeniedMessage();
			break;
		case 8:
			system("cls");
			ShowLogInScreen();
			break;
		default:
			cout << "Invalid option.\n";
			t = 0;
			break;

		}
	}
}


int main()
{
	srand(time(0));
	//Step 1: Run the code once with the following lines uncommented.
		// These lines will create the required files if they do not exist 
		// and add the "Admin" user if it is not already present.

	/*
	CreateFileIfNotExist(FileName);
	CreateFileIfNotExist(UserFileNaame);

		stUserInfo AdminUser;
		AdminUser.UserName = "admin";
		AdminUser.Password = "1111";
		AdminUser.Permissions = -1; 
		string info = ConvertUserInfoToLine(AdminUser, "+++");
		AddUserToFile(info, UserFileNaame);
		cout << "Admin user created successfully.\n";*/
		// Step 2: After running the code once, comment out the lines above 
		// to prevent unnecessary file creation or duplicate user entries.

		// Step 3: Uncomment the following line to proceed with normal execution of the program.

	
	//ShowLogInScreen();
	











	return 0;




}

