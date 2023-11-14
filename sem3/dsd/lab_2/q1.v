module q1(a,b,c,d,f);
input a,b,c,d;
output f;
assign g=(~c&d)|(c&~d);
assign f=(g&a)|(b&~g);
endmodule