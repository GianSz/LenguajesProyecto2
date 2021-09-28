#include "Polynomial.h"

//Default constructpolyObj: it creates a Polynomial with grade 99
Polynomial::Polynomial()
{
	Coef = new double[100];
	grade=99;
}

//Special constructpolyObj: it creates a polynomial with grade sz
Polynomial::Polynomial(int sz)
{
	Coef = new double[sz + 1];
	grade = sz;
}

//Copy ConstructpolyObj
Polynomial::Polynomial(Polynomial &polyObj)
{
	Coef = polyObj.Coef;
	grade = polyObj.grade;
}


//DestructpolyObj: deallocate mempolyObjy
Polynomial::~Polynomial()
{
	delete []Coef;
	Coef=0;
}

//readPolynomial Method: Reads all positions of the Polynomial
void Polynomial::readPolynomial()
{
	int i;
	for(i= 0; i<= grade; i++)
	{
		cout<<"Polynomial["<<i<<"]= ";
		cin>>Coef[i];
	}
}

//printPolynomial Method: Prints all positions of the Polynomial
void Polynomial::printPolynomial()
{
	int i;
	for(i= grade; i>0; i--)
	{
		cout<<Coef[i]<<"X^"<<i<<" + ";
	}
	cout<<Coef[0]<<endl;
}
//generatePolynomial method: generates random coeficients
void Polynomial::generatePolynomial()
{
	int i;
	for(i= 0; i<= grade; i++)
	{
		Coef[i]=rand()%10;
	}
	
}
//initPolynomial method: delete the current polynomomial, and creates new one with grade i
void Polynomial::initPolynomial(int i)
{
	delete []Coef;
	Coef=new double[i+1];
	grade = i;
	for(i=0; i<=grade;i++)
	{
		Coef[i]=0;
	}
}

//getgrade Method: return the Polynomial grade
int Polynomial::getGrade()
{
	return grade;
}

//Overloading += operator
void Polynomial::operator+=(const Polynomial &B)
{
	/**************************************
		write your code here
	***************************************/



	/*************************************/
}

//Overloading + operator
//HECHO :)
Polynomial *Polynomial::operator+(Polynomial &B)
{
	
	Polynomial *res;
	if (grade>=B.grade){
		res = new Polynomial(grade);		

		int i;
		for(i = 0; i <= grade; i++){

			if(i<=B.grade)
				res->Coef[i] = Coef[i] + B.Coef[i];
			else 
				res->Coef[i] = Coef[i];
		}

	}

	else{
		res = new Polynomial(B.grade);

		int i;
		for(i = 0; i <= B.grade; i++){

			if(i<=grade)
				res->Coef[i] = Coef[i] + B.Coef[i];
			else 
				res->Coef[i] = B.Coef[i];
		}
	}

	return res;
	
}

//Overloading * operatorfor Polynomial*Polynomial		
Polynomial *Polynomial::operator*(Polynomial &B)
{
	
	Polynomial *res;
	res = new Polynomial(grade + B.grade); 

	Polynomial *auxiliar;
	auxiliar = new Polynomial(grade + B.grade);
	
	for(int i = 0; i<=grade; i++){

		if(i>0){
			for(int k = 0; k<i; k++){
				auxiliar->Coef[k] = 0;
			}
		}

		for(int j = i; j<=B.grade+i; j++){
			auxiliar->Coef[j] = Coef[i] * B.Coef[j-i];
		}

		res = res->operator+(*auxiliar);
	}

	return res;
}


//Overloading *= operatorfor Polynomial*Polynomial
void Polynomial::operator*=(Polynomial &B)
{

	/**************************************
		write your code here
	***************************************/



	/*************************************/

}

//Overloading * operatorfor Polynomial*int
//¿Esto existe?
Polynomial *Polynomial::operator*(int val)
{
	Polynomial *res;
	res = new Polynomial(grade);

	for(int i = 0; i<grade; i++){
		res->Coef[i] = Coef[i] * val;
	}

	return res;
}



//Overloading * operatorfor Polynomial*int
void Polynomial::operator*=(int c)
{

}


//Overloading + operator
void Polynomial::operator=(const Polynomial &B)
{
	/**************************************
		write your code here
	***************************************/



	/*************************************/
}