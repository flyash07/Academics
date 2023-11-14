`timescale 1ns/1ns
`include "multiplier.v"
module multiplier_tb;
reg [2:0]a,b;
reg [5:0]p;
//wire [2:0]pp0;
//wire [3:1]pp1;
multiplier uut(a,b,p);
initial
begin
$dumpfile("multiplier_tb.vcd");
$dumpvars(0,multiplier_tb);
a=3'b101;b=3'b001;#20;
a=3'b100;b=3'b011;#20;
a=3'b101;b=3'b001;#20;
a=3'b111;b=3'b011;#20;
$display("test cinomplete");
end
endmodule
