`timescale 1ns/1ns
`include "q3.v"

module q3_tb;
  reg [3:0]a;
  wire y;

  q3 uut(a,f);

  integer i, j, k, l;

  initial begin
    $dumpfile("q3_tb.vcd");
    $dumpvars(0, q3_tb);

    // Iterate through all possible combinations
    for (i = 0; i <= 1; i = i + 1) begin
      for (j = 0; j <= 1; j = j + 1) begin
        for (k = 0; k <= 1; k = k + 1) begin
          for (l = 0; l <= 1; l = l + 1) begin
            a[3] = i;
            a[2] = j;
            a[1] = k;
            a[0] = l;
            #10;
                        //$display("%4d %1b %1b %1b %1b | %1b", $time, A, B, C, D, f);
          end
        end
      end
    end
    //A=0,B=0,C=0,D=0;#50;

    // Display "test complete" after all test cases
    $display("test complete");

    // Terminate simulation
    $finish;
  end
endmodule

