//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

���������࣬����һƬ�����������кܶ�С���߶���������
�µ�Ҳʮ�����֣��Ĵ���·������ز�֪ͨ��η���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao6",
  "southeast" : __DIR__"yongdao2", 
  "southwest" : __DIR__"yongdao3",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao2" : 2,    
//  __DIR__"npc/xian": 1,
]));



  setup();
}

