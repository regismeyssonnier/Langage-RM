#pragma once
#ifndef FUNCTION_RM_HEADER
#define FUNCTION_RM_HEADER

#include <iostream>
#include <fstream>
using namespace std;

#include <string>
#include <vector>
#include <map>
#include <stack>
#include <deque>

#include "rm_header.h"




vector<Action> Detect_all_variable(string l, string mod, int ACTION, int SCOPE) {
	//cout << l << "== " << mod << endl;
	string modvc;
	string varvc;
	size_t fdvc = l.find_last_of("--");
	if (fdvc != string::npos) {
		modvc = l.substr(0, fdvc - 1);

		varvc = l.substr(fdvc + 1, l.length());
		size_t fdvvc = varvc.find_last_of(";");
		if (fdvvc != string::npos) {
			varvc = varvc.substr(0, varvc.length() - 1);
		}
		//cout << modvc << " -+- " << varvc << endl;
	}

	int ret;

	
	vector<Action> actionv;


	if (SCOPE == 1 || SCOPE == 3) {
		

		if (Existe(VC.var.vclass, modvc, ret)) {
			//cout << "PRINT CLASS" << varvc <<  endl;
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(VCLASS);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			int ret2;
			//for (auto e : DC[ret].var.doubles)cout << "--e " <<e.first << endl;
			if (Existe(DC[ret].var.doubles, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
				//cout << "VDOUBLE" << endl;
			
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VINT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
				//cout << "VVVVIIINTTTTTTTTTTT" <<  endl;
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else {
				cout << "ERROR1 aucune variable de ce nom existe pour cette classe." << endl;
			}


		}
		else if (Existe(VG.integers, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(INT);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
		}
		else if (Existe(VG.doubles, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(DOUBLE);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
		}
		else if (Existe(VG.strings, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(STRING);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
			cout << "STRING " << mod << endl;
		}
		else {

			cout << "ERROR1 aucune variable de ce nom existe." << endl;

		}
		

	}
	else if (SCOPE == 4) {
		//
		//
		int n = func.size() - 1;
		int ret2;

		//func[n].action.action.push_back(ACTION);

		if (Existe(func[n].var.vclass, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(VCLASS);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			if (Existe(DC[ret].var.doubles, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VINT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else {
				cout << "ERROR1 aucune variable de ce nom existe pour cette classe." << endl;
			}



			//func[n].action.type_action.push_back(VCLASS);
			//func[n].action.num_action.push_back(ret);
			//func[n].action.scope.push_back(SCOPE);
		}
		else {


			

			if (Existe(func[n].var.integers, mod, ret)) {
				Action action0;
				action0.action.push_back(ACTION);
				action0.type_action.push_back(FUNC_VAR);
				action0.num_action.push_back(n);
				action0.scope.push_back(SCOPE);
				actionv.push_back(action0);

				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(INT);
				action.num_action.push_back(ret);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(func[n].var.doubles, mod, ret)) {
				Action action0;
				action0.action.push_back(ACTION);
				action0.type_action.push_back(FUNC_VAR);
				action0.num_action.push_back(n);
				action0.scope.push_back(SCOPE);
				actionv.push_back(action0);

				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(DOUBLE);
				action.num_action.push_back(n);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(func[n].var.strings, mod, ret)) {
				Action action0;
				action0.action.push_back(ACTION);
				action0.type_action.push_back(FUNC_VAR);
				action0.num_action.push_back(n);
				action0.scope.push_back(SCOPE);
				actionv.push_back(action0);

				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(STRING);
				action.num_action.push_back(ret);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}

		}
		
	}
	else if (SCOPE == 5) {
		int dn = DC.size() - 1;
		int n = DC[dn].func.size() - 1;
		int ret2;
		/*f(Existe(DC[dn].func[n].var.vclass, mod, ret)) {
			DC[dn].func[n].action.action.push_back(ACTION);
			DC[dn].func[n].action.type_action.push_back(VCLASS);
			DC[dn].func[n].action.num_action.push_back(ret);
			DC[dn].func[n].action.scope.push_back(2);
		}
		else*/
		

		
		if(Existe(DC[dn].func[n].var.vclass, mod, ret)) {

			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR2);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);
			
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(VCLASS);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			if (Existe(DC[ret].var.doubles, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VINT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				return actionv;
			}
			else {
				cout << "ERROR1 aucune variable de ce nom existe pour cette classe." << endl;
			}



		}
		else if (Existe(DC[dn].func[n].var.integers, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR2);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(FV_INT);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].func[n].var.doubles, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR2);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(FV_DOUBLE);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].func[n].var.strings, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR2);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(FV_STRING);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		//---------------------------------------------
		else if (Existe(DC[dn].var.vclass, modvc, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR2);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(VCLASS);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
			//if (Existe(VC.var.vclass, l.substr(0, fd - 1), ret)) {
			int ret2;
			if (Existe(DC[ret].var.doubles, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

			
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VINT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);

				
			}
			else {
				cout << "ERROR5 aucune variable de ce nom existe pour cette classe." << endl;
			}

	
		}
		else if (Existe(DC[dn].var.integers, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			/*Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);*/
			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(INT);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].var.doubles, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);

			/*Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);*/
			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(DOUBLE);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].var.strings, mod, ret)) {
			Action action0;
			action0.action.push_back(ACTION);
			action0.type_action.push_back(FUNC_VAR);
			action0.num_action.push_back(dn);
			action0.scope.push_back(SCOPE);
			actionv.push_back(action0);
			
			/*Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);*/

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(STRING);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);


		}
		

	}

	return actionv;


}



