#include<iostream>
using namespace std;

class Polynomial
{
  private:
	  	int array[100];
  		int degree;		
  		
    // Variables to store information about polynomial
  public:

    Polynomial()
    {
    	degree=1;
    }

    Polynomial(int deg)
    {
    	// Behavior of constructor with arguments
    	cout<<"Enter the  degree of "<<deg<< " Polynomial ";
 		 cin>>degree;
 		 degree++;
    }
  
    ~Polynomial()
    {
    	cout<<"Destructor called ";
      // Behavior of destructor
    }
    
    //  Overload copy constructor, +, - and = operators
    Polynomial operator +(Polynomial c)
    {
    	Polynomial p;
		p.degree= this->degree>=c.degree? this->degree:c.degree;    	
		for(int i=0;i<p.degree;i++)
    		p.array[i]=c.array[i]+this->array[i];
    	
    	return p;
	}

	Polynomial operator -(Polynomial c)
    {
    	Polynomial p;
		p.degree= this->degree>=c.degree? this->degree:c.degree;    	
		for(int i=0;i<p.degree;i++)
    		p.array[i]=this->array[i]-c.array[i];
    	
    	return p;
	}
	
	Polynomial operator =(Polynomial c)
    {
    	this->degree=c.degree;
    	for(int i=0;i<this->degree;i++)
    		this->array[i]=c.array[i];
    	
	}
    
    void storePolynomial()
    {
      //  Code to enter and store polynomial	
      	
     	cout<<"Enter the cofficients of x0,x1,x2....with respect to the power : "<<endl;
		for(int i=0;i<degree;i++)
			cin>>array[i];
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      cout<<"\n";
      for(int i=0;i<degree;i++)
      {
       	cout<<array[i]<<"X^"<<i;
       	if(i<degree-1)
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
  
  cout<<"\n 1st polynomial is : ";
  firstPolynomial.display();
  cout<<endl;
  cout<<" \n 2nd polynomial is : ";
  secondPolynomial.display();
  cout<<endl;
  cout<<"\n polynomial after addition is : ";
  thirdPolynomial.display();
  cout<<endl;
  cout<<"\n polynomial after subtraction is : ";
  fourthPolynomial.display();
  cout<<endl;
}
