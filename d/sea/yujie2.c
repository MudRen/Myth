// Room: /u/rainy/sea/yujie2.c
inherit ROOM;

void create ()
{
  set ("short", "����ǰ��");
  set ("long", @LONG

�ĸ��޴���������ӳų���һ���൱�������ǰ�������������д󡡡���
����ᣬһ�����������С��������ܹ������飬����ǰ�յ�ͨ��������
������硣��ǽ���и�����ͨ�����ӣ�Χ��Щ����ˮ��ָָ��㡣
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"inside5.c",
  "north" : __DIR__"inside6.c",
  "west" : __DIR__"yujie1",
  "east" : __DIR__"yujie3.c",
]));
set("valid_startroom", 1);
//      
        set("water", 1);
//  
  setup();
"obj/board/dragon_b"->foo();

}
