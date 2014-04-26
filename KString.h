class KString
{
	private:
		char* _string;
		int _valueSet;
		
		void copyString(char*, const char*);
		void deleteString();
		
	public:
		KString();
		KString(const char*);
		KString(const KString&); //copy constructor
		
		~KString();
		
		/* Setters */
		void setString(const char*);
		void setString(KString&);
		void append(char);
		void append(const char*);
		void append(KString&);
		void clear();
		
		/* Static Getters */
		static int length(const char*);
		static int length(KString&);
		
		/* Instance Getters*/
		int length();
		char getAt(int);
		bool equals(const char*);
		bool equals(KString&);
		bool isSet();
	
		/* String Getters*/
		const char* cString();
		KString copy();
		KString concat(const char*);
		KString concat(KString&);
		KString toUpperCase();
		KString toLowerCase();
		KString chomp();
		KString trimRight(char);
		KString trimRight();
		KString trimLeft(char);
		KString trimLeft();
		KString trim(char);
		KString trim();
		
		/* Operator Overloading*/
		friend std::ostream &operator<<(std::ostream&, KString&);
		friend std::istream &operator>>(std::istream&, KString&);
		
		char operator[](int);
		
		void operator=(const char*);
		void operator=(KString&);
		
		bool operator==(const char*);
		bool operator==(KString&);
		
		bool operator!=(const char*);
		bool operator!=(KString&);
		
		KString operator+(const char*);
		KString operator+(KString&);
		
		void operator+=(char);
		void operator+=(const char*);
		void operator+=(KString&);
		
};