/*

>>Compilation

g++ -std=c++11 expressionEvaluation.cpp 

>C++11 required to use stoi()

>>Algorithm

This is derived from "Shunting Yard Algo" used to convert infix to postfix. Generally postfix and prefix expressions can be directly
evaluated as all BODMAS rules are taken care of by the expression style itself.

Here you have 2 stacks, a stack to store numbers and a stack to store operators. When a new operator falls, if the previous operator
has a higher precedence or eqal => You may perform that previous operation. So pop 2 times from value stack, compute and push to value
stack. Keep doing this till prev operator is less than current. Then simply push to operator stack.

If you find a "(", simply push to operator stack. If you find a ")", simply keep computing till you hit a "("

*/

#include<bits/stdc++.h>
using namespace std;

vector <int> valueStack;
vector <string> operatorStack;

map <string,int> operatorPriority; //Higher the priority, the better

//Input
string expression="100*(2+12)/14";
//........... 

struct extractedItem{
	string item;
	bool isOperator;
	int startNextExtractFrom;
};

struct extractedItem* extract(int start){

	struct extractedItem* returnValue = new struct extractedItem;

	//Operator Extracted
	if(expression[start]=='+'||expression[start]=='-'||expression[start]=='*'||expression[start]=='/'||expression[start]=='('
		||expression[start]==')'){

		returnValue->item=expression[start];
		returnValue->startNextExtractFrom=start+1;
		returnValue->isOperator=true;

		return returnValue;

	}

	//Number extracted
	string buffer="";
	int i;

	for(i=start;i<expression.length();i++){
		if('0'<=expression[i] && expression[i]<='9'){
			buffer=buffer+expression[i];
		}
		else{
			break;
		}
	}

	returnValue->item=buffer;
	returnValue->startNextExtractFrom=i;
	returnValue->isOperator=false;

	return returnValue;

}

void performOperationAndPush(int a, int b, string operation){

	if(operation=="+"){
		valueStack.push_back(a+b);
	}
	else if(operation=="-"){
		valueStack.push_back(a-b);
	}
	else if(operation=="*"){
		valueStack.push_back(a*b);
	}
	else if(operation=="/"){
		valueStack.push_back(a/b);
	}

}

void evaluateExpression(){

	expression="("+expression+")"; //Forces all ops to complete

	int extractStart=0;
	struct extractedItem* extractStruct;

	int a,b;
	string operation;

	while(extractStart<expression.length()){

		extractStruct=extract(extractStart);

		if(extractStruct->isOperator){

			if(extractStruct->item=="("){

				operatorStack.push_back("("); //Simply push "("
			
			}
			else if(extractStruct->item==")"){

				while(operatorStack[operatorStack.size()-1]!="("){ //Operate till you find ")"

					b=valueStack[valueStack.size()-1];
					valueStack.pop_back();

					a=valueStack[valueStack.size()-1];
					valueStack.pop_back();

					operation=operatorStack[operatorStack.size()-1];
					operatorStack.pop_back();

					performOperationAndPush(a,b,operation);

				}

				operatorStack.pop_back(); // Remove "("

			}
			else{

				//Keep operating till stack's top operator precedence < extractStruct->item

				while((operatorStack.size()!=0) && 
					(operatorPriority[operatorStack[operatorStack.size()-1]]>=operatorPriority[extractStruct->item])){

					b=valueStack[valueStack.size()-1];
					valueStack.pop_back();

					a=valueStack[valueStack.size()-1];
					valueStack.pop_back();

					operation=operatorStack[operatorStack.size()-1];
					operatorStack.pop_back();

					performOperationAndPush(a,b,operation);

				}

				operatorStack.push_back(extractStruct->item);

			}

		}
		else{
			//Push number to valueStack
			valueStack.push_back(stoi(extractStruct->item));
		}

		extractStart=extractStruct->startNextExtractFrom;

	}

}

int main(){

	//Initialize Map
	operatorPriority["("]=0; //Any op should stop here

	operatorPriority["+"]=1;
	operatorPriority["-"]=1;
	operatorPriority["*"]=2;
	operatorPriority["/"]=2;
	
	evaluateExpression();

	cout<<"Answer= "<<valueStack[valueStack.size()-1]<<endl;

	return 0;
}