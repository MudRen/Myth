//by dewbaby
//masterroom
  
#include <ansi.h> 
inherit ROOM; 
        
void create () 
       { 
         set ("short", HIW"»·ĞÎÊ¯ÊÒ"NOR); 
         set ("long", @LONG 
        
×ßÈë´Ë»·ĞÎÊ¯ÊÒ£¬ÄãÖ»¾õµÃÒ»Õó´Ì¹Çº®Æø´ÓÍ·¶¥´«
Éø½ø£¬´«µ½È«Éí¡£Ô­À´ÕâÀïÕıÊÇÃ÷ºş±ùÑ¨µÄÕıÏÂ·½¡£
ÒªÏë´ÓÕâÀï³öÈ¥£¬ËÆºõÖ»ÄÜ¶¯ÊÖ¾òÂ·(dig road)ÁË¡££
LONG); 
        
         
        set("exits", ([ /* sizeof==1  */
        "out":__DIR__"house1",        
        ])); 

        setup(); 
}
void init()
{
    add_action("do_dig","dig");

}
int do_dig(string arg)
{
    object me = this_player();
    if (!arg || arg !="road")
            return notify_fail("ÄãÒªÍÚÄÄÀï?\n");
    if (me->is_busy() || me->is_fighting())
            return notify_fail("ÄãÕıÃ¦×ÅÆäËûÊÂÄØ!\n");
     if ((int)me->query_skill("force",1) <200)
    return notify_fail("ÄãµÄÄÚ¹¦»ğºî»¹²»¹»,ÕâÑù¿ÖÅÂ»áÓĞÉËÔ­Æø!\n");
    if ((int)me->query("sen",1) < 400)
    return notify_fail("ÄãµÄ¾«Éñ²»¹»,ÎŞ·¨ÍÚµØ¶´!\n");
         if( arg=="road"){ 
    if (random(me->query_str()) <= 20 )
    message_vision(me->name() + "ÔËÆğÄÚ¹¦£¬½«¾«Æø´«ÓÚË«ÊÖ£¬ÔÚµØÉÏÍÚÁËÆğÀ´¡£\n",me); 
    tell_object(me,"Äã¶×ÏÂÉí£¬Î¢Î¢ÎüÁËÒ»¿ÚÆø£¬ÉìÊÖÔÚµØÉÏÍÚÁËÆğÀ´¡£\n"NOR);
    me->start_busy(5);
    remove_call_out("out1");
    call_out("out1", 6, me);
    return 1;
}
else {
     message("vision", me->name() +"¶×ÏÂÉí£¬Î¢Î¢ÔËÁËÒ»¿ÚÆø£¬ÉìÊÖÔÚµØÉÏÍÚÁËÆğÀ´¡£\n",environment(me),({me}));
     tell_object(me,"Äã¶×ÏÂÉí£¬Î¢Î¢ÔËÁËÒ»¿ÚÆø£¬ÉìÊÖÔÚµØÉÏÍÚÁËÆğÀ´¡£\n"NOR);
}
     tell_object(me,HIW"\nÄãÑÛÇ°ºöÈ»Ò»ÁÁ!\n\nÔ­À´ÄãÒÑ¾­Îª×Ô¼º¾ò³öÁËÉúÂ·!\n"NOR);
     me->move("/d/city/center");
     me->start_busy(3);
    message_vision(me->name() + "´ÓµØµÀÀï·ÉÉíÔ¾ÁË³öÀ´£¬°ÑÂ·ÈËÏÅÁËÒ»Ìø£¡\n",me); 
     return 1;
}
void out1(object me)
{          tell_object(me,"\nÄã¾õµÃË«ÊÖÓĞµãÌÛÍ´,µ«ÎªÁËÉú»¹,Ö»ºÃ¼ÌĞøÍÚ¡£\n"NOR); 
     me->start_busy(5);
     remove_call_out("out");
     call_out("out",3,me); 
}
void out(object me)
{
     tell_object(me,"\nÄã¾õµÃË«ÊÖÓĞµãÌÛÍ´£¬µ«ÎªÁËÉú»¹£¬Ö»ºÃ¼ÌĞøÍÚ¡£\n"NOR);
     me->move("/d/city/center");
    message_vision(me->name() + "´ÓµØµÀÀï·ÉÉíÔ¾ÁË³öÀ´£¬°ÑÂ·ÈËÏÅÁËÒ»Ìø£¡\n",me); 
}

    
