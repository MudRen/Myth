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
        "northwest"   : __DIR__"shilu4",
        "southwest"   : __DIR__"shanpo1",
      ]));
  set("outdoors", __DIR__);

  setup();
}



