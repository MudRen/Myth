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
  "north" : __DIR__"huoyun", 
  "south" : __DIR__"zhongdong",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao2" : 2,    
]));


  setup();
}

