//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "�ж�");
  set ("long", @LONG

���������࣬����һƬ�����������кܶ�С���߶���������
�µ�Ҳʮ�����֣��Ĵ���·������ز�֪ͨ��η���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao7",
  "east" : __DIR__"yongdao8",
  "west" : __DIR__"sleep", 
  "south" : __DIR__"yongdao6",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,
  __DIR__"npc/yao2" : 2,    
]));



  setup();
}

