// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����Űεض���������һ��ͭ���ң���д�š����������
�����֡���ľ���Ŵ󿪣�������������������ͭ�壬������
ͷ����ͭ����

LONG);

  set("exits", ([
        "west"    : __DIR__"lin4",
        "east"    : __DIR__"jie7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "west")
    return 0;
  return 1;
}
