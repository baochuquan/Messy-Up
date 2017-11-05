// Branch Predication Simulation
// Coded by Wei Lan (Student ID: 1201214149)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

// global variables
#define BITS4  0x0000f
#define BITS10 0x003ff
#define BITS12 0x00fff
#define BITS14 0x03fff

// 2-bit branch history table predictor
vector<bitset<2> > branch_history_table(pow((float)2,14),bitset<2>(string("00")));

// [10,2] correlating predictor
const int M=10;
const int N=2;
const int ADD_INDEX=14-M;
int branch_saved=0;
int predict_true=0,predict_false=0,actual_true=0,actual_false=0;
bitset<M> latest_branch(string("0000000000"));
vector<vector<bitset<N> > > correlating_predictor_table(pow((float)2,ADD_INDEX),vector<bitset <N> >(pow((float)2,M), bitset<N>(string("00"))));

// tournament predictor
vector< bitset<10> > local_history_table(pow((float)2,10), bitset<10>(string("0000000000")));
vector< bitset<3> > local_predictor_table(pow((float)2,10),bitset<3>(string("000")));
vector< bitset<2> > global_predictor_table(pow((float)2,12), bitset<2>(string("00")));
bitset<12> global_history_table(string("000000000000"));
int global_saved=0;
vector<bitset<2> > selecotors(pow((float)2,12), bitset<2>(string("00")));

// predition fuction
bool correlating(string current_pc, string next_pc);
bool tournament(string current_pc, string next_pc);
bool bht(string current_pc,string next_pc);

int main(){
	string filenames[7]={"gcc.log", "compress.log", "crafty.log", "gzip.log", "mcf.log", "parser.log", "vpr.log"};
	double bht_average=0.0,correlating_average=0.0,tournament_average=0.0;
	for(int i=0;i<7;i++){
		cout<<"Testing file: "<<filenames[i]<<endl;
		ifstream fin(filenames[i]);
		int bht_predict_correct=0,bht_predict_wrong=0,
			correlating_predict_correct=0,correlating_predict_wrong=0,
			tournament_predict_correct=0,tournament_predict_wrong=0;
		string line;
		while(getline(fin,line)){
			stringstream theline(line);
			theline<<line;
			string current_pc;
			string next_pc;
			theline>>current_pc;
			theline>>next_pc;
			if(bht(current_pc,next_pc))
				++bht_predict_correct;
			else
				++bht_predict_wrong;
			if(correlating(current_pc,next_pc))
				++correlating_predict_correct;
			else
				++correlating_predict_wrong;
			if(tournament(current_pc,next_pc))
				++tournament_predict_correct;
			else
				++tournament_predict_wrong;

		}
		float bht_correct_rate=(float)(bht_predict_correct)/(float)(bht_predict_correct+bht_predict_wrong);
		cout<<"The correct rate for 2-bit branch history table predictor is: "<<bht_correct_rate<<endl;
		bht_average+=bht_correct_rate;
		float correlating_correct_rate=(float)correlating_predict_correct/(float)(correlating_predict_correct+correlating_predict_wrong);
		cout<<"The correct rate for ("<<M<<","<<N<<") correlating predictor is: "<<correlating_correct_rate<<endl;
		correlating_average+=correlating_correct_rate;
		float tournament_correct_rate=(float)tournament_predict_correct/(float)(tournament_predict_correct+tournament_predict_wrong);
		cout<<"The correct rate for tournament predictor is: "<<tournament_correct_rate<<endl;
		tournament_average+=tournament_correct_rate;
		cout<<endl;
		fin.close();
	}
	bht_average /=7.0;
	correlating_average /=7.0;
	tournament_average /=7.0;
	cout<<"Average: "<<bht_average<<" "<<correlating_average<<" "<<tournament_average<<endl;

	return 0;
}

bool correlating(string current_pc, string next_pc){
	bool jump_actual=false,jump_predict=false;
	long current_add=strtol(current_pc.c_str(), NULL, 16);
	long next_add=strtol(next_pc.c_str(), NULL, 16);

	bitset<ADD_INDEX> current_add_low=bitset<ADD_INDEX>(current_add & BITS4);
	if(correlating_predictor_table[current_add_low.to_ulong()][latest_branch.to_ullong()].at(1)==1)
		jump_predict=true;

	if((next_add-current_add)!=4)
		jump_actual=true;
	
	// Reset predictor and tables
	if(jump_actual){
		long tmp_predict=correlating_predictor_table[current_add_low.to_ulong()][latest_branch.to_ullong()].to_ulong();
		tmp_predict=(tmp_predict+1)>3 ? 3: (tmp_predict+1);
		correlating_predictor_table[current_add_low.to_ulong()][latest_branch.to_ullong()]=bitset<N>(tmp_predict);
	}
	else {
		long tmp_predict=correlating_predictor_table[current_add_low.to_ulong()][latest_branch.to_ullong()].to_ulong();
		tmp_predict=(tmp_predict-1)<0 ? 0: (tmp_predict-1);
		correlating_predictor_table[current_add_low.to_ulong()][latest_branch.to_ullong()]=bitset<N>(tmp_predict);
	}
	long tmp_latest=latest_branch.to_ulong();
	latest_branch=bitset<M>( (tmp_latest << 1 ) & BITS10);
	latest_branch[0]=jump_actual ? 1 : 0;
	return !(jump_actual ^ jump_predict);
}



