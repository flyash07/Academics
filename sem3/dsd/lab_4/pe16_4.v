module pe16_4(en,i,y,z);
  input en;
  input [15:0]i;
  integer k;
  output reg z;
  output reg [3:0]y;
  always @(en,i)
  begin
    if(en==1)
      begin
      z=1;
      if (i==0) z=0;
      for(k=15;k>=0;k=k-1)
         if (i[k]==1) y=k;
      end
    else begin y=4'bzzzz;z=0; end 
  end
endmodule
