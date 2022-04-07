// Regis.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>


#include <string>
#include <vector>
#include <map>
#include <stack>
#include <deque>
using namespace std;
#include "rm_header.h"
#include "function_rm.h"


map<string, string>module;

bool START = true;

int SCOPE = 1;
// 1 general;
// 2 in class
// 3 in main
// 4 in function
// 5 in function in class



template<class T>
deque<T> stack_func;

map<int, int> vinda;
map<int, int> vindp;
map<int, int> CONST_INT;
map<int, double> CONST_DOUBLE;
map<int, string> CONST_STRING;

void Action_func(Action act, int i, int nf, int fun, int type, int cfun) {


		switch (act.action[i]) {

		case PRINT:
			//cout << "type: " << type <<  " " << act.scope[i] << endl;
			if (act.scope[i] == 1 || act.scope[i] == 3) {
				if (type == -1) {
					if (act.type_action[i] == VINT) {
						cout << DC[nf].var.integer_val[fun] << endl;
						
					}
					else if (act.type_action[i] == VDOUBLE) {
						cout << "VDOUBLE" << endl;
						cout << DC[nf].var.double_val[fun] << endl;

					}
					else if (act.type_action[i] == VSTRING) {
						cout << DC[nf].var.pstring[fun] << endl;

					}
					else  if (act.type_action[i] == INT) {

						cout << VG.integer_val[act.num_action[i]] << endl;

					}
					else  if (act.type_action[i] == DOUBLE) {

						cout << VG.double_val[act.num_action[i]] << endl;
					}
					else  if (act.type_action[i] == STRING) {
						//cout << "is " << action.num_action[i] << endl;
						cout << VG.pstring[act.num_action[i]] << endl;

					}
				}
				else if(type == 1) {
					//cout <<"fun " << fun <<  " " << action.type_action[i]<< " " << i << " " << nf << endl;
					if (act.type_action[i] == VCLASS) {


					}
					else  if (act.type_action[i] == INT) {
						//cout << "int " << endl;
						cout << func[nf].var.integer_val[fun] << endl;

					}
					else  if (act.type_action[i] == DOUBLE) {
						//cout << "double " << endl;
						cout << func[nf].var.double_val[fun] << endl;
					}
					else  if (act.type_action[i] == STRING) {
						//cout << "string " << endl;
						//cout << "is " << action.num_action[i] << endl;
						cout << func[nf].var.pstring[fun] << endl;

					}


				}
				else if (type == 2) {
					//cout << "type " <<act.type_action[i] << endl;
					
					if (act.type_action[i] == VCLASS) {


					}
					else  if (act.type_action[i] == INT) {
						//cout << "int " << endl;
						cout << DC[nf].func[cfun].var.integer_val[fun] << endl;

					}
					else  if (act.type_action[i] == DOUBLE) {
						//cout << "double " << endl;
						int ret;
						cout << DC[nf].func[cfun].var.double_val[fun] << endl;

					}
					else  if (act.type_action[i] == STRING) {
						//cout << "string " << endl;
						//cout << "is " << action.num_action[i] << endl;
						cout << DC[nf].func[cfun].var.pstring[fun] << endl;

					}

				}
				
			}
			else if (act.SCOPE == 2) {
				
					//cout << "type " << act.type_action[i] << endl;

					if (act.type_action[i] == VCLASS) {


					}
					else  if (act.type_action[i] == INT) {
						//cout << "int " << endl;
						cout << DC[nf].func[cfun].var.integer_val[fun] << endl;

					}
					else  if (act.type_action[i] == DOUBLE) {
						//cout << "double " << endl;
						int ret;
						cout << DC[nf].func[cfun].var.double_val[fun] << endl;

					}
					else  if (act.type_action[i] == STRING) {
						//cout << "string " << endl;
						//cout << "is " << action.num_action[i] << endl;
						cout << DC[nf].func[cfun].var.pstring[fun] << endl;

					}

				
			}
			
			break;

		case VCLASS:
			if (act.type_action[i] == INT) {
				if (DC[nf].param_name_stack[0] == PNUMBER_INT) {

					DC[nf].var.integer_val[cfun] = DC[nf].stack_var_int[0];
					DC[nf].stack_var_int.pop_front();
				}
			}
			else if (act.type_action[i] == DOUBLE) {
				if (DC[nf].param_name_stack[0] == PNUMBER_DOUBLE) {

					DC[nf].var.double_val[cfun] = DC[nf].stack_var_double[0];
					DC[nf].stack_var_double.pop_front();
				}
			}
			if (act.type_action[i] == STRING) {
				if (DC[nf].param_name_stack[0] == PNUMBER_STRING) {

					DC[nf].var.pstring[cfun] = DC[nf].stack_var_string[0];
					DC[nf].stack_var_string.pop_front();
				}
			}
			break;

		case ADD:
			if (act.SCOPE == 1 || act.SCOPE == 3) {
				
				//cout << "adddfunc 1 3 " << endl;
				//system("pause");
				int sum = 0;
				double sum2 = 0.0;
				bool integer = false;
				bool vinteger = false;
				bool isint = true;


				int index_int = 0, index_double = 0, cindex_int = 0, cindex_double = 0;
				int I = 1;
				//cout << "VCLASS add " << act.action[i+1 ] << endl;
				if (i + 1 < act.action.size()) {
					if (act.action[i + 1] == VCLASS) {
						//cout << "VCLASS add " << endl;
						
						isint = false;
						if (act.type_action[i + 1] == VINT) {
							sum += DC[act.num_action[i]].var.integer_val[act.num_action[i + 1]];
							sum2 += DC[act.num_action[i]].var.integer_val[act.num_action[i + 1]];
							cindex_int++;
							//i++;
							//I++;
							vinteger = true;
						}
						else if (act.type_action[i + 1] == VDOUBLE) {
							//cout << "VDOUBLE add" << endl;
							sum += DC[act.num_action[i]].var.double_val[act.num_action[i + 1]];
							sum2 += DC[act.num_action[i]].var.double_val[act.num_action[i + 1]];
							cindex_double++;
							//i++;
							//I++;
						}
					}
				}
				//cout << "isint " << isint << " " << VA[nf].type_var_func[0]  << endl;
				//system("pause");
				if (isint) {
					if (VA[nf].type_var_func[0] == INT) {
						integer = true;
						isint = true;
						sum += VG.integer_val[VA[nf].integer_val[index_int]];
						sum2 += VG.integer_val[VA[nf].integer_val[index_int]];
						index_int++;
						//cout << "INT "  << VG.integer_val[VA[nf].integer_val[index_int]] << endl;
						//system("pause");
					}
					else if (VA[nf].type_var_func[0] == DOUBLE) {
						isint = true;
						sum += VG.double_val[VA[nf].double_val[index_double]];
						sum2 += VG.double_val[VA[nf].double_val[index_double]];
						index_double++;
						//cout << "DDDOUBLE" << endl;
						//system("pause");
					}
				}
				//cout << "f0 " << VA[nf].type_var_func[0] << endl;

				//cout << I << " " << VA[nf].param_name.size() <<endl;
				for (int j = I; j < VA[nf].param_name.size(); j++) {
					//cout << "type " <<VA[nf].type_var_func[j] << endl;
					if (VA[nf].type_var_func[j] == VCLASS) {
						//cout << "VVCLASS " << VA[nf].type_var_func[j + 1]  <<endl;
						//cout << "cint " << VA[nf].cinteger_val.size() << endl;
						//cout << "cd " << VA[nf].cdouble_val.size() << endl;
						if (VA[nf].type_var_func[j + 1] == VINT) {
							sum += DC[VA[nf].cinteger_val[cindex_int]].var.integer_val[VA[nf].cinteger_val[cindex_int + 1]];
							sum2 += DC[VA[nf].cinteger_val[cindex_int]].var.integer_val[VA[nf].cinteger_val[cindex_int + 1]];
							cindex_int += 2;
							j++;
						}
						else if (VA[nf].type_var_func[j + 1] == VDOUBLE) {
							//cout << "VDOUBLE " << endl;
							sum += DC[VA[nf].cinteger_val[cindex_int]].var.double_val[VA[nf].cdouble_val[cindex_double ]];
							sum2 += DC[VA[nf].cinteger_val[cindex_int]].var.double_val[VA[nf].cdouble_val[cindex_double ]];
							cindex_double ++;
							cindex_int++;
							j++;
							
						}

					}
					else if (VA[nf].type_var_func[j] == INT) {
						sum += VG.integer_val[VA[nf].integer_val[index_int]];
						sum2 += VG.integer_val[VA[nf].integer_val[index_int]];
						//cout << "NUMBER INT INT " << VG.integer_val[VA[nf].integer_val[index_int]] << " " << sum << endl;
						//system("pause");
						index_int++;
					}
					else if (VA[nf].type_var_func[j] == DOUBLE) {
						sum += VG.double_val[VA[nf].double_val[index_double]];
						sum2 += VG.double_val[VA[nf].double_val[index_double]];
						index_double++;
						//cout << "NUMBER DDOUBLE " << VG.double_val[VA[nf].double_val[index_double]] << " " << sum << endl;
						//system("pause");

					}
					else if (VA[nf].type_var_func[j] == PNUMBER_INT) {
						sum += VA[nf].integer_val[index_int];
						sum2 += VA[nf].integer_val[index_int];
						//cout << "NUMBER INT " << VA[nf].integer_val[index_int] << " " << sum << " " << nf << endl;
						//for (int k = 0; k < VA[nf].integer_val.size(); k++)cout << VA[nf].integer_val[k] << endl;
						//cout << "index " << index_int << endl;
						//system("pause");
						index_int++;
					}
					else if (VA[nf].type_var_func[j] == PNUMBER_DOUBLE) {
						sum += VA[nf].double_val[index_double];
						sum2 += VA[nf].double_val[index_double];
						//cout << "NUMBER DOUBLE " << VA[nf].double_val[index_double] << " " << sum << endl;
						//system("pause");
						index_double++;
					}

				}

				//cout << "sum13 " << sum << endl;
				//system("pause");
				if (isint) {
					if (integer) {
						VG.integer_val[VA[nf].integer_val[0]] = sum;
						//cout << "sum " << sum << endl;
						//system("pause");
					}
					else {
						VG.double_val[VA[nf].double_val[0]] = sum;

					}
				}
				else {
					//cout << "numacvt " << act.num_action[i + 1]<< " " << nf  << endl;
					if (vinteger) {
						//cout << DC[act.num_action[i]].var.integer_val.size() << endl;
						//DC[nf].var.integer_val[act.num_action[i + 1]] = sum;
						DC[act.num_action[i]].var.integer_val[act.num_action[i + 1]] = sum;
						//cout << "sum " << sum << endl;
						//system("pause");
					}
					else {
						//cout << DC[act.num_action[i]].var.double_val.size() << endl;
						DC[act.num_action[i]].var.double_val[act.num_action[i + 1]] = sum;

					}
				}
				
			}
			else if (act.SCOPE == 4) {

				int sum = 0;
				double sum2 = 0.0;
				bool integer = false;
				int index_int = 0, index_double = 0;

				//cout << "add func " << nf << " " << fun << endl;
				
				if (func[nf].add_func[fun].type_var_func[0] == INT) {
					integer = true;
					//cout << "dbg" << endl;
					sum += func[nf].var.integer_val[func[nf].add_func[fun].integer_val[index_int]];
					sum2 += func[nf].var.integer_val[func[nf].add_func[fun].integer_val[index_int]];
					index_int++;
				}
				else if (func[nf].add_func[fun].type_var_func[0] == DOUBLE) {
					sum += func[nf].var.double_val[func[nf].add_func[fun].double_val[index_double]];
					sum2 += func[nf].var.double_val[func[nf].add_func[fun].double_val[index_double]];
					index_double++;

				}
				for (int i = 1; i < func[nf].add_func[fun].param_name.size(); i++) {
					if (func[nf].add_func[fun].type_var_func[i] == INT) {
						sum += func[nf].var.integer_val[func[nf].add_func[fun].integer_val[index_int]];
						sum2 += func[nf].var.integer_val[func[nf].add_func[fun].integer_val[index_int]];
						index_int++;
					}
					else if (func[nf].add_func[fun].type_var_func[i] == DOUBLE) {
						sum += func[nf].var.double_val[func[nf].add_func[fun].double_val[index_double]];
						sum2 += func[nf].var.double_val[func[nf].add_func[fun].double_val[index_double]];
						index_double++;

					}
					else if (func[nf].add_func[fun].type_var_func[i] == PNUMBER_INT) {
						sum += func[nf].add_func[fun].integer_val[index_int];
						sum2 += func[nf].add_func[fun].integer_val[index_int];
						index_int++;
					}
					else if (func[nf].add_func[fun].type_var_func[i] == PNUMBER_DOUBLE) {
						sum += func[nf].add_func[fun].double_val[index_double];
						sum2 += func[nf].add_func[fun].double_val[index_double];
						index_double++;
					}

				}

				if (integer) {
					func[nf].var.integer_val[func[nf].add_func[fun].integer_val[0]] = sum;

				}
				else {
					func[nf].var.double_val[func[nf].add_func[fun].double_val[0]] = sum;

				}
				

			}




			break;


		case INT: {
			if (act.type_action[i] == PNUMBER_INT) {
				//cout << "violate" << endl;
				//VG.integer_val[act.num_action[i]] = VG.stack_var_int[0];
				//VG.stack_var_int.pop_front();
				VG.integer_val[act.num_action[i]] = CONST_INT[i];
				//cout << VG.integer_val[act.num_action[i]] << endl;
				//system("pause");
			}


			break;

		}

		case DOUBLE: {
			if (act.type_action[i] == PNUMBER_DOUBLE) {
				//VG.double_val[act.num_action[i]] = VG.stack_var_double[0];
				//VG.stack_var_double.pop_front();

				VG.double_val[act.num_action[i]] = CONST_DOUBLE[i];
			}

			
			break;

		}

		case STRING: {
			if (act.type_action[i] == PNUMBER_STRING) {
				///VG.pstring[act.num_action[i]] = VG.stack_var_string[0];
				//VG.stack_var_string.pop_front();
				VG.pstring[act.num_action[i]] = CONST_STRING[i];
			}


			break;

		}




		}

	


}


