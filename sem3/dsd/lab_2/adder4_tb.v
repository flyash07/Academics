`timescale 1ns/1ns
`include "adder4.v"
module adder4_tb;
reg [3:0]a,b;
reg k;
wire [2:0]c;
wire [3:0]s;
wire cout;
adder4 uut(a,b,k,s,cout);
initial
begin
$dumpfile("adder4_tb.vcd");
$dumpvars(0,adder4_tb);
a=4'b1010;b=4'b0010;k=0;#20;
a=4'b1001;b=4'b0110;k=0;#20;
a=4'b1010;b=4'b0010;k=1;#20;
a=4'b1111;b=4'b0110;k=1;#20;
$display("test cinomplete");
end
endmodule
