// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/ximen.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ž��գ���¥���ʣ����ٹ����ӭ������Ʈ�¥��������
ʯǽ��¥��վ�����й����֡�¥�»�ǽ�豸ɭ�ϣ�����һ�Ŵ���
�����ĵ����������Դ���

LONG);

  set("exits", ([
        "north"        : __DIR__"qiang3a",
        "east"         : __DIR__"taiping",
        "west"         : __DIR__"shatan4",
        "south"        : __DIR__"qiang5a",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "west")
    return 0;
  return 1;
}
