`timescale 1ns/1ns
`include "state.v"
module state_tb;
reg clk,x,reset;
reg[1:0] t;
wire[1:0] q;
state uut(t,x,clk,reset,q);
always #20 clk = ~clk;
initial begin
    $dumpfile("state_tb.vcd");
    $dumpvars(0,state_tb);
    clk = 0;
    #140 $finish;
end
initial begin
    t = 2'b00;x = 0;reset = 1;#20;
    t = 2'b00;x = 1;reset = 0;#20;
    t = 2'b01;x = 1;reset = 0;#20;
    t = 2'b00;x = 0;reset = 0;#20;
    t = 2'b01;x = 0;reset = 0;#20;
    t = 2'b01;x = 0;reset = 0;#20;
    t = 2'b11;x = 1;reset = 0;#20;
end
endmodule
