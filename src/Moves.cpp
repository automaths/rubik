



CornerToString: array [URF..DRB] of String = ('URF','UFL','ULB','UBR','DFR','DLF','DBL','DRB');

//the positional changes of the cornercubies by faceturns
CornerCubieMove: array[U..B] of CornerCubie =
(((c:UBR;o:0),(c:URF;o:0),(c:UFL;o:0),(c:ULB;o:0),(c:DFR;o:0),(c:DLF;o:0),(c:DBL;o:0),(c:DRB;o:0)),   //U
 ((c:DFR;o:2),(c:UFL;o:0),(c:ULB;o:0),(c:URF;o:1),(c:DRB;o:1),(c:DLF;o:0),(c:DBL;o:0),(c:UBR;o:2)),   //R
 ((c:UFL;o:1),(c:DLF;o:2),(c:ULB;o:0),(c:UBR;o:0),(c:URF;o:2),(c:DFR;o:1),(c:DBL;o:0),(c:DRB;o:0)),   //F
 ((c:URF;o:0),(c:UFL;o:0),(c:ULB;o:0),(c:UBR;o:0),(c:DLF;o:0),(c:DBL;o:0),(c:DRB;o:0),(c:DFR;o:0)),   //D
 ((c:URF;o:0),(c:ULB;o:1),(c:DBL;o:2),(c:UBR;o:0),(c:DFR;o:0),(c:UFL;o:2),(c:DLF;o:1),(c:DRB;o:0)),   //L
 ((c:URF;o:0),(c:UFL;o:0),(c:UBR;o:1),(c:DRB;o:2),(c:DFR;o:0),(c:DLF;o:0),(c:ULB;o:2),(c:DBL;o:1)));  //B

 EdgeToString: array [UR..BR] of String = ('UR','UF','UL','UB','DR','DF','DL','DB','FR','FL','BL','BR');

 EdgeCubieMove: array[U..B] of EdgeCubie = (\
((e:UB;o:0;oA:1),(e:UR;o:0;oA:1),(e:UF;o:0;oA:1),(e:UL;o:0;oA:1),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), (e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)), //U
((e:FR;o:0;oA:1),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:BR;o:0;oA:1),(e:DF;o:0;oA:0), (e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:DR;o:0;oA:1),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:UR;o:0;oA:1)),//R 
((e:UR;o:0;oA:0),(e:FL;o:1;oA:1),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:DR;o:0;oA:0),(e:FR;o:1;oA:1), (e:DL;o:0;oA:0),(e:DB;o:0;oA:0),(e:UF;o:1;oA:1),(e:DF;o:1;oA:1),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)),//F 
((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:UB;o:0;oA:0),(e:DF;o:0;oA:1),(e:DL;o:0;oA:1), (e:DB;o:0;oA:1),(e:DR;o:0;oA:1),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:BL;o:0;oA:0),(e:BR;o:0;oA:0)),//D 
((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:BL;o:0;oA:1),(e:UB;o:0;oA:0),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), (e:FL;o:0;oA:1),(e:DB;o:0;oA:0),(e:FR;o:0;oA:0),(e:UL;o:0;oA:1),(e:DL;o:0;oA:1),(e:BR;o:0;oA:0)),//L 
((e:UR;o:0;oA:0),(e:UF;o:0;oA:0),(e:UL;o:0;oA:0),(e:BR;o:1;oA:1),(e:DR;o:0;oA:0),(e:DF;o:0;oA:0), (e:DL;o:0;oA:0),(e:BL;o:1;oA:1),(e:FR;o:0;oA:0),(e:FL;o:0;oA:0),(e:UB;o:1;oA:1),(e:DB;o:1;oA:1)) );//B 

  