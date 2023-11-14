`timescale 1ns/1ns
`include "gb.v"
module gb_tb;
parameter n=3;
reg [n-1:0]g;
wire [n-1:0]b;

gb uut(g,b);
initial
begin
$dumpfile("gb.vcd");
$dumpvars(0,gb_tb);

g=3'b101;#20;
g=3'b100;#20;
g=3'b110;#20;
g=3'b111;#20;
$display("test complete");
end
endmodule
