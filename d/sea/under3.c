// hill.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����һ��ˮ�����硣�����ϲ�����ӿ������ȴ���ĳ��档һȺȺ��
ɫ��С������ɫ�ĺ�ˮ��������ȥ��������ɫ�ʰ�쵵�ɺ��������
�а�ɫ��ɺ������һ�ߣ���һ�������̳ɵĵ�·��
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid3" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"under2",
  "northeast" : __DIR__"under4",
  "southwest": __DIR__"maze0",
]));
//      
        set("water", 1);
//  
        setup();
}

