`timescale 1ns/1ns
`include "pe16_4.v"
module pe16_4_tb;
  reg [15:0]i;
  reg en;
  wire [3:0]y;
  wire z;

  pe16_4 uut(en,i,y,z);
  initial
    begin
      $dumpfile("pe16_4_tb.vcd");
      $dumpvars(0,pe16_4_tb);
            en=0;i=16'bx;#20;
      	    en=1;
      	    i=32768;#20;
      	    i=16384;#20;
      	    i=8192;#20;
      	    i=4096;#20;
      	    i=2048;#20
      	    i=1024;#20;
      	    i=512;#20;
      	    i=256;#20;
      	    i=128;#20;
      	    i=64;#20;
            i=32;#20;
            i=16;#20;
            i=8;#20;
            i=4;#20;
            i=2;#20;
            i=0;#20;
      $display("test complete");
    end
endmodule
