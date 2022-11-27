int do_echo()
{

for(int ech=0;ech<=core_user_define_nb_echo-1;ech++)
{
if(do_bounce[ech]==1)
{
do_bouncing_levels(ech);
bounce_is_prepared[ech]=0;
}
else
{
prepare_bounce(ech);
}
}
 return(0);
}
