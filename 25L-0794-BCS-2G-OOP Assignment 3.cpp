#include<iostream>
#include<string>
using namespace std;

class Name;
class Address;
class Project;
class Department;
class Employee;
class Company;

class Name
{
private:
	string f_name;
	string l_name;
public:
	Name()
	{
		f_name = "Unknown";
		l_name = "Unknown";
	}
	Name(string f, string l)
	{
		f_name = f;
		l_name = l;
	}
	void displayName()
	{
		cout << endl;
		cout << "Name: " << f_name << " " << l_name;
	}
};

class Address
{
private:
	int houseNo;
	char block;
	int streetNo;
	string city;
public:
	Address()
	{
		houseNo = 0;
		block = ' ';
		streetNo = 0;
		city = "Unknown";
	}
	Address(int HN, char B, int SN, string C)
	{
		houseNo = HN;
		block = B;
		streetNo = SN;
		city = C;
	}
	void displayAddress()
	{
		cout << endl;
		cout << "Address: " << houseNo << "-" << block << " " << "streetNo." << streetNo << ", " << city;
	}
};

class Project
{
private:
	int ID;
	string projectDescription;
	int employeesWorkingOn;
	Employee* employee[10];
public:
	Project()
	{
		ID = 0;
		projectDescription = "Unknown";
		employeesWorkingOn = 0;
		for (int i = 0; i < 10; i++)
		{
			employee[i] = 0;
		}
	}
	Project(int ID, string projectDescription)
	{
		this->ID = ID;
		this->projectDescription = projectDescription;
		employeesWorkingOn = 0;
		for (int i = 0; i < 10; i++)
		{
			employee[i] = 0;
		}
	}
	int getID()
	{
		return ID;
	}
	void displayProjectInfo()
	{
		cout << "\nProject Info: \n";
		cout << "ID: " << ID << "\n" << "Project Description: " << projectDescription << "\nEmployees Working On: " << employeesWorkingOn;
	}
	void IncEmployeesWorkingOn()
	{
		employeesWorkingOn++;
	}
	void DecEmployeeWorkingOn()
	{
		employeesWorkingOn--;
	}
	bool AddEmployee(Employee* emp)
	{
		if (employeesWorkingOn >= 10)
		{
			cout << "\nThe limit has exceeded";
			return false;
		}
		for (int i = 0; i < employeesWorkingOn; i++)
		{
			if (employee[i] == emp)
			{
				cout << "\nThe Employee already exists";
				return false;
			}
		}
		employee[employeesWorkingOn] = emp;
		IncEmployeesWorkingOn();
		return true;
	}
	bool  RemoveEmployee(Employee* emp)
	{
		for (int i = 0; i < employeesWorkingOn; i++)
		{
			if (employee[i] == emp)
			{
				for (int j = i; j < employeesWorkingOn - 1; j++)
				{
					employee[j] = employee[j + 1];
				}
				employee[employeesWorkingOn - 1] = NULL;
				DecEmployeeWorkingOn();
				return true;
			}
		}
		return false;
	}
	void DisplayAllEmployees();
};

class Department
{
private:
	int ID;
	string name;
	Employee* employee[50];
	int employeeCount;
public:
	Department()
	{
		ID = 0;
		name = "Unknown";
		for (int i = 0; i < 50; i++)
		{
			employee[i] = NULL;
		}
		employeeCount = 0;
	}
	Department(int ID, string name)
	{
		this->ID = ID;
		this->name = name;
		employeeCount = 0;
		for (int i = 0; i < 50; i++)
		{
			employee[i] = NULL;
		}
	}
	int getID()
	{
		return ID;
	}
	void displayDeptInfo()
	{
		cout << endl << "Department ID: " << ID << endl << "Department Name: " << name << endl << "Number of Employee in the Department: " << employeeCount;
	}
	bool AddEmployee(Employee* emp)
	{
		if (employeeCount >= 50)
		{
			cout << "\nLimit exceeded";
			return false;
		}
		for (int i = 0; i < employeeCount; i++)
		{
			if (employee[i] == emp)
			{
				cout << "\nEmployee already exists";
				return false;
			}
		}
		employee[employeeCount] = emp;
		employeeCount++;
		return true;
	}
	bool RemoveEmployee(int employeeID);
	void DisplayAllEmployees();
};

