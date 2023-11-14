`timescale 1ns/1ns
`include "q4.v"
module q4_tb;
    reg [2:0] a;
    wire f;
    q4 uut (a,f);
    integer i;
    initial begin
        $dumpfile("q4.vcd");
        $dumpvars(0,q4_tb);
        for(i=0;i<8;i=i+1) begin
           a=i;#10; end
        $display("test complete");
    end
endmodule

