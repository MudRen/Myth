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
        "northeast"   : __DIR__"shimen",
        "west"   : __DIR__"shanlu9",
        "east"   : __DIR__"shanlu11",
      ]));
  set("outdoors", __DIR__);

  setup();
}



