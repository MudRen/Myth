// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��᫵�ɽ����ɽ�������ѣ��Ĵ��ǻ�ɽҰ�룬��������һƬ��
Զ���ֺ������Բԡ�·���в����Ĺ������ٸ��������󣬴�
������ķ�ɳ��

LONG);

  set("exits", ([
        "southeast"   : __DIR__"shan13",
        "westup"   : __DIR__"shan9",
      ]));
  set("outdoors", __DIR__);

  setup();
}



