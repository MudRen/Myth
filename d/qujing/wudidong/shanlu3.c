// Room: /d/qujing/wudidong/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

����ɽ��������ǰһ����ԭ����һ����ɽ֮�У����żҴ���Զ�ˡ�
���������涼���ͱڣ�ֻ���ϱ�һƬ�������ƺ���·��Ѱ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"shanlu2",
  "southup" : __DIR__"shanlu4",
]));
  set("outdoors", 1);

  setup();
}
int valid_leave(object me, string dir)
{
  if (dir == "enter")
    {
      message_vision("$N�ƿ�һ��Ұ�ݣ����������˽�ȥ��\n", me);
      me->move(__DIR__"shanlu2");
      message_vision("$N���˹�����\n", me);
      return 2;
    }
  return ::valid_leave(me, dir);
}
