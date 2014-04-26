class employee : public person
{
	private:
		string _employeeID;
		string _jobTitle;
	public:
		employee();
		employee(person);
		employee(string, string);
		void setEmployeeID(string);
		void setJobTitle(string);
		
		string getEmployeeID();
		string getJobTitle();
		
};