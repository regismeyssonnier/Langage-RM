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
		}
		else {

			cout << "ERROR1 aucune variable de ce nom existe." << endl;

		}
		

	}
	else if (SCOPE == 4) {
		//
		//func[n].action.action.push_back(ACTION);
		

		/*if (Existe(func[n].var.vclass, mod, ret)) {
			action.action.push_back(ACTION);
			action.type_action.push_back(VCLASS);
			action.num_action.push_back(ret);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			if (Existe(DC[ret].var.doubles, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				action.action.push_back(ACTION);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				action.action.push_back(ACTION);
				action.type_action.push_back(VINT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				action.action.push_back(ACTION);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else {
				cout << "ERROR1 aucune variable de ce nom existe pour cette classe." << endl;
			}



			func[n].action.type_action.push_back(VCLASS);
			func[n].action.num_action.push_back(ret);
		}*/


		int n = func.size() - 1;
		Action action;
		action.action.push_back(ACTION);
		action.type_action.push_back(FUNC_VAR);
		action.num_action.push_back(n);
		action.scope.push_back(SCOPE);
		actionv.push_back(action);

		 if (Existe(func[n].var.integers, mod, ret)) {
			 Action action;
			 action.action.push_back(ACTION);
			 action.type_action.push_back(INT);
			 action.num_action.push_back(ret);
			 action.scope.push_back(SCOPE);
			 actionv.push_back(action);
		}
		else if (Existe(func[n].var.doubles, mod, ret)) {
			 Action action;
			 action.action.push_back(ACTION);
			 action.type_action.push_back(DOUBLE);
			 action.num_action.push_back(n);
			 action.scope.push_back(SCOPE);
			 actionv.push_back(action);
		}
		else if (Existe(func[n].var.strings, mod, ret)) {
			 Action action;
			 action.action.push_back(ACTION);
			 action.type_action.push_back(STRING);
			 action.num_action.push_back(ret);
			 action.scope.push_back(SCOPE);
			 actionv.push_back(action);
		}
		
	}
	else if (SCOPE == 5) {
		int dn = DC.size() - 1;
		int n = DC[dn].func.size() - 1;

		/*f(Existe(DC[dn].func[n].var.vclass, mod, ret)) {
			DC[dn].func[n].action.action.push_back(ACTION);
			DC[dn].func[n].action.type_action.push_back(VCLASS);
			DC[dn].func[n].action.num_action.push_back(ret);
			DC[dn].func[n].action.scope.push_back(2);
		}
		else*/
		Action action;
		action.action.push_back(ACTION);
		action.type_action.push_back(FUNC_VAR2);
		action.num_action.push_back(dn);
		action.scope.push_back(SCOPE);
		actionv.push_back(action);

		

		if (Existe(DC[dn].func[n].var.integers, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(INT);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].func[n].var.doubles, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(DOUBLE);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].func[n].var.strings, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(STRING);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		//---------------------------------------------
		else if (Existe(DC[dn].var.vclass, modvc, ret)) {
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
				action.type_action.push_back(DOUBLE);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(DC[ret].var.integers, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(INT);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else if (Existe(DC[ret].var.strings, varvc, ret2)) {
				//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
				Action action;
				action.action.push_back(ACTION);
				action.type_action.push_back(STRING);
				action.num_action.push_back(ret2);
				action.scope.push_back(SCOPE);
				actionv.push_back(action);
			}
			else {
				cout << "ERROR5 aucune variable de ce nom existe pour cette classe." << endl;
			}

	
		}
		else if (Existe(DC[dn].var.integers, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(INT);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].var.doubles, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);
			Action action2;
			action2.action.push_back(ACTION);
			action2.type_action.push_back(DOUBLE);
			action2.num_action.push_back(ret);
			action2.scope.push_back(SCOPE);
			actionv.push_back(action2);
		}
		else if (Existe(DC[dn].var.strings, mod, ret)) {
			Action action;
			action.action.push_back(ACTION);
			action.type_action.push_back(FUNC_VAR);
			action.num_action.push_back(n);
			action.scope.push_back(SCOPE);
			actionv.push_back(action);

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
		
		if (act.type_action[0] == VCLASS) {
			

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

		if (act.type_action[0] == VCLASS) {
			//rv = DC[dn].func[n].
		}
		else if (act.type_action[0] == INT) {
			ri = DC[ret].func[ret2].var.integer_val[ret3];
			typer = INT;
		}
		else if (act.type_action[0] == DOUBLE) {
			rd = DC[ret].func[ret2].var.double_val[ret3];
			typer = DOUBLE;
		}
		else if (act.type_action[0] == STRING) {
			rs = DC[ret].func[ret2].var.pstring[ret3];
			typer = STRING;
		}

	}

		
}


/*





if (action.scope[i] == 1 || action.scope[i] == 3) {
				if (action.type_action[i + 1] == VCLASS) {
					act.type_action.push_back(action.num_action[i + 2]);
					act.scope.push_back(action.SCOPE);
					if (action.type_action[i + 2] == VDOUBLE) {

						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);

					}
					else if (action.type_action[i + 1] == VINT) {

						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);

					}
					else if (action.type_action[i + 1] == VSTRING) {

						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);

					}

				}
				else if (action.type_action[i+1] == INT) {
					act.type_action.push_back(action.num_action[i + 1]);
					act.scope.push_back(action.SCOPE);

					cout << "rip " << action.action[i + 1] << " " << action.type_action[i + 1] << " " << action.num_action[i+1] << " " << action.scope[i+1] << endl;
					Action_all_variable(act, action.num_action[i + 1], -1, -1, ri, rd, rs, rv);
					cout << "ri " << ri << endl;
				}
				else if (action.type_action[i+1] == DOUBLE) {
					act.type_action.push_back(action.num_action[i + 1]);
					act.scope.push_back(action.SCOPE);

					cout << "rdp "<< action.action[i + 1] << " " << action.type_action[i + 1] << " " << action.num_action[i+1] << " " << action.scope[i+1] << endl;
					Action_all_variable(act, action.num_action[i + 1], -1, -1, ri, rd, rs, rv);
					cout << "rd " << rd << endl;
				}
				else if (action.type_action[i+1] == STRING) {
					act.type_action.push_back(action.num_action[i + 1]);
					act.scope.push_back(action.SCOPE);
					Action_all_variable(act, action.num_action[i + 1], -1, -1, ri, rd, rs, rv);
				}

			}
			else if (action.scope[i] == 4) {
				if (action.type_action[i + 1] == FUNC_VAR) {
					act.type_action.push_back(action.num_action[i + 2]);
					act.scope.push_back(action.SCOPE);
					if (action.type_action[i + 2] == INT) {
						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);
					}
					else if (action.type_action[i + 2] == DOUBLE) {
						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);
					}
					else if (action.type_action[i + 2] == STRING) {
						Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], -1, ri, rd, rs, rv);
					}

				}

			}
			else if (action.scope[i] == 5) {
				if (action.type_action[i + 1] == FUNC_VAR2) {
					if (action.type_action[i + 2] == FUNC_VAR) {
						act.type_action.push_back(action.num_action[i + 3]);
						act.scope.push_back(action.SCOPE);
						if (action.type_action[i + 3] == INT) {
							Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], action.num_action[i + 3], ri, rd, rs, rv);
						}
						else if (action.type_action[i + 3] == DOUBLE) {
							Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], action.num_action[i + 3], ri, rd, rs, rv);
						}
						else if (action.type_action[i + 3] == STRING) {
							Action_all_variable(act, action.num_action[i + 1], action.num_action[i + 2], action.num_action[i + 3], ri, rd, rs, rv);
						}

					}

				}

			}







*/



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
	act.scope.push_back(action.scope[I]);

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
	act.scope.push_back(action.scope[I]);

	//cout << "rip3 " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I + 1], action.num_action[I + 2], ri, rd, rs, rv, typer);

	return ri;
}

double get_DOUBLE(Action ac, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I]);
	act.scope.push_back(action.scope[I]);

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], -1, -1, ri, rd, rs, rv, typer);

	return rd;
}

double get_DOUBLE2(Action ac, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+1]);
	act.scope.push_back(action.scope[I]);

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I+1], -1, ri, rd, rs, rv, typer);

	return rd;
}


double get_DOUBLE3(Action ac, int I) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int typer;
	Action act;

	act.type_action.push_back(action.type_action[I+2]);
	act.scope.push_back(action.scope[I]);

	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	Action_all_variable(act, action.num_action[I], action.num_action[I+1], action.num_action[I+2], ri, rd, rs, rv, typer);

	return rd;
}



#endif // !FUNCTION_RM_HEADER
