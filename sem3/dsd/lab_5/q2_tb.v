`timescale 1ns/1ns
`include "q2.v"
module q2_tb;
	reg [3:0]g;
	wire [3:0]b;
	
	//integer i,j,k,l;
	q2 uut(g,b);
	
	initial begin
		$dumpfile("q2_tb.vcd");
		$dumpvars(0,q2_tb);
	        g=4'b0000;#20;
	        g=4'b0101;#20;
	        g=4'b1100;#20;
	        g=4'b1010;#20;
	        g=4'b0110;#20;
    		$display("test complete");
    	end
endmodule
