// created by snowcat.c 5/27/1997
// room: /d/pantao/pan2c.c

inherit ROOM;

void create ()
{
  set ("short", "���԰");
  set ("long", @LONG

���԰�ڻ���Ҷ�̣�زز���ƻ�ӯ�����ſ�֦֦��ѹ֦��ֻ��
�ǣ�ʱ��ʱ��ǧ���죬�����޶����س٣�����ģ�����������
�����ģ�������Ƥ���ø���֬�����̣�ӳ���Ե��ˡ�

LONG);

  set("exits", ([
        "west"       : __DIR__"pan2b",
    "east"   :__DIR__"gate",
//        "east"       : __DIR__"palace4",
      "north"  :  __DIR__"pan1c",
      "south"  :  __DIR__"pan3c",
      ]));

  set("outdoors",1);
  setup();
}

