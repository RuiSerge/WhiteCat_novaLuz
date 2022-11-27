int show_artpoll_reply(int apr_X, int apr_Y)
{

Rect ArtPollReplyPanel(Vec2D(apr_X,  apr_Y), Vec2D( 500,250));
ArtPollReplyPanel.SetRoundness(15);
ArtPollReplyPanel.Draw(CouleurFond.WithAlpha(0.9));
ArtPollReplyPanel.DrawOutline(CouleurLigne);
petitchiffre.Print( "ARTPOLLREPLY from ( up to 16 devices ):",(apr_X+10), (apr_Y+20));

for(int co=0;co<16;co++)//etait 17 aout 2016
{
petitchiffre.Print( PollReplyIs[co],(apr_X+10), (apr_Y+40+(10*co)));
}

return(0);
}