void Action_all_variable(Action act, int ret, int ret2, int ret3, int &ri, double  &rd, string &rs, var_class &rv, int &typer) {

		

	if (act.SCOPE == 1 || act.SCOPE == 3) {
	
			if(act.type_action[0] == VDOUBLE){

				rd =  DC[ret].var.double_val[ret2];
				typer = VDOUBLE;
			}
			else if (act.type_action[0] == VINT) {
				ri =  DC[ret].var.integer_val[ret2];
				typer = VINT;
			}
			else if (act.type_action[0] == VSTRING) {
				rs = DC[ret].var.pstring[ret2];
				typer = VSTRING;
			}
			else if (act.type_action[0] == INT) {
				ri = VG.integer_val[ret];
				typer = INT;
				//cout << "integer--------" << endl;
			}
			else if (act.type_action[0] == DOUBLE) {
				rd = VG.double_val[ret];
				typer = DOUBLE;
				//cout<< "-----------------========"<<rd << endl;
			}
			else if (act.type_action[0] == STRING) {
				rs = VG.pstring[ret];
				typer = STRING;
			}
			else {
				cout << "ERROR 1 : Action_all_variable " << endl;
				typer = -1;
			}
			//cout << "ici " << endl;
	}
	else if (act.SCOPE == 4) {
		
		if (act.type_action[0] == VDOUBLE) {

			rd = DC[ret2].var.double_val[ret3];
			typer = VDOUBLE;

		}
		else if (act.type_action[0] == VINT) {

			ri = DC[ret2].var.integer_val[ret3];
			typer = VINT;

		}
		else if (act.type_action[0] == VSTRING) {

			rs = DC[ret2].var.pstring[ret3];
			typer = VSTRING;

		}
		else if (act.type_action[0] == INT) {

			ri = func[ret].var.integer_val[ret2];
			typer = INT;
		}
		else if (act.type_action[0] == DOUBLE) {

			rd = func[ret].var.double_val[ret2];
			typer = DOUBLE;
		}
		else if (act.type_action[0] == STRING) {

			rs = func[ret].var.pstring[ret2];
			typer = STRING;
		}
		
		
	}
	else if (act.SCOPE == 5) {

		if (act.type_action[0] == VDOUBLE) {
			rd = DC[ret].var.double_val[ret2];
			typer = VDOUBLE;
		}
		else if (act.type_action[0] == VINT) {
			ri = DC[ret].var.integer_val[ret2];
			typer = VINT;
		}
		else if (act.type_action[0] == VSTRING) {
			rs = DC[ret].var.pstring[ret2];
			typer = VSTRING;
		}
		else if (act.type_action[0] == FV_INT) {
			ri = DC[ret].func[ret2].var.integer_val[ret3];
			typer = FV_INT;
		}
		else if (act.type_action[0] == FV_DOUBLE) {
			rd = DC[ret].func[ret2].var.double_val[ret3];
			typer = FV_DOUBLE;
		}
		else if (act.type_action[0] == FV_STRING) {
			rs = DC[ret].func[ret2].var.pstring[ret3];
			typer = FV_INT;
		}
		else if (act.type_action[0] == INT) {
			ri = DC[ret].var.integer_val[ret2];
			typer = INT;
		}
		else if (act.type_action[0] == DOUBLE) {
			rd = DC[ret].var.double_val[ret2];
			typer = DOUBLE;
		}
		else if (act.type_action[0] == STRING) {
			rs = DC[ret].var.pstring[ret2];
			typer = STRING;
		}

	}

		
}

