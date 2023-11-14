module adder4(a,b,k,s,cout);
input [3:0]a,b;
input k;
output [3:0]s;
output cout;
wire [2:0]c;
assign i1=b[0]^k;
assign i2=b[1]^k;
assign i3=b[2]^k;
assign i4=b[3]^k;
full_adder add1(a[0],i1,k,s[0],c[0]);
full_adder add2(a[1],i2,c[0],s[1],c[1]);
full_adder add3(a[2],i3,c[1],s[2],c[2]);
full_adder add4(a[3],i4,c[2],s[3],cout);
endmodule
module full_adder(a,b,cin,s,cout);
input a,b,cin;
output s,cout;
assign s=(a^b)^cin;
assign cout=(a&b)|(b&cin)|(a&cin);
endmodule


