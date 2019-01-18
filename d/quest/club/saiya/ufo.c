inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","ÈûÑÇ·Éµú");
  set ("long", HIR@LONG
                           ¡­¡­    Èû  ÑÇ  ·É  µú    ¡­¡­

    ÕâÀïÊÇÈûÑÇÒì×åÒÅÆúÔÚµØÇòÉÏµÄÒ»¸ö·Éµú¡£·ÉµúÄÚ¶ÑÂúÁËÆÆ¾ÉµÄÒÇÆ÷£¬¿¿Ç½ÓĞÒ»¸öË®¾§Çò
ÒÀÈ»·¢³ö¼¸Ë¿À¶¹â£¬ËÆºõÈÔ¾É¿ÉÒÔºÍÄ³¸öÉñÃØµÄ¿Õ¼ä½øĞĞÁªÂç¡££
    ³¯×ó±ßÊÇÒ»ÉÈ·À»ğÃÅ£¬ÓÒ±ßÊÇÒ»µÀÓÄ°µµÄÍ¨µÀ¡£    

LONG NOR);

  set("exits",([ 
  "left" : __DIR__"center", 
  "right" : __DIR__"tunnel",
]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}

