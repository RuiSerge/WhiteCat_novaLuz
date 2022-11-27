int check_dimmer_minus_override()
{
if(index_patch_overide==1)
{
for(int ck=1;ck<513;ck++)
{
if(Dimmers_selected[ck]==1)
        {
        if (ck>1)
        {
        Dimmers_selected[ck]=0;
        Dimmers_selected[ck-1]=1;
        patch_overide[ck]=0;
        patch_overide[ck-1]=1;
        }
        break;

}
}
}
 return(0);
}
