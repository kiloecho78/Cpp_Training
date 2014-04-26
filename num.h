class num
{
	private:
		double _number;
	
	public:
		num();
		num(int);
		num(double);
		num(char);
		
		void setIntegerValue(int);
		void setDoubleValue(double);
		void setCharValue(char);
		void setValue(int);
		void setValue(double);
		void setValue(char);
		
		int integerValue();
		double doubleValue();
		char charValue();
		
};