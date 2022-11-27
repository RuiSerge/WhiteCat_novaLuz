int key_switch_window_up()
{
if (key_shifts & KB_CTRL_FLAG || index_false_control==1) //appel une par une

{
pos_focus_window=window_focus_id;
substract_a_window(pos_focus_window);
if(pos_focus_window<900){pos_focus_window=899;}
pos_focus_window++;
if(pos_focus_window>max_window_identity_is){pos_focus_window=900;}
add_a_window(pos_focus_window);
}

else//passage dune fenetre à l autre
{
index_to_navigate_between_window++;
nbre_fenetre_actives=check_nbre_opened_windows();
if(index_to_navigate_between_window>=nbre_fenetre_actives+1){index_to_navigate_between_window=0;}
if(window_opened[index_to_navigate_between_window]>0)
{
window_bring_to_front(window_opened[index_to_navigate_between_window]);
}
else {window_bring_to_front(window_opened[0]);   }
}
 return(0);
}
