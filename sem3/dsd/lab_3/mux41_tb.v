`timescale 1ns/1ns
`include "mux41.v"
module mux41_tb;
reg [0:3]w;
reg [0:1]s;

mux41 uut(w,s,f);
initial
begin
$dumpfile("mux41_tb.vcd");
$dumpvars(0,mux41_tb);
w=4'b1010;s=2'b11;#20;
w=4'b1001;s=2'b10;#20;
w=4'b1010;s=2'b00;#20;
w=4'b1111;s=2'b01;#20;
$display("test cinomplete");
end
endmodule
