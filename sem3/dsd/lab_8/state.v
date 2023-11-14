module state(t,x,clk,reset,q);
input[1:0] t;
input x,clk,reset;
output [1:0] q;
assign f = (~t[1]&t[0])|(t[0]&~x);
assign g = (~t[0]&~x)|(t[1]&~x)|(~t[1]&t[0]&x);
t_ff stage1(f,clk,reset,q[1]);
t_ff stage2(g,clk,reset,q[0]);
endmodule; 
module t_ff(t,clk,reset,q);
input clk,t,reset;
output reg q;
always@(reset)
q <= 0;
always@(posedge clk)
begin
if(t == 0)
q <= q;
else
q <= ~q;
end
endmodule
