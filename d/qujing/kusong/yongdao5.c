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
  "east" : __DIR__"yongdao3", 
  "west" : __DIR__"anmen",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 1,
  __DIR__"npc/yao2" : 1,    
]));



  setup();
}

