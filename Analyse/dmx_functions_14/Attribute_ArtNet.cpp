int Attribute_ArtNet(int aff, int ddok)
{
 if(DockIsSelected[aff][ddok]==1  && DockTypeIs[aff][ddok]==2)
 {
 for (int pp=0;pp<512;pp++)
 {
 FaderDockContains[aff][ddok][pp]=ArtNet_16xUniverse_Receiving[pp][DockNetIs[aff][ddok]];
 }

 }
return(0);
}
