// under4.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ǰ����Լ�ֳ�һ���������һ����������ɫ�Ĺ�â����������
Ҳ�ر�࣬����������ι�״�ĺ��֡�һ���У�һ���У����糼��
�ݼ��ʵ�һ�㡣
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/long4" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gate",
  "southwest" : __DIR__"under3",
  "enter" : "/d/quest/m_weapon/lianchashi",
]));
//      
        set("water", 1);
//  
  setup();
}
