`include "../lab_4/decode24.v"
module q4(a,f);
	input [2:0]a;
	output f;
	wire [7:0]y;
	decode24 m1(~a[2],a[1:0],y[3:0]);
	decode24 m2(a[2],a[1:0],y[7:4]);
	assign f=y[3]|y[5]|y[6]|y[7];
endmodule
