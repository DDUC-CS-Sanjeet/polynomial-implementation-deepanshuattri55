#include<iostream>
using namespace std;

class Polynomial
{
	int array[100];
	int power;
	
	 // Variables to store information about polynomial
	 public:
	 	
	 	Polynomial()
	 	{
	 		power=1;
		}
		Polynomial(int deg)
		{
			// Behavior of constructor with arguments
			cout<<"enter the degree of "<<deg<<" polynomial ";
			cin>>power;
			power++;	
		}
		~Polynomial()
        {
             // Behavior of destructor
        }
         //  Overload copy constructor, +, - and = operators
        Polynomial operator +(Polynomial d)
		{
			Polynomial p;
			p.power=this->power>=d.power? this->power:d.power;
			for(int i=0;i<p.power;i++)
			{
				if(i>=this->power)
				  this->array[i]=0;
				if(i>=d.power)
				  d.array[i]=0;
				  p.array[i]=d.array[i]+this->array[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial d)
		{
			Polynomial p;
			p.power=this->power>=d.power? this->power:d.power;
			for(int i=0;i<p.power;i++)
			{
				if(i>=this->power)
				  this-> array[i]=0;
				if (i>=d.power)
				  d.array[i]=0;
				  p.array[i]=this->array[i]-d.array[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial d)
		{
			Polynomial p;
			this->power=d.power;
			for(int i=0;i<this->power;i++)
			  this->array[i]=d.array[i];
	    }
	    void storePolynomial()
        {
                //  Code to enter and store polynomial	
            cout<<"\n enter the cofficient with respect to its ascending order of power"<<endl;
			for(int i=0;i<power;i++)
			cin>>array[i];
 	    }
 	    void display()
        {
            //  Code to print the polynomial in readable format
            cout<<"\n";
            for(int i=0;i<power;i++)
            {
            	cout<<array[i]<<"X^"<<i;
            	if(i<power-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{
	  int degFirst=1, degSecond=2;
  // Ask user to input the values of degFirst and degSecond 
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  cout<<"\n the first polynomial is :";
  firstPolynomial.display();
  cout<<endl;
  cout<<"\n the second polynomial is : ";
  secondPolynomial.display();
  cout<<endl;
  cout<<"\n the third polynomial is :";
  thirdPolynomial.display();
  cout<<endl;
  cout<<"\n the first polynomial is :";
  fourthPolynomial.display();

}
