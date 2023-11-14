module mux16(a,s,f);
input [15:0]a;
input [3:0]s;
output f;
wire g,h;
mux8to1 m1(a[7:0],s[2:0],g);
mux8to1 m2(a[15:8],s[2:0],h);
mux2to1 m3(g,h,s[3],f);
endmodule

module mux8to1(w,s,f);
input [7:0]w;
input [2:0]s;
output reg f;
always@(w,s)
begin
	case (s)
		0:f=w[0];
		1:f=w[1];
		2:f=w[2];
		3:f=w[3];
		4:f=w[4];
		5:f=w[5];
		6:f=w[6];
		7:f=w[7];
	endcase
end 
endmodule
		
module mux2to1 (w0, w1, s, f1);
input w0, w1, s;
output f1;

assign f1 = s ? w1 : w0;
endmodule

