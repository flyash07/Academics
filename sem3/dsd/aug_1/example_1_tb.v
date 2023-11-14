`timescale 1ns/1ns
`include "example_1.v"
module example_1_tb;
reg a,b,c;
wire f;
example_1 uut(a,b,c,f);
initial
begin
$dumpfile("example_1_tb.vcd");
$dumpvars(0,example_1_tb);
a=0;b=0;c=0;#20;
b=1;#20;
a=1;b=0;#20;
b=1;#20;
c=1;#20;
$display("test complete");
end
endmodule