class Employee
{
private:
	int ID;
	Name name;
	Address permanentAddr;
	bool assignedToDept;
	Project* project[3];
	int projectCount;
	Department* Dept;
public:
	Employee(int ID, string f,string l,int HN,char B,int SN,string city): name(f,l),permanentAddr(HN,B,SN,city)
	{
		this->ID = ID;
		assignedToDept = false;
		for (int i = 0; i < 3; i++)
		{
			project[i] = NULL;
		}
		projectCount = 0;
		Dept = NULL;
	}
	int getID()
	{
		return ID;
	}
	void displayEmployeeInfo()
	{
		cout << "\nEmployee ID: " << ID << "\n";
		name.displayName();
		permanentAddr.displayAddress();
	}
	bool AddProject(Project* proj)
	{
		if (projectCount >= 3)
		{
			cout << "\nimit exceeded";
			return false;
		}
		for (int i = 0; i < projectCount; i++)
		{
			if (project[i] == proj)
			{
				cout << "\nProject already assigned";
				return false;
			}
		}
		project[projectCount] = proj;
		projectCount++;
		return true;
	}
	bool RemoveProject(int projectID)
	{
		for (int i = 0; i < projectCount; i++)
		{
			if (project[i]->getID() == projectID)
			{
				for (int j = i; j < projectCount - 1; j++)
				{
					project[j] = project[j + 1];
				}
				project[projectCount - 1] = NULL;
				projectCount--;
				return true;
			}
		}
		return false;
	}
	void displayAllProjects()
	{
		cout << "\nAll projects under the employee are: ";
		for (int i = 0; i < 3; i++)
		{
			if (project[i] != NULL)
			{
				project[i]->displayProjectInfo();
				cout << endl;
			}
		}
	}
	void setAssignedToDept(bool value)
	{
		assignedToDept = value;
	}
	bool GetAssignedToDept()
	{
		return assignedToDept;
	}
	void SetDept(Department* dept)
	{
		Dept = dept;
	}
	void displayDept()
	{
		if (Dept != NULL)
		{
			Dept->displayDeptInfo();
		}
	}
};

void Project::DisplayAllEmployees()
{
	for (int i = 0; i < 10; i++) 
	{
		if (employee[i] != NULL) 
		{
			employee[i]->displayEmployeeInfo();
		}
	}
}

bool Department::RemoveEmployee(int employeeID)
{
	for (int i = 0; i < employeeCount; i++)
	{
		if (employee[i]->getID() == employeeID)
		{
			for (int j = i; j < employeeCount - 1; j++)
			{
				employee[j] = employee[j + 1];
			}
			employee[employeeCount - 1] = NULL;
			employeeCount--;
			return true;
		}
	}
	return false;
}

void Department::DisplayAllEmployees()
{
	cout << "\nThe Employees are: ";
	for (int i = 0; i < employeeCount; i++)
	{
		if (employee[i] != NULL)
		{
			employee[i]->displayEmployeeInfo();
		}
	}
}

