// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

һ���ؽִ������������ݣ�һȺʳ������ϯ�ض�����Χ��һȦ��
�����̾���һ��˺��������͡�������ĳ����ﲻ�ϵش���������
����ζ��

LONG);

  set("exits", ([
        "north"       : __DIR__"xi2",
      ]));

  set("objects", ([ 
    __DIR__"npc/laoban" : 1,
  ]));
  setup();
}

