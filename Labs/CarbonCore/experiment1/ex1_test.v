module test;

reg [2:0] sw;
wire [7:0] ld;

experiment1 uut(.ld(ld), .sw(sw));
initial begin
		 sw = 8'b000;
	#100 sw = 8'b001;
	#100 sw = 8'b010;
	#100 sw = 8'b011;
	#100 sw = 8'b100;
	#100 sw = 8'b101;
	#100 sw = 8'b110;
	#100 sw = 8'b111;
end

endmodule

