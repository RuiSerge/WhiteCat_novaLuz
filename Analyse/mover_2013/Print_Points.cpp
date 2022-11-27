int Print_Points(int move_selected)
{

    for(int dms=1;dms<dock_moves_contains_steps[move_selected]+1;dms++)
    {
    Circle CercleShowPoint( Vec2D(dock_move_xy[move_selected][dms][0]+xmover_window+20, dock_move_xy[move_selected][dms][1]+ymover_window+20), 4 );
    Rect ShowInPoint(Vec2D (dock_move_xy[move_selected][dms][0]+xmover_window+12, dock_move_xy[move_selected][dms][1]+ymover_window+12), Vec2D ( 16,16));

    if(dms==Moves_Inpoint[move_selected]){ShowInPoint.Draw(CouleurLock);}
    CercleShowPoint.Draw(Rgba::WHITE);
    petitchiffre.Print(ol::ToString(dms), dock_move_xy[move_selected][dms][0]+xmover_window+30, dock_move_xy[move_selected][dms][1]+ymover_window+30);
    }

 return(0);
}
