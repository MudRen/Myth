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
        "northup"   : __DIR__"shanlu16",
        "southwest"   : __DIR__"shanlu18",
      ]));
  set("outdoors", __DIR__);

  setup();
}



