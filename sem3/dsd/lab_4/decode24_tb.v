`timescale 1ns/1ns
`include "decode24.v"
module decode24_tb;
    reg en;
    reg [1:0] a;
    wire [3:0] y;
    decode24 uut (en,a,y);
    initial begin
        $dumpfile("decode24_tb.vcd");
        $dumpvars(0,decode24_tb);
        en = 0;a = 0;#20;
        en = 1;a=0;#20;
        a = 1;#20;
        a=2;#20;
        a=3;#20;
        $display("test complete");
    end
endmodule

