#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "²İÆº");
        set("long",HIG @LONG 
ÕâÊÇÒ»Æ¬±ÌÂÌµÄ²İÆº£¬²ÈÉÏÈ¥¾õµÃÒì³£µÄÈáÈíÎÂºñ£¬²İÆºÒ»Ö±
ÑÓÉìµ½Ğ¡ºÓÅÏ£¬ÇàÇà²İ¸ùÒ²½şÈëºÓË®Ö®ÖĞ¡£ºÓÃæÉÏµãµãË¸½ğ,²¨ÎÆÇ
ÇáÇáµ´Ñú¡£²İÆºµÄÄÏÃæ£¬Ò»¿Ã¸ß´óµÄÎàÍ©Ê÷£¬Ö¦¸ÉĞ±Éì£¬Á½¸ù¹ÅÌÙ
´Ö´ÖÍì¾ÍÒ»¸öÇïÇ§(qiu qian)£¬Ò»ÅÉÏçÍÁÆøÏ¢¡£Äã¶ÙÊ±±»ÕâÀïµÄÃÀ
¾°ÃÔ×¡ÁË£¬ÍüÁËÈ¥×·ÄÇÖ»Ğ¡¾«Áé¡£
LONG
        );
        set("exits", ([ 
        ]) );

        set("item_desc", ([
        "qiu qian": "ÇïÇ§ÏµÓÃ¹ÅÌÙÍì¾Í£¬ËäÈ»¼òÂª£¬È´±ğÓĞÇéÈ¤¡£Äã¿ÉÒÔÊÔ×Åµ´µ´(swing)¿´¡£\n",
        "tree": "¸ß´óµÄÎàÍ©Ê÷°Ñ²İÆºµÄ±±·½ÕÚµÄÑÏÑÏÊµÊµ¡£\n",
        ]) );
        
        setup();
}

void init()
{
   add_action("do_swing", "swing");
   add_action("do_north", "po"); 
}

int do_north(string arg)
{
   object me;

   me = this_player(); 

   if(me->query_temp("marks/marble"))
   {
        message_vision(HIW"$NÈÆ¹ıÎàÍ©Ê÷£¬²¦¿ª²İ´Ô£¬ºöÈ»Ò»Õó¿ñ·ç´µ¹ı£¬°Ñ$N´µÁË¸öõÔõÄ¡£\n"NOR,me ); 
        message_vision(HIW"·çÖĞ´«³öÒ»¸öÉùÒô£ºÓÂ¸ÒµÄÈË£¬Ğ»Ğ»Äã½â¿ªµÚÒ»¸ö·âÓ¡£¬½Ó×Å×ßÏÂÈ¥°É¡£\n"NOR,me );
        message("channel:chat", HBMAG"¡¾¾«ÁéÉñ½ç¡¿"+me->query("name")+"³É¹¦½â¿ªµÚÒ»¸ö·âÓ¡!\n"NOR,users());
        me->move("/d/quest/tulong/spirit5");
        me->set_temp("marks/marble", 0);
        me->set_temp("m_success/³õ¼¶",1);
        return 1;
   }
   else 
        tell_object(me, "ÄÇÀïÃ»ÓĞ³öÂ·¡£\n\n");
   return 1;
}

int do_swing(string arg )
{
        object me;
        me = this_player();

        if(!arg || arg != "ÇïÇ§" && arg != "qiu qian" ) return 0;       
        switch (random (7)) {
                case 0:
                message_vision(HIG"$NÅÀµ½ÇïÇ§ÉÏ£¬ÂıÂıµØ¿ªÊ¼µ´ÆğÇïÇ§£¬Ô½µ´Ô½¸ß¡£\n"NOR, me);
                break;
                case 1:
                message_vision(HIG"ÇïÇ§Ô½µ´Ô½¸ß£¬$N²»ÓÉµÃ½ô½ô×¥×¡¹ÅÌÙ¡£\n"NOR, me);
                tell_object(me, "ÄãÖ»¾õµÃ·ç´Ó½Åµ×ÂÓ¹ı£¬ÈËËÆºõÒª³Ë·ç·ÉÈ¥¡£\n");
                break;
                case 2:
                message_vision(HIG"ÇïÇ§Ô½µ´Ô½¸ß£¬$N²»ÓÉµÃ½ô½ô×¥×¡¹ÅÌÙ¡£\n"NOR, me);
                message("vision", me->name()+"ËÆºõ¿´µ½ÁËÊ²Ã´¶«Î÷£¬´Ò´ÒµØ´ÓÇïÇ§ÉÏÌøÁËÏÂÀ´¡£\n", environment(me), me);
                tell_object(me, "ÄãºöÈ»·¢ÏÖÇ°ÃæÓĞÊ²Ã´·¢³öÒ«ÑÛµÄ¹â£¬¹âÒ»ÉÁ¼´Ê§¡£ËÆºõ¿ÉÒÔÍù±±(po)¡£\n");
                me->set_temp("marks/marble", 1);
                break;
                case 3:
                message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
                tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("kee",50);   
                me->receive_damage("sen",50);   
                break;
                case 4:
                message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
                tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("kee",50);   
                me->receive_damage("sen",50);   
                break;
                case 5:
                message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÒ»²»ÁôÉñ´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
                tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("kee",80);   
                me->receive_damage("sen",80);   
                break; 
                case 6:
                message_vision(HIR"ÇïÇ§Ô½µ´Ô½¸ß£¬$NÊÖÒ»»¬£¬´ÓÇïÇ§ÉÏµôÁËÏÂÀ´¡£\n"NOR, me);
                tell_object(me, "£¢Åé£¡£¢ÄãÖØÖØµØË¤ÔÚÊ÷¸ùÉÏ£¬Æ¨¹ÉºÃÍ´Å¶£¡ \n");
                me->receive_damage("kee",80);   
                me->receive_damage("sen",80);   
                break;        
                }
        return 1;
}


