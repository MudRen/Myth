// Room: /d/moon/fengxue/wygdown
//edit by xuanzi
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", HIC"����¥"NOR);
  set ("long", @LONG

���ºδ�����˼��ң����ߣ���Ӱ�޴��١�
���������۲С�˭Ϊ�����į¥���١�
        
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"wytdamen",
  "up" : __DIR__"wxt",
  "north" : __DIR__"woshi",
]));
        set("valid_startroom", 1);
  setup();
//call_other("/obj/board/wangyuege_b", "???");
}

