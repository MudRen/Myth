// created by snowcat.c 5/27/1997
// room: /d/pantao/pan3a.c

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
        "northwest"  : __DIR__"ting5",
        "west"       : __DIR__"ting6",
        "southwest"  : __DIR__"ting7",
        "east"       : __DIR__"pan3b",
      ]));

  set("outdoors",1);
  setup();
}