int main()
{
	std::ifstream input("regis.txt", std::ios::binary);
	//s = vector<unsigned char>(std::istreambuf_iterator<char>(input), {});
	  
	bool exec = false;
	
	string l;
	while (input >> l) {
		exec = false;

		//cout << "l " << l << endl;
		if (l == "module" && START) {
			START = false;
			string mod;
			while (input >> l) {
				
				size_t fd = l.find_last_of(":");
				if (fd != string::npos) {
					if (l.length() == 1) {
						module[mod] = mod;
					}
					else {
						mod += l.substr(0, fd);
						module[mod] = mod;
					}
					break;
					
				}
				else {
					mod += l;
				}
			}
			exec = true;
			
			//cout << mod << endl;
		}
		else if(l == "module" && !START){
			cout << "ERROR module defined in top of the file.";
			return 0;
		}

		if (l == "print") {
			exec = true;
			string mod;

			//cout << "print " << endl;

			while (input >> l) {
				
				size_t fd = l.find_last_of(";");
				
				if (fd != string::npos) {
					if (l.length() != 1) {
						mod += l.substr(0, fd);
					}
					
					break;
					
				}
				else {
					mod += l + " ";
				}
				
			}

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

			if (action.SCOPE == 1 || action.SCOPE == 3) {
				action.action.push_back(PRINT);
				if (Existe(VC.var.vclass, modvc, ret)) {
					//cout << "PRINT CLASS" << varvc <<  endl;
					int ret2;
					//for (auto e : DC[ret].var.doubles)cout << "--e " <<e.first << endl;
					if (Existe(DC[ret].var.doubles, varvc, ret2)) {
						//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
						
						DC[ret].action.action.push_back(PRINT);
						DC[ret].action.type_action.push_back(VDOUBLE);
						DC[ret].action.num_action.push_back(ret2);
						DC[ret].action.scope.push_back(action.SCOPE);
						action.type_action.push_back(VDOUBLE);
						action.num_action.push_back(ret2);

						print p;
						p.class_num = ret;
						VP.push_back(p);
					}
					else if (Existe(DC[ret].var.integers, varvc, ret2)) {
						//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
						DC[ret].action.action.push_back(PRINT);
						DC[ret].action.type_action.push_back(VINT);
						DC[ret].action.num_action.push_back(ret2);
						DC[ret].action.scope.push_back(action.SCOPE);
						action.type_action.push_back(VINT);
						action.num_action.push_back(ret2);
						print p;
						p.class_num = ret;
						VP.push_back(p);
					}
					else if (Existe(DC[ret].var.strings, varvc, ret2)) {
						//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
						DC[ret].action.action.push_back(PRINT);
						DC[ret].action.type_action.push_back(VSTRING);
						DC[ret].action.num_action.push_back(ret2);
						DC[ret].action.scope.push_back(action.SCOPE);
						action.type_action.push_back(VSTRING);
						action.num_action.push_back(ret2);
						print p;
						p.class_num = ret;
						VP.push_back(p);
					}
					else {
						cout << "ERROR1 aucune variable de ce nom existe pour cette classe." << endl;
					}

					
				}
				else if (Existe(VG.integers, mod, ret)) {
					action.type_action.push_back(INT);
					action.num_action.push_back(ret);
				}
				else if (Existe(VG.doubles, mod, ret)) {
					action.type_action.push_back(DOUBLE);
					action.num_action.push_back(ret);
				}
				else if (Existe(VG.strings, mod, ret)) {
					action.type_action.push_back(STRING);
					action.num_action.push_back(ret);
				}
				else {
					
					VG.pstring.push_back(mod);
					action.type_action.push_back(STRING);
					action.num_action.push_back(VG.pstring.size() - 1);
					//cout << "string var " << mod << " " << VG.pstring.size() - 1 << endl;

				}
				action.scope.push_back(action.SCOPE);

				vindp[action.action.size() - 1] = -1;

			}
			else if (action.SCOPE == 4) {
				int n = func.size() - 1;
				func[n].action.action.push_back(PRINT);
				if (Existe(func[n].var.vclass, mod, ret)) {
					func[n].action.type_action.push_back(VCLASS);
					func[n].action.num_action.push_back(ret);
				}
				else if (Existe(func[n].var.integers, mod, ret)) {
					func[n].action.type_action.push_back(INT);
					func[n].action.num_action.push_back(ret);
				}
				else if (Existe(func[n].var.doubles, mod, ret)) {
					func[n].action.type_action.push_back(DOUBLE);
					func[n].action.num_action.push_back(ret);
				}
				else if (Existe(func[n].var.strings, mod, ret)) {
					func[n].action.type_action.push_back(STRING);
					func[n].action.num_action.push_back(ret);
				}
				else {
					//cout << "func4 " << n << "  " << STRING << " " << mod <<endl;
					func[n].var.pstring.push_back(mod);
					func[n].action.type_action.push_back(STRING);
					func[n].action.num_action.push_back(func[n].var.pstring.size() - 1);

				}

				func[n].action.scope.push_back(1);
			}
			else if (action.SCOPE == 5) {
				int dn = DC.size() - 1;
				int n = DC[dn].func.size() - 1;
				
				if (Existe(DC[dn].func[n].var.vclass, mod, ret)) {
					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(VCLASS);
					DC[dn].func[n].action.num_action.push_back(ret);
					DC[dn].func[n].action.scope.push_back(2);
				}
				else if (Existe(DC[dn].func[n].var.integers, mod, ret)) {
					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(INT);
					DC[dn].func[n].action.num_action.push_back(ret);
					DC[dn].func[n].action.scope.push_back(2);
				}
				else if (Existe(DC[dn].func[n].var.doubles, mod, ret)) {
					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(DOUBLE);
					DC[dn].func[n].action.num_action.push_back(ret);
					DC[dn].func[n].action.scope.push_back(2);
				}
				else if (Existe(DC[dn].func[n].var.strings, mod, ret)) {
					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(STRING);
					DC[dn].func[n].action.num_action.push_back(ret);
					DC[dn].func[n].action.scope.push_back(2);
				}
				//---------------------------------------------
				else if (Existe(DC[dn].var.vclass, modvc, ret)) {

					//if (Existe(VC.var.vclass, l.substr(0, fd - 1), ret)) {
						int ret2;
						if (Existe(DC[ret].var.doubles, varvc, ret2)) {
							//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
							DC[dn].func[n].action.action.push_back(PRINT);
							DC[dn].func[n].action.type_action.push_back(DOUBLE);
							DC[dn].func[n].action.num_action.push_back(ret2);
							DC[dn].func[n].action.scope.push_back(2);
						}
						else if (Existe(DC[ret].var.integers, varvc, ret2)) {
							//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
							DC[dn].func[n].action.action.push_back(PRINT);
							DC[dn].func[n].action.type_action.push_back(INT);
							DC[dn].func[n].action.num_action.push_back(ret2);
							DC[dn].func[n].action.scope.push_back(2);
						}
						else if (Existe(DC[ret].var.strings, varvc, ret2)) {
							//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
							DC[dn].func[n].action.action.push_back(PRINT);
							DC[dn].func[n].action.type_action.push_back(STRING);
							DC[dn].func[n].action.num_action.push_back(ret2);
							DC[dn].func[n].action.scope.push_back(2);
						}
						else {
							cout << "ERROR5 aucune variable de ce nom existe pour cette classe." << endl;
						}

					//}

					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(VCLASS);
					DC[dn].func[n].action.num_action.push_back(ret);
					DC[dn].func[n].action.scope.push_back(2);
				}
				else if (Existe(DC[dn].var.integers, mod, ret)) {
					DC[dn].func[n].var.integer_val.push_back(DC[dn].var.integer_val[ret]);
					DC[dn].func[n].var.integers[mod] = DC[dn].func[n].var.integer_val.size() - 1;

					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(INT);
					DC[dn].func[n].action.num_action.push_back(DC[dn].func[n].var.integer_val.size() - 1);
					DC[dn].func[n].action.scope.push_back(2);
				}
				else if (Existe(DC[dn].var.doubles, mod, ret)) {
					DC[dn].func[n].var.double_val.push_back(DC[dn].var.double_val[ret]);
					DC[dn].func[n].var.doubles[mod] = DC[dn].func[n].var.double_val.size()-1;

					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(DOUBLE);
					DC[dn].func[n].action.num_action.push_back(DC[dn].func[n].var.double_val.size() - 1);
					DC[dn].func[n].action.scope.push_back(2);
					cout << "print doubles " << mod << " " << DC[dn].var.double_val[ret]<< endl;
				}
				else if (Existe(DC[dn].var.strings, mod, ret)) {
					DC[dn].func[n].var.pstring.push_back(DC[dn].var.pstring[ret]);
					DC[dn].func[n].var.strings[mod] = DC[dn].func[n].var.pstring.size() - 1;

					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(STRING);
					DC[dn].func[n].action.num_action.push_back(DC[dn].func[n].var.pstring.size() - 1);
					DC[dn].func[n].action.scope.push_back(2);


				}
				else {
					//cout << "func5 " << n << " " << STRING <<" " <<mod<<endl;
					DC[dn].func[n].var.pstring.push_back(mod);
					DC[dn].func[n].action.action.push_back(PRINT);
					DC[dn].func[n].action.type_action.push_back(STRING);
					DC[dn].func[n].action.num_action.push_back(DC[dn].func[n].var.pstring.size() - 1);
					DC[dn].func[n].action.scope.push_back(2);
				}

				//cout << "print 5" << endl;


			}
			

			
			//cout << mod << endl;

			

		}

		if (l == "int") {
			exec = true;
			input >> l;
			string val;
			input >> val;
			size_t sz;
			int v = stoi(val, &sz);

			if (action.SCOPE == 1 || action.SCOPE == 3) {
							
				VG.integer_val.push_back(v);
				VG.integers[l] = VG.integer_val.size()-1;
				action.action.push_back(INT);
				action.type_action.push_back(INT);
				action.num_action.push_back(VG.integers[l]);
				if (action.SCOPE == 1)
					action.scope.push_back(1);
				else if (action.SCOPE == 3)
					action.scope.push_back(3);
				
			}
			if (action.SCOPE == 2) {

				int n = DC.size() - 1;

				DC[n].var.integer_val.push_back(v);
				DC[n].var.integers[l] = DC[n].var.integer_val.size() - 1;
				action.action.push_back(VCLASS);
				action.type_action.push_back(VINT);
				action.num_action.push_back(DC[n].var.integer_val.size() - 1);
				action.scope.push_back(2);
				//cout << "class a " << l << " " <<v << endl;
			}
			if (action.SCOPE == 4) {

				int n = func.size() - 1;

				func[n].var.integer_val.push_back(v);
				func[n].var.integers[l] = func[n].var.integer_val.size() - 1;
				Register_Action(INT, INT, func[n].var.integers[l], 4);

			}
			if (action.SCOPE == 5) {
				int n = DC.size() - 1;
				int fn = DC[n].func.size() - 1;

				DC[n].func[fn].var.integer_val.push_back(v);
				DC[n].func[fn].var.integers[l] = DC[n].func[fn].var.integer_val.size() - 1;
				action.action.push_back(VCLASS);
				action.type_action.push_back(VINT);
				action.num_action.push_back(DC[n].func[fn].var.integer_val.size() - 1);
				action.scope.push_back(2);

			}

		}

		if (l == "double") {
			exec = true;
			input >> l;
			string val;
			input >> val;
			size_t sz;
			double v = stod(val, &sz);

			if (action.SCOPE == 1 || action.SCOPE == 3) {
				
				
				VG.double_val.push_back(v);
				VG.doubles[l] = VG.double_val.size() - 1;
				action.action.push_back(DOUBLE);
				action.type_action.push_back(DOUBLE);
				action.num_action.push_back(VG.doubles[l]);
				if (action.SCOPE == 1)
					action.scope.push_back(1);
				else if (action.SCOPE == 3)
					action.scope.push_back(3);

			}
			if (action.SCOPE == 2) {

				int n = DC.size() - 1;
				//cout << "low " << l << endl;
				DC[n].var.double_val.push_back(v);
				DC[n].var.doubles[l] = DC[n].var.double_val.size() - 1;
				DC[n].var.idoubles[DC[n].var.double_val.size() - 1] = l;
				action.action.push_back(VCLASS);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(DC[n].var.double_val.size() - 1);
				action.scope.push_back(2);
				
				//cout << "class a " << l << " " << v << endl;
			}
			if (action.SCOPE == 4) {

				int n = func.size() - 1;

				func[n].var.double_val.push_back(v);
				func[n].var.doubles[l] = func[n].var.double_val.size() - 1;
				Register_Action(VDOUBLE, VDOUBLE, func[n].var.doubles[l], 4);

			}
			if (action.SCOPE == 5) {
				//cout <<"5 " << l << endl;
				int n = DC.size() - 1;
				int fn = DC[n].func.size()-1;
				DC[n].func[fn].var.double_val.push_back(v);
				DC[n].func[fn].var.doubles[l] = DC[n].var.double_val.size() - 1;
				DC[n].func[fn].var.idoubles[DC[n].var.double_val.size() - 1] = l;
				action.action.push_back(VCLASS);
				action.type_action.push_back(VDOUBLE);
				action.num_action.push_back(DC[n].func[fn].var.double_val.size() - 1);
				action.scope.push_back(1);
				//cout << "class a " << v << endl;
			}


		}

		if (l == "string") {
			exec = true;
			string var;
			input >> var;
			string mod;
			while (input >> l) {

				size_t fd = l.find_last_of(";");

				if (fd != string::npos) {
					if (l.length() != 1) {
						mod += l.substr(0, fd);
					}

					break;

				}
				else {
					mod += l + " ";
				}

			}

			
			if (action.SCOPE == 1 || action.SCOPE == 3) {
				VG.pstring.push_back(mod);
				VG.strings[var] = VG.pstring.size() - 1;
				action.action.push_back(STRING);
				action.type_action.push_back(STRING);
				action.num_action.push_back(VG.pstring.size() - 1);
				if (action.SCOPE == 1)
					action.scope.push_back(1);
				else if (action.SCOPE == 3)
					action.scope.push_back(3);

				//cout << "string scope " << mod << " " << VG.pstring.size() - 1 << endl;
			}
			else if (action.SCOPE == 2) {

				int n = DC.size() - 1;

				DC[n].var.pstring.push_back(mod);
				DC[n].var.strings[var] = DC[n].var.pstring.size() - 1;
				action.action.push_back(VCLASS);
				action.type_action.push_back( VSTRING);
				action.num_action.push_back(DC[n].var.pstring.size() - 1);
				action.scope.push_back(2);
			}
			else if (action.SCOPE == 4) {

				int n = func.size() - 1;

				func[n].var.pstring.push_back(mod);
				func[n].var.strings[var] = func[n].var.pstring.size() - 1;
				Register_Action(STRING, STRING, func[n].var.strings[var], 4);

			}
			else if (action.SCOPE == 5) {
				int n = DC.size() - 1;
				int fn = DC[n].func.size() - 1;

				DC[n].func[fn].var.pstring.push_back(mod);
				DC[n].func[fn].var.strings[var] = DC[n].func[fn].var.pstring.size() - 1;
				action.action.push_back(VCLASS);
				action.type_action.push_back(VSTRING);
				action.num_action.push_back(DC[n].func[fn].var.pstring.size() - 1);
				action.scope.push_back(2);

			}

			//cout << "string " << var << " " << mod << endl;
		}
		//cout << l << endl;
		if (l == "class:") {
			exec = true;
			//cout << "classsssssssss" << endl;
			string mod;
			while (input >> l) {
				
				size_t fd = l.find_last_of(":");

				if (fd != string::npos) {
					if (l.length() != 1) {
						mod += l.substr(0, fd);
					}

					break;

				}
				else {
					mod += l + " ";
				}

			}

			var_class v;
			v.name = mod;
			v.num = action.give_num_action_vclass();
			DC.push_back(v);
			action.SCOPE = 2;
			action.class_name[mod] = v.num;
			//cout << "class " << v.name << endl;
		}

		if (l == "endclass:") {
			action.SCOPE = 1;
			Register_Action(CHANGE_SCOPE, CHANGE_SCOPE, 0, 1);
		}

		if (l == "main:") {
			action.SCOPE = 3;
			
		}

		if (l == "func:") {
			exec = true;
			string mod;
			while (input >> l) {

				size_t fd = l.find_last_of("(");

				if (fd != string::npos) {
					if (l.length() != 1) {
						mod += l.substr(0, fd);
					}

					break;

				}
				else {
					mod += l + " ";
				}

			}

			function f;
			f.name = mod;
			if (action.SCOPE == 1 || action.SCOPE == 3) {
				action.func_name[mod] = action.give_num_action_func();

			}
			else if (action.SCOPE == 2) {
				int n = DC.size() - 1;
				DC[n].action.func_name[mod] = DC[n].action.give_num_action_func();
			}
			//cout << "func " << mod << " ";
			mod = "";
			while (input >> l) {

				size_t fd = l.find_last_of(")");

				if (fd != string::npos) {
					if (l.length() != 1) {
						mod += l.substr(0, fd);
					}

					break;

				}
				else {
					if (l == "int")
					{
						input >> l;
						//cout <<l << endl;
						f.var.integer_val.push_back(0);
						f.var.integers[l] = f.var.integer_val.size() - 1;
						f.type_var_func.push_back(PINT);
						f.param_name.push_back(l);
					}
					else if (l == "double")
					{
						input >> l;
						
						f.var.double_val.push_back(0.0);
						f.var.doubles[l] = f.var.double_val.size() - 1;
						f.type_var_func.push_back(PDOUBLE);
						f.param_name.push_back(l);
					}
					else if (l == "string")
					{
						input >> l;
						
						f.var.pstring.push_back("");
						f.var.strings[l] = f.var.pstring.size() - 1;
						f.type_var_func.push_back(PSTRING);
						f.param_name.push_back(l);
					}
					
					//cout << "l " << l << endl;
				}

			}



			if (action.SCOPE == 2) {
				//nothing
				action.SCOPE = 5;
				int n = DC.size() - 1;
				DC[n].func.push_back(f);
			}
			else if (action.SCOPE == 1) {
				action.SCOPE = 4;
				int n = func.size() - 1;
				//f.action.action.push_back(FUNCTION);
				//f.action.type_action.push_back(FUNCTION);
				//f.action.num_action.push_back(n);
				//f.action.scope.push_back(4);
				f.action.SCOPE = 4;
				func.push_back(f);
			}
			
			//cout << "end " << endl;

			//cout << endl;

		}

		if (l == "return:") {
			if (action.SCOPE == 4) {
				action.SCOPE = 1;
			}

			if (action.SCOPE == 5) {
				action.SCOPE = 2;
			}
		}

		if (l == "add") {
			exec = true;
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
		

			int ret;
			bool integer = false;
			bool vinteger = false;
			int ret1, ret2;
			
			if (action.SCOPE == 1 || action.SCOPE == 3) {

				
				action.action.push_back(ADD);
				action.scope.push_back(action.SCOPE);
				add A;
				//cout << "ADD " << modvc << " " << varvc <<  " " << A.integer_val.size() << endl;
				//system("pause");
				if (Existe(VG.integers, par[0], ret1)) {
					integer = true;
					action.type_action.push_back(INT);
					action.num_action.push_back(ret1);
					A.param_name.push_back(par[0]);
					A.type_var_func.push_back(INT);
					A.integer_val.push_back(ret1);
					//cout << "int add ---" << par[0]  << " " << action.action.size() << endl;
					//system("pause");

				}
				else if (Existe(VG.doubles, par[0], ret1)) {
					action.type_action.push_back(DOUBLE);
					action.num_action.push_back(ret1);
					A.param_name.push_back(par[0]);
					A.type_var_func.push_back(DOUBLE);
					A.double_val.push_back(ret1);
					//cout << "double" << endl;
				}
				else if (Existe(VC.var.vclass, modvc, ret1)) {
					action.type_action.push_back(VCLASS);
					action.num_action.push_back(ret1);
					//cout << "add vdobless0" << endl;
					if (Existe(DC[ret1].var.integers, varvc, ret2)) {
						vinteger = true;
						action.action.push_back(VCLASS);
						action.scope.push_back(action.SCOPE);
						action.type_action.push_back(VINT);
						action.num_action.push_back(ret2);

						A.param_name.push_back(varvc);
						A.type_var_func.push_back(VINT);
						A.cinteger_val.push_back(ret1);

					}
					else if (Existe(DC[ret1].var.doubles, varvc, ret2)) {
						action.action.push_back(VCLASS);
						action.scope.push_back(action.SCOPE);
						action.type_action.push_back(VDOUBLE);
						action.num_action.push_back(ret2);
						//cout << "add vdobless" << endl;
						A.param_name.push_back(varvc);
						A.type_var_func.push_back(VDOUBLE);
						A.cdouble_val.push_back(ret2);
					}

					//cout << "addobject " << endl;
					//system("pause");

				}
				//cout << "ADD " << modvc << " " << varvc << " " << A.integer_val.size() << endl;
				//system("pause");

				for (int i = 1; i < par.size(); i++) {
					cout << par[i] << endl;
					//system("pause");
					modvc = "";
					varvc = "";
					fdvc = par[i].find_last_of("--");
					if (fdvc != string::npos) {
						modvc = par[i].substr(0, fdvc - 1);

						varvc = par[i].substr(fdvc + 1, l.length());
						size_t fdvvc = varvc.find_last_of(";");
						if (fdvvc != string::npos) {
							varvc = varvc.substr(0, varvc.length() - 1);
						}
						//cout << modvc << " -+- " << varvc << endl;
					}

					if (Existe(VG.integers, par[i], ret)) {
						
						A.param_name.push_back(par[i]);
						A.type_var_func.push_back(INT);
						A.integer_val.push_back(ret);
						//cout << "int----------------------------" << endl;
						//system("pause");
					}
					else if (Existe(VG.doubles, par[i], ret)) {
						
						A.param_name.push_back(par[i]);
						A.type_var_func.push_back(DOUBLE);
						A.double_val.push_back(ret);
						//cout << "double" << endl;
					}
					else if (Existe(VC.var.vclass, modvc, ret1)) {
						A.param_name.push_back(modvc);
						A.type_var_func.push_back(VCLASS);
						A.cinteger_val.push_back(ret1);
						//cout << "parvc" << endl;
						if (Existe(DC[ret1].var.integers, varvc, ret2)) {
							A.param_name.push_back(varvc);
							A.type_var_func.push_back(VINT);
							A.cinteger_val.push_back(ret2);
							//cout << "parvi" << endl;
						}
						else if (Existe(DC[ret1].var.doubles, varvc, ret2)) {
							A.param_name.push_back(varvc);
							A.type_var_func.push_back(VDOUBLE);
							A.cdouble_val.push_back(ret2);
							//cout << "parvd" << endl;
						}

						//cout << "addobject " << endl;
						//system("pause");
					}
					else {
						if (integer) {
							size_t sz;
							int v = stoi(par[i], &sz);
						
							A.param_name.push_back(par[i]);
							A.type_var_func.push_back(PNUMBER_INT);
							A.integer_val.push_back(v);
							//cout << "pint" <<  v << " " << A.integer_val.size() <<  " " << action.action.size() <<  endl;
							//system("pause");

						}
						else {
							size_t sz;
							int v = stod(par[i], &sz);
							

							A.param_name.push_back(par[i]);
							A.type_var_func.push_back(PNUMBER_DOUBLE);
							A.double_val.push_back(v);
							//cout << "pdouble" << endl;
						}
					}

				}
				//cout << "ADD " << modvc << " " << varvc << " " << A.integer_val.size() << endl;
				//system("pause");
				vinda[action.action.size() - 1] = -1;
				//cout << "A param " << A.param_name.size() << " " << par.size() << endl;
				VA.push_back(A);
				

			}
			else if (action.SCOPE == 4) {

				int n = func.size() - 1;
				
				func[n].action.action.push_back(ADD);
				func[n].action.scope.push_back(action.SCOPE);

				
				add A;
				if (Existe(func[n].var.integers, par[0], ret1)) {
					integer = true;
					func[n].action.type_action.push_back(INT);
					func[n].action.num_action.push_back(n);
					A.param_name.push_back(par[0]);
					A.type_var_func.push_back(INT);
					A.integer_val.push_back(ret1);
				}
				else if (Existe(func[n].var.doubles, par[0], ret1)) {
					func[n].action.type_action.push_back(DOUBLE);
					func[n].action.num_action.push_back(n);
					A.param_name.push_back(par[0]);
					A.type_var_func.push_back(DOUBLE);
					A.double_val.push_back(ret1);
				}
				for (int i = 1; i < par.size(); i++) {
					if (Existe(func[n].var.integers, par[i], ret)) {

						A.param_name.push_back(par[i]);
						A.type_var_func.push_back(INT);
						A.integer_val.push_back(ret);
					}
					else if (Existe(func[n].var.doubles, par[i], ret)) {

						A.param_name.push_back(par[i]);
						A.type_var_func.push_back(DOUBLE);
						A.double_val.push_back(ret);
					}
					else {
						if (integer) {
							size_t sz;
							int v = stoi(par[i], &sz);

							A.param_name.push_back(par[i]);
							A.type_var_func.push_back(PNUMBER_INT);
							A.integer_val.push_back(v);

						}
						else {
							size_t sz;
							int v = stod(par[i], &sz);


							A.param_name.push_back(par[i]);
							A.type_var_func.push_back(PNUMBER_DOUBLE);
							A.integer_val.push_back(v);
						}
					}

				}

				func[n].add_func.push_back(A);

			}


		}

		/*******************************************************/

		if (l == "while:") {

			string var1;
			input >> var1;

			string cond;
			input >> cond;

			string var2;
			input >> var2;

			//cout << "var1 " << var1 << " " << " var2 " << var2 << endl;
			while_rm w;

			vector<Action> a1 = Detect_all_variable(var1, var1, WHILE_PAR, action.SCOPE);
			vector<Action> a2 = Detect_all_variable(var2, var2, WHILE_PAR, action.SCOPE);
			Register_Action(WHILE, WR.size() , 2, action.SCOPE);
			Register_Action(WHILE, WHILE, a1.size(), action.SCOPE);
			Register_Action(WHILE, WHILE, a2.size(), action.SCOPE);
			for (int i = 0; i < a1.size(); i++) {
				Register_Action(a1[i].action[0], a1[i].type_action[0], a1[i].num_action[0], a1[i].scope[0]);
				//cout << "reg " << a1[i].action[0] << " " << a1[i].type_action[0] << " " << a1[i].num_action[0] << " " << a1[i].scope[0] << endl;
			}
			for (int i = 0; i < a2.size(); i++) {
				Register_Action(a2[i].action[0], a2[i].type_action[0], a2[i].num_action[0], a2[i].scope[0]);
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
			Register_Action(WHILE_COND, condt, 0, action.SCOPE);
			w.cond = condt;
			w.inst_start = action.action.size();
			WR.push_back(w);
			//cout << a1.action[0] << " " << a1.type_action[0] << " " << a1.num_action[0] << " " << a1.scope[0] << endl;
			//cout << a2[i].action[0] << " " << a2[i].type_action[0] << " " << a2[i].num_action[0] << " " << a2[i].scope[0] << endl;

		}

		if (l == "endwhile:") {
			int n = WR.size() - 1;
			WR[n].inst_end = action.action.size();
			Register_Action(END_WHILE, END_WHILE, 0, action.SCOPE);

		}




		/*******************************************************/

		int ret;
		if (action.SCOPE == 1 || action.SCOPE == 3) {
			//find var class add
			if (Existe(action.class_name, l, ret)) {
				string var;
				input >> var;
				
				//cout << "ret " << ret << endl;
				VC.var.vclass[var] = DC[ret].num;
				//cout << "class " << l << " " << var << " " << ret << " " << VC.var.vclass[var] << endl;

			}

			

		}

		if (action.SCOPE == 1 || action.SCOPE == 3) {

			if (Existe(action.func_name, l, ret)) {
				input >> l;
				
				if (l != "(") {
					cout << "ERROR pas de parenthèse" << endl;
					return 0;
				}
				string mod;
				int index_var = 0;
				while (input >> l) {

					size_t fd = l.find_last_of(")");

					if (fd != string::npos) {
						if (l.length() != 1) {
							mod += l.substr(0, fd);
						}

						break;

					}
					else {
						try {
							if (index_var >= func[ret].type_var_func.size())throw func[ret].name;

							if (func[ret].type_var_func[index_var] == PINT) {
								size_t sz;
								int v = stoi(l, &sz);
								func[ret].integer_val.push_back(v);
							}
							else if (func[ret].type_var_func[index_var] == PDOUBLE) {
								size_t sz;
								int v = stod(l, &sz);
								func[ret].double_val.push_back(v);
							}
							else if (func[ret].type_var_func[index_var] == PSTRING) {

								func[ret].pstring.push_back(l);
							}
							index_var++;
						}
						catch (string s) {
							cerr << "N1 Trop de paramètres passés à la fonction " + s << endl;
							return 0;
						}
					}

				}
				action.action.push_back(FUNCTION);
				action.type_action.push_back(FUNCTION);
				action.num_action.push_back(ret);
				action.scope.push_back(1);

				//cout << "function " << l << " " << ret << endl;

				/*for (int j = 0; j < func.size(); j++) {
					for (int k = 0; k < func[j].action.action.size(); k++) {
						cout << "ta " << func[j].action.type_action[k] << endl;

					}
				}*/

			}

			// VCLASS var

			if (!exec) {
				//cout << "not exec " << l << endl;
				//cout << l << endl;

				size_t fd = l.find_last_of("--");
				if (fd != string::npos) {
					string varvc = l.substr(fd + 1, l.length());
					size_t fdvvc = varvc.find_last_of(";");
					if (fdvvc != string::npos) {
						varvc = varvc.substr(0, varvc.length() - 1);
					}
					//cout << "varvc " << varvc << endl;
					//cout << l.substr(0, fd - 1) << " - " << l.substr(fd + 1, l.length()) << endl;
					if (Existe(VC.var.vclass, l.substr(0, fd - 1), ret)) {
						action.action.push_back(VCLASS);
						action.type_action.push_back(VCLASS);
						action.num_action.push_back(ret);
						action.scope.push_back(action.SCOPE);
						//cout << l.substr(0, fd - 1) << " -- " << l.substr(fd + 1, l.length()) << endl;
						int ret2;
						bool fct = false;
						if (Existe(DC[ret].action.func_name, varvc, ret2)) {
							//cout << l.substr(0, fd - 1) << " " << l.substr(fd + 1, l.length()) << endl;
							action.action.push_back(VCLASS);
							action.type_action.push_back(FUNCTION);
							action.num_action.push_back(ret2);
							action.scope.push_back(action.SCOPE);
							fct = true;
														
							//paramètre de la fonction a passé
							input >> l;

							if (l != "(") {
								cout << "ERROR pas de parenthèse" << endl;
								return 0;
							}
							string mod;
							int index_var = 0;
							while (input >> l) {

								size_t fd = l.find_last_of(")");

								if (fd != string::npos) {
									if (l.length() != 1) {
										mod += l.substr(0, fd);
									}

									break;

								}
								else {
									try {
										if (index_var >= DC[ret].func[ret2].type_var_func.size())throw DC[ret].func[ret2].name;

										if (DC[ret].func[ret2].type_var_func[index_var] == PINT) {
											size_t sz;
											int v = stoi(l, &sz);
											DC[ret].func[ret2].integer_val.push_back(v);
										}
										else if (DC[ret].func[ret2].type_var_func[index_var] == PDOUBLE) {
											size_t sz;
											//cout << "llll " << l << endl;
											int v = stod(l, &sz);
											DC[ret].func[ret2].double_val.push_back(v);
										}
										else if (DC[ret].func[ret2].type_var_func[index_var] == PSTRING) {

											DC[ret].func[ret2].pstring.push_back(l);
										}
										index_var++;
									}
									catch (string s) {
										cerr << "N1 Trop de paramètres passés à la fonction " + s << endl;
										return 0;
									}
								}

							}
							

						}


						if (!fct) {

							if (Existe(DC[ret].var.doubles, varvc, ret2)) {
								action.action.push_back(VCLASS);
								action.type_action.push_back(DOUBLE);
								action.num_action.push_back(ret2);
								action.scope.push_back(action.SCOPE);
								fct = true;

								
								string val;
								input >> val;
								cout << val << endl;
								size_t sz;
								double v = stod(val, &sz);

								DC[ret].param_name_stack.push_back(PNUMBER_DOUBLE);
								DC[ret].stack_var_double.push_back(v);
								

							}
							else if (Existe(DC[ret].var.integers, varvc, ret2)) {
								action.action.push_back(VCLASS);
								action.type_action.push_back(INT);
								action.num_action.push_back(ret2);
								action.scope.push_back(action.SCOPE);
								fct = true;

								string val;
								input >> val;
								size_t sz;
								double v = stoi(val, &sz);

								DC[ret].param_name_stack.push_back(PNUMBER_INT);
								DC[ret].stack_var_int.push_back(v);

							}
							else if (Existe(DC[ret].var.strings, varvc, ret2)) {
								action.action.push_back(VCLASS);
								action.type_action.push_back(STRING);
								action.num_action.push_back(ret2);
								action.scope.push_back(action.SCOPE);
								fct = true;

								string val;
								input >> val;

								DC[ret].param_name_stack.push_back(PNUMBER_STRING);
								DC[ret].stack_var_string.push_back(val);

							}
						}

						if (!fct) {
							cout << "ERROR pas de nom de fonction ou variable existant pour cette classe " << endl;
						}


					}
				}
				else if (Existe(VG.integers, l, ret)) {
					//cout << l << endl;
					string val;
					input >> val;
					size_t sz;
					int v = stoi(val, &sz);

					VG.stack_var_int.push_back(v);
					CONST_INT[action.action.size()] = v;
					Register_Action(INT, PNUMBER_INT, ret, action.SCOPE);

				}
				else if (Existe(VG.doubles, l, ret)) {
					string val;
					input >> val;
					size_t sz;
					double v = stod(val, &sz);

					VG.stack_var_double.push_back(v);
					CONST_DOUBLE[action.action.size()] = v;
					Register_Action(DOUBLE, PNUMBER_DOUBLE, ret, action.SCOPE);


				}
				else if (Existe(VG.strings, l, ret)) {
					string mod;
					while (input >> l) {

						size_t fd = l.find_last_of(";");

						if (fd != string::npos) {
							if (l.length() != 1) {
								mod += l.substr(0, fd);
							}

							break;

						}
						else {
							mod += l + " ";
						}

					}
					
					VG.stack_var_string.push_back(mod);
					CONST_STRING[action.action.size()] = mod;
					Register_Action(STRING, PNUMBER_STRING, ret, action.SCOPE);
				}



			}
			

			//add
			ret = 0;

			
		}
		else if (action.SCOPE == 2) {
			

		}

		
		
		/*else if (Existe(VG.integers, l, ret)) {
			action.action.push_back(INT);
			action.type_action.push_back(INT);
			action.num_action.push_back(ret);
			action.scope.push_back(action.SCOPE);
		}
		else if (Existe(VG.doubles, l, ret)) {
			action.action.push_back(DOUBLE);
			action.type_action.push_back(DOUBLE);
			action.num_action.push_back(ret);
			action.scope.push_back(action.SCOPE);
		}
		else if (Existe(VG.strings, l, ret)) {
			action.action.push_back(STRING);
			action.type_action.push_back(STRING);
			action.num_action.push_back(ret);
			action.scope.push_back(action.SCOPE);
		}*/
		

		
	}
	
	/***********************/
	int ind_add = 0;
	int ind_print = 0;
	int svind_add = 0;
	int svind_print = 0;
	int ind_while = -1;
	deque<int> WSTART, WEND;
	bool in_while = false;
	
	bool start_indp = true;
	
	/***********************/

	for (int i = 0; i < action.action.size(); i++) {
		vindp[i] = -1; vinda[i] = -1;
	}

	for (int i = 0; i < action.action.size();i++) {
		//cout << "action " <<action.action[i] << endl;

		//cout << "ind_while ------" << ind_while << endl;
		//cout << "ind_print  ------" << ind_print << endl;
		//system("pause");
		//cout << "I " << i << endl;

		

		switch (action.action[i]) {

		case WHILE:
		{
			int ri;
			double rd;
			string rs;
			var_class rv;
			int cI = 3;
			Action act;
			int typer;

			svind_add = ind_add;
			svind_print = ind_print;


			in_while = true;
			int sz1 = action.num_action[i + 1];
			int sz2 = action.num_action[i + 2];

			ind_while++; // action.type_action[i];
			WR[ind_while].start = true;
			if (ind_while - 1 >= 0) {
				WR[ind_while-1].exec = WR[ind_while - 1].inst_end;

			}

			//cout << "index WHILE " << ind_while << endl;
			//cout << "ind_while" <<ind_while << endl;
			//cout << "action sz " << action.action.size() << endl;

			//cout << "I " << i << " start " << WR[ind_while].inst_start << " end "<< WR[ind_while].inst_end <<endl;

			//cout << sz1 << " - " << sz2 << endl;

			int I = i + 3;
			//cout << "rip " << action.action[I] << " " << action.type_action[I] << " " << action.num_action[I] << " " << action.scope[I] << endl;
			int li = i + 3;
			//cout << I << " " << sz1 + li << endl;

			/*for (int j = I; j < action.action.size(); j++) {
				cout << "action: " <<j << " " << action.action[j] <<" " << action.type_action[j] << endl;
			}*/
			//system("pause");
			//cout << "type action i " << action.type_action[I] << " " << action.type_action[I+1] << " " << action.type_action[I + 2] << endl;
			//cout << sz1 << " " << sz2 << endl;
			WR[ind_while].I_start.push_back(I);
			int scope = 0;
			for (; I < sz1+li; I++) {
				while_func(action, I, ri, rd, rs, rv, typer);
				//cout << "--ri " << ri << endl;
				/*if (typer == INT) {
					WR[ind_while].type_param.push_back(INT);
				}
				else if (typer == DOUBLE) {
					WR[ind_while].type_param.push_back(DOUBLE);
				}*/
				//cout << "typer " << typer << endl;
				WR[ind_while].type_param.push_back(action.type_action[I]);
				
				WSTART.push_back(ri);
				cI++;
			}
			//cout << "type action i2 " << action.type_action[I] << " " << action.type_action[I + 1] << " " << action.type_action[I + 2] << endl;
			WR[ind_while].I_end.push_back(I);
			WR[ind_while].nb_by_param.push_back(sz1);
	
			//cout << "--------------------------------" << endl;
			 li =I;
			 WR[ind_while].I_start.push_back(I);
			 for (; I < sz2 + li; I++) {
				 while_func(action, I, ri, rd, rs, rv, typer);
				 //cout << "rd " << rd << endl;
				 /*if (typer == INT) {
					 WR[ind_while].type_param.push_back(INT);
				 }
				 else if (typer == DOUBLE) {
					 WR[ind_while].type_param.push_back(DOUBLE);
				 }*/

				WR[ind_while].type_param.push_back(action.type_action[I]);
				 WEND.push_back(rd);
				 cI++;
			 }
			 WR[ind_while].I_end.push_back(I);
			 WR[ind_while].nb_by_param.push_back(sz2);

			//cout << "__________________________________________" << endl;


			if (action.action[I] == WHILE_COND) {
				cI++;
			}

			i += cI-1;
			break;
		}

		case END_WHILE:
		{
			//WR[ind_while].inst_end = i;
			//cout << "END index WHILE " << ind_while << endl;

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


			if (WR[ind_while].cond == INF) {
				if (param[0] < param[1]) {
					//cout << "in_while" << endl;
					//ind_add = svind_add;
					//ind_print = svind_print;

					i = WR[ind_while].inst_start - 1;
				}
				else {
					in_while = false;
					ind_while--;
					/*if (ind_while >= 0) {
						i = WR[ind_while].inst_start - 1;
						//ind_print = vindp[ind_while];
					}*/

					//ind_add = svind_add;


				}
			}
			else if (WR[ind_while].cond == INFEQ) {
				if (param[0] <= param[1]) {

					//ind_add = svind_add;
					//ind_print = svind_print;

					i = WR[ind_while].inst_start - 1;
				}
				else {
					in_while = false;
					ind_while--;
					/*if (ind_while >= 0) {
						i = WR[ind_while].inst_start - 1;
						//ind_print = vindp[ind_while];
					}*/

					//ind_add = svind_add;

				}
			}
			else if (WR[ind_while].cond == SUP) {
				if (param[0] > param[1]) {
					//ind_add = svind_add;
					//ind_print = svind_print;

					i = WR[ind_while].inst_start - 1;
				}
				else {
					in_while = false;
					ind_while--;
					/*if (ind_while >= 0) {
						i = WR[ind_while].inst_start - 1;
						///ind_print = vindp[ind_while];
					}*/

					//ind_add = svind_add;

				}
			}
			else if (WR[ind_while].cond == SUPEQ) {
				if (param[0] >= param[1]) {

					//ind_add = svind_add;
					//ind_print = svind_print;

					i = WR[ind_while].inst_start - 1;
				}
				else {
					in_while = false;
					ind_while--;
					
					//cout << "supeq " << endl;
					//system("pause");


					//ind_add = svind_add;

				}
			}
			else if (WR[ind_while].cond == EQ) {
				if (param[0] == param[1]) {

					//ind_add = svind_add;
					//ind_print = svind_print;
					i = WR[ind_while].inst_start - 1;


				}
				else {
					in_while = false;
					ind_while--;
					/*if (ind_while >= 0) {
						i = WR[ind_while].inst_start - 1;
						//ind_print = vindp[ind_while];
					}*/

					//ind_add = svind_add;

				}
			}

			break;
		}

		case PRINT:
			//cout << "PRINT" << endl;
			

			//cout << i << " - " << vindp[i] << endl;
			//system("pause");
			/*if (action.scope[i] == 1 || action.scope[i] == 3) {
				if (action.type_action[i] == VCLASS) {


				}
				else  if (action.type_action[i] == INT) {

					cout << VG.integer_val[action.num_action[i]] << endl;

				}
				else  if (action.type_action[i] == DOUBLE) {

					cout << VG.double_val[action.num_action[i]] << endl;
				}
				else  if (action.type_action[i] == STRING) {
					//cout << "is " << action.num_action[i] << endl;
					cout << VG.pstring[action.num_action[i]] << endl;

				}
			}*/

			if (action.SCOPE == 1 || action.SCOPE == 3) {
				//cout << "TYPE " << action.type_action[i] << endl;
				
				if(action.type_action[i] >= VINT && action.type_action[i] <= VSTRING){
					if (vindp[i] == -1) {
						vindp[i] = ind_print;
						//cout << i << " " << vindp[i] << endl;
						//system("pause");
						start_indp = false;
						ind_print++;
					}

					//cout << "ACTION " << endl;
					Action_func(action, i, VP[vindp[i]].class_num, action.num_action[i], -1, -1);
					
				}
				else {
					Action_func(action, i, -1, -1, -1, -1);
				}
			}
			else if (action.SCOPE == 2) {
				
			}

			break;
		
		case FUNCTION:
		{
			
			try {
				if (func[action.num_action[i]].type_var_func.size() > func[action.num_action[i]].param_name.size()) {
					throw func[action.num_action[i]].name;
				}
				int index_int = 0, index_double = 0, index_string = 0;
				for (int j = 0; j < func[action.num_action[i]].type_var_func.size(); j++) {
					if (func[action.num_action[i]].type_var_func[j] == PINT) {
						string name = func[action.num_action[i]].param_name[j];
						int ret = func[action.num_action[i]].var.integers[name];
						func[action.num_action[i]].var.integer_val[ret] = func[action.num_action[i]].integer_val[index_int];
						index_int++;
					}
					else if (func[action.num_action[i]].type_var_func[j] == PDOUBLE) {
						string name = func[action.num_action[i]].param_name[j];
						int ret = func[action.num_action[i]].var.doubles[name];
						func[action.num_action[i]].var.double_val[ret] = func[action.num_action[i]].double_val[index_double];
						index_double++;
					}
					else if (func[action.num_action[i]].type_var_func[j] == PSTRING) {
						string name = func[action.num_action[i]].param_name[j];
						int ret = func[action.num_action[i]].var.strings[name];
						func[action.num_action[i]].var.pstring[ret] = func[action.num_action[i]].pstring[index_string];
						index_string++;

					}
				}
			}
			catch (string s) {
				//cout << "Trop de paramètre passé a la fonction " + s << endl;
			}
			//cout << "nb func " << func.size() << endl;
			for (int j = 0; j < func[action.num_action[i]].action.action.size(); j++) {
				//cout << "func sete " << func[action.num_action[i]].action.num_action[j] << " " << j << endl;
				//cout << func[action.num_action[i]].action.type_action[j] << endl;
				//cout << func[action.num_action[i]].action.num_action[j] << endl;
				//cout << "scope function " << func[action.num_action[i]].action.SCOPE << endl;
				Action_func(func[action.num_action[i]].action, j, action.num_action[i], func[action.num_action[i]].action.num_action[j], 1, -1);

			}

			//cout << "end func" << endl;
			break;
		}


		case VCLASS:
			if (action.type_action[i] == VCLASS) {
				if (i + 1 < action.action.size()) {
					if (action.action[i + 1] == VCLASS && action.type_action[i + 1] == FUNCTION) {
						//cout << "SSSSSSSSSSTTTTTTZART" << endl;
						try {
							if (DC[action.num_action[i]].func[action.num_action[i + 1]].type_var_func.size() > DC[action.num_action[i]].func[action.num_action[i + 1]].param_name.size()) {
								throw DC[action.num_action[i]].func[action.num_action[i + 1]].name;
							}
							int index_int = 0, index_double = 0, index_string = 0;
							for (int j = 0; j < DC[action.num_action[i]].func[action.num_action[i + 1]].type_var_func.size(); j++) {
								if (DC[action.num_action[i]].func[action.num_action[i + 1]].type_var_func[j] == PINT) {
									string name = DC[action.num_action[i]].func[action.num_action[i + 1]].param_name[j];
									int ret = DC[action.num_action[i]].func[action.num_action[i + 1]].var.integers[name];
									DC[action.num_action[i]].func[action.num_action[i + 1]].var.integer_val[ret] = DC[action.num_action[i]].func[action.num_action[i + 1]].integer_val[index_int];
									index_int++;
								}
								else if (DC[action.num_action[i]].func[action.num_action[i + 1]].type_var_func[j] == PDOUBLE) {
									string name = DC[action.num_action[i]].func[action.num_action[i + 1]].param_name[j];
									int ret = DC[action.num_action[i]].func[action.num_action[i + 1]].var.doubles[name];
									DC[action.num_action[i]].func[action.num_action[i + 1]].var.double_val[ret] = DC[action.num_action[i]].func[action.num_action[i + 1]].double_val[index_double];
									index_double++;
								}
								else if (DC[action.num_action[i]].func[action.num_action[i + 1]].type_var_func[j] == PSTRING) {
									string name = DC[action.num_action[i]].func[action.num_action[i + 1]].param_name[j];
									int ret = DC[action.num_action[i]].func[action.num_action[i + 1]].var.strings[name];
									DC[action.num_action[i]].func[action.num_action[i + 1]].var.pstring[ret] = DC[action.num_action[i]].func[action.num_action[i + 1]].pstring[index_string];
									index_string++;

								}
							}
						}
						catch (string s) {
							cout << "Trop de paramètre passé a la fonction " + s << endl;
						}
						
						for (int j = 0; j < DC[action.num_action[i]].func[action.num_action[i + 1]].action.action.size(); j++) {
							DC[action.num_action[i]].func[action.num_action[i + 1]].action.scope[j] = 1;
							Action_func(DC[action.num_action[i]].func[action.num_action[i + 1]].action,
								j,
								action.num_action[i],
								DC[action.num_action[i]].func[action.num_action[i + 1]].action.num_action[j],
								2,
								action.num_action[i + 1]);
							//cout << "actoin"<< endl;
						}
						/*cout << "-------- - " << endl;
						cout << action.action[i] << " " << action.type_action[i] << endl;
						cout << action.action[i + 1] <<" " << action.type_action[i + 1] << endl;
						cout << action.num_action[i ] << " " << action.num_action[i + 1] << endl;
						cout << DC[action.num_action[i]].func[action.num_action[i + 1]].action.action.size() << endl;
						for (int j = 0; j < DC[action.num_action[i]].func.size(); j++) {
							for (int k = 0; k < DC[action.num_action[i]].func[j].action.action.size(); k++) {
								cout << "ta " << DC[action.num_action[i]].func[j].action.type_action[k] << endl;

							}
						}*/


					}
					else if (action.action[i + 1] == VCLASS && action.type_action[i + 1] == INT) {
						Action_func(action,
							i+1,
							action.num_action[i],
							-1,
							-1,
							action.num_action[i+1]);
					}
					else if (action.action[i + 1] == VCLASS && action.type_action[i + 1] == DOUBLE) {
						Action_func(action,
							i + 1,
							action.num_action[i],
							-1,
							-1,
							action.num_action[i + 1]);
					}
					else if (action.action[i + 1] == VCLASS && action.type_action[i + 1] == STRING) {
						Action_func(action,
							i + 1,
							action.num_action[i],
							-1,
							-1,
							action.num_action[i + 1]);
					}

				}

			}
			break;

		case ADD:
		{
			//cout << "IND ADD " << ind_add << " " << vinda[i] << " " << action.action[i] << " " << VA.size() << " " << i << endl;
			if (vinda[i] == -1) {
				vinda[i] = ind_add;
				start_indp = false;
				ind_add++;
				
			}
			//cout << "IND ADD " << ind_add << " " << vinda[i] << " " << action.action[i] << " " << VA.size() << " " << i << endl;
			//system("pause");
			Action_func(action, i, vinda[i], -1, -1, -1);
			
			break;
		}

		case INT:
		{
			Action_func(action, i, -1, -1, -1, -1);

			break;
		}

		case DOUBLE:
		{
			Action_func(action, i, -1, -1, -1, -1);

			break;
		}

		case STRING:
		{
			Action_func(action, i, -1, -1, -1, -1);

			break;
		}
		
		}
		
		
		//cout << i << endl;

		/*if (in_while) {
			//cout << "in_while " << i << " " << WR[ind_while].inst_end <<endl;

			if (i == WR[ind_while].inst_end) {

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
				int j = 0;
				for (int i = 0; i < WR[ind_while].type_param.size(); i++) {
					cout << WR[ind_while].type_param[i] << endl;
					if (WR[ind_while].type_param[i] == VCLASS) {
						if (WR[ind_while].type_param[i+1] == VINT) {
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
						else if (WR[ind_while].type_param[i+1] == VDOUBLE) {
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
						if (WR[ind_while].nb_by_param[j] == 1){
							no = get_INT(action, WR[ind_while].I_start[j]);
						}
						else if (WR[ind_while].nb_by_param[j] == 2){
							no = get_INT2(action, WR[ind_while].I_start[j]);
						}
						else if (WR[ind_while].nb_by_param[j] == 3){
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
					
				cout << "p1 " << param[0] << " p2 " << param[1] << endl;
				//system("pause");
								

				if (WR[ind_while].cond == INF) {
					if (param[0] < param[1]) {
						//cout << "in_while" << endl;
						//ind_add = svind_add;
						//ind_print = svind_print;

						i = WR[ind_while].inst_start - 1;
					}
					else {
						in_while = false;
						ind_while--;
						

						//ind_add = svind_add;
						

					}
				}
				else if (WR[ind_while].cond == INFEQ) {
					if (param[0] <= param[1]) {
						
						//ind_add = svind_add;
						//ind_print = svind_print;

						i = WR[ind_while].inst_start - 1;
					}
					else {
						in_while = false;
						ind_while--;
						

						//ind_add = svind_add;
						
					}
				}
				else if (WR[ind_while].cond == SUP) {
					if (param[0] > param[1]) {
						//ind_add = svind_add;
						//ind_print = svind_print;

						i = WR[ind_while].inst_start - 1;
					}
					else {
						in_while = false;
						ind_while--;
						

						//ind_add = svind_add;
						
					}
				}
				else if (WR[ind_while].cond == SUPEQ) {
					if (param[0] >= param[1]) {
					
						//ind_add = svind_add;
						//ind_print = svind_print;

						i = WR[ind_while].inst_start - 1;
					}
					else {
						in_while = false;
						ind_while--;
						cout << "supeq " << endl;
						system("pause");
						

						//ind_add = svind_add;
						
					}
				}
				else if (WR[ind_while].cond == EQ) {
					if (param[0] == param[1]) {
						
						//ind_add = svind_add;
						//ind_print = svind_print;
						i = WR[ind_while].inst_start - 1;

						
					}
					else {
						in_while = false;
						ind_while--;
						

						//ind_add = svind_add;
						
					}
				}

				cout << "I " << i << endl;
				system("pause");
			}

			cout << "end while " << endl;

		}*/

		
	}


    
}