bool tournament(string current_pc, string next_pc){
	bool jump_actual=false,jump_predict=false,
		local_predict=false,global_predict=false;
	long current_add=strtol(current_pc.c_str(), NULL, 16);
	long next_add=strtol(next_pc.c_str(), NULL, 16);
	// Local predict 
	int local_index=current_add & BITS10;
	if(local_predictor_table[local_history_table[local_index].to_ulong()].at(2)==1){
		local_predict=true;
	}
	// Global predict
	if(global_predictor_table[global_history_table.to_ulong()].at(1)==1){
		global_predict=true;
	}
	if(selecotors[current_add & BITS12].at(1)==0)
		jump_predict=local_predict;
	else
		jump_predict=global_predict;

	// Update local and predictors and tables
	if((next_add-current_add)!=4)
		jump_actual=true;

	if(jump_actual){
		long local_tmp=local_predictor_table[local_history_table[local_index].to_ulong()].to_ulong();
		local_tmp=(local_tmp+1) > 7 ? 7 : (local_tmp+1) ;
		local_predictor_table[local_history_table[local_index].to_ulong()]=bitset<3>(local_tmp);
	}
	else{
		long local_tmp=local_predictor_table[local_history_table[local_index].to_ulong()].to_ulong();
		local_tmp=(local_tmp-1) < 0 ? 0 : (local_tmp-1) ;
		local_predictor_table[local_history_table[local_index].to_ulong()]=bitset<3>(local_tmp);
	}
	long local_history_tmp=local_history_table[local_index].to_ulong();
	local_history_tmp=(local_history_tmp<<1) & BITS10;
	local_history_table[local_index]=bitset<10>(local_history_tmp);
	local_history_table[local_index][0]= jump_actual ? 1: 0;

	// Update global and predictors and tables
	if( jump_actual){
		long global_tmp=global_predictor_table[global_history_table.to_ulong()].to_ulong();
		global_tmp=(global_tmp+1) > 3 ? 3 : (global_tmp+1) ;
		global_predictor_table[global_history_table.to_ulong()]=bitset<2>(global_tmp);
	}
	else {
		long global_tmp=global_predictor_table[global_history_table.to_ulong()].to_ulong();
		global_tmp=(global_tmp-1) < 0 ? 0 : (global_tmp-1) ;
		global_predictor_table[global_history_table.to_ulong()]=bitset<2>(global_tmp);
	}
	long global_history_tmp=global_history_table.to_ulong();
	global_history_tmp=( (global_history_tmp<<1) & BITS12);
	global_history_table=bitset<12>(global_history_tmp);
	global_history_table[0]=jump_actual ? 1:0;

	// Update selecotrs
	if(local_predict^global_predict){
		if( local_predict^jump_actual ){
			long selecotor_tmp=selecotors[current_add & BITS12].to_ulong();
			selecotor_tmp=(selecotor_tmp+1)>3 ? 3:  (selecotor_tmp+1);
			selecotors[current_add&0xfff]=bitset<2>(selecotor_tmp);
		}
		else if(global_predict^jump_actual ){
			long selecotor_tmp=selecotors[current_add & BITS12].to_ulong();
			selecotor_tmp=(selecotor_tmp-1)<0 ? 0:  (selecotor_tmp-1);
			selecotors[current_add&0xfff]=bitset<2>(selecotor_tmp);
		}
	}

	return !(jump_actual ^ jump_predict);
}

bool bht(string current_pc,string next_pc){
	bool jump_actual=false,jump_predict=false;
	long current_add=strtol(current_pc.c_str(), NULL, 16);
	long next_add=strtol(next_pc.c_str(), NULL, 16);

	if((next_add-current_add)!=4)
		jump_actual=true;

	if(branch_history_table[current_add & BITS14].at(1))
		jump_predict=true;

	// Update histroy table
	if(jump_actual){
		long tmp=branch_history_table[current_add & BITS14].to_ulong();
		tmp=(tmp+1)>3 ? 3:(tmp+1);
		branch_history_table[current_add & BITS14]=bitset<2>(tmp);
	}
	else{
		long tmp=branch_history_table[current_add & BITS14].to_ulong();
		tmp=(tmp-1)<0 ? 0:(tmp-1);
		branch_history_table[current_add & BITS14]=bitset<2>(tmp);
	}
	return !(jump_actual ^ jump_predict);

}
