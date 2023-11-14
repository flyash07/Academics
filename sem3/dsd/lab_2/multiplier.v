module full_adder(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
assign s=(a^b)^cin;
assign cout=(a&b)|(b&cin)|(a&cin);
endmodule

module multiplier(a,b,p);
input [2:0]a,b;
output [5:0]p;
wire [2:0]pp0;
wire [3:1]pp1;
wire [5:0]c;

assign pp0[1]=(a[1]&b[0]);
assign pp0[2]=(a[2]&b[0]);
assign p[0]=(a[0]&b[0]);

full_adder add1(pp0[1],a[0]&b[1],1'b0,pp1[1],c[0]);
full_adder add2(pp0[2],a[1]&b[1],c[0],pp1[2],c[1]);
full_adder add3(pp1[2],a[0]&b[2],1'b0,p[2],c[2]);
full_adder add4(1'b0,a[2]&b[1],c[2],pp1[2],c[3]);
full_adder add5(pp1[2],a[1]&b[2],c[3],p[3],c[4]);
full_adder add6(c[3],a[2]&b[2],c[4],p[4],p[5]);
assign p[1]=pp1[1];

endmodule
