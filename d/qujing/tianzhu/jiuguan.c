// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ƹ�");
  set ("long", @LONG

������Ƹײ��ŷ������￿��ǽ�ĵط���ɢ����Ũ�ҵľ��㣬
���ð������ź�ľ������ÿ�������Ϸ��ż���С�ˣ������Ⱦ�
�ľƿ����¾ơ�

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao21",
        "north"   : __DIR__"jiedao12",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_huang"   : 1,
        "/d/obj/food/huasheng" : 2,
      ]));

  setup();
}


