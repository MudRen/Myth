// Room: /d/qujing/wudidong/shanlu4.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��������ɲ��죬������գ����й��ߺܰ���ɽ�紵����ֻ��������
����������ư��ޡ����ﲻ�������˼�����Ұ��Ҳ����һֻ����Խ
��Խ��ë���Ȼ��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"dong",
  "northdown" : __DIR__"shanlu3",
]));
  set("outdoors", 1);

  setup();
}
