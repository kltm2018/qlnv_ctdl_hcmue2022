#pragma once
#include"HuyInput.h"
#include <locale>
#include <codecvt>
#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()

template <class T>
bool isEmpty(int n, T a) {
	return (n == 0);
}

template <class T>
void loadFile(int n, T* array, string fileText) {
	ofstream fi(fileText, ios::out);
	for (int i = 0; i < n; i++) {
		array[i].ghiFile(fi);
	}
	fi.close();
}

template <class T>
void getDS(int& n, T* array, string fileText) {
	ifstream fi(fileText);
	while (!fi.eof()) {
		array[n].docFile(n, fi);
	}
	fi.close();
}

void exit() {
	char x = _getch();
	while (x != 27) {
		if (x != -32) {
			SetColor(0, 12);
			HuyInput::WriteString(L"Nhấn ESC để quay lại!"); cout << endl;
		}
		x = _getch();
	}
}


// 1 - Main menu
// 2 - Admin menu
// 3 - Update menu
// 4 - Employee menu

void titleSelection(int choice, int k, int t)
{
	wstring message;
	switch (t)
	{
	case 1:
	{
		switch (choice)
		{
		case 1: message = L"             Quản trị viên           ";
			break;
		case 2: message = L"              Nhân viên              ";
			break;
		default:
			message = L"                Thoát                ";
			break;
		}
		break;
	}
	case 2:
	{
		switch (choice)
		{
		case 1: message = L"              Thêm Employee             ";
			break;
		case 2: message = L"               Xoá Employee             ";
			break;
		case 3: message = L"               Tìm Employee             ";
			break;
		case 4: message = L"            Cập nhật Employee           ";
			break;
		case 5: message = L"       Hiển thị thông tin Employee      ";
			break;
		default:
			message = L"                  Thoát                 ";
			break;
		}
		break;
	}
	case 3:
	{
		switch (choice)
		{
		case 1: message = L"           Cập nhật họ tên         ";
			break;
		case 2: message = L"           Cập nhật địa chỉ        ";
			break;
		case 3: message = L"        Cập nhật số điện thoại     ";
			break;
		case 4: message = L"            Cập nhật email         ";
			break;
		default:
			message = L"               Thoát               ";
			break;
		}
		break;
	}
	default:
		switch (choice)
		{
		case 1: message = L"    Xem thông tin tài khoản   ";
			break;
		case 2: message = L"          Đổi password        ";
			break;
		default:
			message = L"            Thoát             ";
			break;
		}
		break;
	}
	cout << setw(44) << "*";
	if (choice == k) {
		SetColor(9, 0);
	}
	cout << setw(1); HuyInput::WriteString(message);
	SetColor(0, 11);
	cout << "*" << endl;
}

void showMainMenu(int k) {
	system("cls");
	cout << "\n\n\n\n\n";
	SetColor(0, 14);
	cout << setw(83) << right << "***************************************\n";
	cout << setw(44) << right << "*"; SetColor(0, 15); cout << setw(0) << right;
	HuyInput::WriteString(L"            QUẢN LÝ NHÂN SỰ          ");

	SetColor(0, 14); cout << setw(0) << right << "*\n";
	cout << setw(84) << right << "***************************************\n\n";
	SetColor(0, 11);
	cout << setw(43) << "" << setfill('*') << setw(39) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 3; i++) {
		titleSelection(i, k, 1);
	}

	cout << setw(43) << "" << setfill('*') << setw(39) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

//Admin Funtions

//Login

void showAdminLogin(string& _userName, string& _passWord, wstring message) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(70);
	wcout << message;
	HuyInput::WriteString(message);  cout << endl;
	SetColor(0, 10);
	cout << setw(75) << right << "******************************\n";
	cout << setw(45) << right << "*"; SetColor(0, 15); cout << setw(60) << right;
	HuyInput::WriteString(L"      ĐĂNG NHẬP ADMIN     "); SetColor(0, 10); cout << setw(4) << right << "*\n";
	cout << setw(76) << right << "******************************\n\n";

	SetColor(0, 3);
	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}

void showMenuAdmin(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 10);
	cout << setw(82) << right << "**********************************\n";
	cout << setw(48) << right << "*"; SetColor(0, 15); cout << setw(0) << right;
	HuyInput::WriteString(L"          MENU QUẢN LÝ          "); SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(83) << right << "**********************************\n\n";
	SetColor(0, 11);
	cout << setw(44) << "" << setfill('*') << setw(40) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 6; i++) {
		titleSelection(i, k, 2);
	}

	cout << setw(44) << "" << setfill('*') << setw(40) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

