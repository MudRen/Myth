// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ˮ��");
  set ("long", @LONG

ˮ���ϵ��̴�ð�ŵ����İ��̣�����һ����ˮ���������ſ�ˮ��
��ǽ����һЩˮͰ��һ�ڴ�ˮ�ס��ſ��м���С�ʣ���·����
��ˮ˳��ЪЪ�š�

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao81",
      ]));
  set("resource", ([
    "water" : 1,
  ]));

  setup();
}


