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
        "west"    : __DIR__"huangye3",
        "east"    : __DIR__"huangye5",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

