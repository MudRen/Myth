// Room: /u/rainy/sea/huilang3.c
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ϸϸ�Ļ��Ȼ�����ˮ�����������������ŵ��������������塣��������
�ϵ��Ÿ���ˮ����棬�ƺ�������ˮ�������ζ���ͷ�����в�ɫ�ġ�����
ɺ����ɡ״��ǰ��ż��Ѳ�ӵı����߹���
LONG);
          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shark" : 1,
]));

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huilang2",
  "east" : __DIR__"huilang7.c",
]));
//      
        set("water", 1);
//  
  setup();
}
