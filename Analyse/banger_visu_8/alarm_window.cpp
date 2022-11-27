int alarm_window()
{
Rect windowAlarm(Vec2D(XAlarm,YAlarm),Vec2D(300,110));
windowAlarm.SetRoundness(15);
windowAlarm.SetLineWidth(triple_epaisseur_ligne_fader);
windowAlarm.Draw(CouleurFond);
windowAlarm.Draw(CouleurBlind.WithAlpha(alpha_blinker));
if(window_focus_id==918)
{windowAlarm.DrawOutline(CouleurFader);}
else{windowAlarm.DrawOutline(CouleurLigne);}
char title_alarm[32];
sprintf(title_alarm,"Alarm from banger number %d",index_alarm_from_banger_num+1);
neuromoyen.Print(title_alarm,XAlarm+80,YAlarm+30);
neuro.Print(string_THE_alarm,XAlarm+20,YAlarm+80);

return(0);
}
