void  Procedure(const std::string title,const std::string subtitle)
{
    const std::string procedure_title 		= title.substr (0,64);
    const std::string procedure_subtitle 	= subtitle.substr (0,120);

    Rect ProcedureAera( Vec2D( window_proc_x, window_proc_y), Vec2D ( 400,70));
    ProcedureAera.SetRoundness(15);
    ProcedureAera.Draw(CouleurBleuProcedure);
    ProcedureAera.DrawOutline(CouleurLigne);
    neuro.Print(procedure_title, window_proc_x+120,window_proc_y+20);
    petitchiffre.Print( procedure_subtitle,window_proc_x+20, window_proc_y+45);
}
