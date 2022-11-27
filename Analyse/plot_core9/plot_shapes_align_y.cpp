int plot_shapes_align_y()
{

int the_value=9999;
for(int i=0;i<=nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1)
{
if(shape_position[i][1]<the_value)
{
the_value=shape_position[i][1];
}
}
}

int longueur_trait=0;
bool way_negativ=0;

for(int i=0;i<= nbre_shapes_on_plot;i++)
{
if(shape_selected[i]==1)
{

if(shape_type[i]<7)
{
if(shape_position[i][1]>shape_position[i][3])
{
longueur_trait=shape_position[i][1]-shape_position[i][3];way_negativ=1;
}
else
{longueur_trait=shape_position[i][3]-shape_position[i][1]; }
}


shape_position[i][1]=the_value;

if(shape_type[i]<7)
{
if(way_negativ==1)
{ shape_position[i][3]=shape_position[i][1]-longueur_trait;}
else {shape_position[i][3]=shape_position[i][1]+longueur_trait; }
}



}
}
 return(0);
}