bool checkAccountAdmin(string userName, string passWord, int nAD, Admin* admin) {
	for (int i = 0; i < nAD; i++) {
		if (admin[i].getUserName() == userName && admin[i].getPassWord() == passWord) {
			return true;
			break;
		}
	}
	return false;
}

// Add Employee Function

bool checkUserNameEmployee(User* user, string _User)
{
	ifstream fileIn("Employees.txt", ios::app);
	while (!fileIn.eof())
	{
		user = new Employee();
		user->readFile(fileIn);
		if (_User == user->getUserName())
			return false;
	}
	fileIn.close();
	return true;
}

void addEmployee(User* user)
{
	string _User, _Pass;
	user = new Employee();
	system("cls");
	SetColor(0, 10);
	cout << setw(75) << right << "**********************************\n";
	cout << setw(41) << right << "*"; SetColor(0, 15); cout << setw(0) << right;
	HuyInput::WriteString(L"  NHẬP THÔNG TIN CỦA NHÂN VIÊN  "); SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(76) << right << "**********************************\n\n";
	SetColor(0, 11);
	HuyInput::WriteString(L" Nhập Username muốn thêm: ");
	cin >> _User;
	if (!checkUserNameEmployee(user, _User))
	{
		SetColor(0, 14);
		HuyInput::WriteString(L" Username đã tồn tại !"); cout << "\n";
	}
	else
	{
		char* FilePath = new char[_User.length() + 1];//tạo một chuỗi kí tự mới
		strcpy(FilePath, _User.c_str());//coppy từ chuỗi nguồn sang chuỗi mới

		ofstream fileOut("Employees.txt", ios::app);
		Employee* Emp = new Employee();// new class employees		
		fileOut << _User << ", " << "111111" << endl;//xuất tên và pass trong file txt
		fileOut.close();
		Emp->createFile(fileOut, FilePath);//gọi tạo file
		Emp->input();//nhập thông tin
		fileOut << Emp->getName() << endl << Emp->getAddress() << endl << Emp->getPhone() << endl << Emp->getEmail();
		fileOut.close();
		SetColor(0, 14);
		HuyInput::WriteString(L" Thêm thành công !");
		cout << endl;
	}
}

// Show Employees 

void showEmployees(User* user)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	string strUser[100];
	int n = 0;
	system("cls");
	SetColor(0, 11);
	cout << setw(33) << "" << setfill('*') << setw(35) << "*" << setfill(' ') << endl;
	cout << setw(68) << "*                                 *" << endl;

	cout << setw(33) << right << " ";
	HuyInput::WriteString(L"*       DANH SÁCH NHÂN VIÊN       *"); cout << endl;

	cout << setw(68) << "*                                 *" << endl;
	cout << setw(33) << "" << setfill('*') << setw(35) << "*" << setfill(' ') << endl << endl;
	while (!fileIn.eof())
	{
		user->readFile(fileIn);
		strUser[n] = user->getUserName();
		n++;
	}
	fileIn.close();
	for (int i = 0; i < n; i++) {
		SetColor(0, 9);
		HuyInput::WriteString(L"  Thông tin:\t ");
		SetColor(0, 15);
		cout << strUser[i] << endl;
		string s = strUser[i];
		char* fileName = new char[s.length() + 1];
		strcpy(fileName, s.c_str());
		user->openFile(fileIn, fileName);
		user->readInfomation(fileIn);
		SetColor(0, 11);
		cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
		SetColor(0, 13);
		cout << setw(30) << left; HuyInput::WriteString(L" Họ và tên\t\t");
		cout << setw(17) << left; HuyInput::WriteString(L"Địa chỉ\t\t\t\t\t\t ");
		cout << setw(18) << left; HuyInput::WriteString(L"SĐT\t\t\t\t");
		cout << setw(18) << left << "Email" << endl;
		SetColor(0, 11);
		cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
		SetColor(0, 15);
		cout << " " << setw(22) << left << user->getName();
		cout << setw(50) << left << user->getAddress();
		cout << setw(20) << left << user->getPhone();
		cout << setw(15) << left << user->getEmail() << endl;
		SetColor(0, 11);
		cout << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
		fileIn.close();
	}
}


