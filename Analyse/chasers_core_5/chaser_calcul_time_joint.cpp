int chaser_calcul_time_joint(int numchaser)
{
if(chaser_time_mode[numchaser]==1)
{

switch(chaser_way[numchaser])
{
case 0://Avant
for(int trk=0;trk< core_user_define_nb_tracks_per_chasers;trk++)
{
count_steps_for_fades[numchaser][trk]=1;//reset

for(int pos_step=chaser_step_is[numchaser];pos_step<nbre_de_cases_par_track;pos_step++)
{
if(chaser_step_operation[numchaser][trk][pos_step-1]!=chaser_step_operation[numchaser][trk][pos_step]
&& chaser_step_operation[numchaser][trk][pos_step]!=0 && chaser_step_operation[numchaser][trk][pos_step]!=2)//sauf Stay et Rien
{
joint_begin_step[numchaser][trk]=pos_step;
}
for(int pstst=joint_begin_step[numchaser][trk]; pstst<nbre_de_cases_par_track;pstst++)
{
if(chaser_step_operation[numchaser][trk][pstst]!=chaser_step_operation[numchaser][trk][(joint_begin_step[numchaser][trk])])
{
joint_end_step[numchaser][trk]=pstst;
joint_nbr_step[numchaser][trk]=joint_end_step[numchaser][trk]-joint_begin_step[numchaser][trk];
break;
}
}

if(chaser_step_operation[numchaser][trk][pos_step]==chaser_step_operation[numchaser][trk][pos_step+1]
&& chaser_step_operation[numchaser][trk][pos_step]!=0 && chaser_step_operation[numchaser][trk][pos_step]!=2)//sauf Stay et Rien
{
count_steps_for_fades[numchaser][trk]++;
}
else{break;}
}
}
break;
case 1: // arrière
for(int trk=0;trk< core_user_define_nb_tracks_per_chasers;trk++)
{
count_steps_for_fades[numchaser][trk]=1;//reset

for(int pos_step=chaser_step_is[numchaser];pos_step>0;pos_step--)
{
if(chaser_step_operation[numchaser][trk][pos_step+1]!=chaser_step_operation[numchaser][trk][pos_step]
&& chaser_step_operation[numchaser][trk][pos_step]!=0 && chaser_step_operation[numchaser][trk][pos_step]!=2)//sauf Stay et Rien
{
joint_begin_step[numchaser][trk]=pos_step;
}
for(int pstst=joint_begin_step[numchaser][trk]; pstst>=0;pstst--)
{
if(chaser_step_operation[numchaser][trk][pstst]!=chaser_step_operation[numchaser][trk][(joint_begin_step[numchaser][trk])])
{
joint_end_step[numchaser][trk]=pstst;
joint_nbr_step[numchaser][trk]=joint_begin_step[numchaser][trk]-joint_end_step[numchaser][trk];
break;
}
}

if(chaser_step_operation[numchaser][trk][pos_step]==chaser_step_operation[numchaser][trk][pos_step-1]
&& chaser_step_operation[numchaser][trk][pos_step]!=0 && chaser_step_operation[numchaser][trk][pos_step]!=2)//sauf Stay et Rien
{
count_steps_for_fades[numchaser][trk]++;
}
else{break;}
}
}
break;
default: break;
}
}
return(0);
}
