`timescale 1ns/1ns
`include "c3.v"
module c3_tb;
reg [2:0]a,b;
wire e,l,g;

c3 uut(a,b,g,l,e);
initial
begin
$dumpfile("c3.vcd");
$dumpvars(0,c3_tb);
a=3'b101;b=3'b001;#20;
a=3'b011;b=3'b100;#20;
a=3'b101;b=3'b101;#20;
a=3'b111;b=3'b011;#20;
$display("test complete");
end
endmodule