void Set_Action_all_variable(Action act, int ret, int ret2, int ret3, int ri, double rd, string rs, var_class rv) {



	if (act.SCOPE == 1 || act.SCOPE == 3) {

		if (act.type_action[0] == VDOUBLE) {

			DC[ret].var.double_val[ret2] = rd;
			
		}
		else if (act.type_action[0] == VINT) {
			DC[ret].var.integer_val[ret2]=ri;
		
		}
		else if (act.type_action[0] == VSTRING) {
			DC[ret].var.pstring[ret2] = rs;
			
		}
		else if (act.type_action[0] == INT) {
			VG.integer_val[ret] = ri;
			
		}
		else if (act.type_action[0] == DOUBLE) {
			VG.double_val[ret] = rd;
			
		}
		else if (act.type_action[0] == STRING) {
			VG.pstring[ret] = rs;
			
		}
		else {
			cout << "ERROR 1 :Set Action_all_variable " << endl;
			
		}
		//cout << "ici " << endl;
	}
	else if (act.SCOPE == 4) {

		if (act.type_action[0] == VDOUBLE) {

			DC[ret2].var.double_val[ret3] = rd;
		
		}
		else if (act.type_action[0] == VINT) {

			DC[ret2].var.integer_val[ret3] = ri;
			

		}
		else if (act.type_action[0] == VSTRING) {

			DC[ret2].var.pstring[ret3] = rs;
			

		}
		else if (act.type_action[0] == INT) {

			func[ret].var.integer_val[ret2] = ri;
			
		}
		else if (act.type_action[0] == DOUBLE) {

			func[ret].var.double_val[ret2] = rd;
			
		}
		else if (act.type_action[0] == STRING) {

			func[ret].var.pstring[ret2] = rs;
			
		}


	}
	else if (act.SCOPE == 5) {

		if (act.type_action[0] == VDOUBLE) {
			DC[ret].var.double_val[ret2]= rd;
			
		}
		else if (act.type_action[0] == VINT) {
			DC[ret].var.integer_val[ret2] = ri;
			
		}
		else if (act.type_action[0] == VSTRING) {
			DC[ret].var.pstring[ret2] = rs;
			
		}
		else if (act.type_action[0] == FV_INT) {
			DC[ret].func[ret2].var.integer_val[ret3] = ri;
			
		}
		else if (act.type_action[0] == FV_DOUBLE) {
			DC[ret].func[ret2].var.double_val[ret3] = rd;
			
		}
		else if (act.type_action[0] == FV_STRING) {
			DC[ret].func[ret2].var.pstring[ret3] = rs;
			
		}
		else if (act.type_action[0] == INT) {
			DC[ret].var.integer_val[ret2] = ri;
			
		}
		else if (act.type_action[0] == DOUBLE) {
			DC[ret].var.double_val[ret2] = rd;
			
		}
		else if (act.type_action[0] == STRING) {
			DC[ret].var.pstring[ret2] = rs;
			
		}

	}


}



