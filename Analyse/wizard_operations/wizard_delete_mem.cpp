int wizard_delete_mem()
{
for(int pm=wizard_from_mem;pm<=wizard_to_mem;pm++)
{
MemoiresExistantes[pm]=0;
MemoiresDetruites[pm]=1;
}
 return(0);
}
