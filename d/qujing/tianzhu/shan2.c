// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�߸ߵ�ɽ���ϣ�ɽ·˳��ɽ���������·͹����ƽ���Ŵ��С
С��ʯͷ�顣·�߹�ʯ������״�������⣬ɽ·ʱ��ʱխ��·
�߳��ų����ĻĲݡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"jiming",
        "southeast"   : __DIR__"shan3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



