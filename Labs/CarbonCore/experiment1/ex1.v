module experiment1(output [7:0] ld, input [2:0] sw);

assign ld[0]=~sw[2]&~sw[1]&~sw[0];
assign ld[1]=~sw[2]&~sw[1]& sw[0];
assign ld[2]=~sw[2]& sw[1]&~sw[0];
assign ld[3]=~sw[2]& sw[1]& sw[0];
assign ld[4]= sw[2]&~sw[1]&~sw[0];
assign ld[5]= sw[2]&~sw[1]& sw[0];
assign ld[6]= sw[2]& sw[1]&~sw[0];
assign ld[7]= sw[2]& sw[1]& sw[0];

endmodule