class Company
{
private:
	static int count;
	Employee* employees[100];
	int ecount;
	Project* projects[20];
	int pcount;
	Department* department[4];
	int dcount;
	Company()
	{
		for (int i = 0; i < 100; i++)
		{
			employees[i] = NULL;
		}
		for (int i = 0; i < 20; i++)
		{
			projects[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			department[i] = NULL;
		}
		ecount = 0;
		pcount = 0;
		dcount = 0;
		count ++ ;
	}
public:
	static Company* Construct()
	{
		if (count >= 1)
		{
			cout << "\nCompany already exists";
			return nullptr;
		}
		return new Company();
	}
	void createDepartment(int ID, string name)
	{
		if (dcount >= 4)
		{
			cout << "\nLimit exceeded";
			return;
		}
		department[dcount] = new Department(ID, name);
		dcount++;
		cout << "\nDepartment created";
	}
	void createProject(int ID, string description)
	{
		if (pcount >= 20)
		{
			cout << "\nLimit exceeded";
			return;
		}
		projects[pcount] = new Project(ID, description);
		pcount++;
		cout << "\nProject created";
	}
	void createEmployee(int ID, string fn, string ln, int HN, char B, int SN, string city)
	{
		if (ecount >= 100)
		{
			cout << "\nLimit exceeded";
			return;
		}
		employees[ecount] = new Employee(ID, fn, ln, HN, B, SN, city);
		ecount++;
		cout << "\nEmployee created";
	}
	void displayDeptID(int id)
	{
		for (int i = 0; i < dcount; i++)
		{
			if (department[i]->getID() == id)
			{
				department[i]->displayDeptInfo();
				return;
			}
		}
		cout << "\nDepartment not found";
	}
	void displayProjID(int id)
	{
		for (int i = 0; i < pcount; i++)
		{
			if (projects[i]->getID() == id)
			{
				projects[i]->displayProjectInfo();
				return;
			}
		}
		cout << "\nProject not found";
	}
	void displayEmpID(int id)
	{
		for (int i = 0; i < ecount; i++)
		{
			if (employees[i]->getID() == id)
			{
				employees[i]->displayEmployeeInfo();
				return;
			}
		}
		cout << "\nEmployee not found";
	}
	bool addEmpInDept(int idE, int idD)
	{
		Employee* emp = NULL;
		Department* dept = NULL;

		for (int i = 0; i < ecount; i++) {
			if (employees[i]->getID() == idE)
			{
				emp = employees[i];
				break;
			}
		}
		for (int i = 0; i < dcount; i++)
		{
			if (department[i]->getID() == idD) 
			{
				dept = department[i];
				break;
			}
		}
		if (emp == NULL)
		{
			cout << "\nEmployee not found";
			return false; 
		}
		if (dept == NULL)
		{
			cout << "\nDepartment not found";
			return false; 
		}
		if (emp->GetAssignedToDept())
		{
			cout << "\nEmployee is already assigned";
			return false;
		}
		if (!dept->AddEmployee(emp))
		{
			return false;
		}
		emp->setAssignedToDept(true);
		emp->SetDept(dept);
		cout << "\nEmployee " << idE << " added to Department " << idD;
		return true;
	}
	bool addEmpInProj(int idE, int idP)
	{
		Employee* emp = NULL;
		Project* proj = NULL;

		for (int i = 0; i < ecount; i++) {
			if (employees[i]->getID() == idE)
			{
				emp = employees[i];
				break;
			}
		}
		for (int i = 0; i < pcount; i++)
		{
			if (projects[i]->getID() == idP)
			{
				proj = projects[i];
				break;
			}
		}
		if (emp == NULL)
		{
			cout << "\nEmployee not found";
			return false;
		}
		if (proj == NULL)
		{
			cout << "\nProject not found";
			return false;
		}
		if (!emp->AddProject(proj))
		{
			return false;
		}
		if (!proj->AddEmployee(emp))
		{
			emp->RemoveProject(idP);
			return false;
		}
		cout << "\nEmployee " << idE << " added to Project " << idP;
		return true;
	}
	bool displayAllProj(int id)
	{
		for (int i = 0; i < ecount; i++)
		{
			if (employees[i]->getID() == id)
			{
				employees[i]->displayAllProjects();
				return true;
			}
		}
		return false;
	}
	bool displayAllEmpInDept(int id)
	{
		{
			for (int i = 0; i < dcount; i++)
			{
				if (department[i]->getID() == id)
				{
					department[i]->DisplayAllEmployees();
					return true;
				}
			}
			return false;
		}
	}
	bool displayAllEmpInProj(int id)
	{
		{
			for (int i = 0; i < pcount; i++)
			{
				if (projects[i]->getID() == id)
				{
					projects[i]->DisplayAllEmployees();
					return true;
				}
			}
			return false;
		}
	}
	bool displayDept(int id)
	{
		for (int i = 0; i < ecount; i++)
		{
			if (employees[i]->getID() == id)
			{
				employees[i]->displayDept();
				return true;
			}
		}
		return false;
	}
	bool removeEmpFromDep(int idE, int idD)
	{
		Department* dept = NULL;
		Employee* emp = NULL;
		for (int i = 0; i < dcount; i++)
		{
			if (department[i]->getID() == idD)
			{
				dept = department[i];
				break;
			}
		}
		for (int i = 0; i < ecount; i++)
		{
			if (employees[i]->getID() == idE)
			{
				emp = employees[i];
				break;
			}
		}
		if (dept != NULL && emp != NULL)
		{
			bool removed = dept->RemoveEmployee(idE);
			if (removed)
			{
				emp->setAssignedToDept(false);
				emp->SetDept(NULL);
			}
			return removed;
		}
		return false;
	}
	bool removeEmpFromProj(int idE, int idP)
	{
		Project* proj = NULL;
		Employee* emp = NULL;
		for (int i = 0; i < ecount; i++)
		{
			if (employees[i]->getID() == idE)
			{
				emp = employees[i];
				break;
			}
		}
		for (int i = 0; i < pcount; i++)
		{
			if (projects[i]->getID() == idP)
			{
				proj = projects[i];
				break;
			}
		}
		if (emp != NULL && proj != NULL)
		{
			bool removed = proj->RemoveEmployee(emp);
			if (removed)
			{
				emp->RemoveProject(idP);
			}
			return removed;
		}
		return false;
	}

	~Company()
	{
		for (int i = 0; i < ecount; i++)
		{
			delete employees[i];
		}
		for (int i = 0; i < pcount; i++)
		{
			delete projects[i];
		}
		for (int i = 0; i < dcount; i++)
		{
			delete department[i];
		}
		count--;
	}
};

int Company::count = 0;

int main()
{
	cout << "==========Welcome to CMS-Company Management System==========";
	cout << "\n\nHow we may help you today? ";
	Company* company = Company::Construct();
	int choice;
	while (true)
	{
		cout << "\n\nThese are our services. Select what you want.\n";
		cout << "0.  Exit" << endl;
		cout << "1.  Create a new Department\n";
		cout << "2.  Create a new Employee\n";
		cout << "3.  Create a new Project\n";
		cout << "4.  Display a Department\n";
		cout << "5.  Display an Employee\n";
		cout << "6.  Display a Project\n";
		cout << "7.  Add Employee to Department\n";
		cout << "8.  Add Employee to Project\n";
		cout << "9.  Display all Projects of an Employee\n";
		cout << "10. Display all Employees in a Department\n";
		cout << "11. Remove Employee from Department\n";
		cout << "12. Remove Employee from Project\n";
		cout << "13. Display all Employees in a Project\n";
		cout << "14. Display Department of an Employee\n";
		cout << "\nEnter option: ";
		cin >> choice;

		if (choice == 0)
		{
			cout << "\nThank you. We hope you never come back to us";
			delete company;
			return 0;
		}
		else if (choice == 1)
		{
			int id; string name;
			cout << "Enter Department ID: ";
			cin >> id;
			cout << "Enter Department Name: ";
			cin >> name;
			company->createDepartment(id, name);
		}
		else if (choice == 2)
		{
			int id, HN, SN;
			string fn, ln, city;
			char B;

			cout << "Enter Employee ID: ";
			cin >> id;
			cout << "Enter First Name: ";
			cin >> fn;
			cout << "Enter Last Name: ";
			cin >> ln;
			cout << "Enter House No: ";
			cin >> HN;
			cout << "Enter Block (char): ";
			cin >> B;
			cout << "Enter Street No: ";
			cin >> SN;
			cout << "Enter City: ";
			cin >> city;
			company->createEmployee(id, fn, ln, HN, B, SN, city);
		}
		else if (choice == 3)
		{
			int id; string desc;
			cout << "Enter Project ID: ";
			cin >> id;
			cout << "Enter Description: ";
			cin >> desc;
			company->createProject(id, desc);
		}
		else if (choice == 4)
		{
			int id;
			cout << "Enter Department ID: ";
			cin >> id;
			company->displayDeptID(id);
		}
		else if (choice == 5)
		{
			int id;
			cout << "Enter Employee ID: ";
			cin >> id;
			company->displayEmpID(id);
		}
		else if (choice == 6) 
		{
			int id;
			cout << "Enter Project ID: ";
			cin >> id;
			company->displayProjID(id);
		}
		else if (choice == 7)
		{
			int idE, idD;
			cout << "Enter Employee ID: ";
			cin >> idE;
			cout << "Enter Department ID: ";
			cin >> idD;
			company->addEmpInDept(idE, idD);
		}
		else if (choice == 8) 
		{
			int idE, idP;
			cout << "Enter Employee ID: ";
			cin >> idE;
			cout << "Enter Project ID: ";
			cin >> idP;

			company->addEmpInProj(idE, idP);
		}
		else if (choice == 9) 
		{
			int id;
			cout << "Enter Employee ID: ";
			cin >> id;
			company->displayAllProj(id);
		}

		else if (choice == 10)
		{
			int id;
			cout << "Enter Department ID: ";
			cin >> id;
			company->displayAllEmpInDept(id);
		}
		else if (choice == 11)
		{
			int idE, idD;
			cout << "Enter Employee ID: ";
			cin >> idE;
			cout << "Enter Department ID: ";
			cin >> idD;
			if (company->removeEmpFromDep(idE, idD)) {
				cout << "\nEmployee removed from Department";
			}
		}
		else if (choice == 12)
		{
			int idE, idP;
			cout << "Enter Employee ID: ";
			cin >> idE;
			cout << "Enter Project ID: ";
			cin >> idP;
			company->removeEmpFromProj(idE, idP);
		}
		else if (choice == 13)
		{
			int id;
			cout << "Enter Project ID: ";
			cin >> id;
			company->displayAllEmpInProj(id);
		}
		else if (choice == 14)
		{
			int id;
			cout << "Enter Employee ID: ";
			cin >> id;
			company->displayDept(id);
		}
		else
		{
			cout << "\nInvalid option! Please try again: \n";
		}
	}
	delete company;
}