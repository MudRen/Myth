// Room: come to baigudong.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

    ��������ͨ���׹Ƕ��ˡ���˵�����г���������������
������֪���˶���Ѱ�����ա��������ˡ����м�λӢ����
�������������δ�������ǳ�����
  ����ٻ���ή�����ٳ�����Ұ��ïʢ���������ڵ�ð��
����������ɱ֮����Ũ��
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"broad",
  "southwest" : __DIR__"guangchang",
  "northeast" : __DIR__"shanlu1",
  "westup"       : __DIR__"shanlu9", 
]));
   set("objects", ([
        __DIR__"npc/xiaoyao"   : 2,
      ]));
  setup();
}






