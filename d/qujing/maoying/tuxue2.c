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
        "west"   : __DIR__"andao1",
        "southwest"   : __DIR__"andao3",
      ]));

  setup();
}



