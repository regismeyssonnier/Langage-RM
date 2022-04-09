#pragma once
#ifndef RM_HEADER
#define RM_HEADER


#define PRINT 1
#define INPUT 2
#define IF 3
#define WHILE 4
#define NEW 5
#define FUNCTION 6

#define INT 7
#define DOUBLE 8
#define STRING 9
#define VCLASS 10
#define CHANGE_SCOPE 11

#define VINT 12
#define VDOUBLE 13
#define VSTRING 14

#define PUT_STACK 15

#define PINT 16
#define PDOUBLE 17
#define PSTRING 18
#define PVCLASS 19
#define PNUMBER 20
#define PNUMBER_INT 21
#define PNUMBER_DOUBLE 22
#define PNUMBER_STRING 23
#define ADD 24
#define ADD_VAR 25

#define END_WHILE 26
#define WHILE_PAR 27

#define INF 28
#define INFEQ 29
#define SUP 30
#define SUPEQ 31
#define EQ 32

#define WHILE_COND 33

#define FUNC_VAR 34
#define FUNC_VAR2 35

#define MUL 36
#define MUL_VAR 37

#define SIZE_NUMBER 38

constexpr int IF_COND = 39;
constexpr int END_IF = 40;
constexpr int IF_PAR = 41;


struct Action {

	vector<int> action;
	vector<int> type_action;
	vector<int>num_action;
	int NUM_VC = 0;
	int NUM_VG = 0;
	int NUM_F = 0;

	int give_num_action_vclass() {
		NUM_VC++;
		return NUM_VC - 1;
	}
	int give_num_action_vgen() {
		NUM_VG++;
		return NUM_VG - 1;
	}
	int give_num_action_func() {
		NUM_F++;
		return NUM_F - 1;
	}
	/******************/
	/* 1  print            */
	/* 2  input               */
	/* 3  if             */
	/* 4 while               */
	/* 5 new            */
	/* 6 function            */
	/* 7 type of print               */
	vector<int> scope;
	int SCOPE = 1;

	map<string, int> class_name;
	map<string, int> func_name;

	int I_start;
	int I_end;
};

Action action;

struct var_gen {

	map<string, int>integers;
	map<string, int>doubles;
	map<string, int>strings;
	map<string, int>vclass;
	map<int, string>idoubles;
	vector<int>integer_val;
	vector<double>double_val;
	vector<string> pstring;

	deque<int> stack_var_int;
	deque<double> stack_var_double;
	deque<string> stack_var_string;

};

struct add {
	vector<int> integer_val;
	vector<double> double_val;
	vector<int> type_var_func;
	vector<string> param_name;
	vector<int>cinteger_val;
	vector<double>cdouble_val;
};

struct mul {

	vector<int> cint;
	vector<double> cdouble;
	vector<int> type_var_func;
	vector<int> size_param;
	vector<int>scope;
	int index_cint=0;
	int index_cdouble = 0;
	int nb_param = 0;
	int size_instruction;

};

struct while_rm {

	int inst_start;
	int inst_end;
	int cond;
	int ind;
	vector<int> I_start;
	vector<int> I_end;
	vector<int> type_param;
	vector<int>nb_by_param;
	int exec;
	bool start = false;

};

struct if_rm {

	int inst_start;
	int inst_end;
	int cond;
	int ind;
	vector<int> I_start;
	vector<int> I_end;
	vector<int> type_param;
	vector<int>nb_by_param;
	int exec;
	bool start = false;

};

struct function {

	Action action;
	var_gen var;
	vector<int>integer_val;
	vector<double>double_val;

	vector<string> pstring;
	vector<int> type_var_func;
	vector<string> param_name;
	string name;
	vector<add> add_func;
};


struct var_class {
	string name;
	Action action;
	var_gen var;
	vector<function> func;
	int num = 0;
	deque<int> stack_var_int;
	deque<double> stack_var_double;
	deque<string> stack_var_string;
	deque<string> stack_var_name;
	deque<int> param_name_stack;
};

struct print {
	vector<string> display;
	int SCOPE_VARPRINT;
	int class_num;
	vector<int> back;
};

struct index_stack {
	vector<int> start;
	vector<int> type;
	vector<int> end;
};

struct Node {

	Node* father;
	vector<Node*> son;
	Node* left;
	Node* right;
	int indice;
	int ind_nws = 0;

};

Node* root_if=nullptr, *root_w=nullptr, *father_if=nullptr, *father_w=nullptr, *left_w=nullptr, *right_w=nullptr,*last_fw,*last_if;
vector<Node*>NW, ANW, NI, ANI;


void Register_Action(int a, int t, int n, int s) {

	action.action.push_back(a);
	action.type_action.push_back(t);
	action.num_action.push_back(n);
	action.scope.push_back(s);

}

///template <class val, class ret>
bool Existe(map<string, int> d, string a, int& r) {

	map<string, int>::iterator itl = d.lower_bound(a);

	//cout << itl << " / " << d.end() << endl;
	if (itl == d.end()) {
		//for (auto e : d)cout << "ee-" << e.first <<"-"<< endl;
		//cout << "end " << a <<"-"<< endl;
		return false;

	}
	else {

		if (itl->first == a) {
			//cout << a << "juste" << endl;
			r = itl->second;
			return true;
		}
		else {
			//for (auto e :d)cout << "e " << e.first << endl;
			//cout << a << " pasjuste " << itl->first << endl;
			return false;
		}
	}


}



var_gen VG;
var_class VC;
vector<function> func;
vector<var_class> DC;
vector<print> VP;
vector<index_stack> IS;
vector<add> VA;
vector<while_rm> WR;
vector<mul>VM;
vector<if_rm> VI;








#endif