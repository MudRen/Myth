inherit ROOM;
void create ()
{
  set ("short", "����");
  set ("long", @LONG

����м�����һ���ں���������С��վ�ţ�����С����
�߶�������һ���õط���
LONG);
 
        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/heihan" : 1,
        ]));
  set("exits", ([
        "north"  : __DIR__"sanmen",
      ]));
  setup();
}
