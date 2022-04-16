#pragma once
#ifndef WHILEIFRM
#define WHILEIFRM

#include "rm_header.h"
#include "function_rm.h"

void while_rm_op() {

	
	//exec = true;
	string var1;
	input >> var1;

	string cond;
	input >> cond;

	string var2;
	input >> var2;

	//cout << "var1 " << var1 << " " << " var2 " << var2 << endl;
	while_rm w;

	int nf = func.size() - 1;

	vector<Action> a1 = Detect_all_variable(var1, var1, WHILE_PAR, action.SCOPE);
	vector<Action> a2 = Detect_all_variable(var2, var2, WHILE_PAR, action.SCOPE);
	Register_Func_Action(nf, WHILE, WR.size(), 2, action.SCOPE);
	Register_Func_Action(nf, WHILE, WHILE, a1.size(), action.SCOPE);
	Register_Func_Action(nf, WHILE, WHILE, a2.size(), action.SCOPE);
	for (int i = 0; i < a1.size(); i++) {
		Register_Func_Action(nf, a1[i].action[0], a1[i].type_action[0], a1[i].num_action[0], a1[i].scope[0]);
		//cout << "reg " << a1[i].action[0] << " " << a1[i].type_action[0] << " " << a1[i].num_action[0] << " " << a1[i].scope[0] << endl;
	}
	for (int i = 0; i < a2.size(); i++) {
		Register_Func_Action(nf, a2[i].action[0], a2[i].type_action[0], a2[i].num_action[0], a2[i].scope[0]);
		//cout << "reg " << a2[i].action[0] << " " << a2[i].type_action[0] << " " << a2[i].num_action[0] << " " << a2[i].scope[0] << endl;
	}
	//Register_Action(a1.action[0], a1.type_action[0], a1.num_action[0], a1.scope[0]);
	//Register_Action(a2.action[0], a2.type_action[0], a2.num_action[0], a2.scope[0]);
	int condt;
	if (cond == "==")condt = EQ;
	else if (cond == "<")condt = INF;
	else if (cond == "<=")condt = INFEQ;
	else if (cond == ">")condt = SUP;
	else if (cond == ">=")condt = SUPEQ;
	Register_Func_Action(nf, WHILE_COND, condt, 0, action.SCOPE);
	w.cond = condt;
	w.inst_start = func[nf].action.action.size();
	//WR.push_back(w);
	func[nf].while_struct.WR.push_back(w);
	//cout << a1.action[0] << " " << a1.type_action[0] << " " << a1.num_action[0] << " " << a1.scope[0] << endl;
	//cout << a2[i].action[0] << " " << a2[i].type_action[0] << " " << a2[i].num_action[0] << " " << a2[i].scope[0] << endl;
	//end_while++;

	//cout << "while" << endl;

	//cout << "error" << endl;
	Node* n = new Node();
	n->indice = func[nf].while_struct.REPR_INDW;
	n->father = func[nf].while_struct.father_wf;
	func[nf].while_struct.ANWF.push_back(n);
	if (func[nf].while_struct.father_wf != nullptr) {
		func[nf].while_struct.father_wf->son.push_back(n);
		func[nf].while_struct.father_wf = n;
	}
	else {
		func[nf].while_struct.father_wf = n;
	}
	//cout << "error pass " << endl;


	func[nf].while_struct.ind_wd.push_front(func[nf].while_struct.REPR_INDW);
	func[nf].while_struct.IND_WHILE++;
	func[nf].while_struct.REPR_INDW++;
	func[nf].while_struct.DEPTH_INDW++;





}

