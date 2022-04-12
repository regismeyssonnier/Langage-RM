#pragma once
#ifndef OP_RM
#define OP_RM

#include <iostream>
#include <fstream>
using namespace std;

#include <string>
#include <vector>
#include <map>
#include <stack>
#include <deque>
using namespace std;
#include "rm_header.h"
#include "function_rm.h"
using namespace std;

template <typename V>
void Detect_op(int op, int op_var, V &VO, V &VO2, V &VO3) {

	string l;
	string mod;
	//cout << "l " << l << endl;
	vector<string> par;
	while (input >> l) {

		size_t fd = l.find_last_of(";");

		if (fd != string::npos) {
			if (l.length() != 1) {
				mod = l.substr(0, fd);
				par.push_back(mod);
			}
			//cout << "add " << mod << endl;
			break;

		}
		else {
			mod = l;
			par.push_back(mod);
		}

		//cout <<"add " <<  mod << endl;
	}

	//cout << "div " << action.SCOPE << endl;

	string modvc;
	string varvc;
	size_t fdvc = par[0].find_last_of("--");
	if (fdvc != string::npos) {
		modvc = par[0].substr(0, fdvc - 1);

		varvc = par[0].substr(fdvc + 1, l.length());
		size_t fdvvc = varvc.find_last_of(";");
		if (fdvvc != string::npos) {
			varvc = varvc.substr(0, varvc.length() - 1);
		}
		//cout << modvc << " -+- " << varvc << endl;
	}

	/*for (int i = 0; i < par.size(); i++) {
		cout << "par " << par[i] << endl;
	}
	cout << modvc << " " << varvc << endl;*/

	op_rm M;
	int nf = func.size() - 1;
	int nd = DC.size() - 1;
	int nfc = DC[nd].func.size() - 1;
	if (action.SCOPE == 1 || action.SCOPE == 3)
		Register_Action(op, op, VO.size(), action.SCOPE);
	else if (action.SCOPE == 4) {
		Register_Func_Action(nf, op, nf, VO2.size(), action.SCOPE);
	}
	else if (action.SCOPE == 5) {
		Register_Class_Func_Action(nd, nfc, op, nd, nfc, action.SCOPE);
		Register_Class_Func_Action(nd, nfc, op, op, VO3.size(), action.SCOPE);
	}

	//cout << "div " << action.SCOPE << endl;
	int sz = 0;
	vector<Action> a1 = Detect_all_variable(par[0], par[0], op_var, action.SCOPE);
	for (int i = 0; i < a1.size(); i++) {
		if (action.SCOPE == 1 || action.SCOPE == 3)
			Register_Action(a1[i].action[0], a1[i].type_action[0], a1[i].num_action[0], a1[i].scope[0]);
		else if (action.SCOPE == 4)
			Register_Func_Action(nf, a1[i].action[0], a1[i].type_action[0], a1[i].num_action[0], a1[i].scope[0]);
		else if (action.SCOPE == 5)
			Register_Class_Func_Action(nd, nfc, a1[i].action[0], a1[i].type_action[0], a1[i].num_action[0], a1[i].scope[0]);

		//cout << "reg " << a1[i].action[0] << " " << a1[i].type_action[0] << " " << a1[i].num_action[0] << " " << a1[i].scope[0] << endl;
	}
	sz += a1.size();
	bool integer = false;
	if (a1[a1.size() - 1].type_action[0] == INT || a1[a1.size() - 1].type_action[0] == VINT) {
		integer = true;
	}
	M.type_var_func.push_back(a1[a1.size() - 1].type_action[0]);
	M.size_param.push_back(a1.size());
	M.scope.push_back(action.SCOPE);

	M.nb_param = par.size();
	for (int i = 1; i < par.size(); i++) {
		///cout << "--------------" << par[i] << endl;
		vector<Action> a2 = Detect_all_variable(par[i], par[i], op_var, action.SCOPE);
		if (a2.size() > 0) {
			for (int j = 0; j < a2.size(); j++) {
				if (action.SCOPE == 1 || action.SCOPE == 3)
					Register_Action(a2[j].action[0], a2[j].type_action[0], a2[j].num_action[0], a2[j].scope[0]);
				else if (action.SCOPE == 4)
					Register_Func_Action(nf, a2[j].action[0], a2[j].type_action[0], a2[j].num_action[0], a2[j].scope[0]);
				else if (action.SCOPE == 5)
					Register_Class_Func_Action(nd, nfc, a2[j].action[0], a2[j].type_action[0], a2[j].num_action[0], a2[j].scope[0]);
			}
			M.type_var_func.push_back(a2[a2.size() - 1].type_action[0]);
			M.size_param.push_back(a2.size());
			M.scope.push_back(action.SCOPE);
			sz += a2.size();
		}
		else {
			if (integer) {
				size_t sz;
				int v = stoi(par[i], &sz);

				M.cint.push_back(v);
				M.type_var_func.push_back(PNUMBER_INT);
				M.size_param.push_back(1);
				M.scope.push_back(action.SCOPE);
				if (action.SCOPE == 1 || action.SCOPE == 3)
					Register_Action(op_var, op_var, 0, action.SCOPE);
				else if (action.SCOPE == 4)
					Register_Func_Action(nf, op_var, op_var, 0, action.SCOPE);
				else if (action.SCOPE == 5)
					Register_Class_Func_Action(nd, nfc, op_var, op_var, 0, action.SCOPE);
				//cout << "PNUMBER_INT" << endl;
			}
			else {
				size_t sz;
				double v = stod(par[i], &sz);

				M.cdouble.push_back(v);
				M.type_var_func.push_back(PNUMBER_DOUBLE);
				M.size_param.push_back(1);
				M.scope.push_back(action.SCOPE);
				if (action.SCOPE == 1 || action.SCOPE == 3)
					Register_Action(op_var, op_var, 0, action.SCOPE);
				else if (action.SCOPE == 4)
					Register_Func_Action(nf, op_var, op_var, 0, action.SCOPE);
				else if (action.SCOPE == 5)
					Register_Class_Func_Action(nd, nfc, op_var, op_var, 0, action.SCOPE);
				//cout << "PNUMBER_DOUBLE" << endl;

			}
			sz++;
		}

	}
	M.size_instruction = sz;

	if (action.SCOPE == 1 || action.SCOPE == 3)
		VO.push_back(M);
	else if (action.SCOPE == 4)
		VO2.push_back(M);
	else if (action.SCOPE == 5)
		VO3.push_back(M);
	




}


