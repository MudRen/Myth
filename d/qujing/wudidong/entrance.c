// Room: /d/qujing/wudidong/entrance.c

inherit ROOM;

void create ()
{
  set ("short", "С���");
  set ("long", @LONG

��ͷ������ȥ��ֻ��һ����ǽ���������飬һ��������СϪΧ��ʮ��
�䰫����é�ݣ������żҴ塣��ɽ��Ұ�Ķ��ǲ���۷��ڽ�Ƶ���
�˻�����衣��ĿԶ��������������ɽ���������������ȥ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"firemount-wudidong3",
  "west" : __DIR__"road1",
]));
  set("outdoors", "1");

  setup();
}