//delete a specific line
void del_line(const char* file_name, int n)
{
	ifstream fin(file_name);
	ofstream fout;
	fout.open("temp.txt", ios::out);

	char ch;
	int line = 1;
	while (fin.get(ch))
	{
		if (ch == '\n')
			line++;

		if (line != n)      // content not to be deleted 
			fout << ch;
	}
	fout.close();
	fin.close();
	remove(file_name);
	rename("temp.txt", file_name);
}


// Delete Employee 
void deleteEmployee(User* user, string s) {
	ifstream fileIn;
	fileIn.open("Employees.txt", ios_base::app);// mở file
	ofstream fileOut;
	fileOut.open("EmployeesCopy.txt", ios_base::out);
	int count = 1;
	while (!fileIn.eof())//đọc file
	{
		user = new Employee();
		user->readFile(fileIn);
		if (user->getUserName() == s) //Nếu tìm thấy username cần xoá thì dừng lại, xác định số dòng chứa username đó qua biến count
		{
			break;
		}
		count++;
	}
	fileIn.close();
	fileOut.close();
	del_line("Employees.txt", count); //Xoá dòng thứ count chứa username cần xoá
	//system("del Employees.txt");
	//char* c = (char*)"Employees";
	//user->createFile(fileOut, c);
	//fileOut.close();
	//fileIn.open("EmployeesCopy.txt", ios_base::in);
	//fileOut.open("Employees.txt", ios_base::app);
	//while (count > 1) {
	//	user = new Employee();
	//	user->readFile(fileIn);
	//	if (count == 2)
	//	{
	//		fileOut << user->getUserName() << "," << user->getPassWord();
	//		break;
	//	}
	//	fileOut << user->getUserName() << "," << user->getPassWord() << endl;
	//	count--;
	//}
	//fileIn.close();
	//fileOut.close();
	user->deleteFile(s);//xóa employees
	SetColor(0, 14);
	HuyInput::WriteString(L" Xoá thành công!"); cout << endl;
	system("del EmployeesCopy.txt");

}

// Find Employee
void findEmployee(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	if (!checkUserNameEmployee(user, userName))
	{
		ifstream f;
		char* fileName = new char[userName.length() + 1];
		strcpy(fileName, userName.c_str());
		user->openFile(f, fileName);
		user->readInfomation(f);//đọc file

		HuyInput::WriteString(L"\tTHÔNG TIN EMPLOYEE CẦN TÌM"); cout << endl << endl;
		HuyInput::WriteString(L" Họ tên:\t"); cout << user->getName() << endl;
		HuyInput::WriteString(L" Địa chỉ:\t"); cout << user->getAddress() << endl;
		HuyInput::WriteString(L" Số điện thoại:\t"); cout << user->getPhone() << endl;
		HuyInput::WriteString(L" Email:\t\t"); cout << user->getEmail();
		f.close();
	}
	else {
		SetColor(0, 14);
		HuyInput::WriteString(L"Username không tồn tại!"); cout << endl;
	}
	fileIn.close();
}

// Update Employee

void menuUpdate(int k)
{
	system("cls");
	cout << "\n\n";
	SetColor(0, 10);
	cout << setw(79) << right << "*********************************\n";
	cout << setw(46) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "          MENU UPDATE          "; SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(80) << right << "*********************************\n\n";
	SetColor(0, 11);
	cout << setw(43) << "" << setfill('*') << setw(37) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 5; i++) {
		titleSelection(i, k, 3);
	}

	cout << setw(43) << "" << setfill('*') << setw(37) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}



void updateName(User* user, string strUser)
{
	//_setmode(_fileno(stdout), _O_WTEXT); //needed for output
	//_setmode(_fileno(stdin), _O_WTEXT); //needed for input
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	HuyInput::WriteString(L" Nhập họ tên cần thay đổi: ");
	cin.ignore();
	//HuyInput::ReadString(edit);
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("NoName.txt", ios_base::out);
	fileOut << edit << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	HuyInput::WriteString(L" Cập nhật họ tên Employee thành công!"); cout << endl;
	user->deleteFile("NoName");
	exit();
}

void updateAddress(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	HuyInput::WriteString(L" Nhập địa chỉ cần thay đổi: ");
	//cin.ignore();
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << edit << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	HuyInput::WriteString(L" Cập nhật địa chỉ Employee thành công!"); cout << endl;
	user->deleteFile("NoName");
	exit();
}

