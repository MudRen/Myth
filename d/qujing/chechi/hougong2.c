// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/hougong2.c

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

�������汦������������ĵ����ɳ�ͭһ���̿�������֮����
���ڹ����ɹ��ɻ������ϵı���Իͣ�������㣬����������
��������

LONG);

  set("exits", ([
        "west"         : __DIR__"hougong1",
        "east"         : __DIR__"hougong3",
        "south"        : __DIR__"jinluan",
      ]));

  set("objects",([
          __DIR__"npc/girl"     : 3,
      ]));
  setup();
}

