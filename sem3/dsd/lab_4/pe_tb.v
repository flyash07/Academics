`timescale 1ns/1ns
`include "pe.v"
module pe_tb;
    wire [1:0] f;
    wire z;
    reg[3:0] s;
    reg en;
    pe uut (s,f,en,z); integer i;
    initial begin
        $dumpfile("pe_tb.vcd");
        $dumpvars(0,pe_tb);
        en=1;
        for(i=0;i<16;i=i+1) begin
        
            s = i;#20; end
        $display("test complete");
    end
endmodule

