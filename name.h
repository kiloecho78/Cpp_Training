class name
{
	private:
		char *_firstName;
		char *_lastName;
	public:
			name();
			~name();
		char *getFirstName();
		char *getLastName();
		
		void setFirstName(char*);
		void setLastName(char*);
};