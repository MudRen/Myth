// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ѩ");
  set ("long", @LONG

һ�������ɽ�������������翣����Ľ�������������ĸɲݡ�
���������ƺ��а�������˵����������Ѩ�����ǵڼ�Ѩ�أ���
��İ�����ͨ��ʲôѨ�أ�

LONG);

  set("exits", ([
        "east"   : __DIR__"andao1",
        "southeast"   : __DIR__"andao2",
      ]));

  setup();
}



