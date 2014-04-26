class person
{
	
	protected:
		string _firstName;
		string _lastName;
	public:
		person();
		person(string, string);
	
		//setters
		void setFirstName(string);
		void setLastName(string);
		//getters
		string getFirstName();
		string getLastName();
};