void while_func(Action action, int I, int& ri, double& rd, string& rs, var_class& rv, int &typer) {

	Action act;
	
	//cout << "action scope " << action.scope[I] << endl;

	if (action.scope[I] == 1 || action.scope[I] == 3) {
		if (action.type_action[I+1] == VDOUBLE) {
			act.type_action.push_back(VDOUBLE);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);
			//cout << "while func vdouble " << endl;
		}
		else if (action.type_action[I+1] == VINT) {
			act.type_action.push_back(VINT);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
			//cout << "while func vint " << endl;
		}
		else if (action.type_action[I+1] == VSTRING) {
			act.type_action.push_back(VSTRING);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else if (action.type_action[I] == INT) {
			act.type_action.push_back(INT);
			act.scope.push_back(action.scope[I]);
			//cout << "while func int " << endl;
			//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);
			//cout << "ri " << ri << endl;
		}
		else if (action.type_action[I] == DOUBLE) {
			act.type_action.push_back(DOUBLE);
			act.scope.push_back(action.scope[I]);
			//cout << "while func double " << endl;
			//cout << "--rdp " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);
			//cout << "rd " << rd << endl;
		}
	}
	else if(action.scope[I] == 4) {
		/*if (action.type_action[I] == VDOUBLE) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else if (action.type_action[I] == VINT) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else if (action.type_action[I] == VSTRING) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else*/ if (action.type_action[I+1] == INT) {
			act.type_action.push_back(INT);
			act.scope.push_back(action.scope[I]);

			//cout << "1rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);
			//cout << "ri " << ri << endl;
		}
		else if (action.type_action[I+1] == DOUBLE) {
			act.type_action.push_back(DOUBLE);
			act.scope.push_back(action.scope[I]);

			//cout << "--rdp " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);
			///cout << "rd " << rd << endl;
		}

	}
	else if (action.scope[I] == 5) {
		/*if (action.type_action[I] == VDOUBLE) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else if (action.type_action[I] == VINT) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else if (action.type_action[I] == VSTRING) {
			act.type_action.push_back(action.type_action[I]);
			act.scope.push_back(action.scope[I]);

			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);
		}
		else*/ if (action.type_action[I+2] == INT) {
			act.type_action.push_back(INT);
			act.scope.push_back(action.scope[I]);

			//cout << "0rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], action.num_action[I + 1], action.num_action[I + 2], ri, rd, rs, rv, typer);
			//cout << "ri " << ri << endl;
		}
		else if (action.type_action[I+2] == DOUBLE) {
			act.type_action.push_back(DOUBLE);
			act.scope.push_back(action.scope[I]);

			//cout << "--rdp " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			Action_all_variable(act, action.num_action[I], action.num_action[I+ 1] , action.num_action[I + 2], ri, rd, rs, rv, typer);
			//cout << "rd " << rd << endl;
		}

	}

}


int get_INT(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I]);
	act.scope.push_back(action.scope[I]);
	act.SCOPE = action.scope[I];

	//cout << "rip1 " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);

	return ri;
}

int get_INT2(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+1]);
	act.scope.push_back(action.scope[I+1]);
	act.SCOPE = action.scope[I+1];

	//cout << "rip2 " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);

	return ri;
}

int get_INT3(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+2]);
	act.scope.push_back(action.scope[I+2]);
	act.SCOPE = action.scope[I+2];

	//cout << "rip3 " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I + 1], action.num_action[I + 2], ri, rd, rs, rv, typer);

	return ri;
}

double get_DOUBLE(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I]);
	act.scope.push_back(action.scope[I]);
	act.SCOPE = action.scope[I];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);

	return rd;
}

double get_DOUBLE2(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+1]);
	act.scope.push_back(action.scope[I+1]);
	act.SCOPE = action.scope[I+1];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);

	return rd;
}


double get_DOUBLE3(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+2]);
	act.scope.push_back(action.scope[I+2]);
	act.SCOPE = action.scope[I+2];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I+1], action.num_action[I+2], ri, rd, rs, rv, typer);

	return rd;
}

