//under1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ��ˮ�����硣�����ϲ�����ӿ������ȴ���ó��档һȺȺ��
ɫ��С������ɫ�ĺ�ˮ��������ȥ��������ɫ�ʰ�쵵�ɺ��������
�а�ɫ��ɺ������һ�ߣ���һ�������̳ɵĵ�·��
LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yecha" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : "d/changan/eastseashore",
  "east" : __DIR__"under2",
]));
//      
        set("water", 1);
//  
        setup();
}

