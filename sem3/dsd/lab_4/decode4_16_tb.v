`timescale 1ns/1ns
`include "decode4_16.v"
module decode4_16_tb;
    reg en;
    reg [3:0] a;
    wire [15:0] y;
    decode4_16 uut (en,a,y);
    initial begin
    $dumpfile("decode4_16_tb.vcd");
    $dumpvars(0,decode4_16_tb);
        en = 0;a = 0;#20;
        en=1;a=0;#20; 
        a=1;#20;
        a=2;#20; 
        a=3;#20; 
        a=4;#20;
        a=5;#20;
        a=6;#20;
        a=7;#20;
        a=8;#20;
        a=9;#20;
        a=10;#20;
        a=11;#20;
        a=12;#20;
        a=13;#20;
        a=14;#20;
        a=15;#20;
    $display("Test complete");
    end
endmodule
