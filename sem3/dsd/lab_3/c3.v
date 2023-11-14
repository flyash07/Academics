module c3(a,b,g,l,e);
input [2:0]a,b;
output g,l,e;
wire [2:0]p,q;

assign p[0]=~(a[0]^b[0]);
assign p[1]=~(a[1]^b[1]);
assign p[2]=~(a[2]^b[2]);
assign q[0]=a[0]&b[0];
assign q[1]=a[1]&b[1]&p[2];
assign q[2]=p[2]&p[1]&a[2]&b[2];


assign e=(p[0]&p[1])&p[2];
assign g=(q[0]||q[1])||q[2];
assign l=~(e|g);
endmodule
