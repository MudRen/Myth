// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽʯ����֮������б���������������£�������������ˮ֮��
���ϣ���ˮ�������ˮ�еĴ�Сʯ�飬����һ�������������
���������������м���������

LONG);

  set("exits", ([
        "southwest"    : __DIR__"huangye1",
      ]));
  set("objects", ([
        __DIR__"npc/shanyao" : 3,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

