// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/hou.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�����������������̨���������ΰ����Ű������ķ���������
��Ҳ�ǲ��ϣ���������һЩ�����š����ߵ���ͨ�����������
��ͨ������¥��

LONG);

  set("exits", ([
        "northup"       : __DIR__"fang",
        "west"          : __DIR__"zheng",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 2,
      ]));
  setup();
}

