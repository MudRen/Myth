// under2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ��ˮ�����硣�����ϲ�����ӿ������ȴ���ĳ��档һȺȺ��
ɫ��С������ɫ�ĺ�ˮ��������ȥ��������ɫ�ʰ�쵵�ɺ��������
�а�ɫ��ɺ������һ�ߣ���һ�������̳ɵĵ�·��
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kid1" : 1,
  __DIR__"npc/kid2" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"under1",
  "east" : __DIR__"under3",
]));
//      
        set("water", 1);
//  
        setup();
}