void updatePhone(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	HuyInput::WriteString(L" Nhập số điện thoại cần thay đổi: ");
	cin.ignore();
	cin >> edit;
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << user->getAddress() << endl << edit << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	HuyInput::WriteString(L" Cập nhật số điện thoại Employee thành công!"); cout << endl;
	user->deleteFile("NoName");
	exit();
}

void updateEmail(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	HuyInput::WriteString(L" Nhập email cần thay đổi: ");
	cin.ignore();
	cin >> edit;
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << edit;
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	HuyInput::WriteString(L" Cập nhật email Employee thành công!"); cout << endl;
	user->deleteFile("NoName");
	exit();
}

// Employee Funtions
void showEmployeeLogin(string& _userName, string& _passWord, wstring message) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(63);
	wcout << message;
	HuyInput::WriteString(message);
	cout << endl;
	SetColor(0, 13);
	cout << setw(76) << right << "******************************\n";
	cout << setw(46) << right << "*"; SetColor(0, 15); cout << setw(0) << right; HuyInput::WriteString(L"     ĐĂNG NHẬP EMPLOYEE     "); SetColor(0, 13); cout << setw(0) << right << "*\n";
	cout << setw(77) << right << "******************************\n\n";

	SetColor(0, 3);
	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}

bool checkAccountEmployee(User* user, string userName, string passWord, string& saveUsername) {
	ifstream fileIn("Employees.txt", ios_base::app);
	while (!fileIn.eof())//đọc file
	{
		user->readFile(fileIn);
		if (user->getUserName() + user->getPassWord() == userName + " " + passWord) {
			saveUsername = userName;
			return true;
		}
	}
	fileIn.close();
	return false;
}

void showMenuEmployee(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 13);
	cout << setw(80) << right << "****************************************\n";
	cout << setw(40) << right << "*"; SetColor(0, 15); cout << setw(0) << right; HuyInput::WriteString(L"            MENU NHÂN VIÊN            "); SetColor(0, 13); cout << setw(0) << right << "*\n";
	cout << setw(81) << right << "****************************************\n\n";
	SetColor(0, 11);
	cout << setw(40) << "" << setfill('*') << setw(38) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 3; i++) {
		titleSelection(i, k, 4);
	}

	cout << setw(40) << "" << setfill('*') << setw(38) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

// Show Employee Information

void showEmployeeInfo(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	ifstream f;
	char* fileName = new char[userName.length() + 1];
	strcpy(fileName, userName.c_str());
	user->openFile(f, fileName);
	user->readInfomation(f);//đọc file
	HuyInput::WriteString(L"\tTHÔNG TIN EMPLOYEE "); cout << endl << endl;
	HuyInput::WriteString(L" Họ tên:\t"); cout << user->getName() << endl;
	HuyInput::WriteString(L" Địa chỉ:\t"); cout << user->getAddress() << endl;
	HuyInput::WriteString(L" Số điện thoại:\t"); cout << user->getPhone() << endl;
	HuyInput::WriteString(L" Email:\t\t"); cout << user->getEmail();
	f.close();
	fileIn.close();
}

// Change Password

void changePass(User* user, string currentPass, string newPass, string userName)
{
	ifstream fileIn;
	ofstream fileOut;
	string s = "NoName";
	char* fileName = new char[s.length() + 1];//tạo chuỗi mới
	strcpy(fileName, s.c_str());//copy chuỗi
	user->createFile(fileOut, fileName);
	fileIn.open("Employees.txt", ios_base::in);//mở file
	int count = 0;
	while (!fileIn.eof())
	{
		user->readFile(fileIn);
		count++;
	}
	fileIn.close();
	int tmp = count;
	fileIn.open("Employees.txt", ios_base::in);
	while (count > 0)
	{
		user->readFile(fileIn);
		if (count == 1)
		{
			fileOut << user->getUserName() << "," << user->getPassWord();
			break;
		}
		fileOut << user->getUserName() << "," << user->getPassWord() << endl;
		count--;
	}
	fileIn.close();
	fileOut.close();
	user->deleteFile("Employees");
	string s2 = "NoName";
	char* fileName2 = new char[s2.length() + 1];
	strcpy(fileName2, s2.c_str());
	user->openFile(fileIn, fileName2);
	fileOut.open("Employees.txt", ios_base::out);
	while (tmp > 0)
	{
		user->readFile(fileIn);
		if (userName == user->getUserName() && " " + currentPass == user->getPassWord() && tmp == 1)
		{
			fileOut << user->getUserName() << ", " << newPass;
			break;
		}
		else if (userName == user->getUserName() && " " + currentPass == user->getPassWord())
		{
			fileOut << user->getUserName() << ", " << newPass << endl;
		}
		else
		{
			if (tmp == 1)
			{
				fileOut << user->getUserName() << "," << user->getPassWord();
				break;
			}
			else if (tmp != 1)
			{
				fileOut << user->getUserName() << "," << user->getPassWord() << endl;
			}
			else
			{
				break;
			}
		}
		tmp--;
	}

	SetColor(0, 14);
	HuyInput::WriteString(L"\n Đổi mật khẩu thành công!\n");
	fileIn.close();
	fileOut.close();
	user->deleteFile("NoName");
}

