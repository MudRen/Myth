//in wangxian DIR
//cave1

#include <ansi.h>
inherit ROOM;
void create()
{
          set("short","ÖñÂ¥µº");
          set("long",@LONG
ÔÂÏÂÍ¤Î÷Ãæ£¬ÕâÀïÊÇÒ»Æ¬»Ä·ÏµÄÖñÂ¥¡£ÖñÂ¥¾ù¼ÜÓÚ±Ì²¨
Ö®ÉÏ¡£ÆäÖĞµÄÒ»¼äÖñÂ¥±ßÓĞÒ»¿Ú¸É¿İµÄÀÏ¾®£¬¿à¾®±ßµÄ
Ê¯Ç½ÉÏÓĞÒ»¸ö´ó¶´(dong)£¬ÀïÃæºÚÆáÆáµÄ£¬²»ÖªµÀÓĞÊ²
Ã´¶«Î÷¡££
LONG); 
         
           set("exits",([ /* sizeof() == 1 */
           "west" : __DIR__"yuexia",
           ]));
           set("item_desc",([
             "dong":"Õâ¶´ÀïºÚÆáÆáµÄÒ»Æ¬£¬Ê²Ã´¶¼¿´²»µ½¡£\n",
           ]));        
          
           setup();
}

void init()
{
          add_action("do_enter","zuan");
          add_action("do_enter","enter");
}
          
int do_enter(string arg)
{
       object me = this_player();
       if(! arg || arg !="dong") return 0;
       if (me->is_busy() || me->is_fighting())
            return notify_fail("ÄãÕıÃ¦×ÅÄÄ£¡\n");
       if (arg == "dong") {
               message("vision", me->name() + "Ò»¸öÁïÉí£¬×ê½øÁËºÚ¶´¡£\n", environment(me), ({me}));
               write("Äã¼±´Ò´ÒµØÍù¶´ÖĞ×ê£¬È´ºöÂÔÁË¶´¶¥µÄÊ¯¿é£¬ÄãÌÛµÃÖ±ÏëµôÑÛÀá¡£\n");
                me->move(__DIR__"cave2");
               message("vision", me->name() + "×êÁË½øÀ´£¬Í·²¿×²µ½ÁËÉ½Ê¯ÉÏ¡£\n", environment(me), ({me}));
               return 1;
       }
       return notify_fail("ÄãÍùÄÄÀï×ê°¡£¿\n");       
}


