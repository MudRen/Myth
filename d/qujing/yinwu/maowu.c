// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG

һ������󿪵�é�ݣ�������ľǽ���������һЩ�ƻ�����ľ
������֮��ĸɲˣ�é�ݵĶ����Ǹ�é�ݣ�������һȦ������
���ǽ��

LONG);

  set("exits", ([
        "northwest"    : __DIR__"huangye8",
      ]));
  set("objects", ([
        __DIR__"npc/laofu" : 1,
      ]));
  setup();
}

