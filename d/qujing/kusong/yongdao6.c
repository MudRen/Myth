//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

���ڷ���һ��Ѫ������ǽ�Ϲ����͵ƣ����������ĵƹ�������
����ǰ��ĵ�·��
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhongdong", 
  "south" : __DIR__"yongdao4",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,    
]));


  setup();
}

