// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ҩ��");
  set ("long", @LONG

�ſ�����һ����ӭ��ҡ�Σ�ҩ��������һ����ľ����������
С����������߿��ִ���һ���ӣ����߰���һ���������Ա���
������ۿ��Ρ�

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao31",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_hou"   : 1,
      ]));

  setup();
}