void menuChangePass(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	ofstream fileOut;
	int size = 0;
	SetColor(0, 9);
	HuyInput::WriteString(L"\n             KHÔNG SỬ DỤNG PASSWORD MẶC ĐỊNH: 111111 "); cout << endl << endl;
	SetColor(0, 11);
	HuyInput::WriteString(L" Nhập password hiện tại: ");
	string currentPass;
	string passC = "\0";
	char kytuC = 0;
	int iC = 0;
	while (kytuC != '\r') {
		kytuC = _getch();
		if ((kytuC >= 'a' && kytuC <= 'z') || (kytuC >= 'A' && kytuC <= 'Z') || (kytuC >= '0' && kytuC <= '9')) {
			passC += kytuC;
			iC++;
			cout << "*";
		}
		if (kytuC == '\b' && iC >= 1) {
			cout << "\b \b";
			iC--;
		}
	}
	currentPass = passC;

	cout << endl; HuyInput::WriteString(L" Nhập password mới: ");
	string newPass;
	string passN = "\0";
	char kytuN = 0;
	int iN = 0;
	while (kytuN != '\r') {
		kytuN = _getch();
		if ((kytuN >= 'a' && kytuN <= 'z') || (kytuN >= 'A' && kytuN <= 'Z') || (kytuN >= '0' && kytuN <= '9')) {
			passN += kytuN;
			iN++;
			cout << "*";
		}
		if (kytuN == '\b' && iN >= 1) {
			cout << "\b \b";
			iN--;
		}
	}
	newPass = passN;

	cout << endl; HuyInput::WriteString(L" Nhập lại password mới: ");
	string confirmPass;
	string passP = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			passP += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	confirmPass = passP;
	cout << endl;
	bool check = false;
	bool checkN = false;
	bool checkP = false;

	while (!fileIn.eof())
	{
		user = new Employee();
		user->readFile(fileIn);
		//cout << user->getUserName();
		if (user->getUserName() == userName) {
			if (user->getPassWord() == " " + (string)currentPass)
			{
				check = true;
				break;
			}

		}
	}

	if ((string)newPass != "111111")
	{
		checkN = true;// break;
	}
	if ((string)newPass == (string)confirmPass)
	{
		checkP = true;
		//break;
	}
	bool checkChange = false, yes = false;

	if (check == false)
	{
		SetColor(0, 14);
		HuyInput::WriteString(L"\n Password bạn nhập không chính xác, bạn vui lòng kiểm tra lại!"); cout << endl;
	}
	else if (checkN == false)
	{
		SetColor(0, 14);
		HuyInput::WriteString(L"\n Password trùng với password mặc định, bạn vui lòng kiểm tra lại!"); cout << endl;
	}
	else if (checkP == false)
	{
		SetColor(0, 14);
		HuyInput::WriteString(L"\n Password xác nhận không chính xác, bạn vui lòng kiểm tra lại!"); cout << endl;
	}
	else
	{
		changePass(user, currentPass, newPass, userName);
		checkChange = true;
	}
	fileIn.close();
	if (checkChange) {
		int n = 0, m = 0;
		string line;
		ifstream file("Employees.txt");
		while (getline(file, line))
		{
			n++;
			if (line.substr(0, 2) == ", ") {
				yes = true; m = n;
			}
		}
		file.close();
		if (yes) {
			del_line("Employees.txt", m); //Xoá dòng cuối không có username mà dư pass
			ofstream savefile("Employees.txt", ios_base::app); //Thêm dòng trống vào dòng cuối cùng trong file, tránh lỗi khi chương trình đọc thông tin tài khoản
			savefile << "\n";
			savefile.close();
		}
		
	}
}

