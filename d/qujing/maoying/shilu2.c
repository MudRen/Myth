// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ·");
  set ("long", @LONG

ɽ����һ��ʯ��·������ȥ�����ŵ�������Щ�����ʯ·�߻�
��������ݴ��������̸���ڣ���֪ͨ��δ���Զ���з�͵�
�ĺ�У�������Ұѻ���ɡ�

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shilu1",
        "south"   : __DIR__"shilu3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



