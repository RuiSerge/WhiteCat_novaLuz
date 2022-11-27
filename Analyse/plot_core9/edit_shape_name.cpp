int edit_shape_name()
{
sprintf(temp_shape_legend_name,numeric);
temp_shape_legend_name[24]='\0';
for(int i=1;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1){sprintf(shape_legend_name[i],temp_shape_legend_name);}
}
reset_numeric_entry();
numeric_postext=0;
if(index_text_auto_close==1){index_type=0;}
return(0);
}
