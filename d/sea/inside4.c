// hill.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ͭ¯Ѭ�㣬����ϸ��ͨ�����ԡ������һ̨��̨�м�����
Ů���������Ź۾���̨����һƬ��԰����÷���࣬���¹̦��Զ
��ƽ�־����������֡�
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long9.c" : 1,
  __DIR__"npc/longpo" : 1,
  __DIR__"npc/gonge" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huayuan1.c",
  "north" : __DIR__"huayuan.c",
  "west" : __DIR__"inside3",
  "east" : __DIR__"yidao.c",
]));
//      
        set("water", 1);
//  
  setup();
}
