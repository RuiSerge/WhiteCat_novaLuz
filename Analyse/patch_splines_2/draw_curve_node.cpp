int draw_curve_node(int n)
{
   if(n<6){
   Circle(curve_nodes[n].x, curve_nodes[n].y, 6).DrawOutline(CouleurBlind);
   petitchiffre.Print(ol::ToString(n),curve_nodes[n].x-7, curve_nodes[n].y-7);
   }


   if( window_focus_id==W_PATCH && mouse_x>=((curve_nodes[n].x)-(diam_curve_node/2)) && mouse_x<=((curve_nodes[n].x)+(diam_curve_node/2))
   && mouse_x>=xpatch_window+30+455 && mouse_x<=xpatch_window+30+455+255
   && mouse_x>(curve_nodes[n-1].x+(diam_curve_node/2)) && mouse_x<(curve_nodes[n+1].x-(diam_curve_node/2))
   && mouse_y>=ypatch_window+50 && mouse_y<=ypatch_window+255+50    )
   {
     Line( Vec2D( curve_nodes[n].x, ypatch_window+50 ), Vec2D(curve_nodes[n].x,ypatch_window+255+50)).Draw(Rgba::YELLOW);
     Circle(curve_nodes[n].x, curve_nodes[n].y, 6).Draw(CouleurBlind);

    if(mouse_b&1 && index_enable_curve_editing==1 )
    {
    if(n>1 && n<5)
    {
    curve_ctrl_pt[curve_selected][n][0]=mouse_x-(xpatch_window+30+455);
    curve_ctrl_pt[curve_selected][n][1]=mouse_y-(ypatch_window+50);
    }
    if(n==1)
    {
    curve_ctrl_pt[curve_selected][n][0]=0;
    curve_ctrl_pt[curve_selected][n][1]=mouse_y-(ypatch_window+50);
    }
    if(n==5)
    {
    curve_ctrl_pt[curve_selected][n][0]=255;
    curve_ctrl_pt[curve_selected][n][1]=mouse_y-(ypatch_window+50);
    }

    write_curve();//ecriture des niveaux
    }

   }

   if (dmx_view==1)//255
   {
   //affichage OUT
   petitpetitchiffrerouge.Print(ol::ToString(255-curve_ctrl_pt[curve_selected][n][1]),xpatch_window+5+455,ypatch_window+50+curve_ctrl_pt[curve_selected][n][1]);
   //affichage IN
   petitpetitchiffre.Print(ol::ToString(curve_ctrl_pt[curve_selected][n][0]),xpatch_window+455+20+curve_ctrl_pt[curve_selected][n][0],ypatch_window+50+270);
   }
   else   if (dmx_view==0)//%
   {
   //affichage OUT
   petitpetitchiffrerouge.Print(ol::ToString((int)((255-curve_ctrl_pt[curve_selected][n][1])/2.55)),xpatch_window+5+455,ypatch_window+50+curve_ctrl_pt[curve_selected][n][1]);
   //affichage IN
   petitpetitchiffre.Print(ol::ToString((int)((curve_ctrl_pt[curve_selected][n][0])/2.55)),xpatch_window+455+20+curve_ctrl_pt[curve_selected][n][0],ypatch_window+50+270);
   }


 return(0);
}