string get_STRING(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I]);
	act.scope.push_back(action.scope[I]);
	act.SCOPE = action.scope[I];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);

	return rs;
}

string get_STRING2(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I + 1]);
	act.scope.push_back(action.scope[I + 1]);
	act.SCOPE = action.scope[I + 1];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I + 1], -1, ri, rd, rs, rv, typer);

	return rs;
}


string get_STRING3(Action action, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I + 2]);
	act.scope.push_back(action.scope[I + 2]);
	act.SCOPE = action.scope[I + 2];

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I + 1], action.num_action[I + 2], ri, rd, rs, rv, typer);

	return rs;
}


template <class T>
vector<int> Condition_pass(int i, int ind_while, T WR) {

	Action act;
	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;

	vector<int>param;
	//cout << "taille " << WR[ind_while].type_param.size() << endl;
	//cout << "taille " << WR[ind_while].nb_by_param.size() << endl;
	//cout << "taille " << WR[ind_while].I_start.size() << endl;

	//cout << "INDWHILE " << ind_while << endl; system("pause");

	int j = 0;
	for (int i = 0; i < WR[ind_while].type_param.size(); i++) {
		//cout << WR[ind_while].type_param[i] << endl;
		if (WR[ind_while].type_param[i] == VCLASS) {
			if (WR[ind_while].type_param[i + 1] == VINT) {
				action.I_start = WR[ind_while].I_start[j];
				action.I_end = WR[ind_while].I_end[j];
				int no = 0;
				if (WR[ind_while].nb_by_param[j] == 1) {
					no = get_INT(action, WR[ind_while].I_start[j]);
				}
				else if (WR[ind_while].nb_by_param[j] == 2) {
					no = get_INT2(action, WR[ind_while].I_start[j]);
				}
				else if (WR[ind_while].nb_by_param[j] == 3) {
					no = get_INT3(action, WR[ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}
			else if (WR[ind_while].type_param[i + 1] == VDOUBLE) {
				action.I_start = WR[ind_while].I_start[j];
				action.I_end = WR[ind_while].I_end[j];
				int no = 0;
				if (WR[ind_while].nb_by_param[j] == 1) {
					no = get_DOUBLE(action, WR[ind_while].I_start[j]);
				}
				else if (WR[ind_while].nb_by_param[j] == 2) {
					no = get_DOUBLE2(action, WR[ind_while].I_start[j]);
				}
				else if (WR[ind_while].nb_by_param[j] == 3) {
					no = get_DOUBLE3(action, WR[ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}


		}
		else if (WR[ind_while].type_param[i] == INT) {
			action.I_start = WR[ind_while].I_start[j];
			action.I_end = WR[ind_while].I_end[j];
			int no = 0;
			if (WR[ind_while].nb_by_param[j] == 1) {
				no = get_INT(action, WR[ind_while].I_start[j]);
			}
			else if (WR[ind_while].nb_by_param[j] == 2) {
				no = get_INT2(action, WR[ind_while].I_start[j]);
			}
			else if (WR[ind_while].nb_by_param[j] == 3) {
				no = get_INT3(action, WR[ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;

		}
		else if (WR[ind_while].type_param[i] == DOUBLE) {
			action.I_start = WR[ind_while].I_start[j];
			action.I_end = WR[ind_while].I_end[j];
			int no = 0;
			if (WR[ind_while].nb_by_param[j] == 1) {
				//cout << "getdpouble 1 " << endl;
				no = get_DOUBLE(action, WR[ind_while].I_start[j]);
			}
			else if (WR[ind_while].nb_by_param[j] == 2) {
				no = get_DOUBLE2(action, WR[ind_while].I_start[j]);
			}
			else if (WR[ind_while].nb_by_param[j] == 3) {
				no = get_DOUBLE3(action, WR[ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;
		}

		//cout << i << " " << j << endl;
	}

	//cout << "p1 " << param[0] << " p2 " << param[1] << endl;
	//system("pause");

	return param;


}


#endif // !FUNCTION_RM_HEADER
