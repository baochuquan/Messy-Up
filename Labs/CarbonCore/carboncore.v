module CarbonCore(clkA, clkB, PC, INST, OP, C, DI, DO);

//芯片对外的接口包括:
//时钟:
input clkA,clkB;					//两相不交叠时钟

//同指令RAM交互:
output [7:0] PC;					//PC的值
input [13:0] INST;					//"INST段地址+PC"所指向的指令

//同数据RAM以及IO port交互的:
output [13:8] OP;					//指令的高6位,即OP==INST[13:8]
output [7:0] C;						//指令的低8位,即C==INST[7:0]
input [7:0] DI;						//从数据RAM或IO port读来的值
output [7:0] DO;					//向数据RAM或IO port写出的值

//以上这些接口都和一颗FPGA芯片相连,注意芯片不向FPGA输出时钟,只接受FPGA送过来的时钟
//时钟和信号的同步,由FPGA端负责
//三种右源操作数的寻址方式完全由FPGA来处理,Carbon只管使用DI输入的值

assign OP=INST[13:8];
assign C=INST[7:0];

reg [7:0] acc;						//累加器		默认初始值为不定值
reg [7:0] pc;						//程序计数器
wire acc_zero=(acc==8'b0);
assign PC=pc;

reg [7:0] pc_plus_1;				//pc+1的值

reg [7:0] A;						//加法器输入A
reg [7:0] B;						//加法器输入B
reg	CI;								//加法器的carry-in
reg [7:0] X;						//加法器的输出
reg acc_update,acc_update_r;		//acc是否更新值
reg br_taken,br_taken_r;			//branch是否taken
assign DO=X;

/*
指令		编码		加法器输入A		加法器输入B		加法器carry-in		acc是否更新		PC的新值
MOV			0000-xx		acc				8'b0			1'b0				是				pc+1
MOVa 		0001-xx		acc				8'b0			1'b0				否				pc+1
ADD 		0010-xx		acc				DI				1'b0				是				pc+1
ADDa 		0011-xx		acc				DI				1'b0				否				pc+1
SUB			0100-xx		acc				~DI				1'b1				是				pc+1
SUBa 		0101-xx		acc				~DI				1'b1				否				pc+1
RSB			0110-xx		DI				~acc			1'b1				是				pc+1
RSBa 		0111-xx		DI				~acc			1'b1				否				pc+1

OUT			1000-00		acc				8'b0			1'b0				否				pc+1
IN			1001-00		DI				8'b0			1'b0				是				pc+1
DATASEG		1010-00		8'bx			8'bx			1'bx				否				pc+1
IOSEG		1010-01		8'bx			8'bx			1'bx				否				pc+1
JR			1011-00		acc				8'b0			1'b0				否				加法器输出
B			1100-00		pc				C				1'b0				否				加法器输出
BZ			1100-10		pc				C				1'b0				否				acc==0?加法器输出:pc+1
BNZ			1100-01		pc				C				1'b0				否				acc!=0?加法器输出:pc+1
*/

always @(*)
	begin
		casex(INST[13:8])
			6'b0000xx: {A,B,CI,acc_update,br_taken}={acc,  8'b0, 1'b0, 1'b1, 1'b0};			
			6'b0001xx: {A,B,CI,acc_update,br_taken}={acc,  8'b0, 1'b0, 1'b0, 1'b0};			
			6'b0010xx: {A,B,CI,acc_update,br_taken}={acc,  DI,   1'b0, 1'b1, 1'b0};			
			6'b0011xx: {A,B,CI,acc_update,br_taken}={acc,  DI,   1'b0, 1'b0, 1'b0};			
			6'b0100xx: {A,B,CI,acc_update,br_taken}={acc,  ~DI,  1'b1, 1'b1, 1'b0};			
			6'b0101xx: {A,B,CI,acc_update,br_taken}={acc,  ~DI,  1'b1, 1'b0, 1'b0};			
			6'b0110xx: {A,B,CI,acc_update,br_taken}={DI,   ~acc, 1'b1, 1'b1, 1'b0};			
			6'b0111xx: {A,B,CI,acc_update,br_taken}={DI,   ~acc, 1'b1, 1'b0, 1'b0};			

			6'b100000: {A,B,CI,acc_update,br_taken}={acc,  8'b0, 1'b0, 1'b0, 1'b0};			
			6'b100100: {A,B,CI,acc_update,br_taken}={DI,   8'b0, 1'b0, 1'b1, 1'b0};			
			6'b101000: {A,B,CI,acc_update,br_taken}={8'bx, 8'bx, 1'b0, 1'b0, 1'b0};			
			6'b101001: {A,B,CI,acc_update,br_taken}={8'bx, 8'bx, 1'b0, 1'b0, 1'b0};			
			6'b101100: {A,B,CI,acc_update,br_taken}={acc,  8'b0, 1'b0, 1'b0, 1'b1};			
			6'b110000: {A,B,CI,acc_update,br_taken}={pc,   C,    1'b0, 1'b0, 1'b1};			
			6'b110010: {A,B,CI,acc_update,br_taken}={pc,   C,    1'b0, 1'b0, acc_zero};			
			6'b110001: {A,B,CI,acc_update,br_taken}={pc,   C,    1'b0, 1'b0, ~acc_zero};			
			default:   {A,B,CI,acc_update,br_taken}={8'bx, 8'bx, 1'bx, 1'bx, 1'bx};	
		endcase
	end

wire [7:0] SUM;
DW01_add #(.width(8)) U_adder (.A(A), .B(B), .CI(CI), .SUM(SUM), .CO());

always @(*)	begin
	if(clkA) begin
		X=SUM;
		acc_update_r=acc_update;
		br_taken_r=br_taken;
		pc_plus_1=pc+1;
	end
end

always @(*) begin
	if(clkB) begin
		pc=(br_taken_r? X : pc_plus_1);
	end
end
always @(*) begin
	if(clkB & acc_update_r) begin
		acc=X;
	end
end

endmodule
