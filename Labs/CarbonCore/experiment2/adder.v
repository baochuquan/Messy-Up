module add_4(X, Y, sum, C);
input [3:0] X, Y;
output [3:0] sum;
output C;

assign {C, sum} = X + Y;

endmodule


