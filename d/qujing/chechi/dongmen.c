// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dongmen.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����Ŵ󿪣���¥���ʣ����ٹ����ӭ������Ʈ�¥��������ʯǽ��¥
��վ�����й����֡�¥�»�ǽ�豸ɭ�ϣ�����һ�Ŵ��״����ĵ���������
�Դ���
LONG);

  set("outdoors", "/d/qujing/chechi");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shatan1",
  "south" : __DIR__"qiang5g",
  "north" : __DIR__"qiang3g",
  "west" : __DIR__"ruizhao",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
        dir == "east")
    return 0;
  return 1;
}


