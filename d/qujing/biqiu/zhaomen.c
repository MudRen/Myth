// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������ΰ������ƣ�һ������ɫ���칰���ϱ���󿪣���¥��
Ʈ����̫ƽ�졣������Ǳ���������������������������ڣ�
�����������촫����

LONG);

  set("exits", ([
        "north"    : __DIR__"xiaozi",
        "southwest"    : __DIR__"guan",
        "west"    : __DIR__"da",
      ]));
  set("objects", ([
        __DIR__"npc/wenguan"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir != "north")
    return 0;
  return 1;
}
