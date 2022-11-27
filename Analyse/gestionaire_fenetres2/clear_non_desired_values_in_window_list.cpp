int clear_non_desired_values_in_window_list()
{
for(int i=0;i<72;i++)
{
if(window_opened[i] >max_window_identity_is+1){window_opened[i]=0;window_opened[i]=0;} //+1 règle bug de rwanoux et jaques alpha 0.8.3
if(window_opened[i] <900){window_opened[i]=0;}
}
 return(0);
}
