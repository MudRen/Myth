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
  "northeast" : __DIR__"yongdao4", 
  "southeast" : __DIR__"yongdao1",
  "west" : __DIR__"yongdao5",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao1" : 2,    
]));


  setup();
}

