`timescale 1ns/1ns
`include "q1.v"

module q1_tb;
  reg A, B, C, D;
  wire f;

  q1 uut(A, B, C, D, f);

  integer i, j, k, l;

  initial begin
    $dumpfile("q1_tb.vcd");
    $dumpvars(0, q1_tb);
    for (i = 0; i <= 1; i = i + 1) begin
      for (j = 0; j <= 1; j = j + 1) begin
        for (k = 0; k <= 1; k = k + 1) begin
          for (l = 0; l <= 1; l = l + 1) begin
            A = i;
            B = j;
            C = k;
            D = l;
            #10;
          end
        end
      end
    end
    $display("test complete");
    
  end
endmodule

