`include "../lab_4/decode4_16.v"

module q3(a,f);
   input [3:0]a;
   output f;
   wire [15:0]y;
   decode4_16 m1(1'b1,a,y);
   assign f=y[1]|y[4]|y[6]|y[8]|y[9]|y[13]|y[15];
endmodule
