// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֿ�");
  set ("long", @LONG

ʯͷ�Ķ�Ѩ��Ȼ�γ���һ���ֿ⣬��������������ʯ�ڷֿ���
�ѷ��Ų�ͬ�Ķ�������Ҫ����Ƥ���֮��ĳ»����ڶ��ߵ�ǽ
�����ƺ���һ����϶��

LONG);

  set("exits", ([
        "southwest"   : __DIR__"can",
      ]));

  setup();
}



