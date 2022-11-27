int wizard_calcul_nbre_de_mem()
{
    nbre_de_mems_manipulees=0;
    for(int memo=wizard_from_mem; memo<=wizard_to_mem; memo++)
    {
        if(MemoiresExistantes[memo]==1)
        {
            nbre_de_mems_manipulees++;
        }
    }
    return(0);
}
