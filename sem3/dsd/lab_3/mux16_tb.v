`timescale 1ns/1ns
`include "mux16.v"
module mux16_tb;
reg [15:0]a;
reg [3:0]s;
wire f;

mux16 uut(a,s,f);
initial
begin
$dumpfile("mux16_tb.vcd");
$dumpvars(0,mux16_tb);
a=16'b1010101011110011;s=4'b0000;#20;
s=4'b0001;#20;
s=4'b0010;#20;
s=4'b0011;#20;
s=4'b0100;#20;
s=4'b0101;#20;
s=4'b0110;#20;
s=4'b0111;#20;
s=4'b1000;#20;
s=4'b1001;#20;
s=4'b1010;#20;
s=4'b1011;#20;
s=4'b1100;#20;
s=4'b1101;#20;
s=4'b1110;#20;
s=4'b1111;#20;
$display("test cinomplete");
end
endmodule
