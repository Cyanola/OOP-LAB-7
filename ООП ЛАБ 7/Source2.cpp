#include <iostream>
#include <cassert> // assert
#include <cmath>
#include <string>
using namespace std;
struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() { };
};
struct Number : public Expression
{
	Number(double value) : value_(value) {}
	double value() const { return value_; }
	double evaluate() const { return value_; }
private:
	double value_;
};
struct BinaryOperation : public Expression
{
	enum {
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};
	BinaryOperation(Expression const* left, int op,

		Expression const* right) :left_(left), op_(op), right_(right)

	{
		assert(left_ && right_);
	}
	~BinaryOperation()
	{
		delete left_;
		delete right_;
	}
	Expression const* left() const { return left_; }
	Expression const* right() const { return right_; }
	int operation() const { return op_; }

	double evaluate() const
	{
		double left = left_->evaluate();
		double right = right_->evaluate();
		switch (op_)
		{
		case PLUS: return left + right;
		case MINUS: return left - right;
		case DIV: return left / right;
		case MUL: return left * right;
		}
		assert(0);
		return 0.0;
	}
private:
	Expression const* left_;
	Expression const* right_;
	int op_;
};
struct Expression;
struct BinaryOperation;
struct Number;
struct FunctionCall : Expression
{
		FunctionCall(const string& name, const Expression* arg) : _name(name), _arg(arg)
	{
		
		assert(name == "abs" || name == "sqrt");
	}
	double evaluate() const override
	{
		if (_name == "sqrt") return sqrt(_arg->evaluate());
		else if (_name == "abs") return fabs(_arg->evaluate());

		else throw exception("");
	};

	std::string const& name() const { return this->_name; }
	Expression const* arg() const { return this->_arg; }

	~FunctionCall()
	{
		cout << "Деструктор" << _name << endl;
		delete this->_arg;
	}

private:
	const string _name;
	const Expression* _arg;
};
int main1()
{
	//------------------------------------------------------------
	Expression* e1 = new Number(1.234);
	Expression* e2 = new Number(-1.234);
	Expression* e3 = new BinaryOperation(e1,BinaryOperation::DIV, e2);

	cout << e3->evaluate() << endl;
	//------------------------------------------------------------
	//------------------------------------------------------------
	Expression* n32 = new Number(32.0);
	Expression* n16 = new Number(16.0);
	Expression* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
	Expression* callSqrt = new FunctionCall("sqrt", minus);
	Expression* n2 = new Number(2.0);
	Expression* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
	Expression* callAbs = new FunctionCall("abs", mult);
	cout << callAbs->evaluate() << endl;
	//------------------------------------------------------------
	return 0;
}