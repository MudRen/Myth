// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�����ɽ·ƽ������ɢ���࣬����������һ��ǳһ�ţ����˲�
���е����顣·�߿�����������������������粻�ϵش�����
�Ĵ���������Ұ����

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanlu7",
        "east"   : __DIR__"shanlu10",
        "southdown"   : __DIR__"shanlu13",
      ]));
  set("outdoors", __DIR__);

  setup();
}



