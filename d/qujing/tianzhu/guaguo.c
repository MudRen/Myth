// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�Ϲ���");
  set ("long", @LONG

һ�������������һ���ŵ���𣬿�������Ÿ������ʵĹ�
���������ۡ���ʱ��·�˽���������˹Ϲ��꣬����һЩˮ��
���ࡣ

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao65",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_zhang"   : 1,
      ]));

  setup();
}


