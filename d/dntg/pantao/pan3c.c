// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3c.c

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
        "west"       : __DIR__"pan3b",
      "north" : __DIR__"pan2c",
]));
//         "northeast"  : __DIR__"palace5",

  set("outdoors",1);
  setup();
}

