int set_patch_scroll( int dim)
{
    if(dim>0 && dim<55)
    {
        scroller_patch=1;
    }
    else  if(dim>=55 && dim<103)
    {
        scroller_patch=22;
    }
    else  if(dim>=103 && dim<151)
    {
        scroller_patch=42;
    }
    else  if(dim>=151 && dim<193)
    {
        scroller_patch=60;
    }
    else  if(dim>=193 && dim<247)
    {
        scroller_patch=78;
    }
    else  if(dim>=247 && dim<295)
    {
        scroller_patch=99;
    }
    else  if(dim>=295 && dim<349)
    {
        scroller_patch=118;
    }
    else  if(dim>=349 && dim<397)
    {
        scroller_patch=140;
    }
    else  if(dim>=397 && dim<445)
    {
        scroller_patch=159;
    }
    else  if(dim>=445 && dim<493)
    {
        scroller_patch=178;
    }
    else  if(dim>=493)
    {
        scroller_patch=198;
    }
    return(0);
}
