module q2(g, b);
  input [3:0] g;
  output [3:0] b;
  //wire [7:0] y;

  mux8_1 m1 (
    .y({g[3], g[3], g[3], g[3], g[3], g[3], g[3], g[3]}),
    .f(b[3]),
    .s(g[2:0])
  );

  mux8_1 m2 (
    .y({~g[3], ~g[3], ~g[3], ~g[3], g[3], g[3], g[3], g[3]}),
    .f(b[2]),
    .s(g[2:0])
  );

  mux8_1 m3 (
    .y({g[3], g[3], ~g[3], ~g[3], ~g[3], ~g[3], g[3], g[3]}),
    .f(b[1]),
    .s(g[2:0])
  );

  /*mux8_1 m4 (
    .y({g[3], ~g[3], ~g[3], g[3], ~g[3], g[3], g[3], ~g[3]}),
    .f(b[0]),
    .s(g[2:0])
  );*/
   mux8_1 m4 (
    .y({~g[3], g[3], g[3], ~g[3], g[3], ~g[3], ~g[3], g[3]}),
    .f(b[0]),
    .s(g[2:0])
  );
endmodule

module mux8_1(y, f, s);
  input [7:0] y;
  input [2:0] s;
  output reg f;

  always @ (s)
    case (s)
      3'b000: f = y[0];
      3'b001: f = y[1];
      3'b010: f = y[2];
      3'b011: f = y[3];
      3'b100: f = y[4];
      3'b101: f = y[5];
      3'b110: f = y[6];
      3'b111: f = y[7];
      default: f = 1'bx;
    endcase
endmodule
