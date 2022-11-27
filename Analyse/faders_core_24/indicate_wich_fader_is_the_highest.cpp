int indicate_wich_fader_is_the_highest()
{
for(int ig=1;ig<514;ig++)
{
int temp_highest=0;
for (int fd=0;fd<core_user_define_nb_faders;fd++)
{
if (FaderDoDmx[fd][ig]>temp_highest)
{
temp_highest=FaderDoDmx[fd][ig];
highest_level_comes_from_fader[ig]= fd+1;
}
}
}
return(0);
}
