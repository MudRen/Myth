// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "Ƥ��");
  set ("long", @LONG

Ƥ�������һ�����������ӣ�������˸�ʽ������Ƥ��Ƥѥ��
ǽ�ϵ�ľ����Ҳ����һЩ��Ƥ����Ƥñ���ſ���һ�����ӣ�Ҳ
������Ƥ����

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao92",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_shu"   : 1,
      ]));

  setup();
}


