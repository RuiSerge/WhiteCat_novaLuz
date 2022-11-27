int record_minifaders_selected_as_fgroup(int fd, int dk)
{
for(int i=0;i<48;i++)
{
if(i!=fd)
{
fgroup[fd][dk][i]= minifaders_selected[i];
minifaders_selected[i]=0;
}
}
 return(0);
}
