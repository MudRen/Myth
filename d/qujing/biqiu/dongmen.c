// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

һ�����Űεض���������һ��ͭ���ң���д�š����������
�����֡���ľ���Ŵ󿪣�������������������ͭ�壬������
ͷ����ͭ����

LONG);

  set("exits", ([
        "west"    : __DIR__"jie6",
        "east"    : __DIR__"lin2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "east")
    return 0;
  return 1;
}
