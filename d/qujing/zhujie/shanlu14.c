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
        "northeast"   : __DIR__"shanlu12",
        "northwest"   : __DIR__"shanlu11",
      ]));

  set("objects", ([
"/d/sea/npc/beast/beast5" : 1,
]));

  set("outdoors", __DIR__);

  setup();
}



