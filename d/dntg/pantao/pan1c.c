// created by snowcat.c 5/27/1997
// room: /d/pantao/pan1c.c

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
        "west"       : __DIR__"pan1b",
//        "northeast"  : __DIR__"palace1",
//        "east"       : __DIR__"palace2",
//        "southeast"  : __DIR__"palace3",
       "south" : __DIR__"pan2c",
      ]));

  set("outdoors",1);
  setup();
}

