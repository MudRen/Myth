// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ұ");
  set ("long", @LONG

��Ұ�Ĵ�������Զ���ɼ�Ⱥɽ�����ͱڣ�������С·������С
ɭ����ľ���紵������֮�����ϣ���ˮ������ʱ�Ų����ƽУ�
ʱ�Ŷ���������

LONG);

  set("exits", ([
        "east"    : __DIR__"huangye7",
        "northwest"    : __DIR__"huangye1",
        "southwest"    : __DIR__"huangye8",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