void div_op(Action act, int i, int nf, int fun, int type, int cfun) {

	int I = i + 1;
	int mult = 1;

	//cout << " div NBparam " << act.scope[i] << " " << act.SCOPE << " " << act.scope[I] << " " << act.scope[I + 1] << " " << act.scope[I + 2] << endl;

	bool start = true;
	if (act.scope[I] == 1 || act.scope[I] == 3) {
		nf = act.num_action[i];
		
		for (int j = 0; j < VD[nf].nb_param; j++) {
			//cout << "type " << VD[nf].type_var_func[j] << " " << VD[nf].size_param[j] << endl;
			if (VD[nf].size_param[j] == 1) {
				if (VD[nf].type_var_func[j] == INT) {
					if (start)mult = get_INT(act, I);
					else mult /= get_INT(act, I);
					//cout << "getint " << get_INT(act, I) << " " << act.scope[I] << endl;;
				}
				else if (VD[nf].type_var_func[j] == DOUBLE) {
					if (start)mult = get_DOUBLE(act, I);
					else mult /= get_DOUBLE(act, I);
					//cout << "getdouble " << get_DOUBLE(act, I) << " " << act.scope[I] << endl;;
				}
				else if (VD[nf].type_var_func[j] == PNUMBER_INT) {
					mult /= VD[nf].cint[VD[nf].index_cint++];
					//cout << "pnumberint " << VD[nf].cint[VD[nf].index_cint - 1] << " " << act.scope[I] << endl;;
				}
				else if (VD[nf].type_var_func[j] == PNUMBER_DOUBLE) {
					mult /= VD[nf].cdouble[VD[nf].index_cdouble++];
					//cout << "pnumberdouble " << VD[nf].cdouble[VD[nf].index_cdouble - 1] << " " << act.scope[I] << endl;;
				}
				I++;

			}
			else if (VD[nf].size_param[j] == 2) {
				if (VD[nf].type_var_func[j] == INT || VD[nf].type_var_func[j] == VINT) {
					//cout << "getint2 " << get_INT2(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT2(act, I);
					else mult /= get_INT2(act, I);
				}
				else if (VD[nf].type_var_func[j] == DOUBLE || VD[nf].type_var_func[j] == VDOUBLE) {
					if (start)mult = get_DOUBLE2(act, I);
					else mult /= get_DOUBLE2(act, I);
					//cout << "getdouble2 " << get_DOUBLE2(act, I) << " " << act.scope[I] << endl;;
				}

				I += 2;
			}
			else if (VD[nf].size_param[j] == 3) {
				if (VD[nf].type_var_func[j] == INT || VD[nf].type_var_func[j] == VINT || VD[nf].type_var_func[j] == FV_INT) {
					//cout << "getint3 " << get_INT3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT3(act, I);
					else mult /= get_INT3(act, I);
				}
				else if (VD[nf].type_var_func[j] == DOUBLE || VD[nf].type_var_func[j] == VDOUBLE || VD[nf].type_var_func[j] == FV_DOUBLE) {
					//cout << "getdouble3 " << get_DOUBLE3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_DOUBLE3(act, I);
					else mult /= get_DOUBLE3(act, I);
				}
				I += 3;
			}
		}

		var_class vr;
		Action act2;
		act2.type_action.push_back(VD[nf].type_var_func[0]);
		act2.scope.push_back(VD[nf].scope[0]);
		act2.SCOPE = VD[nf].scope[0];
		if (VD[nf].size_param[0] == 1) {
			Set_Action_all_variable(act2, act.num_action[i + 1], -1, -1, mult, mult, "", vr);

		}
		else if (VD[nf].size_param[0] == 2) {
			Set_Action_all_variable(act2, act.num_action[i + 1], act.num_action[i + 2], -1, mult, mult, "", vr);

		}
		else if (VD[nf].size_param[0] == 3) {
			Set_Action_all_variable(act2, act.num_action[i + 1], act.num_action[i + 2], act.num_action[i + 3], mult, mult, "", vr);

		}



	}
	else if (act.scope[I] == 4) {// 4
		
		nf = act.type_action[i]; fun = act.num_action[i];
		//cout << "bug 0 " << nf << " " << fun << " " << func[nf].div_func[fun].nb_param << endl;

		for (int j = 0; j < func[nf].div_func[fun].nb_param; j++) {
			//cout << "bug " << func[nf].div_func[fun].type_var_func[j] << " " << func[nf].div_func[fun].size_param[j] << endl;
			if (func[nf].div_func[fun].size_param[j] == 1) {
				if (func[nf].div_func[fun].type_var_func[j] == INT) {
					if (start)mult = get_INT(act, I);
					else mult /= get_INT(act, I);
					//cout << "getint " << get_INT(act, I) << " " << act.scope[I] << endl;;
				}
				else if (func[nf].div_func[fun].type_var_func[j] == DOUBLE) {
					if (start)mult = get_DOUBLE(act, I);
					else mult /= get_DOUBLE(act, I);
					//cout << "getdouble " << get_DOUBLE(act, I) << " " << act.scope[I] << endl;;
				}
				else if (func[nf].div_func[fun].type_var_func[j] == PNUMBER_INT) {
					mult /= func[nf].div_func[fun].cint[func[nf].div_func[fun].index_cint++];
					//cout << "pnumberint " << func[nf].div_func[fun].cint[func[nf].div_func[fun].index_cint - 1] << " " << act.scope[I] << endl;;
				}
				else if (func[nf].div_func[fun].type_var_func[j] == PNUMBER_DOUBLE) {
					mult /= func[nf].div_func[fun].cdouble[func[nf].div_func[fun].index_cdouble++];
					//cout << "pnumberdouble " << func[nf].div_func[fun].cdouble[func[nf].div_func[fun].index_cdouble - 1] << " " << act.scope[I] << endl;;
				}
				I++;

			}
			else if (func[nf].div_func[fun].size_param[j] == 2) {
				if (func[nf].div_func[fun].type_var_func[j] == INT || func[nf].div_func[fun].type_var_func[j] == VINT) {
					//cout << "getint2 " << get_INT2(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT2(act, I);
					else mult /= get_INT2(act, I);
				}
				else if (func[nf].div_func[fun].type_var_func[j] == DOUBLE || func[nf].div_func[fun].type_var_func[j] == VDOUBLE) {
					if (start)mult = get_DOUBLE2(act, I);
					else mult /= get_DOUBLE2(act, I);
					//cout << "getdouble2 " << get_DOUBLE2(act, I) << " " << act.scope[I] << endl;;
				}

				I += 2;
			}
			else if (func[nf].div_func[fun].size_param[j] == 3) {
				if (func[nf].div_func[fun].type_var_func[j] == INT || func[nf].div_func[fun].type_var_func[j] == VINT || func[nf].div_func[fun].type_var_func[j] == FV_INT) {
					//cout << "getint3 " << get_INT3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT3(act, I);
					else mult /= get_INT3(act, I);
				}
				else if (func[nf].div_func[fun].type_var_func[j] == DOUBLE || func[nf].div_func[fun].type_var_func[j] == VDOUBLE || func[nf].div_func[fun].type_var_func[j] == FV_DOUBLE) {
					//cout << "getdouble3 " << get_DOUBLE3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_DOUBLE3(act, I);
					else mult /= get_DOUBLE3(act, I);
				}
				I += 3;
			}

		}

		var_class vr;
		Action act2;
		act2.type_action.push_back(func[nf].div_func[fun].type_var_func[0]);
		act2.scope.push_back(func[nf].div_func[fun].scope[0]);
		act2.SCOPE = func[nf].div_func[fun].scope[0];
		if (func[nf].div_func[fun].size_param[0] == 1) {
			Set_Action_all_variable(act2, act.num_action[i + 1], -1, -1, mult, mult, "", vr);

		}
		else if (func[nf].div_func[fun].size_param[0] == 2) {
			Set_Action_all_variable(act2, act.num_action[i + 1], act.num_action[i + 2], -1, mult, mult, "", vr);

		}
		else if (func[nf].div_func[fun].size_param[0] == 3) {
			Set_Action_all_variable(act2, act.num_action[i + 1], act.num_action[i + 2], act.num_action[i + 3], mult, mult, "", vr);

		}


	}
	else if (act.scope[I] == 5) {
		
		nf = act.type_action[i]; fun = act.num_action[i]; cfun = act.num_action[i + 1]; I++;
		//cout << "bug 5 " << nf << " " << fun << " " << cfun << endl;

		for (int j = 0; j < DC[nf].func[fun].div_func[cfun].nb_param; j++) {
			//cout << "bug " << DC[nf].func[fun].div_func[cfun].type_var_func[j] << " " << DC[nf].func[fun].div_func[cfun].size_param[j] << endl;
			if (DC[nf].func[fun].div_func[cfun].size_param[j] == 1) {
				if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == INT) {
					if (start)mult = get_INT(act, I);
					else mult /= get_INT(act, I);
					//cout << "getint " << get_INT(act, I) << " " << act.scope[I] << endl;;
				}
				else if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == DOUBLE) {
					if (start)mult = get_DOUBLE(act, I);
					else mult /= get_DOUBLE(act, I);
					//cout << "getdouble " << get_DOUBLE(act, I) << " " << act.scope[I] << endl;;
				}
				else if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == PNUMBER_INT) {
					mult /= DC[nf].func[fun].div_func[cfun].cint[DC[nf].func[fun].div_func[cfun].index_cint++];
					//cout << "pnumberint " << DC[nf].func[fun].div_func[cfun].cint[DC[nf].func[fun].div_func[cfun].index_cint - 1] << " " << act.scope[I] << endl;;
				}
				else if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == PNUMBER_DOUBLE) {
					mult /= DC[nf].func[fun].div_func[cfun].cdouble[DC[nf].func[fun].div_func[cfun].index_cdouble++];
					//cout << "pnumberdouble " << DC[nf].func[fun].div_func[cfun].cdouble[DC[nf].func[fun].div_func[cfun].index_cdouble - 1] << " " << act.scope[I] << endl;;
				}
				I++;

			}
			else if (DC[nf].func[fun].div_func[cfun].size_param[j] == 2) {
				if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == INT || DC[nf].func[fun].div_func[cfun].type_var_func[j] == VINT) {
					//cout << "getint2 " << get_INT2(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT2(act, I);
					else mult /= get_INT2(act, I);
				}
				else if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == DOUBLE || DC[nf].func[fun].div_func[cfun].type_var_func[j] == VDOUBLE) {
					if (start)mult = get_DOUBLE2(act, I);
					else mult /= get_DOUBLE2(act, I);
					//cout << "getdouble2 " << get_DOUBLE2(act, I) << " " << act.scope[I] << endl;;
				}

				I += 2;
			}
			else if (DC[nf].func[fun].div_func[cfun].size_param[j] == 3) {
				if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == INT || DC[nf].func[fun].div_func[cfun].type_var_func[j] == VINT || DC[nf].func[fun].div_func[cfun].type_var_func[j] == FV_INT) {
					//cout << "getint3 " << get_INT3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_INT3(act, I);
					else mult /= get_INT3(act, I);
				}
				else if (DC[nf].func[fun].div_func[cfun].type_var_func[j] == DOUBLE || DC[nf].func[fun].div_func[cfun].type_var_func[j] == VDOUBLE || DC[nf].func[fun].div_func[cfun].type_var_func[j] == FV_DOUBLE) {
					//cout << "getdouble3 " << get_DOUBLE3(act, I) << " " << act.scope[I] << endl;;
					if (start)mult = get_DOUBLE3(act, I);
					else mult /= get_DOUBLE3(act, I);
				}
				I += 3;
			}

		}

		var_class vr;
		Action act2;
		act2.type_action.push_back(DC[nf].func[fun].div_func[cfun].type_var_func[0]);
		act2.scope.push_back(DC[nf].func[fun].div_func[cfun].scope[0]);
		act2.SCOPE = DC[nf].func[fun].div_func[cfun].scope[0];
		if (DC[nf].func[fun].div_func[cfun].size_param[0] == 1) {
			Set_Action_all_variable(act2, act.num_action[i + 2], -1, -1, mult, mult, "", vr);

		}
		else if (DC[nf].func[fun].div_func[cfun].size_param[0] == 2) {
			Set_Action_all_variable(act2, act.num_action[i + 2], act.num_action[i + 3], -1, mult, mult, "", vr);

		}
		else if (DC[nf].func[fun].div_func[cfun].size_param[0] == 3) {
			Set_Action_all_variable(act2, act.num_action[i + 2], act.num_action[i + 3], act.num_action[i + 4], mult, mult, "", vr);

		}

		action.I = 1;
	}




	//cout << "DIVVVVV " << mult << " " << act.SCOPE << endl;

}







#endif