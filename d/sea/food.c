// Room: /d/sea/food.c
inherit ROOM;

void create ()
{
  set ("short", "�ͷ�");
  set ("long", @LONG

�����ڵ�һ��ͷ���һ��ֻ�ǹ��е���ʹ�á�������ི�֪����ʲô��
����һ�����������ź�Щ���ӡ�

LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long6.c" : 1,
  __DIR__"obj/food" : 3,
  "/d/obj/food/niupi-jiudai.c" : 1,
]));

set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mulang1.c",
]));
//      
        set("water", 1);
//  
  setup();
}