void end_whilerm_op() {

	int nf = func.size() - 1;
	int n = func[nf].while_struct.WR.size() - 1;
	//cout << n - (n - end_while) - 1 << endl;
	func[nf].while_struct.WR[func[nf].while_struct.IND_WHILE].inst_end = func[nf].action.action.size();

	func[nf].while_struct.last_fwf = func[nf].while_struct.father_wf;
	func[nf].while_struct.father_wf = func[nf].while_struct.father_wf->father;
	if (func[nf].while_struct.father_wf == nullptr) {
		func[nf].while_struct.NWF.push_back(func[nf].while_struct.last_fwf);
	}


	//cout << "end while " << endl;
	func[nf].while_struct.IND_WHILE = func[nf].while_struct.ind_wd.front();
	func[nf].while_struct.ind_wd.pop_front();

	Register_Func_Action(nf, END_WHILE, END_WHILE, 0, action.SCOPE);

}


void whilerm_func_exec(Action action, int &i, int nf) {

	int ri;
	double rd;
	string rs;
	var_class rv;
	int cI = 3;
	Action act;
	int typer;

	
		
	int sz1 = action.num_action[i + 1];
	int sz2 = action.num_action[i + 2];

	// action.type_action[i];
		

	if (func[nf].while_struct.start_nw) {
		func[nf].while_struct.NWI->ind_nws = 0;
		func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;
		func[nf].while_struct.start_nw = false;
	}
	else if (func[nf].while_struct.NWI->son.size() > 0) {
		func[nf].while_struct.NWI = func[nf].while_struct.NWI->son[func[nf].while_struct.NWI->ind_nws];
		func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;
		//cout << "son " << endl;
	}
	

	int I = i + 3;
	//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
	int li = i + 3;
	//cout << I << " " << sz1 + li << endl;

	/*for (int j = I; j < action.action.size(); j++) {
		cout << "action: " <<j << " " << action.action[j] <<" " << action.type_action[j] << endl;
	}*/
	
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start.push_back(I);
	int scope = 0;
	for (; I < sz1 + li; I++) {
		while_func(action, I, ri, rd, rs, rv, typer);
	
		func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param.push_back(action.type_action[I]);
				
		cI++;
	}
	//cout << "type action i2 " << action.type_action[I] << " " << action.type_action[I + 1] << " " << action.type_action[I + 2] << endl;
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end.push_back(I);
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param.push_back(sz1);

	//cout << "--------------------------------" << endl;
	li = I;
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start.push_back(I);
	for (; I < sz2 + li; I++) {
		while_func(action, I, ri, rd, rs, rv, typer);
		
		func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param.push_back(action.type_action[I]);
		
		cI++;
	}
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end.push_back(I);
	func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param.push_back(sz2);

	//cout << "__________________________________________" << endl;


	if (action.action[I] == WHILE_COND) {
		cI++;
	}


	//cout <<"ind_while " << ind_while << endl;
	vector<int>param;

	int j = 0;
	for (int i = 0; i < func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param.size(); i++) {
		//cout << WR[ind_while].type_param[i] << endl;
		if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == VCLASS) {
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i + 1] == VINT) {
				action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
				action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
				int no = 0;
				if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
					no = get_INT(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
					no = get_INT2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
					no = get_INT3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i + 1] == VDOUBLE) {
				action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
				action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
				int no = 0;
				if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
					no = get_DOUBLE(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
					no = get_DOUBLE2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
					no = get_DOUBLE3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}


		}
		else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == INT) {
			action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
			action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
			int no = 0;
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
				no = get_INT(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
				no = get_INT2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
				no = get_INT3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;

		}
		else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == DOUBLE) {
			action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
			action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
			int no = 0;
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
				//cout << "getdpouble 1 " << endl;
				no = get_DOUBLE(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
				no = get_DOUBLE2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
				no = get_DOUBLE3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;
		}

		//cout << i << " " << j << endl;
	}


	if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == INF) {
		
		if (param[0] < param[1]) {
			
			i += cI - 1;
			
		}
		else {
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_end;

			func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if( func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;

			

		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == INFEQ) {
		if (param[0] <= param[1]) {

			i += cI - 1;
		}
		else {
			
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_end;

		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == SUP) {
		if (param[0] > param[1]) {
			i += cI - 1;
		}
		else {
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_end;

			func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;



		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == SUPEQ) {
		if (param[0] >= param[1]) {

			i += cI - 1;
		}
		else {
			
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_end;

			func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;


		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == EQ) {
		if (param[0] == param[1]) {

			i += cI - 1;


		}
		else {
			
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_end;

			func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;



		}
	}



}


void end_whilerm_func_exec(Action action, int &i, int nf) {

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

	//cout << "ind_while " << ind_while << endl;
	//cout << i << endl; system("pause");

	int j = 0;
	for (int i = 0; i < func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param.size(); i++) {
		//cout << WR[ind_while].type_param[i] << endl;
		if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == VCLASS) {
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i + 1] == VINT) {
				action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
				action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
				int no = 0;
				if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
					no = get_INT(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
					no = get_INT2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
					no = get_INT3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i + 1] == VDOUBLE) {
				action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
				action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
				int no = 0;
				if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
					no = get_DOUBLE(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
					no = get_DOUBLE2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
					no = get_DOUBLE3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
				}
				param.push_back(no);
				i++;
				j++;
			}


		}
		else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == INT) {
			action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
			action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
			int no = 0;
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
				no = get_INT(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
				no = get_INT2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
				no = get_INT3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;

		}
		else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].type_param[i] == DOUBLE) {
			action.I_start = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j];
			action.I_end = func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_end[j];
			int no = 0;
			if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 1) {
				//cout << "getdpouble 1 " << endl;
				no = get_DOUBLE(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 2) {
				no = get_DOUBLE2(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].nb_by_param[j] == 3) {
				no = get_DOUBLE3(action, func[nf].while_struct.WR[func[nf].while_struct.ind_while].I_start[j]);
			}
			param.push_back(no);
			j++;
		}

		//cout << i << " " << j << endl;
	}

	//cout << "p1 " << param[0] << " p2 " << param[1] << endl;
	//system("pause");


	if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == INF) {
		
		if (param[0] < param[1]) {
			//cout << "in_while" << endl;
			//ind_add = svind_add;
			//ind_print = svind_print;
			//cout << "INF " << endl;
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_start - 1;
			//cout << "ind_while" << ind_while << endl;
		}
		else {
			
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;

			//cout << "INDWHILE end " << ind_while << endl;

			//cout << NWI->ind_nws << endl;

		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == INFEQ) {
		if (param[0] <= param[1]) {

			//ind_add = svind_add;
			//ind_print = svind_print;

			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_start - 1;
		}
		else {
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;


		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == SUP) {
		if (param[0] > param[1]) {
			//ind_add = svind_add;
			//ind_print = svind_print;

			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_start - 1;
		}
		else {
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;



		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == SUPEQ) {
		if (param[0] >= param[1]) {

			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_start - 1;
		}
		else {

			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;

			//cout << "INDWHILE end " << ind_while << endl;


		}
	}
	else if (func[nf].while_struct.WR[func[nf].while_struct.ind_while].cond == EQ) {
		if (param[0] == param[1]) {

			//ind_add = svind_add;
			//ind_print = svind_print;
			i = func[nf].while_struct.WR[func[nf].while_struct.ind_while].inst_start - 1;


		}
		else {
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.NWI = func[nf].while_struct.NWI->father;

			if (func[nf].while_struct.NWI == nullptr) {
				func[nf].while_struct.ind_nw++;
				if (func[nf].while_struct.ind_nw < func[nf].while_struct.NWF.size())
					func[nf].while_struct.NWI = func[nf].while_struct.NWF[func[nf].while_struct.ind_nw];

				func[nf].while_struct.start_nw = true;
			}
			else {
				if (func[nf].while_struct.NWI->ind_nws < func[nf].while_struct.NWI->son.size() - 1)
					func[nf].while_struct.NWI->ind_nws++;
			}
			if (func[nf].while_struct.NWI != nullptr)
				func[nf].while_struct.ind_while = func[nf].while_struct.NWI->indice;

		}
	}




}



#endif
