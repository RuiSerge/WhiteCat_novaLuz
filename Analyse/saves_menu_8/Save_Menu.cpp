int Save_Menu(int xsave, int ysave)
{
Rect backSave(Vec2D(xsave,ysave),Vec2D(420,520));
backSave.SetRoundness(15);
backSave.SetLineWidth(triple_epaisseur_ligne_fader);
backSave.Draw(CouleurFond);
backSave.DrawOutline(CouleurLigne);

if(window_focus_id==W_SAVE){backSave.DrawOutline(CouleurFader);}

neuro.Print("SAVE",xsave+110, ysave+30);


Rect TogBSav(Vec2D(xsave+310,ysave+15),Vec2D(100,20));
TogBSav.SetRoundness(5);
TogBSav.SetLineWidth(epaisseur_ligne_fader);



switch(index_save_mode_export_or_binary)
{
case 0:
petitchiffre.Print("  BINARY",xsave+325,ysave+30);
selecteur_binary_save_solo_global(xsave+30, ysave+50);
deroule_repertoire_classical_save(xsave+20, ysave+85, "saves");
choose_personnal_preset_binary_save_load(xsave+300, ysave+270);
break;
case 1:
TogBSav.Draw(CouleurSurvol);
petitchiffre.Print("IMP-EXPORT",xsave+325,ysave+30);
if(isPdf==1) {selecteur_PDF_save_solo_global(xsave+30, ysave+50);   }
deroule_repertoire_export_import(xsave+20, ysave+85, "import_export");
break;
default: break;
}
TogBSav.DrawOutline(CouleurLigne);

Rect ShowReport(Vec2D(xsave+300,ysave+430),Vec2D(70,25));
ShowReport.SetRoundness(5);
ShowReport.Draw(CouleurSurvol.WithAlpha(index_show_save_load_report));
ShowReport.DrawOutline(CouleurLigne);
petitchiffre.Print("Show",xsave+305,ysave+440);
petitchiffre.Print("Log",xsave+315,ysave+450);


return(0);
}
