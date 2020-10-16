#include<iostream>
using namespace std;

class Array
{
	protected:
		int *Arr;
		int size;
	public:
		Array(int value=10)
		{
			this->size=value;
			this->Arr=new int[size];
		}
		
		Array(Array &ref)
		{
			this->size=ref.size;
			this->Arr=new int[this->size];
			for(int i=0;i<size;i++)
			{
				this->Arr[i]=ref.Arr[i];
			}
		}
		
		~Array()
		{
			delete []Arr;
		}
		
		inline void Accept();
		inline void Display();
};

void Array::Accept()
{
	cout<<"Enter the values"<<endl;
	for(int i=0;i<this->size;i++)
	{
		cin>>Arr[i];
	}
}

void Array::Display()
{
	cout<<"Elements are"<<endl;
	for(int i=0;i<this->size;i++)
	{
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}

class ArrSearch:public Array
{
	public:
		ArrSearch(int no=10):Array(no){}
		int Frequency(int);
		int SearchFirst(int);
		int SearchLast(int);
		int EvenCount();
		int OddCount();
		int SumAll();
};

int ArrSearch::SearchFirst(int value)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		if(Arr[i]==value)
		{
			break;
		}
	}
	if(i==size)
	{
		return -1;
	}
	else
	{
		return i+1;
	}
}

int ArrSearch::Frequency(int value)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(Arr[i]==value)
		{
			count++;
		}
	}
	return count;
}

int ArrSearch::SearchLast(int value)
{
	int i=-1;
	int j=0;
	for(j=0;j<size;j++)
	{
		if(Arr[j]==value)
		{
			i=j;			
		}
	}
	return i;
}

int ArrSearch::EvenCount()
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(Arr[i]%2==0)
		{
			count++;
		}
	}
	return count;
}

int ArrSearch::OddCount()
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(Arr[i]%2!=0)
		{
			count++;
		}
	}
	return count;
}

int ArrSearch::SumAll()
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		count+=Arr[i];
	}
	return count;
}

int main()
{
	int n=0;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	ArrSearch aobj(n);
	aobj.Accept();
	aobj.Display();
	int choice=1;
	int element=0;
	int ret=0;
	while(choice!=0)
	{
		cout<<"-----------------------------"<<endl;
		cout<<"Menu : "<<endl;
		cout<<"1.Frequency of element"<<endl;
		cout<<"2.First occurance of element"<<endl;
		cout<<"3.Last occurence of element"<<endl;
		cout<<"4.Number of even elements"<<endl;
		cout<<"5.Number of odd elements"<<endl;
		cout<<"6.Sum of all elements"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Enter your choice"<<endl;
		cout<<"-----------------------------"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"-----------------------------"<<endl;
				cout<<"Enter the element"<<endl;
				cout<<"-----------------------------"<<endl;
				cin>>element;
				ret=aobj.Frequency(element);
				if(ret==-1)
				{
					cout<<"-----------------------------"<<endl;
					cout<<"Element is not present"<<endl;
					cout<<"-----------------------------"<<endl;
				}
				else
				{
					cout<<"-----------------------------"<<endl;
					cout<<"Element is present "<<ret<<" times"<<endl;
					cout<<"-----------------------------"<<endl;
				}
				break;
			case 2:
				cout<<"-----------------------------"<<endl;
				cout<<"Enter the element"<<endl;
				cout<<"-----------------------------"<<endl;
				cin>>element;
				ret=aobj.SearchFirst(element);
				if(ret==-1)
				{
					cout<<"-----------------------------"<<endl;
					cout<<"Element is not present"<<endl;
					cout<<"-----------------------------"<<endl;
				}
				else
				{
					cout<<"-----------------------------"<<endl;
					cout<<"First occurence is "<<ret<<endl;
					cout<<"-----------------------------"<<endl;
				}
				break;
			case 3:
				cout<<"-----------------------------"<<endl;
				cout<<"Enter the element"<<endl;
				cout<<"-----------------------------"<<endl;
				cin>>element;
				ret=aobj.SearchLast(element);
				if(ret==-1)
				{
					cout<<"-----------------------------"<<endl;
					cout<<"Element is not present"<<endl;
					cout<<"-----------------------------"<<endl;
				}
				else
				{
					cout<<"-----------------------------"<<endl;
					cout<<"Last occurence is "<<ret<<endl;
					cout<<"-----------------------------"<<endl;
				}
				break;
			case 4:
				ret=aobj.EvenCount();
				cout<<"-----------------------------"<<endl;
				cout<<"Even elements are "<<ret<<endl;
				cout<<"-----------------------------"<<endl;
				break;
			case 5:
				ret=aobj.OddCount();
				cout<<"-----------------------------"<<endl;
				cout<<"Odd elements are "<<ret<<endl;
				cout<<"-----------------------------"<<endl;
				break;
			case 6:
				ret=aobj.SumAll();
				cout<<"-----------------------------"<<endl;
				cout<<"Sum of all elements is "<<ret<<endl;
				cout<<"-----------------------------"<<endl;
				break;
		}
	}
	return 0;
}














