// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jingang.c

inherit ROOM;

void create ()
{
  set ("short", "��յ�");
  set ("long", @LONG

��յ�����Ʋ���������ʮ��������������̥�Ѿ���Ϊ���ʧ��
��ɫ��������ˣ�̨�Ϸ��ž��㶦������������ȼ�ŷ��㡣����
��������Ϸ�����һͨ����

LONG);

  set("exits", ([
        "west"          : __DIR__"simen",
        "east"          : __DIR__"zheng",
        "north"         : __DIR__"beiyuan",
        "southeast"     : __DIR__"damo",
      ]));

  setup();
}

